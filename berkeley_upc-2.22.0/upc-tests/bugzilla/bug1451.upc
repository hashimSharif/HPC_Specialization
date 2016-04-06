#include <stdio.h>
#include <stdint.h>
#include <string.h>
unsigned int ui = 0xfa9b3701;
const char *ui_str="fa9b3701";
unsigned long ul = 0xfa9b3701;
const char *ul_str="fa9b3701";
uint64_t u64 = 0xffa9b3701L;
const char *u64_str="ffa9b3701";
int main() {
 char tmp[255];
 sprintf(tmp,"%08x",ui);
 if (strcmp(ui_str,tmp)) printf("ERROR: %s != %s\n",ui_str,tmp);
 ui = 0xfa9b3701;
 sprintf(tmp,"%08x",ui);
 if (strcmp(ui_str,tmp)) printf("ERROR: %s != %s\n",ui_str,tmp);
 sprintf(tmp,"%08lx",ul);
 if (strcmp(ul_str,tmp)) printf("ERROR: %s != %s\n",ul_str,tmp);
 sprintf(tmp,"%08llx",(unsigned long long)u64);
 if (strcmp(u64_str,tmp)) printf("ERROR: %s != %s\n",u64_str,tmp);
 printf("done.\n");
}
