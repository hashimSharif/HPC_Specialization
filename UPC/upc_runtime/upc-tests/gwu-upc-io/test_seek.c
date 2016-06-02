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
		printf("upcio test: seek with %d Threads\n", THREADS);
	hints=(struct upc_hint *)malloc(sizeof(struct upc_hint));
        nmemb = 1;
        size = 10*(MYTHREAD+1);
#ifdef BUPC_TEST_HARNESS
        buffer = (char *)calloc(size*nmemb+1, sizeof(char));
#else
        buffer = (char *)malloc(sizeof(char)*size*nmemb);
#endif /* BUPC_TEST_HARNESS */

	upc_barrier;
	fd=upc_all_fopen("upcio.test", UPC_INDIVIDUAL_FP|UPC_RDONLY, 0, hints);
	if(fd==NULL)
	{
		printf("TH%2d: File open Error\n",MYTHREAD);
		upc_global_exit(-1);
	}

	upc_barrier;
	upc_all_fseek(fd, 5+(MYTHREAD+1)*5, UPC_SEEK_SET);
	size = upc_all_fread_local(fd, (void *)buffer, size, nmemb, sync);
        if( size == -1 )
                printf("upcio test: fread_local error on TH%2d\n",MYTHREAD);
        else
        {
                for(i=0; i<THREADS; i++)
                {
                        if(MYTHREAD==i)
                                printf("upcio test: read \"%s\" on TH%2d\n",buffer,MYTHREAD);
                        upc_barrier;
                }
        }

	if(upc_all_fclose(fd)!=0)
	{
                printf("TH%2d: File close Error\n",MYTHREAD);
                upc_global_exit(-1);
	}

	if(!MYTHREAD)
		printf("upcio test: Done with seek testing\n");
	free((void *)hints);
	return 0;
}
	
