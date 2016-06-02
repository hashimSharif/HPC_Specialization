/*   $Source: bitbucket.org:berkeleylab/upc-runtime.git/profile/gasp_upc.h $ */
/*  Description: GASP API header file - UPC specific declarations */
/*  Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#ifndef _GASP_UPC_H
#define _GASP_UPC_H

typedef void gasp_upc_PTS_t; /* a void C "dummy" for (shared void *) */
typedef void gasp_upc_lock_t;

/* non-blocking handles */
#define GASP_UPC_NB_TRIVIAL           ((gasp_upc_nb_handle_t)0)
#define GASP_UPC_NBI_TRIVIAL          ((gasp_upc_nb_handle_t)-1)
typedef void *gasp_upc_nb_handle_t;

#define GASP_UPC_VERSION       0x020311

#define GASP_UPC_EVT_NONE      0

/* used by tool to allocate user events */
#define GASP_UPC_USEREVT_START 100
#define GASP_UPC_USEREVT_END   999

#define _GASP_UPC_SYSEVT_START 1000

/* library calls */
#define GASP_UPC_ALLOC                _GASP_UPC_SYSEVT_START+0
#define GASP_UPC_GLOBAL_ALLOC         _GASP_UPC_SYSEVT_START+1
#define GASP_UPC_ALL_ALLOC            _GASP_UPC_SYSEVT_START+2
#define GASP_UPC_FREE                 _GASP_UPC_SYSEVT_START+3

#define GASP_UPC_GLOBAL_LOCK_ALLOC    _GASP_UPC_SYSEVT_START+10
#define GASP_UPC_ALL_LOCK_ALLOC       _GASP_UPC_SYSEVT_START+11
#define GASP_UPC_LOCK_FREE            _GASP_UPC_SYSEVT_START+12
#define GASP_UPC_LOCK_ATTEMPT         _GASP_UPC_SYSEVT_START+13
#define GASP_UPC_LOCK                 _GASP_UPC_SYSEVT_START+14
#define GASP_UPC_UNLOCK               _GASP_UPC_SYSEVT_START+15

#define GASP_C_MALLOC                 _GASP_UPC_SYSEVT_START+20
#define GASP_C_REALLOC                _GASP_UPC_SYSEVT_START+21
#define GASP_C_FREE                   _GASP_UPC_SYSEVT_START+22
#define GASP_C_FUNC                   _GASP_UPC_SYSEVT_START+23

#define GASP_UPC_MEMGET               _GASP_UPC_SYSEVT_START+30
#define GASP_UPC_MEMPUT               _GASP_UPC_SYSEVT_START+31
#define GASP_UPC_MEMCPY               _GASP_UPC_SYSEVT_START+32
#define GASP_UPC_MEMSET               _GASP_UPC_SYSEVT_START+33

/* language ops */
#define GASP_UPC_NOTIFY               _GASP_UPC_SYSEVT_START+100
#define GASP_UPC_WAIT                 _GASP_UPC_SYSEVT_START+101

#define GASP_UPC_PUT                  _GASP_UPC_SYSEVT_START+110 
#define GASP_UPC_GET                  _GASP_UPC_SYSEVT_START+111

#define GASP_UPC_NB_GET_INIT          _GASP_UPC_SYSEVT_START+120
#define GASP_UPC_NB_PUT_INIT          _GASP_UPC_SYSEVT_START+121
#define GASP_UPC_NB_SYNC              _GASP_UPC_SYSEVT_START+122

#define GASP_BUPC_NB_TRYSYNC          _GASP_UPC_SYSEVT_START+130
#define GASP_BUPC_NB_MEMGET_INIT      _GASP_UPC_SYSEVT_START+131
#define GASP_BUPC_NB_MEMPUT_INIT      _GASP_UPC_SYSEVT_START+132
#define GASP_BUPC_NB_MEMCPY_INIT      _GASP_UPC_SYSEVT_START+133

#define GASP_BUPC_STATIC_SHARED       _GASP_UPC_SYSEVT_START+140

/* atomic events issued by runtime on shutdown */
#define GASP_UPC_COLLECTIVE_EXIT      _GASP_UPC_SYSEVT_START+210
#define GASP_UPC_NONCOLLECTIVE_EXIT   _GASP_UPC_SYSEVT_START+211

#define GASP_UPC_ALL_BROADCAST        _GASP_UPC_SYSEVT_START+300
#define GASP_UPC_ALL_SCATTER          _GASP_UPC_SYSEVT_START+310
#define GASP_UPC_ALL_GATHER           _GASP_UPC_SYSEVT_START+320
#define GASP_UPC_ALL_GATHER_ALL       _GASP_UPC_SYSEVT_START+330
#define GASP_UPC_ALL_EXCHANGE         _GASP_UPC_SYSEVT_START+340
#define GASP_UPC_ALL_PERMUTE          _GASP_UPC_SYSEVT_START+350

#define GASP_UPC_ALL_REDUCE           _GASP_UPC_SYSEVT_START+400
#define GASP_UPC_ALL_PREFIX_REDUCE    _GASP_UPC_SYSEVT_START+410

typedef enum {
  GASP_UPC_REDUCTION_C = 0,
  GASP_UPC_REDUCTION_UC= 1,
  GASP_UPC_REDUCTION_S = 2,
  GASP_UPC_REDUCTION_US= 3,
  GASP_UPC_REDUCTION_I = 4,
  GASP_UPC_REDUCTION_UI= 5,
  GASP_UPC_REDUCTION_L = 6,
  GASP_UPC_REDUCTION_UL= 7,
  GASP_UPC_REDUCTION_F = 8,
  GASP_UPC_REDUCTION_D = 9,
  GASP_UPC_REDUCTION_LD= 10
} gasp_upc_reduction_t;

#endif
