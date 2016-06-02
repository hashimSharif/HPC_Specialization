#ifndef WORK_AROUND
  // Including stdio.h before stdarg.h yields broken va_list defn with
  // clang on Solaris/x86-64 and -U__GNUC__, as seen with clang-upc2c
  // using Sun compiler as backend, but also seen with clang (no UPC).
  #include <stdio.h>
  #include <stdarg.h>
#else
  // Works:
  #include <stdarg.h>
  #include <stdio.h>
#endif

static void msg(const char *s, ...) {
  char msg[255];
  va_list ap;
  va_start(ap, s);
    vsnprintf(msg, sizeof(msg), s, ap);
  va_end(ap);
  fprintf(stderr,"*** NOTICE: %s\n", msg);
}

int main(void) {
  msg("PASS.");
  return 0;
}
