#include <stdio.h>
#include <upc.h>
#include <upc_io.h>

#define NUM 20
#define TYPE int

shared [5] TYPE buffer[NUM];
upc_file_t *fd;

void create_input() {
    FILE *fptr;
    int   i;
    TYPE buf[NUM];

    for (i=0; i<NUM; i++) buf[i] = (TYPE)i;

    fptr=fopen("datafile", "w");
    fwrite(buf, sizeof(TYPE), NUM, fptr);
    fclose(fptr);
}

int main() {
    int i;

    if (!MYTHREAD) create_input();
    upc_barrier;
    fd = upc_all_fopen("datafile", UPC_COMMON_FP|UPC_RDONLY, 0, NULL);
    upc_all_fread_shared(fd, buffer, 5, sizeof(TYPE), NUM, UPC_IN_ALLSYNC|UPC_OUT_ALLSYNC);
    upc_all_fclose(fd);
    upc_barrier;
    upc_forall (i=0; i<NUM; i++; &buffer[i]) {
        printf("%d: [%2d] %9.4f\n", MYTHREAD,i,(double)buffer[i]);
        if (buffer[i] != (TYPE)i) printf("ERROR at %i\n",i);
    }
    upc_barrier;
    if (!MYTHREAD) printf("done.\n");
    return 0;
}
