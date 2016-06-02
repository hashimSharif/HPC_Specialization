/* Copyright (C) 2001-2013 Free Software Foundation, Inc.
   This file is part of the UPC runtime library test suite.
   Written by Gary Funck <gary@intrepid.com>
   and Nenad Vukicevic <nenad@intrepid.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#include <upc_strict.h>
#include <stdio.h>
#include <stdlib.h>

#define DIM1 1024

void
test08 ()
{
  extern shared int array[DIM1][THREADS];
  int i, j;
  for (i = 0; i < DIM1; ++i)
    {
      array[i][MYTHREAD] = (i + 1) * (MYTHREAD + 1);
    }
  upc_barrier;
  if (MYTHREAD == 0)
    {
      for (i = 0; i < DIM1; ++i)
	{
	  for (j = 0; j < THREADS; ++j)
	    {
	      int got = array[i][j];
	      int expected = (i + 1) * (j + 1);
	      if (got != expected)
		{
		  fprintf (stderr, "test08: error at element [%d,%d]. Expected %d, got %d\n",
			   i, j, expected, got);
		  abort ();
		}
	    }
	}
      printf ("test08: simple external 2-dimensional array test - passed.\n");
    }
}
