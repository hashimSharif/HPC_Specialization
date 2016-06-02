/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/profile/dump/gasp.c $ */
/*  Description: main implementation of the GASP-based tracing tool 'dump' */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */


#include <stdlib.h>
#include <stddef.h>
#if HAVE_GASNET_TOOLS
#define GASNETT_LITE_MODE 1
#include <gasnet_tools.h>
#else
#include <stdint.h>
#endif
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <gasp.h>
#include <gasp_upc.h>

#include "gaspu.h"

/* internal tool events, placed at end of user event range */
#define GASPI_EVT_BASE          (GASP_UPC_USEREVT_END - GASPI_RESERVEDEVTS)
#define GASPI_INIT              GASPI_EVT_BASE+0
#define GASPI_CREATE_EVENT      GASPI_EVT_BASE+1
#define GASPI_CONTROL           GASPI_EVT_BASE+2
#define GASPI_RESERVEDEVTS      3

/* number of user events */
#define GASPI_UPC_USEREVT_NUM ((GASP_UPC_USEREVT_END-GASPI_RESERVEDEVTS)-GASP_UPC_USEREVT_START+1)

#ifndef GASP_UPC_NB_TRIVIAL /* bug workaround for Cray UPC */
#define GASP_UPC_NB_TRIVIAL ((gasp_upc_nb_handle_t)0)
#endif

/* avoid an identifier conflict on BG/P (and others?) */
#undef INIT

typedef struct {
  const char *name;
  const char *desc;
} gasp_userevt_t;

struct _gasp_context_S {
  int inupcall;
  int enabled;
  int forceflush; /* force flush after each output (useful for crashes) */
  int skipoutput; /* fully parse events but skip the final output to file (for debugging tool) */
  gasp_model_t srcmodel;
  gasp_tick_t starttime;
  int mythread;
  int threads;
  FILE *outputfile;
  gasp_userevt_t *userevt;
  size_t userevt_cnt;
  size_t userevt_sz;
};

/* make a reentrant-safe upcall into UPC */
#define GASPI_UPCALL(context, fncall) do { \
  assert(!context->inupcall);              \
  context->inupcall = 1;                   \
  fncall;                                  \
  context->inupcall = 0;                   \
} while(0)

int gasp_control(gasp_context_t context, int on) {
  int oldval = context->enabled;
  int newval = !!on;
  if (oldval ^ newval) { /* control transition */
    context->enabled = 1; 
    gasp_event_notify(context, GASPI_CONTROL, GASP_ATOMIC, NULL, 0, 0, newval);
    context->enabled = newval;
  }
  return oldval;
}

void gaspi_err(const char *fmt,...) {
  char buf[1024];
  va_list argptr;
  va_start(argptr, fmt); /*  pass in last argument */
    vsnprintf(buf,1024,fmt,argptr);
  va_end(argptr);
  fprintf(stderr,"*** GASP FATAL ERROR: %s\n", buf);
  abort();
}

int gaspi_getenvYN(gasp_context_t context, const char *key, int defaultval) { 
  const char *val = NULL;
  GASPI_UPCALL(context, gaspu_getenv(key, &val));
  if (val) {
    if (atoi(val) || *val == 'y' || *val == 'Y') return 1;
    else return 0;
  }
  return defaultval;
}

unsigned int gasp_create_event(gasp_context_t context, const char *name, const char *desc) {
  int idx = context->userevt_cnt;
  int retval;
  if (context->userevt_cnt == context->userevt_sz) {
    if (context->userevt_cnt == GASPI_UPC_USEREVT_NUM) 
      gaspi_err("gasp_create_event(): too many user events. Max is %i", GASPI_UPC_USEREVT_NUM);
    context->userevt_sz = (context->userevt_sz*2)+1;
    context->userevt = realloc(context->userevt, sizeof(gasp_userevt_t)*context->userevt_sz);
    assert(context->userevt);
  }
  context->userevt[idx].name = (name?strdup(name):"USER_EVENT");
  context->userevt[idx].desc = (desc?strdup(desc):"");
  context->userevt_cnt++;
  retval = idx + GASP_UPC_USEREVT_START;
  gasp_event_notify(context, GASPI_CREATE_EVENT, GASP_ATOMIC, NULL, 0, 0, name, desc, retval);
  return retval;
}

gasp_context_t gasp_init(gasp_model_t srcmodel, int *argc, char ***argv) {
  /* allocate a local context */
  gasp_context_t context = (gasp_context_t)calloc(1,sizeof(struct _gasp_context_S));
  assert(context->srcmodel == GASP_MODEL_UPC); /* for now */
  context->srcmodel = srcmodel; 
  gaspu_init(&(context->mythread),&(context->threads));
  context->enabled = 1; 

  /* query system parameters */
  GASPI_UPCALL(context, gaspu_ticks_now(&(context->starttime)));

  context->forceflush = gaspi_getenvYN(context,"GASP_FLUSH",0);

  { /* setup output file */
    const char *filename = NULL;
    char filetmp[255];
    GASPI_UPCALL(context, gaspu_getenv("GASP_DUMPFILE", &filename));
    if (!filename) filename = "gasp_dump.%";
    if (!strcmp(filename,"") || !strcmp(filename,"-") || !strcmp(filename,"stderr")) {
      strcpy(filetmp,"stderr");
      context->outputfile = stderr;
    } else if (!strcmp(filename,"stdout")) {
      strcpy(filetmp,"stdout");
      context->outputfile = stdout;
    } else {
      char *p = filetmp;
      for (;*filename;filename++) {
        if (*filename == '%') { sprintf(p,"%i", context->mythread); p += strlen(p); }
        else *(p++) = *filename;
      }
      *p = '\0';
      context->outputfile = fopen(filetmp,"wt");
      if (!context->outputfile) { perror("fopen"); abort(); }
    }
    fprintf(stderr, "GASP tracing output enabled - thread %i output directed to: %s\n", context->mythread, filetmp);
    fflush(stderr);
  }
  /* report startup message */
  { char argstr[1024];
    int i;
    sprintf(argstr,"MYTHREAD = %i, THREADS = %i, argc = %i, argv = [ ", 
      context->mythread, context->threads, *argc);
    for (i = 0; i < *argc; i++) {
      if (i > 0) strcat(argstr,", ");
      strcat(argstr,"'"); strcat(argstr,(*argv)[i]); strcat(argstr,"'");
    }
    strcat(argstr," ]");
    gasp_event_notify(context, GASPI_INIT, GASP_ATOMIC, NULL, 0, 0, argstr);
  }
  context->skipoutput = gaspi_getenvYN(context,"GASP_SKIPOUTPUT",0);
  if (context->skipoutput) fprintf(context->outputfile, "File output disabled by GASP_SKIPOUTPUT\n");
  fflush(context->outputfile);
  return context;
}

void gasp_event_notify(gasp_context_t context, unsigned int evttag, gasp_evttype_t evttype,
                       const char *filename, int linenum, int colnum, ...) {
  va_list argptr;
  va_start(argptr, colnum); /*  pass in last argument */
    gasp_event_notifyVA(context, evttag, evttype, filename, linenum, colnum, argptr);
  va_end(argptr);
}

void gasp_event_notifyVA(gasp_context_t context, unsigned int evttag, gasp_evttype_t evttype,
                         const char *filename, int linenum, int colnum, va_list argptr) { 
  gasp_tick_t curtime;
  const char *typestr = "<unknown type>";
  const char *tagstr = "<unknown tag>";
  const char *argstr = "";
  int is_user_evt = 0;

  assert(context);
  if (!context->enabled) return; /* disabled by control */
  if (context->inupcall) return; /* reentrant call */

  GASPI_UPCALL(context, gaspu_ticks_now(&curtime)); /* get current time */

  switch (evttype) {
    case GASP_START:  typestr = "START";  break;
    case GASP_END:    typestr = "END";    break;
    case GASP_ATOMIC: typestr = "ATOMIC"; break;
  }

  #define _GASPI_TAG(prefix,tag,args,resultargs)                 \
    case prefix##tag: tagstr=#tag;                       \
              if (evttype==GASP_END) argstr=resultargs; \
              else argstr=args;                         \
              break
  #define GASPI_TAG(tag,args,resultargs) _GASPI_TAG(GASP_,tag,args,resultargs)
  #define GASPI_TAG_INTERNAL(tag,args,resultargs) _GASPI_TAG(GASPI_,tag,args,resultargs)

  switch (evttag) { /* define each event and its args - see arg definitions below */
    /* internal tool events */
    GASPI_TAG_INTERNAL(INIT,"s","");
    GASPI_TAG_INTERNAL(CREATE_EVENT,"SSI","");
    GASPI_TAG_INTERNAL(CONTROL,"I","");

    /* system events */
  #ifdef GASP_UPC_ALL_ALLOC
    GASPI_TAG(UPC_ALL_ALLOC,"zz","zzP");
  #endif
  #ifdef GASP_UPC_GLOBAL_ALLOC
    GASPI_TAG(UPC_GLOBAL_ALLOC,"zz","zzP");
  #endif
  #ifdef GASP_UPC_ALLOC
    GASPI_TAG(UPC_ALLOC,"z","zP");
  #endif
  #ifdef GASP_UPC_FREE
    GASPI_TAG(UPC_FREE,"P","P");
  #endif

  #ifdef GASP_BUPC_STATIC_SHARED
    #if GASP_UPC_VERSION >= 0x020311
      GASPI_TAG(BUPC_STATIC_SHARED,"zzPpzss","");
    #else
      GASPI_TAG(BUPC_STATIC_SHARED,"zzPp","");
    #endif
  #endif

  #ifdef GASP_C_FUNC
    GASPI_TAG(C_FUNC,"s","s");
  #endif
  #ifdef GASP_C_MALLOC
    GASPI_TAG(C_MALLOC,"z","zp");
  #endif
  #ifdef GASP_C_REALLOC
    GASPI_TAG(C_REALLOC,"pz","pzp");
  #endif
  #ifdef GASP_C_FREE
    GASPI_TAG(C_FREE,"p","p");
  #endif

  #ifdef GASP_UPC_ALL_LOCK_ALLOC
    GASPI_TAG(UPC_ALL_LOCK_ALLOC,"","K");
  #endif
  #ifdef GASP_UPC_GLOBAL_LOCK_ALLOC
    GASPI_TAG(UPC_GLOBAL_LOCK_ALLOC,"","K");
  #endif
  #ifdef GASP_UPC_LOCK_FREE
    GASPI_TAG(UPC_LOCK_FREE,"K","K");
  #endif

  #ifdef GASP_UPC_LOCK
    GASPI_TAG(UPC_LOCK,"K","K");
  #endif
  #ifdef GASP_UPC_LOCK_ATTEMPT
    GASPI_TAG(UPC_LOCK_ATTEMPT,"K","KI");
  #endif
  #ifdef GASP_UPC_UNLOCK
    GASPI_TAG(UPC_UNLOCK,"K","K");
  #endif

  #ifdef GASP_UPC_NOTIFY
    GASPI_TAG(UPC_NOTIFY,"II","II");
  #endif
  #ifdef GASP_UPC_WAIT
    GASPI_TAG(UPC_WAIT,"II","II");
  #endif

  #ifdef GASP_UPC_MEMGET
    GASPI_TAG(UPC_MEMGET,"pPz","pPz");
  #endif
  #ifdef GASP_UPC_MEMPUT
    GASPI_TAG(UPC_MEMPUT,"Ppz","Ppz");
  #endif
  #ifdef GASP_UPC_MEMCPY
    GASPI_TAG(UPC_MEMCPY,"PPz","PPz");
  #endif
  #ifdef GASP_UPC_MEMSET
    GASPI_TAG(UPC_MEMSET,"PCz","PCz");
  #endif

  #ifdef GASP_UPC_PUT
    GASPI_TAG(UPC_PUT,"IPpz","IPpz");
  #endif
  #ifdef GASP_UPC_GET
    GASPI_TAG(UPC_GET,"IpPz","IpPz");
  #endif
  #ifdef GASP_UPC_NB_GET_INIT
    GASPI_TAG(UPC_NB_GET_INIT,"IpPz","IpPzH");
  #endif
  #ifdef GASP_UPC_NB_PUT_INIT
    GASPI_TAG(UPC_NB_PUT_INIT,"IPpz","IPpzH");
  #endif
  #ifdef GASP_UPC_NB_SYNC
    GASPI_TAG(UPC_NB_SYNC,"H","H");
  #endif
  #ifdef GASP_BUPC_NB_TRYSYNC
    GASPI_TAG(BUPC_NB_TRYSYNC,"H","HI");
  #endif

  #ifdef GASP_BUPC_NB_MEMGET_INIT
    GASPI_TAG(BUPC_NB_MEMGET_INIT,"pPz","pPzH");
  #endif
  #ifdef GASP_BUPC_NB_MEMPUT_INIT
    GASPI_TAG(BUPC_NB_MEMPUT_INIT,"Ppz","PpzH");
  #endif
  #ifdef GASP_BUPC_NB_MEMCPY_INIT
    GASPI_TAG(BUPC_NB_MEMCPY_INIT,"PPz","PPzH");
  #endif

  #ifdef GASP_UPC_COLLECTIVE_EXIT
    GASPI_TAG(UPC_COLLECTIVE_EXIT,"I","I");
  #endif
  #ifdef GASP_UPC_NONCOLLECTIVE_EXIT
    GASPI_TAG(UPC_NONCOLLECTIVE_EXIT,"I","I");
  #endif

  #ifdef GASP_UPC_ALL_BROADCAST
    GASPI_TAG(UPC_ALL_BROADCAST, "PPzF","PPzF");
  #endif
  #ifdef GASP_UPC_ALL_SCATTER
    GASPI_TAG(UPC_ALL_SCATTER,   "PPzF","PPzF");
  #endif
  #ifdef GASP_UPC_ALL_GATHER
    GASPI_TAG(UPC_ALL_GATHER,    "PPzF","PPzF");
  #endif
  #ifdef GASP_UPC_ALL_GATHER_ALL
    GASPI_TAG(UPC_ALL_GATHER_ALL,"PPzF","PPzF");
  #endif
  #ifdef GASP_UPC_ALL_EXCHANGE
    GASPI_TAG(UPC_ALL_EXCHANGE,  "PPzF","PPzF");
  #endif
  #ifdef GASP_UPC_ALL_PERMUTE
    GASPI_TAG(UPC_ALL_PERMUTE,   "PPPzF","PPPzF");
  #endif

  #ifdef GASP_UPC_ALL_REDUCE
    GASPI_TAG(UPC_ALL_REDUCE,       "PPOzzpFR","PPOzzpFR");
  #endif
  #ifdef GASP_UPC_ALL_PREFIX_REDUCE
    GASPI_TAG(UPC_ALL_PREFIX_REDUCE,"PPOzzpFR","PPOzzpFR");
  #endif

    default:
      if (evttag >= GASP_UPC_USEREVT_START &&
        evttag <= GASP_UPC_USEREVT_END) { /* it's a user event */
        int id = evttag - GASP_UPC_USEREVT_START;
        assert(id < context->userevt_cnt);
        tagstr = context->userevt[id].name;
        argstr = context->userevt[id].desc;
        is_user_evt = 1;
      }
  }

  { double cursecs;
    #define BUFSZ 1024
    char buf[BUFSZ]; 
    const char *argp;
    
    /* calculate elapsed seconds since startup */
    GASPI_UPCALL(context,gaspu_ticks_to_sec(curtime - context->starttime, &cursecs));

    sprintf(buf, "%i/%i %0.6f> [%s:%i:%i] %s %-5s { ", 
      context->mythread, context->threads, cursecs,
      (filename?filename:"<unknown>"), linenum, colnum,
      tagstr, typestr);

    if (is_user_evt) { /* user event */
      char *p = buf+strlen(buf);
      int maxsz = BUFSZ - (p - buf);
      int sz = vsnprintf(p, maxsz, argstr, argptr);
      if (sz >= (maxsz-5) || sz < 0) strcpy(p+(maxsz-5),"...");
    } else { /* system event */
      for (argp = argstr; *argp; argp++) {
        #define ARGBUFSZ 255
        char argbuf[ARGBUFSZ];

        switch (*argp) {
          case 'I': sprintf(argbuf, "%i",  (int)          va_arg(argptr, int));           break;
          case 'i': sprintf(argbuf, "%u",  (unsigned int) va_arg(argptr, unsigned int));  break;
          case 'Z': sprintf(argbuf, "%li", (long)         va_arg(argptr, ssize_t));       break;
          case 'z': sprintf(argbuf, "%lu", (unsigned long)va_arg(argptr, size_t));        break;
          case 'L': sprintf(argbuf, "%li", (long)         va_arg(argptr, long));          break;
          case 'l': sprintf(argbuf, "%lu", (unsigned long)va_arg(argptr, unsigned long)); break;
          case 'C': sprintf(argbuf, "%c",  (char)         va_arg(argptr, int));           break;
          case 'p': sprintf(argbuf, "%p",  (void *)       va_arg(argptr, void *));        break;
          case 's': case 'S': { /* char string (unquoted or quoted) */
            const char *p = (char *)       va_arg(argptr, char *);
            sprintf(argbuf, (*argp == 'S'?"\"%s\"":"%s"), (p?p:"(null)"));
            break;
          }
          case 'P': { /* (shared void **) */
            gasp_upc_PTS_t *ppts = va_arg(argptr, gasp_upc_PTS_t *);
            GASPI_UPCALL(context,gaspu_dump_shared(ppts, argbuf, ARGBUFSZ));
            break;
          }
          case 'K': { /* (upc_lock_t **) */
            gasp_upc_lock_t *ppts = va_arg(argptr, gasp_upc_lock_t *);
            GASPI_UPCALL(context,gaspu_dump_shared((gasp_upc_PTS_t *)ppts, argbuf, ARGBUFSZ));
            break;
          }
          case 'H': { /* gasp_upc_nb_handle_t */
            gasp_upc_nb_handle_t h = va_arg(argptr, gasp_upc_nb_handle_t);
            if (h == GASP_UPC_NB_TRIVIAL) {
              strcpy(argbuf, "handle:COMPLETE");
            } else {
              int i;
              char *p = argbuf;
              strcpy(argbuf, "handle:0x");
              p += strlen(argbuf);
              for (i=0; i<sizeof(h); i++) {
                sprintf(p,"%02x",((int)(((char *)&h)[i]))&0x0FF);
                p += strlen(p);
              }
            }
            break;
          }
          case 'F': { /* upc_flag_t (as int) */
            int flags = va_arg(argptr, int);
            GASPI_UPCALL(context,gaspu_flags_to_string(flags, argbuf, ARGBUFSZ));
            break;
          }
          case 'O': { /* upc_op_t (as int) */
            int op = va_arg(argptr, int);
            GASPI_UPCALL(context,gaspu_collop_to_string(op, argbuf, ARGBUFSZ));
            break;
          }
        #if defined(GASP_UPC_ALL_REDUCE) || defined(GASP_UPC_ALL_PREFIX_REDUCE)
          case 'R': { /* gasp_upc_reduce_t */
            gasp_upc_reduction_t redtype = va_arg(argptr, gasp_upc_reduction_t);
            switch (redtype) {
              #define GASPI_REDTYPE(tsuff)  case GASP_UPC_REDUCTION_##tsuff: strcpy(argbuf,#tsuff); break;
              GASPI_REDTYPE(C)
              GASPI_REDTYPE(UC)
              GASPI_REDTYPE(S)
              GASPI_REDTYPE(US)
              GASPI_REDTYPE(I)
              GASPI_REDTYPE(UI)
              GASPI_REDTYPE(L)
              GASPI_REDTYPE(UL)
              GASPI_REDTYPE(F)
              GASPI_REDTYPE(D)
              GASPI_REDTYPE(LD)
              default: gaspi_err("ERROR: unknown reduce type: %i", redtype); 
            }
            break;
          }
        #endif
          default: gaspi_err("ERROR: unknown arg type: %c", *argp); 
        }
        if (argp > argstr) strcat(buf, ", ");
        strcat(buf, argbuf);
      }
    }
    strcat(buf, " }\n");

    if (!context->skipoutput) {
      fputs(buf, context->outputfile);
      if (context->forceflush) fflush(context->outputfile);
    }

    if (evttag == GASP_UPC_COLLECTIVE_EXIT && evttype == GASP_END) {
      /* perform graceful tool shutdown */
      GASPI_UPCALL(context, gaspu_barrier()); /* first, wait for all to arrive */

      /* UPC shutdown semantics already guarantee correct file flush/closure, 
         but do it here anyhow for demonstration purposes */
      fprintf(context->outputfile, "Execution complete: goodbye!\n");
      fclose(context->outputfile);
      context->outputfile = NULL;
      context->enabled = 0;

      GASPI_UPCALL(context, gaspu_barrier()); /* wait for all threads to finish shutdown */
    }
  }
}

