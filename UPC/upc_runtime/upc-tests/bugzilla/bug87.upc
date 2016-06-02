/* all the headers listed in the ANSI-C spec */

#include <assert.h>
#if 0
/* complex currently not supported */
#include <complex.h>
#include <tgmath.h>
#endif
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>

#define CHECKSZ(x,val) assert(sizeof(x) == val)
int main(void) {
  int8_t  i8 = 0;
  uint8_t u8 = 0;
  int16_t  i16 = 0;
  uint16_t u16 = 0;
  int32_t  i32 = 0;
  uint32_t u32 = 0;
  int64_t  i64 = 0;
  uint64_t u64 = 0;
  intptr_t ip = 0;
  uintptr_t up = 0;
  bool b = true;
  CHECKSZ(int8_t,1);
  CHECKSZ(uint8_t,1);
  CHECKSZ(int16_t,2);
  CHECKSZ(uint16_t,2);
  CHECKSZ(int32_t,4);
  CHECKSZ(uint32_t,4);
  CHECKSZ(int64_t,8);
  CHECKSZ(uint64_t,8);
  CHECKSZ(i8,1);
  CHECKSZ(u8,1);
  CHECKSZ(i16,2);
  CHECKSZ(u16,2);
  CHECKSZ(i32,4);
  CHECKSZ(u32,4);
  CHECKSZ(i64,8);
  CHECKSZ(u64,8);
  u64=u64+u32+u16+u8;
  i64=i64+i32+i16+i8;
  printf("done.\n");
  return 0;
}


