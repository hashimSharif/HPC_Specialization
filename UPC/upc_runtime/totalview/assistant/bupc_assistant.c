/* $Source: bitbucket.org:berkeleylab/upc-runtime.git/totalview/assistant/bupc_assistant.c $ */
/* $Locker:  $ */

/**********************************************************************
 * Copyright (C) 2002 Etnus, LLC
 *
 * Permission is hereby granted to use, reproduce, prepare derivative
 * works, and to redistribute to others.
 *
 *				  DISCLAIMER
 *
 * Neither Etnus, nor any of their employees, makes any warranty
 * express or implied, or assumes any legal liability or
 * responsibility for the accuracy, completeness, or usefulness of any
 * information, apparatus, product, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 *
 * This code was written by
 * James Cownie: Etnus, LLC. <jcownie@etnus.com>
 **********************************************************************/

/* Update log
 *
 * Dec 18 2002 JHC: Use the new V5 callbacks for variable lookup on a thread.
 * Nov 26 2002 JHC: Created for GCC/UPC
 */

/**********************************************************************
 * An initial implementation of the core functions of the debug assistant
 * for the GCC/UPC implementation on SGI.
 * The key files for understanding this come from the GCC/UPC implementation
 *
 *    libupc/upc_defs.h        for structure definitions
 *    libupc/upc_access.c      for conversion of PTS to local pointer
 */

#include <stdio.h>
#include <stdarg.h>
#include "bupc_totalview_sptr.h"


/*********************************************************************
 * Information we cache on the uda_image.
 */
struct uda_image_info_
{
  uda_target_type_sizes type_sizes;		/* Sizes of the basic types */
}; /* uda_image_info_ */

/*********************************************************************
 * Information we cache on the uda_thread. 
 */
struct uda_thread_info_
{
  int         mythread;
  int	      threads;
  uintptr_t   myregion;
#if ! UPCRI_SINGLE_ALIGNED_REGIONS
  uintptr_t  *thread2region;
#endif
};  /* uda_thread_info_ */


static uda_basic_callbacks const * callbacks = 0;

/* A property of the machine we're running on, so can be shared */
static int big_endian = 0;

/* Macros so that we don't need to worry about the fact that the callback
 * functions are called via function pointers.
 */
#define db_malloc(sz)             ((*(callbacks->malloc_cb))((sz)))
#define db_free(a)                ((*(callbacks->free_cb))((a)))             
#define db_prints(a)              ((*(callbacks->prints_cb))((a)))           
#define db_error_string(a)        ((*(callbacks->error_string_cb))((a)))     
                     
#define db_relocate_address(a,b,c)((*(callbacks->relocate_address_cb))((a),(b),(c))) 
                     
#define db_job_thread_count(a,b)  ((*(callbacks->job_thread_count_cb))((a),(b))) 
#define db_job_get_thread(a,b)    ((*(callbacks->job_get_thread_cb))((a),(b)))   
#define db_job_get_image(a,b)     ((*(callbacks->job_get_image_cb))((a),(b)))   
#define db_thread_get_job(a,b)    ((*(callbacks->thread_get_job_cb))((a),(b)))   
                     
#define db_image_set_info(a,b)    ((*(callbacks->image_set_info_cb))((a),(b)))     
#define db_image_get_info(a,b)    ((*(callbacks->image_get_info_cb))((a),(b)))     

#define db_job_set_info(a,b)      ((*(callbacks->job_set_info_cb))((a),(b)))     
#define db_job_get_info(a,b)      ((*(callbacks->job_get_info_cb))((a),(b)))     
                     
#define db_thread_set_info(a,b)   ((*(callbacks->thread_set_info_cb))((a),(b)))  
#define db_thread_get_info(a,b)   ((*(callbacks->thread_get_info_cb))((a),(b)))  
                     
#define db_get_type_sizes(a,b)    ((*(callbacks->get_type_sizes_cb))((a),(b)))
#define db_variable_lookup(a,b,c) ((*(callbacks->variable_lookup_cb))((a),(b),(c)))
#define db_type_lookup(a,b,c)     ((*(callbacks->type_lookup_cb))((a),(b),(c)))
#define db_type_bitsize(a,b)      ((*(callbacks->type_bitsize_cb))((a),(b)))
#define db_type_get_member_info(a,b,c,d,e)((*(callbacks->type_get_member_info_cb))((a),(b),(c),(d),(e)))   

#define db_read_store(a,b,c,d)    ((*(callbacks->read_store_cb))((a),(b),(c),(d)))       
#define db_target_to_host(a,b,c,d)((*(callbacks->target_to_host_cb))((a),(b),(c),(d)))   
#define db_host_to_target(a,b,c,d)((*(callbacks->host_to_target_cb))((a),(b),(c),(d)))   
#define db_thread_variable_lookup(a,b,c) ((*(callbacks->thread_variable_lookup_cb))((a),(b),(c)))
#define db_thread_type_lookup(a,b,c) ((*(callbacks->thread_type_lookup_cb))((a),(b),(c)))

/**********************************************************************
 * Housekeeping routines.
 */
void uda_setup_basic_callbacks (uda_basic_callbacks const * cb)
{
  int i = 1;
  char * p = (char *) &i;

  big_endian = (*p == 0);

  callbacks = cb;
} /* uda_setup_basic_callbacks */

/**********************************************************************
 */
int uda_initialise_job (uda_job * job)
{

  TV_ASST_TRACE( () )

  return uda_ok;
} /* uda_initialise_job */

/**********************************************************************
 * Versioning information.
 */
const char * uda_version_string()
{
  return "Etnus UPC debug assistant for Berkeley UPC; Compiled " __DATE__;
} /* uda_version_string */

int uda_version_compatibility()
{
  return UPCDA_INTERFACE_COMPATIBILITY;
} /* uda_version_compatibility */

/**********************************************************************
 * Error code to string mapping.
 */
const char * uda_error_string (int err)
{
  return "unknown UPC assistant error";		/* No errors yet */
} /* uda_error_string */

/**********************************************************************
 * We don't need any information associated with the UPC job.
 */
void uda_destroy_job_info (uda_job *job)
{
} /* uda_destroy_job_info */

void uda_destroy_thread_info (uda_thread *thread)
{
  uda_thread_info * thread_info = 0;

  db_thread_get_info (thread, &thread_info);

  if (thread_info)
    db_free (thread_info);
} /* uda_destroy_thread_info */

void uda_destroy_image_info (uda_image *image)
{
  uda_image_info * image_info = 0;

  db_image_get_info (image, &image_info);
  
  if (image_info)
    db_free (image_info);
} /* uda_destroy_image_info */

/**********************************************************************
 * Support functions.
 */
#if ! defined (__GNUC__) && ! defined (__attribute__)
  #define __attribute__(flags)
#endif
/* Shut gcc up (and get helpful format warnings) */
static void d_printf (const char *fmt, ...)
     __attribute__((__format__ (__printf__, 1, 2)));

static void d_printf (const char *fmt, ...)
{
  char buffer [1024];
  va_list args;

  va_start (args, fmt);

  vsnprintf (&buffer[0], sizeof (buffer), fmt, args);

  buffer[sizeof (buffer)-1] = 0;

  db_prints (buffer);
} /* d_printf */

/**********************************************************************
 * Lookup a variable in the UPC thread. 
 */
static uda_taddr lookup_variable (uda_thread * thread, const char * var_name)
{
  uda_taddr res;
  int status = db_thread_variable_lookup (thread, var_name, &res);

  if (status == uda_ok)
    return res;
  else
    return 0;
} /* lookup_variable */

/**********************************************************************
 * Extract a scalar value from target store and return it into a 
 * uda_taddr. Need to be careful if we're extracting a small item to
 * get it into the right part of the taddr.
 */
static int read_scalar (uda_thread * thread, uda_taddr addr, int len, uda_taddr *res)
{
  char buffer [sizeof (uda_taddr)];
  int status;
  int offset  = big_endian ? sizeof (uda_taddr) - len : 0;

  *res = 0;					/* Default result */

  /* Sanity check */
  if (len > sizeof (uda_taddr))
    {
      d_printf ("Bad length for read_scalar %d, max %d\n", len, (int)sizeof(uda_taddr));
      abort();
    }
  
  status = db_read_store (thread, addr, len, &buffer[0]);
  
  if (status != uda_ok)
    return status;

  db_target_to_host (thread, len, &buffer[0], ((char *)res)+offset);

  return uda_ok;
} /* read_data */

static int read_struct_member(uda_thread *thread, 
			      uda_taddr struct_addr, 
			      const char * struct_name, 
			      const char *member_name, 
			      void *dest, 
			      int len)
			      
{
    uda_type  *info_type;
    uda_tword bit_offset;
    uda_tword bit_length;
    uda_type *field_type;
    uda_taddr member_addr;
    int status;

    status = db_thread_type_lookup (thread, struct_name, &info_type);
    if (status) {
	d_printf("Failed to get type info for '%s'\n", struct_name);
	return status;
    }
    status = db_type_get_member_info(info_type, member_name, &bit_offset, 
				     &bit_length, &field_type);
    if (status != uda_ok) {
	d_printf("Failed to find member '%s' in type '%s'\n", 
		 member_name, struct_name);
	return status;
    } 
    if (len != (bit_length/8) ) {
	d_printf("read_struct_member: size requested different than struct member's size!\n");
	abort();
    }
    member_addr = struct_addr + (bit_offset / 8);
    status = read_scalar(thread, member_addr, (bit_length/8), dest);
    if (status != uda_ok) {
	d_printf("Failed to read member '%s' of struct type '%s' at 'x%lx'\n",
		 member_name, struct_name, (long) member_addr);
	return status;
    }
    return uda_ok;
}

/* reads a upcr_shared_ptr_t from executable into assistant lib */
static int read_shared_ptr (uda_thread * thread, uda_taddr addr, upcr_shared_ptr_t *res)
{
    int status;
    char buffer[sizeof(upcr_shared_ptr_t)];

#if UPCRI_PACKED_SPTR
    status = db_read_store(thread, addr, sizeof(upcr_shared_ptr_t), &buffer[0]);
    if (status != uda_ok)
	return status;

    db_target_to_host(thread, sizeof(upcr_shared_ptr_t), &buffer[0],
		      ((char *) res));
#elif UPCRI_STRUCT_SPTR
    /* must grab each member of struct individually to ensure correct endianness */
    read_struct_member(thread, addr, "upcr_shared_ptr_t", "s_addr", &res->s_addr,
		       sizeof(res->s_addr));
    read_struct_member(thread, addr, "upcr_shared_ptr_t", "s_thread", &res->s_thread,
		       sizeof(res->s_thread));
    read_struct_member(thread, addr, "upcr_shared_ptr_t", "s_phase", &res->s_phase,
		       sizeof(res->s_phase));
#else
  #error unknown shared pointer representation!
#endif

    return uda_ok;
}

/* reads a upcr_pshared_ptr_t from executable into assistant lib */
static int read_pshared_ptr (uda_thread * thread, uda_taddr addr, upcr_pshared_ptr_t *res)
{
    int status;
    char buffer[sizeof(upcr_pshared_ptr_t)];

#if UPCRI_PACKED_SPTR
    /* Just read in integral type, and correct for endianness */
    status = db_read_store(thread, addr, sizeof(upcr_pshared_ptr_t), &buffer[0]);
    if (status != uda_ok)
	return status;
    db_target_to_host(thread, sizeof(upcr_pshared_ptr_t), &buffer[0],
		      ((char *) res));
#elif UPCRI_STRUCT_SPTR
    /* must grab each member of struct individually to ensure correct endianness */
    read_struct_member(thread, addr, "upcr_pshared_ptr_t", "s_addr", &res->s_addr,
		       sizeof(res->s_addr));
    read_struct_member(thread, addr, "upcr_pshared_ptr_t", "s_thread", &res->s_thread,
		       sizeof(res->s_thread));
#else
  #error unknown shared pointer representation!
#endif

    return uda_ok;
}

/* Combines lookup_variable with read_scalar */
static int lookup_and_read_scalar(uda_thread * thread, const char *varname, 
				  int len, void *result)
{
    int status;
    uda_taddr var_addr;

    status = db_thread_variable_lookup(thread, varname, &var_addr);
    if (status != uda_ok) {
	d_printf("Failed to find symbol %s\n", varname);
	return status;
    }
    status = read_scalar(thread, var_addr, len, (uda_taddr *)result);
    if (status != uda_ok) {
	d_printf("Failed to read %s at 0x%08lx\n", varname, (long)var_addr);
	return status;
    } 
    return status;
}

/* Read contents of an array */
static int lookup_and_read_array(uda_thread * thread, const char *varname, 
				 int elemsz, int count, void *result)
{
    int status;
    uda_taddr var_addr;
    int i;
    char * buf = db_malloc(elemsz * count);
    if (!buf)
	return uda_assistant_malloc_failed;

    status = db_thread_variable_lookup(thread, varname, &var_addr);
    if (status != uda_ok) {
	d_printf("Failed to find symbol %s\n", varname);
	goto free_and_return;
    }
    /* Read each element and convert to correct endianness */
    for (i = 0; i < count; i++) {
	uda_taddr src = var_addr + i*elemsz;
	char * dest = buf + i*elemsz;
	status = db_read_store(thread, src, elemsz, dest);
	if (status != uda_ok) {
	    d_printf("Failed to read %s at 0x%08lx\n", varname, (long)var_addr);
	    goto free_and_return;
	} 
	db_target_to_host(thread, elemsz, dest, ((char*)result) + i*elemsz);
    }
free_and_return: 
    db_free(buf);
    return status;
}
/**********************************************************************
 * Ensure we've extracted the image info we need for the image associated
 * with this thread.
 */
static uda_image_info * ensure_have_image_info (uda_thread * thread)
{
  uda_image_info  * im_info  = 0;
  uda_job   * job   = 0;
  uda_image * image = 0;

  db_thread_get_job (thread, &job);
  db_job_get_image  (job,  &image);
  db_image_get_info (image, &im_info);

  if (im_info)
    return im_info;

  im_info = db_malloc (sizeof (*im_info));
  if (im_info)
    {
      db_get_type_sizes (image, &(im_info->type_sizes));
      db_image_set_info (image, im_info);
    }

  return im_info;
} /* ensure_have_image_info */

/**********************************************************************
 * Ensure that we've extracted and cached the thread info we need.
 *
 * We also ensure that we've got any image info for the image associated
 * with the thread.
 */
static uda_thread_info * ensure_have_thread_info (uda_thread * thread)
{
  uda_thread_info * thr_info = 0;
  uda_image_info  * im_info  = 0;

  db_thread_get_info (thread, &thr_info);

  if (thr_info)
    return thr_info;

  im_info = ensure_have_image_info (thread);
  
  /* Don't have it yet so we must allocate it and fill it in.
   */
  thr_info = (uda_thread_info *) db_malloc (sizeof (*thr_info));
  if (thr_info) {
      db_thread_set_info (thread, thr_info);	/* Associate it with the thread */

      /* Lookup MYTHREAD and fill in its value
       * - JCD: for non-pthreaded Berkeley UPC job this is same as GASNet node */
      if (lookup_and_read_scalar(thread, "upcri_mynode", 
				 im_info->type_sizes.int_size,
				 &thr_info->mythread)) {
	  goto error_cleanup;
      }
      /* get THREADS */
      if (lookup_and_read_scalar(thread, "upcri_threads", 
				 im_info->type_sizes.int_size,
				 &thr_info->threads)) {
	  goto error_cleanup;
      }
      /* get this thread's start of shared region */
      if (lookup_and_read_scalar(thread, "upcri_myregion_single", 
				 im_info->type_sizes.pointer_size,
				 &thr_info->myregion)) {
	  goto error_cleanup;
      }
#if ! UPCRI_SINGLE_ALIGNED_REGIONS
      /* get lookup table for thread's shared regions */
      thr_info->thread2region = db_malloc(im_info->type_sizes.pointer_size * thr_info->threads);
      if (!thr_info->thread2region)
	  return NULL;  /* was uda_assistant_malloc_failed, but that isn't a pointer */
      if (lookup_and_read_array(thread, "upcri_thread2region", 
				 im_info->type_sizes.pointer_size,
				 thr_info->threads,
				 thr_info->thread2region)) {
	  goto error_cleanup;
      }
#endif
    }

  return thr_info;	/* null if the allocation failed... */

error_cleanup:
    if (thr_info)
	db_free(thr_info);
    return NULL;
} /* ensure_have_thread_info */

/**********************************************************************
 * Useful functions called by the debugger.
 */

/**********************************************************************
 * Which thread is this ?
 * (I.e. what's the value of MYTHREAD in this thread).
 */

int uda_get_threadno (uda_thread * thread, int * mythreadp)
{
  uda_thread_info * info = ensure_have_thread_info (thread);

  if (info)
    {
      *mythreadp = info->mythread;
      return uda_ok;
    }
  else
    return uda_no_information;
} /* uda_get_threadno */

/**********************************************************************
 * How big is a pointer to shared in the target ?
 */
int uda_length_of_pts (uda_image *image, uda_tword blocksize, 
		       uda_tword element_size, uda_tword *res)
{
  *res = (blocksize <= 1) ? sizeof(upcr_pshared_ptr_t) : sizeof(upcr_shared_ptr_t);
  TV_ASST_TRACE( ("blocksize=%ld, element_size=%ld, sizeof sptr=%ld", (long) blocksize, 
		 (long)element_size, (long)*res) )
  return uda_ok;
} /* uda_length_of_pts */

/**********************************************************************
 * Does the PTS have any opaque data which we want to preserve and 
 * show to the user ?
 * In our case the answer is no.
 */
int uda_show_opaque (uda_image *thread, uda_tword blocksize, uda_tword target_length)
{
  return uda_no_information;
} /* uda_show_opaque */

/**********************************************************************
 * Convert a pointer to shared from the target version to the unpacked
 * version used by the debugger. (Or, at least, passed through the
 * interface).
 */
int uda_unpack_pts (uda_thread * thread, 
		    const uda_target_pts * src, 
		    uda_tword blocksize,
		    uda_debugger_pts * res)
{
  /* Copy the data in to ensure alignment */
  upcr_pshared_ptr_t psptr;
  upcr_shared_ptr_t sptr;

  TV_ASST_TRACE( () )

  if(blocksize <= 1) {
    memcpy (&psptr, src, sizeof (psptr));
    res->addrfield = (uda_taddr) upcr_addrfield_pshared(psptr);
    res->phase   = upcr_phaseof_pshared(psptr);
    res->thread  = upcr_threadof_pshared(psptr);
  } else {
    memcpy (&sptr, src, sizeof (sptr));
    res->addrfield = (uda_taddr) upcr_addrfield_shared(sptr);
    res->phase   = upcr_phaseof_shared(sptr);
    res->thread  = upcr_threadof_shared(sptr);
  }
 
  res->opaque  = 0;   /* We don't need to carry any extra information around with us, 
		       * so this is just for cleanliness
		       */
  return uda_ok;
} /* uda_unpack_pts */

/**********************************************************************
 * The reverse of the previous function, convert back to target
 * format.
 */
int uda_pack_pts (uda_thread * thread,
		  const uda_debugger_pts * src,
		  uda_tword blocksize,
		  uda_target_pts * res)
{
  upcr_shared_ptr_t sptr;
  upcr_pshared_ptr_t psptr;

  TV_ASST_TRACE( () )

  if(blocksize <= 1) {
    psptr = upcri_addrfield_to_pshared((uintptr_t)src->addrfield, src->thread);
    memcpy (res, &psptr, sizeof (psptr));

  } else {
    sptr = upcri_addrfield_to_shared((uintptr_t)src->addrfield, src->thread, src->phase);
    memcpy (res, &sptr, sizeof (sptr));
  }
  

  /* Copy the data out in case target is mis-aligned */
  
  return uda_ok;
} /* uda_pack_pts */

/**********************************************************************
 * Convert a PTS into an absolute address.
 * 
 */

int uda_pts_to_addr (uda_thread *thread, 
		     const uda_debugger_pts *src, 
		     uda_tword blocksize, 
		     uda_tword element_size, 
		     uda_taddr *dest)
{
  uda_thread_info * info = ensure_have_thread_info (thread);
  
  TV_ASST_TRACE( ("src->addr=%lu(x%lx), blocksize=%lu, element_size=%lu",
		(unsigned long)src->addrfield, (unsigned long)src->addrfield, 
		(unsigned long)blocksize, (unsigned long)element_size) )
  *dest = 0;

  if (!info)
    return uda_no_information;

  if (blocksize <= 1) {
    upcr_pshared_ptr_t psptr;
    psptr = upcri_addrfield_to_pshared((uintptr_t)src->addrfield, src->thread);
    if (!upcr_isnull_pshared(psptr))
	*dest = (uda_taddr)upcri_pshared_to_remote(psptr);
  } else {
    upcr_shared_ptr_t sptr;
    sptr = upcri_addrfield_to_shared((uintptr_t)src->addrfield, src->thread, src->phase);
    if (!upcr_isnull_shared(sptr))
	*dest = (uda_taddr)upcri_shared_to_remote(sptr);
  }
  return uda_ok;
} /* uda_pts_to_addr */

/***********************************************************************/
/* The heart of UPC, index a shared pointer.
 */
int uda_index_pts (uda_thread *thread,
		   uda_debugger_pts *p,
		   uda_tword blocksize,
		   uda_tword element_size, 
		   uda_tword upc_threads, uda_tword delta)
{
  /* UPC Language specification para 6.3.4.2,
   * which omits to mention that the base pointer value also moves !
   */

  TV_ASST_TRACE( ("blocksize=%ld, element_size=%ld, upc_threads=%ld, delta=%ld",
	          (unsigned long) blocksize, (unsigned long) element_size, 
		  (unsigned long) upc_threads, (unsigned long) delta) )

  if(blocksize <= 1) {
    upcr_pshared_ptr_t psptr;
    psptr = upcri_addrfield_to_pshared((uintptr_t)p->addrfield, p->thread);
    if (blocksize == 1) {
      upcr_inc_pshared1(&psptr, element_size, delta);
    } else {
      upcr_inc_psharedI(&psptr, element_size, delta);
    }
    p->phase   = 0;
    p->thread  = upcr_threadof_pshared(psptr);
    p->addrfield = (uda_taddr) upcr_addrfield_pshared(psptr);
  } else {
    upcr_shared_ptr_t sptr;
    sptr = upcri_addrfield_to_shared((uintptr_t)p->addrfield, p->thread, p->phase);
    upcr_inc_shared(&sptr, element_size, delta, blocksize);
    p->phase   = upcr_phaseof_shared(sptr);
    p->thread  = upcr_threadof_shared(sptr);
    p->addrfield = (uda_taddr) upcr_addrfield_shared(sptr);
  }

  TV_ASST_TRACE( ("result: addrfield=%lx, thread=%d, phase=%d", 
	         (unsigned long)p->addrfield, (int)p->thread, (int)p->phase) )
  return uda_ok;
} /* upc_pts_t::add_offset */

/***********************************************************************/
/* Work out the difference between two pointers to shared.
 * 
 * What we're after is the same result as one would get by doing a pointer
 * subtraction in UPC.
 *
 * This needs to be written, but is not yet used by TotalView.
 */
int uda_pts_difference (uda_thread * thread, 
			const uda_debugger_pts *p1, 
			const uda_debugger_pts *p2,
			uda_tword blocksize, 
			uda_tword element_size, 
			uda_tword thread_count, 
			uda_tword *delta)
{
  TV_ASST_TRACE( ("blocksize=%ld, element_size=%ld, thread_count=%ld, delta=%ld",
	  (long) blocksize, (long) element_size, 
	  (long) thread_count, (long) delta) )


  if (blocksize <= 1) {
    upcr_pshared_ptr_t ps1, ps2;
    ps1 = upcri_addrfield_to_pshared((uintptr_t)p1->addrfield, p1->thread);
    ps2 = upcri_addrfield_to_pshared((uintptr_t)p2->addrfield, p2->thread);
    if (blocksize == 1) 
      *delta = upcr_sub_pshared1(ps1, ps2, element_size);
    else
      *delta = upcr_sub_psharedI(ps1, ps2, element_size);
  } else {
    upcr_shared_ptr_t s1, s2;
    s1 = upcri_addrfield_to_shared((uintptr_t)p1->addrfield, p1->thread, p1->phase);
    s2 = upcri_addrfield_to_shared((uintptr_t)p2->addrfield, p2->thread, p1->phase);
    *delta = upcr_sub_shared(s1, s2, element_size, blocksize);
  }
  return uda_ok;
} /* uda_pts_difference */


/***********************************************************************/
/* Convert a symbol into a pointer to shared.
 */
int uda_symbol_to_pts (uda_thread *thread,
		       const char *name,
		       uda_taddr   sym_addr,
		       uda_tword   block_size,
		       uda_tword   element_size,
		       uda_debugger_pts *res)
{
  upcr_shared_ptr_t sp;
  upcr_pshared_ptr_t ps;
  int status;

  TV_ASST_TRACE( ("sym_addr=%lu, block_size=%ld, element_size=%ld",
		(unsigned long)sym_addr, (long)block_size, (long)element_size) )

  /* Read proxy pointer at symbol address, then get info out of it */
  if (block_size <= 1) {
      status = read_pshared_ptr(thread, sym_addr, &ps);
      if (status)
	  return status;
      res->phase  = 0;
      res->thread = upcr_threadof_pshared(ps);
      res->addrfield= (uda_taddr) upcr_addrfield_pshared(ps);
  } else {
      status = read_shared_ptr(thread, sym_addr, &sp);
      if (status)
	  return status;
      res->phase  = upcr_phaseof_shared(sp);
      res->thread = upcr_threadof_shared(sp);
      res->addrfield= (uda_taddr) upcr_addrfield_shared(sp);
  }

  res->opaque = 0;

  TV_ASST_TRACE( ("returning: addrfield=%lu, thread=%ld, phase=%ld\n", 
		(unsigned long)res->addrfield, (long)res->thread, (long)res->phase ) )

  return uda_ok;
} /* uda_symbol_to_pts */


/******************************************************************************
 * Implementations of variables/functions needed by functions in upcr_sptr.h
 ******************************************************************************/

const upcr_shared_ptr_t upcr_null_shared = UPCR_NULL_SHARED;
const upcr_pshared_ptr_t upcr_null_pshared = UPCR_NULL_PSHARED;

int bupc_assistant_mythread (uda_thread *thread)
{
    uda_thread_info *info = ensure_have_thread_info(thread);
    if (info == NULL)
	return -1;
    return info->mythread;
}

int bupc_assistant_threads (uda_thread *thread)
{
    uda_thread_info *info = ensure_have_thread_info(thread);
    if (info == NULL)
	return -1;
    return info->threads;
}

uintptr_t  bupc_assistant_myregion (uda_thread *thread)
{
    uda_thread_info *info = ensure_have_thread_info(thread);
    if (info == NULL)
	return -1;
    return info->myregion;
}

#if ! UPCRI_SINGLE_ALIGNED_REGIONS
uintptr_t *bupc_assistant_thread2region (uda_thread *thread)
{
    uda_thread_info *info = ensure_have_thread_info(thread);
    if (info == NULL)
	return NULL;
    return info->thread2region;
}
#endif

/**********************************************************************
 * That's all folks.
 **********************************************************************/

