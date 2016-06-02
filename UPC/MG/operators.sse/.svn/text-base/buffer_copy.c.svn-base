void buffer_copy(double * __restrict__ destination, double * __restrict__ source, int elements, int useCacheBypass){
  if( (!useCacheBypass) || (((uint64_t)source)&0xF) || (((uint64_t)destination)&0xF) || (elements&0x1) ){memcpy(destination,source,elements*sizeof(double));}
  else{int c;for(c=0;c<elements;c+=2){_mm_stream_pd(destination+c,_mm_load_pd(source+c));}_mm_mfence();}
}
