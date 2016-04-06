// All of these cases are valid uses of incomplete types:
// NOTE: ISO C99 prohibits forward references to enums

struct incomplete_s;
union  incomplete_u;

typedef struct incomplete_s my_struct_t;
typedef union  incomplete_u my_union_t;

// Shared arrays of pointers to private incomplete types:
my_struct_t * shared array0[THREADS];
my_union_t  * shared array1[THREADS];
struct incomplete_s * shared array0a[THREADS];
union  incomplete_u * shared array1a[THREADS];

// Shared arrays of pointers to shared incomplete types:
shared my_struct_t * shared array3[THREADS];
shared my_union_t  * shared array4[THREADS];
shared struct incomplete_s * shared array3a[THREADS];
shared union  incomplete_u * shared array4a[THREADS];
