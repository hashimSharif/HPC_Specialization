/* tools/clang/include/clang/Config/config.h.  Generated from config.h.in by configure.  */
/* include/clang/Config/config.h.in. */

#ifndef CONFIG_H
#define CONFIG_H

/* Bug report URL. */
#define BUG_REPORT_URL "http://llvm.org/bugs/"

/* Relative directory for resource files */
#define CLANG_RESOURCE_DIR ""

/* Directories clang will search for headers */
#define C_INCLUDE_DIRS ""

/* Linker version detected at compile time. */
#define HOST_LINK_VERSION "2.24"

/* Default <path> to all compiler invocations for --sysroot=<path>. */
#define DEFAULT_SYSROOT ""

/* Directory where gcc is installed. */
#define GCC_INSTALL_PREFIX ""

/* UPC shared pointer representation. */                                        
#define UPC_PTS "packed"
                                                                                
/* the number of bits in each field. */                                         
#define UPC_PACKED_BITS "20,10,34"
                                                                                
/* the field order */                                                           
#define UPC_PTS_VADDR_ORDER "first"

#endif
