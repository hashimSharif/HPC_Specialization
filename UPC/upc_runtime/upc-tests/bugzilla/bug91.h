/* test that gcc inline assembly appears to work for a few common architectures */
int foo() {
#if defined(__GNUC__) && \
   !defined(__APPLE_CC__) /* don't try on Apple gcc, which breaks due to bug 1319 workaround */
  #if defined(__i386__) || defined(__i386) || defined(i386) || \
      defined(__i486__) || defined(__i486) || defined(i486) || \
      defined(__i586__) || defined(__i586) || defined(i586) || \
      defined(__i686__) || defined(__i686) || defined(i686) || \
      defined(__MIC__)
     asm     volatile ("nop" : : : "memory");
     __asm   volatile ("nop" : : : "memory");
     __asm__ volatile ("nop" : : : "memory");
     asm     ("nop" : : : "memory");
     __asm   ("nop" : : : "memory");
     __asm__ ("nop" : : : "memory");
  #elif defined(__x86_64__) /* Athlon/Opteron */
     asm volatile ("mfence" : : : "memory");
  #elif defined(_POWER) || (defined(__linux__) && defined(__PPC__)) || (defined(__blrts__) && defined(__PPC__))
     asm volatile ("sync" : : : "memory");
  #endif
#endif
 return 0;
}

