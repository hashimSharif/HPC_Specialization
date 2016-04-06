typedef int xint64_t __attribute__ ((__mode__ (__DI__)));

shared long long int src;

int main(void) {
  xint64_t dst = *(shared xint64_t *) &src;
  return (int)dst;
}
