// BUPC uses non-const spill for this because it doesn't know that
// the string literal is to be "const", but when using gcc as the
// backend we pass -Wwrite-strings which leads to treatment of
// the string literal as const-qualified and a warning.
const char * foo(char *q) { return q ? q : "(null)"; }

// We do manage to get this one right:
const int * bar(int *p, const int *q) { return p ? p : q; }
