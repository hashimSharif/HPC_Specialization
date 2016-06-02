#include <upc.h>
#include <stdio.h>
#define N 50
upc_lock_t *l;
shared double pi = 0.0;
int main(void) {
        double local_pi=0.0;
        int i;
        l=upc_all_lock_alloc();

        upc_forall(i=0;i<N;i++; i) 
                local_pi += 1.0;

//fprintf(stderr, "%d: lpi=%lg\n",MYTHREAD, local_pi);

        upc_lock(l);
        pi += local_pi;
//fprintf(stderr, "%d: lpi=%lg, pi=%lg\n",MYTHREAD, local_pi, pi);
        upc_unlock(l);

        upc_barrier; // Ensure all is done
        //if(MYTHREAD==0) printf("PI=%f\nn_threads=%d\n",pi,THREADS);
        if(MYTHREAD==0) printf("PI=%f\n",pi);
        if (pi == N) printf("done.\n");
        else printf("ERROR\n");
        if(MYTHREAD==0) upc_lock_free(l);
        return 0;
}

