/* should compile in both static and dynamic env!!! */
#include <upc.h>
#include <stdio.h>

shared [10] int arr1[100*THREADS]; /* blocksz=10 shared array of ints */
int shared [10] arr2[100*THREADS]; /* same */

shared [10] int * arr3[100]; /* private array of pointers-to-shared-ints bsz=10 */
int shared [10] * arr4[100]; /* same */

int main() {
 if (upc_threadof(&(arr1[0])) != 0) printf("ERROR1\n");
 if (upc_threadof(&(arr2[0])) != 0) printf("ERROR2\n");

 if (upc_blocksizeof(*(arr3[0])) != 10) printf("ERROR3\n");
 if (upc_blocksizeof(*(arr4[0])) != 10) printf("ERROR4\n");

 if (upc_blocksizeof(arr1) != 10) printf("ERROR5\n");
 if (upc_blocksizeof(arr2) != 10) printf("ERROR6\n");
 if (upc_blocksizeof(arr1[0]) != 10) printf("ERROR7\n");
 if (upc_blocksizeof(arr2[0]) != 10) printf("ERROR8\n");

 
 printf("done\n");
 return 0;
}
