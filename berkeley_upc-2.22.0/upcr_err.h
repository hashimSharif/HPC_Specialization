/*
 * Error handler function for UPC runtime.
 *
 * Jason Duell <jcduell@lbl.gov>
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_err.h $
 */

#ifndef UPCR_ERR_H
#define UPCR_ERR_H

GASNETT_BEGIN_EXTERNC

/* appends source line information (if any) to a string */
void upcri_append_srcloc(char *buf, size_t total_len);

/* prints formatted message to screen, and calls upcr_global_exit(-1) */
GASNETT_FORMAT_PRINTF(upcri_err,1,2,
void upcri_err(const char *msg, ...) GASNETT_NORETURN);
GASNETT_NORETURNP(upcri_err)

/* Also prints strerror(errno) in message */
GASNETT_FORMAT_PRINTF(upcri_errno,1,2,
void upcri_errno(const char *msg, ...) GASNETT_NORETURN);
GASNETT_NORETURNP(upcri_errno)

/* prints message based on GASNet error passed, plus message */
GASNETT_FORMAT_PRINTF(upcri_gaserr,2,3,
void upcri_gaserr(int gasneterr, const char *msg, ...) GASNETT_NORETURN);
GASNETT_NORETURNP(upcri_gaserr)

/* use before gasnet_init has been called */
GASNETT_FORMAT_PRINTF(upcri_early_err,1,2,
void upcri_early_err(const char *msg, ...) GASNETT_NORETURN);
GASNETT_NORETURNP(upcri_early_err)

/* Prints warning */
GASNETT_FORMAT_PRINTF(upcri_warn,1,2,
void upcri_warn(const char *msg, ...));

/* handoff the current #pragma pupc setting to libupcr instrumentation code, if necessary
   and return indication of whether instrumentation is currently enabled in the caller */
#if UPCRI_INST_UPCCFLAG
  /* compilation units where instrumentation is enabled - handoff and return current pragma state */
  /* the comparison against zero silences icc warnings (use of = where == may have been intended) */
  #define upcri_pevt_pragmahandoff()           (0 != (UPCRI_PEVT_PRAGMA = (UPCR_PRAGMA_PUPC)))
  #define UPCR_PRAGMA_PUPC 1  /* this value is undefed and redefed by user's #pragma pupc on/off */
#elif UPCRI_GASP
  /* compilation units where instrumentation is disabled - clear the pragma, but otherwise compile away */
  /* the comparison against zero silences icc warnings (use of = where == may have been intended) */
  #define upcri_pevt_pragmahandoff()           (0 != (UPCRI_PEVT_PRAGMA = 0))
#else
  /* no instrumentation support */
  #define upcri_pevt_pragmahandoff()           (0)
#endif

#if defined(GASNET_TRACE) || (UPCRI_GASP && UPCRI_INST_UPCCFLAG)
  /* srcline tracking is enabled for tracing (globally), 
     libupcr (with GASP) and instrumented app compilation units */
  #define UPCRI_SRCLINES 1
#endif

/* upcri_srcpos(): called from macros which are expanded into generated code (only!)
   to register the current UPC-level source line number with the GASNet srclines system
*/
#if UPCRI_SRCLINES && !defined(UPCR_NO_SRCPOS)
  #if defined(GASNET_TRACE) /* unconditionally register srclines when tracing */
    #define _upcri_dosrcpos(profcond)  ((profcond),GASNETT_TRACE_SETSOURCELINE(__FILE__,__LINE__),0)
  #else /* not tracing, only register srclines when required by profiling */
    #define _upcri_dosrcpos(profcond)  ((profcond)?(GASNETT_TRACE_SETSOURCELINE(__FILE__,__LINE__),0):0)
  #endif
  #define upcri_srcpos()              _upcri_dosrcpos(upcri_pevt_pragmahandoff())
  /* version for use in UPCR_BEGIN_FUNCTION only: */
  #if UPCRI_INST_FUNCTIONS
    #define upcri_srcpos_declnosemi() ; char _bupc_dummy_SRCPOS = upcri_srcpos()
  #else
    #define upcri_srcpos_declnosemi() ; char _bupc_dummy_SRCPOS = _upcri_dosrcpos(0)
  #endif
#else
  #define upcri_srcpos() ((void)0)
  #define upcri_srcpos_declnosemi() 
#endif
#if UPCRI_SRCLINES
  #define UPCR_SET_SRCPOS(file,line) GASNETT_TRACE_SETSOURCELINE(file,line)
#else
  #define UPCR_SET_SRCPOS(file,line)
#endif
#if defined(GASNET_TRACE)
  #define UPCRI_TRACE_PRINTF_NOPOS(parenthesized_args) \
          (GASNETT_TRACE_ENABLED ? GASNETT_TRACE_PRINTF parenthesized_args : ((void)0))
  #define UPCRI_TRACE_PRINTF(parenthesized_args) (upcri_srcpos(), UPCRI_TRACE_PRINTF_NOPOS(parenthesized_args))
  GASNETT_FORMAT_PRINTF(upcri_trace_printf_user,1,2,
  extern void upcri_trace_printf_user(const char *msg, ...));
#else
  #define UPCRI_TRACE_PRINTF_NOPOS(parenthesized_args) ((void)0)
  #define UPCRI_TRACE_PRINTF(parenthesized_args)       ((void)0)
#endif

extern void bupc_trace_setmask(const char *newmask);
extern void bupc_stats_setmask(const char *newmask);
extern const char *bupc_trace_getmask(void);
extern const char *bupc_stats_getmask(void);
extern int bupc_trace_gettracelocal(void);
extern void bupc_trace_settracelocal(int val);

extern int upcri_stats_enabled;
extern void upcri_stats_finish(void (*stat_printf)(const char *, ...));

/*
 * Debug functions
 * ===============
 *
 * Perform barriers and/or short sleep() calls to ensure
 * that output is flushed to stderr in a (probabilistically) sane
 * order--otherwise most parallel job runners may give output that appears to
 * cross barriers, etc., which can be most unhelpful.
 *
 * Note: If you are compiling with GCC, you may use '%S' and '%P' to print out
 * phased and unphased shared pointers (respectively).  Pass the ADDRESS of
 * the shared pointer.
 */

/* Prints printf-like msg to stderr, flushes, does barrier, and sleeps for a
 * second, in herculean effort to provide lockstep debug printouts
 */
GASNETT_FORMAT_PRINTF(upcri_barprintf,1,2,
void upcri_barprintf(const char *msg, ...));

/* Same as upcri_barprintf, but doesn't do barrier.  Use when printing from
 * non-collective point in execution.
 */
GASNETT_FORMAT_PRINTF(upcri_sleepprintf,1,2,
void upcri_sleepprintf(const char *msg, ...));

GASNETT_END_EXTERNC

#endif /* UPCR_ERR_H */
