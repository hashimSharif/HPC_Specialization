struct foo { int array[10]; };
  
struct foo toto[20];	

int main(void)
{

  toto[0].array[0] = 1;
  toto[0].array[1] = 2;
  toto[1].array[0] = 3;
  toto[1].array[1] = 4;
  return 0;
}
