// C99 says type qualifers are idempotent.
// UPC's relaxed and strict should be the same

const const int c1;
typedef const int c_int;
const c_int c2;
c_int const c3;

volatile volatile int v1;
typedef volatile int v_int;
volatile v_int v2;
v_int volatile v3;

shared relaxed relaxed int r1;
typedef shared relaxed int r_int;
r_int relaxed r2;
relaxed r_int r3;

shared strict strict int s1;
typedef shared strict int s_int;
s_int strict s2;
strict s_int s3;
