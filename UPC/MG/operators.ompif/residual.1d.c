//------------------------------------------------------------------------------------------------------------------------------
void residual(domain_type * domain, int level,  int res_id, int phi_id, int rhs_id, double a, double b, double h){
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    #warning using Collaborative Threading for large boxes in residual()
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->numsubdomains;box++){
    int i,j,k;
    int pencil = domain->subdomains[box].levels[level].pencil;
    int  plane = domain->subdomains[box].levels[level].plane;
    int ghosts = domain->subdomains[box].levels[level].ghosts;
    int  dim_k = domain->subdomains[box].levels[level].dim.k;
    int  dim_j = domain->subdomains[box].levels[level].dim.j;
    int  dim_i = domain->subdomains[box].levels[level].dim.i;
    double h2inv = 1.0/(h*h);
    double * __restrict__ phi    = domain->subdomains[box].levels[level].grids[  phi_id] + ghosts*plane + ghosts*pencil + ghosts; // i.e. [0] = first non ghost zone point
    double * __restrict__ rhs    = domain->subdomains[box].levels[level].grids[  rhs_id] + ghosts*plane + ghosts*pencil + ghosts;
    double * __restrict__ alpha  = domain->subdomains[box].levels[level].grids[__alpha ] + ghosts*plane + ghosts*pencil + ghosts;
    double * __restrict__ beta_i = domain->subdomains[box].levels[level].grids[__beta_i] + ghosts*plane + ghosts*pencil + ghosts;
    double * __restrict__ beta_j = domain->subdomains[box].levels[level].grids[__beta_j] + ghosts*plane + ghosts*pencil + ghosts;
    double * __restrict__ beta_k = domain->subdomains[box].levels[level].grids[__beta_k] + ghosts*plane + ghosts*pencil + ghosts;
    double * __restrict__ res    = domain->subdomains[box].levels[level].grids[  res_id] + ghosts*plane + ghosts*pencil + ghosts;

    #pragma omp parallel for private(k,j,i) if(omp_within_a_box) collapse(2)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      double helmholtz =  a*alpha[ijk]*phi[ijk]
                         -b*h2inv*(
                            beta_i[ijk+1     ]*( phi[ijk+1     ]-phi[ijk       ] )
                           -beta_i[ijk       ]*( phi[ijk       ]-phi[ijk-1     ] )
                           +beta_j[ijk+pencil]*( phi[ijk+pencil]-phi[ijk       ] )
                           -beta_j[ijk       ]*( phi[ijk       ]-phi[ijk-pencil] )
                           +beta_k[ijk+plane ]*( phi[ijk+plane ]-phi[ijk       ] )
                           -beta_k[ijk       ]*( phi[ijk       ]-phi[ijk-plane ] )
                          );
      res[ijk] = rhs[ijk]-helmholtz;
    }}}
  }
}

//------------------------------------------------------------------------------------------------------------------------------
void residual_and_restriction(domain_type *domain, int level_f, int phi_id, int rhs_id, int level_c, int res_id, double a, double b, double h){
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    #warning using Collaborative Threading for large boxes in residual()
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level_f].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level_f].dim.i >= CollaborativeThreadingBoxSize);
  int box;

  #pragma omp parallel for private(box) if(omp_across_boxes)
  for(box=0;box<domain->numsubdomains;box++){
    int i,j,k,kk;
    int pencil_c = domain->subdomains[box].levels[level_c].pencil;
    int  plane_c = domain->subdomains[box].levels[level_c].plane;
    int ghosts_c = domain->subdomains[box].levels[level_c].ghosts;

    int pencil_f = domain->subdomains[box].levels[level_f].pencil;
    int  plane_f = domain->subdomains[box].levels[level_f].plane;
    int ghosts_f = domain->subdomains[box].levels[level_f].ghosts;
    int  dim_k_f = domain->subdomains[box].levels[level_f].dim.k;
    int  dim_j_f = domain->subdomains[box].levels[level_f].dim.j;
    int  dim_i_f = domain->subdomains[box].levels[level_f].dim.i;

    double h2inv = 1.0/(h*h);
    double * __restrict__ phi    = domain->subdomains[box].levels[level_f].grids[  phi_id] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f; // i.e. [0] = first non ghost zone point
    double * __restrict__ rhs    = domain->subdomains[box].levels[level_f].grids[  rhs_id] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    double * __restrict__ alpha  = domain->subdomains[box].levels[level_f].grids[__alpha ] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    double * __restrict__ beta_i = domain->subdomains[box].levels[level_f].grids[__beta_i] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    double * __restrict__ beta_j = domain->subdomains[box].levels[level_f].grids[__beta_j] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    double * __restrict__ beta_k = domain->subdomains[box].levels[level_f].grids[__beta_k] + ghosts_f*plane_f + ghosts_f*pencil_f + ghosts_f;
    double * __restrict__ res    = domain->subdomains[box].levels[level_c].grids[  res_id] + ghosts_c*plane_c + ghosts_c*pencil_c + ghosts_c;

    #pragma omp parallel for private(kk,k,j,i) if(omp_within_a_box)
    for(kk=0;kk<dim_k_f;kk+=2){
    for(k=kk;k<kk+2;k++){
    for(j=0;j<dim_j_f;j++){
      if( ((j&1)==0) && ((k&1)==0) ){
      for(i=0;i<dim_i_f>>1;i++){
        int ijk_c = (i   ) + (j>>1)*pencil_c + (k>>1)*plane_c;
        res[ijk_c] = 0.0;
      }}
      for(i=0;i<dim_i_f;i++){
        int ijk_f = (i   ) + (j   )*pencil_f + (k   )*plane_f;
        int ijk_c = (i>>1) + (j>>1)*pencil_c + (k>>1)*plane_c;
        double helmholtz =  a*alpha[ijk_f]*phi[ijk_f]
                           -b*h2inv*(
                              beta_i[ijk_f+1       ]*( phi[ijk_f+1       ]-phi[ijk_f         ] )
                             -beta_i[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-1       ] )
                             +beta_j[ijk_f+pencil_f]*( phi[ijk_f+pencil_f]-phi[ijk_f         ] )
                             -beta_j[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-pencil_f] )
                             +beta_k[ijk_f+plane_f ]*( phi[ijk_f+plane_f ]-phi[ijk_f         ] )
                             -beta_k[ijk_f         ]*( phi[ijk_f         ]-phi[ijk_f-plane_f ] )
                            );
        res[ijk_c] += (rhs[ijk_f]-helmholtz)*0.125;
      }
    }}}
  }
}

//------------------------------------------------------------------------------------------------------------------------------
