
/* UPC GASP instrumentation support */

#include <upcr_internal.h>

#if UPCRI_GASP
  unsigned int _pupc_create_event(const char *name, const char *desc UPCRI_PT_ARG) {
    return gasp_create_event(UPCRI_PEVT_CONTEXT, name, desc);
  }
  int _pupc_control(int on UPCRI_PT_ARG) { 
    return gasp_control(UPCRI_PEVT_CONTEXT, on);
  }
  #define UPCRI_USER_NOTIFY(fnname,evttype)                      \
    void fnname(unsigned int evttag, ...) {                      \
      UPCRI_PTHREADINFO_LOOKUPDECL();                            \
      va_list argptr;                                            \
      const char *file; unsigned int line;                       \
      upcri_assert(UPCRI_PTHREADINFO_VALID());                   \
      upcri_assert(evttag >= GASP_UPC_USEREVT_START);            \
      upcri_assert(evttag <= GASP_UPC_USEREVT_END);              \
      GASNETT_TRACE_GETSOURCELINE(&file,&line);                  \
      va_start(argptr, evttag); /*  pass in last argument */     \
        gasp_event_notifyVA(UPCRI_PEVT_CONTEXT, evttag, evttype, \
                            file, line, 0, argptr);              \
      va_end(argptr);                                            \
    }
  UPCRI_USER_NOTIFY(_pupc_event_start, GASP_START)
  UPCRI_USER_NOTIFY(_pupc_event_end, GASP_END)
  UPCRI_USER_NOTIFY(_pupc_event_atomic, GASP_ATOMIC)

  extern upcri_pevt_fninfo_t upcri_pevt_beginfn(const char *_fnname UPCRI_PT_ARG) {
  #if HAVE_NONCONST_STRUCT_INIT
    upcri_pevt_fninfo_t info = { _fnname UPCRI_PT_PASS };
  #else
    upcri_pevt_fninfo_t info;
    info.fnname = _fnname;
   #if UPCRI_UPC_PTHREADS && UPCRI_PT_PASS_ENABLED
    info._upcr_pthreadinfo = _upcr_pthreadinfo;
   #endif
  #endif
    #define UPCRI_PEVT_ARGS , _fnname
    upcri_pevt_start(GASP_C_FUNC);
    #undef UPCRI_PEVT_ARGS
    return info;
  }
  extern void upcri_pevt_endfn(const upcri_pevt_fninfo_t *_pfninfo) {
    #if UPCRI_UPC_PTHREADS && UPCRI_PT_PASS_ENABLED
      UPCRI_PT_ARG_ALONE = _pfninfo->_upcr_pthreadinfo;
    #endif
    #define UPCRI_PEVT_ARGS , _pfninfo->fnname
    upcri_pevt_end(GASP_C_FUNC);
    #undef UPCRI_PEVT_ARGS
  }
  typedef struct  {
     upcr_startup_shalloc_t info;
     upcr_shared_ptr_t ptr;
  } upcri_info_cache_t;
  static upcri_info_cache_t *info_cache = NULL;
  static size_t info_cache_len = 0;
  static size_t info_cache_sz = 0;
  static upcri_info_cache_t *upcri_pevt_allocpush(size_t count) {
    upcri_info_cache_t *result;
    while (info_cache_len+count > info_cache_sz) {
      upcri_info_cache_t *old = info_cache;
      info_cache_sz = (info_cache_sz*2)+1;
      info_cache = UPCRI_XMALLOC(upcri_info_cache_t, info_cache_sz);
      if (old) memcpy(info_cache, old, sizeof(upcri_info_cache_t)*info_cache_len);
    }
    result = info_cache+info_cache_len;
    info_cache_len += count;
    return result;
  }
  void upcri_pevt_shalloc(upcr_startup_shalloc_t *info) {
    size_t count = 1;
    upcri_info_cache_t *p = upcri_pevt_allocpush(count);
    size_t i;
    for (i=0; i < count; i++) {
      p[i].info = info[i];
      p[i].ptr = *(info[i].sptr_addr);
    }
  }
  void upcri_pevt_pshalloc(upcr_startup_pshalloc_t *info) {
    size_t count = 1;
    upcri_info_cache_t *p = upcri_pevt_allocpush(count);
    size_t i;
    for (i=0; i < count; i++) {
      p[i].info = ((upcr_startup_shalloc_t *)info)[i];
      p[i].ptr = upcr_pshared_to_shared(*(info[i].psptr_addr));
    }
  }
  void upcri_pevt_init(int *pargc, char ***pargv) {
    UPCR_BEGIN_FUNCTION();
    size_t i;
    UPCRI_PEVT_CONTEXT = gasp_init(GASP_MODEL_UPC, pargc, pargv);
    UPCRI_SINGLE_BARRIER();
    upcri_pthread_barrier(); /* bug 1637 - ensure all threads have passed barrier_wait evt */
    upcri_pevt_isinit = 1;
    UPCRI_PEVT_PRAGMA = 1; /* bug 1641 - enable instrumentation pragma */

    for (i = 0; i < info_cache_len; i++) {
      upcri_info_cache_t *p = &info_cache[i];
      size_t nblocks = p->info.numblocks;
      size_t nbytes = p->info.blockbytes;
      upcr_shared_ptr_t ptr = p->ptr;
      void *staticsymbol = p->info.sptr_addr;
      size_t elemsz = p->info.elemsz;
      const char *namestr = p->info.namestr;
      const char *typestr = p->info.typestr;
      if (p->info.mult_by_threads) nblocks *= upcr_threads();
      #define UPCRI_PEVT_ARGS , nblocks, nbytes, &ptr, staticsymbol, elemsz, namestr, typestr
      upcri_pevt_atomic(GASP_BUPC_STATIC_SHARED);
      #undef UPCRI_PEVT_ARGS
    }
  }
#endif
