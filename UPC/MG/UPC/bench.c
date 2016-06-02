#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#if defined(_HC_MPI) || defined(_HC)
#include <hc.h>
#endif
#include <unistd.h>

//#include <sched.h>
//------------------------------------------------------------------------------------------------------------------------------
#include <omp.h>
#ifdef _MPI
#include <mpi.h>
#endif
#ifdef _UPC
#include "upc.h"
#endif 

#ifdef _UPCR
#ifdef _UPC
#error DDs
#endif
#include "upcr.h"
#endif
//------------------------------------------------------------------------------------------------------------------------------
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "timer.h"
#include "operators.h"
//==============================================================================
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//#if defined(__x86_64__)
//  #warning x86/64 detected...
//#elif defined(__sparc) && defined (__sparcv9)
//  #warning Sparc detected
//#elif defined(__bgp__)
//  #warning BlueGene/P detected
//#else
//  #warning Defaulting to generic processor...
//#endif
////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//#if defined(__CrayXT__)
//  #warning CrayXT detected...
////#include "../arch/generic/affinity.infoonly.c"
//#elif defined(__SOLARIS__)
//  #warning Solaris detected...
////#include "../arch/sparc/affinity.solaris.c"
//#elif defined(__bgp__)
//  #warning BlueGene/P detected...
////#include "../arch/generic/affinity.bgp.c"
//#else
//  #warning Defaulting to standard Linux cluster...
////#include "../arch/generic/affinity.reconstruct.c"
//#endif
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

pthread_mutex_t norm_mutex_int;
pthread_mutex_t * norm_mutex = &norm_mutex_int;

#define DOMAIN_1_ID 1
#define DOMAIN_CA_ID 0

#ifdef _UPC
#error Not implemented ...
//shared sh_domain_type_p domain_1_sh[THREADS];
#ifndef MG_NO_CA
//shared sh_domain_type_p domain_CA_sh[THREADS];
#endif
#endif


#ifdef _UPCR
//extern upcr_pshared_ptr_t domain_1_sh;
#ifndef MG_NO_CA
//extern upcr_pshared_ptr_t domain_CA_sh;
#endif
int gasneti_linkconfig_idiotcheck_CORE_SMP;
int gasneti_linkconfig_idiotcheck_EXTENDED_SMP;

#endif



#ifdef THOR_ENABLED
extern void  thor_default_server_init();
extern void thor_windup_comm();
extern void thor_winddown_comm();
extern void thor_killall();
extern int thor_servers_per_domain;
extern int thor_issue_immediate; 
#endif

//==============================================================================
void __box_initialize_rhs(box_type *box, int grid_id, double h){
  //printf("%3d,%3d,%3d\n",box->low.i,box->low.j,box->low.k);
  int i,j,k;
  double twoPi = 2.0 * 3.1415926535;
  memset(box->grids[grid_id],0,box->volume*sizeof(double)); // zero out the grid and ghost zones
  for(k=0;k<box->dim.k;k++){
  for(j=0;j<box->dim.j;j++){
  for(i=0;i<box->dim.i;i++){
    double x = h*(double)(i+box->low.i);
    double y = h*(double)(j+box->low.j);
    double z = h*(double)(k+box->low.k);
    int ijk = (i+box->ghosts) + (j+box->ghosts)*box->pencil + (k+box->ghosts)*box->plane;
    double value = sin(twoPi*x)*sin(twoPi*y)*sin(twoPi*z);
    box->grids[grid_id][ijk] = value;
  }}}
}


void print_box(box_type *box, int grid_id){
  int i;
  int gridSize = box->dim_with_ghosts.i * box->dim_with_ghosts.j * box->dim_with_ghosts.k;
  for(i=0; i < gridSize; i++){
    double value = box->grids[grid_id][i];
    printf("%f ", value);
  }
  printf("\n");
}

  int MPI_Rank=0;
int do_print = 0;
//==============================================================================
#ifdef _MY_GUPC
#define user_main upc_main
#endif

#ifndef THOR_ENABLED
void thor_server_event_loop() {}
#endif 

int user_main(int argc, char **argv){

  printf("This is MiniGMG.\n");

  int MPI_Tasks=1;
  int OMP_Threads = 1;


  
   
#ifdef _HC_MPI 
  init_omp_threads(&_OMP_Threads);
#else
  init_omp_threads(&OMP_Threads);
#endif


  pthread_mutex_init(norm_mutex, 0);
#ifdef _MPI 
#warning Compiling for MPI...
  int MPI_threadingModel          = -1;
  //int MPI_threadingModelRequested = MPI_THREAD_SINGLE;
  int MPI_threadingModelRequested = MPI_THREAD_FUNNELED;
  //int MPI_threadingModelRequested = MPI_THREAD_MULTIPLE;
  MPI_Init_thread(&argc, &argv, MPI_threadingModelRequested, &MPI_threadingModel);
  MPI_Comm_size(MPI_COMM_WORLD, &MPI_Tasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &MPI_Rank);
  
  if(MPI_threadingModel>MPI_threadingModelRequested)MPI_threadingModel=MPI_threadingModelRequested;
  if(MPI_Rank==0){
    if(MPI_threadingModelRequested == MPI_THREAD_MULTIPLE  )printf("Requested MPI_THREAD_MULTIPLE, ");
    else if(MPI_threadingModelRequested == MPI_THREAD_SINGLE    )printf("Requested MPI_THREAD_SINGLE, ");
    else if(MPI_threadingModelRequested == MPI_THREAD_FUNNELED  )printf("Requested MPI_THREAD_FUNNELED, ");
    else if(MPI_threadingModelRequested == MPI_THREAD_SERIALIZED)printf("Requested MPI_THREAD_SERIALIZED, ");
    else if(MPI_threadingModelRequested == MPI_THREAD_MULTIPLE  )printf("Requested MPI_THREAD_MULTIPLE, ");
    else                                                printf("got Unknown MPI_threadingModel (%d)\n",MPI_threadingModel);
    if(MPI_threadingModel == MPI_THREAD_MULTIPLE  )printf("got MPI_THREAD_MULTIPLE\n");
    else if(MPI_threadingModel == MPI_THREAD_SINGLE    )printf("got MPI_THREAD_SINGLE\n");
    else if(MPI_threadingModel == MPI_THREAD_FUNNELED  )printf("got MPI_THREAD_FUNNELED\n");
    else if(MPI_threadingModel == MPI_THREAD_SERIALIZED)printf("got MPI_THREAD_SERIALIZED\n");
    else if(MPI_threadingModel == MPI_THREAD_MULTIPLE  )printf("got MPI_THREAD_MULTIPLE\n");
    else                                                printf("got Unknown MPI_threadingModel (%d)\n",MPI_threadingModel);
    fflush(stdout);  }
#endif
  
#ifdef _UPC
#warning Compiling for UPC...
  MPI_Rank = MYTHREAD;
  MPI_Tasks = THREADS;
#endif 

#ifdef _UPCR
  MPI_Rank = upcr_mythread();
  MPI_Tasks = upcr_threads();
#endif
  
//  timer_init();

  int log2_subdomain_dim = 6;
  //    log2_subdomain_dim = 7;
  //    log2_subdomain_dim = 5;
  //    log2_subdomain_dim = 2;
  int subdomains_per_rank_in_i=256 / (1<<log2_subdomain_dim);
  int subdomains_per_rank_in_j=256 / (1<<log2_subdomain_dim);
  int subdomains_per_rank_in_k=256 / (1<<log2_subdomain_dim);
  int ranks_in_i=1;
  int ranks_in_j=1;
  int ranks_in_k=1;
  
  if(argc==2){
    log2_subdomain_dim=atoi(argv[1]);
    subdomains_per_rank_in_i=256 / (1<<log2_subdomain_dim);
    subdomains_per_rank_in_j=256 / (1<<log2_subdomain_dim);
    subdomains_per_rank_in_k=256 / (1<<log2_subdomain_dim);
  }else if(argc==5){
    log2_subdomain_dim=atoi(argv[1]);
    subdomains_per_rank_in_i=atoi(argv[2]);
    subdomains_per_rank_in_j=atoi(argv[3]);
    subdomains_per_rank_in_k=atoi(argv[4]);
  }else if(argc>=8){
    log2_subdomain_dim=atoi(argv[1]);
    subdomains_per_rank_in_i=atoi(argv[2]);
    subdomains_per_rank_in_j=atoi(argv[3]);
    subdomains_per_rank_in_k=atoi(argv[4]);
    ranks_in_i=atoi(argv[5]);
                  ranks_in_j=atoi(argv[6]);
                  ranks_in_k=atoi(argv[7]);
  }else

 if(argc!=1){
    if(MPI_Rank==0){printf("usage: ./a.out [log2_subdomain_dim]   [subdomains per rank in i,j,k]  [ranks in i,j,k]\n");}
#ifdef _MPI
    MPI_Finalize();
#endif
#ifdef _UPC
    upc_global_exit(-1);
#endif
#ifdef _UPCR
    upcr_global_exit(-1);
#endif
    exit(0);
  }
  

#ifdef THOR_ENABLED
  if(argc > 8) {
    thor_issue_immediate = 1;
  } else 
#endif

  if(log2_subdomain_dim>7){
    if(MPI_Rank==0){printf("error, log2_subdomain_dim(%d)>7\n",log2_subdomain_dim);}
#ifdef _MPI
    MPI_Finalize();
#endif
    exit(0);
  }
  
  if(ranks_in_i*ranks_in_j*ranks_in_k != MPI_Tasks){
    if(MPI_Rank==0){printf("error, ranks_in_i*ranks_in_j*ranks_in_k(%d*%d*%d=%d) != MPI_Tasks(%d)\n",ranks_in_i,ranks_in_j,ranks_in_k,ranks_in_i*ranks_in_j*ranks_in_k,MPI_Tasks);}
#ifdef _MPI
    MPI_Finalize();
#endif
#ifdef _UPC
    upc_global_exit(-1);
#endif
#ifdef _UPCR
    upcr_global_exit(-1);
#endif
    exit(0);
  }
  
#ifdef THOR_ENABLED
  // Init UPC Dispatch Server
  printf("Winding up thor...\n");
  thor_default_server_init();
  thor_windup_comm();
#endif


  if(MPI_Rank==0)printf("%d MPI Tasks of %d threads\n",MPI_Tasks,OMP_Threads);
  
  int subdomain_dim_i=1<<log2_subdomain_dim;
  int subdomain_dim_j=1<<log2_subdomain_dim;
  int subdomain_dim_k=1<<log2_subdomain_dim;
  //    dim = 128 64 32 16 8 4
  // levels =   6  5  4  3 2 1
  int levels_in_vcycle=(log2_subdomain_dim+1)-2; // ie -log2(bottom size)
  //levels_in_vcycle = 1; // turn off MG
  
  //uint64_t _timeStart = CycleTime();
  //sleep(1);
  //uint64_t _timeEnd   = CycleTime();
  //printf("%20llu\n",_timeStart);
  //printf("%20llu\n",_timeEnd  );
  //printf("%20llu\n",_timeEnd-_timeStart);
  //return(0);
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  //Affinity_Init();
  //cpu_set_t NewMask;
  //CPU_ZERO(&NewMask);
  //CPU_SET(1,&NewMask);
  //if(sched_setaffinity(0, sizeof(NewMask), &NewMask)<0){
  //  printf("Affinity: Couldn't bind thread\n");
  //  exit(0);
  //}
  //sched_getaffinity(0, sizeof(NewMask), &NewMask);
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  domain_type * domain_1;
#ifndef MG_NO_CA
  domain_type * domain_CA;
#endif

#if defined (_UPC) || defined(_UPCR)
  domain_1 = init_domain(DOMAIN_1_ID);
#ifndef MG_NO_CA
  domain_CA = init_domain(DOMAIN_CA_ID);
#endif
#else
  domain_1 = malloc(sizeof(domain_type));
#ifndef MG_NO_CA
  domain_CA = malloc(sizeof(domain_type));
#endif
#endif
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  create_domain(domain_1 ,subdomain_dim_i,subdomain_dim_j,subdomain_dim_k,
  		subdomains_per_rank_in_i,subdomains_per_rank_in_j,subdomains_per_rank_in_k,
  		ranks_in_i,ranks_in_j,ranks_in_k,
  		MPI_Rank,10,1,levels_in_vcycle);
  do_print = 0;
#ifndef MG_NO_CA
  create_domain(domain_CA,subdomain_dim_i,subdomain_dim_j,subdomain_dim_k,
  		subdomains_per_rank_in_i,subdomains_per_rank_in_j,subdomains_per_rank_in_k,
  		ranks_in_i,ranks_in_j,ranks_in_k,
  		MPI_Rank,10,4,levels_in_vcycle);
#endif

#if defined(_UPC) || defined(_UPCR)

  exchange_global_buffer_info(DOMAIN_1_ID);
#ifndef MG_NO_CA
  exchange_global_buffer_info(DOMAIN_CA_ID);
#endif

#endif 
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  double  a=0.9;
  double  b=0.9;
  double h0=1.0/((double)(domain_1->dim.i));
  int box;
  int s,sMax=1;
#if defined(_MPI) || defined(_UPC) || defined (_UPCR)
  sMax=1;
#endif
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // define __alpha, __beta*, etc...
  if(!MPI_Rank) {
    printf("\n>>> DOMAIN OR <<<\n\n"); fflush(stdout);
  }

  initialize_grid_to_scalar( domain_1,0,__alpha ,h0,1.0);
  initialize_grid_to_scalar( domain_1,0,__beta_i,h0,1.0);
  initialize_grid_to_scalar( domain_1,0,__beta_j,h0,1.0);
  initialize_grid_to_scalar( domain_1,0,__beta_k,h0,1.0);
  for(box=0;box< domain_1->numsubdomains;box++){__box_initialize_rhs(& domain_1->subdomains[box].levels[0],__f,h0);}
  for(box=0;box< domain_1->numsubdomains;box++){__box_zero_grid(& domain_1->subdomains[box].levels[0],__u);}
  
  //for(box=0;box< domain_1->numsubdomains;box++){__box_initialize_grid_to_scalar(& domain_1->subdomains[box].levels[0],__u,0.0,1.0);}
  //printf("Thread %d before exchange: ", MPI_Rank);
  //print_box(& domain_1->subdomains[0].levels[0], __u);
  //printf("Thread %d doing exchange.\n", MPI_Rank);
  //exchange_boundary(domain_1, 0, __u, 1, 1, 1);
  //printf("Thread %d finished exchange: ", MPI_Rank);
  //print_box(& domain_1->subdomains[0].levels[0], __u);
  //upcri_err("Exiting for testing.\n");

 
  MGBuild(domain_1 );

#ifndef MG_NO_WARMUP
  MGSolve(domain_1 ,__u,__f,1,a,b,h0); // warmup
#endif
  for(s=0;s<sMax;s++) {
    MGSolve(domain_1 ,__u,__f,1,a,b,h0);
    print_timing(domain_1 );
  }


#ifndef MG_NO_CA
  //CA algorithm
  if(!MPI_Rank) {
    printf("\n>>> DOMAIN CA <<<\n\n"); fflush(stdout);
  }

  initialize_grid_to_scalar(domain_CA,0,__alpha ,h0,1.0);
  initialize_grid_to_scalar(domain_CA,0,__beta_i,h0,1.0);
  initialize_grid_to_scalar(domain_CA,0,__beta_j,h0,1.0);
  initialize_grid_to_scalar(domain_CA,0,__beta_k,h0,1.0);
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // define RHS
  for(box=0;box<domain_CA->numsubdomains;box++){__box_initialize_rhs(&domain_CA->subdomains[box].levels[0],__f,h0);}
  // make initial guess for __u
  for(box=0;box<domain_CA->numsubdomains;box++){__box_zero_grid(&domain_CA->subdomains[box].levels[0],__u);}
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  MGBuild(domain_CA);
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
#ifndef MG_NO_WARMUP
  MGSolve(domain_CA,__u,__f,1,a,b,h0); // warmup
#endif 
  for(s=0;s<sMax;s++) {
    MGSolve(domain_CA,__u,__f,1,a,b,h0);
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  // verification....
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

    print_timing(domain_CA);
  }
#endif

#ifdef THOR_ENABLED
 thor_winddown_comm();
 thor_killall();
#endif

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  //destroy_domain(domain_1 ); 
  //destroy_domain(domain_CA);
  
  // TODO - WHY IS THIS COMMENTED OUT?
  //  free(domain_1); 
  //free(domain_CA);

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  pthread_mutex_destroy(norm_mutex);
  #ifdef _MPI
  MPI_Finalize();
  #endif
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
  return(0);
}
