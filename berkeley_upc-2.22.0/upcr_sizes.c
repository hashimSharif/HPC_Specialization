#include <upcr.h>

/***************************************** 
 * Various strings we embed in the library 
 *****************************************/

#ifdef UPCRI_SIZES_DUMMY
 /* allows this file to be linked alone for scanning */
 int main(void) {
   abort();
   return 1;
 }
#endif

/* GASNETT_IDENT doesn't work with char array arguments (because of the
 * commas), which we need for the really gross stuff below */
#define UPCRI_IDENT_CHAR_ARRAY(identName)		           \
extern char volatile identName[];                                  \
extern char *_##identName##_identfn(void) { return (char*)identName; } \
char volatile identName[] 

#define UPCRI_IDENT_START_CHARS '$','U','P','C','R','S','i','z','e','o','f',':',' '
/* We don't want to embed unprintable chars, nor '$', which would confuse
 * ident, so we store size as an offset from '$' in ASCII = 36 */
#define UPCRI_IDENT_MAGIC_OFFSET 36

/* 
 * Strings we use to store sizes of various types that the translator
 * needs to see, in 'ident'-ifiable string format.  Upcc greps these out to
 * make the 'upcc-sizes' file it sends to the translator.
 *
 *  - Note:  we embed sizeof strings in our libraries because for certain
 *           platforms/networks (notably MPI on the IBM SP) we cannot compile
 *           & run a program to get them at config time without running a
 *           parallel job in the middle of ./configure...
 */ 
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_shared_ptr) =
	{ UPCRI_IDENT_START_CHARS, 's','h','a','r','e','d','_','p','t','r','=', 
	sizeof(upcr_shared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_pshared_ptr) =
	{ UPCRI_IDENT_START_CHARS, 'p','s','h','a','r','e','d','_','p','t','r','=', 
	sizeof(upcr_pshared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_mem_handle) =
	{ UPCRI_IDENT_START_CHARS, 'm','e','m','_','h','a','n','d','l','e','=', 
	sizeof(upcr_handle_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_reg_handle) =
	{ UPCRI_IDENT_START_CHARS, 'r','e','g','_','h','a','n','d','l','e','=', 
	sizeof(upcr_valget_handle_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_void_ptr) =
	{ UPCRI_IDENT_START_CHARS, 'v','o','i','d','_','p','t','r','=', 
	sizeof(void *) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_ptrdiff_t) =
	{ UPCRI_IDENT_START_CHARS, 'p','t','r','d','i','f','f','_','t','=', 
	sizeof(ptrdiff_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_char) =
	{ UPCRI_IDENT_START_CHARS, 'c','h','a','r','=', 
	sizeof(char) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_int) =
	{ UPCRI_IDENT_START_CHARS, 'i','n','t','=', 
	sizeof(int) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_short) =
	{ UPCRI_IDENT_START_CHARS, 's','h','o','r','t','=', 
	sizeof(short) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_long) =
	{ UPCRI_IDENT_START_CHARS, 'l','o','n','g','=', 
	sizeof(long) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_longlong) =
	{ UPCRI_IDENT_START_CHARS, 'l','o','n','g','l','o','n','g','=', 
	sizeof(long long) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_float) =
	{ UPCRI_IDENT_START_CHARS, 'f','l','o','a','t','=', 
	sizeof(float) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_double) =
	{ UPCRI_IDENT_START_CHARS, 'd','o','u','b','l','e','=', 
	sizeof(double) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_longdouble) =
	{ UPCRI_IDENT_START_CHARS, 'l','o','n','g','d','o','u','b','l','e','=', 
	sizeof(long double) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_size_t) =
	{ UPCRI_IDENT_START_CHARS, 's','i','z','e','_','t','=', 
	sizeof(size_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

#if SIZEOF__BOOL
#define UPCRI_IDENT__BOOL_SIZE sizeof(_Bool)
#else
#define UPCRI_IDENT__BOOL_SIZE 1
#endif
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof__Bool) =
	{ UPCRI_IDENT_START_CHARS, '_','B','o','o','l','=', 
	UPCRI_IDENT__BOOL_SIZE + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_phasebits) =
	{ UPCRI_IDENT_START_CHARS, 'p','h','a','s','e','b','i','t','s','=',
	UPCRI_PHASE_BITS + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

/* 
 * Strings to pass the alignment of various data types to translator.  
 *   - the amount by which a type is padded in a struct tells us its alignment
 */

#define UPCRI_IDENT_START_ALIGN UPCRI_IDENT_START_CHARS ,'a','l','i','g','n','o','f','_'

#define UPCRI_ALIGNMENT_STRUCT(name, type) \
	struct _upcri_align_##name {       \
	    char __;                       \
	    type _;                        \
	}
#define UPCRI_ALIGNMENT_OF(name) \
	((char)(uintptr_t) &(((struct _upcri_align_##name *)0)->_)) 


UPCRI_ALIGNMENT_STRUCT(upcr_shared_ptr_t, upcr_shared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_shared_ptr) =
	{ UPCRI_IDENT_START_ALIGN, 's','h','a','r','e','d','_','p','t','r','=', 
	  UPCRI_ALIGNMENT_OF(upcr_shared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(upcr_pshared_ptr_t, upcr_pshared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_pshared_ptr) =
	{ UPCRI_IDENT_START_ALIGN, 'p','s','h','a','r','e','d','_','p','t','r','=', 
	  UPCRI_ALIGNMENT_OF(upcr_pshared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(upcr_handle_t, upcr_handle_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_mem_handle) =
	{ UPCRI_IDENT_START_ALIGN, 'm','e','m','_','h','a','n','d','l','e','=', 
	  UPCRI_ALIGNMENT_OF(upcr_handle_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(upcr_valget_handle_t, upcr_valget_handle_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_reg_handle) =
	{ UPCRI_IDENT_START_ALIGN, 'r','e','g','_','h','a','n','d','l','e','=', 
	  UPCRI_ALIGNMENT_OF(upcr_valget_handle_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(void_ptr, void *);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_void_ptr) =
	{ UPCRI_IDENT_START_ALIGN, 'v','o','i','d','_','p','t','r','=', 
	  UPCRI_ALIGNMENT_OF(void_ptr) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(ptrdiff_t, ptrdiff_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_ptrdiff_t) =
	{ UPCRI_IDENT_START_ALIGN, 'p','t','r','d','i','f','f','_','t','=', 
	  UPCRI_ALIGNMENT_OF(ptrdiff_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(char, char);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_int) =
	{ UPCRI_IDENT_START_ALIGN, 'c','h','a','r','=', 
	  UPCRI_ALIGNMENT_OF(char) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(int, int);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_char) =
	{ UPCRI_IDENT_START_ALIGN, 'i','n','t','=', 
	  UPCRI_ALIGNMENT_OF(int) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(short, short);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_short) =
	{ UPCRI_IDENT_START_ALIGN, 's','h','o','r','t','=', 
	  UPCRI_ALIGNMENT_OF(short) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(long, long);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_long) =
	{ UPCRI_IDENT_START_ALIGN, 'l','o','n','g','=', 
	  UPCRI_ALIGNMENT_OF(long) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(longlong, long long);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_longlong) =
	{ UPCRI_IDENT_START_ALIGN, 'l','o','n','g','l','o','n','g','=', 
	  UPCRI_ALIGNMENT_OF(longlong) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(float, float);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_float) =
	{ UPCRI_IDENT_START_ALIGN, 'f','l','o','a','t','=', 
	  UPCRI_ALIGNMENT_OF(float) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(double, double);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_double) =
	{ UPCRI_IDENT_START_ALIGN, 'd','o','u','b','l','e','=', 
	  UPCRI_ALIGNMENT_OF(double) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(longdouble, long double);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_longdouble) =
	{ UPCRI_IDENT_START_ALIGN, 'l','o','n','g','d','o','u','b','l','e','=', 
	  UPCRI_ALIGNMENT_OF(longdouble) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNMENT_STRUCT(size_t, size_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_size_t) =
	{ UPCRI_IDENT_START_ALIGN, 's','i','z','e','_','t','=', 
	  UPCRI_ALIGNMENT_OF(size_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

#if SIZEOF__BOOL
UPCRI_ALIGNMENT_STRUCT(_Bool, _Bool);
#define UPCRI_IDENT__BOOL_ALIGN UPCRI_ALIGNMENT_OF(_Bool)
#else
#define UPCRI_IDENT__BOOL_ALIGN 1
#endif
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof__Bool) =
	{ UPCRI_IDENT_START_ALIGN, '_','B','o','o','l','=', 
	  UPCRI_IDENT__BOOL_ALIGN + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

/* Power-stupidity:  on (some?) Power chips, even though alignof(double) is 4,
 * if a double is the first member of a struct, alignof(struct) is 8.
 * - Detect this by seeing if sizeof struct { double, char } == 16 instead of
 *   12.
 */
#define UPCRI_TYPECHAR_STRUCT(name, type) \
	struct _upcri_typechar_##name {       \
		type _;                        \
		char __;                       \
	}
#define UPCRI_TYPECHAR_SIZE(name) \
	sizeof(struct _upcri_typechar_##name)

UPCRI_TYPECHAR_STRUCT(double, double);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_dbl_1st_struct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'd','b','l','c','h','a','r','_','s','t','r','u','c','t','=',
	  UPCRI_TYPECHAR_SIZE(double) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

/* Power-stupidity:  on (some?) Power chips + O/S, 64-bit ints have the same
 * alignment exception described above for doubles.
 * Also need shared_ptr_t and pshared_ptr_t in case they are 64-bit integer types
 */
UPCRI_TYPECHAR_STRUCT(int64_t, int64_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_int64_1st_struct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'i','n','t','6','4','c','h','a','r','_','s','t','r','u','c','t','=',
	  UPCRI_TYPECHAR_SIZE(int64_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };
UPCRI_TYPECHAR_STRUCT(upcr_shared_ptr_t, upcr_shared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_upcr_shared_ptr_t_1st_struct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  's','p','t','r','c','h','a','r','_','s','t','r','u','c','t','=',
	  UPCRI_TYPECHAR_SIZE(upcr_shared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };
UPCRI_TYPECHAR_STRUCT(upcr_pshared_ptr_t, upcr_pshared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_upcr_pshared_ptr_t_1st_struct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'p','s','p','t','r','c','h','a','r','_','s','t','r','u','c','t','=',
	  UPCRI_TYPECHAR_SIZE(upcr_pshared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

/* bug1452: Further Power oddities:  on Power chips with some OS and compiler flag combos,
 * 64-bit datatypes with the above alignment exceptions may or may not have those 
 * alignments enforced when the relevant field resides in a struct contained within 
 * a larger struct - specifically, the compiler might or might not insert padding in the
 * outer struct to enforce the alignment exceptions of the contained structs
 * Here we create such a situtation and measure the alignment of an inner struct field
 * when the containing struct has specified a misaligned placement
 */
struct _upcri_innerstruct1 {
  char __f1;
};
#define UPCRI_ALIGNOF_INNERSTRUCT_SETUP(name, type)     \
	struct _upcri_innerstruct2_##name {             \
		type __f2;                              \
		char __f3;                              \
        };                                              \
	struct _upcri_outerstruct_##name {              \
		struct _upcri_innerstruct1 __s1;        \
		struct _upcri_innerstruct2_##name __s2; \
        } 

#define UPCRI_ALIGNOF_INNERSTRUCT(name) \
	((uintptr_t)&(((struct _upcri_outerstruct_##name *)NULL)->__s2.__f2))

UPCRI_ALIGNOF_INNERSTRUCT_SETUP(double, double);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_double_innerstruct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'd','b','l','_','i','n','n','e','r','s','t','r','u','c','t','=',
	  UPCRI_ALIGNOF_INNERSTRUCT(double) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNOF_INNERSTRUCT_SETUP(int64_t, int64_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_int64_t_innerstruct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'i','n','t','6','4','_','i','n','n','e','r','s','t','r','u','c','t','=',
	  UPCRI_ALIGNOF_INNERSTRUCT(int64_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNOF_INNERSTRUCT_SETUP(upcr_shared_ptr_t, upcr_shared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_upcr_shared_ptr_t_innerstruct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  's','p','t','r','_','i','n','n','e','r','s','t','r','u','c','t','=',
	  UPCRI_ALIGNOF_INNERSTRUCT(upcr_shared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

UPCRI_ALIGNOF_INNERSTRUCT_SETUP(upcr_pshared_ptr_t, upcr_pshared_ptr_t);
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_alignof_upcr_pshared_ptr_t_innerstruct) = 
	{ UPCRI_IDENT_START_CHARS, 
	  'p','s','p','t','r','_','i','n','n','e','r','s','t','r','u','c','t','=',
	  UPCRI_ALIGNOF_INNERSTRUCT(upcr_pshared_ptr_t) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };

/* bug1452: Even MORE Power oddities: an exception to the previous rule may exist for
 * nested structs in which we use the strictest alignment of any type involved.
 */
struct _upcri_structpromote {
  char   __f1;
  struct _upcri_typechar_int64_t __f2;
};
UPCRI_IDENT_CHAR_ARRAY(upcri_IdentString_sizeof_structpromote) = 
	{ UPCRI_IDENT_START_CHARS, 
          's','t','r','u','c','t','_','p','r','o','m','o','t','e','=',
	  sizeof(struct _upcri_structpromote) + UPCRI_IDENT_MAGIC_OFFSET, ' ','$','\0' };
