/*********************************************
  UPC-IO Reference Implementation
  Synthetic perf cases
  This cases is used to test the performance
  of read/write from/to local/shared  memory
  buffers using both private and common file
  pointers
 
  For the cases using shared memory buffer,
  Both infinite and finite blocksize senarios
  are tested.

  HPCL, The George Wasnington University
  Author: Yiyi Yao
  E-mail: yyy@gwu.edu
*********************************************/
#include "upc.h"
#include "upc_io.h" 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

/* A simple performance test. The file name is taken as a 
   command-line argument. */

//#define SIZE (1048576*4)       /* read/write size per node in bytes */
#define SIZE (800000*4)       /* read/write size per node in bytes */
#if SIZE > UPC_MAX_BLOCK_SIZE
#  undef SIZE
#  define SIZE UPC_MAX_BLOCK_SIZE
#endif
#define BLOCK SIZE

shared int len;
shared char *gfilename;

double UPC_Wtime()
{
  struct timeval sampletime;
  double time;
  upc_barrier;
  gettimeofday(&sampletime, NULL);
  time=sampletime.tv_sec + (sampletime.tv_usec / 1000000.0);
  return(time);
}

int main(int argc, char **argv)
{
    int i, j, ntimes, err, flag;
    double stim, read_tim, write_tim;
    double min_read_tim, min_write_tim, read_bw, write_bw;
    upc_file_t *fh;
    struct upc_hint *hints;
    upc_flag_t sync = 0;
    char *filename;
    shared int *buf;

    ntimes=5;
/* process 0 takes the file name as a command-line argument and 
   broadcasts it to other processes */
    if (!MYTHREAD) {
	i = 1;
	while ((i < argc) && strcmp("-fname", *argv)) {
	    i++;
	    argv++;
	}
	if (i >= argc) {
	    fprintf(stderr, "\n*#  Usage: perf -fname filename\n\n");
	    upc_global_exit(-1);
	}
	argv++;
	len = strlen(*argv);
    }
    upc_barrier; /* To ensure write to len is complete */
    gfilename = (shared char *) upc_all_alloc(1,sizeof(char)*(len));
    if (!MYTHREAD)
    {
	upc_memput(gfilename, *argv, len);
	fprintf(stderr, "Access size per process = %d bytes, ntimes = %d\n", SIZE, ntimes);
    }

    upc_barrier;
    filename = (char *) malloc(sizeof(char)*(len+1));
    upc_memget(filename, gfilename, len);
    filename[len] = '\0';

    /* allocate the shared buf on each thread
       this is for shared w/r with INDIVIDUAL FP */
    buf = (shared int *) upc_global_alloc(SIZE/BLOCK,BLOCK);
    hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));

    upc_barrier;
    min_read_tim=10000000.0;
    min_write_tim=10000000.0;
    for (j=0; j<ntimes; j++) {
	fh = upc_all_fopen(filename, UPC_INDIVIDUAL_FP|UPC_CREATE | UPC_RDWR, 0, hints); 
	if( !fh )
	{
		fprintf(stderr, "TH%2d: open %s error\n", MYTHREAD, filename);
		break;
	}
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);

	upc_barrier;

	stim = UPC_Wtime();
	err = upc_all_fwrite_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	write_tim = UPC_Wtime() - stim;
	if( err == -1 )
	{
		fprintf(stderr, "TH%2d: Error in write\n", MYTHREAD);
		break;
	}
  
	upc_all_fclose(fh);

	upc_barrier;
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}

	fh = upc_all_fopen(filename, UPC_INDIVIDUAL_FP | UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);
      
	upc_barrier;
	stim = UPC_Wtime();
	err = upc_all_fread_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	read_tim = UPC_Wtime() - stim;
	if( err == -1 )
	{
		fprintf(stderr, "TH%2d: Error in read\n", MYTHREAD);
		break;
	}
  
	upc_all_fclose(fh);
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}
  
	if(min_write_tim > write_tim)
		min_write_tim = write_tim;
	if(min_read_tim > read_tim)
		min_read_tim = read_tim;
    }
    upc_barrier;
    if( !MYTHREAD )
    {
	printf("\n"); fflush(stdout);
    }
    
    if (MYTHREAD == 0) {
	read_bw = (SIZE*THREADS)/(min_read_tim*1024.0*1024.0);
	write_bw = (SIZE*THREADS)/(min_write_tim*1024.0*1024.0);
	fprintf(stderr, "(INDIVIDUAL FP) Write bandwidth without file sync = %f Mbytes/sec\n", write_bw);
	fprintf(stderr, "(INDIVIDUAL FP) Read bandwidth without prior file sync = %f Mbytes/sec\n", read_bw);
    }
    upc_barrier;

    min_write_tim=10000000.0;
    min_read_tim=10000000.0;

    flag = 0;
    for (j=0; j<ntimes; j++) {
	fh = upc_all_fopen(filename, UPC_INDIVIDUAL_FP|UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);

	upc_barrier;
	stim = UPC_Wtime();
	upc_all_fwrite_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	err = upc_all_fsync(fh);
	write_tim = UPC_Wtime() - stim;
	if (err == -1) {
	    flag = 1;
	    break;
	}
  
	upc_all_fclose(fh);
  
	upc_barrier;
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}

	fh = upc_all_fopen(filename, UPC_INDIVIDUAL_FP|UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);
      
	upc_barrier;
	stim = UPC_Wtime();
	upc_all_fread_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	read_tim = UPC_Wtime() - stim;
  
	upc_all_fclose(fh);
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}
  
	if(min_write_tim > write_tim)
		min_write_tim = write_tim;
	if(min_read_tim > read_tim)
		min_read_tim = read_tim;
    }
    upc_barrier;
    if( !MYTHREAD )
    {
	printf("\n"); fflush(stdout);
    }

    if (MYTHREAD == 0) {
	if (flag) fprintf(stderr, "upc_all_sync returns error.\n");
	else {
	    read_bw = (SIZE*THREADS)/(min_read_tim*1024.0*1024.0);
	    write_bw = (SIZE*THREADS)/(min_write_tim*1024.0*1024.0);
	    fprintf(stderr, "(INDIVIDUAL FP) Write bandwidth including file sync = %f Mbytes/sec\n", write_bw);
	    fprintf(stderr, "(INDIVIDUAL FP) Read bandwidth after file sync = %f Mbytes/sec\n", read_bw);
	}
    }

    /* each thread frees the shared buf */
    upc_free(buf);

    /* use upc_all_alloc to create a single shared buf for all threads */
    buf = (shared int *)upc_all_alloc(SIZE/BLOCK, BLOCK);

    upc_barrier;
    min_read_tim=10000000.0;
    min_write_tim=10000000.0;
    for (j=0; j<ntimes; j++) {
	fh = upc_all_fopen(filename, UPC_COMMON_FP|UPC_CREATE | UPC_RDWR, 0, hints); 
	if( !fh )
	{
		fprintf(stderr, "TH%2d: open %s error\n", MYTHREAD, filename);
		break;
	}
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);

	upc_barrier;

	stim = UPC_Wtime();
	err = upc_all_fwrite_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	write_tim = UPC_Wtime() - stim;
	if( err == -1 )
	{
		fprintf(stderr, "TH%2d: Error in write\n", MYTHREAD);
		break;
	}
  
	upc_all_fclose(fh);

	upc_barrier;
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}

	fh = upc_all_fopen(filename, UPC_COMMON_FP | UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);
      
	upc_barrier;
	stim = UPC_Wtime();
	err = upc_all_fread_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	read_tim = UPC_Wtime() - stim;
	if( err == -1 )
	{
		fprintf(stderr, "TH%2d: Error in read\n", MYTHREAD);
		break;
	}
  
	upc_all_fclose(fh);
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}
  
	if(min_write_tim > write_tim)
		min_write_tim = write_tim;
	if(min_read_tim > read_tim)
		min_read_tim = read_tim;
    }
    upc_barrier;
    if( !MYTHREAD )
    {
	printf("\n"); fflush(stdout);
    }
    
    if (MYTHREAD == 0) {
	read_bw = (SIZE*THREADS)/(min_read_tim*1024.0*1024.0);
	write_bw = (SIZE*THREADS)/(min_write_tim*1024.0*1024.0);
	fprintf(stderr, "(COMMON FP) Write bandwidth without file sync = %f Mbytes/sec\n", write_bw);
	fprintf(stderr, "(COMMON FP) Read bandwidth without prior file sync = %f Mbytes/sec\n", read_bw);
    }
    upc_barrier;

    min_write_tim=10000000.0;
    min_read_tim=10000000.0;

    flag = 0;
    for (j=0; j<ntimes; j++) {
	fh = upc_all_fopen(filename, UPC_COMMON_FP|UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);

	upc_barrier;
	stim = UPC_Wtime();
	upc_all_fwrite_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	err = upc_all_fsync(fh);
	write_tim = UPC_Wtime() - stim;
	if (err == -1) {
	    flag = 1;
	    break;
	}
  
	upc_all_fclose(fh);
  
	upc_barrier;
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}

	fh = upc_all_fopen(filename, UPC_COMMON_FP|UPC_CREATE | UPC_RDWR, 0, hints);
	upc_all_fseek(fh, MYTHREAD*SIZE, UPC_SEEK_SET);
      
	upc_barrier;
	stim = UPC_Wtime();
	upc_all_fread_shared(fh, buf, BLOCK, sizeof(unsigned char), SIZE, sync);
	read_tim = UPC_Wtime() - stim;
  
	upc_all_fclose(fh);
	if( !MYTHREAD )
	{
		printf(">"); fflush(stdout);
	}
  
	if(min_write_tim > write_tim)
		min_write_tim = write_tim;
	if(min_read_tim > read_tim)
		min_read_tim = read_tim;
    }
    upc_barrier;
    if( !MYTHREAD )
    {
	printf("\n"); fflush(stdout);
    }

    if (MYTHREAD == 0) {
	if (flag) fprintf(stderr, "upc_all_sync returns error.\n");
	else {
	    read_bw = (SIZE*THREADS)/(min_read_tim*1024.0*1024.0);
	    write_bw = (SIZE*THREADS)/(min_write_tim*1024.0*1024.0);
	    fprintf(stderr, "(COMMON FP) Write bandwidth including file sync = %f Mbytes/sec\n", write_bw);
	    fprintf(stderr, "(COMMON FP) Read bandwidth after file sync = %f Mbytes/sec\n", read_bw);
	}
    }

    upc_barrier;
    /* only thread 0 clean up the single shared buf */
    if(!MYTHREAD)
       upc_free(buf);

    free(filename);
    free((void *)hints);
    if(!MYTHREAD)
	printf("upcio test: Done\n");
    return 0;
}
