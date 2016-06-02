typedef struct S
  {
    shared struct S *next;
    long data;
  } S_t;
typedef shared S_t *S_p;

void
proc(shared S_p *p, S_p ptr)
{
  ptr->next = *p;
}
