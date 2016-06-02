#ifndef _GULA_H
#define _GULA_H 1

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// This doesn't exit
#define GULA_PRINT_FAIL(x)					                            \
		{					                                            \
				fprintf(stderr, "Failed %s:%d (thread %d) Error: %s\n", \
                        __FILE__, __LINE__, MYTHREAD, x);		        \
		}

#define GULA_FAIL(x)					                                \
		{					                                            \
				fprintf(stderr, "Failed %s:%d (thread %d) Error: %s\n", \
                        __FILE__, __LINE__, MYTHREAD, x);		        \
				upc_global_exit(EXIT_FAILURE);	                        \
		}

#endif /* _GULA_H */
