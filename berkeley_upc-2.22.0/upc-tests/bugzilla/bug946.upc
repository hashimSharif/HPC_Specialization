#include <stdio.h>

int i,j;

void set_indx() {
  i = 1;
  j = 2;
}
struct s1 { float aaa[4]; };
struct s2 { struct s1 bbb[8]; };

int main(void)
{
  volatile // Otherwise backend may discard most/all of the test
  struct s2 foo,*pfoo;
  set_indx();
  //foo.bbb[1].aaa[2] = 3.0;
  pfoo = &foo;
  pfoo->bbb[1].aaa[2] = 3.0;
  if(*((float*)((char*)pfoo+sizeof(struct s1)) + 2) != 3.0)
    fprintf(stderr,"Error: setting constant offsets \n");

  pfoo->bbb[i].aaa[j] = 4.0;
  if(*((float*)((char*)pfoo+sizeof(struct s1)*i) + j) != 4.0)
    fprintf(stderr,"Error: setting var offsets \n");

  foo.bbb[i].aaa[j] = 5.0;
  if(*((float*)((char*)pfoo+sizeof(struct s1)*i) + j) != 5.0)
    fprintf(stderr,"Error: setting var offsets \n");
  
  foo.bbb[1].aaa[2] = 6.0;
  if(*((float*)((char*)pfoo+sizeof(struct s1)*i) + j) != 6.0)
    fprintf(stderr,"Error: setting const offsets \n");
  printf("done.\n");
  return 0;
}
