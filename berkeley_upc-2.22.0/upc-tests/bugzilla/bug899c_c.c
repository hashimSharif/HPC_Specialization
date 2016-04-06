#pragma upc c_code

extern int shared(void);
extern int strict(void);
extern int relaxed(void);

int test(void) {
  const int want = 6;
  int got = shared() + strict() + relaxed();
  return (got == want);
}
