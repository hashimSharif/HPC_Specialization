#include <string.h>
#include <stdio.h>

int main() {
  char s[100];
  const char *s2 = "hi there";
  char *x; 
  int i;
  size_t z;
  x = strchr(s2, 't');
  x = strrchr(s2, 't');
  x = strcpy(s, s2);
  x = strcat(s, s2);
  i = strcmp(s, s2);
  x = strncpy(s, s2, 4);
  x = strncat(s, s2, 4);
  i = strncmp(s, s2, 4);
  z = strlen(s);
  x = memchr(s2, 't',5);
  x = memcpy(s, s2, 10);
  x = memmove(s, s2, 10);
  x = memset(s, 0, 10);
  i = memcmp(s, s2, 10);

  x = strpbrk(s, s2);
  x = strstr(s, s2);
  x = strerror(0);
  z = strcspn(s, s2);
  z = strspn(s, s2);
  i = strcoll(s, s2);
  z = strxfrm(s, s2, 1);
  x = strtok(s, s2);

  return 0;
}
