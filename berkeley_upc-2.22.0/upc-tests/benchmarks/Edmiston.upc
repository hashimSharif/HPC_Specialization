/* This is the program to compute Edit Distance Matrix 
 * using the Edmiston's Algorithm on MultiProcessors.
 * This program will further be used as a sub-routine
 * to implement Heirschberg's Divide and Conquer Algorithm.
 * i.e a hybrid of Heirschberg and Edmiston's Algorithm.
 *
 * PLZ NOTE: This code uses upc_all_alloc() (Shared Ptrs)
 *           and uses upc_barrier, which is suspected to
 *           be causing problems because of its blocking
 *           nature.  	
 *
 *
 *  Author: Sirisha Muppavarapu
 */

#include<upc_relaxed.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<upc.h>
#include<upc_tick.h>
#define iGapPen 2
#define iMatch 0
#define iMisMatch 1

/* Macro which determines the minimum of the two arguments */
#undef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
/* Macro which determines the maximum of the two arguments */
#undef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
/* Macro which determines the minimum of the three arguments */
#define MIN3(a,b,c) MIN(MIN((a),(b)),(c))
/* Macro which determines the maximum of the three arguments */
#define MAX3(a,b,c) MAX(MAX((a),(b)),(c))


/* Function Prototypes */
void initEditDistance();
void printEditDistance(char *cSeq1, char *cSeq2);
void printCounter(); 
void initCounter();
void printSeq(char *cSeq);
void findEditDist(char* cSeq1, char* cSeq2);
int isMatch(char cChar1, char cChar2);
int findMin(int iRow,int iCol,int iThreadNum,char *cSeq1,char *cSeq2);
void initSeq(int iLen,char *cDest);


/* Shared Variables */
shared[ ] int **iEditDist;
shared int iCounter[THREADS];
shared int iMatRowSize,iMatColSize,iError;
shared char *seqAG,*seqBG;


/* Initialization of the EditDistance Matrix */

void initEditDistance() {
	int i,j=0;
	int iRowSize,iColSize;
	iRowSize = iMatRowSize;
	iColSize = iMatColSize;

	//iEditDist = (shared [ ] int**) upc_all_alloc(1,(iMatRowSize+1)*sizeof(shared int*));
	iEditDist = (shared [ ] int**)malloc((iRowSize+1)*sizeof(shared [] int*));
	for(i=0;i<=iRowSize;i++)
		//iEditDist[i]=(shared [ ] int*) upc_all_alloc(floor(iColSize/THREADS),(iColSize+1)*sizeof(int));
		iEditDist[i]=(shared [ ] int*) upc_all_alloc(1,(iColSize+1)*sizeof(int));
	upc_forall(i=0;i<=iRowSize;i++;i)
		for(j=0;j<=iColSize;j++)
			iEditDist[i][j] = 0;
}


/* Function to print the Edit Distance Matrix */

void printEditDistance(char *cSeq1, char *cSeq2){
	int i=0,j=0,iRowSize,iColSize;
	iRowSize = iMatRowSize;
	iColSize = iMatColSize;

	printf("Matrix EditDistance is:\n");

	printf(" %3c ",' ');
	printf(" %3c ",'-');
	for(j=1;j<=iColSize;j++)
		printf(" %3c ",cSeq2[j-1]);
	printf("\n");

	for(i=0;i<=iRowSize;i++){
		if(i==0)
			printf(" %3c ",'-');
		else
			printf(" %3c ",cSeq1[i-1]);
		for(j=0;j<=iColSize;j++)
			printf(" %3d ",iEditDist[i][j]);
		printf("\n");
	}
}


/* Function to print the input sequences */

void printSeq(char *cSeq){
	printf("The Given String is = %s\n", cSeq);
}


/* Function to initialize the shared counter */

void initCounter() {
	int i=0;
	for(i=0;i<THREADS;i++)
		iCounter[i]= -1;
}


/* Function to print the shared counter */

void printCounter() {
	int i=0;
	printf("The Counter Value is :\n");
	for(i=0;i<THREADS;i++)
		printf("%d",iCounter[i]);
	printf("\n");
}


/* Function to generate a random sequence and initialize it as the
   input sequence */


void initSeq(int iLen,char *cDest) {
#if 0
/* DOB: inefficient method, relies on tiny RAND_MAX */
	int i=0,j=0,iVal=0;
	for(j=0,i=0;i<iLen;j++) {
		iVal = rand();
		if(iVal==65 || iVal==67 || iVal==71 || iVal==84){
			cDest[i]=(char)iVal;
			i++;
		}
	}
#else
/* fast method */
        static char possvals[] = { 65, 67, 71, 84 };
        int numvals = sizeof(possvals)/sizeof(char);
	for(int i=0;i<iLen;i++) {
          int idx = ((double)numvals)*rand()/(RAND_MAX+1.0);
	  cDest[i]=(char)possvals[idx];
	}
#endif
        cDest[iLen] = '\0'; 
	//printf("The Initialized sequence is =%s\n",cDest);

}


/* Function to determine if the characters of the input sequences
   match at that particular index */

int isMatch(char cChar1, char cChar2){
	int iIsMatch =0;
	/*if(cChar1 == cChar2)
		iIsMatch= iMatch;
	else iIsMatch= iMisMatch;
	//printf("Inside IsMatch; iIsMatch=%d for cChar1 = %c,cChar2 = %c\n",iIsMatch,cChar1,cChar2);*/

	iIsMatch = (cChar1 == cChar2 ? iMatch :iMisMatch);


	return iIsMatch;
}


/* Function which determines the minimum value among North, NorthWest
 * West elements of the EditDistance Matrix for the given values of 
 * Row and Column Numbers 
 */ 

int findMin(int iRow,int iCol,int iThreadNum,char *cSeq1,char *cSeq2){
	int iNorth =0, iWest =0, iNorthWest =0;
	int match =0, mismatch=1;

	//printf("Inside findMin; I am Thread %d\n",iThreadNum);
	if(iCol==0 && iRow==0)
		return 0;

	if(iCol==0 && iRow>0)
		return iEditDist[iRow-1][iCol]+iGapPen;
	if(iRow==0 && iCol>0)
		return iEditDist[iRow][iCol-1]+iGapPen;
	if(iCol>0 && iRow>0) {
		iNorth = iEditDist[iRow-1][iCol]+iGapPen;
		iWest = iEditDist[iRow][iCol-1]+iGapPen;
		iNorthWest = iEditDist[iRow-1][iCol-1]+isMatch(cSeq1[iRow-1],cSeq2[iCol-1]);
		//iNorthWest = (iEditDist[iRow-1][iCol-1])+(cSeq1[iRow-1]==cSeq2[iCol-1] ? match : mismatch);
	}
	return MIN3(iNorth,iWest,iNorthWest);
}



void findEditDist(char* cSeq1, char* cSeq2) {
	
	int i,j,iColStart,iColEnd=0,iRow=0,iRowSize,iColSize;
	iRowSize = iMatRowSize;
	iColSize = iMatColSize;
	
	iColStart=MYTHREAD*floor(((iColSize+1)/THREADS));
	if(MYTHREAD == THREADS-1){
		iColEnd=iColSize+1;
	} else {
		iColEnd=(MYTHREAD+1)*floor(((iColSize+1)/THREADS));
	}
	//printf("I am Thread %d, My Columns Range is %d to %d\n",MYTHREAD,iColStart,iColEnd); 
	//upc_barrier;
#if 0
/* DOB: this loop is incorrect because some threads exit the loop early while
 * others are still inside it performing barriers */
        for(i=0;iCounter[MYTHREAD]<iRowSize;i++){
		if(MYTHREAD <= i) { 
			iRow = i-MYTHREAD;
			for(j=iColStart;j<iColEnd;j++){
				iEditDist[iRow][j] = findMin(iRow,j,MYTHREAD,cSeq1,cSeq2);
				//printf("Computation by Thread %d\n",MYTHREAD);
				//printf("iEditDist[%d][%d] = %d\n",iRow,j,iEditDist[iRow][j]);
			}
			iCounter[MYTHREAD] = iRow;
			//printf("I am Thread %d and I finished computing Row:%d\n",MYTHREAD, iCounter[MYTHREAD]);
		}

		upc_barrier;
	}
	//printf("I am Thread %d and I finished my share\n",MYTHREAD);
	upc_barrier;
#else
        /* simpler version without the barrier problem */
        for (i = 0; i < MYTHREAD; i++) { upc_barrier; } /* prolog */
	for(iRow=0;iRow<=iRowSize;iRow++){
			for(j=iColStart;j<iColEnd;j++){
				iEditDist[iRow][j] = findMin(iRow,j,MYTHREAD,cSeq1,cSeq2);
				//printf("Computation by Thread %d\n",MYTHREAD);
			//	printf("iEditDist[%d][%d] = %d\n",iRow,j,iEditDist[iRow][j]);
			}
			//printf("I am Thread %d and I finished computing Row:%d\n",MYTHREAD, iRow);
		upc_barrier;
	}
	//printf("I am Thread %d and I finished my share\n",MYTHREAD);
        for (i = MYTHREAD; i < THREADS; i++) { upc_barrier; } /* epilog */
        upc_barrier 1234; /*  a named barrier here as a sanity check that
                             the above logic matched up all the threads correctly */
#endif
}


/* The main() method which implements the Edmiston's Algorithms */
 
int main(int argc,char** argv ) {
	int i,j=0,iColStart,iColEnd=0,iRow=0;
	char *cSeq1,*cSeq2;
	int iRowSize, iColSize;

	//upc_barrier;

	if(MYTHREAD == 0) {
		if(argc < 2){
			iError =1;
			//system("clear");
			printf("Invalid inputs\n");
			printf("Usage: upcrun a.out [seq1_length] [seq2_length]\n");
			printf("Try again.....\n");
		}
	}

	upc_barrier;

	if(iError == 1)
		exit(0);

	upc_tick_t start = upc_ticks_now();
  
        if(MYTHREAD == 0) {
                iMatRowSize = atoi(argv[1]);
                iMatColSize = atoi(argv[2]);
        }
                upc_barrier;

		iRowSize = iMatRowSize;
		iColSize = iMatColSize;
		
		printf("iRowSize=%d,iColSize= %d\n", iRowSize, iColSize);
                seqAG=(shared char*)upc_all_alloc(1,(iRowSize+1)*sizeof(char));
                seqBG=(shared char*)upc_all_alloc(1,(iColSize+1)*sizeof(char));


                cSeq1=(char*)malloc((iRowSize+1)*sizeof(char));
                cSeq2=(char*)malloc((iColSize+1)*sizeof(char));


        if(MYTHREAD == 0) {

                initSeq(iRowSize,cSeq1);
                initSeq(iColSize,cSeq2);
		initCounter();

                upc_memput(seqAG,cSeq1,iRowSize+1);
                upc_memput(seqBG,cSeq2,iColSize+1);
        }
                upc_barrier;

                upc_memget(cSeq1,seqAG,iRowSize+1);
                upc_memget(cSeq2,seqBG,iColSize+1);

                upc_barrier;
		initEditDistance();	
                //upc_barrier;


	//if(MYTHREAD == 0) {	
		//printf("strlen(cSeq1)=%d\n",strlen(cSeq1));
		//printf("strlen(cSeq2)=%d\n",strlen(cSeq2));
		//printf("Rowsize= %d,Col Size = %d\n",iMatRowSize,iMatColSize);

		//initCounter();
		//printSeq(cSeq1);
		//printSeq(cSeq2);
		//printCounter();
		//printf("The EditDistance Matrix before computation is=\n");
		//printEditDistance(cSeq1,cSeq2);
	//}

	upc_barrier;

	findEditDist(cSeq1,cSeq2);

	upc_tick_t end = upc_ticks_now();
  	printf("Time was: %d microseconds\n", (int)(upc_ticks_to_ns(end-start)/1000));
        if (!MYTHREAD) printf("done.\n");

	//printf("Thread:%d, In main() I finished my share of computation\n",MYTHREAD);
	//upc_barrier;

	//if(MYTHREAD == 0){
		//printf("The Edit Distance Matrix After Computation is=\n");
		//printEditDistance(cSeq1,cSeq2);
	//}
	//printf("I am Thread %d, I am exiting\n",MYTHREAD);

	return 0;
}


