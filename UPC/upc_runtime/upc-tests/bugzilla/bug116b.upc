#include <stdio.h>

char s[] = "Hello \\ world\n\tI'm good today - 'A-OK'\n  \tHooray for \"happy\" \'things\'\n";
char s2[] = "Trickier\?\x0A\\n\x5C\x6E\x5C\x5c\x0AStill?\x20Well OK then: \x59\x61\x79\41\41\12\x42\x6F\x6C\x6c\x6f\x63\x6B\x73\x21\x21\n";
char dquote1 = '\"';
char dquote2 = '"';
char squote1 = '\'';
char squote2 = '\x27';

char s3[] = "\a\b\f\n\r\t";
char s4[] = "\1\2\3\4\5\6\7\10\11\x0\x1\x2\x3\x4\x5\x6\x7\x8\x9";

int main() {
  int i;
  printf(s);
  printf(s2);
  printf("%cGood%c %cBye%c\n",dquote1,dquote2,squote1,squote2);
  if (sizeof(s3) != 7) printf("ERROR: s3 wrong size!\n");
  if (s3[0] != '\a' || 
      s3[1] != '\b' ||
      s3[2] != '\f' ||
      s3[3] != '\n' ||
      s3[4] != '\r' ||
      s3[5] != '\t') printf("ERROR: wrong values in s3!\n");
  if (sizeof(s4) != 20) printf("ERROR: s4 wrong size!\n");
  for (i=0;i<19;i++) {
    if (s4[i] != ((i+1) % 10)) printf("ERROR: wrong value in s4[%i]!\n",i);
  }
  printf("done.\n");
  return 0;
}
