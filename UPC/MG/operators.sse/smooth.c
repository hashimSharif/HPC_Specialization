//==================================================================================================
void __box_smooth_GSRB_multiple(box_type *box, int phi_id, int rhs_id, double a, double b, double h, int sweep){
  int pencil = box->pencil;
  int plane = box->plane;
  int ghosts = box->ghosts;
  int DimI = box->dim.i;
  int DimJ = box->dim.j;
  int DimK = box->dim.k;
  double h2inv = 1.0/(h*h);
  double * __restrict__ phi    = box->grids[  phi_id] + ghosts*plane;
  double * __restrict__ rhs    = box->grids[  rhs_id] + ghosts*plane;
  double * __restrict__ alpha  = box->grids[__alpha ] + ghosts*plane;
  double * __restrict__ beta_i = box->grids[__beta_i] + ghosts*plane;
  double * __restrict__ beta_j = box->grids[__beta_j] + ghosts*plane;
  double * __restrict__ beta_k = box->grids[__beta_k] + ghosts*plane;
  double * __restrict__ lambda = box->grids[__lambda] + ghosts*plane;
  {
    int ij_start =                (                       pencil+1)&~1;
    int ij_end    = ij_start+8*((((ghosts+DimJ+ghosts-1)*pencil-1)-ij_start+8-1)/8);
    #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
    double * __restrict__ Prefetch_Pointers[7];
    Prefetch_Pointers[0] =    phi + plane-pencil;
    Prefetch_Pointers[1] = beta_k + plane;
    Prefetch_Pointers[2] = beta_j        ;
    Prefetch_Pointers[3] = beta_i        ;
    Prefetch_Pointers[4] =  alpha        ;
    Prefetch_Pointers[5] =    rhs        ;
    Prefetch_Pointers[6] = lambda        ;
    #endif
    int leadingK;
    int kLow  =     -(ghosts-1);
    int kHigh = DimK+(ghosts-1);
    for(leadingK=kLow;leadingK<kHigh;leadingK++){
      #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
      int prefetch_stream=0;
      int prefetch_ijk_start = ij_start + (leadingK+1)*plane;
      int prefetch_ijk_end   = ij_end   + (leadingK+1)*plane;
      int prefetch_ijk       = prefetch_ijk_start;
      #endif
      int j,k,planeInWavefront;
      for(planeInWavefront=0;planeInWavefront<ghosts;planeInWavefront++){
        #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)
                                  int prefetch_offset_for_next_plane_in_wavefront=      -plane;
        if(planeInWavefront==ghosts-1)prefetch_offset_for_next_plane_in_wavefront=ghosts*plane;
        #endif
        k=(leadingK-planeInWavefront);if((k>=kLow)&&(k<kHigh)){
        uint64_t invertMask = 0-((k^planeInWavefront^sweep^1)&0x1);
        const __m128d    invertMask2 =            _mm_loaddup_pd((double*)&invertMask);
        const __m128d       a_splat2 =            _mm_loaddup_pd(&a);
        const __m128d b_h2inv_splat2 = _mm_mul_pd(_mm_loaddup_pd(&b),_mm_loaddup_pd(&h2inv));
        int ij,kplane=k*plane;
        for(ij=ij_start;ij<ij_end;ij+=8){ // smooth a vector...
          int ijk=ij+kplane;
          #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM)
          #warning will attempt to prefetch the next plane from DRAM one component at a time
            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;
            _mm_prefetch((const char*)(_base+ 0),_MM_HINT_T1);
            _mm_prefetch((const char*)(_base+ 8),_MM_HINT_T1);
            prefetch_ijk+=14;if(prefetch_ijk>prefetch_ijk_end){prefetch_stream++;prefetch_ijk=prefetch_ijk_start;}
          #elif defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
          #warning will attempt to prefetch the next plane from DRAM interleaving prefetches by component
            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;
            _mm_prefetch((const char*)(_base+ 0),_MM_HINT_T1);
            _mm_prefetch((const char*)(_base+ 8),_MM_HINT_T1);
            prefetch_stream++;if(prefetch_stream>6){prefetch_stream=0;prefetch_ijk+=14;}
          #endif
          #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)
          #warning attempting to prefetch the next plane in the wavefront
            _mm_prefetch((const char*)(   phi+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
          #elif defined(__PREFETCH_NEXT_PENCIL_FROM_CACHE)
          #warning attempting to prefetch the next pencil
            _mm_prefetch((const char*)(   phi+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+pencil+ 0),_MM_HINT_T0);
          #elif defined(__PREFETCH_NEXT_LINE_FROM_CACHE)
          #warning attempting to prefetch the next line
            _mm_prefetch((const char*)(   phi+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+8+ 8),_MM_HINT_T0);
          #endif
          // this version performs unalligned accesses for phi+/-1, betai+1 and phi+/-pencil
          //careful... assumes the compiler maps _mm128_load_pd to unaligned vmovupd and not the aligned version (should be faster when pencil is a multiple of 2 doubles (16 bytes)
          const __m128d       phi_00 = _mm_load_pd(phi+ijk+  0);
          const __m128d       phi_02 = _mm_load_pd(phi+ijk+  2);
          const __m128d       phi_04 = _mm_load_pd(phi+ijk+  4);
          const __m128d       phi_06 = _mm_load_pd(phi+ijk+  6);
                __m128d helmholtz_00;
                __m128d helmholtz_02;
                __m128d helmholtz_04;
                __m128d helmholtz_06;
                        helmholtz_00 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        1),             phi_00           ),_mm_loadu_pd(beta_i+ijk+        1)); 
                        helmholtz_02 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        3),             phi_02           ),_mm_loadu_pd(beta_i+ijk+        3)); 
                        helmholtz_04 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        5),             phi_04           ),_mm_loadu_pd(beta_i+ijk+        5)); 
                        helmholtz_06 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        7),             phi_06           ),_mm_loadu_pd(beta_i+ijk+        7)); 
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_loadu_pd(phi+ijk+       -1)),_mm_load_pd( beta_i+ijk+        0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_loadu_pd(phi+ijk+        1)),_mm_load_pd( beta_i+ijk+        2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_loadu_pd(phi+ijk+        3)),_mm_load_pd( beta_i+ijk+        4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_loadu_pd(phi+ijk+        5)),_mm_load_pd( beta_i+ijk+        6)));
                        helmholtz_00 = _mm_add_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 0),             phi_00           ),_mm_load_pd( beta_j+ijk+pencil+ 0)));
                        helmholtz_02 = _mm_add_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 2),             phi_02           ),_mm_load_pd( beta_j+ijk+pencil+ 2)));
                        helmholtz_04 = _mm_add_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 4),             phi_04           ),_mm_load_pd( beta_j+ijk+pencil+ 4)));
                        helmholtz_06 = _mm_add_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 6),             phi_06           ),_mm_load_pd( beta_j+ijk+pencil+ 6)));
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_load_pd( phi+ijk-pencil+ 0)),_mm_load_pd( beta_j+ijk+        0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_load_pd( phi+ijk-pencil+ 2)),_mm_load_pd( beta_j+ijk+        2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_load_pd( phi+ijk-pencil+ 4)),_mm_load_pd( beta_j+ijk+        4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_load_pd( phi+ijk-pencil+ 6)),_mm_load_pd( beta_j+ijk+        6)));
                        helmholtz_00 = _mm_add_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 0),             phi_00           ),_mm_load_pd( beta_k+ijk+ plane+ 0)));
                        helmholtz_02 = _mm_add_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 2),             phi_02           ),_mm_load_pd( beta_k+ijk+ plane+ 2)));
                        helmholtz_04 = _mm_add_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 4),             phi_04           ),_mm_load_pd( beta_k+ijk+ plane+ 4)));
                        helmholtz_06 = _mm_add_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 6),             phi_06           ),_mm_load_pd( beta_k+ijk+ plane+ 6)));
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_load_pd( phi+ijk- plane+ 0)),_mm_load_pd( beta_k+ijk       + 0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_load_pd( phi+ijk- plane+ 2)),_mm_load_pd( beta_k+ijk       + 2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_load_pd( phi+ijk- plane+ 4)),_mm_load_pd( beta_k+ijk       + 4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_load_pd( phi+ijk- plane+ 6)),_mm_load_pd( beta_k+ijk       + 6)));
                        helmholtz_00 = _mm_mul_pd(helmholtz_00,b_h2inv_splat2);
                        helmholtz_02 = _mm_mul_pd(helmholtz_02,b_h2inv_splat2);
                        helmholtz_04 = _mm_mul_pd(helmholtz_04,b_h2inv_splat2);
                        helmholtz_06 = _mm_mul_pd(helmholtz_06,b_h2inv_splat2);
                        helmholtz_00 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 0)),phi_00),helmholtz_00);
                        helmholtz_02 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 2)),phi_02),helmholtz_02);
                        helmholtz_04 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 4)),phi_04),helmholtz_04);
                        helmholtz_06 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 6)),phi_06),helmholtz_06);
                __m128d       new_00 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 0),_mm_sub_pd(helmholtz_00,_mm_load_pd(rhs+ijk+ 0)));
                __m128d       new_02 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 2),_mm_sub_pd(helmholtz_02,_mm_load_pd(rhs+ijk+ 2)));
                __m128d       new_04 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 4),_mm_sub_pd(helmholtz_04,_mm_load_pd(rhs+ijk+ 4)));
                __m128d       new_06 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 6),_mm_sub_pd(helmholtz_06,_mm_load_pd(rhs+ijk+ 6)));
                              new_00 = _mm_sub_pd(phi_00,new_00);
                              new_02 = _mm_sub_pd(phi_02,new_02);
                              new_04 = _mm_sub_pd(phi_04,new_04);
                              new_06 = _mm_sub_pd(phi_06,new_06);
          const __m128d RedBlack_00 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 0) ));
          const __m128d RedBlack_02 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 2) ));
          const __m128d RedBlack_04 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 4) ));
          const __m128d RedBlack_06 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 6) ));
                        new_00  = _mm_or_pd(_mm_and_pd(RedBlack_00,new_00),_mm_andnot_pd(RedBlack_00,phi_00));
                        new_02  = _mm_or_pd(_mm_and_pd(RedBlack_02,new_02),_mm_andnot_pd(RedBlack_02,phi_02));
                        new_04  = _mm_or_pd(_mm_and_pd(RedBlack_04,new_04),_mm_andnot_pd(RedBlack_04,phi_04));
                        new_06  = _mm_or_pd(_mm_and_pd(RedBlack_06,new_06),_mm_andnot_pd(RedBlack_06,phi_06));
                                              _mm_store_pd(phi+ijk+ 0,new_00);
                                              _mm_store_pd(phi+ijk+ 2,new_02);
                                              _mm_store_pd(phi+ijk+ 4,new_04);
                                              _mm_store_pd(phi+ijk+ 6,new_06);
        }
      }}
    }
  }
}


void __box_smooth_GSRB_multiple_threaded(box_type *box, int phi_id, int rhs_id, double a, double b, double h, int sweep){
  int pencil = box->pencil;
  int plane = box->plane;
  int ghosts = box->ghosts;
  int DimI = box->dim.i;
  int DimJ = box->dim.j;
  int DimK = box->dim.k;
  double h2inv = 1.0/(h*h);
  double * __restrict__ phi    = box->grids[  phi_id] + ghosts*plane;
  double * __restrict__ rhs    = box->grids[  rhs_id] + ghosts*plane;
  double * __restrict__ alpha  = box->grids[__alpha ] + ghosts*plane;
  double * __restrict__ beta_i = box->grids[__beta_i] + ghosts*plane;
  double * __restrict__ beta_j = box->grids[__beta_j] + ghosts*plane;
  double * __restrict__ beta_k = box->grids[__beta_k] + ghosts*plane;
  double * __restrict__ lambda = box->grids[__lambda] + ghosts*plane;
  #pragma omp parallel
  {
    int id      = omp_get_thread_num();
    int threads = omp_get_num_threads();
    int global_ij_start = (                       pencil+1)&~1;
    int global_ij_end   = ((ghosts+DimJ+ghosts-1)*pencil-1);
    int TotalUnrollings = ((global_ij_end-global_ij_start+8-1)/8);
    int ij_start = global_ij_start + 8*((id  )*(TotalUnrollings)/threads);
    int ij_end   = global_ij_start + 8*((id+1)*(TotalUnrollings)/threads);
    if(id==(threads-1))ij_end = global_ij_end;
    #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
    double * __restrict__ Prefetch_Pointers[7];
    Prefetch_Pointers[0] =    phi + plane-pencil;
    Prefetch_Pointers[1] = beta_k + plane;
    Prefetch_Pointers[2] = beta_j        ;
    Prefetch_Pointers[3] = beta_i        ;
    Prefetch_Pointers[4] =  alpha        ;
    Prefetch_Pointers[5] =    rhs        ;
    Prefetch_Pointers[6] = lambda        ;
    #endif
    int leadingK;
    int kLow  =     -(ghosts-1);
    int kHigh = DimK+(ghosts-1);
    for(leadingK=kLow;leadingK<kHigh;leadingK++){
    if(ghosts>1){
      #pragma omp barrier
    }
      #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
      int prefetch_stream=0;
      int prefetch_ijk_start = ij_start + (leadingK+1)*plane;
      int prefetch_ijk_end   = ij_end   + (leadingK+1)*plane;
      int prefetch_ijk       = prefetch_ijk_start;
      #endif
      int j,k,planeInWavefront;
      for(planeInWavefront=0;planeInWavefront<ghosts;planeInWavefront++){
        #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)
                                  int prefetch_offset_for_next_plane_in_wavefront=      -plane;
        if(planeInWavefront==ghosts-1)prefetch_offset_for_next_plane_in_wavefront=ghosts*plane;
        #endif
        k=(leadingK-planeInWavefront);if((k>=kLow)&&(k<kHigh)){
        uint64_t invertMask = 0-((k^planeInWavefront^sweep^1)&0x1);
        const __m128d    invertMask2 =            _mm_loaddup_pd((double*)&invertMask);
        const __m128d       a_splat2 =            _mm_loaddup_pd(&a);
        const __m128d b_h2inv_splat2 = _mm_mul_pd(_mm_loaddup_pd(&b),_mm_loaddup_pd(&h2inv));
        int ij,kplane=k*plane;
        for(ij=ij_start;ij<ij_end;ij+=8){ // smooth a vector...
          int ijk=ij+kplane;
          #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM)
          #warning will attempt to prefetch the next plane from DRAM one component at a time
            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;
            _mm_prefetch((const char*)(_base+ 0),_MM_HINT_T1);
            _mm_prefetch((const char*)(_base+ 8),_MM_HINT_T1);
            prefetch_ijk+=14;if(prefetch_ijk>prefetch_ijk_end){prefetch_stream++;prefetch_ijk=prefetch_ijk_start;}
          #elif defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)
          #warning will attempt to prefetch the next plane from DRAM interleaving prefetches by component
            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;
            _mm_prefetch((const char*)(_base+ 0),_MM_HINT_T1);
            _mm_prefetch((const char*)(_base+ 8),_MM_HINT_T1);
            prefetch_stream++;if(prefetch_stream>6){prefetch_stream=0;prefetch_ijk+=14;}
          #endif
          #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)
          #warning attempting to prefetch the next plane in the wavefront
            _mm_prefetch((const char*)(   phi+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+prefetch_offset_for_next_plane_in_wavefront+ 0),_MM_HINT_T0);
          #elif defined(__PREFETCH_NEXT_PENCIL_FROM_CACHE)
          #warning attempting to prefetch the next pencil
            _mm_prefetch((const char*)(   phi+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+pencil+ 0),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+pencil+ 0),_MM_HINT_T0);
          #elif defined(__PREFETCH_NEXT_LINE_FROM_CACHE)
          #warning attempting to prefetch the next line
            _mm_prefetch((const char*)(   phi+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_k+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_j+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(beta_i+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)( alpha+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(lambda+ijk+8+ 8),_MM_HINT_T0);
            _mm_prefetch((const char*)(   rhs+ijk+8+ 8),_MM_HINT_T0);
          #endif
          // this version performs unalligned accesses for phi+/-1, betai+1 and phi+/-pencil
          //careful... assumes the compiler maps _mm128_load_pd to unaligned vmovupd and not the aligned version (should be faster when pencil is a multiple of 2 doubles (16 bytes)
          const __m128d       phi_00 = _mm_load_pd(phi+ijk+  0);
          const __m128d       phi_02 = _mm_load_pd(phi+ijk+  2);
          const __m128d       phi_04 = _mm_load_pd(phi+ijk+  4);
          const __m128d       phi_06 = _mm_load_pd(phi+ijk+  6);
                __m128d helmholtz_00;
                __m128d helmholtz_02;
                __m128d helmholtz_04;
                __m128d helmholtz_06;
                        helmholtz_00 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        1),             phi_00           ),_mm_loadu_pd(beta_i+ijk+        1)); 
                        helmholtz_02 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        3),             phi_02           ),_mm_loadu_pd(beta_i+ijk+        3)); 
                        helmholtz_04 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        5),             phi_04           ),_mm_loadu_pd(beta_i+ijk+        5)); 
                        helmholtz_06 =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+        7),             phi_06           ),_mm_loadu_pd(beta_i+ijk+        7)); 
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_loadu_pd(phi+ijk+       -1)),_mm_load_pd( beta_i+ijk+        0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_loadu_pd(phi+ijk+        1)),_mm_load_pd( beta_i+ijk+        2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_loadu_pd(phi+ijk+        3)),_mm_load_pd( beta_i+ijk+        4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_loadu_pd(phi+ijk+        5)),_mm_load_pd( beta_i+ijk+        6)));
                        helmholtz_00 = _mm_add_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 0),             phi_00           ),_mm_load_pd( beta_j+ijk+pencil+ 0)));
                        helmholtz_02 = _mm_add_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 2),             phi_02           ),_mm_load_pd( beta_j+ijk+pencil+ 2)));
                        helmholtz_04 = _mm_add_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 4),             phi_04           ),_mm_load_pd( beta_j+ijk+pencil+ 4)));
                        helmholtz_06 = _mm_add_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+ 6),             phi_06           ),_mm_load_pd( beta_j+ijk+pencil+ 6)));
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_load_pd( phi+ijk-pencil+ 0)),_mm_load_pd( beta_j+ijk+        0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_load_pd( phi+ijk-pencil+ 2)),_mm_load_pd( beta_j+ijk+        2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_load_pd( phi+ijk-pencil+ 4)),_mm_load_pd( beta_j+ijk+        4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_load_pd( phi+ijk-pencil+ 6)),_mm_load_pd( beta_j+ijk+        6)));
                        helmholtz_00 = _mm_add_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 0),             phi_00           ),_mm_load_pd( beta_k+ijk+ plane+ 0)));
                        helmholtz_02 = _mm_add_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 2),             phi_02           ),_mm_load_pd( beta_k+ijk+ plane+ 2)));
                        helmholtz_04 = _mm_add_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 4),             phi_04           ),_mm_load_pd( beta_k+ijk+ plane+ 4)));
                        helmholtz_06 = _mm_add_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+ 6),             phi_06           ),_mm_load_pd( beta_k+ijk+ plane+ 6)));
                        helmholtz_00 = _mm_sub_pd(helmholtz_00,_mm_mul_pd(_mm_sub_pd(             phi_00           ,_mm_load_pd( phi+ijk- plane+ 0)),_mm_load_pd( beta_k+ijk       + 0)));
                        helmholtz_02 = _mm_sub_pd(helmholtz_02,_mm_mul_pd(_mm_sub_pd(             phi_02           ,_mm_load_pd( phi+ijk- plane+ 2)),_mm_load_pd( beta_k+ijk       + 2)));
                        helmholtz_04 = _mm_sub_pd(helmholtz_04,_mm_mul_pd(_mm_sub_pd(             phi_04           ,_mm_load_pd( phi+ijk- plane+ 4)),_mm_load_pd( beta_k+ijk       + 4)));
                        helmholtz_06 = _mm_sub_pd(helmholtz_06,_mm_mul_pd(_mm_sub_pd(             phi_06           ,_mm_load_pd( phi+ijk- plane+ 6)),_mm_load_pd( beta_k+ijk       + 6)));
                        helmholtz_00 = _mm_mul_pd(helmholtz_00,b_h2inv_splat2);
                        helmholtz_02 = _mm_mul_pd(helmholtz_02,b_h2inv_splat2);
                        helmholtz_04 = _mm_mul_pd(helmholtz_04,b_h2inv_splat2);
                        helmholtz_06 = _mm_mul_pd(helmholtz_06,b_h2inv_splat2);
                        helmholtz_00 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 0)),phi_00),helmholtz_00);
                        helmholtz_02 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 2)),phi_02),helmholtz_02);
                        helmholtz_04 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 4)),phi_04),helmholtz_04);
                        helmholtz_06 = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+ 6)),phi_06),helmholtz_06);
                __m128d       new_00 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 0),_mm_sub_pd(helmholtz_00,_mm_load_pd(rhs+ijk+ 0)));
                __m128d       new_02 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 2),_mm_sub_pd(helmholtz_02,_mm_load_pd(rhs+ijk+ 2)));
                __m128d       new_04 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 4),_mm_sub_pd(helmholtz_04,_mm_load_pd(rhs+ijk+ 4)));
                __m128d       new_06 = _mm_mul_pd(_mm_load_pd(lambda+ijk+ 6),_mm_sub_pd(helmholtz_06,_mm_load_pd(rhs+ijk+ 6)));
                              new_00 = _mm_sub_pd(phi_00,new_00);
                              new_02 = _mm_sub_pd(phi_02,new_02);
                              new_04 = _mm_sub_pd(phi_04,new_04);
                              new_06 = _mm_sub_pd(phi_06,new_06);
          const __m128d RedBlack_00 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 0) ));
          const __m128d RedBlack_02 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 2) ));
          const __m128d RedBlack_04 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 4) ));
          const __m128d RedBlack_06 = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+ 6) ));
                        new_00  = _mm_or_pd(_mm_and_pd(RedBlack_00,new_00),_mm_andnot_pd(RedBlack_00,phi_00));
                        new_02  = _mm_or_pd(_mm_and_pd(RedBlack_02,new_02),_mm_andnot_pd(RedBlack_02,phi_02));
                        new_04  = _mm_or_pd(_mm_and_pd(RedBlack_04,new_04),_mm_andnot_pd(RedBlack_04,phi_04));
                        new_06  = _mm_or_pd(_mm_and_pd(RedBlack_06,new_06),_mm_andnot_pd(RedBlack_06,phi_06));
                                              _mm_store_pd(phi+ijk+ 0,new_00);
                                              _mm_store_pd(phi+ijk+ 2,new_02);
                                              _mm_store_pd(phi+ijk+ 4,new_04);
                                              _mm_store_pd(phi+ijk+ 6,new_06);
        }
      }}
    }
  }
}


//==================================================================================================
void smooth(domain_type * domain, int level, int phi_id, int rhs_id, double a, double b, double hLevel, int sweep){
  int CollaborativeThreadingBoxSize = 100000; // i.e. never
  #ifdef __COLLABORATIVE_THREADING
    #warning using Collaborative Threading for large boxes...
    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;
  #endif
  int box;
  if(domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize){
    for(box=0;box<domain->numsubdomains;box++){__box_smooth_GSRB_multiple_threaded(&domain->subdomains[box].levels[level],phi_id,rhs_id,a,b,hLevel,sweep);}
  }else{
    #pragma omp parallel for private(box)
    for(box=0;box<domain->numsubdomains;box++){__box_smooth_GSRB_multiple(&domain->subdomains[box].levels[level],phi_id,rhs_id,a,b,hLevel,sweep);}
  }
}
//==================================================================================================
