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
	int i;
	void *dummy=0;
	shared [] char *buffer;

	if(!MYTHREAD)
		printf("upcio test: test fwrite_shared with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	nmemb = 1;
	blocksize = 0;
	size = 10;
#ifdef __UPC_VERSION__ // UPC version 1.1 or higher
	buffer = (shared [] char *)upc_alloc(sizeof(char)*size*nmemb);
#else   
	buffer = (shared [] char *)upc_local_alloc(1,sizeof(char)*size*nmemb);
#endif

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_COMMON_FP|UPC_WRONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}
        upc_barrier;

	if( MYTHREAD == 0 )
	{
		printf("TH%2d: size is %d\n",MYTHREAD, (int)size);
        	for(i=0; i<size; i++)
                        buffer[i] = '0';
        }
        upc_barrier;

	if( upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, dummy) )
		printf("TH%2d has an outstanding ASYNC OP\n",MYTHREAD);
	else
		printf("TH%2d does not has outstanding ASYNC OPs\n",MYTHREAD);
	upc_barrier;

	size = upc_all_fwrite_shared(fd, (shared void *)buffer, blocksize, size, nmemb, sync);
        printf("TH%2d: return size is %d\n", MYTHREAD, (int)size);
	if( size == -1 )
		printf("upcio test: fwrite_shared error on TH%2d\n",MYTHREAD);
	
	upc_barrier;
	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with fwrite_shared testing\n");
	upc_free(buffer);
	free((void *)hints);
	return 0;
}
	
