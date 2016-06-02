#include <upc.h>
#include <stdio.h>
#include <assert.h>
#define MAX_NODES_NUM 1024

/* Global queue for breadth-first search in global relabeling */
typedef struct GDS{
       upc_lock_t * lock;  //lock for this structure
        int header; //header pointer
        int tail;       //tail pointer
        int active_nodes_num; /* # of vertices currently being stored */
        int node_list[MAX_NODES_NUM];
} GDS;

shared GDS theGDS;

/* a shared pointer pointing to the shared global in-queue for BFS */
shared GDS * shared g_BFSInQueue;

/* a shared pointer pointing to the shared global out-queue for BFS */
shared GDS * shared g_BFSOutQueue;

int main() {
  int index = 2;
  int tail = 100;
  g_BFSInQueue = &theGDS;
  g_BFSInQueue->header = 1;
  g_BFSInQueue->tail = 2;
  g_BFSInQueue->active_nodes_num = 3;
  g_BFSInQueue->node_list[index-1] = tail-1;
  g_BFSInQueue->node_list[index] = tail;
  g_BFSInQueue->node_list[index+1] = tail+1;

  assert(theGDS.header == 1);
  assert(theGDS.tail == 2);
  assert(theGDS.active_nodes_num == 3);
  assert(theGDS.node_list[index-1] == tail-1);
  assert(theGDS.node_list[index] == tail);
  assert(theGDS.node_list[index+1] == tail+1);

  printf("done.\n"); 
}
