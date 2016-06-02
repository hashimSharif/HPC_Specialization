eval 'exec perl $0 $*'
        if 0;
$NumArgs = $#ARGV+1;

$ARGV0 = $ARGV[0];
$ARGV0 =~ tr/A-Z/a-z/;


#==========================================================================================================================================
open(F,">./smooth.c");
print F "//==================================================================================================\n";
$GlobalU = 8;
&smooth_gsrb_wavefront($GlobalU,0);
&smooth_gsrb_wavefront($GlobalU,1);
print F "//==================================================================================================\n";
print F "void smooth(domain_type * domain, int level, int phi_id, int rhs_id, double a, double b, double hLevel, int sweep){\n";
print F "  int CollaborativeThreadingBoxSize = 100000; // i.e. never\n";
print F "  #ifdef __COLLABORATIVE_THREADING\n";
print F "    #warning using Collaborative Threading for large boxes...\n";
print F "    CollaborativeThreadingBoxSize = 1 << __COLLABORATIVE_THREADING;\n";
print F "  #endif\n";
print F "  int box;\n";
print F "  if(domain->subdomains[0].levels[level].dim.i >= CollaborativeThreadingBoxSize){\n";
print F "    for(box=0;box<domain->numsubdomains;box++){__box_smooth_GSRB_multiple_threaded(&domain->subdomains[box].levels[level],phi_id,rhs_id,a,b,hLevel,sweep);}\n";
print F "  }else{\n";
print F "    #pragma omp parallel for private(box)\n";
print F "    for(box=0;box<domain->numsubdomains;box++){__box_smooth_GSRB_multiple(&domain->subdomains[box].levels[level],phi_id,rhs_id,a,b,hLevel,sweep);}\n";
print F "  }\n";
print F "}\n";
print F "//==================================================================================================\n";
close(F);


#==========================================================================================================================================
sub smooth_gsrb_wavefront{
  local($U,$THREADED)=@_;
  $Uminus1 = $U-1;
  $Alignment = 2; # i.e. align to multiples of four...
  $AlignmentMinus1 = $Alignment-1;
  if(($U % $Alignment) != 0){printf("Warning, SSE code's unrolling must be a multiple of 4\n");return;}
  if($THREADED){$FunctionName = "__box_smooth_GSRB_multiple_threaded";}
           else{$FunctionName = "__box_smooth_GSRB_multiple";}
  print F "void $FunctionName(box_type *box, int phi_id, int rhs_id, double a, double b, double h, int sweep){\n";

  if($THREADED){
  #print F "  volatile int64_t KPlaneFinishedByThread[256]; // limited to 256 threads !!!\n";
  }
  print F "  int pencil = box->pencil;\n";
  print F "  int plane = box->plane;\n";
  print F "  int ghosts = box->ghosts;\n";
  print F "  int DimI = box->dim.i;\n";
  print F "  int DimJ = box->dim.j;\n";
  print F "  int DimK = box->dim.k;\n";
  print F "  double h2inv = 1.0/(h*h);\n";
  print F "  double * __restrict__ phi    = box->grids[  phi_id] + ghosts*plane;\n";
  print F "  double * __restrict__ rhs    = box->grids[  rhs_id] + ghosts*plane;\n";
  print F "  double * __restrict__ alpha  = box->grids[__alpha ] + ghosts*plane;\n";
  print F "  double * __restrict__ beta_i = box->grids[__beta_i] + ghosts*plane;\n";
  print F "  double * __restrict__ beta_j = box->grids[__beta_j] + ghosts*plane;\n";
  print F "  double * __restrict__ beta_k = box->grids[__beta_k] + ghosts*plane;\n";
  print F "  double * __restrict__ lambda = box->grids[__lambda] + ghosts*plane;\n";
  if($THREADED){
  #print F "  #pragma omp parallel shared(KPlaneFinishedByThread)\n";
  print F "  #pragma omp parallel\n";
  print F "  {\n";
  print F "    int id      = omp_get_thread_num();\n";
  print F "    int threads = omp_get_num_threads();\n";
  print F "    int global_ij_start = (                       pencil+1)&~$AlignmentMinus1;\n";
  print F "    int global_ij_end   = ((ghosts+DimJ+ghosts-1)*pencil-1);\n";
  print F "    int TotalUnrollings = ((global_ij_end-global_ij_start+$U-1)/$U);\n";
  print F "    int ij_start = global_ij_start + $U*((id  )*(TotalUnrollings)/threads);\n";
  print F "    int ij_end   = global_ij_start + $U*((id+1)*(TotalUnrollings)/threads);\n";
  print F "    if(id==(threads-1))ij_end = global_ij_end;\n";
  #print F "    // only works if (ij_end-ij_start)>=pencil;\n";
  #print F "    int  left = max(        0,id-1);\n";
  #print F "    int right = min(threads-1,id+1);\n";
  #print F "    if(ghosts==1){right=id;left=id;}\n";
  #print F "    if(ghosts>1){\n";
  #print F "    KPlaneFinishedByThread[id]=-100;\n";
  #print F "    #pragma omp barrier\n";
  #print F "    }\n";
  }else{
  print F "  {\n";
  print F "    int ij_start =                (                       pencil+1)&~$AlignmentMinus1;\n";
  print F "    int ij_end    = ij_start+$U*((((ghosts+DimJ+ghosts-1)*pencil-1)-ij_start+$U-1)/$U);\n";
#printf(F "    printf(\"%%d...%%d\\n\",ij_start,ij_end);\n");
  }

  print F "    #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)\n";
  $PF_Streams=7;$s=0;
  print F "    double * __restrict__ Prefetch_Pointers[$PF_Streams];\n";
  print F "    Prefetch_Pointers[$s] =    phi + plane-pencil;\n";$s++;
  print F "    Prefetch_Pointers[$s] = beta_k + plane;\n";$s++;
  print F "    Prefetch_Pointers[$s] = beta_j        ;\n";$s++;
  print F "    Prefetch_Pointers[$s] = beta_i        ;\n";$s++;
  print F "    Prefetch_Pointers[$s] =  alpha        ;\n";$s++;
  print F "    Prefetch_Pointers[$s] =    rhs        ;\n";$s++;
  print F "    Prefetch_Pointers[$s] = lambda        ;\n";$s++;
 #$PF_increment = int(($PF_Streams*$U   )/4); # exact increment... e.g. increment by 14 == redundant prefetches
 #$PF_increment = 8*$PF_number; # increment matches number of prefetches == too many prefetches
 #print F "   uint8_t Prefetch_Increment[$PF_Streams];\n";
 #print F "   uint8_t Prefetch_NextStream[$PF_Streams];\n";
 #for($s=0;$s<$PF_Streams;$s++){
 #if($s<$PF_Streams-1){printf(F "   Prefetch_Increment[%2d]=%2d;Prefetch_NextStream[%2d]=%2d;\n",$s,0            ,$s,($s+1)%$PF_Streams);}
 #                else{printf(F "   Prefetch_Increment[%2d]=%2d;Prefetch_NextStream[%2d]=%2d;\n",$s,$PF_increment,$s,($s+1)%$PF_Streams);}}
  print F "    #endif\n";


  print F "    int leadingK;\n";
  print F "    int kLow  =     -(ghosts-1);\n";
  print F "    int kHigh = DimK+(ghosts-1);\n";

  print F "    for(leadingK=kLow;leadingK<kHigh;leadingK++){\n";

  if($THREADED){
  print F "    if(ghosts>1){\n";
  print F "      #pragma omp barrier\n";
  print F "    }\n";
  }

  print F "      #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM) || defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)\n";
  print F "      int prefetch_stream=0;\n";
  print F "      int prefetch_ijk_start = ij_start + (leadingK+1)*plane;\n";
  print F "      int prefetch_ijk_end   = ij_end   + (leadingK+1)*plane;\n";
  print F "      int prefetch_ijk       = prefetch_ijk_start;\n";
  print F "      #endif\n";
  print F "      int j,k,planeInWavefront;\n";
  print F "      for(planeInWavefront=0;planeInWavefront<ghosts;planeInWavefront++){\n";
  print F "        #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)\n";
  print F "                                  int prefetch_offset_for_next_plane_in_wavefront=      -plane;\n";
  print F "        if(planeInWavefront==ghosts-1)prefetch_offset_for_next_plane_in_wavefront=ghosts*plane;\n";
  print F "        #endif\n";
  print F "        k=(leadingK-planeInWavefront);if((k>=kLow)&&(k<kHigh)){\n";
                   &smooth_gsrb_VL_sse($GlobalU);
  print F "      }}\n";

 #if($THREADED){
 #print F "    if(ghosts>1){\n";
 #print F "      KPlaneFinishedByThread[id]=leadingK;\n";
 #print F "      {_mm_pause();}while( (KPlaneFinishedByThread[left ]<leadingK) || (KPlaneFinishedByThread[right]<leadingK) );\n";
 #print F "      while( (KPlaneFinishedByThread[left ]<leadingK) || (KPlaneFinishedByThread[right]<leadingK) ){};\n";
 #print F "    }\n";
 #}

  print F "    }\n";
  print F "  }\n";
  print F "}\n\n\n";
}


#==========================================================================================================================================
sub smooth_gsrb_VL_sse{
  local($U)=@_;

                        print  F "        uint64_t invertMask = 0-((k^planeInWavefront^sweep^1)&0x1);\n";
                        print  F "        const __m128d    invertMask2 =            _mm_loaddup_pd((double*)&invertMask);\n";
                        print  F "        const __m128d       a_splat2 =            _mm_loaddup_pd(&a);\n";
                        print  F "        const __m128d b_h2inv_splat2 = _mm_mul_pd(_mm_loaddup_pd(&b),_mm_loaddup_pd(&h2inv));\n";
                        print  F "        int ij,kplane=k*plane;\n";
                        print  F "        for(ij=ij_start;ij<ij_end;ij+=$U){ // smooth a vector...\n";
                        print  F "          int ijk=ij+kplane;\n";


                        $PF_number    = int(($PF_Streams*$U+31)/32); #   7 ($PF_Streams) planes prefetched for every 4 planes computed
                        #$PF_number    = int(($PF_Streams*$U+64)/64); #   7 ($PF_Streams) planes prefetched for every 4 planes computed
                        #$PF_increment = 8*$PF_number; # increment matches number of prefetches == too many prefetches
                        $PF_increment = int(($PF_Streams*$U   )/4); # exact increment... e.g. increment by 14 == redundant prefetches
                        print  F "          #if defined(__PREFETCH_NEXT_PLANE_FROM_DRAM)\n";
                        print  F "          #warning will attempt to prefetch the next plane from DRAM one component at a time\n";
                        #printf(F "          if(prefetch_stream<$PF_Streams){\n");
                        printf(F "            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;\n");
for($x=0;$x<8*$PF_number;$x+=8){
#for($x=0;$x<16*$PF_number;$x+=16){
                        printf(F "            _mm_prefetch((const char*)(_base+%2d),_MM_HINT_T1);\n",$x);}
                        printf(F "            prefetch_ijk+=$PF_increment;if(prefetch_ijk>prefetch_ijk_end){prefetch_stream++;prefetch_ijk=prefetch_ijk_start;}\n");
                        #printf(F "          }\n");


                        $PF_number    = int(($PF_Streams*$U+31)/32); #   7 ($PF_Streams) planes prefetched for every 4 planes computed
                        #$PF_number    = int(($PF_Streams*$U+63)/64); #   7 ($PF_Streams) planes prefetched for every 4 planes computed
                        #$PF_increment = 8*$PF_number; # increment matches number of prefetches == too many prefetches
                        $PF_increment = int(($PF_Streams*$U   )/4); # exact increment... e.g. increment by 14 == redundant prefetches
                        print  F "          #elif defined(__PREFETCH_NEXT_PLANE_FROM_DRAM_INTERLEAVED)\n";
                        print  F "          #warning will attempt to prefetch the next plane from DRAM interleaving prefetches by component\n";
                       #printf(F "          if(prefetch_ijk<prefetch_ijk_end){\n");
                        printf(F "            double * _base = Prefetch_Pointers[prefetch_stream] + prefetch_ijk;\n");
for($x=0;$x<8*$PF_number;$x+=8){
#for($x=0;$x<16*$PF_number;$x+=16){
                        printf(F "            _mm_prefetch((const char*)(_base+%2d),_MM_HINT_T1);\n",$x);}
                        printf(F "            prefetch_stream++;if(prefetch_stream>%d){prefetch_stream=0;prefetch_ijk+=%d;}\n",$PF_Streams-1,$PF_increment);
                       #printf(F "            prefetch_ijk   +=Prefetch_Increment[prefetch_stream];\n");
                       #printf(F "            prefetch_stream =Prefetch_NextStream[prefetch_stream];\n");
                       #printf(F "          }\n");
                        printf(F "          #endif\n");


                                $PF_number    = int(($U+7)/8); # one plane prefetched per plane computed...
                                print  F "          #if defined(__PREFETCH_NEXT_PLANE_FROM_CACHE)\n";
                                print  F "          #warning attempting to prefetch the next plane in the wavefront\n";
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(   phi+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_k+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_j+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_i+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)( alpha+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(lambda+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(   rhs+ijk+prefetch_offset_for_next_plane_in_wavefront+%2d),_MM_HINT_T0);\n",$x);}
                                print  F "          #elif defined(__PREFETCH_NEXT_PENCIL_FROM_CACHE)\n";
                                print  F "          #warning attempting to prefetch the next pencil\n";
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(   phi+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_k+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_j+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(beta_i+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)( alpha+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(lambda+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
for($x=0;$x<8*$PF_number;$x+=8){printf(F "            _mm_prefetch((const char*)(   rhs+ijk+pencil+%2d),_MM_HINT_T0);\n",$x);}
                                print  F "          #elif defined(__PREFETCH_NEXT_LINE_FROM_CACHE)\n";
                                print  F "          #warning attempting to prefetch the next line\n";
                                printf(F "            _mm_prefetch((const char*)(   phi+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)(beta_k+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)(beta_j+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)(beta_i+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)( alpha+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)(lambda+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "            _mm_prefetch((const char*)(   rhs+ijk+$U+%2d),_MM_HINT_T0);\n",8);
                                printf(F "          #endif\n");


                        printf(F "          // this version performs unalligned accesses for phi+/-1, betai+1 and phi+/-pencil\n",$x);
                        printf(F "          //careful... assumes the compiler maps _mm128_load_pd to unaligned vmovupd and not the aligned version (should be faster when pencil is a multiple of 2 doubles (16 bytes)\n");
  for($x=0;$x<$U;$x+=2){printf(F "          const __m128d       phi_%02d = _mm_load_pd(phi+ijk+%3d);\n",$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                __m128d helmholtz_%02d;\n",$x);}

  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d =                           _mm_mul_pd(_mm_sub_pd(_mm_loadu_pd(phi+ijk+       %2d),             phi_%02d           ),_mm_loadu_pd(beta_i+ijk+       %2d)); \n",$x,$x+1,$x,$x+1);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_sub_pd(helmholtz_%02d,_mm_mul_pd(_mm_sub_pd(             phi_%02d           ,_mm_loadu_pd(phi+ijk+       %2d)),_mm_load_pd( beta_i+ijk+       %2d)));\n",$x,$x,$x,$x-1,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_add_pd(helmholtz_%02d,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+pencil+%2d),             phi_%02d           ),_mm_load_pd( beta_j+ijk+pencil+%2d)));\n",$x,$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_sub_pd(helmholtz_%02d,_mm_mul_pd(_mm_sub_pd(             phi_%02d           ,_mm_load_pd( phi+ijk-pencil+%2d)),_mm_load_pd( beta_j+ijk+       %2d)));\n",$x,$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_add_pd(helmholtz_%02d,_mm_mul_pd(_mm_sub_pd(_mm_load_pd( phi+ijk+ plane+%2d),             phi_%02d           ),_mm_load_pd( beta_k+ijk+ plane+%2d)));\n",$x,$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_sub_pd(helmholtz_%02d,_mm_mul_pd(_mm_sub_pd(             phi_%02d           ,_mm_load_pd( phi+ijk- plane+%2d)),_mm_load_pd( beta_k+ijk       +%2d)));\n",$x,$x,$x,$x,$x);}

  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_mul_pd(helmholtz_%02d,b_h2inv_splat2);\n",$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        helmholtz_%02d = _mm_sub_pd(_mm_mul_pd(_mm_mul_pd(a_splat2,_mm_load_pd(alpha+ijk+%2d)),phi_%02d),helmholtz_%02d);\n",$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                __m128d       new_%02d = _mm_mul_pd(_mm_load_pd(lambda+ijk+%2d),_mm_sub_pd(helmholtz_%02d,_mm_load_pd(rhs+ijk+%2d)));\n",$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                              new_%02d = _mm_sub_pd(phi_%02d,new_%02d);\n",$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "          const __m128d RedBlack_%02d = _mm_xor_pd(invertMask2,(__m128d)_mm_load_si128( (__m128i*)(box->RedBlackMask+ij+%2d) ));\n",$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                        new_%02d  = _mm_or_pd(_mm_and_pd(RedBlack_%02d,new_%02d),_mm_andnot_pd(RedBlack_%02d,phi_%02d));\n",$x,$x,$x,$x,$x);}
  for($x=0;$x<$U;$x+=2){printf(F "                                              _mm_store_pd(phi+ijk+%2d,new_%02d);\n",$x,$x);}
                         print F "        }\n";

return;



}
#==========================================================================================================================================
