#ifdef _UPC
#include "upc.h"
#endif
#include <stdio.h>

#ifdef _UPCR
#ifdef _UPC
#error DDs
#endif
#include "upcr.h"
#endif

extern int do_print;

char buf[1024];
#define print_sem(what,s,pos,do_it)  {		\
if(do_it ) { \
 upcri_dump_shared(upcr_pshared_to_shared(s), buf, UPCRI_DUMP_MIN_LENGTH);\
 buf[0] = '\0'; \
 printf("%d: %s AT %d   %s\n", upcr_mythread(), what, pos,buf);		\
  fflush(stdout);\
 }\
}


#ifdef THOR_ENABLED
extern void sbupc_waitsync_all(bupc_handle_t *ph, size_t n);
extern bupc_handle_t sbupc_memput_async(upcr_shared_ptr_t dst, void * src, size_t n);
extern bupc_handle_t sbupc_memget_async(void *dst, upcr_shared_ptr_t src, size_t n);
#define bupc_memput_async sbupc_memput_async
#define bupc_waitsync sbupc_waitsync
#define bupc_waitsync_all sbupc_waitsync_all
#endif


#ifdef _MY_GUPC
  #define PSHARED2SHARED(x) (x)
#else
  #define PSHARED2SHARED(x) (upcr_pshared_to_shared(x))
#endif

//----------------------------------------------------------------------------------------------------------------------------------------------------
// Exchange boundaries by aggregating into domain buffers
//----------------------------------------------------------------------------------------------------------------------------------------------------

#warning will aggregate MPI messages into process-level buffers befor sending
void exchange_boundary(domain_type *domain, int level, int grid_id, int exchange_faces, int exchange_edges, int exchange_corners){

  uint64_t _timeStart,_timeEnd;
  int sendBox,recvBox,n;
  //                 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}
  int       di[27] = {-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1};
  int       dj[27] = {-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1};
  int       dk[27] = {-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int    faces[27] = {0,0,0,0,1,0,0,0,0,  0,1,0,1,0,1,0,1,0,  0,0,0,0,1,0,0,0,0};
  int    edges[27] = {0,1,0,1,0,1,0,1,0,  1,0,1,0,0,0,1,0,1,  0,1,0,1,0,1,0,1,0};
  int  corners[27] = {1,0,1,0,0,0,1,0,1,  0,0,0,0,0,0,0,0,0,  1,0,1,0,0,0,1,0,1};
  int exchange[27] = {0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0};
  

for(n=0;n<27;n++){
    if(                       exchange_faces   )exchange[n] |=   faces[n];
    if( (domain->ghosts>1) && exchange_edges   )exchange[n] |=   edges[n];
    if( (domain->ghosts>1) && exchange_corners )exchange[n] |= corners[n];
             
  }
  int   FaceSizeAtLevel = domain->subdomains[0].levels[level].dim.i*domain->subdomains[0].levels[level].dim.i*domain->ghosts;
  int   EdgeSizeAtLevel = domain->subdomains[0].levels[level].dim.i*domain->ghosts*domain->ghosts;
  int CornerSizeAtLevel = domain->ghosts*domain->ghosts*domain->ghosts;
  char  *base;

  #ifdef _MPI
  MPI_Request requests[54];
  MPI_Status  status[54];
  int nMessages=0;
  #endif

#ifdef _UPC
  bupc_handle_t requests[154];
  int nMessages = 0;
  static int phase = 0;
  shared [] double * remote_buf;
#endif

#ifdef _UPCR 
#ifdef _UPC
#error Both UPC and UPCR defined ...
#endif
  bupc_handle_t requests[154];
  int nMessages = 0;
  static int phase = 0;
  upcr_pshared_ptr_t remote_buf;
#endif

  // loop through bufs, prepost Irecv's
  #ifdef _MPI
  _timeStart = CycleTime();
  for(n=0;n<27;n++)
    if(exchange[26-n] && (domain->rank_of_neighbor[26-n] != domain->rank) ){
      int size = FaceSizeAtLevel*domain->buffer_size[26-n].faces + EdgeSizeAtLevel*domain->buffer_size[26-n].edges + CornerSizeAtLevel*domain->buffer_size[26-n].corners;
      MPI_Irecv(domain->recv_buffer[26-n],size,MPI_DOUBLE,domain->rank_of_neighbor[26-n],n,MPI_COMM_WORLD,&requests[nMessages]);
      nMessages++;
    }
  _timeEnd = CycleTime();
  domain->cycles.recv[level] += (_timeEnd-_timeStart);
  #endif

#ifdef _UPC
  //recv in UPC is a Nop
#endif


  // extract surface, pack into surface_bufs
  _timeStart = CycleTime();
  int test = domain->numsubdomains;
  #pragma omp parallel for private(n,sendBox) collapse(2)
  for(sendBox=0;sendBox<test;sendBox++){
    for(n=0;n<27;n++)
      {if(exchange[n]){
	  int ghosts = domain->subdomains[sendBox].levels[level].ghosts;
	  int pencil = domain->subdomains[sendBox].levels[level].pencil;
	  int  plane = domain->subdomains[sendBox].levels[level].plane;
	  int  dim_i = domain->subdomains[sendBox].levels[level].dim.i;
	  int  dim_j = domain->subdomains[sendBox].levels[level].dim.j;
	  int  dim_k = domain->subdomains[sendBox].levels[level].dim.k;
	  int low_i,low_j,low_k;
	  int buf_i,buf_j,buf_k;
	  switch(di[n]){
	  case -1:low_i=ghosts;buf_i=ghosts;break;
	  case  0:low_i=ghosts;buf_i= dim_i;break;
	  case  1:low_i= dim_i;buf_i=ghosts;break;
	  };
	  switch(dj[n]){
	  case -1:low_j=ghosts;buf_j=ghosts;break;
	  case  0:low_j=ghosts;buf_j= dim_j;break;
	  case  1:low_j= dim_j;buf_j=ghosts;break;
	  };
	  switch(dk[n]){
	  case -1:low_k=ghosts;buf_k=ghosts;break;
	  case  0:low_k=ghosts;buf_k= dim_k;break;
	  case  1:low_k= dim_k;buf_k=ghosts;break;
	  };
	  extract_from_grid(low_i,low_j,low_k,buf_i,buf_j,buf_k,pencil,plane,domain->subdomains[sendBox].levels[level].grids[grid_id],domain->subdomains[sendBox].levels[level].surface_bufs[n],1);
	}}
  }
  _timeEnd = CycleTime();
  domain->cycles.s2buf[level] += (_timeEnd-_timeStart);
  
  
// pack domain buffers
#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
  _timeStart = CycleTime();
   test = domain->numsubdomains;




#if defined(_UPCR) || defined(_UPC) 

#ifdef PC_NO_DB
   for(n=0; n < 27; n++) {
     if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){
      bupc_sem_waitN(domain->empty_bit[n],1);
     }
   }
#endif 
#endif 

#pragma omp parallel for private(n,sendBox,recvBox) collapse(2)
  for(sendBox=0;sendBox<test;sendBox++){
    for(n=0;n<27;n++)if(exchange[n]){
	recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
      if(domain->subdomains[sendBox].neighbors[n].rank != domain->rank){
        buffer_copy( domain->send_buffer[domain->subdomains[sendBox].neighbors[n].send.buf] +
		     FaceSizeAtLevel*domain->subdomains[sendBox].neighbors[n].send.offset.faces +
		     EdgeSizeAtLevel*domain->subdomains[sendBox].neighbors[n].send.offset.edges +
		     CornerSizeAtLevel*domain->subdomains[sendBox].neighbors[n].send.offset.corners,
		     domain->subdomains[sendBox].levels[level].surface_bufs[n],
		     domain->subdomains[sendBox].levels[level].bufsizes[n], 
		     1 );
      }
  }}



#ifdef THOR_ENABLED
  //thor_windup_comm();
#endif

#if defined(_BARRIER_SYNC)
    upcr_notify(0,0); // OK
    upcr_wait(0,0);
#endif
#if defined(PC_NO_DB) /*|| defined(PC_DB)*/
    //signal buffer ready
    for(n=0;n<27;n++)
      if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ) {
	bupc_sem_postN(domain->signal_full[n],1);
      }
#endif
#if defined(PC_NO_DB) /*|| defined(PC_DB)*/
  for(n=0;n<27;n++)
    if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){
      bupc_sem_waitN(domain->full_bit[n],1);     
    }
#endif
  _timeEnd = CycleTime();
  domain->cycles.bufcopy[level] += (_timeEnd-_timeStart);
#endif


  // loop through bufs, post Isend's
#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
  _timeStart = CycleTime();
  for(n=0;n<27;n++)
    if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){
      int size = FaceSizeAtLevel*domain->buffer_size[n].faces + EdgeSizeAtLevel*domain->buffer_size[n].edges + CornerSizeAtLevel*domain->buffer_size[n].corners;
#ifdef _MPI
      MPI_Isend(domain->send_buffer[n],size,MPI_DOUBLE,domain->rank_of_neighbor[n],n,MPI_COMM_WORLD,&requests[nMessages]);
#endif
#if defined(_UPC) || defined(_UPCR)
      remote_buf = domain->remote_recv_buffer[n];
#ifdef PC_DB
      remote_buf = add_disp(remote_buf, phase*domain->recv_buffer_size[26-n]);
#endif      
      requests[nMessages] = bupc_memget_async(domain->recv_buffer[n], PSHARED2SHARED(remote_buf), size*sizeof(double));
      //printf("%d: %d GET %d\n", upcr_mythread(), upcr_threadof_pshared(remote_buf), size*sizeof(double));
#endif
      nMessages++;
    }
  _timeEnd = CycleTime();
  domain->cycles.send[level] += (_timeEnd-_timeStart);
#endif
  
  
  // exchange locally... try and hide within Isend latency... 
  _timeStart = CycleTime();
  test = domain->numsubdomains;
  //#pragma omp parallel for private(n,sendBox,recvBox) collapse(2)
  for(recvBox=0;recvBox<test;recvBox++){
    for(n=0;n<27;n++)if(exchange[n]){
      sendBox = domain->subdomains[recvBox].neighbors[n].local_index;
      if(domain->subdomains[recvBox].neighbors[n].rank == domain->rank){
	buffer_copy(domain->subdomains[recvBox].levels[level].ghost_bufs[n],
		    domain->subdomains[sendBox].levels[level].surface_bufs[26-n],
		    domain->subdomains[sendBox].levels[level].bufsizes[26-n], 1 );
      }}}
  _timeEnd = CycleTime();
  domain->cycles.bufcopy[level] += (_timeEnd-_timeStart);
  
  
#if defined(_MPI) || defined (_UPC) || defined(_UPCR)
  // loop through bufs, MPI_Wait on recvs
  _timeStart = CycleTime();
#ifdef _MPI
  MPI_Waitall(nMessages,requests,status);
#endif

#if defined(_UPC) || defined(_UPCR)
  if(nMessages) {
    //wait for the gets to complete
    bupc_waitsync_all(requests, nMessages);
    //printf("%d: WAIT ON %d\n", upcr_mythread(), nMessages);
  }
#endif
#endif
  
#if defined(_UPC) || defined(_UPCR)
#ifdef THOR_ENABLED
  thor_winddown_comm();
#endif

#ifdef PC_NO_DB
  for(n=0;n<27;n++)
    if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){     
      bupc_sem_postN(domain->signal_empty[n],1);
    }
#endif

#if defined(_BARRIER_SYNC)
    upcr_notify(0,0); // OK
    upcr_wait(0,0);
#endif
#endif	


  // MOVED TIMER TO HERE
#if defined(_MPI) || defined(_UPC) || defined (_UPCR)
  _timeEnd = CycleTime();
  domain->cycles.wait[level] += (_timeEnd-_timeStart);
#endif


  // unpack domain buffers 
  // TODO - WHICH TIMER IS THIS? WHAT MAKES SENSE?
#if defined(_MPI) || defined(_UPC) || defined (_UPCR)
  _timeStart = CycleTime();
  test = domain->numsubdomains;
#pragma omp parallel for private(n,sendBox,recvBox, base) collapse(2)
  for(recvBox=0;recvBox<test;recvBox++){
    for(n=0;n<27;n++)if(exchange[n]){
	sendBox = domain->subdomains[recvBox].neighbors[n].local_index;
	if(domain->subdomains[recvBox].neighbors[n].rank != domain->rank){
	  base =  domain->recv_buffer[domain->subdomains[recvBox].neighbors[n].recv.buf] +
	    FaceSizeAtLevel*domain->subdomains[recvBox].neighbors[n].recv.offset.faces +
	    EdgeSizeAtLevel*domain->subdomains[recvBox].neighbors[n].recv.offset.edges +
	    CornerSizeAtLevel*domain->subdomains[recvBox].neighbors[n].recv.offset.corners;
#ifdef PC_DB
	  base = base + phase*domain->recv_buffer_size[n];
#endif 
	  buffer_copy(domain->subdomains[recvBox].levels[level].ghost_bufs[n], 
		      base,
		      domain->subdomains[recvBox].levels[level].bufsizes[n], 
		      1 );
	}
      }
  }

  _timeEnd = CycleTime();
  domain->cycles.bufcopy[level] += (_timeEnd-_timeStart);
#endif


#ifdef PC_DB
  //flip the DB
  //phase = (phase == 0) ? 1 : 0;
#endif

  
  // unpack ghost_bufs, insert into grid
  _timeStart = CycleTime();
  test = domain->numsubdomains;
#pragma omp parallel for private(n,recvBox) collapse(2)
  for(recvBox=0;recvBox<test;recvBox++){
    for(n=0;n<27;n++){if(exchange[n]){
	int ghosts = domain->subdomains[recvBox].levels[level].ghosts;
	int pencil = domain->subdomains[recvBox].levels[level].pencil;
	int  plane = domain->subdomains[recvBox].levels[level].plane;
	int  dim_i = domain->subdomains[recvBox].levels[level].dim.i;
	int  dim_j = domain->subdomains[recvBox].levels[level].dim.j;
	int  dim_k = domain->subdomains[recvBox].levels[level].dim.k;
	int low_i,low_j,low_k;
	int buf_i,buf_j,buf_k;
	switch(di[n]){
        case -1:low_i=           0;buf_i=ghosts;break;
        case  0:low_i=      ghosts;buf_i= dim_i;break;
        case  1:low_i=ghosts+dim_i;buf_i=ghosts;break;
	};
	switch(dj[n]){
        case -1:low_j=           0;buf_j=ghosts;break;
        case  0:low_j=      ghosts;buf_j= dim_j;break;
        case  1:low_j=ghosts+dim_j;buf_j=ghosts;break;
	};
	switch(dk[n]){
        case -1:low_k=           0;buf_k=ghosts;break;
        case  0:low_k=      ghosts;buf_k= dim_k;break;
        case  1:low_k=ghosts+dim_k;buf_k=ghosts;break;
	};
	insert_into_grid(low_i,low_j,low_k,buf_i,buf_j,buf_k,pencil,plane,domain->subdomains[recvBox].levels[level].ghost_bufs[n],domain->subdomains[recvBox].levels[level].grids[grid_id],0);
      }}
  }
  _timeEnd = CycleTime();
  domain->cycles.buf2g[level] += (_timeEnd-_timeStart);
  
}
