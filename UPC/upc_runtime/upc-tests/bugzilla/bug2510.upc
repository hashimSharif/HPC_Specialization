#include <upc_relaxed.h>
shared char * shared readASequence(char *path, short *alphabetIndex); 
char f(void) { return *readASequence(NULL, NULL); }
