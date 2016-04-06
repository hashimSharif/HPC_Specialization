// All of these cases are valid uses of incomplete types:
// NOTE: ISO C99 prohibits forward references to enums

struct incomplete_s;
union  incomplete_u;

typedef struct incomplete_s my_struct_t;
typedef union  incomplete_u my_union_t;

// arrays of pointers to incomplete types:
my_struct_t * array0[4];
my_union_t  * array1[4];
struct incomplete_s * array0a[4];
union  incomplete_u * array1a[4];
