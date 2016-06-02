#include <stdio.h>
//shared int A[256][1024][1024*THREADS];
//shared int B[1024][1024][1024*THREADS];
int main() {
//printf("upc_localsizeof(A)=%llu\n",(unsigned long long)upc_localsizeof(A));
//printf("sizeof(A)=%llu\n",(unsigned long long)sizeof(A));
//printf("upc_localsizeof(B)=%llu\n",(unsigned long long)upc_localsizeof(B));
//printf("sizeof(B)=%llu\n",(unsigned long long)sizeof(B));
unsigned long long localsz = upc_localsizeof(shared int [256][1024][1024*THREADS]);
unsigned long long sz =               sizeof(shared int [256][1024][1024*THREADS]);
unsigned long long expectedsz = ((unsigned long long)sizeof(int))*256ULL*1024ULL*1024ULL*THREADS;
unsigned long long expectedlocalsz = expectedsz/THREADS;

unsigned long long localsz2 = upc_localsizeof(shared int [1024][1024][1024*THREADS]);
unsigned long long sz2 =               sizeof(shared int [1024][1024][1024*THREADS]);
unsigned long long expectedsz2 = ((unsigned long long)sizeof(int))*1024ULL*1024ULL*1024ULL*THREADS;
unsigned long long expectedlocalsz2 = expectedsz2/THREADS;

if (localsz != expectedlocalsz) { /* should work on any platform */
  printf("ERROR: localsz=%llu expectedlocalsz=%llu\n",localsz,expectedlocalsz);
} else if (sizeof(size_t) >= 8 && /* should work on any 64-bit size_t platform */
          (sz != expectedsz || sz2 != expectedsz2 || localsz2 != expectedlocalsz2)) {
  printf("ERROR: sz=%llu expectedsz=%llu sz2=%llu expectedsz2=%llu localsz2=%llu expectedlocalsz2=%llu \n",
                 sz,expectedsz,sz2,expectedsz2,localsz2,expectedlocalsz2);
} else {
  printf("upc_localsizeof(shared int [256][1024][1024*THREADS])=%llu\n",localsz);
  printf("sizeof(shared int [256][1024][1024*THREADS])=%llu\n",sz);
  printf("upc_localsizeof(shared int [1024][1024][1024*THREADS])=%llu\n",localsz2);
  printf("sizeof(shared int [1024][1024][1024*THREADS])=%llu\n",sz2);
  printf("done.\n");
}
return 0;
}
