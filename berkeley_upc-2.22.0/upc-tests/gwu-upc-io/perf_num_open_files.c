/*********************************************
  UPC-IO Reference Implementation         
  Synthetic perf cases
  This test is to stress test the number of 
  opened file this I/O system can handle at
  a single time

  HPCL, The George Wasnington University
  Author: Yiyi Yao
  E-mail: yyy@gwu.edu
*********************************************/
#include <upc.h>
#include <upc_io.h>
#include <stdio.h>
#define NUM 100

int main()
{
	upc_file_t *fd[NUM];
	struct upc_hint *hints;
	int i, j;

	if(!MYTHREAD)
		printf("upcio perf: test # of opened files with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));

	for(i=0; i<NUM; i++)
	{
		upc_barrier;
		fd[i]=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY|UPC_CREATE, 0, hints);
		if(fd[i]==NULL)
		{
			printf("TH%2d: Fail to open %d/%d file\n",MYTHREAD, i, NUM);
			printf("TH%2d: Closing up all the opened file and exit\n", MYTHREAD);
			for(j=0; j<i; j++)
			{
				if(upc_all_fclose(fd[j])!=0)
				{
                			printf("TH%2d: Double errors!! Fail to close %d/%d file\n",MYTHREAD, j, i);
                			upc_global_exit(-1);
				}
			}
			upc_global_exit(-1);
		}
	}

	for(j=0; j<NUM; j++)
	{
		upc_barrier;
		if(upc_all_fclose(fd[j])!=0)
		{
                	printf("TH%2d: Fail to close %d/%d file\n",MYTHREAD, j, NUM);
                	upc_global_exit(-1);
		}
	}

	if(!MYTHREAD)
		printf("upcio test: Done with testing # of opened files\n");
	free((void *)hints);
	return 0;
}
	
