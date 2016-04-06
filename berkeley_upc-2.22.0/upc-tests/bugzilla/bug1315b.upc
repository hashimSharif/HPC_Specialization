#include <upc.h>
#include <stdio.h>
#include <stdlib.h> 

struct T1 {
  shared int *xxx; //adjusted size of the field not taken into account when 
                   //computing the offset of a[] in the chain of references starting
                   // at T3
  int a[36];
  int *A;
};

struct T2 {
  int a;
  struct T1 b[15];
  struct T1 *B;
};

struct T3 {
  int a;
  int b;
  struct T2 c;
};

struct T3* t;


struct AT1 {
  int *xxx;
  int a[36]; 
  int *A;
};

struct AT2 {
  int a;
  struct AT1 b[15];
  struct T1 *B;
};

struct AT3 {
  int a;
  int b;
  struct AT2 c;
};

struct AT3 *at;
int i,j;
void set_indx() {
 i = 1;
 j = 1;
}


int
main()
{
 
  struct T1 *p1;
  struct AT1 *ap1;
  t = malloc(sizeof(struct T3));
  at = malloc(sizeof(struct AT3));

  set_indx();
  t->c.b[1].a[1] = 7;
  p1 = (struct T1*)&(t->c.b);
  p1++;
  if(p1->a[1] != 7)
    fprintf(stderr, "ERROR: \"UPC\" const offset not adjusted\n");
  
  t->c.b[i].a[j] = 77;
  if(p1->a[1] != 77)
    fprintf(stderr, "ERROR: \"UPC\" var  offset not adjusted\n");
	
  at->c.b[1].a[1] = 10;
  ap1 = (struct AT1*)&(at->c.b);
  ap1++;
  if(ap1->a[1] != 10)
    fprintf(stderr, "ERROR: bad \"C\" const offset calculation\n");

  at->c.b[i].a[j] = 1010;
  if(ap1->a[1] != 1010)
    fprintf(stderr, "ERROR: bad \"C\" var offset calculation\n");
  

   printf("done.\n");	 

}
