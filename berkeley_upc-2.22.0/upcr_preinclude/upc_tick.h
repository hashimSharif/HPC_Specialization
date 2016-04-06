/* upcr_extinclude/upc_tick.h */

#ifndef _UPC_TICK_H_
#define _UPC_TICK_H_

#if !defined(__UPC_TICK__) || (__UPC_TICK__ < 1)
#  error Bad feature macro predefinition
#endif

/* required, to define uint64_t  */
#include <stdint.h>

/* an integral type for holding ticks with its min and max values */
#ifndef __BERKELEY_UPC_SECOND_PREPROCESS__
# ifndef _UPCR_UTIL_H /* Avoid duplicate typedef */
  typedef uint64_t upc_tick_t;
# endif
# define UPC_TICK_MAX ((upc_tick_t)(int64_t)(-1))
# define UPC_TICK_MIN ((upc_tick_t)0)
#endif

extern upc_tick_t upc_ticks_now(void); /* the current tick value */
extern uint64_t upc_ticks_to_ns(upc_tick_t ticks); /* convert ticks to nanosecs */

#endif /* !_UPC_TICK_H_ */
