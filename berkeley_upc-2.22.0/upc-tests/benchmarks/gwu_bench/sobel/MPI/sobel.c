/*
 * MPI-based Sobel Edge Detection
 * Copyright (C) 2000 Chen Jianxun, Sebastien Chauvin, Tarek El-Ghazawi
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/* Sobel edge detection on a random bitmap using MPI.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

/* ITERATION_NUM: number of iterations of the Sobel Edge Detections. Running
 * the algorithm several times allows to get a more accurate execution time.
 */
#define ITERATION_NUM 15.0

#define BYTET unsigned char

BYTET verbose=0;

#ifndef DYNAMIC

#ifndef IMGSIZE
# error "IMGSIZE undefined."
#else
# define pic_size IMGSIZE
#endif

BYTET orig[pic_size][pic_size], edge[pic_size][pic_size];
BYTET Temp[pic_size][pic_size];

#else
/* Dynamic memory allocation */

long pic_size=0;
BYTET** orig;
BYTET** Temp;
BYTET** edge;

#endif

void Genrandom(void);
void MPI_Sobel();

int rank, threads_num;

int main(int argc, char** argv)
{ 
  long i;
  clock_t itime;
  double ftime;
#ifdef DYNAMIC
  int p ;
  MPI_Status status;
#endif

  setbuf(stdout,NULL);

/*  if (argc > 2)
  { fprintf(stderr, "sobel: Too many arguments.\n");
    fprintf(stderr, "sobel: usage: sobel [-q]\n");
    return 1;
  }*/

#ifdef DEBUG
  for(i=0; i<argc; i++) printf("argv[%d]=%s\n", i, argv[i]);
#endif

  i=1;
#ifdef DYNAMIC
  while((!pic_size) && (i<argc))
#else
  while (i<argc)
#endif
  { if (!strncmp(argv[i], "-v", 2)) verbose=1;	/* `verbose' option */
#ifdef DYNAMIC
    else pic_size = atol(argv[i]);
#endif
    i++;
  }

  if (!pic_size)
  { fprintf(stderr, "Bad picture size (%d).\n", pic_size);
    exit(1);
  }

#ifdef DYNAMIC
  orig = (BYTET**)malloc(pic_size*sizeof(BYTET*));
  Temp = (BYTET**)malloc(pic_size*sizeof(BYTET*));
  edge = (BYTET**)malloc(pic_size*sizeof(BYTET*));
  for (i=0; i<pic_size; i++)
  { orig[i] = (BYTET*)malloc(pic_size*sizeof(BYTET));
    Temp[i] = (BYTET*)malloc(pic_size*sizeof(BYTET));
    edge[i] = (BYTET*)malloc(pic_size*sizeof(BYTET));
  }
#endif

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &threads_num);

  MPI_Barrier(MPI_COMM_WORLD);

#ifdef DYNAMIC
/*  if (!rank) MPI_Bcast(&pic_size, 1, MPI_LONG, 0, MPI_COMM_WORLD); */
  if (!rank)
  	for(p = 1; p < threads_num; p++)
		MPI_Send(&pic_size, 1, MPI_LONG, p, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);

  if(rank) MPI_Recv(&pic_size, 1, MPI_LONG, 0, -1, MPI_COMM_WORLD, &status);
#ifdef DEBUG
  printf("#%d: PictureSize/ThreadNumber=%d/%d\n", rank, pic_size, threads_num);
#endif
  MPI_Barrier(MPI_COMM_WORLD);
#endif

  if (pic_size%threads_num!=0){
    fprintf(stderr, "#%d: pic_size (%d) should be multiple of threads_num (%d).\n",
            rank, pic_size, threads_num);
    MPI_Finalize();
    exit(1);
  }

  if (!rank) Genrandom();

  MPI_Barrier(MPI_COMM_WORLD);
  if (rank==0) clock();
  for (i=0; i<ITERATION_NUM; i++) 
    MPI_Sobel();  

  MPI_Barrier(MPI_COMM_WORLD);

  if (rank==0) {
    itime=clock();
    ftime=(itime*1.0)/(ITERATION_NUM*1.0*CLOCKS_PER_SEC);
    if (verbose)
      printf("PictureSize=%d Processors=%d RunTime=%12.6f\n\n",pic_size,threads_num,ftime);
    else
      printf(" %f\n", ftime);
  }

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  exit(0);
}

void MPI_Sobel(void)
{
  int i,j,d1,d2;
  int line;
  double magnitude;

  BYTET *p0, *p1;
  BYTET Localrow0[pic_size];
  BYTET Localrow1[pic_size];
  
  MPI_Status status;

  
  line=pic_size/threads_num; 

  if (rank>0)
    MPI_Send(orig,pic_size,MPI_BYTE,rank-1,1,MPI_COMM_WORLD);

  if (rank<threads_num-1)
    MPI_Recv(Localrow0,pic_size,MPI_BYTE,rank+1,1,MPI_COMM_WORLD,&status);

  if (rank<threads_num-1)
    MPI_Send(orig[pic_size-1],pic_size,MPI_BYTE,rank+1,0,MPI_COMM_WORLD);

  if (rank>0)
    MPI_Recv(Localrow1,pic_size,MPI_BYTE,rank-1,0,MPI_COMM_WORLD,&status);

  /* Below : why should it be 'line-1' and 'pic_size-1' ?!
   */
    for (i=1; i<line-1; i++) {
      if (i!=0) p0=orig[i-1]; else p0=Localrow0;
      if (i!=line-1) p1=orig[i+1]; else p1=Localrow1;
      for(j=1; j<pic_size-1; j++) {
        d1=(int)        p0[j+1]-     p0[j-1];
        d1+=((int) orig[i][j+1]-orig[i][j-1])<<1;
        d1+=(int)       p1[j+1]-     p1[j-1];

        d2 = (int) orig[i-1][j-1] - orig[i+1][j-1];
        d2+=((int) orig[i-1][j]   - orig[i+1][j]  )<<1;
        d2+= (int) orig[i-1][j+1] - orig[i+1][j+1];
 
        magnitude=sqrt(d1*d1+d2*d2);
        edge[i][j]=magnitude>255? 255:(BYTET)magnitude;
      }
    }
  MPI_Barrier(MPI_COMM_WORLD);
}

void Genrandom(void)
{
  int i,j;

  for (i=0; i<pic_size; i++)
    for (j=0; j<pic_size; j++)
      orig[i][j]=(BYTET)random();
}
