/*********************************************
  UPC-IO Reference Implementation         
  Internal test cases

  HPCL, The George Wasnington University
  Author: Yiyi Yao
  E-mail: yyy@gwu.edu
*********************************************/
#include <upc.h>
#include <upc_io.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	upc_file_t *fd;
	struct upc_hint *hints;
	ssize_t ret_size;
	size_t size, nmemb;
	upc_flag_t sync = 0;
	char *buffer;
	int i;

	if(!MYTHREAD)
		printf("upcio test: test fwrite_local with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	nmemb = 1;
	size = 10*(MYTHREAD+1);
	buffer = (char *)malloc(sizeof(char)*size*nmemb);

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	for(i=0; i<size; i++)
	{
		if(MYTHREAD)
			buffer[i] = '5';
		else
			buffer[i] = '0';
	}
	upc_barrier;

#ifdef BUPC_TEST_HARNESS
	/* The barriers in the original code violate the collective constraint */
	size = upc_all_fwrite_local(fd, (void *)buffer, size, nmemb, sync);
#else
	for(i=THREADS-1; i>=0; i--)
	{
		if(MYTHREAD==i)
			size = upc_all_fwrite_local(fd, (void *)buffer, size, nmemb, sync);
		upc_barrier;
	}
#endif
	if( size == -1 )
		printf("upcio test: fwrite_local error on TH%2d\n",MYTHREAD);
	
	upc_barrier;
	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with fwrite_local testing\n");
	free((void *)buffer);
	free((void *)hints);
	return 0;
}
	
