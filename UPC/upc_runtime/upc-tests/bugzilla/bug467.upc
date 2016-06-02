typedef struct {
  int x;
  int y;
} foo;

shared [] foo *p1;
foo *p2;
void bar (int i,int j)
{
  p1[i]=p2[j];
}

int main() { return 0; }
