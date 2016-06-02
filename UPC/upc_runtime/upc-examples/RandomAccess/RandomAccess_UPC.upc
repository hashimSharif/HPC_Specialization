/*-----------------------------------------------------------------------------

  RandomAccess Benchmark - UPC version - RandomAccess_UPC.c

  -- X1 ready version -- 10/28/04 --

  This benchmark is a UPC version of the RandomAccess code, developed by the
  High Performance Computing Laboratory at the George Washington University.

  Information on the UPC project at GWU is available at:

           http://upc.gwu.edu

  This benchmark is derived from the code from the High Performance Computing
  Challenge Benchmark Suite available at http://icl.cs.utk.edu/hpcc/

  UPC version:      F. Cantonnet    - GWU - HPCL (fcantonn@gwu.edu)
                    Y. Yao          - GWU - HPCL (yyy@gwu.edu)
                    T. El-Ghazawi   - GWU - HPCL (tarek@gwu.edu)

  Authors (HPCC):   D. Koester      - MITRE
                    B. Lucas        - USC / ISI
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. This program
    can be freely redistributed provided that you conspicuously and
    appropriately publish on each copy an appropriate referral notice to
    the authors and disclaimer of warranty; keep intact all the notices
    that refer to this License and to the absence of any warranty; and
    give any other recipients of the Program a copy of this License along
    with the Program.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA02111-1307 USA
-----------------------------------------------------------------------------*/

/* The benchmark is successfully completed if at least 99% of the table
 * is correctly built; it *is* OK, for example, to have a few errors
 * enter into the table due to rare race conditions between processors
 * updating the same memory location.
 *
 * It is expected that in a multi-processor version, one will start the
 * random number generator at N equally spaced spots along its cycle.
 * Each processor then steps the generator through its section of the
 * cycle.  (The starts routine provided can be used to start the
 * random number generator at any specified point.)
 *
 * The benchmark objective is to measure interprocessor bandwidth.  It
 * is ok to bucket sort locally and use a message passing protocol
 * between processors if this is faster than a global shared memory
 * approach.  More sophisticated optimizations which attempt to reorder
 * the loop so that all updates are local are not considered "in the
 * spirit" of the benchmark. */

#include <upc_relaxed.h>
#include <hpcc.h>

//#define LONG_IS_64BITS 1

#include "RandomAccess_UPC.h"
#include "string.h"

/* Number of updates to table (suggested: 4x number of table entries) */
#define NUPDATE (4 * TableSize)

/* Allocate main table (in global memory) */
shared u64Int *Table;
u64Int logTableSize, TableSize;
u64Int rank;

shared u64Int sh_temp[THREADS];

#define MAXJOBS 16384

void
RandomAccessUpdate(u64Int TableSize)
{
  s64Int i;
  static u64Int _ran[MAXJOBS];              /* Current random numbers */
  u64Int * const ran = _ran;
  int j;

  /* Initialize main table */
  for( i=MYTHREAD; i<TableSize; i+= THREADS )
    Table[i] = i;

  /* Perform updates to main table.  The scalar equivalent is:
   *
   *     u64Int ran;
   *     ran = 1;
   *     for (i=0; i<NUPDATE; i++) {
   *       ran = (ran << 1) ^ (((s64Int) ran < 0) ? POLY : 0);
   *       table[ran & (TableSize-1)] ^= ran;
   *     }
   */

  upc_barrier;

  for( j=MYTHREAD; j<MAXJOBS; j+=THREADS )
    ran[j] = starts ((NUPDATE/MAXJOBS) * j);

  for (i=0; i<NUPDATE/MAXJOBS; i++ )
    {
#ifdef _CRAY
#pragma _CRI concurrent
#endif
      for( j=MYTHREAD; j<MAXJOBS; j+=THREADS )
	{
          ran[j] = (ran[j] << 1) ^ ((s64Int) ran[j] < 0 ? POLY : 0);

	  Table[(ran[j] & (TableSize-1))] ^= ran[j];
        }
    }
}

int main(int argc, char **argv )
{
  double d_gups;
  int pow2_size;
  int r, i_failure;
  char *tmp;
  HPCC_Params p;

  if( argc == 2 )
    {
      sscanf( argv[1], "%d", &pow2_size );
      for( r=0, p.HPLMaxProcMem=sizeof(u64Int); 
	   r<pow2_size; r++, p.HPLMaxProcMem <<= 1 );
    }
  else
    p.HPLMaxProcMem = 16*1024*1024;

  tmp = p.outFname;
  strcpy(tmp, "output.txt" );
  r = RandomAccess( &p, 1, &d_gups, &i_failure );

  return r;
}

int
RandomAccess(HPCC_Params *params, int doIO, double *GUPs, int *failure)
{
  s64Int i, j;
  u64Int temp;
  double cputime;               /* CPU time to update table */
  double realtime;              /* Real time to update table */
  double totalMem;
  FILE *outFile;

  if( MYTHREAD == 0 )
    {
      if (doIO)
        {
          outFile = fopen( params->outFname, "a" );
          if (! outFile)
            {
              outFile = stderr;
              fprintf( outFile, "Cannot open output file.\n" );
	      upc_global_exit(1);
            }
        }
    }

  /* calculate local memory per node for the update table */
  totalMem = params->HPLMaxProcMem;
  totalMem /= sizeof(u64Int);

  /* calculate the size of update array (must be a power of 2) */
  for (totalMem *= 0.5, logTableSize = 0, TableSize = 1;
       totalMem >= 1.0;
       totalMem *= 0.5, logTableSize++, TableSize <<= 1)
    ; /* EMPTY */

  if( MYTHREAD == 0 )
    {
      /* Print parameters for run */
      if (doIO)
      {
        fprintf( outFile, "Running on %d processors\n", THREADS );
        fprintf( outFile, "Main table size   = 2^" FSTR64 " = " FSTR64 " words\n", 
                 (long long int)logTableSize, (long long int)TableSize);
        fprintf( outFile, "Number of updates = " FSTR64 "\n", (long long int)NUPDATE);
      }
      printf( "Running on %d processors\n", THREADS );
      printf( "Main table size   = 2^" FSTR64 " = " FSTR64 " words\n", 
                (long long int)logTableSize, (long long int)TableSize);
      printf( "Number of updates = " FSTR64 "\n", (long long int)NUPDATE);
    }  

  Table = (shared u64Int *) upc_all_alloc(TableSize,sizeof(u64Int));
  if (! Table)
    {
      if (doIO)
        {
          fprintf( outFile, "Failed to allocate memory for the update table (" FSTR64 ").\n", 
                            (long long int) TableSize);
          fclose( outFile );
        }
      upc_global_exit(1);
    }

  upc_barrier;

  /* Begin timing here */
  cputime = -CPUSEC();
  realtime = -RTSEC();

  RandomAccessUpdate( TableSize );

  upc_barrier;

  /* End timed section */
  cputime += CPUSEC();
  realtime += RTSEC();

  if( MYTHREAD==0 )
    {
      /* make sure no division by zero */
      *GUPs = (realtime > 0.0 ? 1.0 / realtime : -1.0);
      *GUPs *= 1e-9*NUPDATE;

      /* Print timing results */
      if (doIO)
      {
        fprintf( outFile, "CPU time used  = %.6f seconds\n", cputime);
        fprintf( outFile, "Real time used = %.6f seconds\n", realtime);
        fprintf( outFile, "%.9f Billion(10^9) Updates    per second [GUP/s]\n", *GUPs );
      }
      printf( "CPU time used  = %.6f seconds\n", cputime);
      printf( "Real time used = %.6f seconds\n", realtime);
      printf( "%.9f Billion(10^9) Updates    per second [GUP/s]\n", *GUPs );
    }

  /* Verification of results (in serial or "safe" mode; optional) */
  if( NUPDATE < 10e7 )
    {
      temp = 0x1;
      for (i=0; i<NUPDATE; i++)
	{
	  temp = (temp << 1) ^ (((s64Int) temp < 0) ? POLY : 0);
	  
	  rank = (temp & (TableSize-1))%THREADS;
	  
	  if( rank == MYTHREAD )
	    {
	      Table[(temp & (TableSize-1))] ^= temp;
	    }
	}
      
      upc_barrier;
      
      temp = 0;
      upc_forall( j=0; j<TableSize; j++; j%THREADS )
	if (Table[j] != j)
	  temp++;
	
	sh_temp[MYTHREAD] = temp;
	upc_barrier;
	
	if( MYTHREAD == 0 )
	  {
	    temp = sh_temp[0];
	    for( i=1; i<THREADS; i++ )
	      temp += sh_temp[i];
	    
	    if (doIO)
	      {
		fprintf( outFile, "Found " FSTR64 " errors in " FSTR64 " locations (%s).\n",
			 (long long int)temp, (long long int)TableSize, 
                         (temp <= 0.01*TableSize) ? "passed" : "failed");
	      }
	    printf( "Found " FSTR64 " errors in " FSTR64 " locations (%s).\n",
		    (long long int)temp, (long long int)TableSize, 
                    (temp <= 0.01*TableSize) ? "passed" : "failed");
	    
	    if (temp <= 0.01*TableSize)
	      *failure = 0;
	    else
	      *failure = 1;
	    
	    if (doIO)
	      {
		fflush( outFile );
		fclose( outFile );
	      }
	  }
    }
  else
    {
      if( MYTHREAD == 0 )
	{
	    if (doIO)
	      {
		fflush( outFile );
		fclose( outFile );
	      }
	}
    }

  return 0;
}

/* Utility routine to start random number generator at Nth step */
u64Int
starts(s64Int n)
{
  /* s64Int i, j; */
  int i, j;
  u64Int m2[64];
  u64Int temp, ran;

  while (n < 0)
    n += PERIOD;
  while (n > PERIOD)
    n -= PERIOD;
  if (n == 0)
    return 0x1;

  temp = 0x1;
  for (i=0; i<64; i++)
    {
      m2[i] = temp;
      temp = (temp << 1) ^ ((s64Int) temp < 0 ? POLY : 0);
      temp = (temp << 1) ^ ((s64Int) temp < 0 ? POLY : 0);
    }

  for (i=62; i>=0; i--)
    if ((n >> i) & 1)
      break;

  ran = 0x2;
  while (i > 0)
    {
      temp = 0;
      for (j=0; j<64; j++)
        if ((ran >> j) & 1)
          temp ^= m2[j];
      ran = temp;
      i -= 1;
      if ((n >> i) & 1)
        ran = (ran << 1) ^ ((s64Int) ran < 0 ? POLY : 0);
    }

  return ran;
}

