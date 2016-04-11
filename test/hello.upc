
/* hello.upc - a simple UPC example */
#include <upc.h>
#include <stdio.h>
#include<unistd.h>

int main() {

  //int a;
  //scanf("%d", &a);
   
  sleep(40);
 
  if (MYTHREAD == 0) 
  { 
    printf("Welcome to Berkeley UPC!!!\n"); 
  } 
  
  upc_barrier; 

  printf(" - Hello from thread  %i\n", MYTHREAD); 
  return 0;
 
}
 
