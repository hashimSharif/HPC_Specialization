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
	void *dummy=0;

	if(!MYTHREAD)
		printf("upcio test: test fwrite_local_async with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	nmemb = 1;
	size = 10*(MYTHREAD+1);
	buffer = (char *)malloc(sizeof(char)*(size+1)*nmemb);

	for(i=0; i<size; i++)
		buffer[i]='1';
	buffer[size]='\0';

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;
	upc_all_fwrite_local_async(fd, (void *)buffer, size, nmemb, 0);
	
        if( upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, dummy) )
                printf("TH%2d has an outstanding ASYNC OP\n",MYTHREAD);
        else
                printf("TH%2d does not has outstanding ASYNC OPs\n",MYTHREAD);
        upc_barrier;

	ret = upc_all_ftest_async(fd, &flag);
	if( ret == -1 )
                printf("TH%2d: ftest Error\n",MYTHREAD);
	else
	{
		if( flag )
		{
			printf("TH%2d: Async op done\n",MYTHREAD);
			printf("TH%2d: Async return %d\n",MYTHREAD,(int)ret);
		}
		else
			printf("TH%2d: Async pending\n",MYTHREAD);
	}
	
      if (!flag) {
	ret = upc_all_fwait_async(fd);
        if( ret == -1 )
                printf("TH%2d: fwait Error\n",MYTHREAD);
	else
		printf("TH%2d: fwait returns %d\n",MYTHREAD,(int)ret);
      }

	upc_barrier;

        if( upc_all_fcntl(fd, UPC_ASYNC_OUTSTANDING, dummy) )
                printf("TH%2d has an outstanding ASYNC OP\n",MYTHREAD);
        else
                printf("TH%2d does not has outstanding ASYNC OPs\n",MYTHREAD);

        upc_barrier;

	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with fwrite_local_async testing\n");
	free((void *)buffer);
	free((void *)hints);
	return 0;
}
	
