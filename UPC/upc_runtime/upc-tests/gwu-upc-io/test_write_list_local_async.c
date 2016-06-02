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
	char *buffer;
        ssize_t ret;
	int size, i;
	struct upc_local_memvec memvec[2];
	struct upc_filevec filevec[2];
        int flag;
        void *dummy=0;


	if(!MYTHREAD)
		printf("upcio test: test fwrite_list_local_async with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	size = 10;
	buffer = (char *)malloc(sizeof(char)*size);

	memvec[0].baseaddr = &buffer[0];
	memvec[0].len = 4;
	memvec[1].baseaddr = &buffer[6];
	memvec[1].len = 3;
	filevec[0].offset = 4*MYTHREAD;
	filevec[0].len = 3;
        filevec[1].offset = 8+4*MYTHREAD;
        filevec[1].len = 4;

	for(i=0; i<size; i++)
		buffer[i] = 'z';

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;
	upc_all_fwrite_list_local_async(fd, 2, (struct upc_local_memvec const *)&memvec, 2, (struct upc_filevec const *)&filevec, 0);

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
		printf("upcio test: Done with fwrite_list_local_async testing\n");
	free((void *)buffer);
	free((void *)hints);
	return 0;
}
	
