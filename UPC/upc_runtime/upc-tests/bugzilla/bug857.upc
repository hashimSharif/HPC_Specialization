#include <upc_relaxed.h>
#include <stddef.h>
   
typedef shared [] char *scptr;
 
void bug(shared [] char *entry) 
{   
  shared [] char *next = *((shared [] scptr *) entry);
  next = (scptr) NULL;
} 


