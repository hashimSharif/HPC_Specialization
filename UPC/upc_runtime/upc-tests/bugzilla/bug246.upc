#include <upc.h>

typedef shared [] double *sdblptr;
typedef shared [] int *sintptr;
typedef struct {
  sdblptr localData;       /* Local data */
  sintptr sdims;           /* Dimensions of local data */
  sintptr faceSync;        /* Synchronization points for transfers */
  sdblptr xzbuffer;        /* Buffers for transfers */
  sdblptr yzbuffer;
  sdblptr xybuffer;
  sdblptr *directory;      /* Pointers to remote data */
  sintptr *dimsdir;        /* Remote sizes */
  sintptr *facedir;        /* Remote sync points */
  sdblptr *yzdirectory;    /* Remote buffers */
  sdblptr *xzdirectory;
  sdblptr *xydirectory;
  double *G;               /* Local pointer to local data */
  double *yzcommbuffer;    /* Local pointers to buffers */
  double *xzcommbuffer;
  int *dims;               /* Local pointer to size */
  int totalSize;           /* Total number of elements (including ghosts) */
  int globallb[3];         /* What part of the grid do I have */
  int globalub[3];
  int live;                /* Am I alive at this level? */
} upc3d;

upc3d *result;

void f() {
 int *p;
 int i=1;
 p = &(result->globalub[i]);
}
