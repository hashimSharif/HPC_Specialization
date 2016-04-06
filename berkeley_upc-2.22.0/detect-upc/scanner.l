
%{
/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/detect-upc/scanner.l $
 * Note: If you edit scanner.l, please commit a corresponding scanner.c to Git.
 * Do so as follows to preserve the .l file's ident info
 *   $ cvs ci scanner.l
 *   $ flex -8 -Cfe -oscanner.c scanner.l
 *   $ cvs ci scanner.c
 * WARNING:
 *   Avoid flex-2.5.35 which generates a scanner.c that crashes icc on ia64.
 * Also try Solaris and AIX versions of lex and increase setting if needed.
 */
#include "detect-upc.h"
#include <assert.h>

/* Implement a call stack */

/* define to 0 for unlimited dynamic stack */
#define MAX_STACK_DEPTH 1

#if MAX_STACK_DEPTH == 1
  /* Simplified case since we only need depth of 1 */
  static int prev_state = 0;
  #ifdef YY_START
    #define push_state(state) \
       do { prev_state = YY_START; BEGIN(state); } while(0)
  #else
    #define push_state(state) \
       do { prev_state = YYSTATE; BEGIN(state); } while(0)
  #endif
  #define pop_state() BEGIN(prev_state)
#else
  /* Implementation at bottom of file */
  static void pop_state(void);
  static void push_state(int state);
#endif

/* manage enter and exit from TOPLVL */
static int seen_paren = 0;
static void enter_toplvl(void);
static void leave_toplvl(void);

%}

 /* 
  * UPC keywords and standard functions: the presence of any of these 
  * in a file indicate that it contains UPC code for our purposes.
  * Note that 'shared', 'strict' and 'relaxed' are handled separately
  * to allow for their use as valid identifiers in C-mode headers.
  */
upc1  THREADS|MYTHREAD|upc_forall|upc_global_exit
upc2  upc_global_alloc|upc_all_alloc|upc_alloc|upc_local_alloc|upc_free
upc3  upc_localsizeof|upc_blocksizeof|UPC_MAX_BLOCK_SIZE
upc4  upc_elemsizeof|upc_affinitysize
upc5  upc_phaseof|upc_threadof|upc_resetphase|upc_addrfield
upc6  upc_notify|upc_wait|upc_barrier|upc_fence
upc7  upc_lock_t|upc_global_lock_alloc|upc_all_lock_alloc|upc_lock_free
upc8  upc_lock|upc_lock_attempt|upc_unlock
upc9  upc_memcpy|upc_memget|upc_memput|upc_memset

 /* Instances of whitespace:
  *  ws = a single space or tab character
  *  blanks = any (possibly empty) sequence of space or tab followed by optional newline
  */
ws     [\ \t]
blanks {ws}*\n?

 /* Since upc pragmas use a '^' start of line match, we can't
  * group them together with the others in upc_token */
pragma_upc   {ws}*#{ws}*pragma{ws}+upc{ws}+
upc_code     ^{pragma_upc}upc_code{ws}*\n
c_code       ^{pragma_upc}c_code{ws}*\n
startupconly ^{pragma_upc}start_upc_only{ws}*\n
endupconly   ^{pragma_upc}end_upc_only{ws}*\n
suspendins   ^{pragma_upc}detect_upc{ws}+suspend_insertion{ws}*\n
resumeins    ^{pragma_upc}detect_upc{ws}+resume_insertion{ws}*\n
upc_pragma   ^{pragma_upc}(strict|relaxed){ws}*\n
upc_token {upc1}|{upc2}|{upc3}|{upc4}|{upc5}|{upc6}|{upc7}|{upc8}|{upc9}
upc_shared (shared|relaxed|strict)
upc_threads THREADS|MYTHREAD

literalslash    \\\\
doublequote     \"
escapedquote    \\\"
line_number     [1-9][0-9]*
entering_file   ^#{ws}*(line)?{ws}*{line_number}{ws}+\"[^<>"]+\".*\n
pp_directive    ^{ws}*#.*\n
wholeline       .*\n?
token           [_A-Za-z0-9]+
brackets        \[([^\]]|']')*\]
attribute       __attribute__[\ \t\n]*\(\(
lefty           [[({]
righty          [\])}]

 /* charconst only needs to be sufficient to match chars special to us */
charconst       '\\?.'

%x INSHARED STRING UPCONLY ATTRIBUTE
%s OUTPUT TOPLVL INITIALIZER NESTED

 /* Need larger than the defaults on AIX and Solaris lex: */
%e 2000
%p 5100
%n 625

%%
    int nest_depth = 0;

    if (do_output) BEGIN OUTPUT;

<INITIAL>{entering_file} { handle_include(yytext); }
<INITIAL>{startupconly}  { push_state(UPCONLY); }
<INITIAL>{upc_code}      { mark_as_upc(yytext, PRAGMA);} 
<INITIAL>{c_code}        { mark_as_c(yytext); }
<INITIAL>{upc_pragma}    { mark_as_upc(yytext, LEXXER);} 
<INITIAL>{upc_token}     { mark_as_upc(yytext, LEXXER);} 
<INITIAL>{upc_shared}    { BEGIN(INSHARED); }
<INITIAL>{doublequote}   { push_state(STRING); }
<INITIAL>{pp_directive}  |
<INITIAL>{charconst}     |
<INITIAL>{token}         |
<INITIAL>.|\n            ;

%{
 /*
  * following 'shared', 'relaxed' or 'strict':
  * Determine if the keyword is followed by an identifier-like word
  * (making it UPC) or not (making it C),
  * while ignoring []s which can appear legally in both C and UPC:
  * UPC:	shared [8] int *x;
  * C:		int relaxed[8][4];
  */
%}
<INSHARED>{token}     { mark_as_upc("shared/relaxed/strict", LEXXER);}
<INSHARED>{brackets}  ;
<INSHARED>[\ \t\n]+   ;
<INSHARED>.           { BEGIN(INITIAL); }

%{
 /* 
  * string literal: go until another double quote seen, but not
  * if it's preceded by a \ (unless it's a \\, i.e. a literal \)
  */
%}
<STRING>{doublequote}  { if (do_output) ECHO; pop_state(); }
<STRING>{literalslash} |
<STRING>{escapedquote} |
<STRING>[^\\"]+        |
<STRING>.|\n           { if (do_output) ECHO; }

%{
 /* Between the delimiters
  *   #pragma upc start_upc_only
  * and
  *   #pragma upc end_upc_only
  * on input: we don't apply our UPC detection heuristics.
  * on output: we swallow the text if not in UPC mode, and always swallow the delimiters.
  * NOTE: These don't (yet) nest, but a "depth" counter could fix that.
  */
%}
<UPCONLY>{endupconly}  { pop_state(); }
<UPCONLY>{wholeline}   { if (do_output && !in_c) ECHO; }

%{
 /* output scan common rules:
  *  + remove "c_code" pragams
  *  + implement "(start|end)_upc_only" pragams
  *  + implement "(suspend|resume)_insertion" pragams
  *  + pass-through unknown directive lines
  *  + insert "upc_code" pragams when we enter file
  *  + transform of 'shared', 'strict' and 'relaxed' in C mode.
  *  + transform of '__thread' to a (fake) attribute in C mode.
  * NOTE: These apply in all the start conditions below
  */
%}
{entering_file}  { insert_pragma(yytext); }
{startupconly}   { push_state(UPCONLY); }
{c_code}         { print_out("\n",1); /* blank line to preserve line counts */ }
{suspendins}     { print_out("\n",1); /* blank line to preserve line counts */
                   ++insert_suspend; }
{resumeins}      { print_out("\n",1); /* blank line to preserve line counts */
                   assert(insert_suspend);
                   --insert_suspend; }
{pp_directive}   ECHO;
{upc_shared}     { if (in_c) print_out("_bupc_",6); ECHO; }
{upc_threads}    { if (in_c && prefix_threads) print_out("_bupc_",6); ECHO; }
"__thread"       { if (in_c && xform_misc) print_out("__attribute__((__bupc__thread__))",33); else ECHO; }
{doublequote}    { ECHO; push_state(STRING); }

%{
 /* output scan:
  * Most of the work here and below is tracking context so we avoid
  * inserting the pragmas in illegal locations.
  * See also the unqualified rules above
  */
%}
<OUTPUT>{blanks} |
<OUTPUT>";"      ECHO;
<OUTPUT>.        { yyless(0); enter_toplvl(); }

%{
 /* output scan "top level":
  *  Parsing text that is not a preprocessor directive
  *  See also the unqualified rules above and shared rules below.
  */
%}
<TOPLVL>{attribute}      { ECHO; assert(!nest_depth); BEGIN(ATTRIBUTE); }
<TOPLVL>"="              { ECHO; assert(!nest_depth); BEGIN(INITIALIZER); }
<TOPLVL>{lefty}          { ECHO; assert(!nest_depth); nest_depth=1; BEGIN(NESTED); }
<TOPLVL>";"              { ECHO; assert(!nest_depth); leave_toplvl(); }

%{
 /* attribute: scan to "))" while nesting parens and honoring single- and double-quotes
    Exists to ensure the parens don't get mistaken for an argument list
    See also the shared rules below (but NOT the unqualified ones above).
  */
%}
<ATTRIBUTE>{doublequote} { ECHO; push_state(STRING); }
<ATTRIBUTE>"("           { ECHO; ++nest_depth; }
<ATTRIBUTE>\)+           { if (yyleng > nest_depth) {
                             /* (yyleng == accept_len + 1) is a syntax error.
                                However, we accept it here to avoid an endless yyless-loop.
                              */
                             /* accept the '))', but not more */
                             if (yyleng > nest_depth + 2) yyless(nest_depth + 2);
                             nest_depth = 0;
                             BEGIN(TOPLVL);
                           } else {
                             nest_depth -= yyleng;
                           }
                           ECHO;
                         }

%{
 /* initilizer: scan to ";" while nesting [({})] and honoring single- and double-quotes
    Exists to ensure compound initializers don't get mistaken for a function definition
    See also the unqualified rules above and shared rules below.
  */
%}
<INITIALIZER>{righty}    { ECHO;
                           if (!nest_depth) {
                             fprintf(stderr, "Unexpected/unbalanced '%s' in input\n", yytext);
                             exit(1);
                           }
                           --nest_depth; }
<INITIALIZER>";"         { ECHO; if (!nest_depth) leave_toplvl(); }

%{
 /* nested: balance '[({' and '})]' while honoring single- and double-quotes
    See also the unqualified rules above and shared rules below.
 */
%}
<NESTED>{righty}  { ECHO; 
                    if (!nest_depth) {
                      fprintf(stderr, "Unexpected/unbalanced '%s' in input\n", yytext);
                      exit(1);
                    }
                    if (! --nest_depth) {
                      char c = yytext[0];
                      if ((c == '}') && seen_paren) {
                        /* Saw paired (...) followed by {...}.
                           We took care not to get tricked by attributes or initializers.
                           So we are confident we've reached the end of a function body.
                         */
                        leave_toplvl(); /* End of function body (hopefully) */
                      } else {
                        if (c == ')') seen_paren = 1;
                        BEGIN(TOPLVL);
                      }
                    }
                  }

%{
 /* output shared rules (some of which must appear last) */
%}
<INITIALIZER,NESTED>{lefty} { ECHO; ++nest_depth; }
<TOPLVL,ATTRIBUTE,INITIALIZER,NESTED>{charconst}     |
<TOPLVL,ATTRIBUTE,INITIALIZER,NESTED>{token}         |
<TOPLVL,ATTRIBUTE,INITIALIZER,NESTED>{blanks}        |
<TOPLVL,ATTRIBUTE,INITIALIZER,NESTED>.               ECHO;


%%

/* 
 * we use only 1 file per run, so stop yylex() at EOF 
 */
int yywrap()
{
    return 1;
}

#if MAX_STACK_DEPTH != 1
  #if MAX_STACK_DEPTH
    static int call_stack[MAX_STACK_DEPTH];
  #else
    static int *call_stack = NULL;
    static int stack_alloc = 0;
  #endif
  static int stack_top = 0;

  static void push_state(int state) {
  #if !MAX_STACK_DEPTH
    if (stack_top == stack_alloc) {
      stack_alloc += 2;
      call_stack = realloc(call_stack, stack_alloc * sizeof(int));
    }
  #else
    assert(stack_top < MAX_STACK_DEPTH);
  #endif
  #ifdef YY_START
    call_stack[stack_top++] = YY_START;
  #else
    call_stack[stack_top++] = YYSTATE;
  #endif
    BEGIN state;
  }
  static void pop_state(void) {
    assert(stack_top);
    BEGIN call_stack[--stack_top];
  }
#endif

static void enter_toplvl(void) {
  ++insert_suspend;
  seen_paren = 0;
  BEGIN TOPLVL;
}
static void leave_toplvl(void) {
  assert(insert_suspend);
  --insert_suspend;
  BEGIN OUTPUT;
}

