#include <stdio.h>
#include "bug1303.h"
int main() {
if (sizeof(struct SOLARIS_FILE) != sizeof_SOLARIS_FILE()) {
 printf("ERROR: sizeof(SOLARIS_FILE)=%i, should be %i\n",
        (int)sizeof(struct SOLARIS_FILE), sizeof_SOLARIS_FILE());
} else {
printf("done.\n");
}
}
