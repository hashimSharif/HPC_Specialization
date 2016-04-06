/*
 * Some generic error handling functions for GASNet
 */

#include <upcr_internal.h>

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h> /* RLIMIT_CORE */
#endif

/* If UPC_ABORT is set, call abort(), to hopefully dump core file.
 * Otherwise, call upcr_global_exit.
 */ 
#if PLATFORM_COMPILER_SUN_C && PLATFORM_ARCH_X86 /* bug1661: workaround sunC optimizer bug */
static void abort_or_exit(void);
#else
static void abort_or_exit(void) GASNETT_NORETURN;
GASNETT_NORETURNP(abort_or_exit)
#endif

static void abort_or_exit(void)
{
    upcri_memcheck_all(); /* check for heap corruption, in case that's the cause of crash */
    fflush(stderr);

    gasnett_freezeForDebuggerErr(); /* allow user freeze */

    gasnett_print_backtrace_ifenabled(STDERR_FILENO);

    if (gasnett_getenv_yesno_withdefault("UPC_ABORT",0)) {
	/* unmask signal, in case gasnet is blocking it */
	signal(SIGABRT, SIG_DFL);
        #ifdef RLIMIT_CORE
          gasnett_maximize_rlimit(RLIMIT_CORE, "RLIMIT_CORE");
        #endif
	abort();
    } else {
	upcr_global_exit(-1);
    }
}

/* format a UPC-level srcpos if we have it */
void
upcri_append_srcloc(char *buf, size_t total_len)
{
#if GASNET_SRCLINES
  size_t offset = strlen(buf);
  const char *file = NULL; unsigned int line = 0;
  GASNETT_TRACE_GETSOURCELINE(&file,&line);
  if (file && file[0] && line) {
    snprintf(buf+offset, total_len-offset, "\n at: %s:%i", file, line);
  }
#endif
}

void 
upcri_err(const char *msg, ...)
{
    va_list args;
    char buf[1000];
    
    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);
    upcri_append_srcloc(buf, sizeof(buf));

    fflush(stdout);
    /* NOTE: the test harness scans for this string */
    fprintf(stderr, "UPC Runtime error: %s\n", buf);
    fflush(stderr);
    abort_or_exit();
}


void 
upcri_errno(const char *msg, ...)
{
    va_list args;
    char buf[1000];

    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);
    upcri_append_srcloc(buf, sizeof(buf));

    fflush(stdout);
    /* NOTE: the test harness scans for this string */
    fprintf(stderr, "UPC Runtime error: %s: %s\n", buf, strerror(errno));
    fflush(stderr);
    abort_or_exit();
}

void 
upcri_gaserr(int gasneterr, const char *msg, ...)
{    
    va_list args;
    char buf[1000];

    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);
    upcri_append_srcloc(buf, sizeof(buf));

    fflush(stdout);
    /* NOTE: the test harness scans for this string */
    fprintf(stderr, "UPC Runtime: GASNet error %s(%s): %s\n", 
	    gasnet_ErrorName(gasneterr), gasnet_ErrorDesc(gasneterr), buf);
    fflush(stderr);
    abort_or_exit();
}

void 
upcri_early_err(const char *msg, ...) 
{
    va_list args;
    char buf[1000];
    
    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);

    fflush(stdout);
    /* NOTE: the test harness scans for this string */
    fprintf(stderr, "UPC Runtime error: %s\n", buf);
    fflush(stderr);

    exit(-1);
}

void 
upcri_warn(const char *msg, ...)
{
    va_list args;
    char buf[1000];
    
    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);

    fprintf(stderr, "UPC Runtime warning: %s\n", buf);
    fflush(stderr);
    if (gasnett_getenv_yesno_withdefault("UPC_WARN_FATAL",0)) {
      abort_or_exit();
    } 
}

#ifdef GASNET_TRACE
extern void upcri_trace_printf_user(const char *format, ...) {
    #define TMPBUFSZ 1024
    char output[TMPBUFSZ];
    va_list argptr;
    va_start(argptr, format); /*  pass in last argument */
      { int sz = vsnprintf(output, TMPBUFSZ, format, argptr);
        if (sz >= (TMPBUFSZ-5) || sz < 0) strcpy(output+(TMPBUFSZ-5),"...");
      }
    va_end(argptr);
    UPCRI_TRACE_PRINTF_NOPOS(("USERMSG: %s",output));
    #undef TMPBUFSZ
}
#endif

extern void bupc_trace_setmask(const char *newmask) {
  GASNETT_TRACE_SETMASK(newmask);
}
extern void bupc_stats_setmask(const char *newmask) {
  GASNETT_STATS_SETMASK(newmask);
}
extern const char *bupc_trace_getmask(void) {
  return GASNETT_TRACE_GETMASK();
}
extern const char *bupc_stats_getmask(void) {
  return GASNETT_STATS_GETMASK();
}
extern int bupc_trace_gettracelocal(void) {
  int val = GASNETT_TRACE_GET_TRACELOCAL();
  return val;
}
extern void bupc_trace_settracelocal(int val) {
  #ifdef GASNET_TRACE
    upcri_trace_suppresslocal = !val;
  #endif
  GASNETT_TRACE_SET_TRACELOCAL(val);
}

#ifdef GASNET_STATS
int upcri_stats_enabled = 0;
uint64_t upcri_stat_mallocsz = 0;
extern void upcri_stats_finish(void (*stat_printf)(const char *, ...)) {
  /* callback invoked by GASNet at shutdown when stats enabled */
  int i;
  stat_printf("UPCR Statistical Summary:");
  stat_printf("");
  stat_printf("Private memory utilization:");
  #if UPCR_DEBUGMALLOC
    if (upcri_debug_malloc) {
      gasnett_heapstats_t stats;
      gasnett_getheapstats(&stats);
      stat_printf(" malloc() space used:         %10lu bytes, in %10lu objects", 
        (unsigned long)stats.live_bytes, (unsigned long)stats.live_objects);
      stat_printf(" malloc() space freed:        %10lu bytes, in %10lu objects", 
        (unsigned long)stats.freed_bytes, (unsigned long)stats.freed_objects);
      stat_printf(" malloc() space peak usage:   %10lu bytes,    %10lu objects", 
        (unsigned long)stats.live_bytes_max, (unsigned long)stats.live_objects_max);
      stat_printf(" malloc() system overhead: >= %10lu bytes", 
        (unsigned long)stats.overhead_bytes);
    } else 
  #endif
      stat_printf(" total malloc() bytes: %lu", (long unsigned)upcri_stat_mallocsz);
  stat_printf("");
  if (gasnet_mynode() == 0) { /* shared heap stats currently only supported on node 0 */
    char prefix[10];
    char buf[1024];
    snprintf(prefix,sizeof(prefix),"%i>  ", (int)gasnet_mynode());
    upcri_getheapstats(prefix, buf, 1024);
    stat_printf("Shared memory utilization:\n%s", buf);
    stat_printf("");
  }

  stat_printf("upc_lock_t utilization:");
  for (i=0; i < upcri_mypthreads(); i++) {
    upcri_lockinfo_t * const li = &(upcri_hisauxdata(i)->lock_info);
    stat_printf(" *** UPC thread %i", (int)(i+upcri_1stthread(gasnet_mynode())));
    stat_printf("  upc_lock_t objects allocated: %4llu", (unsigned long long)li->alloccnt);
    stat_printf("  upc_lock_t objects freed:     %4llu", (unsigned long long)li->freecnt);
    stat_printf("  upc_lock_t acquires:          %4llu local, %4llu remote", 
                (unsigned long long)li->locklocal_cnt, (unsigned long long)li->lockremote_cnt);
    stat_printf("  upc_lock_attempt() failures:  %4llu local, %4llu remote", 
                (unsigned long long)li->lockfaillocal_cnt, (unsigned long long)li->lockfailremote_cnt);
    stat_printf("  upc_unlock() operations:      %4llu local, %4llu remote", 
                (unsigned long long)li->unlocklocal_cnt, (unsigned long long)li->unlockremote_cnt);
    stat_printf("  Time in upc_lock()/upc_lock_attempt(): %4llu us", 
                (unsigned long long)gasnett_ticks_to_us(li->waittime));
  }

  stat_printf("");
  stat_printf("bupc_sem_t utilization:");
  for (i=0; i < upcri_mypthreads(); i++) {
    #define UPCRI_STAT_DIV(a,b) ((b) == 0 ? 0 : ((double)(a))/(b))
    upcri_seminfo_t * const si = &(upcri_hisauxdata(i)->sem_info);
    stat_printf(" *** UPC thread %i", (int)(i+upcri_1stthread(gasnet_mynode())));
    stat_printf("  bupc_sem_t objects allocated:   %4llu", (unsigned long long)si->alloc_cnt);
    stat_printf("  bupc_sem_t objects freed:       %4llu", (unsigned long long)si->free_cnt);
    stat_printf("  bupc_sem_post[N] ops:           %4llu local, %4llu remote", 
                (unsigned long long)si->postlocal_cnt, (unsigned long long)si->postremote_cnt);
    stat_printf("  bupc_memput_signal[_async] ops: %4llu local, %4llu remote", 
                (unsigned long long)si->putsignallocal_cnt, (unsigned long long)si->putsignalremote_cnt);
    stat_printf("  bupc_memput_signal[_async] avg sz (bytes): %8.3f local, %8.3f remote", 
                UPCRI_STAT_DIV(si->putsignallocal_databytes,si->putsignallocal_cnt), 
                UPCRI_STAT_DIV(si->putsignalremote_databytes,si->putsignalremote_cnt));
    stat_printf("  bupc_sem_wait[N] ops:           %4llu local, %4llu remote", 
                (unsigned long long)si->waitlocal_cnt, (unsigned long long)si->waitremote_cnt);
    stat_printf("  bupc_sem_try[N] ops:            %4llu local, %4llu remote", 
                (unsigned long long)si->trylocal_cnt, (unsigned long long)si->tryremote_cnt);
    stat_printf("  bupc_sem_try[N] failures:       %4llu local, %4llu remote", 
                (unsigned long long)si->trylocal_failure_cnt, (unsigned long long)si->tryremote_failure_cnt);
    stat_printf("  Time in upc_sem_try/wait[N]:    %4llu us total, %.3f us avg", 
                (unsigned long long)gasnett_ticks_to_us(si->waittime),
                UPCRI_STAT_DIV(gasnett_ticks_to_us(si->waittime),
                (si->waitlocal_cnt+si->trylocal_cnt+si->waitremote_cnt+si->tryremote_cnt)));
    stat_printf("  bupc_sem tinypacket connection: %4llu incoming, %4llu outgoing", 
                (unsigned long long)si->tinypacket_incoming_connections,
                (unsigned long long)si->tinypacket_outgoing_connections);
    stat_printf("  bupc_sem tinypacket sends:      %4llu", 
                (unsigned long long)si->tinypacket_send_cnt);
    stat_printf("  bupc_sem tinypacket backpress:  %4llu", 
                (unsigned long long)si->tinypacket_backpressure_cnt);
    stat_printf("  bupc_sem tinypacket no connect: %4llu", 
                (unsigned long long)si->tinypacket_noconnection_cnt);
    stat_printf("  bupc_sem tinypacket avg datasz: %8.3f bytes", 
                UPCRI_STAT_DIV(si->tinypacket_databytes,si->tinypacket_send_cnt));
    stat_printf("  memput_signal AMShorts:         %4llu", 
                (unsigned long long)si->post_short_cnt);
    stat_printf("  memput_signal AMMediums:        %4llu", 
                (unsigned long long)si->put_medium_cnt);
    stat_printf("  memput_signal AMLongs:          %4llu", 
                (unsigned long long)si->put_long_cnt);
    stat_printf("  memput_signal AMLongAsyncs:     %4llu", 
                (unsigned long long)si->put_longasync_cnt);
  }

}
#endif

void 
upcri_barprintf(const char *msg, ...)
{
    UPCR_BEGIN_FUNCTION();
    va_list args;
    char buf[1000];

    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);

    fflush(stdout);
    if (upcr_mythread() == 0) fprintf(stderr, "%s", buf);
    fflush(stderr);
    UPCRI_SINGLE_BARRIER_WITHCODE(sleep(1));
}

void 
upcri_sleepprintf(const char *msg, ...)
{
    va_list args;
    char buf[1000];

    va_start(args, msg);
    vsnprintf(buf, sizeof(buf), msg, args);
    va_end(args);

    fflush(stdout);
    fprintf(stderr, "%s", buf);
    fflush(stderr);
    sleep(1);
}


