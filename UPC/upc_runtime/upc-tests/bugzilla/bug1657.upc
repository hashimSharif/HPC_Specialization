#define PACKAGE_NAME "petunias"
#define PACKAGE_TARNAME "petunias"
#define PACKAGE_VERSION "0.9.1"
#define PACKAGE_STRING "petunias 0.9.1"
#define PACKAGE_BUGREPORT "PETUNIAS"
#define PACKAGE "petunias"
#define VERSION "0.9.1"
#ifdef __cplusplus
void exit (int);
#endif
#define THREADS_PER_NODE 1
#define HAVE_LOG2 1
#define restrict
#include <upc_relaxed.h>
int
main ()
{
upc_forall (int i = 0; i < THREADS; i++; i) {}
;
return 0;
}
