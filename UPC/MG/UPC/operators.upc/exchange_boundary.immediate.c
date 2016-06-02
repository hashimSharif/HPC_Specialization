//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
//#include "../timer.h"

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


#define MAX_MESG 4096
//#define THROTTLE 512

#ifdef THOR_ENABLED

extern void thor_windup_comm();
extern void thor_winddown_comm();  
extern void sbupc_waitsync_all(bupc_handle_t *ph, size_t n);
extern bupc_handle_t sbupc_memput_async(upcr_shared_ptr_t dst, void * src, size_t n);
extern bupc_handle_t sbupc_memget_async(void *dst, upcr_shared_ptr_t src, size_t n);
#define xbupc_memput_async sbupc_memput_async
#define xbupc_waitsync sbupc_waitsync
#define xbupc_waitsync_all sbupc_waitsync_all
#else
#define xbupc_memput_async bupc_memput_async
#define xbupc_waitsync bupc_waitsync
#define xbupc_waitsync_all bupc_waitsync_all
#endif

//------------------------------------------------------------------------------------------------------------------------------
// Exchange boundaries by having all boxes indivudually send/recv
//------------------------------------------------------------------------------------------------------------------------------
void exchange_boundary(domain_type *domain, int level, int grid_id, int exchange_faces, int exchange_edges, int exchange_corners){
//#if defined(_UPCR) || defined(_UPC)  
//printf("[%d] Exchange Boundary.\n", upcr_mythread());
//#endif
  uint64_t _timeStart,_timeEnd;
  int sendBox,recvBox,n;
  int       di[27] = {-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1,-1, 0, 1};
  int       dj[27] = {-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1,-1,-1,-1, 0, 0, 0, 1, 1, 1};
  int       dk[27] = {-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int    faces[27] = {0,0,0,0,1,0,0,0,0,  0,1,0,1,0,1,0,1,0,  0,0,0,0,1,0,0,0,0};
  int    edges[27] = {0,1,0,1,0,1,0,1,0,  1,0,1,0,0,0,1,0,1,  0,1,0,1,0,1,0,1,0};
  int  corners[27] = {1,0,1,0,0,0,1,0,1,  0,0,0,0,0,0,0,0,0,  1,0,1,0,0,0,1,0,1};
  int exchange[27] = {0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0};

  int wait_empty[27] = {0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0};

  for(n=0;n<27;n++){
    if(                       exchange_faces   )exchange[n] |=   faces[n];
    if( (domain->ghosts>1) && exchange_edges   )exchange[n] |=   edges[n];
    if( (domain->ghosts>1) && exchange_corners )exchange[n] |= corners[n];
  }


#if defined(_UPCR) || defined(_UPC)
  bupc_handle_t xrequests[MAX_MESG];
  bupc_handle_t requests[MAX_MESG];
  int nMessages=0;
  int xnMessages=0;
  static int phase = 0;
  upcr_pshared_ptr_t remote_buf;
#endif





#if defined(_UPCR) || defined(_UPC)  
#if defined(_BARRIER_SYNC)
    upcr_notify(0,0);
    upcr_wait(0,0);
#endif
#endif



#ifdef _MPI
    int nMessages=0;
    for(recvBox=0;recvBox<domain->numsubdomains;recvBox++){
      for(n=0;n<27;n++)if(exchange[n]){
	  sendBox = domain->subdomains[recvBox].neighbors[n].local_index;
	  if(domain->subdomains[recvBox].neighbors[n].rank != domain->rank){
	    nMessages += 2; // one for send and one for recv
	  }}}
    MPI_Request *requests = (MPI_Request*)malloc(nMessages*sizeof(MPI_Request));
    MPI_Status  *status   = (MPI_Status *)malloc(nMessages*sizeof(MPI_Status ));
    nMessages=0;
#endif


#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeStart = CycleTime();
#endif
    
    // loop through ghost_bufs, prepost Irecv's
#ifdef _MPI
    
    for(recvBox=0;recvBox<domain->numsubdomains;recvBox++){
      for(n=0;n<27;n++)if(exchange[n]){
	  sendBox = domain->subdomains[recvBox].neighbors[n].local_index;
	  if(domain->subdomains[recvBox].neighbors[n].rank != domain->rank){  
	    int tag = (sendBox<<8) | (26-n); // I receive a message with the box ID and direction ID of my neighbor from my neighbor
	    MPI_Irecv(domain->subdomains[recvBox].levels[level].ghost_bufs[n],
		      domain->subdomains[recvBox].levels[level].bufsizes[n],MPI_DOUBLE,
		      domain->subdomains[recvBox].neighbors[n].rank,tag,MPI_COMM_WORLD,
		      &requests[nMessages++]);
	  }
	}}
#endif


#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeEnd = CycleTime();
    domain->cycles.recv[level] += (_timeEnd-_timeStart);
#endif

     
    // extract surface, pack into surface_bufs
    _timeStart = CycleTime();
//#pragma omp parallel for private(sendBox)
//    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){__box_grid_to_surface_bufs(&domain->subdomains[sendBox].levels[level],grid_id);}


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

    
    // local boundary exchanges...
//#pragma omp parallel for private(n,sendBox,recvBox)
//    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
//      for(n=0;n<27;n++)if(exchange[n]){
//        recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
//        if(domain->subdomains[sendBox].neighbors[n].rank == domain->rank){
//            buffer_copy(domain->subdomains[recvBox].levels[level].ghost_bufs[26-n],
//                domain->subdomains[sendBox].levels[level].surface_bufs[n],
//                domain->subdomains[sendBox].levels[level].bufsizes[n], (level==0) );
//        }
//      }
//    }

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
    
    // loop through surface_bufs, post Isend's -or- copy (surface to ghost)

#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeStart = CycleTime();
#endif

#if defined(_UPCR) || defined(_UPC)  
#if defined(_BARRIER_SYNC)
    upcr_notify(0,0);
    upcr_wait(0,0);
#endif
#endif


#ifdef _MPI
    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
      for(n=0;n<27;n++)if(exchange[n]){
	  recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
	  if(domain->subdomains[sendBox].neighbors[n].rank != domain->rank){
	    int tag = (sendBox<<8) | (n); // I send a message tagged with my ID and direction to my neighbor
	    MPI_Isend(domain->subdomains[sendBox].levels[level].surface_bufs[n],
                domain->subdomains[sendBox].levels[level].bufsizes[n],MPI_DOUBLE,
		      domain->subdomains[sendBox].neighbors[n].rank,tag,MPI_COMM_WORLD,
		      &requests[nMessages++]);
	  }
	}}
#endif


#ifdef THOR_ENABLED
    //thor_windup_comm();
#endif

#if defined(_UPCR) || defined(_UPC)  
    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
      for(n=0;n<27;n++)if(exchange[n]){
	  recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
	  if(domain->subdomains[sendBox].neighbors[n].rank != domain->rank){
#ifdef PC_NO_DB
	    if(!wait_empty[n]) {
	      bupc_sem_waitN(domain->empty_bit[n],1);
	      wait_empty[n] = 1;
	    }
#endif
            //int stemp;
            //printf("sendbox %d surface_buf %d: ", sendBox, n);
            //for(stemp = 0; stemp < domain->subdomains[sendBox].levels[level].bufsizes[n]; ++stemp) {
            //    printf("%f ", domain->subdomains[sendBox].levels[level].surface_bufs[n][stemp]);    
            //}
            //printf("\n");


#ifdef _UPCR
        size_t msgsize = domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double);
        size_t remote_thread = upcr_threadof_shared(upcr_pshared_to_shared(domain->subdomains[sendBox].levels[level].surface_bufs_sh[n]));
        if(msgsize <= 8192) {
	        printf("%d: XPUT %d -> %d %s\n", upcr_mythread(),  domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double), remote_thread, upcr_mythread()==remote_thread ? "LOCAL" : "");
            xrequests[xnMessages++] = xbupc_memput_async(upcr_pshared_to_shared(domain->subdomains[sendBox].levels[level].surface_bufs_sh[n]),
                                domain->subdomains[sendBox].levels[level].surface_bufs[n],
                                domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double));
        } else {
	        printf("%d: PUT %d -> %d %s\n", upcr_mythread(),  domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double), remote_thread, upcr_mythread()==remote_thread ? "LOCAL" : "");
            requests[nMessages++] = bupc_memput_async(upcr_pshared_to_shared(domain->subdomains[sendBox].levels[level].surface_bufs_sh[n]),
                                domain->subdomains[sendBox].levels[level].surface_bufs[n],
                                domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double));
        }
#else
        size_t msgsize = domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double);
        size_t remote_thread =  upc_threadof((shared void*)domain->subdomains[sendBox].levels[level].surface_bufs_sh[n]);
        if(msgsize <= 8192) {
	        printf("%d: XPUT %d -> %d %s\n", upcr_mythread(),  domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double), remote_thread, upcr_mythread()==remote_thread ? "LOCAL" : "");
            xrequests[xnMessages++] = xbupc_memput_async(
                                (shared void*)domain->subdomains[sendBox].levels[level].surface_bufs_sh[n],
                                domain->subdomains[sendBox].levels[level].surface_bufs[n],
                                domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double));
        } else {
	        printf("%d: PUT %d -> %d %s\n", upcr_mythread(),  domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double), remote_thread, upcr_mythread()==remote_thread ? "LOCAL" : "");
            requests[nMessages++] = bupc_memput_async(
                                (shared void*)domain->subdomains[sendBox].levels[level].surface_bufs_sh[n],
                                domain->subdomains[sendBox].levels[level].surface_bufs[n],
                                domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double));
        }
#endif

    _timeEnd = CycleTime();
    domain->cycles.send[level] += (_timeEnd-_timeStart);
    
#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeStart = CycleTime();
#endif
	  }
	}}
#endif


#ifdef _MPI
    MPI_Waitall(nMessages,requests,status);
#endif
#if defined(_UPC) || defined(_UPCR)
    if(nMessages > 0 || xnMessages > 0) {
    if(xnMessages) {
      //wait for the puts to complete
      printf("%d: XWAIT ON  %d\n", upcr_mythread(),  xnMessages);
      xbupc_waitsync_all(xrequests, xnMessages);
      if(xnMessages > MAX_MESG) {
	printf("Error .. too many mesgs in flight at %d!\n", upcr_mythread());
	upcr_global_exit(1);
      }
    }
    if(nMessages) {
      //wait for the puts to complete
      printf("%d: WAIT ON  %d\n", upcr_mythread(),  nMessages);
      bupc_waitsync_all(requests, nMessages);
      if(nMessages > MAX_MESG) {
	printf("Error .. too many mesgs in flight at %d!\n", upcr_mythread());
	upcr_global_exit(1);
      } 
    }
#if defined(PC_NO_DB) || defined(PC_DB)
    //signal the puts
    for(n=0;n<27;n++)
      if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ) {
	bupc_sem_postN(domain->signal_full[n],1);
      }
#endif
    }
#endif
#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeEnd = CycleTime();
    domain->cycles.wait[level] += (_timeEnd-_timeStart); 
#endif  
    
#ifdef THOR_ENABLED
    //thor_winddown_comm();
#endif

#if defined(_UPC) || defined(_UPCR) 
#if defined(PC_NO_DB) || defined(PC_DB)
  for(n=0;n<27;n++)
    if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){
      bupc_sem_waitN(domain->full_bit[n],1);     
    }
#endif
   
#if defined(_BARRIER_SYNC)
    upcr_notify(0,0);
    upcr_wait(0,0);
#endif
  
#endif

    //for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
    //  for(n=0;n<27;n++)if(exchange[n]){
    //        int stemp;
    //        printf("AFTER PUT sendbox %d surface_buf %d: ", sendBox, n);
    //        for(stemp = 0; stemp < domain->subdomains[sendBox].levels[level].bufsizes[n]; ++stemp) {
    //            printf("%f ", domain->subdomains[sendBox].levels[level].surface_bufs[n][stemp]);    
    //        }
    //        printf("\n");
    //  }
    //}
    //for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
    //  for(n=0;n<27;n++)if(exchange[n]){
    //        int stemp;
    //        printf("AFTER PUT sendbox %d ghost_buf %d: ", sendBox, n);
    //        for(stemp = 0; stemp < domain->subdomains[sendBox].levels[level].bufsizes[n]; ++stemp) {
    //            printf("%f ", domain->subdomains[sendBox].levels[level].ghost_bufs[n][stemp]);    
    //        }
    //        printf("\n");
    //  }
    //}
    
    // unpack ghost_bufs, insert into grid
    _timeStart = CycleTime();
//#pragma omp parallel for private(recvBox)
    //for(recvBox=0;recvBox<domain->numsubdomains;recvBox++){__box_ghost_bufs_to_grid(&domain->subdomains[recvBox].levels[level],grid_id);}
    

    test = domain->numsubdomains;
#pragma omp parallel for private(n,recvBox) collapse(2)
    for(recvBox=0;recvBox < test;recvBox++){
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
   
#if defined(_UPC) || defined(_UPCR)
#ifdef PC_NO_DB
    for(n=0;n<27;n++)
      if(exchange[n] && (domain->rank_of_neighbor[n] != domain->rank) ){     
	//print_sem("POST-EMPTY", domain->signal_empty[n],n,1);
	bupc_sem_postN(domain->signal_empty[n],1);
      }
#endif
     
#if defined(_BARRIER_SYNC)
    upcr_notify(0,0); // OK
    upcr_wait(0,0);
#endif
    
#endif	
    



 
#ifdef _MPI
    free(requests);
    free(status  );
#endif

// DON'T DOUBLE-COUNT    
//    domain->cycles.communication[level] += (uint64_t)(CycleTime()-_timeCommunicationStart);
}
