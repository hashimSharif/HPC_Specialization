struct A { struct { int c; int d; } b; };
void baz(shared struct A *p, struct A *q) { p->b = q->b; }
