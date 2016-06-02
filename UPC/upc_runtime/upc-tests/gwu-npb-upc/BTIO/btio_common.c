#include <stdio.h>
#include <upc.h>
#include "functions.h"

void clear_timestep()
{
	int cio, kio, jio, ix;

	for(cio=0; cio<ncells; cio++)
	{
	  for(kio=0; kio<cell_size[cio][2]; kio++)
	  {
	    for(jio=0; jio<cell_size[cio][1]; jio++)
	    {
	      for(ix=0; ix<cell_size[cio][0]; ix++)
	      {
		 u_priv_d(cio, kio+2, jio+2, ix+2, 0) = 0;
		 u_priv_d(cio, kio+2, jio+2, ix+2, 0) = 0;
		 u_priv_d(cio, kio+2, jio+2, ix+2, 0) = 0;
		 u_priv_d(cio, kio+2, jio+2, ix+2, 0) = 0;
		 u_priv_d(cio, kio+2, jio+2, ix+2, 0) = 0;
	      }
            }
          }
	}

	return;
}
