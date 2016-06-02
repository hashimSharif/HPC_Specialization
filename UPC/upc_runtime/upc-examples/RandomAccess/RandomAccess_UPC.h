/*-----------------------------------------------------------------------------

  RandomAccess Benchmark - UPC version - RandomAccess.h

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

#if 0
static FILE *LogFile;
static void LogBegin(int p) {char fname[100]; sprintf(fname, "%d.log", p); LogFile = fopen(fname, "a");}
static void LogEnd() {if(LogFile) fclose(LogFile);}
#define DLOG(i,v) do{if(LogFile){fprintf(LogFile,__FILE__ "(%d)@%d:" #v "=%g\n",__LINE__,i,(double)(v));fflush(LogFile);}}while(0)
#endif

#include "inttypes.h"

typedef uint64_t u64Int;
typedef int64_t s64Int;
#define POLY 0x0000000000000007ULL
#define PERIOD 1317624576693539401LL
#define FSTR64 "%lld"

//wei: use the standard types directly, instead of the broken define scheme
#if 0
/* Types used by program (should be 64 bits) */
#ifdef LONG_IS_64BITS
typedef unsigned long u64Int;
typedef long s64Int;
#define FSTR64 "%ld"
#define ZERO64B 0L
#else
typedef unsigned long long u64Int;
typedef long long s64Int;
#define FSTR64 "%lld"
#define ZERO64B 0LL
#endif

/* Random number generator */
#ifdef LONG_IS_64BITS
#define POLY 0x0000000000000007UL
#define PERIOD 1317624576693539401L
#else
#define POLY 0x0000000000000007ULL
#define PERIOD 1317624576693539401LL
#endif
#endif

/* Macros for timing */
#define CPUSEC() ((double)clock()/CLOCKS_PER_SEC)
#define RTSEC() ((double)UPC_Wtime())
//(MPI_Wtime())

extern u64Int starts (s64Int);

#include <sys/time.h>

double UPC_Wtime()
{
  struct timeval sampletime;
  double time;

  gettimeofday( &sampletime, NULL );
  time = sampletime.tv_sec + (sampletime.tv_usec / 1000000.0);
  return( time );
}
