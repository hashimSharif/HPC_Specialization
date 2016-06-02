#include <stdio.h>
#include <stdlib.h>
#include "upc.h"

typedef struct
{
  long x;
} STRUCT1;

typedef struct
{
  int y;
  int z;
} STRUCT2;

typedef union
{
  STRUCT1 S1;
  STRUCT2 S2;
} UNION1;

int main()
{
  UNION1 U1;

  // U1.S1.x = 0;  (ok)
  // U1.S2.y = 0;  (ok)
  U1.S2.z = 0;    // error

  return 0;
}

