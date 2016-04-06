
/* UPC GASP instrumentation interface support macros */

#if UPCRI_GASP
  #define UPCRI_PEVT_CONTEXT  (upcri_auxdata()->pevt_context)
  #define UPCRI_PEVT_PRAGMA   (upcri_auxdata()->pevt_pragma)
#endif

#if UPCRI_INST_UPCCFLAG
  #define UPCRI_PEVT_PTMP     (*(upcr_shared_ptr_t*)&(upcri_auxdata()->pevt_ptrtmp))
  #define UPCRI_PTHREADINFO_LOOKUPDECL_IFINST UPCRI_PTHREADINFO_LOOKUPDECL

  int upcri_pevt_isinit;
  #define UPCRI_PEVT_ENABLED (UPCRI_PTHREADINFO_VALID() && UPCRI_PEVT_PRAGMA && upcri_pevt_isinit) 
  #define _upcri_pevt_deliver_wloc(tag,startend,file,line) do { \
      upcri_assert(UPCRI_PEVT_ENABLED);                         \
      gasp_event_notify(UPCRI_PEVT_CONTEXT, tag, startend,      \
                        file, line, 0 UPCRI_PEVT_ARGS);         \
      UPCRI_PEVT_PRAGMA = 1; /* fix for gaspu reentrance */     \
  } while (0)
  #define _upcri_pevt_deliver(tag,startend) do {          \
    if (UPCRI_PEVT_ENABLED) {                             \
      const char *_file; unsigned int _line;              \
      GASNETT_TRACE_GETSOURCELINE(&_file,&_line);         \
      _upcri_pevt_deliver_wloc(tag,startend,_file,_line); \
    }                                                     \
  } while (0)
  #define upcri_pevt_start(tag)  _upcri_pevt_deliver(tag,GASP_START)
  #define upcri_pevt_end(tag)    _upcri_pevt_deliver(tag,GASP_END)
  #define upcri_pevt_atomic(tag) _upcri_pevt_deliver(tag,GASP_ATOMIC)
  #define upcri_pevt(tag, profonly_setupcode, code) do {    \
    if (UPCRI_PEVT_ENABLED) {                               \
      const char *_file; unsigned int _line;                \
      GASNETT_TRACE_GETSOURCELINE(&_file,&_line);           \
      profonly_setupcode;                                   \
      _upcri_pevt_deliver_wloc(tag,GASP_START,_file,_line); \
      { code; }                                             \
      _upcri_pevt_deliver_wloc(tag,GASP_END,_file,_line);   \
    } else { code; }                                        \
  } while (0)
  /* set UPCRI_PEVT_PTMP to the displacement-adjusted put/get target */
  #define upcri_pevt_tmp_ssetup(sptr,sptroffset) (               \
    upcri_assert(UPCRI_MAX_SPTRSZ >= sizeof(upcr_shared_ptr_t)), \
    ((sptroffset == 0) ? (UPCRI_PEVT_PTMP = (sptr)) : (          \
      (UPCRI_PEVT_PTMP = upcr_local_to_shared_withphase(         \
        upcri_shared_to_remote_off(sptr,sptroffset),             \
        upcr_phaseof_shared(sptr),                               \
        upcr_threadof_shared(sptr)))))                           \
  )
  #define upcri_pevt_tmp_psetup(sptr,sptroffset) (                            \
    upcri_assert(UPCRI_MAX_SPTRSZ >= sizeof(upcr_shared_ptr_t)),              \
    ((sptroffset == 0) ? (UPCRI_PEVT_PTMP = upcr_pshared_to_shared(sptr)) : ( \
      (UPCRI_PEVT_PTMP = upcr_local_to_shared_withphase(                      \
        upcri_pshared_to_remote_off(sptr,sptroffset),                         \
        0, upcr_threadof_pshared(sptr)))))                                    \
  )
  /* safety mechanism to ensure we never invoke GASP from an AM context */
  #define UPCRI_PEVT_BEGINAMHANDLER                   \
    do { UPCRI_PTHREADINFO_LOOKUPDECL_IFINST();       \
         int _upcri_pevt_oldpragma;                   \
         if (UPCRI_PTHREADINFO_VALID()) {             \
           _upcri_pevt_oldpragma = UPCRI_PEVT_PRAGMA; \
           UPCRI_PEVT_PRAGMA = 0;                     \
         }
  #define UPCRI_PEVT_ENDAMHANDLER                    \
      ; if (UPCRI_PTHREADINFO_VALID())               \
          UPCRI_PEVT_PRAGMA = _upcri_pevt_oldpragma; \
    } while (0)


  typedef struct {
    const char *fnname;
  #if UPCRI_UPC_PTHREADS && UPCRI_PT_PASS_ENABLED
    UPCRI_PT_ARG_FIELD;
  #endif
  } upcri_pevt_fninfo_t;
  extern upcri_pevt_fninfo_t upcri_pevt_beginfn(const char *_fnname UPCRI_PT_ARG);
  extern void upcri_pevt_endfn(const upcri_pevt_fninfo_t *_pfninfo);
  #if UPCRI_INST_FUNCTIONS && !defined(UPCR_NO_SRCPOS)
    #if UPCRI_HAVE_ATTRIBUTE_CLEANUP
      /* catch function exit with gcc 3.4+ cleanup attribute, if available */
      #define _UPCRI_PEVT_BEGINFN() \
        const upcri_pevt_fninfo_t _bupc_fninfo __attribute__((cleanup(upcri_pevt_endfn))) \
                  = upcri_pevt_beginfn(GASNETT_CURRENT_FUNCTION UPCRI_PT_PASS)
      #define UPCRI_PEVT_EXITFN()   ((void)0)
    #else /* use EXIT_FUNCTION support added in runtime spec 3.7 if translator provides it */
      #define _UPCRI_PEVT_BEGINFN() \
        const upcri_pevt_fninfo_t _bupc_fninfo \
                  = upcri_pevt_beginfn(GASNETT_CURRENT_FUNCTION UPCRI_PT_PASS)
      #define UPCRI_PEVT_EXITFN()    upcri_pevt_endfn(&_bupc_fninfo)
    #endif
    #define UPCRI_PEVT_BEGINFN_DECLNOSEMI() ; _UPCRI_PEVT_BEGINFN()
  #else
    #define UPCRI_PEVT_BEGINFN_DECLNOSEMI() 
    #define UPCRI_PEVT_EXITFN()     ((void)0)
  #endif

  #define UPCRI_PT_ARG_ALONE_IFINST  UPCRI_PT_ARG_ALONE
  #define UPCRI_PT_ARG_IFINST        UPCRI_PT_ARG
  #define UPCRI_PT_PASS_ALONE_IFINST UPCRI_PT_PASS_ALONE
  #define UPCRI_PT_PASS_IFINST       UPCRI_PT_PASS

  void upcri_pevt_init(int *pargc, char ***pargv);
  struct upcr_startup_shalloc_S;
  struct upcr_startup_pshalloc_S;
  void upcri_pevt_shalloc(struct upcr_startup_shalloc_S *info);
  void upcri_pevt_pshalloc(struct upcr_startup_pshalloc_S *info);
#else
  #define upcri_pevt_start(tag)   ((void)0)
  #define upcri_pevt_end(tag)     ((void)0)
  #define upcri_pevt_atomic(tag)     ((void)0)
  #define upcri_pevt(tag, profonly_setupcode, code) do { code; } while (0)
  #define UPCRI_PTHREADINFO_LOOKUPDECL_IFINST() const char _bupc_dummy_PTHLOOKUP = \
                                                (char)sizeof(_bupc_dummy_PTHLOOKUP)
  #define UPCRI_PEVT_BEGINAMHANDLER 
  #define UPCRI_PEVT_ENDAMHANDLER
  #define UPCRI_PEVT_BEGINFN_DECL()
  #define UPCRI_PEVT_BEGINFN_DECLNOSEMI()
  #define UPCRI_PEVT_EXITFN()

  #define UPCRI_PT_ARG_ALONE_IFINST
  #define UPCRI_PT_ARG_IFINST
  #define UPCRI_PT_PASS_ALONE_IFINST
  #define UPCRI_PT_PASS_IFINST

  #define upcri_pevt_init(pargc,pargv)      ((void)0)
  #define upcri_pevt_shalloc(info)          ((void)0)
  #define upcri_pevt_pshalloc(info)         ((void)0)
#endif

#if UPCRI_INST_LOCAL
  #define upcri_pevt_start_local(tag)  upcri_pevt_start(tag)
  #define upcri_pevt_end_local(tag)    upcri_pevt_end(tag)
  #define upcri_pevt_atomic_local(tag) upcri_pevt_atomic(tag)
  #define upcri_pevt_local(tag, profonly_setupcode, code) \
          upcri_pevt(tag, profonly_setupcode, code)
#else
  #define upcri_pevt_start_local(tag)  ((void)0)
  #define upcri_pevt_end_local(tag)    ((void)0)
  #define upcri_pevt_atomic_local(tag) ((void)0)
  #define upcri_pevt_local(tag, profonly_setupcode, code) do { code; } while (0)
#endif

/* end-user instrumentation interface: event creation & control */
#if UPCRI_GASP
  unsigned int _pupc_create_event(const char *name, const char *desc UPCRI_PT_ARG);
  int _pupc_control(int on UPCRI_PT_ARG);
  #define pupc_control(on) _pupc_control(on UPCRI_PT_PASS)
  #define pupc_create_event(name, desc) _pupc_create_event(name, desc UPCRI_PT_PASS)
#else
  #define pupc_create_event(name, desc) 0
  #define pupc_control(on)              0
#endif

/* end-user instrumentation interface: event triggerring */
#if UPCRI_INST_UPCCFLAG
  void _pupc_event_start(unsigned int evttag, ...);
  void _pupc_event_end(unsigned int evttag, ...);
  void _pupc_event_atomic(unsigned int evttag, ...);
  #define pupc_event_start  (upcri_srcpos(), _pupc_event_start)
  #define pupc_event_end    (upcri_srcpos(), _pupc_event_end)
  #define pupc_event_atomic (upcri_srcpos(), _pupc_event_atomic)
#else
  /* GASP support is off, define these away to nothing (as nearly as possible) */
  static void _pupc_donothing(unsigned int _evttag, ...) { 
    #if PLATFORM_COMPILER_PGI
      va_list _ap; va_start(_ap,_evttag); va_end(_ap); /* avoid a silly warning */
    #endif
    return; 
  }
  #define pupc_event_start    _pupc_donothing
  #define pupc_event_end      _pupc_donothing
  #define pupc_event_atomic   _pupc_donothing
#endif
