#if defined(__BERKELEY_UPC__) && defined(__BERKELEY_UPC_FIRST_PREPROCESS__)
/* This is ONLY seen by the Berkeley UPC-to-C translator */
int sld = 0;
#else
int sld = sizeof(long double);
#endif
