#include <upc.h>
#include <stdio.h>
#include <assert.h>

/* all the primitive types defined by ISO C (excluding _Complex types) */

char                      c;
signed char               nc;
unsigned char             uc;
short                     s;
signed short              ns;
short int                 si;
signed short int          nsi;
unsigned short            us;
unsigned short int        usi;
int                       i;
signed                    n;
signed int                ni;
unsigned                  u;
unsigned int              ui;
long                      l;
signed long               sl;
long int                  li;
signed long int           nli;
unsigned long             ul;
unsigned long int         uli;
long long                 ll;
signed long long          nll;
long long int             lli;
signed long long int      nlli;
unsigned long long        ull;
unsigned long long int    ulli;
float                     f;
double                    d;
long double               ld;

#ifdef __BERKELEY_UPC__
#define BUPC_ASSERT_TYPE(v,t) bupc_assert_type(v,t)
#else
#define BUPC_ASSERT_TYPE(v,t)
#endif

#define CHECK(type,var) \
  assert(sizeof(var) == sizeof(type)); \
  BUPC_ASSERT_TYPE(var, type) ; \
  printf("sizeof("#type")=%i\n",(int)sizeof(type))

int main() {
  CHECK(char                      ,c);
  CHECK(signed char               ,nc);
  CHECK(unsigned char             ,uc);
  CHECK(short                     ,s);
  CHECK(signed short              ,ns);
  CHECK(short int                 ,si);
  CHECK(signed short int          ,nsi);
  CHECK(unsigned short            ,us);
  CHECK(unsigned short int        ,usi);
  CHECK(int                       ,i);
  CHECK(signed                    ,n);
  CHECK(signed int                ,ni);
  CHECK(unsigned                  ,u);
  CHECK(unsigned int              ,ui);
  CHECK(long                      ,l);
  CHECK(signed long               ,sl);
  CHECK(long int                  ,li);
  CHECK(signed long int           ,nli);
  CHECK(unsigned long             ,ul);
  CHECK(unsigned long int         ,uli);
  CHECK(long long                 ,ll);
  CHECK(signed long long          ,nll);
  CHECK(long long int             ,lli);
  CHECK(signed long long int      ,nlli);
  CHECK(unsigned long long        ,ull);
  CHECK(unsigned long long int    ,ulli);
  CHECK(float                     ,f);
  CHECK(double                    ,d);
  CHECK(long double               ,ld);
 

  printf("done.\n"); 
  return 0;
}
