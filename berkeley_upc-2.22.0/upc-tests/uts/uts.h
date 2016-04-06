/*
 *         ---- The Unbalanced Tree Search (UTS) Benchmark ----
 *  
 *  Copyright (c) 2010 See AUTHORS file for copyright holders
 *
 *  This file is part of the unbalanced tree search benchmark.  This
 *  project is licensed under the MIT Open Source license.  See the LICENSE
 *  file for copyright and licensing information.
 *
 *  UTS is a collaborative project between researchers at the University of
 *  Maryland, the University of North Carolina at Chapel Hill, and the Ohio
 *  State University.  See AUTHORS file for more information.
 *
 */

#ifndef _UTS_H
#define _UTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "rng/rng.h"

#define UTS_VERSION "2.1"

#if defined(BUPC_TEST_HARNESS)
  #if defined(__BERKELEY_UPC__) && defined(__BERKELEY_UPC_PTHREADS__)
    // Work-around BUPC bug 3038 - TLD failure for variable declared in C-mode header.
    // Needed to get proper TLD treatment for 'type' (and probably others) w/ pthreads.
    #pragma upc upc_code
  #elif defined(__clang_upc__) && defined(__BERKELEY_UPC_PTHREADS__)
    #pragma upc upc_code
  #elif defined(__GCC_UPC__) && defined(__UPC_PTHREADS_MODEL_TLS__)
    // Work-around for extern-vs-TLS issues, similar to above
    #pragma upc upc_code
  #endif
  #if defined(__CYGWIN__)
    // Work around collison between "FIXED" and w32api headers
    #define FIXED MY_FIXED
  #endif
#endif

/***********************************************************
 *  Tree node descriptor and statistics                    *
 ***********************************************************/

#define MAXNUMCHILDREN    100  // cap on children (BIN root is exempt)

struct node_t {
  int type;          // distribution governing number of children
  int height;        // depth of this node in the tree
  int numChildren;   // number of children, -1 => not yet determined
  
  /* for statistics (if configured via UTS_STAT) */
#ifdef UTS_STAT
  struct node_t *pp;          // parent pointer
  int sizeChildren;           // sum of children sizes
  int maxSizeChildren;        // max of children sizes
  int ind;
  int size[MAXNUMCHILDREN];   // children sizes
  double unb[MAXNUMCHILDREN]; // imbalance of each child 0 <= unb_i <= 1
#endif

  /* for RNG state associated with this node */
  struct state_t state;
};

typedef struct node_t Node;

/* Tree type
 *   Trees are generated using a Galton-Watson process, in 
 *   which the branching factor of each node is a random 
 *   variable.
 *   
 *   The random variable can follow a binomial distribution
 *   or a geometric distribution.  Hybrid tree are
 *   generated with geometric distributions near the
 *   root and binomial distributions towards the leaves.
 */
enum   uts_trees_e    { BIN = 0, GEO, HYBRID, BALANCED };
enum   uts_geoshape_e { LINEAR = 0, EXPDEC, CYCLIC, FIXED };

#ifdef BUPC_TEST_HARNESS
#if defined(__BERKELEY_UPC__) && \
    (PLATFORM_COMPILER_SUN || PLATFORM_COMPILER_XLC || PLATFORM_COMPILER_SGI)
// Work around BUPC bug 3036 which is only problematic w/ Sun, IBM and SGI C compilers
typedef unsigned int tree_t;
typedef unsigned int geoshape_t;
#else
typedef enum uts_trees_e    tree_t;
typedef enum uts_geoshape_e geoshape_t;
#endif
#else
typedef enum uts_trees_e    tree_t;
typedef enum uts_geoshape_e geoshape_t;
#endif

/* Strings for the above enums */
#ifdef BUPC_TEST_HARNESS
extern const char * uts_trees_str[];
extern const char * uts_geoshapes_str[];
#else
extern char * uts_trees_str[];
extern char * uts_geoshapes_str[];
#endif


/* Tree  parameters */
extern tree_t     type;
extern double     b_0;
extern int        rootId;
extern int        nonLeafBF;
extern double     nonLeafProb;
extern int        gen_mx;
extern geoshape_t shape_fn;
extern double     shiftDepth;         

/* Benchmark parameters */
extern int    computeGranularity;
extern int    debug;
extern int    verbose;

/* For stats generation: */
typedef unsigned long long counter_t;

/* Utility Functions */
#if !defined(BUPC_TEST_HARNESS) || !defined(max)
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#if !defined(BUPC_TEST_HARNESS) || !defined(min)
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifdef BUPC_TEST_HARNESS
void   uts_error(const char *str);
#else
void   uts_error(char *str);
#endif
void   uts_parseParams(int argc, char **argv);
int    uts_paramsToStr(char *strBuf, int ind);
void   uts_printParams();
void   uts_helpMessage();

void   uts_showStats(int nPes, int chunkSize, double walltime, counter_t nNodes, counter_t nLeaves, counter_t maxDepth);
double uts_wctime();

double rng_toProb(int n);

/* Common tree routines */
void   uts_initRoot(Node * root, int type);
int    uts_numChildren(Node *parent);
int    uts_numChildren_bin(Node * parent);
int    uts_numChildren_geo(Node * parent);
int    uts_childType(Node *parent);

/* Implementation Specific Functions */
#ifdef BUPC_TEST_HARNESS
const char * impl_getName();
#else
char * impl_getName();
#endif
int    impl_paramsToStr(char *strBuf, int ind);
int    impl_parseParam(char *param, char *value);
void   impl_helpMessage();
void   impl_abort(int err);


#ifdef __cplusplus
}
#endif

#endif /* _UTS_H */
