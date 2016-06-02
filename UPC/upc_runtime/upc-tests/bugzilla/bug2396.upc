#include <stdlib.h>
#include <upc_relaxed.h>
#include <stdio.h>
#include <sys/time.h>
#include <assert.h>

#define XDIM 200
#define YDIM 200
#define MAXFIELDS 10

shared double* shared buffer[MAXFIELDS];

double getmicroseconds()
{
  struct timeval tv;

  gettimeofday (&tv, NULL);
  return((double)tv.tv_sec + 1.0e-6 * ((double)tv.tv_usec));
}

typedef struct grid 
{
        shared double *arrValues[MAXFIELDS];
        double xorg, yorg, global_xorg, global_yorg;
        double spacing, nodata;
        int xdim, ydim, global_xdim, global_ydim, fields, num_nodata;
        int max_xind, max_yind, xind, yind;
} Grid;

Grid *createGridNull() 
{
        Grid *p;
        int i;

        if ((p = (Grid *) malloc(sizeof(Grid))) == NULL)
        {
#if (GR_MESSAGES >= 1)
                fprintf(stderr, "createGridNull: insufficient memory for grid allocation\n");
#endif
                return((Grid *)NULL);
        }

        p->xdim = 0;
        p->ydim = 0;
        p->xorg = 0.0;
        p->yorg = 0.0;
        p->spacing = 0.0;
        p->nodata = 0.0;
        p->fields = 0;
        p->num_nodata = 0;

        return(p);
}

int main()
{
        double start_time, finish_time;
        int i, field = 0;
        Grid *p;
        
        p = createGridNull();
        p->max_xind = XDIM;
        p->max_yind = YDIM;
        p->nodata = -1;
        start_time = getmicroseconds();
        
//      printf("ALLOCATING\n\n");
        if ((buffer[field] = upc_all_alloc(p->max_xind * p->max_yind, sizeof(double))) == NULL)
        {
                fprintf(stderr, "inGrid: memory allocation error\n");
                return(0);
        }

        finish_time = getmicroseconds();
        //printf("Thread %i Allocation time:  %e\n", MYTHREAD, finish_time - start_time);
        
        p->arrValues[field] = buffer[field];
        
        upc_barrier;
        start_time = getmicroseconds();
        upc_forall (i=0; i < (p->max_xind * p->max_yind); i++; &(p->arrValues[field][i]))
        {
                p->arrValues[field][i] = p->nodata;
                //if(i < 50) printf("T: %i  %i\n", MYTHREAD, i);
        }
        finish_time = getmicroseconds();
        
        printf("Thread %i Initialization time:  %e\n", MYTHREAD, finish_time - start_time);
        
        upc_barrier;

        
        return 0;
}
