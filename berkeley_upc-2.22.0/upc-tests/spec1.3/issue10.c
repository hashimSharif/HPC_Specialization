#include "upc_types.h"
#include <assert.h>
#include <stdio.h>

#if UPC_IN_ALLSYNC  <= 0 || \
    UPC_IN_MYSYNC   <= 0 || \
    UPC_IN_NOSYNC   <= 0 || \
    UPC_OUT_ALLSYNC <= 0 || \
    UPC_OUT_MYSYNC  <= 0 || \
    UPC_OUT_NOSYNC  <= 0 
  #error bad flag value
#endif

#if UPC_ADD    <= 0 || \
    UPC_MULT   <= 0 || \
    UPC_AND    <= 0 || \
    UPC_OR     <= 0 || \
    UPC_XOR    <= 0 || \
    UPC_LOGAND <= 0 || \
    UPC_LOGOR  <= 0 || \
    UPC_MIN    <= 0 || \
    UPC_MAX    <= 0
  #error bad op value
#endif

#if UPC_CHAR    <= 0 || \
    UPC_UCHAR   <= 0 || \
    UPC_SHORT   <= 0 || \
    UPC_USHORT  <= 0 || \
    UPC_INT     <= 0 || \
    UPC_UINT    <= 0 || \
    UPC_LONG    <= 0 || \
    UPC_ULONG   <= 0 || \
    UPC_LLONG   <= 0 || \
    UPC_ULLONG  <= 0 || \
    UPC_INT8    <= 0 || \
    UPC_UINT8   <= 0 || \
    UPC_INT16   <= 0 || \
    UPC_UINT16  <= 0 || \
    UPC_INT32   <= 0 || \
    UPC_UINT32  <= 0 || \
    UPC_INT64   <= 0 || \
    UPC_UINT64  <= 0 || \
    UPC_FLOAT   <= 0 || \
    UPC_DOUBLE  <= 0 || \
    UPC_LDOUBLE <= 0 || \
    UPC_PTS     <= 0 
  #error bad type value
#endif

upc_op_t everyop[] = { UPC_ADD, UPC_MULT, UPC_AND, UPC_OR, UPC_XOR, UPC_LOGAND, UPC_LOGOR, UPC_MIN, UPC_MAX };
upc_flag_t everyflag[] = { UPC_IN_ALLSYNC, UPC_IN_MYSYNC, UPC_IN_NOSYNC, \
                           UPC_OUT_ALLSYNC, UPC_OUT_MYSYNC, UPC_OUT_NOSYNC };

upc_type_t everytype[] = {
 UPC_CHAR, UPC_UCHAR, UPC_SHORT, UPC_USHORT, 
 UPC_INT, UPC_UINT, UPC_LONG, UPC_ULONG, UPC_LLONG, UPC_ULLONG, 
 UPC_INT8, UPC_UINT8, UPC_INT16, UPC_UINT16, UPC_INT32, UPC_UINT32, UPC_INT64, UPC_UINT64, 
 UPC_FLOAT, UPC_DOUBLE, UPC_LDOUBLE, 
 UPC_PTS
};

int main() {
  int i,j;
  /* a few simple, non-comprehensive tests */
  upc_flag_t flag1 = 0;
  upc_flag_t flag2 = UPC_IN_ALLSYNC | UPC_OUT_MYSYNC;
  upc_op_t op1 = UPC_ADD | UPC_MIN | UPC_MAX;
  upc_type_t type1 = UPC_INT;
  upc_type_t type2 = UPC_LONG;

  /* more rigorous tests */
  { 
    upc_flag_t allflags = 0;
    for(i = 0; i < sizeof(everyflag)/sizeof(upc_flag_t); i++) {
      assert(everyflag[i]);
      assert((allflags & everyflag[i]) == 0);
      allflags = allflags | everyflag[i];
    }
    assert(allflags == 63);
  }

  {
    upc_op_t allops = 0;
    for(i = 0; i < sizeof(everyop)/sizeof(upc_op_t); i++) {
      assert(everyop[i] > 0);
      assert(everyop[i] < 65536);
      assert((allops & everyop[i]) == 0);
      allops = allops | everyop[i];
    }
  }

  {
    for(i = 0; i < sizeof(everytype)/sizeof(upc_type_t); i++) {
      assert(everytype[i] > 0);
      assert(everytype[i] < 65536);
      for(j = 0; j < sizeof(everytype)/sizeof(upc_type_t); j++) {
        if (i != j) assert(everytype[i] != everytype[j]);
      }
    }
  }
  printf("pass\n");
  return 0;
}
