#include <stdio.h>
#include "functions.h"

upc_file_t *fd;
void setup_btio()
{
	upc_barrier;
	const char *filenm = "btio_simple.out";
#ifdef BUPC_TEST_HARNESS
	const char *envval;
	if (NULL != (envval = getenv("BTIO_OUTPUT")))
	{
		filenm = envval;
	}
#endif

	fd = upc_all_fopen(filenm, UPC_INDIVIDUAL_FP|UPC_WRONLY|UPC_CREATE, 0, NULL);

	if(!fd)
	{
		printf("Error opening output file\n");
		upc_global_exit(-1);
	}

	return;
}

void output_timestep()
{
	int count, jio, kio, cio, iio;
	int iseek;
	upc_off_t offset;

	for(cio=0; cio<ncells; cio++)
	{
	  for(kio=0; kio<=cell_size[cio][2]-1; kio++)
	  {
	    for(jio=0; jio<=cell_size[cio][1]-1; jio++)
	    {
                  iseek=5*(cell_low[cio][0] +
                        PROBLEM_SIZE*((cell_low[cio][1]+jio) +
                        PROBLEM_SIZE*((cell_low[cio][2]+kio) +
                        PROBLEM_SIZE*idump)));
		for(iio=2; iio<=cell_size[cio][0]+1;iio++)
		{
		  offset = upc_all_fseek(fd, iseek, UPC_SEEK_SET);
                  if (offset == -1)
		  {
		     printf("Error seeking to correct position in file\n");
		     upc_global_exit(-1);
		  }
		  offset = upc_all_fwrite_local(fd, &u_priv_d(cio,kio+2,jio+2,iio,0),
						5, sizeof(double), 0);
                  if (offset == -1)
		  {
		     printf("Error writing to file\n");
		     upc_global_exit(-1);
		  }
		  iseek+=5;
		}
            }
	  }
	}

	return;
}

void btio_cleanup()
{
	if(upc_all_fclose(fd)==-1)
	{
	  printf("Error closing file\n");
	  upc_global_exit(-1);
	}

	return;
}

void accumulate_norms(double * xce_acc)
{
	int count, jio, kio, cio, m, iio;
	//double xce_acc[5], xce_single[5];
	double xce_single[5];
	int ii;
	int iseek;
	upc_off_t offset;
	const char *filenm = "btio_simple.out";
#ifdef BUPC_TEST_HARNESS
	const char *envval;
	if (NULL != (envval = getenv("BTIO_OUTPUT")))
	{
		filenm = envval;
	}
#endif

	fd = upc_all_fopen(filenm, UPC_INDIVIDUAL_FP|UPC_RDONLY, 0, NULL);
	if(fd==NULL)
	{
	  printf("Error opening file\n");
	  upc_global_exit(-1);
	}

	//clear the last time step

	clear_timestep();

	//read back the time steps and accumulate norms

	for(m=0; m<5; m++)
	{
          xce_acc[m] = 0;
	}

	for(ii=0; ii<idump; ii++)
	{
	  for(cio=0; cio<ncells; cio++)
	  {
	    for(kio=0; kio<cell_size[cio][2]; kio++)
	    {
	      for(jio=0; jio<cell_size[cio][1]; jio++)
              {
                  iseek=5*(cell_low[cio][0] +
                        PROBLEM_SIZE*((cell_low[cio][1]+jio) +
                        PROBLEM_SIZE*((cell_low[cio][2]+kio) +
                        PROBLEM_SIZE*ii)));
		for(iio=2;iio<=cell_size[cio][0]+1;iio++)
		{
		  offset = upc_all_fseek(fd, iseek, UPC_SEEK_SET);
		  if(offset == -1)
		  {
		    printf("Error seeking to right position in file\n");
		    upc_global_exit(-1);
		  }
		  offset = upc_all_fread_local(fd, &u_priv_d(cio,kio+2,jio+2,iio,0),
					       5, sizeof(double), 0);
		  if(offset == -1)
		  {
		    printf("Error writing to :file\n");
		    upc_all_fclose(fd);
		    upc_global_exit(-1);
		  }
		  iseek+=5;
		}
	      }
	    }
	  }

	  if(MYTHREAD == 0)
  	    printf("Reading data set %d\n", ii+1);

          error_norm(xce_single);

	  for(m=0; m<5; m++)
            xce_acc[m] = xce_acc[m] + xce_single[m];
	}

	for(m=0; m<5; m++)
          xce_acc[m] = xce_acc[m] / idump;

	upc_all_fclose(fd);

	return;
}

