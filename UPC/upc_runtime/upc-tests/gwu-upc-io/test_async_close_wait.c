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
	ssize_t ret;
	size_t size, nmemb;
	char *buffer;
	int i;
	int flag;
	void *dummy;
	

	if(!MYTHREAD)
		printf("upcio test: test fread_local_async with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	nmemb = 1;
	size = 10;
	buffer = (char *)malloc(sizeof(char)*size*nmemb);

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_RDWR | UPC_CREATE, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_all_fseek(fd, 10*MYTHREAD, UPC_SEEK_SET);
	/* Initialize the buffer, then write */
	for(i=0; i<size; i++)
		buffer[i]= MYTHREAD + 48;
	
	upc_all_fwrite_local_async(fd, (void *)buffer, size, nmemb, 0);
        /* intentionally try to close the file without completing */
	
	if(upc_all_fclose(fd) != -1)
		printf("TH%2d, Error we succeed to close the file.\n", MYTHREAD);
	
	upc_barrier;
	ret = upc_all_fwait_async(fd);
	if( ret == -1 )
		printf("TH%2d: fwait Error\n",MYTHREAD);
	else
		printf("TH%2d: fwait returns %d\n",MYTHREAD,(int)ret);
	
		
	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with fread_local_async testing\n");
	
	
	free((void *)buffer);
	free((void *)hints);
	return 0;
}
	
