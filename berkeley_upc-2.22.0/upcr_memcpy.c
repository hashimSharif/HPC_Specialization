/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_memcpy.c $
 * Description: 
 * Non-blocking memcpy extensions, a Berkeley UPC extension - 
 * see: Bonachea, D. "Proposal for Extending the UPC Memory Copy Library Functions"
 *  available at http://upc.lbl.gov/publications/
 *
 * Copyright 2004, Dan Bonachea <bonachea@cs.berkeley.edu>
 */

#include <upcr.h>
#include <upcr_internal.h>
#include <gasnet_vis.h>

/*---------------------------------------------------------------------------------*/
#define UPCRI_TINY_EOP ((bupc_handle_t)0x8) /* set in the next field for 0-space eops */
#define UPCRI_HANDLE_EOL(h) ((h) <= UPCRI_TINY_EOP)

/* we keep a per-thread freelist of the "tiny" eops - those that just hold a handle,
   since the space overhead is negligble and they are commonly used for contiguous operations
 */

#define upcri_newhandle(extraspace) _upcri_newhandle(extraspace UPCRI_PT_PASS)
GASNETT_INLINE(_upcri_newhandle)
bupc_handle_t _upcri_newhandle(size_t extraspace UPCRI_PT_ARG) {
  bupc_handle_t h;
#if UPCRI_SUPPORT_PTHREADS && !UPCRI_UPC_PTHREADS
  /* Potentially have multiple phtreads per UPC thread.
     TODO: rather than disable the freelist we could either:
           + mutex-protect the one freelist
           + implement per-pthread freelists
   */
  h = upcri_malloc(sizeof(upcri_eop)+extraspace);
  h->next = BUPC_COMPLETE_HANDLE;
#else
  if (extraspace == 0 && (h = upcri_auxdata()->eop_freelist) != NULL) {
    upcri_auxdata()->eop_freelist = h->next;
    h->next = UPCRI_TINY_EOP;
  } else {
    h = upcri_malloc(sizeof(upcri_eop)+extraspace);
    h->next = extraspace ? BUPC_COMPLETE_HANDLE : UPCRI_TINY_EOP;
  }
#endif
  return h;
}

#define upcri_freehandlelist(h) _upcri_freehandlelist(h UPCRI_PT_PASS)
GASNETT_INLINE(_upcri_freehandlelist)
void _upcri_freehandlelist(bupc_handle_t h UPCRI_PT_ARG) {
  while (h != BUPC_COMPLETE_HANDLE) {
    bupc_handle_t const next = h->next;
#if UPCRI_SUPPORT_PTHREADS && !UPCRI_UPC_PTHREADS
    upcri_assert(next != UPCRI_TINY_EOP);
#else
    if (next == UPCRI_TINY_EOP) { /* end of list is a tiny eop */
      h->next = upcri_auxdata()->eop_freelist;
      upcri_auxdata()->eop_freelist = h;
      break;
    } else
#endif
    {
      upcri_free(h);
    }
    h = next;
  }
}

extern void _upcr_waitsync(bupc_handle_t h UPCRI_PT_ARG) {
  bupc_handle_t hp;
  if (h == BUPC_COMPLETE_HANDLE) return;
  upcri_assert(h != UPCRI_TINY_EOP);
  hp = h;
  while (!UPCRI_HANDLE_EOL(hp)) {
    upcr_wait_syncnb(hp->handle);
    hp = hp->next;
  }
  upcri_freehandlelist(h);
}
extern int _upcr_trysync(bupc_handle_t h UPCRI_PT_ARG) {
  bupc_handle_t hp;
  if (h == BUPC_COMPLETE_HANDLE) return 1;
  upcri_assert(h != UPCRI_TINY_EOP);
  hp = h;
  while (!UPCRI_HANDLE_EOL(hp)) { 
    if (upcr_try_syncnb(hp->handle)) {
      hp->handle = GASNET_INVALID_HANDLE;
      hp = hp->next;
    } else return 0; /* some entry still in flight */
  }
  upcri_freehandlelist(h);
  return 1;
}

extern void _bupc_waitsync_all (bupc_handle_t *_ph, size_t _n UPCRI_PT_ARG) {
  size_t i;
  upcri_assert(_n > 0 && _ph);
  for (i=0; i < _n; i++) {
    _upcr_waitsync(_ph[i] UPCRI_PT_PASS);
    _ph[i] = BUPC_COMPLETE_HANDLE;
  }
}
extern int  _bupc_trysync_all  (bupc_handle_t *_ph, size_t _n UPCRI_PT_ARG) {
  size_t i;
  upcri_assert(_n > 0 && _ph);
  for (i=0; i < _n; i++) {
    bupc_handle_t const h = _ph[i];
    if (h == BUPC_COMPLETE_HANDLE) ;
    else if (_upcr_trysync(h UPCRI_PT_PASS)) { /* found complete */
      _ph[i] = BUPC_COMPLETE_HANDLE;
    } else { /* found incomplete */
      return 0;
    }
  }
  return 1;
}
extern void _bupc_waitsync_some(bupc_handle_t *_ph, size_t _n UPCRI_PT_ARG) {
  upcri_assert(_n > 0 && _ph);
  while (!_bupc_trysync_some(_ph, _n UPCRI_PT_PASS)) {
    if (upcri_polite_wait) gasnett_sched_yield(); /* spin-wait */
    gasnett_spinloop_hint();
  }
}
extern int  _bupc_trysync_some (bupc_handle_t *_ph, size_t _n UPCRI_PT_ARG) {
  size_t i;
  int success = 0;
  int empty = 1;
  upcri_assert(_n > 0 && _ph);
  for (i=0; i < _n; i++) {
    bupc_handle_t const h = _ph[i];
    if (h != BUPC_COMPLETE_HANDLE) {
      empty = 0;
      if (_upcr_trysync(h UPCRI_PT_PASS)) { /* found complete */
        _ph[i] = BUPC_COMPLETE_HANDLE;
        success = 1;
      }
    }
  }

  if (success || empty) return 1;
  else return 0;
}

/*---------------------------------------------------------------------------------*/

#define UPCRI_EOP_ENCAPSULATE(operation) do {                      \
    gasnet_handle_t const tmp = operation;                         \
    if (tmp == GASNET_INVALID_HANDLE) return BUPC_COMPLETE_HANDLE; \
    else {                                                         \
      bupc_handle_t h = upcri_newhandle(0);                        \
      h->handle = tmp;                                             \
      return h;                                                    \
    }                                                              \
  } while (0)

extern bupc_handle_t _upcr_memcpy_nb(upcr_shared_ptr_t dst, upcr_shared_ptr_t src, size_t n UPCRI_PT_ARG) {
  UPCRI_EOP_ENCAPSULATE(_upcr_nb_memcpy(dst, src, n UPCRI_PT_PASS));
}

extern bupc_handle_t _upcr_memget_nb(void *dst, upcr_shared_ptr_t src, size_t n UPCRI_PT_ARG) {
  UPCRI_EOP_ENCAPSULATE(_upcr_nb_memget(dst, src, n UPCRI_PT_PASS));
}

extern bupc_handle_t _upcr_memput_nb(upcr_shared_ptr_t dst, const void *src, size_t n UPCRI_PT_ARG) {
  UPCRI_EOP_ENCAPSULATE(_upcr_nb_memput(dst, (void *)src, n UPCRI_PT_PASS));
}

extern bupc_handle_t _upcr_memset_nb(upcr_shared_ptr_t dst, int c, size_t n UPCRI_PT_ARG) {
  UPCRI_EOP_ENCAPSULATE(_upcr_nb_memset(dst, c, n UPCRI_PT_PASS));
}

extern bupc_handle_t _bupc_end_accessregion(UPCRI_PT_ARG_ALONE) {
  UPCRI_EOP_ENCAPSULATE(_upcr_end_nbi_accessregion(UPCRI_PT_PASS_ALONE));
}

/*---------------------------------------------------------------------------------*/
/* VIS extensions */
/*---------------------------------------------------------------------------------*/
/* Design approach:
   Runtime needs to translate a list of src/dst pointer-to-shared addresses, 
   (possibly each pointing to a different remote node) into a list of virtual 
   addresses for the remote node, with requests binned by each remote node for use
   in point-to-point GASNet calls.
   Current approach is to allocate a new binning buffer for each GASNet request we will make
   We take an object-oriented style approach for the handles
   The sync functions treat all handles as linked lists of (upcri_eop *)'s
   The VIS functions construct upcri_vlist_t and upcri_ilist_t objects 
   (which are derived classes of the abstract base class upcri_list_t, 
   which is itself a derived class of upcri_eop)
   The flags block in upcri_list_t tells whether the entry is a upcri_vlist_t or upcri_ilist_t
   We also allow upcri_eop entries in the chain with no associated GASNet request
   (handle is GASNET_INVALID_HANDLE) which are used merely to hold metadata

   Note for future possible enhancement: 
   We could get better buffer space utilization (about 50% reduction) at the cost of 
   considerable additional complexity to the logic and scrambling the user's access pattern,
   by filling the binning buffers in use from both ends towards the middle.
 */
  /* TODO: do we need to call upcri_strictflush() in any of these VIS functions? */
typedef struct {
  upcri_eop eop; /* must come first */
  uint32_t flags;    
  gasnet_node_t remotenode;
  /* ---------------------- */
} upcri_list_t;
#define UPCRI_LISTFLAG_VECTOR   1 /* list entry is a vlist (otherwise is an ilist) */
typedef struct {
  upcri_eop eop; /* must come first */
  uint32_t flags;    
  gasnet_node_t remotenode;
  /* ---------------------- */

  size_t remotecount; /* num active entries */
  #if UPCR_DEBUG
    size_t remotesize;  /* num allocated entries */
  #endif
  gasnet_memvec_t *remotelist;

  size_t localcount; /* num active entries */
  #if UPCR_DEBUG
    size_t localsize;  /* num allocated entries */
  #endif
  gasnet_memvec_t *locallist;

} upcri_vlist_t;

typedef struct {
  upcri_eop eop; /* must come first */
  uint32_t flags;    
  gasnet_node_t remotenode;
  /* ---------------------- */

  size_t remotecount; /* num active entries */
  #if UPCR_DEBUG
    size_t remotesize;  /* num allocated entries */
  #endif
  void **remotelist;
  size_t remotelen; 

  size_t localcount; /* num active entries */
  #if UPCR_DEBUG
    size_t localsize;  /* num allocated entries */
  #endif
  void **locallist;
  size_t locallen;

} upcri_ilist_t;

#if BUPC_SG_DESIGN_A
  extern bupc_handle_t _bupc_memcpy_vlist_async(size_t dstcount, bupc_smemvec_t const dstlist[], 
                                     size_t srccount, bupc_smemvec_t const srclist[] UPCRI_PT_ARG) {
    int i;
    uintptr_t datasz = 0;
    UPCRI_PASS_GAS();
    gasnet_node_t mynode = gasnet_mynode();
    { /* try to convert into a pure memput or memget */
      bupc_handle_t h = upcri_newhandle(MAX(dstcount,srccount)*sizeof(bupc_pmemvec_t));
      bupc_pmemvec_t *locallist = (bupc_pmemvec_t *)upcri_eop_metadata(h);

      for (i = 0; i < srccount; i++) {
        bupc_smemvec_t saddr = srclist[i];
        if (saddr.len > 0 && upcri_shared_nodeof(saddr.addr) != mynode) break; /* remote address */
        locallist[i].addr = upcri_shared_to_remote(saddr.addr);
        locallist[i].len = saddr.len;
      }
      if (i == srccount) { /* src entirely local */
        h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the metadata memory */
        h->next = _bupc_memput_vlist_async(dstcount, dstlist, srccount, locallist UPCRI_PT_PASS);
        return h;
      }

      for (i = 0; i < dstcount; i++) {
        bupc_smemvec_t saddr = dstlist[i];
        if (saddr.len > 0 && upcri_shared_nodeof(saddr.addr) != mynode) break; /* remote address */
        locallist[i].addr = upcri_shared_to_remote(saddr.addr);
        locallist[i].len = saddr.len;
        datasz += saddr.len;
      }
      if (i == dstcount) { /* dst entirely local */
        h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the metadata memory */
        h->next = _bupc_memget_vlist_async(dstcount, locallist, srccount, srclist UPCRI_PT_PASS);
        return h;
      } else { /* finish computing datasz, which we'll need in a moment */
        for (; i < dstcount; i++) {
          datasz += dstlist[i].len;
        }
      }

      upcri_free(h);
    }

    /* Not a pure put or get: involves one or more remote nodes in both src & dst 
         so decompose it into a get to temp followed by put from temp
       Future work: decompose the operation into sub-operations (over smaller range) where
         each is a pure put, pure get, or 3rd party xfer
     */
    { bupc_handle_t h = upcri_newhandle(datasz+sizeof(bupc_pmemvec_t));
      bupc_pmemvec_t *tmplist = (bupc_pmemvec_t*)upcri_eop_metadata(h);
      char *tmpdata = upcri_eop_metadata(h)+sizeof(bupc_pmemvec_t);
      tmplist->addr = tmpdata;
      tmplist->len = datasz;
      _upcr_waitsync(
        _bupc_memget_vlist_async(1, tmplist, srccount, srclist 
        UPCRI_PT_PASS) UPCRI_PT_PASS);
      h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the bounce buffer and metadata memory */
      h->next = _bupc_memput_vlist_async(dstcount, dstlist, 1, tmplist UPCRI_PT_PASS);
      return h;
    }
  }

  /* bin the remote addresses into separate per-node operations and convert all shared ptrs to VA's 
     returns a linked list of bins (or NULL for an empty transfer)
   */
  static upcri_vlist_t *upcri_convertandbin_vlist(size_t const remotecount, bupc_smemvec_t const *remotelist,
                                                  size_t const localcount, bupc_pmemvec_t const *locallist) {
    upcri_vlist_t *all_vl = NULL;
    ssize_t localidx = -1, remoteidx = -1;
    gasnet_node_t cur_remotenode;
    gasnet_memvec_t cur_remotevec;
    gasnet_memvec_t cur_localvec;
    upcri_vlist_t *cur_vl = NULL;
    upcri_assert(sizeof(bupc_pmemvec_t) == sizeof(gasnet_memvec_t));

    #define ADVANCE_LOCAL() do { /* advance position, pass empties, update curvec */   \
        localidx++;                                                                    \
        while (localidx < localcount &&                                                \
              ((cur_localvec=locallist[localidx]), cur_localvec.len == 0)) localidx++; \
        upcri_assert(localidx >= 0 && localidx <= localcount);                         \
      } while (0)
    #define ADVANCE_REMOTE() do {  /* advance position, pass empties, update curvec */          \
        bupc_smemvec_t remoteentry;                                                             \
        remoteidx++;                                                                            \
        while (remoteidx < remotecount &&                                                       \
               (remoteentry=remotelist[remoteidx], remoteentry.len == 0)) remoteidx++;          \
        if (remoteidx < remotecount) {                                                          \
          cur_remotenode = upcri_shared_nodeof(remoteentry.addr);                               \
          cur_remotevec.addr = upcri_shared_to_remote(remoteentry.addr);                        \
          cur_remotevec.len = remoteentry.len;                                                  \
          /* find the appropriate bin, creating it if necessary */                              \
          if (cur_vl == NULL || cur_vl->remotenode != cur_remotenode) {                         \
            cur_vl = all_vl;                                                                    \
            while (cur_vl != NULL && cur_vl->remotenode != cur_remotenode)                      \
              cur_vl = (upcri_vlist_t*)(cur_vl->eop.next);                                      \
            if (cur_vl == NULL) {                                                               \
              upcri_assert(localidx >= 0);                                                      \
              /* worst-case fragmentation: locals break at each remote break */                 \
              cur_vl = upcri_malloc(sizeof(upcri_vlist_t) +                                     \
                   (2*(remotecount-remoteidx) + localcount-localidx)*sizeof(gasnet_memvec_t));  \
              cur_vl->remotenode = cur_remotenode;                                              \
              cur_vl->flags = UPCRI_LISTFLAG_VECTOR;                                            \
              cur_vl->localcount = 0; cur_vl->remotecount = 0;                                  \
              UPCRI_DEBUG_DO(cur_vl->localsize = (localcount-localidx)+(remotecount-remoteidx); \
                             cur_vl->remotesize = (remotecount-remoteidx););                    \
              cur_vl->locallist = (gasnet_memvec_t *)(cur_vl+1);                                \
              cur_vl->remotelist = ((gasnet_memvec_t *)cur_vl->locallist)+                      \
                                   (localcount-localidx)+(remotecount-remoteidx);               \
              cur_vl->eop.next = (upcri_eop *)all_vl;                                           \
              all_vl = cur_vl;                                                                  \
            }                                                                                   \
          }                                                                                     \
        }                                                                                       \
        upcri_assert(remoteidx >= 0 && remoteidx <= remotecount);                               \
      } while (0)

    #define UPCRI_VLIST_BIN() do {                                                       \
        size_t localoffset = 0, remoteoffset = 0;                                        \
        ADVANCE_LOCAL(); ADVANCE_REMOTE();                                               \
        while (remoteidx < remotecount) {                                                \
          const size_t localremain = cur_localvec.len - localoffset;                     \
          const size_t remoteremain = cur_remotevec.len - remoteoffset;                  \
          upcri_assert(localidx < localcount);                                           \
          upcri_assert(localremain > 0 && remoteremain > 0);                             \
                                                                                         \
          if (remoteremain <= localremain) { /* remote input break */                    \
            cur_vl->remotelist[cur_vl->remotecount++] = cur_remotevec;                   \
            upcri_assert(cur_vl->remotecount <= cur_vl->remotesize);                     \
            if (remoteremain == localremain) { /* also a local input break */            \
              cur_vl->locallist[cur_vl->localcount++] = cur_localvec;                    \
              upcri_assert(cur_vl->localcount <= cur_vl->localsize);                     \
              ADVANCE_LOCAL();                                                           \
              localoffset = 0;                                                           \
            } else {                                                                     \
              /* cannot be the last one, or we'd also have a local input break */        \
              upcri_assert(remoteidx < remotecount-1);                                   \
              if (upcri_shared_nodeof(GET_REMOTE_SPTR(remoteidx+1)) != cur_remotenode) { \
                /* about to cross a node boundary with remotes - force a local break */  \
                size_t localamt = localoffset+remoteremain;                              \
                cur_vl->locallist[cur_vl->localcount].addr = cur_localvec.addr;          \
                cur_vl->locallist[cur_vl->localcount].len = localamt;                    \
                cur_vl->localcount++;                                                    \
                upcri_assert(cur_vl->localcount <= cur_vl->localsize);                   \
                cur_localvec.addr = (void*)(((uintptr_t)cur_localvec.addr)+localamt);    \
                cur_localvec.len -= localamt;                                            \
                upcri_assert(cur_localvec.len > 0);                                      \
                localoffset = 0;                                                         \
              } else localoffset += remoteremain;                                        \
            }                                                                            \
            ADVANCE_REMOTE(); /* must come after the local pushes to cur_vl */           \
            remoteoffset = 0;                                                            \
          } else { /* simple local input break */                                        \
            upcri_assert(localremain < remoteremain);                                    \
            cur_vl->locallist[cur_vl->localcount++] = cur_localvec;                      \
            upcri_assert(cur_vl->localcount <= cur_vl->localsize);                       \
            ADVANCE_LOCAL();                                                             \
            localoffset = 0;                                                             \
            remoteoffset += localremain;                                                 \
          }                                                                              \
        }                                                                                \
        upcri_assert(localidx == localcount && remoteidx == remotecount);                \
        upcri_assert(localoffset == 0);                                                  \
      } while (0)

    #define GET_REMOTE_SPTR(idx) (remotelist[(idx)].addr)

    UPCRI_VLIST_BIN();

    #undef GET_REMOTE_SPTR
    #undef ADVANCE_LOCAL
    #undef ADVANCE_REMOTE

    #ifdef UPCR_DEBUG
      { /* verify sanity
         * some of these checks may need to be weakened in the future,
         * if we add a more aggressive binning algorithm
         */
        upcri_vlist_t *cur_vl = all_vl;
        uintptr_t totalsz = 0;
        uintptr_t totalsz_input = 0;
        uintptr_t maxlocal = 0;
        uintptr_t maxremote = 0;
        size_t i;
        for (i=0; i < localcount; i++) {
          totalsz_input += locallist[i].len;
          if (locallist[i].len > maxlocal) maxlocal = locallist[i].len;
        }
        for (i=0; i < remotecount; i++) {
          if (remotelist[i].len > maxremote) maxremote = remotelist[i].len;
        }
        while (cur_vl) {
          size_t i;
          uintptr_t cur_localsz = 0;
          uintptr_t cur_remotesz = 0;
          gasnet_node_t node = cur_vl->remotenode;
          upcri_vlist_t *tmp_vl = (upcri_vlist_t*)cur_vl->eop.next;
          upcri_assert(cur_vl->flags == UPCRI_LISTFLAG_VECTOR);
          upcri_assert(node < gasnet_nodes());
          upcri_assert(cur_vl->remotecount > 0);
          upcri_assert(cur_vl->remotecount <= cur_vl->remotesize);
          upcri_assert(cur_vl->remotelist != NULL);
          for (i = 0; i < cur_vl->remotecount; i++) {
            upcri_assert(cur_vl->remotelist[i].addr != NULL);
            upcri_assert(cur_vl->remotelist[i].len > 0 && cur_vl->remotelist[i].len <= maxremote);
            cur_remotesz += cur_vl->remotelist[i].len;
          }
          upcri_assert(cur_vl->localcount > 0);
          upcri_assert(cur_vl->localcount <= cur_vl->localsize);
          upcri_assert(cur_vl->locallist != NULL);
          for (i = 0; i < cur_vl->localcount; i++) {
            upcri_assert(cur_vl->locallist[i].addr != NULL);
            upcri_assert(cur_vl->locallist[i].len > 0 && cur_vl->locallist[i].len <= maxlocal);
            cur_localsz += cur_vl->locallist[i].len;
          }
          upcri_assert(cur_localsz == cur_remotesz);
          totalsz += cur_localsz;
          while (tmp_vl) {
            upcri_assert(tmp_vl->remotenode != node);
            tmp_vl = (upcri_vlist_t*)tmp_vl->eop.next;
          }
          cur_vl = (upcri_vlist_t*)cur_vl->eop.next;
        }
        upcri_assert(totalsz == totalsz_input);
      }
    #endif

    return all_vl;
  }

  extern bupc_handle_t _bupc_memput_vlist_async(size_t dstcount, bupc_smemvec_t const dstlist[], 
                                     size_t srccount, bupc_pmemvec_t const srclist[] UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    upcri_vlist_t *vl = upcri_convertandbin_vlist(dstcount, dstlist, srccount, srclist);
    upcri_vlist_t *cur_vl = vl;
    while (cur_vl) {
      upcri_assert(cur_vl->flags & UPCRI_LISTFLAG_VECTOR);
      cur_vl->eop.handle = gasnet_putv_nb_bulk(cur_vl->remotenode,cur_vl->remotecount,cur_vl->remotelist,
                                               cur_vl->localcount,cur_vl->locallist);
      cur_vl = (upcri_vlist_t*)(cur_vl->eop.next);
    }
    return (vl == NULL ? BUPC_COMPLETE_HANDLE : &(vl->eop));
  }

  extern bupc_handle_t _bupc_memget_vlist_async(size_t dstcount, bupc_pmemvec_t const dstlist[], 
                                     size_t srccount, bupc_smemvec_t const srclist[] UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    upcri_vlist_t *vl = upcri_convertandbin_vlist(srccount, srclist, dstcount, dstlist);
    upcri_vlist_t *cur_vl = vl;
    while (cur_vl) {
      upcri_assert(cur_vl->flags & UPCRI_LISTFLAG_VECTOR);
      cur_vl->eop.handle = gasnet_getv_nb_bulk(cur_vl->localcount,cur_vl->locallist,
                                               cur_vl->remotenode,cur_vl->remotecount,cur_vl->remotelist);
      cur_vl = (upcri_vlist_t*)(cur_vl->eop.next);
    }
    return (vl == NULL ? BUPC_COMPLETE_HANDLE : &(vl->eop));
  }
#endif

#if BUPC_SG_DESIGN_B
  extern bupc_handle_t _bupc_memcpy_ilist_async(size_t dstcount, upcr_shared_ptr_t const dstlist[], 
                                       size_t dstlen,
                                       size_t srccount, upcr_shared_ptr_t const srclist[], 
                                       size_t srclen UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    gasnet_node_t mynode = gasnet_mynode();
    if_pf (dstcount == 0) {
      upcri_assert(srccount == 0);
      return BUPC_COMPLETE_HANDLE;
    }
    { /* try to convert into a pure memput or memget */
      bupc_handle_t h = upcri_newhandle(MAX(dstcount,srccount)*sizeof(void*));
      void **locallist = (void **)upcri_eop_metadata(h);
      int i;

      for (i = 0; i < srccount; i++) {
        gasnet_node_t curnode = upcri_shared_nodeof(srclist[i]);
        if (curnode != mynode) break; /* remote address */
        locallist[i] = upcri_shared_to_remote(srclist[i]);
      }
      if (i == srccount) { /* src entirely local */
        h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the metadata memory */
        h->next = _bupc_memput_ilist_async(dstcount, dstlist, dstlen, srccount, (const void **)locallist, srclen UPCRI_PT_PASS);
        return h;
      }

      for (i = 0; i < dstcount; i++) {
        gasnet_node_t curnode = upcri_shared_nodeof(dstlist[i]);
        if (curnode != mynode) break; /* remote address */
        locallist[i] = upcri_shared_to_remote(dstlist[i]);
      }
      if (i == dstcount) { /* dst entirely local */
        h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the metadata memory */
        h->next = _bupc_memget_ilist_async(dstcount, locallist, dstlen, srccount, srclist, srclen UPCRI_PT_PASS);
        return h;
      }

      upcri_free(h);
    }

    /* Not a pure put or get: involves one or more remote nodes in both src & dst 
         so decompose it into a get to temp followed by put from temp
       Future work: decompose the operation into sub-operations (over smaller range) where
         each is a pure put, pure get, or 3rd party xfer
     */
    { size_t datasz = dstcount*dstlen;
      bupc_handle_t h = upcri_newhandle(datasz+sizeof(void *));
      void **tmplist = (void **)upcri_eop_metadata(h);
      char *tmpdata = upcri_eop_metadata(h)+sizeof(void *);
      *tmplist = tmpdata;
      _upcr_waitsync(
        _bupc_memget_ilist_async(1, tmplist, datasz, srccount, srclist, srclen 
        UPCRI_PT_PASS) UPCRI_PT_PASS);
      h->handle = GASNET_INVALID_HANDLE; /* this entry just holds the bounce buffer and metadata memory */
      h->next = _bupc_memput_ilist_async(dstcount, dstlist, dstlen, 1, (const void **)tmplist, datasz UPCRI_PT_PASS);
      return h;
    }
  }

  /* bin the remote addresses into separate per-node operations and convert all shared ptrs to VA's 
     returns a linked list of bins, which may be a mix of vlists and ilists covering the area
   */
  static upcri_list_t *upcri_convertandbin_ilist(
                       size_t const remotecount, upcr_shared_ptr_t const remotelist[], size_t const remotelen,
                       size_t const localcount, void * const locallist[],       size_t const locallen) {
    upcri_list_t *all_l = NULL;

    upcri_assert(((uintptr_t)remotecount)*remotelen == ((uintptr_t)localcount)*locallen && 
                 ((uintptr_t)remotecount)*remotelen > 0);
    if (remotecount == 1) { /* just a single one is enough, reuse metadata */
      upcri_ilist_t *cur_il = upcri_malloc(sizeof(upcri_ilist_t)+sizeof(void*));
      cur_il->flags = 0;
      cur_il->localcount = localcount; cur_il->remotecount = remotecount;
      cur_il->locallen = locallen; cur_il->remotelen = remotelen;
      UPCRI_DEBUG_DO(cur_il->localsize = localcount;
                     cur_il->remotesize = 1;);
      cur_il->locallist = (void **)locallist;
      cur_il->remotelist = (void **)(cur_il+1);
      cur_il->eop.next = NULL;
      cur_il->remotenode = upcri_shared_nodeof(remotelist[0]);
      cur_il->remotelist[0] = upcri_shared_to_remote(remotelist[0]);
      all_l = (upcri_list_t *)cur_il;
    } else if (remotelen % locallen == 0) { 
      /* guaranteed that local elements won't break across remote nodes, 
         so it's safe to use a straightforward translation to ilists 
         Future work: We could reuse the local metadata (w/o copying) if we 
         detect that all the entries for a given remote node are grouped 
         together in the remote list (or as a special case, if there is only 
         one remote node)
      */
      ssize_t localidx = -1, remoteidx = -1;
      gasnet_node_t cur_remotenode;
      void *cur_remoteaddr;
      upcri_ilist_t *cur_il = NULL;
      size_t localsperremote = remotelen / locallen;
      #define ADVANCE_LOCAL() do { /* advance local position */  \
          localidx++;                                            \
          upcri_assert(localidx >= 0 && localidx <= localcount); \
        } while (0)
      #define ADVANCE_REMOTE() do {  /* advance remote position, update cur_remote */        \
          remoteidx++;                                                                       \
          if (remoteidx < remotecount) {                                                     \
            cur_remotenode = upcri_shared_nodeof(remotelist[remoteidx]);                     \
            cur_remoteaddr = upcri_shared_to_remote(remotelist[remoteidx]);                  \
            /* find the appropriate bin, creating it if necessary */                         \
            if (cur_il == NULL || cur_il->remotenode != cur_remotenode) {                    \
              cur_il = (upcri_ilist_t *)all_l;                                               \
              while (cur_il != NULL && cur_il->remotenode != cur_remotenode)                 \
                cur_il = (upcri_ilist_t*)cur_il->eop.next;                                   \
              if (cur_il == NULL) {                                                          \
                upcri_assert(localidx >= 0);                                                 \
                cur_il = upcri_malloc(sizeof(upcri_ilist_t) + /* never have fragmentation */ \
                         (remotecount-remoteidx + localcount-localidx)*sizeof(void*));       \
                cur_il->remotenode = cur_remotenode;                                         \
                cur_il->flags = 0;                                                           \
                cur_il->localcount = 0; cur_il->remotecount = 0;                             \
                cur_il->locallen = locallen; cur_il->remotelen = remotelen;                  \
                UPCRI_DEBUG_DO(cur_il->localsize = (localcount-localidx);                    \
                               cur_il->remotesize = (remotecount-remoteidx););               \
                cur_il->locallist = (void **)(cur_il+1);                                     \
                cur_il->remotelist = (cur_il->locallist)+(localcount-localidx);              \
                cur_il->eop.next = (upcri_eop*)all_l;                                        \
                all_l = (upcri_list_t*)cur_il;                                               \
              }                                                                              \
            }                                                                                \
          }                                                                                  \
          upcri_assert(remoteidx >= 0 && remoteidx <= remotecount);                          \
        } while (0)

      ADVANCE_LOCAL(); ADVANCE_REMOTE();
      while (remoteidx < remotecount) {
        size_t i;
        cur_il->remotelist[cur_il->remotecount++] = cur_remoteaddr;
        upcri_assert(cur_il->remotecount <= cur_il->remotesize);
        for (i = 0; i < localsperremote; i++) {
          upcri_assert(localidx < localcount);
          cur_il->locallist[cur_il->localcount++] = (void *)locallist[localidx];
          upcri_assert(cur_il->localcount <= cur_il->localsize);
          ADVANCE_LOCAL();
        }
        ADVANCE_REMOTE();
      } 
      upcri_assert(localidx == localcount && remoteidx == remotecount);
      #undef ADVANCE_LOCAL
      #undef ADVANCE_REMOTE
    } else if (locallen % remotelen == 0) { 
      /* safe to use ilists with length remotelen and break local elements into multiple entries 
         Future work: Currently we hit this case for single local region and multiple remote regions
         we should detect runs with same remote node and merge them using vector variant
         (or at least detect and optimize the special case of local contiguous and non-contiguous single remote node)
       */
      ssize_t localidx = -1, remoteidx = -1;
      gasnet_node_t cur_remotenode;
      void *cur_remoteaddr;
      upcri_ilist_t *cur_il = NULL;
      size_t remotesperlocal = locallen / remotelen;
      #define ADVANCE_LOCAL() do { /* advance local position */  \
          localidx++;                                            \
          upcri_assert(localidx >= 0 && localidx <= localcount); \
        } while (0)
      #define ADVANCE_REMOTE() do {  /* advance remote position, update cur_remote */   \
          remoteidx++;                                                                  \
          if (remoteidx < remotecount) {                                                \
            cur_remotenode = upcri_shared_nodeof(remotelist[remoteidx]);                \
            cur_remoteaddr = upcri_shared_to_remote(remotelist[remoteidx]);             \
            /* find the appropriate bin, creating it if necessary */                    \
            if (cur_il == NULL || cur_il->remotenode != cur_remotenode) {               \
              cur_il = (upcri_ilist_t*)all_l;                                           \
              while (cur_il != NULL && cur_il->remotenode != cur_remotenode)            \
                cur_il = (upcri_ilist_t*)(cur_il->eop.next);                            \
              if (cur_il == NULL) {                                                     \
                size_t locallistentries = remotesperlocal*(localcount-localidx);        \
                upcri_assert(localidx >= 0);                                            \
                cur_il = upcri_malloc(sizeof(upcri_ilist_t) + /* fragment the locals */ \
                         (remotecount-remoteidx + locallistentries)*sizeof(void*));     \
                /* this slightly overallocates the locals, because we only advance      \
                   localidx upon every remotesperlocal remotes */                       \
                upcri_assert(locallistentries >= remotecount-remoteidx);                \
                cur_il->remotenode = cur_remotenode;                                    \
                cur_il->flags = 0;                                                      \
                cur_il->localcount = 0; cur_il->remotecount = 0;                        \
                cur_il->locallen = remotelen; cur_il->remotelen = remotelen;            \
                UPCRI_DEBUG_DO(cur_il->localsize = locallistentries;                    \
                               cur_il->remotesize = (remotecount-remoteidx););          \
                cur_il->locallist = (void **)(cur_il+1);                                \
                cur_il->remotelist = (cur_il->locallist)+locallistentries;              \
                cur_il->eop.next = (upcri_eop*)all_l;                                   \
                all_l = (upcri_list_t*)cur_il;                                          \
              }                                                                         \
            }                                                                           \
          }                                                                             \
          upcri_assert(remoteidx >= 0 && remoteidx <= remotecount);                     \
        } while (0)

      ADVANCE_LOCAL(); ADVANCE_REMOTE();
      while (localidx < localcount) {
        size_t i;
        uintptr_t cur_localaddr = (uintptr_t)(locallist[localidx]);
        for (i = 0; i < remotesperlocal; i++) {
          upcri_assert(remoteidx < remotecount);
          cur_il->remotelist[cur_il->remotecount++] = cur_remoteaddr;
          upcri_assert(cur_il->remotecount <= cur_il->remotesize);
          cur_il->locallist[cur_il->localcount++] = (void *)cur_localaddr;
          upcri_assert(cur_il->localcount <= cur_il->localsize);
          cur_localaddr += remotelen;
          ADVANCE_REMOTE();
        }
        ADVANCE_LOCAL();
      } 
      upcri_assert(localidx == localcount && remoteidx == remotecount);
      #undef ADVANCE_LOCAL
      #undef ADVANCE_REMOTE
    } else {
      /* possible corner cases are too complicated - just use vlists 
         future work: scan for grouped node ids and use ilists where possible
       */
      ssize_t localidx = -1, remoteidx = -1;
      gasnet_node_t cur_remotenode;
      gasnet_memvec_t cur_remotevec;
      gasnet_memvec_t cur_localvec;
      upcri_vlist_t *cur_vl = NULL;
      #define ADVANCE_LOCAL() do { /* advance position, update curvec */ \
          localidx++;                                                    \
          cur_localvec.addr = (void*)locallist[localidx];                \
          cur_localvec.len = locallen;                                   \
          upcri_assert(localidx >= 0 && localidx <= localcount);         \
        } while (0)
      #define ADVANCE_REMOTE() do {  /* advance position, update curvec */                          \
          remoteidx++;                                                                              \
          if (remoteidx < remotecount) {                                                            \
            cur_remotenode = upcri_shared_nodeof(remotelist[remoteidx]);                            \
            cur_remotevec.addr = upcri_shared_to_remote(remotelist[remoteidx]);                     \
            cur_remotevec.len = remotelen;                                                          \
            /* find the appropriate bin, creating it if necessary */                                \
            if (cur_vl == NULL || cur_vl->remotenode != cur_remotenode) {                           \
              cur_vl = (upcri_vlist_t *)all_l;                                                      \
              while (cur_vl != NULL && cur_vl->remotenode != cur_remotenode)                        \
                cur_vl = (upcri_vlist_t*)cur_vl->eop.next;                                          \
              if (cur_vl == NULL) {                                                                 \
                upcri_assert(localidx >= 0);                                                        \
                /* worst-case fragmentation: locals break at each remote break */                   \
                cur_vl = upcri_malloc(sizeof(upcri_vlist_t) + /* 2x for worst-case fragmentation */ \
                   (2*(remotecount-remoteidx) + localcount-localidx)*sizeof(gasnet_memvec_t));      \
                cur_vl->remotenode = cur_remotenode;                                                \
                cur_vl->flags = UPCRI_LISTFLAG_VECTOR;                                              \
                cur_vl->localcount = 0; cur_vl->remotecount = 0;                                    \
              UPCRI_DEBUG_DO(cur_vl->localsize = (localcount-localidx)+(remotecount-remoteidx);     \
                             cur_vl->remotesize = (remotecount-remoteidx););                        \
                cur_vl->locallist = (gasnet_memvec_t *)(cur_vl+1);                                  \
              cur_vl->remotelist = ((gasnet_memvec_t *)cur_vl->locallist)+                          \
                                   (localcount-localidx)+(remotecount-remoteidx);                   \
                cur_vl->eop.next = (upcri_eop*)all_l;                                               \
                all_l = (upcri_list_t*)cur_vl;                                                      \
              }                                                                                     \
            }                                                                                       \
          }                                                                                         \
          upcri_assert(remoteidx >= 0 && remoteidx <= remotecount);                                 \
        } while (0)


      #define GET_REMOTE_SPTR(idx) (remotelist[(idx)])

      UPCRI_VLIST_BIN();

      #undef GET_REMOTE_SPTR
      #undef ADVANCE_LOCAL
      #undef ADVANCE_REMOTE
    }

    #ifdef UPCR_DEBUG
    { /* verify sanity 
       * some of these checks may need to be weakened in the future,
       * if we add a more aggressive binning algorithm
       */
      if (all_l->flags & UPCRI_LISTFLAG_VECTOR) {
        upcri_vlist_t *cur_vl = (upcri_vlist_t *)all_l;
        uintptr_t totalsz = 0;
        while (cur_vl) {
          size_t i;
          uintptr_t cur_localsz = 0;
          uintptr_t cur_remotesz = 0;
          gasnet_node_t node = cur_vl->remotenode;
          upcri_vlist_t *tmp_vl = (upcri_vlist_t*)cur_vl->eop.next;
          upcri_assert(cur_vl->flags == UPCRI_LISTFLAG_VECTOR);
          upcri_assert(node < gasnet_nodes());
          upcri_assert(cur_vl->remotecount > 0);
          upcri_assert(cur_vl->remotecount <= cur_vl->remotesize);
          upcri_assert(cur_vl->remotelist != NULL);
          for (i = 0; i < cur_vl->remotecount; i++) {
            upcri_assert(cur_vl->remotelist[i].addr != NULL);
            upcri_assert(cur_vl->remotelist[i].len > 0 && cur_vl->remotelist[i].len <= remotelen);
            cur_remotesz += cur_vl->remotelist[i].len;
          }
          upcri_assert(cur_vl->localcount > 0);
          upcri_assert(cur_vl->localcount <= cur_vl->localsize);
          upcri_assert(cur_vl->locallist != NULL);
          for (i = 0; i < cur_vl->localcount; i++) {
            upcri_assert(cur_vl->locallist[i].addr != NULL);
            upcri_assert(cur_vl->locallist[i].len > 0 && cur_vl->locallist[i].len <= locallen);
            cur_localsz += cur_vl->locallist[i].len;
          }
          upcri_assert(cur_localsz == cur_remotesz);
          totalsz += cur_localsz;
          while (tmp_vl) {
            upcri_assert(tmp_vl->remotenode != node);
            tmp_vl = (upcri_vlist_t*)tmp_vl->eop.next;
          }
          cur_vl = (upcri_vlist_t*)cur_vl->eop.next;
        }
        upcri_assert(totalsz == ((uintptr_t)localcount) * locallen);
      } else {
        upcri_ilist_t *cur_il = (upcri_ilist_t *)all_l;
        uintptr_t totalsz = 0;
        while (cur_il) {
          size_t i;
          gasnet_node_t node = cur_il->remotenode;
          upcri_ilist_t *tmp_il = (upcri_ilist_t*)cur_il->eop.next;
          upcri_assert(cur_il->flags == 0);
          upcri_assert(node < gasnet_nodes());
          upcri_assert(cur_il->remotecount > 0);
          upcri_assert(cur_il->remotecount <= cur_il->remotesize);
          upcri_assert(cur_il->remotelist != NULL);
          for (i = 0; i < cur_il->remotecount; i++) upcri_assert(cur_il->remotelist[i] != NULL);
          upcri_assert(cur_il->localcount > 0);
          upcri_assert(cur_il->localcount <= cur_il->localsize);
          upcri_assert(cur_il->locallist != NULL);
          for (i = 0; i < cur_il->localcount; i++) upcri_assert(cur_il->locallist[i] != NULL);
          while (tmp_il) {
            upcri_assert(tmp_il->remotenode != node);
            tmp_il = (upcri_ilist_t*)tmp_il->eop.next;
          }
          upcri_assert(((uintptr_t)cur_il->localcount) * cur_il->locallen == 
                       ((uintptr_t)cur_il->remotecount) * cur_il->remotelen);
          totalsz += ((uintptr_t)cur_il->localcount) * cur_il->locallen;
          cur_il = (upcri_ilist_t*)cur_il->eop.next;
        }
        upcri_assert(totalsz == ((uintptr_t)localcount) * locallen);
      }
    }
    #endif

    return all_l;
  }

  extern bupc_handle_t _bupc_memput_ilist_async(size_t dstcount, upcr_shared_ptr_t const dstlist[], 
                                       size_t dstlen,
                                       size_t srccount,        const void * const srclist[], 
                                       size_t srclen UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    if_pf (dstcount == 0) {
      upcri_assert(srccount == 0);
      return BUPC_COMPLETE_HANDLE;
    }
    { upcri_list_t *l = upcri_convertandbin_ilist(dstcount, dstlist, dstlen, srccount, (void * const *)srclist, srclen);
      upcri_list_t *cur_l = l;
      while (cur_l) {
        if (cur_l->flags & UPCRI_LISTFLAG_VECTOR) {
          upcri_vlist_t *cur_vl = (upcri_vlist_t *)cur_l;
          cur_vl->eop.handle = gasnet_putv_nb_bulk(cur_vl->remotenode,cur_vl->remotecount,cur_vl->remotelist,
                                               cur_vl->localcount,cur_vl->locallist);
        } else {
          upcri_ilist_t *cur_il = (upcri_ilist_t *)cur_l;
          cur_il->eop.handle = gasnet_puti_nb_bulk(cur_il->remotenode,cur_il->remotecount,cur_il->remotelist,cur_il->remotelen,
                                               cur_il->localcount,cur_il->locallist,cur_il->locallen);
        }
        cur_l = (upcri_list_t*)cur_l->eop.next;
      }
      return &(l->eop);
    }
  }

  extern bupc_handle_t _bupc_memget_ilist_async(size_t dstcount,              void * const dstlist[], 
                                       size_t dstlen, 
                                       size_t srccount, upcr_shared_ptr_t const srclist[], 
                                       size_t srclen UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    if_pf (dstcount == 0) {
      upcri_assert(srccount == 0);
      return BUPC_COMPLETE_HANDLE;
    }
    { upcri_list_t *l = upcri_convertandbin_ilist(srccount, srclist, srclen, dstcount, dstlist, dstlen);
      upcri_list_t *cur_l = l;
      while (cur_l) {
        if (cur_l->flags & UPCRI_LISTFLAG_VECTOR) {
          upcri_vlist_t *cur_vl = (upcri_vlist_t *)cur_l;
          cur_vl->eop.handle = gasnet_getv_nb_bulk(cur_vl->localcount,cur_vl->locallist,
                                               cur_vl->remotenode,cur_vl->remotecount,cur_vl->remotelist);
        } else {
          upcri_ilist_t *cur_il = (upcri_ilist_t *)cur_l;
          cur_il->eop.handle = gasnet_geti_nb_bulk(cur_il->localcount,cur_il->locallist,cur_il->locallen,
                                               cur_il->remotenode,cur_il->remotecount,cur_il->remotelist,cur_il->remotelen);
        }
        cur_l = (upcri_list_t*)cur_l->eop.next;
      }
      return &(l->eop);
    }
  }
#endif
/*---------------------------------------------------------------------------------*/
#if BUPC_STRIDED_DESIGN_A
  extern bupc_handle_t _bupc_memcpy_fstrided_async(upcr_shared_ptr_t dstaddr,  size_t dstchunklen, 
                                          size_t dstchunkstride, size_t dstchunkcount,
                                          upcr_shared_ptr_t srcaddr,  size_t srcchunklen, 
                                          size_t srcchunkstride, size_t srcchunkcount UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_shared(srcaddr);
    (void) upcri_checkvalid_shared(dstaddr);
    upcri_assert(dstchunkstride >= dstchunklen);
    upcri_assert(srcchunkstride >= srcchunklen);
    upcri_assert(dstchunklen*dstchunkcount == srcchunklen*srcchunkcount);
    if (upcri_shared_nodeof(srcaddr) == gasnet_mynode()) { /* it's a memput */
      return _bupc_memput_fstrided_async(dstaddr, dstchunklen, dstchunkstride, dstchunkcount,
                                        upcri_shared_to_remote(srcaddr), srcchunklen, srcchunkstride, srcchunkcount
                                        UPCRI_PT_PASS);
    } else if (upcri_shared_nodeof(dstaddr) == gasnet_mynode()) { /* it's a memget */
      return _bupc_memget_fstrided_async(upcri_shared_to_remote(dstaddr), dstchunklen, dstchunkstride, dstchunkcount,
                                        srcaddr, srcchunklen, srcchunkstride, srcchunkcount
                                        UPCRI_PT_PASS);
    } else { /* it's a third-party xfer */
      size_t datasz = dstchunklen*dstchunkcount;
      if (datasz == 0) return BUPC_COMPLETE_HANDLE;
      else {
        bupc_handle_t h = upcri_newhandle(4*sizeof(size_t)+datasz);
        size_t *dststrides = (size_t*)upcri_eop_metadata(h);
        size_t *srcstrides = (size_t*)(upcri_eop_metadata(h)+sizeof(size_t));
        size_t *count = (size_t*)(upcri_eop_metadata(h)+2*sizeof(size_t));
        char *tmpdata = upcri_eop_metadata(h)+4*sizeof(size_t);
        /* blocking get */
        _upcr_waitsync(
          _bupc_memget_fstrided_async(tmpdata, datasz, datasz, 1,
                                     srcaddr, srcchunklen, srcchunkstride, srcchunkcount
                                     UPCRI_PT_PASS) UPCRI_PT_PASS);
        /* non-blocking put */
        dststrides[0] = dstchunkstride;
        count[0] = dstchunklen;
        count[1] = dstchunkcount;
        srcstrides[0] = dstchunklen;
        h->handle = gasnet_puts_nb_bulk(upcri_shared_nodeof(dstaddr),upcri_shared_to_remote(dstaddr), dststrides,
                                        tmpdata,srcstrides,
                                        count,1);
        return h;
      }
    }
  }

  extern bupc_handle_t _bupc_memput_fstrided_async(upcr_shared_ptr_t dstaddr,  size_t dstchunklen, 
                                          size_t dstchunkstride, size_t dstchunkcount,
                                                 void *srcaddr,  size_t srcchunklen, 
                                          size_t srcchunkstride, size_t srcchunkcount UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    size_t datasz = dstchunklen*dstchunkcount;
    (void) upcri_checkvalid_shared(dstaddr);
    upcri_assert(dstchunkstride >= dstchunklen);
    upcri_assert(srcchunkstride >= srcchunklen);
    upcri_assert(dstchunklen*dstchunkcount == srcchunklen*srcchunkcount);
    if (datasz == 0) return BUPC_COMPLETE_HANDLE;
    else {
      int hardcase = ((dstchunklen != srcchunklen) && (dstchunkstride > dstchunklen) && (srcchunkstride > srcchunklen));
      bupc_handle_t h = upcri_newhandle(4*sizeof(size_t)+(hardcase?datasz:0));
      size_t *dststrides = (size_t*)upcri_eop_metadata(h);
      size_t *srcstrides = (size_t*)(upcri_eop_metadata(h)+sizeof(size_t));
      size_t *count = (size_t*)(upcri_eop_metadata(h)+2*sizeof(size_t));
      char *tmpdata = upcri_eop_metadata(h)+4*sizeof(size_t);
      void *xfer_srcaddr = srcaddr;

      if (hardcase) { /* hard case - reshaping xfer */
        /* copy source data to a contiguous bounce buffer */
        int chunkidx;
        char *srcpos = srcaddr;
        char *tmppos = tmpdata;
        for (chunkidx = 0; chunkidx < srcchunkcount; chunkidx++) {
          memcpy(tmppos, srcpos, srcchunklen);
          srcpos += srcchunkstride;
          tmppos += srcchunklen;
        }
        xfer_srcaddr = tmpdata;
        dststrides[0] = dstchunkstride;
        count[0] = dstchunklen;
        count[1] = dstchunkcount;
        srcstrides[0] = dstchunklen;
      } else if (dstchunklen == srcchunklen) { /* easy case - no reshaping */
        dststrides[0] = dstchunkstride;
        srcstrides[0] = srcchunkstride;
        count[0] = dstchunklen;
        upcri_assert(srcchunkcount == dstchunkcount);
        count[1] = dstchunkcount;
      } else if (srcchunkstride == srcchunklen) { /* easy case - src contiguous */
        dststrides[0] = dstchunkstride;
        count[0] = dstchunklen;
        count[1] = dstchunkcount;
        srcstrides[0] = dstchunklen;
      } else if (dstchunkstride == dstchunklen) { /* easy case - dst contiguous */
        srcstrides[0] = srcchunkstride;
        count[0] = srcchunklen;
        count[1] = srcchunkcount;
        dststrides[0] = srcchunklen;
      } else upcri_err("bad bupc_memput_fstrided case: illegal arguments?");

      h->handle = gasnet_puts_nb_bulk(upcri_shared_nodeof(dstaddr),upcri_shared_to_remote(dstaddr),dststrides,
                                      xfer_srcaddr,srcstrides,
                                      count,1);
      return h;
    }
  }

  extern bupc_handle_t _bupc_memget_fstrided_async(       void *dstaddr,  size_t dstchunklen, 
                                          size_t dstchunkstride, size_t dstchunkcount,
                                          upcr_shared_ptr_t srcaddr,  size_t srcchunklen, 
                                          size_t srcchunkstride, size_t srcchunkcount UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    size_t datasz = dstchunklen*dstchunkcount;
    (void) upcri_checkvalid_shared(srcaddr);
    upcri_assert(dstchunkstride >= dstchunklen);
    upcri_assert(srcchunkstride >= srcchunklen);
    upcri_assert(dstchunklen*dstchunkcount == srcchunklen*srcchunkcount);
    if (datasz == 0) return BUPC_COMPLETE_HANDLE;
    else {
      int hardcase = ((dstchunklen != srcchunklen) && (dstchunkstride > dstchunklen) && (srcchunkstride > srcchunklen));
      bupc_handle_t h = upcri_newhandle(4*sizeof(size_t)+(hardcase?datasz:0));
      size_t *dststrides = (size_t*)upcri_eop_metadata(h);
      size_t *srcstrides = (size_t*)(upcri_eop_metadata(h)+sizeof(size_t));
      size_t *count = (size_t*)(upcri_eop_metadata(h)+2*sizeof(size_t));
      char *tmpdata = upcri_eop_metadata(h)+4*sizeof(size_t);
      void *xfer_dstaddr = dstaddr;

      if (hardcase) { /* hard case - reshaping xfer */
        /* copy source data to a contiguous bounce buffer */
        /* no easy way to make this non-blocking for now */
        dststrides[0] = srcchunklen;
        count[0] = srcchunklen;
        count[1] = srcchunkcount;
        srcstrides[0] = srcchunkstride;
        gasnet_gets_bulk(tmpdata,dststrides,
                         upcri_shared_nodeof(srcaddr),upcri_shared_to_remote(srcaddr),srcstrides,
                         count,1);

        { int chunkidx;
          char *dstpos = dstaddr;
          char *tmppos = tmpdata;
          for (chunkidx = 0; chunkidx < dstchunkcount; chunkidx++) {
            memcpy(dstpos, tmppos, dstchunklen);
            dstpos += dstchunkstride;
            tmppos += dstchunklen;
          }
        }
        upcri_free(h);
        return BUPC_COMPLETE_HANDLE;
      } else if (dstchunklen == srcchunklen) { /* easy case - no reshaping */
        dststrides[0] = dstchunkstride;
        srcstrides[0] = srcchunkstride;
        count[0] = dstchunklen;
        upcri_assert(srcchunkcount == dstchunkcount);
        count[1] = dstchunkcount;
      } else if (srcchunkstride == srcchunklen) { /* easy case - src contiguous */
        dststrides[0] = dstchunkstride;
        count[0] = dstchunklen;
        count[1] = dstchunkcount;
        srcstrides[0] = dstchunklen;
      } else if (dstchunkstride == dstchunklen) { /* easy case - dst contiguous */
        srcstrides[0] = srcchunkstride;
        count[0] = srcchunklen;
        count[1] = srcchunkcount;
        dststrides[0] = srcchunklen;
      } else upcri_err("bad bupc_memget_fstrided case: illegal arguments?");

      h->handle = gasnet_gets_nb_bulk(xfer_dstaddr,dststrides,
                                      upcri_shared_nodeof(srcaddr),upcri_shared_to_remote(srcaddr),srcstrides,
                                      count,1);
      return h;
    }
  }
#endif

#if BUPC_STRIDED_DESIGN_B
  extern bupc_handle_t _bupc_memcpy_strided_async(upcr_shared_ptr_t dstaddr, const size_t dststrides[], 
                                          upcr_shared_ptr_t srcaddr, const size_t srcstrides[], 
                                          const size_t count[], size_t stridelevels UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_shared(srcaddr);
    (void) upcri_checkvalid_shared(dstaddr);
    if (upcri_shared_nodeof(srcaddr) == gasnet_mynode()) { /* it's a memput */
      return _bupc_memput_strided_async(dstaddr, dststrides, upcri_shared_to_remote(srcaddr), srcstrides, 
                                        count, stridelevels UPCRI_PT_PASS);
    } else if (upcri_shared_nodeof(dstaddr) == gasnet_mynode()) { /* it's a memget */
      return _bupc_memget_strided_async(upcri_shared_to_remote(dstaddr), dststrides, srcaddr, srcstrides, 
                                        count, stridelevels UPCRI_PT_PASS);
    } else { /* it's a third-party xfer */
      size_t datasz = count[0];
      int i;
      for (i = 1; i < stridelevels+1; i++) { datasz *= count[i]; }
      if (datasz == 0) return BUPC_COMPLETE_HANDLE;
      else {
        bupc_handle_t h = upcri_newhandle(datasz+sizeof(size_t)*stridelevels);
        size_t *strides = (size_t*)upcri_eop_metadata(h);
        char *tmpdata = upcri_eop_metadata(h)+sizeof(size_t)*stridelevels;
        size_t strsz = 1;
        for (i = 0; i < stridelevels; i++) { strsz *= count[i]; strides[i] = strsz; }
        /* blocking get */
        _upcr_waitsync(
          _bupc_memget_strided_async(tmpdata, strides, 
                                     srcaddr, srcstrides, 
                                     count, stridelevels
                                     UPCRI_PT_PASS) UPCRI_PT_PASS);
        /* non-blocking put */
        h->handle = gasnet_puts_nb_bulk(upcri_shared_nodeof(dstaddr),upcri_shared_to_remote(dstaddr),dststrides,
                                        tmpdata,strides,
                                        count,stridelevels);
        return h;
      }
    }
  }
  extern bupc_handle_t _bupc_memput_strided_async(upcr_shared_ptr_t dstaddr, const size_t dststrides[], 
                                                 const void *srcaddr, const size_t srcstrides[], 
                                          const size_t count[], size_t stridelevels UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_shared(dstaddr);

    UPCRI_EOP_ENCAPSULATE(gasnet_puts_nb_bulk(upcri_shared_nodeof(dstaddr),upcri_shared_to_remote(dstaddr),dststrides,
                                    (void *)srcaddr,srcstrides,
                                    count,stridelevels));
  }
  extern bupc_handle_t _bupc_memget_strided_async(             void *dstaddr, const size_t dststrides[], 
                                          upcr_shared_ptr_t srcaddr, const size_t srcstrides[], 
                                                 const size_t count[], size_t stridelevels UPCRI_PT_ARG) {
    UPCRI_PASS_GAS();
    (void) upcri_checkvalid_shared(srcaddr);

    UPCRI_EOP_ENCAPSULATE(gasnet_gets_nb_bulk(dstaddr,dststrides,
                                    upcri_shared_nodeof(srcaddr),upcri_shared_to_remote(srcaddr),srcstrides,
                                    count,stridelevels));
  }
#endif
/*---------------------------------------------------------------------------------*/
