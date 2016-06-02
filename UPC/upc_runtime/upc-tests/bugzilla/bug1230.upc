#include <ctype.h>
#include <stdio.h>
int main(int argc, char **argv) {
  char x = 'a';
  for ( ; x <= 'z'; x++)  {
    char y = toupper(x);
    printf("%c\n",y);
    if ((int)y != (int)'A'+x-'a') printf("ERROR\n");
    fflush(NULL);
  }
  printf("done.\n");
}
