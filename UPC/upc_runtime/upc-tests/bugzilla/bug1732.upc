#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
 
int main ()
{
  shared char *ptr;
  char *s;
  const size_t size = 3141592;
  int k;
  upc_barrier 1;
  ptr = upc_all_alloc (THREADS, size);
  if (!ptr)
    {
      fprintf (stderr, "%d: Error: upc_all_alloc() failed\n",
               MYTHREAD);
      abort ();
    }
  /* shared -> local */
  s = (char *)&ptr[MYTHREAD];
  for (k = 0; k < size; ++k)
    {
      void *local_addr = (void *)&s[k];
      void *remote_to_local_addr =
        (void *)&(((shared [] char *)&ptr[MYTHREAD])[k]);
      if (local_addr != remote_to_local_addr)
        {
          fprintf (stderr,
            "%d: Error: address compare for size %ld failed at index %d\n"
            "    Local address %016lx != %016lx\n",
            MYTHREAD, (long int)size, k,
            (long unsigned)local_addr,
            (long unsigned)remote_to_local_addr);
          abort ();
        }
    }
  upc_barrier 2;
  if (MYTHREAD == 0)
    printf ("castbug passed.\n");
  return 0;
}

