/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/profile/gasp.h $ */
/*  Description: GASP API header file  */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#ifndef _GASP_H
#define _GASP_H

/* ------------------------------------------------------------------------------------ */
/* model-independent GASP declarations */

#ifdef __cplusplus
  extern "C" {
#endif

#define GASP_VERSION 20060914L

typedef enum {
  GASP_MODEL_UPC,
  GASP_MODEL_TITANIUM,
  GASP_MODEL_CAF,
  GASP_MODEL_MPI,
  GASP_MODEL_SHMEM
} gasp_model_t;

/* --- deprecated names, to be removed in GASP spec v1.5: --- */
#define gasp_lang_t          gasp_model_t
#define GASP_LANG_UPC        GASP_MODEL_UPC
#define GASP_LANG_TITANIUM   GASP_MODEL_TITANIUM
#define GASP_LANG_CAF        GASP_MODEL_CAF
#define GASP_LANG_MPI        GASP_MODEL_MPI
#define GASP_LANG_SHMEM      GASP_MODEL_SHMEM
/* ---------------------------------------------------------- */

typedef enum {
  GASP_START,
  GASP_END,
  GASP_ATOMIC
} gasp_evttype_t;

struct _gasp_context_S;
typedef struct _gasp_context_S *gasp_context_t;

/* init the interface with a model, and get the thread-specific context */
gasp_context_t gasp_init(gasp_model_t srcmodel, int *argc, char ***argv);

/* notify the interface of a system-level or user-initiated event */
void gasp_event_notify(gasp_context_t context, unsigned int evttag, gasp_evttype_t evttype,
                       const char *filename, int linenum, int colnum, ...);
/* alternate interface where varargs are passed as a va_list 
   useful for writing compiler-provided wrappers like pupc_event_start()
 */
void gasp_event_notifyVA(gasp_context_t context, unsigned int evttag, gasp_evttype_t evttype,
                       const char *filename, int linenum, int colnum, va_list varargs);

/* enable or disable collection for this thread, and return the prior value 
   called by UPC compiler's implementation of pupc_control
 */
int gasp_control(gasp_context_t context, int on);

/* create a thread-specific user-level event handle, and associate an optional name 
   and printf-like description string to be evaluated upon each notification 
   called by UPC compiler's implementation of pupc_create_event
*/
unsigned int gasp_create_event(gasp_context_t context, const char *name, const char *desc);

#ifdef __cplusplus
  }
#endif

#endif
