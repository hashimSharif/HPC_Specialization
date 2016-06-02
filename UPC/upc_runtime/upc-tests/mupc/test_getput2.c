/* _test_getput2.c: gets and puts with interleaved data types. (X)

	Date created    : August 28, 2002
        Date modified   : November 3, 2002

	Function tested: UPCRTS_GetBytes, UPCRTS_GetSyncInteger, UPCRTS_GetSyncFloat, UPCRTS_GetSyncDouble,             
                         UPCRTS_GetLongDouble, UPCRTS_PutInteger, UPCRTS_PutFloat, UPCRTS_PutDouble,                    
                         UPCRTS_PutLongDouble

        Description:
        - Test gets and puts with interleaved data types. Data types currently supported by MuPC 
	  include char, short, integer, long, float, and double. Long double has not been implemented.
	- Each thread initializes the portion of the 6 arrays that they have affinity to concurrently
	  (each array for each data type).
	- Each element in the 6 arrays gets updated.
	- Thread 0 performs error checking at end.

        Platform Tested         No. Proc        Date Tested             Success
        UPC0                    1               August 29, 2002         No 
	UPC0			1-4		August 29, 2002		Yes (w/ longdouble commented out)
	UPC0			1-16		October 9, 2002		Yes        
	UPC0			2,4,8		October 28, 2002	Yes
	CSE0			2,4,8,16	November 7, 2002	Yes
	LION 			2,4,8,16,32	November 18, 2002	Yes
	UPC0 			2		December 3, 2002	Yes

	Bugs Found:
        [08/28/2002] Compilation of test case failed, following functions cannot be resolved:
			  _UPCRTS_GetSyncLongDouble
			  _UPCRTS_PutLongDouble
	Notes:
	[10/28/2002] 1) Since this test case involves all data types, it won't be compatible with the
		        rtype.sh script.		   
		     2) Also, keep in mind the range of data types when choosing the SIZE. For instance,
			"short" has a size of 2 bytes. Thus, if SIZE exceeds the largest number that
			"short" can hold, this test case would probably fail.
*/

#include <upc.h>
#include <stdio.h>

//#define VERBOSE0 
#define SIZE (THREADS * 5000)

shared char		CharData[SIZE];
shared short		ShortData[SIZE];
shared int 		IntData[SIZE];
shared long		LongData[SIZE];
shared float 		FloatData[SIZE];
shared double 		DoubleData[SIZE];
#if TEST_LONG_DOUBLE
shared long double 	LdoubleData[SIZE];
#endif

int main (void) {
	
	int errorNum=0;	
	char c = 'A';
	short s = 1;
	int i, iNum = 1;
	long l = 1L;
	float f = 1.0f;
        double d = 1.0;
#if TEST_LONG_DOUBLE
	long double longd = 1.0L;
#endif

	/* Generate a base number for integer, double, and long double */
       	for (i = 0; i < (sizeof(double)*8)-10; ++i) 
		d = d * 2.0;
#ifdef VERBOSE0
       	printf("double num = %f\n", d);
#endif

	for (i = 0; i < (sizeof(int)*8)-2; ++i)
		iNum = iNum * 2;
#ifdef VERBOSE0
	printf("integer num = %d\n", iNum);
#endif

#if TEST_LONG_DOUBLE
	for (i = 0; i < (sizeof(long double)*8)-2; ++i) {
		longd = longd * 2.0L;
		printf("longd i = %d, longd  = %Lf\n", i, longd);
	}
#ifdef VERBOSE0
	printf("long double num = %Lf\n", longd);
#endif
#endif

	upc_barrier;
	
	/* Initialize the 6 shared arrays */
	upc_forall(i = 0; i < SIZE; i++; &IntData[i]) {
		CharData[i] = c;
		ShortData[i] = s + i;
		IntData[i] = iNum + i;
		LongData[i] = l + (i * 1000); 
		FloatData[i] = f + (i * 1.0f);
		DoubleData[i] = d + (i * 10000.0);
#if TEST_LONG_DOUBLE
		LdoubleData[i] = longd + (i * 10000.0L);
#endif
	}
	
#ifdef VERBOSE0
	upc_barrier;
	/* Print the elements in the array */
	if (MYTHREAD == 0) {
	
		for (i = 0; i < SIZE; i++)
			printf("CharData[%d] = %c\n", i, CharData[i]);
	
		for (i = 0; i < SIZE; i++)
			printf("ShortData[%d] = %d\n", i, ShortData[i]);
		
		for (i = 0; i < SIZE; i++) 
			printf("IntData[%d] = %d\n", i, IntData[i]);
	
		for (i = 0; i < SIZE; i++)
			printf("LongData[%d] = %d\n", i, LongData[i]);
	
		for (i = 0; i < SIZE; i++)
			printf("FloatData[%d] = %f\n", i, FloatData[i]);

		for (i = 0; i < SIZE; i++)
			printf("DoubleData[%d] = %f\n", i, DoubleData[i]);

/*		for (i = 0; i < SIZE; i++)
			printf("LdoubleData[%d] = %Lf\n", i, LdoubleData[i]);
*/	
	}
#endif
	upc_barrier;

	/* Update the values of the 4 shared arrays */
	upc_forall(i = 0; i < SIZE; i++; &IntData[i]) {
		CharData[i] = CharData[i] + 1;	
		ShortData[i] = ShortData[i] + 1;
		IntData[i] = IntData[i] + 1;
		LongData[i] = LongData[i] + 1000;
		FloatData[i] = FloatData[i] + 1.0f;
		DoubleData[i] = DoubleData[i] + 10000.0;
		/* LdoubleData[i] = LdoubleData[i] + 10000.0L; */
	} 

	upc_barrier;

#ifdef VERBOSE0
	/* Print the elements in the array */
        if (MYTHREAD == 0) {
        
		for (i = 0; i < SIZE; i++)
			printf("(update) CharData[%d] = %c\n", i, CharData[i]);

		for (i = 0; i < SIZE; i++)
			printf("(update) ShortData[%d] = %d\n", i, ShortData[i]);

                for (i = 0; i < SIZE; i++)
                        printf("(update) IntData[%d] = %d\n", i, IntData[i]);
        
		for (i = 0; i < SIZE; i++)
			printf("(update) LongData[%d] = %ld\n", i, LongData[i]);

                for (i = 0; i < SIZE; i++)
                        printf("(update) FloatData[%d] = %f\n", i, FloatData[i]);

                for (i = 0; i < SIZE; i++)
                        printf("(update) DoubleData[%d] = %f\n", i, DoubleData[i]);

/*              for (i = 0; i < SIZE; i++)
                        printf("(update) LdoubleData[%d] = %Lf\n", i, LdoubleData[i]);
*/      
        }
#endif

	if (MYTHREAD == 0) {
	
		for (i = 0; i < SIZE; i++) {
			
			if (CharData[i] != (c + 1)) {
				errorNum = 1; break;
			}

			if (ShortData[i] != (short)(s + i + 1)) {
				errorNum = 2; break;
			}

			if (IntData[i] != (iNum + i + 1)) {
				errorNum = 3; break;
			}	
	
			if (LongData[i] != (l + (i * 1000) + 1000)) {
				errorNum = 4; break;
			}
	
			if (FloatData[i] != (f + (i * 1.0f) + 1.0f)) {
				errorNum = 5; break;
			}

			if (DoubleData[i] != (d + (i * 10000.0) + 10000.0)) {
				errorNum = 6; break;
			}

#if TEST_LONG_DOUBLE
			if (LdoubleData[i] != (longd + (i * 10000.0L) + 10000.0L)) {
				errorNum = 7; break;
			}
#endif
		}

		if (errorNum)
			printf("Error: test_getput2.c failed! [th=%d, errorNum=%d]\n", THREADS, errorNum);
		else
			printf("Success: test_getput2.c passed! [th=%d, errorNum=%d]\n", THREADS, errorNum);		
	}
 return 0;

}

