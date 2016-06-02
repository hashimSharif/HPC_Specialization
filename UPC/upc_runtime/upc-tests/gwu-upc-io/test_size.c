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
	upc_off_t fsize;

	if(!MYTHREAD)
		printf("upcio test: size with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_WRONLY|UPC_CREATE, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;
	fsize = upc_all_fget_size(fd);
	if( fsize == -1 )
		printf("TH%2d: get_size Error\n",MYTHREAD);
	else
		printf("TH%2d: the size of file is %d\n",MYTHREAD,(int)fsize);
	upc_barrier;

	size = upc_all_fset_size(fd, 5);
	if( size == -1 )
		printf("TH%2d: set_size Error\n",MYTHREAD);

	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with size testing\n");
	free((void *)hints);
	return 0;
}
	
