/*
 * upcr_proxy.h:  definitions/macros needed by the UPC compiler
 *
 * This file contains any definitions and/or macros which are not in the UPC
 * Runtime specification, but are needed to compile the C code emitted by our
 * sgiupc compiler.  
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_postinclude/upcr_proxy.h $
 */

#ifndef UPCR_PROXY_H
#define UPCR_PROXY_H

/*#define UPCR_RET_handle_t       _INT64 */
#define UPCR_RET_pshared_ptr_t(call)	(call)
#define UPCR_ARG_pshared_ptr_t(arg)  (arg)
#define UPCR_RET_shared_ptr_t(call)  (call)
#define UPCR_ARG_shared_ptr_t(arg)	(arg)
#define UPCR_RET_handle_t(call)	(call)
#define UPCR_ARG_handle_t(arg)	(*((upcr_handle_t*) &(arg)))

#define UPCR_RET_val_handle_t(call)  (call)
#define UPCR_ARG_val_handle_t(arg)	(*(upcr_valget_handle_t*)&(arg))

/* #define UPCR_ARG_handle_t       upcr_handle_t */

#define UPCR_RET_reg_value_t(call)   ((upcr_register_value_t)(call))
#define UPCR_ARG_reg_value_t(arg)	((upcr_register_value_t)(arg))

/* memory allocation routines */

#define UPCR_ALLOC(x) \
             UPCR_RET_shared_ptr_t(upcr_alloc(x))   

/* upc_local_alloc() has been removed from the spec - this will not link if used */
#define UPCR_LOCAL_ALLOC(x,y) \
             UPCR_RET_shared_ptr_t(upc_local_alloc((x), (y)))


#define UPCR_GLOBAL_ALLOC(x, y) \
             UPCR_RET_shared_ptr_t(upcr_global_alloc((x), (y)))

#define UPCR_ALL_ALLOC(x, y) \
             upcr_all_alloc((x), (y))

#define UPCR_FREE(x)\
              upcr_free(UPCR_ARG_shared_ptr_t(x))


/* locks */ 

#define UPCR_GLOBAL_LOCK_ALLOC() \
              UPCR_RET_shared_ptr_t(upcr_global_lock_alloc())


#define UPCR_ALL_LOCK_ALLOC() \
              UPCR_RET_shared_ptr_t(upcr_all_lock_alloc())

#define UPCR_LOCK(x) \
               upcr_lock(UPCR_ARG_shared_ptr_t(x))

#define UPCR_LOCK_ATTEMPT(x) \
               upcr_lock_attempt(UPCR_ARG_shared_ptr_t(x))

#define UPCR_UNLOCK(x) \
               upcr_unlock(UPCR_ARG_shared_ptr_t(x))

#define UPCR_LOCK_FREE(x) \
               upcr_lock_free(UPCR_ARG_shared_ptr_t(x))


/* relaxed memory get/put */

#define UPCR_PUT_SHARED(x,y,z,w) \
              upcr_put_shared(UPCR_ARG_shared_ptr_t(x), (y), (z), (w))

#define UPCR_PUT_PSHARED(x,y,z,w) \
              upcr_put_pshared(UPCR_ARG_pshared_ptr_t(x), (y), (z), (w))

#define UPCR_PUT_NB_SHARED(x,y,z,w) \
              UPCR_RET_handle_t(upcr_put_nb_shared(UPCR_ARG_shared_ptr_t(x), (y), (z), (w)))

#define UPCR_PUT_NBI_SHARED(x,y,z,w) \
              upcr_put_nbi_shared(UPCR_ARG_shared_ptr_t(x), (y), (z), (w))

#define UPCR_PUT_NB_PSHARED(x,y,z,w) \
              UPCR_RET_handle_t(upcr_put_nb_pshared(UPCR_ARG_pshared_ptr_t(x), (y), (z), (w)))

#define UPCR_PUT_NBI_PSHARED(x,y,z,w) \
              upcr_put_nbi_pshared(UPCR_ARG_pshared_ptr_t(x), (y), (z), (w))

#define UPCR_GET_SHARED(x,y,z,w) \
              upcr_get_shared((x), UPCR_ARG_shared_ptr_t(y), (z), (w))

#define UPCR_GET_NB_SHARED(x,y,z,w) \
              UPCR_RET_handle_t(upcr_get_nb_shared((x), UPCR_ARG_shared_ptr_t(y), (z), (w)))

#define UPCR_GET_NBI_SHARED(x,y,z,w) \
              upcr_get_nbi_shared((x), UPCR_ARG_shared_ptr_t(y), (z), (w))

#define UPCR_GET_PSHARED(x,y,z,w) \
              upcr_get_pshared((x), UPCR_ARG_pshared_ptr_t(y), (z), (w))

#define UPCR_GET_NB_PSHARED(x,y,z,w) \
              UPCR_RET_handle_t(upcr_get_nb_pshared((x), UPCR_ARG_pshared_ptr_t(y), (z), (w)))

#define UPCR_GET_NBI_PSHARED(x,y,z,w) \
              upcr_get_nbi_pshared((x), UPCR_ARG_pshared_ptr_t(y), (z), (w))

/* strict memory get/put */

#define UPCR_PUT_SHARED_STRICT(x,y,z,w) \
              upcr_put_shared_strict(UPCR_ARG_shared_ptr_t(x), (y), (z), (w))

#define UPCR_PUT_PSHARED_STRICT(x,y,z,w) \
              upcr_put_pshared_strict(UPCR_ARG_pshared_ptr_t(x), (y), (z), (w))

#define UPCR_PUT_NB_SHARED_STRICT(x,y,z,w) \
              UPCR_RET_handle_t(upcr_put_nb_shared_strict(UPCR_ARG_shared_ptr_t(x), (y), (z), (w)))

#define UPCR_PUT_NB_PSHARED_STRICT(x,y,z,w) \
              UPCR_RET_handle_t(upcr_put_nb_pshared_strict(UPCR_ARG_pshared_ptr_t(x), (y), (z), (w)))

#define UPCR_GET_SHARED_STRICT(x,y,z,w) \
              upcr_get_shared_strict((x), UPCR_ARG_shared_ptr_t(y), (z), (w))

#define UPCR_GET_NB_SHARED_STRICT(x,y,z,w) \
              UPCR_RET_handle_t(upcr_get_nb_shared_strict((x), UPCR_ARG_shared_ptr_t(y), (z), (w)))

#define UPCR_GET_PSHARED_STRICT(x,y,z,w) \
              upcr_get_pshared_strict((x), UPCR_ARG_pshared_ptr_t(y), (z), (w))

#define UPCR_GET_NB_PSHARED_STRICT(x,y,z,w) \
              UPCR_RET_handle_t(upcr_get_nb_pshared_strict((x), UPCR_ARG_pshared_ptr_t(y), (z), (w)))

/* synchronization */

#define UPCR_WAIT_SYNCNB(x) \
               upcr_wait_syncnb(UPCR_ARG_handle_t(x))

#define UPCR_WAIT_SYNCNB_STRICT(x) \
               upcr_wait_syncnb_strict(UPCR_ARG_handle_t(x))


#define UPCR_TRY_SYNCNB(x) \
               upcr_try_syncnb(UPCR_ARG_handle_t(x))

#define UPCR_TRY_SYNCNB_STRICT(x) \
               upcr_try_syncnb_strict(UPCR_ARG_handle_t(x))


/* relaxed register get/put */

#define UPCR_PUT_SHARED_VAL(x,y,z,w) \
           upcr_put_shared_val(UPCR_ARG_shared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w))   

#define UPCR_PUT_NB_SHARED_VAL(x,y,z,w) \
           UPCR_RET_handle_t(upcr_put_nb_shared_val(UPCR_ARG_shared_ptr_t(x),(y), UPCR_ARG_reg_value_t(z), (w)))

#define UPCR_PUT_PSHARED_VAL(x,y,z,w) \
           upcr_put_pshared_val(UPCR_ARG_pshared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w)) 

#define UPCR_PUT_NB_PSHARED_VAL(x,y,z,w) \
           UPCR_RET_handle_t(upcr_put_nb_pshared_val(UPCR_ARG_pshared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w)))


#define UPCR_GET_SHARED_VAL(x,y,z) \
           UPCR_RET_reg_value_t(upcr_get_shared_val(UPCR_ARG_shared_ptr_t(x), (y), (z))) 

#define UPCR_GET_NB_SHARED_VAL(x,y,z) \
           UPCR_RET_val_handle_t(upcr_get_nb_shared_val(UPCR_ARG_shared_ptr_t(x), (y), (z))) 

#define UPCR_GET_PSHARED_VAL(x,y,z) \
           UPCR_RET_reg_value_t(upcr_get_pshared_val(UPCR_ARG_pshared_ptr_t(x), (y), (z))) 

#define UPCR_GET_NB_PSHARED_VAL(x,y,z) \
           UPCR_RET_val_handle_t(upcr_get_nb_pshared_val(UPCR_ARG_pshared_ptr_t(x), (y), (z))) 


#define UPCR_WAIT_SYNCNB_VALGET(x) \
           UPCR_RET_reg_value_t(upcr_wait_syncnb_valget(UPCR_ARG_val_handle_t(x)))


/* strict register get/put */

#define UPCR_PUT_SHARED_VAL_STRICT(x,y,z,w) \
           upcr_put_shared_val_strict(UPCR_ARG_shared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w))   

#define UPCR_PUT_NB_SHARED_VAL_STRICT(x,y,z,w) \
           UPCR_RET_handle_t(upcr_put_nb_shared_val_strict(UPCR_ARG_shared_ptr_t(x),(y), UPCR_ARG_reg_value_t(z), (w)))

#define UPCR_PUT_PSHARED_VAL_STRICT(x,y,z,w) \
           upcr_put_pshared_val_strict(UPCR_ARG_pshared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w)) 

#define UPCR_PUT_NB_PSHARED_VAL_STRICT(x,y,z,w) \
           UPCR_RET_handle_t(upcr_put_nb_pshared_val_strict(UPCR_ARG_pshared_ptr_t(x), (y), UPCR_ARG_reg_value_t(z), (w)))


#define UPCR_GET_SHARED_VAL_STRICT(x,y,z) \
           UPCR_RET_reg_value_t(upcr_get_shared_val_strict(UPCR_ARG_shared_ptr_t(x), (y), (z))) 

#define UPCR_GET_PSHARED_VAL_STRICT(x,y,z) \
           UPCR_RET_reg_value_t(upcr_get_pshared_val_strict(UPCR_ARG_pshared_ptr_t(x), (y), (z))) 


/* relaxed float put/get */

#define UPCR_PUT_SHARED_FLOATVAL(x,y,z) \
           upcr_put_shared_floatval(UPCR_ARG_shared_ptr_t(x), (y), (z)) 

#define UPCR_PUT_PSHARED_FLOATVAL(x,y,z) \
           upcr_put_pshared_floatval(UPCR_ARG_pshared_ptr_t(x), (y), (z))

#define UPCR_PUT_SHARED_DOUBLEVAL(x,y,z) \
           upcr_put_shared_doubleval(UPCR_ARG_shared_ptr_t(x), (y), (z))

#define UPCR_PUT_PSHARED_DOUBLEVAL(x,y,z) \
           upcr_put_pshared_doubleval(UPCR_ARG_pshared_ptr_t(x), (y), (z))


#define UPCR_GET_SHARED_FLOATVAL(x,y) \
           upcr_get_shared_floatval(UPCR_ARG_shared_ptr_t(x), (y)) 

#define UPCR_GET_PSHARED_FLOATVAL(x,y) \
           upcr_get_pshared_floatval(UPCR_ARG_pshared_ptr_t(x), (y)) 

#define UPCR_GET_SHARED_DOUBLEVAL(x,y) \
           upcr_get_shared_doubleval(UPCR_ARG_shared_ptr_t(x), (y))

#define UPCR_GET_PSHARED_DOUBLEVAL(x,y) \
           upcr_get_pshared_doubleval(UPCR_ARG_pshared_ptr_t(x), (y))


/* strict float put/get */

#define UPCR_PUT_SHARED_FLOATVAL_STRICT(x,y,z) \
           upcr_put_shared_floatval_strict(UPCR_ARG_shared_ptr_t(x), (y), (z)) 

#define UPCR_PUT_PSHARED_FLOATVAL_STRICT(x,y,z) \
           upcr_put_pshared_floatval_strict(UPCR_ARG_pshared_ptr_t(x), (y), (z))

#define UPCR_PUT_SHARED_DOUBLEVAL_STRICT(x,y,z) \
           upcr_put_shared_doubleval_strict(UPCR_ARG_shared_ptr_t(x), (y), (z))

#define UPCR_PUT_PSHARED_DOUBLEVAL_STRICT(x,y,z) \
           upcr_put_pshared_doubleval_strict(UPCR_ARG_pshared_ptr_t(x), (y), (z))


#define UPCR_GET_SHARED_FLOATVAL_STRICT(x,y) \
           upcr_get_shared_floatval_strict(UPCR_ARG_shared_ptr_t(x), (y)) 

#define UPCR_GET_PSHARED_FLOATVAL_STRICT(x,y) \
           upcr_get_pshared_floatval_strict(UPCR_ARG_pshared_ptr_t(x), (y)) 

#define UPCR_GET_SHARED_DOUBLEVAL_STRICT(x,y) \
           upcr_get_shared_doubleval_strict(UPCR_ARG_shared_ptr_t(x), (y))

#define UPCR_GET_PSHARED_DOUBLEVAL_STRICT(x,y) \
           upcr_get_pshared_doubleval_strict(UPCR_ARG_pshared_ptr_t(x), (y))


/* bulk memory operations */

#define UPCR_MEMGET(x,y,z) \
            upcr_memget((x), UPCR_ARG_shared_ptr_t(y), (z))

  /* (void *) cast removes const qualifier on src argument to prevent warnings */
#define UPCR_MEMPUT(x,y,z) \
           upcr_memput(UPCR_ARG_shared_ptr_t(x), (void *)(y), (z)) 

#define UPCR_MEMSET(x,y,z) \
	upcr_memset(UPCR_ARG_shared_ptr_t(x), (y), (z)) 			     
 


#define UPCR_NB_MEMGET(x,y,z) \
            UPCR_RET_handle_t(upcr_nb_memget((x), UPCR_ARG_shared_ptr_t(y), (z)))

  /* (void *) cast removes const qualifier on src argument to prevent warnings */
#define UPCR_NB_MEMPUT(x,y,z) \
           UPCR_RET_handle_t(upcr_nb_memput(UPCR_ARG_shared_ptr_t(x), (void *)(y), (z)))

#define UPCR_NB_MEMSET(x,y,z) \
	UPCR_RET_handle_t(upcr_nb_memset(UPCR_ARG_shared_ptr_t(x), (y), (z)))


#define UPCR_MEMCPY(x,y,z) \
         upcr_memcpy(UPCR_ARG_shared_ptr_t(x), UPCR_ARG_shared_ptr_t(y), (z))


#define UPCR_NB_MEMCPY(x,y,z) \
         upcr_nb_memcpy(UPCR_ARG_shared_ptr_t(x), UPCR_ARG_shared_ptr_t(y), (z))




/* shared pointer ops */

#define UPCR_ISVALID_SHARED(x) \
          upcr_isvalid_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_ISVALID_PSHARED(x) \
          upcr_isvalid_pshared(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_ISNULL_SHARED(x) \
          upcr_isnull_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_ISNULL_PSHARED(x) \
          upcr_isnull_pshared(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_SHARED_TO_LOCAL(x) \
          upcr_shared_to_local(UPCR_ARG_shared_ptr_t(x))

#define UPCR_PSHARED_TO_LOCAL(x) \
          upcr_pshared_to_local(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_SHARED_TO_PSHARED(x) \
          UPCR_RET_pshared_ptr_t(upcr_shared_to_pshared(UPCR_ARG_shared_ptr_t(x)))

#define UPCR_PSHARED_TO_SHARED(x) \
          UPCR_RET_shared_ptr_t(upcr_pshared_to_shared(UPCR_ARG_pshared_ptr_t(x)))


#define UPCR_SHARED_RESETPHASE(x) \
         UPCR_RET_shared_ptr_t(upcr_shared_resetphase(UPCR_ARG_shared_ptr_t(x)))

#define UPCR_THREADOF_SHARED(x) \
          upcr_threadof_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_THREADOF_PSHARED(x) \
          upcr_threadof_pshared(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_PHASEOF_SHARED(x) \
          upcr_phaseof_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_PHASEOF_PSHARED(x) \
          upcr_phaseof_pshared(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_ADDRFIELD_SHARED(x) \
         upcr_addrfield_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_ADDRFIELD_PSHARED(x) \
         upcr_addrfield_pshared(UPCR_ARG_pshared_ptr_t(x))

#define UPCR_SETNULL_SHARED(x) \
         upcr_setnull_shared((upcr_shared_ptr_t*)(x))

#define UPCR_SETNULL_PSHARED(x) \
        upcr_setnull_pshared((upcr_pshared_ptr_t*)(x))

/* BUG?  These macros are casting to the wrong type (shared_ptr, not
 * 'shared_ptr *'.  I'm commenting them out until this gets sorted out
 *	- JCD
#define UPCR_SETNULL_RSHARED(x) \
         upcr_setnull_shared(UPCR_ARG_shared_ptr_t(x))

#define UPCR_SETNULL_RPSHARED(x) \
        upcr_setnull_pshared(UPCR_ARG_shared_ptr_t(x))
*/

#define UPCR_ADD_SHARED(x,y,z,w) \
        UPCR_RET_shared_ptr_t(upcr_add_shared(UPCR_ARG_shared_ptr_t(x), (y), (z), (w)))

#define UPCR_ADD_PSHAREDI(x,y,z) \
         UPCR_RET_pshared_ptr_t(upcr_add_psharedI(UPCR_ARG_pshared_ptr_t(x), (y), (z)))

#define UPCR_ADD_PSHARED1(x,y,z) \
         UPCR_RET_pshared_ptr_t(upcr_add_pshared1(UPCR_ARG_pshared_ptr_t(x), (y), (z)))


#define UPCR_ISEQUAL_SHARED_SHARED(x,y) \
         upcr_isequal_shared_shared(UPCR_ARG_shared_ptr_t(x), UPCR_ARG_shared_ptr_t(y))

#define UPCR_ISEQUAL_SHARED_PSHARED(x,y) \
         upcr_isequal_shared_pshared(UPCR_ARG_shared_ptr_t(x), UPCR_ARG_pshared_ptr_t(y))


#define UPCR_ISEQUAL_PSHARED_PSHARED(x,y) \
         upcr_isequal_pshared_pshared(UPCR_ARG_pshared_ptr_t(x), UPCR_ARG_pshared_ptr_t(y))

#define UPCR_SUB_SHARED(x,y,z,w) \
         upcr_sub_shared(UPCR_ARG_shared_ptr_t(x), UPCR_ARG_shared_ptr_t(y), (z), (w))

#define UPCR_SUB_PSHAREDI(x,y,z) \
         upcr_sub_psharedI(UPCR_ARG_pshared_ptr_t(x), UPCR_ARG_pshared_ptr_t(y), (z))

#define UPCR_SUB_PSHARED1(x,y,z) \
         upcr_sub_pshared1(UPCR_ARG_pshared_ptr_t(x), UPCR_ARG_pshared_ptr_t(y), (z))

#define MYTHREAD (int)upcr_mythread()
#ifndef __UPC_STATIC_THREADS__
# define THREADS (int)upcr_threads()
#endif
#define upcr_add_shared_ptr upcr_add_shared

#define UPCR_SHARED_SIZE    sizeof(upcr_shared_ptr_t)
#define UPCR_PSHARED_SIZE   sizeof(upcr_pshared_ptr_t)


/* implicit handle synchronization */
#define UPCR_WAIT_SYNCNBI_GETS upcr_wait_syncnbi_gets
#define UPCR_WAIT_SYNCNBI_PUTS upcr_wait_syncnbi_puts
#define UPCR_WAIT_SYNCNBI_ALL upcr_wait_syncnbi_all
#define UPCR_BEGIN_NBI_ACCESSREGION upcr_begin_nbi_accessregion
#define UPCR_END_NBI_ACCESSREGION upcr_end_nbi_accessregion

/* new spelling for inline modifier */
#define UPCRI_INLINE GASNETT_INLINE

#endif /* UPCR_PROXY_H */
