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
	char *buffer;
	int size, i;
	struct upc_local_memvec memvec[2];
	struct upc_filevec filevec[2];
	upc_flag_t sync = 0;

	if(!MYTHREAD)
		printf("upcio test: test fread_list_local with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
	size = 10;
#ifdef BUPC_TEST_HARNESS
	buffer = (char *)calloc(size+1, sizeof(char));
#else
	buffer = (char *)malloc(sizeof(char)*size);
#endif /* BUPC_TEST_HARNESS */

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
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_RDONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;
	size = upc_all_fread_list_local(fd, 2, (struct upc_local_memvec const *)&memvec, 2, (struct upc_filevec const *)&filevec, sync);
	if( size == -1 )
                printf("TH%2d: read_list_local error \n",MYTHREAD);

	printf("TH%2d: read %s\n",MYTHREAD, buffer);
        upc_barrier;

	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with fread_local testing\n");
	free((void *)buffer);
	free((void *)hints);
	return 0;
}
	
