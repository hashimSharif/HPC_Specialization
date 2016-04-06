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

int main()
{
	upc_file_t *fd;
	struct upc_hint *hints;
	int size;

	if(!MYTHREAD)
		printf("upcio test: open and close with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY|UPC_CREATE, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;

	size = upc_all_fpreallocate(fd, 1000);
	if( size == -1 )
                printf("TH%2d: Prealloc Error\n",MYTHREAD);
		
	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with open and close testing\n");
	free((void *)hints);
	return 0;
}
	
