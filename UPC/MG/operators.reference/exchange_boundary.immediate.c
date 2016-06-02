//------------------------------------------------------------------------------------------------------------------------------
// Samuel Williams
// SWWilliams@lbl.gov
// Lawrence Berkeley National Lab
//------------------------------------------------------------------------------------------------------------------------------
#include <stdint.h>
#include "../timer.h"
//------------------------------------------------------------------------------------------------------------------------------
// Exchange boundaries by having all boxes indivudually send/recv
//------------------------------------------------------------------------------------------------------------------------------
void exchange_boundary(domain_type *domain, int level, int grid_id, int exchange_faces, int exchange_edges, int exchange_corners){
  uint64_t _timeCommunicationStart = CycleTime();
  uint64_t _timeStart,_timeEnd;
  int sendBox,recvBox,n;
  int    faces[27] = {0,0,0,0,1,0,0,0,0,  0,1,0,1,0,1,0,1,0,  0,0,0,0,1,0,0,0,0};
  int    edges[27] = {0,1,0,1,0,1,0,1,0,  1,0,1,0,0,0,1,0,1,  0,1,0,1,0,1,0,1,0};
  int  corners[27] = {1,0,1,0,0,0,1,0,1,  0,0,0,0,0,0,0,0,0,  1,0,1,0,0,0,1,0,1};
  int exchange[27] = {0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0,  0,0,0,0,0,0,0,0,0};

  for(n=0;n<27;n++){
    if(                       exchange_faces   )exchange[n] |=   faces[n];
    if( (domain->ghosts>1) && exchange_edges   )exchange[n] |=   edges[n];
    if( (domain->ghosts>1) && exchange_corners )exchange[n] |= corners[n];
  }

#if defined(_UPCR) || defined(_UPC)
  bupc_handle_t requests[1024];
  int nMessages=0;
#endif

#if defined(_UPC) || defined(_UPCR)
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
#pragma omp parallel for private(sendBox)
    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){__box_grid_to_surface_bufs(&domain->subdomains[sendBox].levels[level],grid_id);}
    _timeEnd = CycleTime();
    domain->cycles.s2buf[level] += (_timeEnd-_timeStart);
    
    
    // local boundary exchanges...
    _timeStart = CycleTime();
#pragma omp parallel for private(n,sendBox,recvBox)
    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
      for(n=0;n<27;n++)if(exchange[n]){
    recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
    if(domain->subdomains[sendBox].neighbors[n].rank == domain->rank){
      buffer_copy(domain->subdomains[recvBox].levels[level].ghost_bufs[26-n],
                  domain->subdomains[sendBox].levels[level].surface_bufs[n],
                  domain->subdomains[sendBox].levels[level].bufsizes[n], (level==0) );
    }
    //else{
    // Costin, ideally one would use a one-sided put to copy directly to the ghost_buf on the remote node
    //}
	}}
    _timeEnd = CycleTime();
    domain->cycles.bufcopy[level] += (_timeEnd-_timeStart);
    
    
    // loop through surface_bufs, post Isend's -or- copy (surface to ghost)

#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeStart = CycleTime();
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

#ifdef _UPCR 
    for(sendBox=0;sendBox<domain->numsubdomains;sendBox++){
      for(n=0;n<27;n++)if(exchange[n]){
	  recvBox = domain->subdomains[sendBox].neighbors[n].local_index;
	  if(domain->subdomains[sendBox].neighbors[n].rank != domain->rank){
	    requests[nMessages++] = bupc_memput_async(upcr_pshared_to_shared(domain->subdomains[sendBox].levels[level].surface_bufs_sh[n]),
						      domain->subdomains[sendBox].levels[level].surface_bufs[n],
						      domain->subdomains[sendBox].levels[level].bufsizes[n]*sizeof(double));
	  }
	}}
#endif

#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeEnd = CycleTime();
    domain->cycles.send[level] += (_timeEnd-_timeStart);
    _timeStart = CycleTime();
#endif

    
#ifdef _MPI
    MPI_Waitall(nMessages,requests,status);
#endif
  

#if defined(_UPC) || defined(_UPCR)
    if(nMessages) {
      //wait for the puts to complete
      bupc_waitsync_all(requests, nMessages);
      if(nMessages > 1024) {
	printf("Error .. too many mesgs in flight at %d!\n", upcr_mythread());
	upcr_global_exit(1);
      }
    }
#endif

#if defined(_MPI) || defined(_UPC) || defined(_UPCR)
    _timeEnd = CycleTime();
    domain->cycles.wait[level] += (_timeEnd-_timeStart); 
#endif  
    
#if defined(_UPC) || defined(_UPCR)
#if defined(_BARRIER_SYNC)
    upcr_notify(0,0);
    upcr_wait(0,0);
#endif
#endif

    
    // unpack ghost_bufs, insert into grid
    _timeStart = CycleTime();
#pragma omp parallel for private(recvBox)
    for(recvBox=0;recvBox<domain->numsubdomains;recvBox++){__box_ghost_bufs_to_grid(&domain->subdomains[recvBox].levels[level],grid_id);}
    _timeEnd = CycleTime();
    domain->cycles.buf2g[level] += (_timeEnd-_timeStart);
    
#ifdef _MPI
    free(requests);
    free(status  );
#endif
    
    domain->cycles.communication[level] += (uint64_t)(CycleTime()-_timeCommunicationStart);
}
