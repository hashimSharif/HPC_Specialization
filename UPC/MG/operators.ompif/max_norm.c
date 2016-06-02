//===========================================================================================================================
double norm_of_residual(domain_type * domain, int level, int phi_id, int rhs_id, double a, double b, double h){
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    #warning using Collaborative Threading for large boxes in norm()
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int omp_across_boxes = (domain->subdomains[0].levels[level].dim.i <  CollaborativeThreadingBoxSize);
  int omp_within_a_box = (domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize);


  exchange_boundary(domain,level,phi_id,1,0,0); // technically only needs to be a 1-deep ghost zone & faces only

  int box;
  double max_norm =  0.0;
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
    double * __restrict__ res    = domain->subdomains[box].levels[level].grids[__temp  ] + ghosts*plane + ghosts*pencil + ghosts;

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


    double box_norm = 0.0;
    #pragma omp parallel for private(i,j,k) if(omp_within_a_box) collapse(2) reduction(max:box_norm)
    for(k=0;k<dim_k;k++){
    for(j=0;j<dim_j;j++){
    for(i=0;i<dim_i;i++){
      int ijk = i + j*pencil + k*plane;
      double fabs_grid_ijk = fabs(res[ijk]);
      if(fabs_grid_ijk>box_norm){box_norm=fabs_grid_ijk;} // max norm
    }}}

    #pragma omp critical
    {
      if(box_norm>max_norm){max_norm = box_norm;}
    }

  }


  #ifdef _MPI
  double send = max_norm;
  MPI_Allreduce(&send,&max_norm,1,MPI_DOUBLE,MPI_MAX,MPI_COMM_WORLD);
  #endif
  return(max_norm);
}

