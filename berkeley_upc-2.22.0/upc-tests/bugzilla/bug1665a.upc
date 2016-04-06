typedef struct S
  {
    shared struct S *next;
    long data;
  } S_t;
typedef shared S_t *S_p;
 
shared S_p S;

void
proc()
{
  shared [] S_p *p; // Addition of '[]' is a correction relative to bug1665.upc
  p = &(S->next);
}
