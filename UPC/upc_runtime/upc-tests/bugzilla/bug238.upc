#include <stdlib.h>
#include "upc.h"

typedef unsigned long hash_val_t;
typedef struct hnode_t {
   
    struct hnode_t *hash_next;          /* 2 */
    const void *hash_key;               /* 3 */
    void *hash_data;                    /* 4 */
    hash_val_t hash_hkey;               /* 5 */
   
} hnode_t;


typedef struct point_name{
  double x;
  double y;
  int gid;
} point;

#define hnode_get(N) ((N)->hash_data)

point getglobal(int gid,shared [] point *gpoints)
{
  hnode_t *retpoint = NULL;
  return(*((point *) hnode_get(retpoint)));
 
}
