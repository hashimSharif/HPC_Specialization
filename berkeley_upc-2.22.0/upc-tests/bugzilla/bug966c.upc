struct struct95
  {
    int field[10];
  };
shared struct struct95 shared_struct;
int main() {
  int got;
  shared [] int *p1;
  shared int *p2;
  p1 = shared_struct.field;
  p1 = &shared_struct.field[0];

  p2 = (shared int *)shared_struct.field;
  p2 = (shared int *)&shared_struct.field[0];

  got = *((shared int *)shared_struct.field);
  return 0;
}

