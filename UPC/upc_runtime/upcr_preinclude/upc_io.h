/* upcr_preinclude/upc_io.h */

#ifndef _UPC_IO_H_
#define _UPC_IO_H_

#if !defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && !defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
#error This file should only be included during initial preprocess
#endif

#if !defined(__UPC_IO__) || __UPC_IO__ < 1
#error Bad feature macro predefinition
#endif

#include <stdlib.h>
#include <stdint.h>

#ifndef UPCRI_LIBWRAP
  typedef shared void * bupc_sharedptr_t;

  #define BUPC_IO_BITS
  #include <upc_io_bits.h>
  #undef BUPC_IO_BITS
#endif

/* Enable use of our builtin UPC-IO implementation */

#define upc_all_fopen                     bupc_all_fopen       
#define upc_all_fclose                    bupc_all_fclose      
#define upc_all_fsync                     bupc_all_fsync       
#define upc_all_fseek                     bupc_all_fseek       
#define upc_all_fset_size                 bupc_all_fset_size   
#define upc_all_fget_size                 bupc_all_fget_size   
#define upc_all_fpreallocate              bupc_all_fpreallocate
#define upc_all_fcntl                     bupc_all_fcntl       
#define upc_all_fread_local               bupc_all_fread_local    
#define upc_all_fread_shared              bupc_all_fread_shared   
#define upc_all_fwrite_local              bupc_all_fwrite_local   
#define upc_all_fwrite_shared             bupc_all_fwrite_shared  
#define upc_all_fread_list_local          bupc_all_fread_list_local  
#define upc_all_fread_list_shared         bupc_all_fread_list_shared 
#define upc_all_fwrite_list_local         bupc_all_fwrite_list_local 
#define upc_all_fwrite_list_shared        bupc_all_fwrite_list_shared
#define upc_all_fread_local_async         bupc_all_fread_local_async  
#define upc_all_fread_shared_async        bupc_all_fread_shared_async 
#define upc_all_fwrite_local_async        bupc_all_fwrite_local_async 
#define upc_all_fwrite_shared_async       bupc_all_fwrite_shared_async
#define upc_all_fread_list_local_async    bupc_all_fread_list_local_async  
#define upc_all_fread_list_shared_async   bupc_all_fread_list_shared_async 
#define upc_all_fwrite_list_local_async   bupc_all_fwrite_list_local_async 
#define upc_all_fwrite_list_shared_async  bupc_all_fwrite_list_shared_async
#define upc_all_fwait_async               bupc_all_fwait_async 
#define upc_all_ftest_async               bupc_all_ftest_async 

#endif

