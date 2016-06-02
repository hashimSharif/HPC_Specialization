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
   Test: XII_case1_i - static locks
   Purpose: Check that upc_lock does lock.
   Type: Positive.
   How : - Use upc_lock to protect a critical section
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <upc.h>

upc_lock_t* shared lock1;

shared int v;

int main()
{
  int i;
  int pe=MYTHREAD;
  int errflag=0;

  v = 0;

  if (!MYTHREAD) lock1 = upc_global_lock_alloc();

  upc_barrier 1;

  upc_lock(lock1);
  i=v;
  sleep(1);  // To be sure to catch any problem
  v=i+1;
  upc_unlock(lock1);

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
