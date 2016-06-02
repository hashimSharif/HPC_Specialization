#include <stdio.h>
#include <string.h>
struct foo {
  char str1[80];
  char str2[80];
  char *str3;
  char str4[80];
} F;

int main(int argc, char **argv) {
char tmp[80];
F.str3 = tmp;
strcpy(F.str1, "p");
strcpy(F.str2, "a");
strcpy(F.str3, "s");
strcpy(&(F.str4[0]), "s");
printf("%s%s%s%s\n", F.str1, F.str2, F.str3, F.str4);
return 0;
}
