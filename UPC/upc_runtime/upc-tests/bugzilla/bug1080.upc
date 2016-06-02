#include <upc.h>
#include <stddef.h>

typedef struct {
double real;
double imag;
} _ComPLex_t;

    typedef struct {
      _ComPLex_t value;
      _ComPLex_t flag;
    } bundle_t;
int main() {
    bundle_t *myReduce = NULL;

    bundle_t mybundle = { 0 }; 

    for (int i=0; i < 10; i++) {
      mybundle.value.real += myReduce[i].value.real;
      mybundle.value.imag += myReduce[i].value.imag;
    }

}
