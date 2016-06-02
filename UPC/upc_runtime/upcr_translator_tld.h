/*
 * upcr_translator_tld.h
 *
 * Arbitrary thread-local variables needed by the translator.
 *
 * Nothing besides comments and UPCR_TRANSLATOR_TLD definitions (without
 * semicolons) should go into this file.
 */

/* Control for nested forall loops */
UPCR_TRANSLATOR_TLD(int, upcr_forall_control, 0)

/* DOB: DO NOT PLACE ANYTHING MORE IN THIS FILE 
 * This mechanism was obsoleted in runtime spec 3.6 by the upcr_trans_extra support
 *  and this file will be removed in the next major runtime spec version.
 *  The declaration above exists in the interrium only to support compiling 
 *  against old pre-3.6 translators.
 * Any new TLD required by the translator should be declared using
 * UPCR_TLD_DEFINE_TENTATIVE in the translator file:
 *  open64/osprey1.0/libupc/upcr_trans_extra.w2c.h
 */
