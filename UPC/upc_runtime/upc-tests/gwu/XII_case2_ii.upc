/*
UPC Testing Suite

Copyright (C) 2000 Chen Jianxun, Sebastien Chauvin, Tarek El-Ghazawi

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
/**
   Test: XII_case2_ii - dynamic locks
   Purpose: Check the lock dynamic allocation
   Type: Positive.
   How : - Use the upc_all_lock_alloc to allocate a lock
         - Use upc_lock to protect a critical section
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <upc.h>

upc_lock_t* lock1;

shared int v;

int main()
{
  int i;
  int pe=MYTHREAD;
  int errflag=0;

  v = 0;
  upc_barrier 1;

  printf("before alloc\n");
  lock1 = upc_all_lock_alloc();
  printf("after alloc\n");
  upc_lock(lock1);
  printf("after lock\n");
  i=v;
  sleep(1);
  printf("after sleep\n");
  v=i+1;
  upc_unlock(lock1);
  printf("after unlock\n");

  /* Next two lines reduce the chance of the Success/Failure message getting
     interleaved with the before/after messages.
   */
  fflush(stdout);
  sleep(1);

  upc_barrier 2;

  if (!MYTHREAD)
  { if (v!=THREADS)
      errflag = 1;
  }
  
  if (errflag) {
      printf("Failure: on Thread %d with errflag %d\n",MYTHREAD,errflag);
  } else if (MYTHREAD == 0) {
      printf("Success: on Thread %d \n",MYTHREAD);
  }

  return(errflag);   
}


