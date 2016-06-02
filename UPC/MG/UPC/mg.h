#ifndef _MG_H
#define _MG_H 

#ifndef _UPC_DI

#ifdef _MPI
#include <mpi.h>
#endif

#ifdef _UPC
#include "upc.h"
#include <bupc_extensions.h>
#endif

#ifdef MY_POSIX_SEM
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#endif

//------------------------------------------------------------------------------------------------------------------------------

typedef struct {
  int rank;							// MPI rank of remote process
  int local_index;						// index in subdomains[] on remote process
#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
  struct{int buf;struct{int faces,edges,corners;}offset;}send;	// i.e. calculate offset as faceSize*faces + edgeSize*edges + cornerSize*corners
  struct{int buf;struct{int faces,edges,corners;}offset;}recv;	// i.e. calculate offset as faceSize*faces + edgeSize*edges + cornerSize*corners
#endif
} neighbor_type;

//------------------------------------------------------------------------------------------------------------------------------
typedef struct {
  struct {int i, j, k;}low;  			// global coordinates of the first (non-ghost) element of subdomain at the finest resolution
  struct {int i, j, k;}dim;  			// subdomain dimensions at finest resolution
  int numLevels;      				// number of levels in MG v-cycle.  1=no restrictions
  int ghosts;                			// ghost zone depth
  neighbor_type neighbors[27];			// MPI rank and local index (on remote process) of each subdomain neighboring this subdomain
  box_type * levels;				// pointer to an array of all coarsenings of this box

#if (defined(_UPC) || defined(_UPCR)) && defined(NO_PACK)
#ifdef _UPC
  shared [] box_type* levels_sh;
#else
  upcr_pshared_ptr_t levels_sh;
#endif
#endif 
} subdomain_type;


#ifdef _UPC
typedef shared [] subdomain_type* sh_subdomain_type_p;
#endif

//------------------------------------------------------------------------------------------------------------------------------

typedef struct {
  // timing information...
  struct {
    uint64_t        smooth[10];
    uint64_t      residual[10];
    uint64_t   restriction[10];
    uint64_t interpolation[10];
    uint64_t communication[10];
    uint64_t         s2buf[10];
    uint64_t       bufcopy[10];
    uint64_t         buf2g[10];
    uint64_t          recv[10];
    uint64_t          send[10];
    uint64_t          wait[10];
    uint64_t          norm[10];
    uint64_t         blas1[10];
    uint64_t   collectives[10];
    uint64_t bottom_solve;
    uint64_t build;   // total time spent building the coefficients...
    uint64_t vcycles; // total time spent in all vcycles (all CycleMG)
    uint64_t MGSolve; // total time spent in MGSolve
  }cycles;

  int                                   rank_of_neighbor[27]; // = MPI rank of the neighbors of this process's subdomains (presumes rectahedral packing)
#if defined(_MPI) || defined(_UPC) || defined (_UPCR) 
#ifdef _MPI
  MPI_Request                               send_request[27]; // to be used for non-blocking isend's
  MPI_Request                               recv_request[27]; // to be used for non-blocking irecv's
#endif
  double *                       send_buffer[27]; // = MPI send buffers (one per neighbor)
  double *                       recv_buffer[27]; // = MPI recieve buffer (one per neighbor)
#ifdef _UPC
  shared [] double * send_buffer_sh[27];
  shared [] double * recv_buffer_sh[27];
  shared [] double * remote_recv_buffer[27];
 #ifdef PC_DB
  int recv_buffer_size[27];
#endif
  bupc_sem_t*  full_bit[27];
  bupc_sem_t*  empty_bit[27];
  bupc_sem_t*  signal_empty[27];
  bupc_sem_t*  signal_full[27];
#ifdef NO_PACK
  sh_subdomain_type_p subdomains_sh;
#endif
#else //_UPCR
  
  upcr_pshared_ptr_t  send_buffer_sh[27];
  upcr_pshared_ptr_t  recv_buffer_sh[27];
  upcr_pshared_ptr_t  remote_recv_buffer[27];
#ifdef PC_DB
  int recv_buffer_size[27];
#endif
  upcr_pshared_ptr_t full_bit[27];
  upcr_pshared_ptr_t empty_bit[27];
  upcr_pshared_ptr_t signal_empty[27];
  upcr_pshared_ptr_t signal_full[27];

#ifdef NO_PACK
  upcr_pshared_ptr_t subdomains_sh;
#endif

#endif
  struct{int faces,edges,corners;}           buffer_size[27]; // = MPI buffer size (one per neighbor) in the units of faces/edges/corners
#endif



// n.b. i=unit stride
  struct {int i, j, k;}dim;			// global dimensions at finest resolution
  struct {int i, j, k;}subdomains_in;		// total number of subdomains in i,j,k
  struct {int i, j, k;}subdomains_per_rank_in;	// number of subdomains in i,j,k
  int rank;					// MPI rank of this process
  int numsubdomains;				// number of subdomains owned by this process
  int numLevels;				// number of levels in MG v-cycle.  1=no restrictions
  int numGrids;                                 // number of grids (variables)
  int ghosts;					// ghost zone depth
  subdomain_type * subdomains;			// pointer to a list of all subdomains owned by this process
} domain_type;

#ifdef _UPC 
typedef shared domain_type * sh_domain_type_p;
//void exchange_global_buffer_info(shared sh_domain_type_p *);
void exchange_global_buffer_info(int);
//domain_type * init_domain(shared sh_domain_type_p *p );
domain_type * init_domain(int);
void init_domain_srcv(domain_type *domain, int n, int size);
void set_ghost_bufs(box_type *box);
void init_box_levels(subdomain_type * box, int NL);
void init_subdomains(domain_type * box, int SD);
shared [] char* add_disp(shared [] char* base, int elems);
shared [] double *the_saddest_hack(shared [] box_type * bp, int n);
#endif

#ifdef _UPCR
//void exchange_global_buffer_info(upcr_pshared_ptr_t );
void exchange_global_buffer_info(int);
//domain_type * init_domain(upcr_pshared_ptr_t p);
domain_type * init_domain(int);
void init_domain_srcv(domain_type *domain, int n, int size);
void set_ghost_bufs(box_type *box);
void init_box_levels(subdomain_type * box, int NL);
void init_subdomains(domain_type * box, int SD);
upcr_pshared_ptr_t add_disp(upcr_pshared_ptr_t base, int elems);
upcr_pshared_ptr_t the_saddest_hack(upcr_pshared_ptr_t bp, int n);
#endif
//------------------------------------------------------------------------------------------------------------------------------
int create_subdomain(subdomain_type * box, 
		     int subdomain_low_i, int subdomain_low_j, int subdomain_low_k,
		     int subdomain_dim_i, int subdomain_dim_j, int subdomain_dim_k,
		     int numGrids, int ghosts, int numLevels);
void destroy_domain(domain_type * domain);
int create_domain(domain_type * domain,
		  int subdomain_dim_i, int subdomain_dim_j, int subdomain_dim_k,
		  int subdomains_per_rank_in_i, int subdomains_per_rank_in_j, int subdomains_per_rank_in_k,
		  int ranks_in_i, int ranks_in_j, int ranks_in_k,
                   int rank, int numGrids, int ghosts, int numLevels);
#if defined(_HC_MPI) || defined(_HC)
#pragma hc continuable
#endif 
void MGBuild(domain_type * domain);

#if defined(_HC_MPI) || defined(_HC)
#pragma hc continuable
#endif 

void MGSolve(domain_type * domain, int e0_id, int R0_id, int homogeneous, double a, double b, double h0);
void CycleMG(domain_type * domain, int e_id, int R_id, double a, double b, double h0);
void print_timing(domain_type *domain);
void init_omp_threads(int *);
void print_all_domain_ptrs(domain_type*);
void print_all_sd_ptrs(subdomain_type*,int);
void print_all_box_ptrs(box_type*);

//------------------------------------------------------------------------------------------------------------------------------
#endif
#endif
