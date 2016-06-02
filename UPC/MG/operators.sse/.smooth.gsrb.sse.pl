eval 'exec perl $0 $*'
        if 0;
$NumArgs = $#ARGV+1;

$ARGV0 = $ARGV[0];
$ARGV0 =~ tr/A-Z/a-z/;


#==========================================================================================================================================
open(F,">./smooth.c");
print F "//==================================================================================================\n";
print F "#define max(a, b)  (((a) > (b)) ? (a) : (b))\n";
print F "#define min(a, b)  (((a) < (b)) ? (a) : (b))\n";
print F "//==================================================================================================\n";
print F "const uint64_t __ZeroOneMask[2][8] __attribute__((aligned(32))) = { { 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull, 0x0000000000000000ull },  \n";
print F "                                                                    { 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull, 0xFFFFFFFFFFFFFFFFull } };\n";
print F "\n";
print F "//==================================================================================================\n";
$GlobalU = 8;
&smooth_gsrb_wavefront($GlobalU,0);
&smooth_gsrb_wavefront($GlobalU,1);
print F "//==================================================================================================\n";
close(F);


#==========================================================================================================================================
sub smooth_gsrb_wavefront{
  local($U,$Threaded)=@_;
  $Uminus1 = $U-1;
  $Alignment = 2; # i.e. align to multiples of two...
  $AlignmentMinus1 = $Alignment-1;
  if(($U % 2) != 0){printf("Warning, unrolled SSE code's unrolling must be a multiple of 2\n");return;}
  if($Threaded){$FunctionName = "smooth_multiple_GSRB_threaded";}
           else{$FunctionName = "smooth_multiple_GSRB";}
  print F "void $FunctionName(box_type *box, int phi_id, int rhs_id, double a, double b, double h, int sweep){\n";

  if($Threaded){
  print F "  volatile int64_t KPlaneFinishedByThread[256]; // limited to 256 threads !!!\n";
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
  if($Threaded){
  print F "  #pragma omp parallel shared(KPlaneFinishedByThread)\n";
  print F "  {\n";
  print F "    int id      = omp_get_thread_num();\n";
  print F "    int threads = omp_get_num_threads();\n";
  print F "    int global_ij_start = (                       pencil+1)&~$AlignmentMinus1;\n";
  print F "    int global_ij_end   = ((ghosts+DimJ+ghosts-1)*pencil-1);\n";
  print F "    int TotalUnrollings = ((global_ij_end-global_ij_start+$U-1)/$U);\n";
  print F "    int ij_start = global_ij_start + $U*((id  )*(TotalUnrollings)/threads);\n";
  print F "    int ij_end   = global_ij_start + $U*((id+1)*(TotalUnrollings)/threads);\n";
  print F "    if(id==(threads-1))ij_end = global_ij_end;\n";
  print F "    // only works if (ij_end-ij_start)>=pencil;\n";
  print F "    int  left = max(        0,id-1);\n";
  print F "    int right = min(threads-1,id+1);\n";
  print F "    if(ghosts==1){right=id;left=id;}\n";
  print F "    KPlaneFinishedByThread[id]=-100;\n";
  print F "    #pragma omp barrier\n";
  }else{
  print F "  {\n";
 printf(F "    int ij_start = (                       pencil+1)&~0x%02x;\n",$AlignmentMinus1);
 printf(F "    int ij_end   = ((ghosts+DimJ+ghosts-1)*pencil-1);\n");
  }

  $PF_Streams=7;$s=0;
  print  F "   double * __restrict__ Prefetch_Pointers[$PF_Streams];\n";
  print  F "   Prefetch_Pointers[$s] =    phi + ij_start + plane + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] = beta_k + ij_start + plane + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] = beta_j + ij_start         + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] = beta_i + ij_start         + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] =  alpha + ij_start         + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] =    rhs + ij_start         + plane;\n";$s++;
  print  F "   Prefetch_Pointers[$s] = lambda + ij_start         + plane;\n";$s++;

  print F "    int leadingK;\n";
  print F "    int kLow  =     -(ghosts-1);\n";
 #print F "    int kLow  =     0;\n";
  print F "    int kHigh = DimK+(ghosts-1);\n";

  print F "    for(leadingK=kLow;leadingK<kHigh;leadingK++){\n";
  print F "      int stream=0;\n";
  print F "      int _offset=leadingK*plane;\n";
  print F "      int _limit =leadingK*plane + (ij_end-ij_start);\n";
  print F "      int j,k,planeInWavefront;\n";
  print F "      for(planeInWavefront=0;planeInWavefront<ghosts;planeInWavefront++){\n";
  print F "        k=(leadingK-planeInWavefront);if((k>=kLow)&&(k<kHigh)){\n";
 #print F "        k=(leadingK-planeInWavefront);if(k>-ghosts){\n";
                   &smooth_gsrb_VL_sse($GlobalU);
  print F "      }}\n";
  if($Threaded){
  print F "      KPlaneFinishedByThread[id]=leadingK;\n";
 #print F "      _mm_pause();\n";
  print F "      if(left  != id){while( (KPlaneFinishedByThread[left ]<leadingK) ){};}\n";
  print F "      if(right != id){while( (KPlaneFinishedByThread[right]<leadingK) ){};}\n";
 #print F "      if(left  != id){{_mm_pause();}while( (KPlaneFinishedByThread[left ]<leadingK) );}\n";
 #print F "      if(right != id){{_mm_pause();}while( (KPlaneFinishedByThread[right]<leadingK) );}\n";
 #print F "      #pragma omp barrier\n";
  }
  print F "    }\n";
  print F "  }\n";
  print F "}\n\n\n";
}


#==========================================================================================================================================
sub smooth_gsrb_VL_sse{
  local($U)=@_;

                        print  F "        const __m128d    invertMask2 = (__m128d)_mm_load_si128( (__m128i*)(__ZeroOneMask[(k^planeInWavefront^sweep^1)&0x1]));\n";
                        print  F "        const __m128d       a_splat2 =            _mm_loaddup_pd(&a);\n";
                        print  F "        const __m128d b_h2inv_splat2 = _mm_mul_pd(_mm_loaddup_pd(&b),_mm_loaddup_pd(&h2inv));\n";
                        print  F "        int ij,kplane=k*plane;\n";
                        print  F "        for(ij=ij_start;ij<ij_end;ij+=$U){ // smooth a vector...\n";
                        print  F "          int ijk=ij+kplane;\n";

                        printf(F "#if 0\n");
                        printf(F "                               if(stream<$PF_Streams){\n");
                        $PF_number    = int(($PF_Streams*$U+31)/32); # ceiling...
                        $PF_increment = 8*$PF_number;
                        printf(F "                                 double * _base = Prefetch_Pointers[stream] + _offset;\n");
for($x=0;$x<8*$PF_number;$x+=8){
                        printf(F "                                 _mm_prefetch((const char*)(_base+%2d),_MM_HINT_T0);\n",$x);}
                        printf(F "                                 _offset+=$PF_increment;if(_offset>_limit){stream++;_offset=leadingK*plane;}\n");
                        printf(F "                               }\n");
                        printf(F "#else\n");
                        $PF_number    = int(($PF_Streams*$U+31)/32); # ceiling...
                        $PF_increment = int(($PF_Streams*$U   )/4); # e.g. increment by 14 == redundant prefetches
                        printf(F "                                 double * _base = Prefetch_Pointers[stream] + _offset;\n");
for($x=0;$x<8*$PF_number;$x+=8){
                        printf(F "                                 _mm_prefetch((const char*)(_base+%2d),_MM_HINT_T0);\n",$x);}
                        printf(F "                                 stream++;if(stream>%d){stream=0;_offset+=%d;}\n",$PF_Streams-1,$PF_increment);
                        printf(F "#endif\n");

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
