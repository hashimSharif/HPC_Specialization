double __box_norm_of_grid(box_type *box, int grid_id){
  double rv = 0.0;
  int i,j,k;
  double * __restrict__ grid = box->grids[grid_id];
  for(k=0;k<box->dim.k;k++){
   for(j=0;j<box->dim.j;j++){
    for(i=0;i<box->dim.i;i++){
      int ijk = (i+box->ghosts) + (j+box->ghosts)*box->pencil + (k+box->ghosts)*box->plane;
      double fabs_grid_ijk = fabs(grid[ijk]);
      if(fabs_grid_ijk>rv){rv=fabs_grid_ijk;} // max norm
  }}}
  return(rv);
}


double norm_of_residual(domain_type * domain, int level, int phi_id, int rhs_id, double a, double b, double hLevel){
  double        max_norm =  0.0;
  int box;

  exchange_boundary(domain,level,phi_id,1,0,0); // technically only needs to be a 1-deep ghost zone & faces only
  #pragma omp parallel for private(box)
  for(box=0;box<domain->numsubdomains;box++){
    __box_residual(&domain->subdomains[box].levels[level],__temp,phi_id,rhs_id,a,b,hLevel);
  }

  #pragma omp parallel for private(box)
  for(box=0;box<domain->numsubdomains;box++){
    double box_norm = __box_norm_of_grid(&domain->subdomains[box].levels[level],__temp);
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

