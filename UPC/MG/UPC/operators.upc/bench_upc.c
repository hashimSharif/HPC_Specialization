//#include <stdio.h>
#include <string.h>
#include "timer.h"
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"

extern struct _IO_FILE *stderr;         /* Standard error output stream.  */


#ifdef _UPC
#include "upc.h"
#include <bupc_extensions.h>
shared sh_domain_type_p domain_1_sh[THREADS];
shared sh_domain_type_p domain_CA_sh[THREADS];
#ifndef _MY_GUPC
shared void *upcr_pshared_to_shared(shared [] double*);
#endif
#endif

#ifdef __UPCR
#error Not implemented ...
#ifdef _UPC
#error DDs
#endif
#include "supcr.h"
upcr_pshared_ptr_t domain_1_sh;
upcr_pshared_ptr_t domain_CA_sh;
#endif



shared void* upc_alloc_aligned(size_t size, size_t align) 
{
  shared []  char* res;
  char *lres;
  uint64_t disp;
  res = (shared [] char*)upc_alloc(size+align);
  lres = (char*)res;
  disp = (uint64_t)lres;
  disp = disp + (64 - disp%align);
  if(disp%64) {
    printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
  }
  res = res+disp;
  return (shared void*)res;
  
}
extern int  do_print;


bupc_sem_t *tmp_full[27];
bupc_sem_t *tmp_empty[27];
shared [] double *tmp_recv[27];

char lbuf[1024];

shared [] char* add_disp(shared [] char* base, int elems)
{
  // printf("%d: Adding remote  displacement %d \n ", MYTHREAD, elems);
  return base+elems;;
}


void print_domain_layout(shared sh_domain_type_p *Ds) {
#ifndef _MY_GUPC
  int n,th;
  if(MYTHREAD == 0) {
    for (th = 0; th < THREADS; th++) {
      for(n = 0; n < 27; n++) {
  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->recv_buffer_sh[n]), lbuf, 1024);
  fprintf(stderr,"%d : RECEIVE BUFFER AT %d   %s\n", th, n, lbuf);

  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->remote_recv_buffer[n]), lbuf, 1024);
  fprintf(stderr,"%d : REMOTE RECEIVE BUFFER AT %d  %s\n", th, n, lbuf);

  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->empty_bit[n]), lbuf, 1024);
  fprintf(stderr,"%d : EMPTY BIT  AT %d  %s\n", th, n, lbuf);

  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->signal_empty[n]), lbuf, 1024);
  fprintf(stderr, "%d : SIGNAL EMPTY  BIT  AT %d   %s\n", th, n, lbuf);

  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->full_bit[n]), lbuf, 1024);
  fprintf(stderr, "%d : FULL  BIT  AT %d  %s\n", th, n, lbuf);

  upcri_dump_shared(upcr_pshared_to_shared(Ds[th]->signal_full[n]), lbuf, 1024);
  fprintf(stderr, "%d : SIGNAL FULL  BIT  AT %d   %s\n", th, n, lbuf);

      }
    }
  }
#endif
}

#ifdef _UPC

#ifdef NO_PACK

void init_box_levels(subdomain_type *box, int NL) {
  
  box->levels_sh = (shared [] box_type *)upc_alloc(sizeof(box_type)*NL);
  box->levels = (box_type*) box->levels_sh;
  
  char dump[256];
  bupc_dump_shared((shared void*)box->levels_sh, dump, 255);
  //printf("%d: BOXBOX %p at %s\n", MYTHREAD, box->levels, dump);
  
}



void init_subdomains( domain_type *d, int SD) 
{
  d->subdomains_sh= (sh_subdomain_type_p)upc_alloc(sizeof(subdomain_type)*SD);
  d->subdomains = (subdomain_type*)d->subdomains_sh;
  
    char dump[255];
    bupc_dump_shared((shared void*)d->subdomains_sh, dump, 255);
    //printf("%d : SUBDOMAIN %s\n",MYTHREAD,  dump);
  
}


void set_ghost_bufs(box_type *box) {
  double *base;
  int n;
  size_t disp;
  base=box->surface_bufs[0];
  for(n=0;n<27;n++){
    box->surface_bufs[n]=base;
    base+=box->bufsizes[n];
  }
  
  base=  box->ghost_bufs[0];
  disp = 0;
  for(n=0;n<27;n++){  
    box->ghost_bufs[n]=base;
    box->ghost_bufs_sh[n] = box->ghost_bufs_sh[0]+disp;
    base+=box->bufsizes[n];
    disp += box->bufsizes[n];
    
      char dump[256];
      bupc_dump_shared((shared void*)box->ghost_bufs_sh[n],dump, 255);
      //if(MYTHREAD == 1)
      //printf("%d: Setting GB %s at %d\n", MYTHREAD, dump, n);
    
  }
}
#endif

//domain_type *init_domain(shared sh_domain_type_p *dom) {
domain_type *init_domain(int which) {
  shared sh_domain_type_p *dom = which ? domain_1_sh : domain_CA_sh;
  domain_type *result;

  if(!dom) {
    printf("Ooops!\n");
    upc_global_exit(1);
  }
  
  dom[MYTHREAD] =  (sh_domain_type_p) upc_alloc(sizeof(domain_type));
  result = (domain_type*)dom[MYTHREAD];
  if(!result) {
    printf("Null domain ...\n");
    upc_global_exit(1);
  }
  return result;
}

#ifdef NO_PACK

void print_all_box_ptrs(box_type *bp) {
  int level, n,  box, NL;
  char dump[256];
 
  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  for(n=0;  n < 27; n++) {
    bupc_dump_shared((shared void*)bp->ghost_bufs_sh[n], dump, 255);
    printf("%d: BOXLEV %p Assigning  at %d: %s\n", MYTHREAD, bp, n,dump);
  }
  printf("==================================================================\n");
}

#endif

void print_all_domain_ptrs(domain_type *local_d) {
  int level, n,  box, NL;
  shared [] subdomain_type *sdp;
  shared [] box_type *bp;
  char dump[256];
 
  for(box=0; box < local_d->numsubdomains; box++) {
    NL = local_d->subdomains[box].numLevels;
#ifdef NO_PACK    
    sdp = local_d->subdomains_sh+box;
    bupc_dump_shared((shared void* )sdp, dump, 255);
    printf("%d: INITIAL Subdomain in %d at %d %s\n", MYTHREAD, 100, box, dump);

    for(level = 0; level < NL; level++) {
	bp = sdp->levels_sh+level;
	bupc_dump_shared((shared void *)bp, dump, 255);
	printf("%d: INITIAL Box in %d at %d  level %d %s\n", MYTHREAD, 100, box, level, dump);
      for(n=0;  n < 27; n++) {
        bupc_dump_shared((shared void*)the_saddest_hack(bp,n), dump, 255);
        printf("%d: INITIAL Assigning  dom  %d, level %d at %d: %s\n", MYTHREAD, box,level,n,dump);
      }
    }
#endif
  }  

  printf("==================================================================\n");

}




//void exchange_global_buffer_info(shared sh_domain_type_p *Ds) {
void exchange_global_buffer_info(int which) {
  shared sh_domain_type_p *Ds = which ? domain_1_sh : domain_CA_sh;
  int n,tmp;  
  int remote_d;
  sh_domain_type_p target_d;
  domain_type *local_d;
  int box,level, NL;
  shared [] char* base;
  
#if 1
  upc_barrier;
#endif

 

#ifdef NO_PACK
  shared [] subdomain_type *sdp;
  shared [] box_type *bp;
  local_d = (domain_type*)Ds[MYTHREAD];
  for(box=0; box < local_d->numsubdomains; box++) {
    NL = local_d->subdomains[box].numLevels;
    for(level = 0; level < NL; level++) {
      for(n=0;  n < 27; n++) {
	char dump[256];
	tmp = local_d->subdomains[box].neighbors[n].rank;
	//Ds[tmp]->subdomains_sh[box]->levels_sh[level]->ghost_bufs[n];
	target_d = Ds[tmp];
	sdp = target_d->subdomains_sh+box;
	bp = sdp->levels_sh+level; 
	local_d->subdomains[box].levels[level].surface_bufs_sh[n] = the_saddest_hack(bp,26-n);
	//local_d->subdomains[box].levels[level].surface_bufs_sh[n] = Ds[tmp]->subdomains_sh[box].levels_sh[level].ghost_bufs_sh[26-n];
      }
    }
  }

  for(n=0; n<27; n++){
   int  tmp = 26 -n;
    Ds[MYTHREAD]->signal_empty[n] =  Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->empty_bit[tmp];
    Ds[MYTHREAD]->signal_full[n] =  Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->full_bit[tmp];  
  }
  
#else 
  for(n=0; n<27; n++){
    int tmp = 26 -n;
#ifdef _USE_GET
    Ds[MYTHREAD]->remote_recv_buffer[n] = Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->send_buffer_sh[tmp];
#else
    Ds[MYTHREAD]->remote_recv_buffer[n] = Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->recv_buffer_sh[tmp];
#endif
    Ds[MYTHREAD]->signal_empty[n] =  Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->empty_bit[tmp];
    Ds[MYTHREAD]->signal_full[n] =  Ds[Ds[MYTHREAD]->rank_of_neighbor[n]]->full_bit[tmp];  
    //fprintf(stderr, "%d: MAPPING  %d WITH %d AT %d \n", MYTHREAD, n, Ds[MYTHREAD]->rank_of_neighbor[n], tmp); 
  }
#endif

  /*
    //exposed compiler bug...
  local_d = Ds[MYTHREAD];
  for(n=0; n < 27; n++) {
    tmp = 26-n;
    target_d = Ds[local_d->rank_of_neighbor[n]];
    local_d->remote_recv_buffer[n] = target_d->recv_buffer_sh[tmp];
    local_d->signal_empty[n] =  target_d->empty_bit[tmp];
    local_d->signal_full[n] =  target_d->full_bit[tmp];
  }
  
  */
#if  1
  //upc_barrier;
  if(do_print)
    print_domain_layout(Ds);
  upc_barrier;
#endif    
  
}

#if _UPC 
shared [] int* my_bupc_sem_alloc(int);
void my_bupc_sem_postN(shared [] int*, int);
#else 
upcr_pshared_ptr_t  my_bupc_sem_alloc(int);
void my_bupc_sem_postN(upcr_pshared_ptr_t, int);
#endif


void init_domain_srcv(domain_type *domain, int n, int size)
{
  
#ifdef PC_DB
  //printf("%d: Allocating %d at %d\n", MYTHREAD, size, n);
  domain->recv_buffer_size[n] = size;
  size = size*2;
#endif

  domain->send_buffer_sh[n] = (shared [] double*)upc_alloc(size);
  domain->recv_buffer_sh[n] = (shared [] double*)upc_alloc(size);
#ifdef _UPC_OUTSEG
  domain->send_buffer[n] = (double *)malloc(size);
#else
 domain->send_buffer[n] = (double *)domain->send_buffer_sh[n]; 
#endif 
  domain->recv_buffer[n] = (double *)domain->recv_buffer_sh[n];
  if(!domain->recv_buffer_sh[n] || !domain->send_buffer_sh[n]) {
    printf("Error allocating UPC memory...\n");
    upc_global_exit(1);
  }
  
  if(!domain->send_buffer[n] || !domain->recv_buffer[n]) {
    printf("Error casting to local buffer ...\n");
    upc_global_exit(1);
  }
  
#ifndef _BARRIER_SYNC
  domain->full_bit[n] = bupc_sem_alloc(BUPC_SEM_INTEGER|BUPC_SEM_SCONSUMER|BUPC_SEM_SPRODUCER);
  /* this is the empty sempahore */
  domain->empty_bit[n] = bupc_sem_alloc(BUPC_SEM_INTEGER|BUPC_SEM_SCONSUMER|BUPC_SEM_SPRODUCER);
  bupc_sem_postN(domain->empty_bit[n],1);
  if (domain->full_bit[n] == NULL || domain->empty_bit[n] == NULL ) {
     printf("Error allocating UPC semaphores ...\n");
     upc_global_exit(1);
  }
#endif   
  

#if 0
  printf("%d Initializing domain %d = %d\n", MYTHREAD, n, size);
#endif
}
#endif
 
