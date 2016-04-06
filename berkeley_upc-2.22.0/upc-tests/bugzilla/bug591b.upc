#include <stdio.h>
#include <upc_relaxed.h>

#define maxcells        1
#define MAX_CELL_DIM    103
#define IMAX    MAX_CELL_DIM
#define JMAX    MAX_CELL_DIM
#define KMAX    MAX_CELL_DIM
typedef struct U_shared u_t;
struct U_shared
{
  double local[maxcells][IMAX+4][JMAX+4][KMAX+4][5];
};
extern shared u_t *u;
extern int ncells, grid_points[3];
extern int predecessor[3], successor[3];
extern u_t *u_priv;
extern int sh_cell_size[128][maxcells][3],
  sh_cell_coord[128][maxcells][3];
shared u_t *u;
int ncells, grid_points[3];
int predecessor[3], successor[3];
u_t *u_priv;
int sh_cell_size[128][maxcells][3],
  sh_cell_coord[128][maxcells][3];

int main()
{
  int i,j,c;
  int suc0;
      
      suc0= successor[0];
      for (c = 0; c <ncells ; c++)
	{
	  if(sh_cell_coord[MYTHREAD][c][0]!=ncells)
	    {
	      for(i=0;i<2;i++)
		{
		  for(j=0;j< sh_cell_size[MYTHREAD][c][1];j++)
		    {			
		      upc_memput(&u[suc0].local[c][i][j+2][2][0],
				 &u_priv->local[c][i+sh_cell_size[MYTHREAD][c][0]][j+2][2][0],
				 sizeof(double)* 5 *(sh_cell_size[MYTHREAD][c][2]) );
		    }
		}
	    }
	}
}
