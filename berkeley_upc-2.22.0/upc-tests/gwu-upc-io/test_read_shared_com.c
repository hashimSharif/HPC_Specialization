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
	size_t size, nmemb, blocksize;
	upc_flag_t sync = 0;
	shared [] char *buffer;
	int i;

	if(!MYTHREAD)
		printf("upcio test: test fread_shared with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	nmemb = 1;
	blocksize = 0;
	size = 30;
	buffer = (shared [] char *)upc_all_alloc(1,sizeof(char)*size*nmemb);

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_COMMON_FP|UPC_RDONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	size = upc_all_fread_shared(fd, (shared void *)buffer, blocksize, size, nmemb, sync);
	if( size == -1 )
		printf("upcio test: fread_shared error on TH%2d\n",MYTHREAD);
	else
	{
		if(!MYTHREAD)
			printf("upcio test: read \"%s\" on all threads\n",(char *)buffer);
	}
	
	upc_barrier;
	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
	{
		printf("upcio test: Done with fread_shared testing\n");
		upc_free(buffer);
	}
	free((void *)hints);
	return 0;
}
	
