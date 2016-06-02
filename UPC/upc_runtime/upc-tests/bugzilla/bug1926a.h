struct mystruct2 {
  int field1;
  long field2;
};

void foo2 (struct mystruct2 *p) { p->field1 = p->field2 = 0; }
