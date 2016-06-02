#include <upc_relaxed.h>
#include <stdlib.h>

int shared [] * shared full_filevec = NULL;                               
size_t shared full_filevec_cnt;                                                     
size_t shared full_filevec_datasz;                                                  
                                                                                               
  int get_fvec_datasz(size_t cnt, int *vec) {                                  
    int sz = 0;                                                                          
    return sz;                                                                                 
  }                                                                                            

int main(int argc, char **argv) {
    int *filevec=NULL;                                                                    
    int i=0;                                                                                     
    full_filevec_datasz = get_fvec_datasz(full_filevec_cnt, filevec);                          
    full_filevec_cnt = i+1;
    full_filevec_datasz = get_fvec_datasz(full_filevec_cnt, (int*)full_filevec);
}



