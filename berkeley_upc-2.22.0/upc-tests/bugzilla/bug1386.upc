#ifndef M
#define M 4
#endif

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#if 0
#include <gmp.h>
#else
typedef unsigned long int mp_limb_t;
typedef struct
{
  int _mp_alloc;
  int _mp_size;
  mp_limb_t *_mp_d;
} __mpz_struct;
typedef __mpz_struct mpz_t[1];
typedef __mpz_struct *mpz_ptr;
#define mpz_init __gmpz_init
void __gmpz_init (mpz_ptr);
#define mpz_set_ui __gmpz_set_ui
void __gmpz_set_ui (mpz_ptr, unsigned long int);
#endif

typedef struct {
  int x;
  mpz_t c[M];
} mpz_struct;

void mpz_struct_init(mpz_struct *f)
{
  int i;
  for(i=0;i<M;i++)
    mpz_init(f->c[i]);
}

int main(int argc, char **argv)
{
  static mpz_struct q;

  mpz_struct_init(&q);
  q.x=1;
  /* This seems OK ... */
  mpz_set_ui(q.c[0],3);
  /* but this induces a translator error */
  mpz_set_ui(q.c[q.x-1],4);
  
  return 0;
}

