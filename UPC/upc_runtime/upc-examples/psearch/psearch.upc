/**
 *  Psearch - parallel search of unbalanced trees
 *    J. Prins UNC - Chapel Hill
 *    prins@cs.unc.edu  
 *
 *  Some node ids to verify correct operation.  Results shown in byte order.
 *    Root = 0000000000000000000000000000000000000102 (258)
 *      Child 0 = 1C76B8C34F9AE2B92AB9149766705AB8638E44D8
 *      Child 1 = 878191BB8380AA3B833672FAC0FACE7455719BB4
 *  with q = 0.375 and m = 2, child 0 is a leaf, and child 1 is not.
 */
#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
#include <sys/time.h>
#include "sha1.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

#define MAXSTACKDEPTH 20000



/***********************************************************
 *                                                         *
 *  type definitions                                       *
 *                                                         *
 ***********************************************************/

/* tree node */
struct node_t
{
  uint8  nodeid[20];  // SHA-1 hash
  int    height;
};
typedef struct node_t Node;

/* data per thread */
struct stealStack_t
{
  int workAvail;     /* if work available for stealing */
  int sharedStart;   /* index of start of shared portion of stack */
  int local;         /* index of start of local portion */
  int top;           /* index of stack top */
  int nNodes, maxDepth, nAcquire, nRelease, nSteal, nFail;  /* stats */
  upc_lock_t *stackLock;  /* lock for manipulation of shared portion */
  Node stack[MAXSTACKDEPTH]; /* stack */	
};
typedef struct stealStack_t StealStack;



/***********************************************************
 *                                                         *
 *  global parameters and variables                        *
 *                                                         *
 ***********************************************************/

/* forest parameters */
int nTrees    = 3200;
uint32 rootId = 0;

/* tree size and variation parameters
 * Galton-Watson trees with binomial distribution:
 *    non-leaf branching factor m children occurs with prob q, 
 *    leaf nodes with prob (1-q).
 * The expected number of children per node = qm must be < 1
 */
int    nonLeafBF = 4;
double nonLeafProb = 15.0 / 64.0;

/* search parameters */
int doSteal  = 1;
int chunkSize = 20;
int maxTreeDepth = MAXSTACKDEPTH;

/* execution parameters */
int debug = 0;
int verbose = 1;

/* root Node */
Node rootNode;

/***********************************************************
 *                                                         *
 *  thread shared state                                    *
 *                                                         *
 ***********************************************************/

/* tree search stack */
shared StealStack stealStack[THREADS];


/***********************************************************
 *                                                         *
 *  functions                                              *
 *                                                         *
 ***********************************************************/

/* 
 * StealStack
 *    stack with sharing at the bottom of the stack
 *    elements can be stolen from the bottom of the stack
 *
 */

/* restore stack to empty state */
void mkEmpty(StealStack *s) {
  upc_lock(s->stackLock);
  s->sharedStart = 0;
  s->local  = 0;
  s->top    = 0;
  s->workAvail = 0;
  upc_unlock(s->stackLock);
}

/* initialize the stack */
void initialize(StealStack *s) {
  s->stackLock = upc_global_lock_alloc();
  s->nNodes = 0;
  s->maxDepth = 0;
  s->nAcquire = 0;
  s->nRelease = 0;
  s->nSteal = 0;
  s->nFail = 0;
  mkEmpty(s);
}

/* fatal error */
void error(const char *str) {
  printf("*** [Thread %i] %s\n",(int)MYTHREAD, str);
  upc_global_exit(4);
}

int numChildren(Node *p);

void printnode(Node *c) {
  int i;
  printf("%4d ", c->height);
  for (i=0; i <20; i++) printf("%02x", c->nodeid[i]);
  printf(" (%d children)\n",numChildren(c));
}

/* local push */
void push(StealStack *s, Node *c) {
  if (s->top >= MAXSTACKDEPTH)
    error("StealStack::push  overflow");
  if ((debug & 1) != 0) {printf("push "); printnode(c);}
  memcpy(&s->stack[s->top], c, sizeof(Node));
  s->top++;
  s->maxDepth = max(s->top, s->maxDepth);
  }

/* local pop */
void pop(StealStack *s, Node *c) {
  if (s->top <= 0)
    error("StealStack::pop  empty local stack");
  s->top--;
  memcpy(c, &s->stack[s->top], sizeof(Node));
  if ((debug & 1) != 0) {printf("pop  "); printnode(c);}
  s->nNodes++;
  }

/* local depth */
int localDepth(StealStack *s) {
  return (s->top - s->local);
}

/* release k values from bottom of local stack */
void release(StealStack *s, int k) {
  upc_lock(s->stackLock);
  if (s->top - s->local >= k) {
    s->local += k;
    s->workAvail += k;
    s->nRelease += k / chunkSize;
  }
  else
    error("StealStack::release  do not have k vals to release");
  upc_unlock(s->stackLock);
}

/* move k values from top of shared stack into local stack
 * return false if k vals are not avail on shared stack
 */
int acquire(StealStack *s, int k) {
  int avail;
  upc_lock(s->stackLock);
  avail = s->local - s->sharedStart;
  if (avail >= k) {
    s->local -= k;
    s->workAvail -= k;
    s->nAcquire += k / chunkSize;
  }
  upc_unlock(s->stackLock);
  return (avail >= k);
}

/* steal k values from thread i onto this thread's stack
 * return false if k vals are not avail in thread i
 */
int steal(StealStack *s, int i, int k) {
  int victimLocal, victimShared, victimWorkAvail;
  int ok;

  int obsAvail = stealStack[i].workAvail;

  /* lock stack in thread i and try to reserve k elts */
  upc_lock(stealStack[i].stackLock);
  victimLocal = stealStack[i].local;
  victimShared = stealStack[i].sharedStart;
  victimWorkAvail = stealStack[i].workAvail;
  ok = victimWorkAvail >= k;
  if (ok) {
    /* reserve a chunk */
    stealStack[i].sharedStart =  victimShared + k;
    stealStack[i].workAvail = victimWorkAvail - k;
  }
  upc_unlock(stealStack[i].stackLock);

  /* if k elts reserved, move them to local portion of our stack */
  if (ok) {
    upc_memcpy(&stealStack[MYTHREAD].stack[s->top],
	       &stealStack[i].stack[victimShared],
	       k * sizeof(Node)
	       );
    s->top += k;
    s->nSteal++;
  }
  else {
    s->nFail++;
    if ((debug & 4) != 0) {
      printf("Thread %d failed to steal %d nodes from thread %d, obsAv = %d, ActAv = %d, sh = %d, loc =%d\n",
	     MYTHREAD, k, i, obsAvail, victimWorkAvail, 
	     victimShared, victimLocal);
    }
  }
  return (ok);
} 

/* search other threads for work to steal */
int findwork(int k) {
  int i,v;
  for (i = 1; i < THREADS; i++) {
    v = (MYTHREAD + i) % THREADS;
    if (stealStack[v].workAvail >= k)
      return v;
  }
  return -1;
}


/* generate the id of the child from the parent 
 * using SHA-1 cryptographic hash
 */
void genChildId(Node *child, Node *parent, uint32 childno)
{
  struct sha1_context ctx;
  uint8  bytes[4];

  bytes[0] = 0xFF & (childno >> 24);
  bytes[1] = 0xFF & (childno >> 16);
  bytes[2] = 0xFF & (childno >> 8);
  bytes[3] = 0xFF & childno;

  sha1_starts(&ctx);
  sha1_update(&ctx, &parent->nodeid[0], 20);
  sha1_update(&ctx, bytes, 4);
  sha1_finish(&ctx, &child->nodeid[0]);

  child->height = parent->height + 1;
  
  if ((debug & 2) != 0) {
    printf("genchildId parent = "); printnode(parent);
    printf("        child %3d = ",(int)childno); printnode(child);
  }
}

/* determine number of children for node p 
 */
int numChildren(Node *p)
{
  uint32 b =  (p->nodeid[16] << 24) | (p->nodeid[17] << 16)
    | (p->nodeid[18] << 8) | (p->nodeid[19] << 0);
  double d  = 4294967296.0;  /* 2^32 */
  double r  = (double) b;
  int n = ( r/d < nonLeafProb) ? nonLeafBF : 0;
  return n;
}


/* depth-first traversal of nodes in
 * this thread's stack
 */
void dfsLocal(StealStack *ss) {
  Node parent, child;
  int i, n;
  int moreWork = 0;

  do  {
    while (localDepth(ss) > 0) {

      /* explore children of node at stack top */
      pop(ss, &parent);
      n = numChildren(&parent);
      for (i = n - 1; i >= 0; i--) {
	genChildId(&child, &parent, i);
	push(ss, &child);
      }
				
      /* if sufficient work on local stack
       *  make some available for stealing
       */
      if (localDepth(ss) > 2 * chunkSize) {
	release(ss, chunkSize);
      }
    }
			
    /* local stack exhausted, try re-localizing
     * stealable work onto the local stack
     */
    moreWork = acquire(ss, chunkSize);	
  }
  while (moreWork);
	
  /* local and shared stack exhausted */
}

/* explore Forest of trees
 */
void exploreForest(StealStack *ss) {
  Node node;
  int i, rel, victimId;
  int startTreeIndex, endTreeIndex;

  /* portion of group handled by this thread */  
  int groupSize = (nTrees + THREADS - 1) / THREADS;
  startTreeIndex = MYTHREAD * groupSize;
  endTreeIndex = min(startTreeIndex + groupSize, nTrees);

  /* push trees onto DFS search stack */
  for (i = endTreeIndex -1 ; i >= startTreeIndex; i--) {
    genChildId(&node, &rootNode, i);
    push(ss, &node);
  }
    
  /*  make some chunks available for stealing, if stack is deep enough */
  rel = (localDepth(ss) - 2 * chunkSize) / chunkSize;
  if (rel > 0) {
    release(ss, rel * chunkSize);
  }
			
  /* explore trees in DFS order */
  dfsLocal(ss);
						
  /* local and shared stack are exhausted
   * now try stealing work from an unfinished thread
   */
  if (doSteal) {
    victimId = findwork(chunkSize);
    while (victimId != -1) {
      if (steal(ss, victimId, chunkSize)) {
	/* succesful steal onto local stack, now explore */
	dfsLocal(ss);
      }
      victimId = findwork(chunkSize);
    }
    
  }

  /* no stealable work observed in group
   * clean up stack and wait for other threads to finish
   */
  upc_barrier;

  /* forest fully explored */
  return;
}

double wctime(){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec + 1E-6 * tv.tv_usec);
}


void showParameters() {
  double q = nonLeafProb;
  int m = nonLeafBF;
  double es  = (1.0 / (1.0 - q * m));

  if (verbose == 0)
    return;

  printf("Psearch %d trees using %d threads\n", nTrees, THREADS);
  if (doSteal)
    printf("Work stealing chunk size = %d nodes\n",chunkSize);
  else
    printf("No load balancing.  Chunk Size = %d\n",chunkSize);
  printf("Tree parameters: rootId = %d, q = %f, m = %d, E(n) = %f, E(s) = %.2f",
	 (int)rootId, q, m, q * m, es);
  printf("\n\n");
}

void showStats(double elapsedSecs) {
  int i;
  int tnodes, trel, tacq, tsteal, tfail, mdepth = 0;

  trel = tacq = tsteal = tfail = 0;
  tnodes = 1; /* for root */
  for (i = 0; i < THREADS; i++) {
    if (verbose != 0) {
      printf("** Thread %d\n", i);
      printf("  # nodes explored    = %d\n", stealStack[i].nNodes);
      printf("  # chunks released   = %d\n", stealStack[i].nRelease);
      printf("  # chunks reacquired = %d\n", stealStack[i].nAcquire);
      printf("  # chunks stolen     = %d\n", stealStack[i].nSteal);
      printf("  # failed steals     = %d\n", stealStack[i].nFail);
      printf("  maximum stack depth = %d\n", stealStack[i].maxDepth);
      printf("\n");
    }
    tnodes += stealStack[i].nNodes;
    trel   += stealStack[i].nRelease;
    tacq   += stealStack[i].nAcquire;
    tsteal += stealStack[i].nSteal;
    tfail  += stealStack[i].nFail;
    mdepth = max(mdepth, stealStack[i].maxDepth);
  }
  if (verbose != 0) {
    printf("Total nodes = %d, average tree size = %.2f\n", tnodes, 
	   ((double) tnodes) / nTrees);
    printf("Total chunks released = %d, of which %d reacquired and %d stolen\n",
	   trel, tacq, tsteal);
    if (trel != tacq + tsteal) {
      printf("*** error! total released != total acquired + total stolen\n");
    }
    printf("Failed steals = %d, Max stack size = %d\n", tfail, mdepth);
    printf("Time = %.3f seconds, performance = %.0f nodes per second\n", 
	   elapsedSecs, (tnodes / elapsedSecs));
  }
  else /* verbose == 0 */ {
    // printf("** procs, time, nodes, steals, fails, n, q, m, r, chunksize, l-b\n");
    printf("%3d %7.3f %9d %6d %4d %d %f %d %d %d %d\n",
	   THREADS, elapsedSecs, tnodes, tsteal, tfail, 
	   nTrees, nonLeafProb, nonLeafBF, (int)rootId, chunkSize, doSteal);
  }
}


int main(int argc, char *argv[]) {
  double t1, t2;
  int i, err, v;
  StealStack * ss;

  /* parse parameters */
  i = 1; err = -1;
  while (i < argc) {
    if (argv[i][0] != '-' || strlen(argv[i]) != 2 || argc <= i+1) {
      err = i; break;
    }
    switch (argv[i][1]) {
    case 'n':
      nTrees = atoi(argv[i+1]);  break;
    case 'c':
      chunkSize = atoi(argv[i+1]); break;
    case 'd':
      debug = atoi(argv[i+1]); break;
    case 'q':
      nonLeafProb = atof(argv[i+1]); break;
    case 'm':
      nonLeafBF = atoi(argv[i+1]); break;
    case 'r':
      rootId = (uint32) atoi(argv[i+1]); break;
    case 's':
      doSteal = atoi(argv[i+1]); break;
    case 'v':
      verbose = atoi(argv[i+1]); break;
    default:
      err = i; break;
    }
    i +=2;
  }
  if (err != -1 && MYTHREAD == 0) {
    printf("unrecognized parameter %s or missing argument\n", argv[i]);
    printf("usage:  psearch <UPC switches> ((-n|-c|-d|-q|-m|-r|-s) <int>)*\n");
    upc_global_exit(4);
  }

  if (doSteal == 0)
    chunkSize = MAXSTACKDEPTH;

  /* local address of this thread's stealstack */
  ss = (StealStack *) &stealStack[MYTHREAD];

  /* initialize stacks */
  initialize(ss);

  /* set root node description */
  rootNode.height = 0;
  for (i=0; i < 16; i++) rootNode.nodeid[i] = 0;
  rootNode.nodeid[16] = 0xFF & (rootId >> 24);
  rootNode.nodeid[17] = 0xFF & (rootId >> 16);
  rootNode.nodeid[18] = 0xFF & (rootId >> 8);
  rootNode.nodeid[19] = 0xFF & (rootId >> 0);

  /* report parameters */
  if (MYTHREAD == 0) showParameters();
  upc_barrier;
  
  /* explore forest */
  t1 = wctime();
  exploreForest(ss);
  t2 = wctime();
		
  /* report performance */
  if (MYTHREAD == 0) showStats(t2 - t1);

  return 0;
  /* end */
}
