struct foo { struct bar *p; };
struct foo *foop;
struct bar { struct bar *q; };
typedef struct bar BARSTRUCT;

