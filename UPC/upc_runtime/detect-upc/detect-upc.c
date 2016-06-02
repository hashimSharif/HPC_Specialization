#include "detect-upc.h"

/*******************************************************************************
 * detect-upc
 * ----------
 *
 *  This program, in conjunction with the 'upcppp' script, scans a
 *  preprocessed .i file to determine which files in the compilation unit
 *  contain UPC code (with files that #include other files that contain UPC
 *  also being considered UPC, transitively).
 *
 *  This serves two purposes:
 *
 *  1) For any UPC implementation that uses pthreads for UPC threads, UPC
 *     files must be handled differently than C ones, in that any
 *     static/global unshared variables must be made "thread-local", i.e. a
 *     copy for each pthread must be made.  This must not happen to C
 *     variables (like 'stdout', mutexes, etc.).  While ideally a construct
 *     like 'extern "C"' could be used to accomplish this, at a block level,
 *     for Berkeley UPC this is done at the file level.
 *
 *  2) In order to avoid certain troublesome constructs (esp. inline assembly)
 *     in system header files, Berkeley UPC's source-to-source translator
 *     "puts back" all C headers, i.e. it replaces their contents in the C it
 *     generates with "#include <filename.h>".  This allows the backend C
 *     compiler to handle the inline assembly.  This cannot be done with UPC
 *     code, since the backend C compiler will of course choke on UPC
 *     constructs.  So detect-upc allows the translator to decide which
 *     headers to "put back".
 *
 *  Detect-upc places a 
 *
 *	#pragma upc upc_code
 *
 *  when UPC code is encountered.  If the -b option is passed, corresponding
 *  lines with 
 *
 *	#pragma upc c_code
 *
 *  are also emitted (on transitions from UPC to C).
 *
 *  Additionally name-shifting (a "_bupc_") prefix is applied to some
 *  identifiers when they appear in C mode.  By default the following
 *  are affected:
 *      shared
 *      relaxed
 *      strict
 *  When -t is passed, the following are also name-shifted in C mode:
 *      THREADS
 *      MYTHREADS
 *  When -T is passed, the following is transformed in C mode:
 *      __thread  ->  __attribute__((__bupc__thread__))
 *  
 ******************************************************************************/

/* TODO: use config.h if we ever find a platform that doesn't have all these
 * header files 
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h> /* For PATH_MAX */

/* depth of header file inclusion we support */
#define MAX_DEPTH 255

/* (f)lex-defined thingies */
extern FILE *yyin, *yyout;
extern int yylex();

static int verbose = 0;
static char *progname;
static char *outfile;

/* type for marking modes of files */
enum lang_mode {
	LANG_UNKNOWN = 0,	/* Default when we start reading a .h file (implicitly C) */
	LANG_IMPLICIT_UPC,	/* lexxer heuristic, transitive include, or .uph */
	LANG_EXPLICIT_C,	/* contains "#pragma upc c_code" */
	LANG_EXPLICIT_UPC	/* contains "#pragma upc upc_code" */
};

/* info on current stack of includes */
static char * istack[MAX_DEPTH];       /* stack of current includes */
static enum lang_mode marked[MAX_DEPTH];          /* what mode file on stack is marked as */
static int lvl = -1;

/* singly-linked list of the dependency file */
typedef struct _dep_node {
    const char * filename;
    int num_inc;
    char ** includes;
    struct _dep_node * next;
} dep_node;
static dep_node *dep_files = NULL;

FILE *depfile;
int do_output = 0;
int insert_suspend = 0;
int prefix_threads = 0;
int xform_misc = 0;

/* control whether/when 'c_code' pragma emitted */
int c_pragma = 0;
int in_c = 0;

/*******************************************************************************
 * Normalize an absolute path, returning a new string that caller must free().
 * Here "normalization" is removal of all instances of "//", "/./" and "/../".
 * Input must begin with '/' or it will be returned unchanged.
 * Last path component is left unchanged, even if it is ".", "..", or empty.
 * In other words: we assume 'in' is the absolute path of a file, but even if
 * not, we will always return a valid path which corresponds to the input.
 *******************************************************************************/
#ifdef __CYGWIN__
  #include <cygwin/version.h>
  #if (CYGWIN_VERSION_API_MAJOR > 0) || (CYGWIN_VERSION_API_MINOR >= 213)
  /* If available, use canonicalize_file_name() which will additionally
   * resolve all symlinks (which gcc-5 under cygwin treat inconsistently).
   */
    #define USE_canonicalize_file_name
  #endif
#endif

char *normalize(const char *in) {
  #ifdef USE_canonicalize_file_name
    char *out = canonicalize_file_name(in);
    return out ? out : strdup(in);
  #else
    char *p, *q, *r, *out;
    out = p = strdup(in);
    while (p[0]=='/') {
        if (p[1]=='/') {
            q = p + 1;
        } else if (p[1]=='.' && p[2]=='/') {
            q = p + 2;
        } else if (p[1]=='.' && p[2]=='.' && p[3]=='/') {
            q = p + 3;
            while (p!=out && *--p!='/');
        } else {
            while (*++p && *p!='/');
            continue;
        }
        for (r = p; (*++r = *++q); );
    }
    return out;
  #endif
}

/*******************************************************************************
 * The list of known UPC files.
 * Current implemented as a linked list
 *******************************************************************************/
 
/* singly-linked list of UPC .h files found */
typedef struct _flist_node {
    const char * filename;
    struct _flist_node * next; 
    int has_pragma;
} flist_node;

static flist_node *upc_files = NULL;
static flist_node *tail_file = NULL;

/* Prints the list of UPC files */
static void print_upc_files(void) {
    flist_node *p;
    if (upc_files != NULL)
	printf("UPC FILES FOUND:\n");
    else
	printf("NO UPC FILES FOUND\n");
    for (p = upc_files; p != NULL; p = p->next) 
	printf("    %s\n", p->filename);
}

/* Checks to see if the fname is currently in the upc_files list */
static int is_upc_file(const char * fname) {
    flist_node * p = upc_files;
    char * tmpname = normalize(fname);
    int result = 0;
    for (p = upc_files; p != NULL; p = p->next) {
	if (!strcmp(tmpname, p->filename)) {
	    result = 1;
	    break;
	}
    }
    free(tmpname);
    return result;
}	

/* Adds fname to the upc_files list */
static flist_node *add_upc_file(const char *fname) {
    flist_node *p = (flist_node *)malloc(sizeof(flist_node));
    if (!p) {
	perror("malloc failed");
	exit(-1);
    }
    p->has_pragma = 0;
    p->next = NULL;
    p->filename = normalize(fname);
    if (!p->filename) {
	perror("strdup failed");
	exit(-1);
    }
    if (!upc_files) {
	upc_files = tail_file = p;
    } else {
	tail_file->next = p;
	tail_file = p;
    }
    return p;
}

static int has_upc_suffix(const char *str)
{
    char *p;

    if ( (p = strrchr(str, '.')) == NULL)
	return 0;

    if (p[1]=='u' && p[2]=='p' && (p[3]=='h' || p[3]=='c') && p[4]=='\0')
	return 1;

    return 0;
}

/*
 * When we see a UPC construct, we mark both the file and all those
 * that (transitively) #included it, all the way back to the .c or
 * .upc file.
 *   - Needed logically--since any code that #included UPC file
 *     could refer to UPC variable declared in this UPC header.
 *   - Needed practically with our 'double include fix', since no .h
 *     file can put 'put back' if its expansion contains UPC
 *     constructs.
 */
void mark_as_upc(char *keyword, int reason)
{
    flist_node *p;
    int i;

    /* should have detected entering a file by now: otherwise we probably handle
     * the preprocessors's line directives incorrectly */
    if (lvl < 0) {
	fprintf(stderr, "Failed to parse line directives.  Please report as a bug.\n");
	exit(-1);
    }

    if (marked[lvl] == LANG_EXPLICIT_C) {
	if (reason == PRAGMA) {
	    fprintf(stderr, "file %s contains both \"#pragma upc c_code\" and "
			    "\"#pragma upc upc_code\"\n", istack[lvl]);
	    exit(-1);
	} else {
	    /* Ignore heuristic match in an explicit C-mode file */
	    if (verbose) {
		for (i = 0; i < lvl; i++)
		    printf("  ");
		printf("  UPC CODE: %s (ignored due to pragma)\n", keyword);
		fflush(stdout);
	    }
	    return;
	}
    } else if (marked[lvl] == LANG_UNKNOWN) {
	/* First check parents (if any) for conflicts before marking any */
	for (i = lvl-1; i >= 0; i--) {
            if (marked[i] == LANG_EXPLICIT_C) {
		if (reason == PRAGMA) {
		    fprintf(stderr, "file %s contains \"#pragma upc c_code\" "
				    "and%s includes %s, containing \"#pragma "
				    "upc upc_code\"\n", istack[i],
				    ((lvl-i) > 1) ? " transitively" : "",
				    istack[lvl]);
		    exit(-1);
		} else if (reason == SUFFIX) {
		    fprintf(stderr, "file %s contains \"#pragma upc c_code\" "
				    "and%s includes %s\n", istack[i],
				    ((lvl-i) > 1) ? " transitively" : "",
				    istack[lvl]);
		    exit(-1);
		} else {
	    	    /* Ignore heuristic match in child of an explicit C-mode file */
		    /* XXX: do we want to issue a warning here? */
		    if (verbose) {
			for (i = 0; i < lvl; i++)
			    printf("  ");
			    printf("  UPC CODE: %s (ignored due to earlier pragma)\n", keyword);
			fflush(stdout);
		    }
		    return;
		}
	    }
	}


	if (verbose) {
            for (i = 0; i < lvl; i++)
		printf("  ");
	    printf("  UPC CODE: %s\n", keyword);
	    fflush(stdout);
	}

	/* mark current file */
        p = add_upc_file(istack[lvl]);
	if (reason == PRAGMA) {
	    /* Don't add '#pragma upc upc_code' to file if already present */
	    p->has_pragma = 1;
	    marked[lvl] = LANG_EXPLICIT_UPC;
	} else {
	    marked[lvl] = LANG_IMPLICIT_UPC;
	}

	/* Now mark all parents */
        for (i = 0; i < lvl; i++) {
            if (marked[i] == LANG_UNKNOWN) {
                add_upc_file(istack[i]);
                marked[i] = LANG_IMPLICIT_UPC;
	    }
	}

    } 
}

void mark_as_c(char *keyword)
{
    int i;

    /* should have detected entering a file by now: otherwise we probably handle
     * the preprocessors's line directives incorrectly */
    if (lvl < 0) {
	fprintf(stderr, "Failed to parse line directives.  Please report as a bug.\n");
	exit(-1);
    }

    if (verbose) {
        for (i = 0; i < lvl; i++)
            printf("  ");
        printf("  C CODE: %s\n", keyword);
	fflush(stdout);
    }

    if (marked[lvl] == LANG_EXPLICIT_UPC) {
	fprintf(stderr, "file %s contains both \"#pragma upc c_code\" and "
			"\"#pragma upc upc_code\"\n", istack[lvl]);
	exit(-1);
    } else if (marked[lvl] == LANG_IMPLICIT_UPC) {
	/* error case: pragmas appears after code (too late to unmark) */
	fprintf(stderr, "file %s contains \"#pragma upc c_code\" %s\n",
			istack[lvl], has_upc_suffix(istack[lvl])
				? "but has .uph or .upc suffix"
				: "after apparent UPC code");
	exit(-1);
    } else if (marked[lvl] == LANG_UNKNOWN) {
	marked[lvl] = LANG_EXPLICIT_C;
    } 
}

/* Parses out file name from lines like 
 *
 *	# 1 "/usr/foo/bar.h" 
 * 
 * Note: uses strdup:  up to caller to free 
 */
static char * get_filename(char *line_directive)
{
    char * firstquote = strchr(line_directive, '"');
    char * lastquote = strrchr(line_directive, '"');
    char * filename = NULL;

    if (!firstquote | !lastquote) {
        fprintf(stderr, "line directive '%s' not understood!\n",
                line_directive);
        exit(-1);
    }
    *lastquote = '\0';
    firstquote++;             /* skip over " */
    filename = strdup(firstquote);
    if (!filename || !strlen(filename)) {
        fprintf(stderr, "file name in line_directive '%s' is empty!\n",
                line_directive);
        exit(-1);
    }
    *lastquote = '"';
    return filename;
}

/* Handles entry to a new .h file */
void handle_include(char *line_directive)
{
    char * filename = get_filename(line_directive);
    int r;
    int entering = 1;

    /* If file name is the current top of stack, we're still in same file */
    if (lvl >= 0 && !strcmp(filename, istack[lvl]))
	goto free_file;

    /* If we're returning to one of the files on the stack, we've implicitly
     * exited from all the files above it
     *  - Needed to handle OSX gcc's 'smart preprocessor', which returns w/o
     *    showing all stack pops if they don't contain code. (we no longer use
     *    the smart preprocessor on OSX, but it doesn't hurt to check) */
    for (r = (lvl - 1); r >= 0; r--) {
        if (!strcmp(filename, istack[r])) {
            while (lvl > r) {
                if (verbose) {
                    int i;
                    for (i = 0; i < lvl; i++)
                        printf("  ");
                    printf("leaving %s\n", istack[lvl]);
		    fflush(stdout);
                }
                free(istack[lvl]);
                marked[lvl--] = LANG_UNKNOWN;
            }
            entering = 0;
            break;
        }
    }

    /* otherwise, we're entering a new .h file: push onto stack */
    if (entering) {
        istack[++lvl] = strdup(filename); 
        if (!istack[lvl]) { 
            perror("strdup failed!"); 
            exit(-1);
        }
        if (verbose) {
            int i;
            for (i = 0; i < lvl; i++)
                printf("  ");
            printf("entering %s\n", istack[lvl]);
	    fflush(stdout);
        }
	/* if included file has .uph or .upc extension, mark as UPC */
	if (has_upc_suffix(filename))
	    mark_as_upc("filename ends with .uph or .upc", SUFFIX);
    }

free_file:
    free(filename);
}

/* 2nd pass over file: generate output file with #pragma's added to mark 
 * .h files that contain UPC code (or #include others that do) */
void generate_output()
{
    fseek(yyin, 0, SEEK_SET);	/* rewind input file */
    in_c = 0;
    do_output = 1;
    yylex();
}

/* When we output #line again after printing #pragma upc, make sure to omit
 * anything after the file name (gcc puts magic '2' that indicates 'just left
 * a file', and if it sees it twice in a row it barfs).
 * Note- this function modifies the argument in-place.
 */
static char * remove_ephemera_from_line(char *line_directive)
{
    char * quote = strchr(line_directive, '"');
    if (quote == NULL) {
        fprintf(stderr, "line directive '%s' contains no quotes!\n",
                line_directive);
        exit(-1);
    }
    quote++;
    quote = strchr(quote, '"');
    if (quote == NULL) {
        fprintf(stderr, "line directive '%s' contains only one quote!\n",
                line_directive);
        exit(-1);
    }
    quote++;
    if (*quote != '\n') {
	quote[0] = '\n';
	quote[1] = 0;
    }
    return line_directive; 
}

/* Adds "#pragma upc upc_code (or c_code)" to output if needed */
void insert_pragma(char *yytxt)
{
    char *filename = get_filename(yytxt);

    /* Only need to output pragma at file transitions */
    static char * lastfile = NULL;
    if (lastfile && !strcmp(lastfile, filename)) {
	fprintf(yyout, "%s", yytxt);
	return;
    } else if (lastfile) {
	free(lastfile);
    }
    lastfile = strdup(filename);
    if (!lastfile) {
	perror("strdup failed!\n");
	exit(-1);
    }

    fprintf(yyout, "%s", yytxt);

    if (insert_suspend) {
        if (verbose) {
	    printf("SKIPPING pragma insertion for %s due to suspend_insertion\n", filename);
	    fflush(stdout);
	}
    } else if (is_upc_file(filename)) {
	fprintf(yyout, "#pragma upc upc_code\n");
	/* Print #line directive again, else debugger/__LINE__ will be off
	 * by 1 */
    	fprintf(yyout, "%s", remove_ephemera_from_line(yytxt));
	if (verbose) {
	    printf("added UPC pragma 'upc_code' to %s\n", filename);
	    fflush(stdout);
	}
	in_c = 0;
    } else {
        /* only print the c_code pragma when transitioning from UPC context, so we
         * don't get lots in a row (note: we need 'upc_code' at top of each UPC
         * file, so we must tolerate series of upc_code pragmas, at least unless
         * the translator is taught to maintain upc mode across file transitions. */
        if (c_pragma && !in_c) {
    	    fprintf(yyout, "#pragma upc c_code\n");
	    /* Print #line directive again, else debugger/__LINE__ will be off
	     * by 1 */
	    fprintf(yyout, "%s", remove_ephemera_from_line(yytxt));
	    if (verbose) {
	        printf("added UPC pragma 'c_code' to %s\n", filename);
	        fflush(stdout);
	    }
        }
        in_c = 1;
    }
}


/* prints a string to the output file, verbatim.
 * - Can't use printf, etc., since string may contain escape sequences
 */
void print_out(char *str, int len)
{
    /* "fwrite returns value less than 3rd param only if error occurs" */
    if (fwrite(str, 1, len, yyout) != len) {
	fprintf(stderr, "%s: unable to write to '%s'\n", progname, outfile);
	exit(-1);
    }
}

void usage(FILE *f, const char *argv0, int exitcode)
{
    fprintf(stdout, "Usage: %s -i dependency_file -o outfile [-b] [-t] [-T] [-v] preprocessed_input\n", 
	    argv0);
    exit(exitcode);
}


/* update the upc_file list by reading the dependency file to
   to avoid putting back upc files as c files
   */
void add_by_dep() {
    int i;
    int count = 1; /* the number of updates in the list */
    dep_node *cur_dep ;
    while (count) {  /*if there's any new files added to the upc-files list */
    	count = 0; /* reset it to zero */
    	cur_dep = dep_files;
	while (cur_dep) {
	    /* If the current header file is a UPC file then search for all
	     * the files that include it, marking all those that are not
	     * currently in the list as UPC files
	    */
	    if (is_upc_file(cur_dep->filename)) {
	        for (i=0; i<(cur_dep->num_inc); i++) {
	            if (!is_upc_file(cur_dep->includes[i])) {
			add_upc_file(cur_dep->includes[i]);
	            	count++;
	            }
	        }
	    }
	    cur_dep = cur_dep->next;        		    
	}
    }
}

/* read 1 line of input (discarding newline) into static buffer */
static char * my_getline(FILE *f)
{
    const int chunk = 10;
    static int size = 0;
    static char *buf = NULL;
    char *p;

    if (!buf) {
	buf = malloc(chunk);
        if (!buf) {
            perror("malloc failed");
            exit(-1);
        }
	size = chunk;
    }

    p = buf; *p = '\0';
    while (!feof(f)) {
        size_t len;
        if (fgets(p, size - strlen(buf), f) == NULL) return 0;
        len = strlen(p);
        if (p[len-1] == '\n') {
            p[len-1] = '\0';
            break; /* Full line read */
        }
        /* Grow buf */
	len += p - buf;
	size += chunk;
	buf = realloc(buf, size);
        if (!buf) {
            perror("realloc failed");
            exit(-1);
        }
	p = buf + len;
    }



    return buf;
}

/* parse one 'file count' line from input */
int my_parseline(FILE *f, char **name, int *count)
{
    char *buf, *p;

    buf = my_getline(f);
    if (buf == NULL) return 0;

    p = strrchr(buf, ' '); /* LAST space in case path contains spaces */
    if (p == NULL) return 0;
    
    *p = '\0';
    *name = buf;

    return (sscanf(p+1,"%d",count) == 1);
}

/* Read the dependency file into the linked list of dep_files
*/

void read_dependency(FILE *f) 
{   
    char *temp;
    int num_of_includers, i;
    while (my_parseline(f, &temp, &num_of_includers)) {
    	dep_node *p = (dep_node *) malloc (sizeof (dep_node));
    	if (!p) {
    	    perror("malloc failed");
    	    exit(-1);
    	}
    	p->filename = strdup(temp);
    	    if (!p->filename) {
    	    	perror("strdup failed");
    	    	exit(-1);
    	    }
    	p->num_inc = num_of_includers;
    	p->next = NULL;
    	p->includes = (char **) malloc (p->num_inc * sizeof(char *));
    	    if (!p->includes) {
    	    	perror("malloc failed");
    	    	exit(-1);
    	    }
    	    /* read the files that includes the header */
    	    for (i = 0; i < p->num_inc; i++) {
    	    	temp = my_getline(f);
    	    	if (temp == NULL) {
    	    	    perror("getline failed");
    	    	    exit(-1);
                }
#ifdef USE_canonicalize_file_name /* Only on Cygwin 1.7+ for now */
                p->includes[i] = normalize(temp);
#else
                p->includes[i] = strdup(temp);
#endif
    	    	    if (!p->includes[i]) {
    	    	    	perror("strdup failed");
    	    	    	exit(-1);
    	    	    }
    	    }
    	if (!dep_files) {
    		dep_files = p;
    	} else {
    		p->next = dep_files;
    		dep_files = p;
    	}   	
    }
}


int main(int argc, char **argv)
{
    int flag;

    while ( (flag = getopt(argc, argv, "btThvi:o:")) != -1) {
	switch (flag) {
	case 'h':
	    usage(stdout, argv[0], 0);
	    break;
	case 'v':
	    verbose = 1;
	    break;
	case 'b':
	    c_pragma = 1;
	    break;
	case 't':
	    prefix_threads = 1;
	    break;
	case 'T':
	    xform_misc = 1;
	    break;
	case 'i':
	    if ( (depfile = fopen(optarg, "r")) == NULL) {
		fprintf(stderr, "%s: error: can't open dependency file '%s'\n", 
			argv[0], optarg);
		exit(-1);
	    }
	    break;
	case 'o':
	    if ( (yyout = fopen(optarg, "w")) == NULL) {
		fprintf(stderr, "%s: error: can't open '%s' for writing\n", 
			argv[0], argv[1]);
		exit(-1);
	    }
	    outfile = strdup(optarg);
	    if (!outfile) {
		perror("in strdup");
		exit(-1);
	    }
	    break;
	case '?':
	    fprintf(stderr, "%s: unrecognized flag '%c'\n", argv[0],
		    flag);
	    exit(-1);
	    break;
	default:
	    fprintf(stderr, "%s: internal getopt error\n", argv[0]);
	    exit(-1);
	}
    }

    if ((argc - optind) != 1 || !depfile || !outfile)
	usage(stderr, argv[0], -1);

    if ( (yyin = fopen(argv[optind], "r")) == NULL) {
        fprintf(stderr, "%s: error: can't open '%s'\n", 
                argv[0], argv[optind]);
        exit(1);
    }
#if 0
    add_upc_file(argv[optind]); /* tag top-level file as always UPC */
#endif

    /* Find UPC constructs in files, and mark files in which they're found,
     * and the files that #included them */
    yylex();

    /* Read list of dependencies, and use to mark any file that may have been
     * missed due to "#ifndef .... #endif" blocks in #included UPC files
     * - Many preprocessors will show no record of entering a file which
     *   expands to nothing due to the #ifndef block, and this causes the
     *   yylex pass above to miss them. */
    read_dependency(depfile);
    add_by_dep();

    if (verbose) {
	print_upc_files();
	fflush(stdout);
    }

    /* Output version of file with #pragmas marking UPC code from C code */
    generate_output();

    return 0;
}


