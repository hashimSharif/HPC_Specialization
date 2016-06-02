/********************************************************************************************  
 *	Author: Nam Nguyen
 *  Partner: Burt Gordon
 *   With help from Chris Conger and Matt Murphy on cryptology theory and psuedocode.
 *
 *	Spring 2003
 *
 *		Written and tested with resources made available by the 
 *		High-performance Computing and Simulation (HCS) Laboratory,
 *		University of Florida
 *
 * ##################### DESCRIPTION and EXECUTION INFO #################################
 * Differential Simulator
 *
 *     This program simulates a simple differential analysis of made-up
 *  S-Boxes.  Use the definitions noted below to change the different
 *  parameters of the S-Boxes, such as the number of input/output bits,
 *  number of S-Boxes, etc.  This should drastically affect the memory
 *  performance of this program.  Larger input and output bit #s will produce
 *  exponentially larger tables (memory consumption) and execution time.
 *
 *     The number of input bits should be any power of two and the number of
 *  output bits can be anything.  If you choose large numbers of input/output 
 *  bits, try using only 2 or 1 S-Boxes.
 *
 *  Make sure that you specify -fthreads when you compile this code. Otherwise
 *  errors are reported for the declaration of global variables.
 *
 *  This code was written for and is known to with the Compaq (now HP) UPC 
 *  compiler V2.0 and V2.1.
 *
 ***************************************************************************************/

#include <stdio.h>
#include <upc.h>
#include <upc_relaxed.h>
#include <sys/time.h>

#define NUMSBOXES 4            /* Number of S-Boxes */
#define NUMSINPUTS 8           /* Number of input bits to each S-Box */
#define NUMSOUTPUTS 8          /* Number of output bits from each S-Box */
char logfile[] = "parlog";     /* Name of file results are written to */

#define inputSq (1<<NUMSINPUTS)
#define outputSq (1<<NUMSOUTPUTS)
#define TOTALINPUT NUMSBOXES*NUMSINPUTS
#define TOTALOUTPUT NUMSBOXES*NUMSOUTPUTS
#define COLUMN unsigned int
#define ROW unsigned int
#define ELEMENT unsigned int
#define INDEX unsigned int
#define UINT unsigned int
#define MAX_BLK_SIZE 128
#define BLKSIZE 128

/*============================Global Variables============================*/

shared [BLKSIZE] ELEMENT DPS[NUMSBOXES][inputSq][inputSq];   // DPS table
shared [BLKSIZE] ELEMENT DTS[NUMSBOXES][inputSq][outputSq];  // DTS table
shared [BLKSIZE] UINT sBox[NUMSBOXES][inputSq];  // S-Boxes

shared int dex[NUMSBOXES];
shared int dey[NUMSBOXES];
shared double prob[NUMSBOXES];

UINT LFSRstart = 0xfa9b3701;
UINT centerMask = ((1<<((3*NUMSINPUTS)/4)) - (1<<(NUMSINPUTS/4)));
UINT MSBmask = ((1<<NUMSINPUTS) - (1<<((3*NUMSINPUTS)/4)));
UINT LSBmask = ((1<<(NUMSINPUTS/4)) - 1);
UINT rowLength = (1<<(NUMSINPUTS/2));
UINT centerShift = NUMSINPUTS/4;
UINT MSBshift = NUMSINPUTS/2;
//shared UINT feedback;
//shared int f[4];

/*==========================General Functions==============================*/

/* Creates the S-boxes to be used. */
void create_sBoxes()
{
   INDEX i,j,r; 
   int f1,f2,f3,f4;
   UINT temp,Itemp,feedback,bit;
   UINT sElementTemp;

   temp = LFSRstart;                             /* start off LFSR */
   for(r=0;r<NUMSBOXES;r++)
   {
     for(i=0;i<inputSq;i++)
	 {
       sElementTemp =0;
       for(j=0;j<NUMSOUTPUTS;j++)
	   {
         /* GENERATE 1 BIT */
   	     f1 = ((1U << 31) & temp)?1:0;      /* Primitive Feedback Polynomial */
         f2 = ((1 << 6) & temp)?1:0;
     	 f3 = ((1 << 5) & temp)?1:0;
     	 f4 = ((1 << 1) & temp)?1:0;
         feedback = f1^f2^f3^f4;               	    /* compute feedback bit */
         Itemp = ((temp >> 1) & 2147483647);        /* right shift 1, mask  */
         temp = (feedback << 31)|Itemp;             /* add feedback as MSB  */
         bit = (1 & temp)?1:0;  	     /* compute next bit of string A */

         sElementTemp |= (bit<<(NUMSOUTPUTS-j-1));
       }

       sBox[r][i]=sElementTemp;

     }
   }
}


/*=========================Cryptanalytic Functions=========================*/
ELEMENT SIO(INDEX k, COLUMN col, shared [BLKSIZE] UINT S[NUMSBOXES][inputSq])
{
   ELEMENT value;
   UINT r,c;
   c = (col & centerMask) >> centerShift;
   r = ((col & MSBmask) >> MSBshift) | (col & LSBmask);
   value = S[k][rowLength*r + c];
   return value;
}


void findDC(INDEX k, shared [BLKSIZE]  ELEMENT DT[NUMSBOXES][inputSq][outputSq])
{
   ELEMENT curV,curL=0;
   INDEX i,j;

   for(i=0;i<inputSq;i++)
   {
      for(j=0;j<outputSq;j++)
	  {
         curV=DT[k][i][j];
         if((curV>curL)&(curV!=inputSq))
	     {
            curL = curV;
            dex[k] = i;
            dey[k] = j;
         }
      }
   }
   prob[k]=((double) curL)/inputSq;

}


int main(void)
{
   int cnt, SBox_index, DPS_index, DTS_index;
   INDEX i,j,k,r,x,dx,dy; 
   unsigned long int sboxMem; 
   double memory, probability = 1.0;
   long time0, time1, time2, time3, time4, totaltime;
   long count = 0;
   struct timeval currentTime;
   ELEMENT *DTS_ptr, *DPS_ptr, *SBox_ptr;
   ELEMENT **DTS_pptr;
   ELEMENT **DPS_pptr;
   FILE *fid; 
   //fid = fopen(logfile, "w");


/* THIS PORTION IS FOR THE LOG FILE ONLY AND CAN BE OMITTED
   sboxMem = 4*inputSq*(inputSq+outputSq) + 4*inputSq + 16;
   memory = 4*NUMSBOXES*inputSq*(inputSq+outputSq+1)+(4*7)+(16*NUMSBOXES);
   fprintf(fid,"Simulated Differential Analysis of Generic S-Boxes\n\n");
   fprintf(fid,"# of S-Boxes................. %i\n\n",NUMSBOXES);
   fprintf(fid,"# of input bits per S-Box:    %i\n",NUMSINPUTS);
   fprintf(fid,"# of output bits per S-Box:   %i\n",NUMSOUTPUTS);
   fprintf(fid,"Total number of input bits:   %i\n",TOTALINPUT);
   fprintf(fid,"Total number of output bits:  %i\n\n\n",TOTALOUTPUT);
   fprintf(fid,"Size of 1 S-Box:		%i Bytes\n",inputSq*4);
   fprintf(fid,"Memory to store all S-Boxes:%i Bytes\n\n",NUMSBOXES*inputSq*4);
   fprintf(fid,"Including all tables...\n");
   fprintf(fid,"Memory per S-Box:		%i Bytes\n",sboxMem);
   fprintf(fid,"Memory Used/Required >         .3f MB\n\n",memory/1048576);*/

/*********** THIS BEGINS THE MAIN PORTION OF THE PROGRAM **************************** */
   
   //printf("Thread %u running...\n-------------------\n\n", MYTHREAD); 
   gettimeofday(&currentTime, NULL);
   time0 = currentTime.tv_sec*1000000 + currentTime.tv_usec;

	//generation of S boxes is sequential
   if(MYTHREAD == 0)
        create_sBoxes();             // generate arbitrary S-Boxes

   gettimeofday(&currentTime, NULL);
   time1 = currentTime.tv_sec*1000000 + currentTime.tv_usec;
   
/* Fill in the Difference Pair Tables */
   upc_barrier 1;
   for(r=0; r<NUMSBOXES; r++)
   {
     for(dx=0; dx<inputSq; dx++)
     {
       upc_forall(i=0; i<inputSq; i+=BLKSIZE; upc_threadof(DPS[r][dx] + i))
       {  
			DPS_ptr = (ELEMENT *) (DPS[r][dx]+i);
			for(x=i; x<i+BLKSIZE; x++)
				DPS_ptr[x-i]=( ( SIO(r,x,sBox) ) ^( SIO(r,x^dx,sBox) ) );
       }
     }
   }

   gettimeofday(&currentTime, NULL);
   time2 = currentTime.tv_sec*1000000 + currentTime.tv_usec;   

/* Fill in the Difference Distribution Tables */
   upc_barrier 2;

   for(r=0; r<NUMSBOXES; r++)
   {
      for(dx=0; dx<inputSq; dx++)
      { 
		upc_forall(j=0; j<outputSq; j+=BLKSIZE; upc_threadof(&DTS[r][dx][j]))
		{
			DTS_ptr = (ELEMENT *) (&DTS[r][dx][j]);
            for(dy=0; dy<BLKSIZE; dy++)
            {
#if 0
				cnt=0;
				for(k=0; k<inputSq; k+=BLKSIZE)
				{ 
			// DOB: the cast below is erroneous because k steps off the end
			// of the local block of DPS (inputSq > BLKSIZE)
			//		DPS_ptr = (ELEMENT *) (&DPS[r][dx][k]);
			// naive, temporary work-around:
                                  shared [BLKSIZE] ELEMENT *DPS_ptr = (&DPS[r][dx][k]);
					for(i = 0; i < BLKSIZE; i++)
					{
						count++;
						if(DPS_ptr[i]==dy)
					    	cnt++;					
					}
				}
				DTS_ptr[dy] = cnt;
#else
/* fix from Burt, 1/9/2004 */
                                cnt=0;
                                for(k=0; k<inputSq; k++)
                                {                                               
                                        if(DPS[r][dx][k]==dy)
                                        cnt++;  
                                }
                                DTS_ptr[dy] = cnt; 

#endif
			}
		}
      }
	}

   upc_barrier 3;
   gettimeofday(&currentTime, NULL);
   time3 = currentTime.tv_sec*1000000 + currentTime.tv_usec;
  

	// determine best pair for each SBox
   for(r=0; r<NUMSBOXES; r++) 
      findDC(r, DTS);

   gettimeofday(&currentTime, NULL);
   time4 = currentTime.tv_sec*1000000 + currentTime.tv_usec;
   //printf("Time 4 = %u\n", time4);

   /* THIS ENDS THE MAIN PORTION OF THE PROGRAM ******************************/

// Printing out the Execution times
   upc_barrier 4;
   if(MYTHREAD == 0)
   {
		printf("Time to create S-Boxes: %li us\n",time1-time0);
	    printf("Time to create DPTs: %li us\n",time2-time1);
		printf("Time to create DDTs:	%li us\n",time3-time2);
		printf("Time to pick best difference pair: %li us\n",time4-time3);
	    printf("Total execution time: %li us\n",time4-time0);
		//printf("Speedup: %0.12f\n\n", 571849.0/((double) (time4-time0)));

		for(r=0; r<NUMSBOXES; r++)
		{
		  // printf("For S-Box %i\n --------------------------\n", r);
		  printf("Best Difference Pair: dex = %i , dey = %i \n", dex[r], dey[r]);
		  // printf("Number of Occurences:	%.0f\n",(prob[r]*inputSq));
		  // printf("Probability = %f \n\n", prob[r]);
		  probability = probability*prob[r];
		}

        printf("Probability of Characteristic\n -----------------------\n");
        printf("Probability = %0.8f\n\n", probability);

		
   //fclose(fid);
   }//end printing of info by thread 0

   upc_barrier 5;

   printf("done.\n");
   return 0;
}


