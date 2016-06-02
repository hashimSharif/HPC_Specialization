/*
 * Copyright (c)  2012, Mellanox Technologies LTD. All rights reserved.
 */

#ifndef UPCR_FCA_H
#define UPCR_FCA_H

typedef enum {
    fca_sc,
    fca_uc,
    fca_ss,
    fca_us,
    fca_si,
    fca_ui,
    fca_sl,
    fca_ul,
    fca_f,
    fca_d,
    fca_ld
} fca_reduce_type_t;

#define UNSUPPORTED_OP     -1

extern int upcr_fca_reduce(int root,  void *target, const void *source, upc_op_t op, fca_reduce_type_t type, int flags);
extern int upcr_fca_reduce_all( void *target, const void *source, upc_op_t op, fca_reduce_type_t type, int flags);
extern int upcr_my_partial_dummy_init(void *my_partial, upc_op_t op, fca_reduce_type_t type);


#define COUNT_DUMMY_THREADS do{         \
    int i;                              \
    size_t my_skipped, i_count;         \
    for (i=0; i<upcri_threads; i++){    \
        if (i < start_thread) {         \
            my_skipped = blk_size;      \
        } else if (i == start_thread) { \
            i_count = start_phase;      \
        } else {                        \
            i_count = 0;                \
        }                               \
        i_count = blk_size * rows - i;  \
        if (i < end_thread) {           \
            i_count += blk_size;        \
        } else if (i == end_thread) {   \
            i_count += end_phase;       \
        }                               \
        if (0 == i_count){              \
            dummy_counter++;            \
        }                               \
    }                                   \
}                                       \
while(0)

#define XOR_RESULT do {                          \
    char *p = (char *)upcr_shared_to_local(dst); \
    size_t size = sizeof(UPCRI_COLL_RED_TYPE);   \
    int i;                                       \
    for (i=0; i<size; i++){                      \
        *p ^= 0;                                 \
        p++;                                     \
    }                                            \
}                                                \
while(0)

#define DECLARE_FCA_PREP_FN(name, suff, args, ...) \
    static inline \
    void fca##name##suff##_fn( args ) {\
        __VA_ARGS__\
    }\

#define CALL_FCA_PREP_FN(name, suff, args, ...) \
     fca##name##suff##_fn( args )

#define EVAL(MACRO, X, Y, ARGS, ...) MACRO(X, Y, ARGS, __VA_ARGS__)

EVAL(DECLARE_FCA_PREP_FN, type, UC, fca_reduce_type_t *type, *type=fca_uc;);
EVAL(DECLARE_FCA_PREP_FN, type, C,  fca_reduce_type_t *type, *type=fca_sc;);
EVAL(DECLARE_FCA_PREP_FN, type, US, fca_reduce_type_t *type, *type=fca_us;);
EVAL(DECLARE_FCA_PREP_FN, type, S,  fca_reduce_type_t *type, *type=fca_ss;);
EVAL(DECLARE_FCA_PREP_FN, type, UI, fca_reduce_type_t *type, *type=fca_ui;);
EVAL(DECLARE_FCA_PREP_FN, type, I,  fca_reduce_type_t *type, *type=fca_si;);
EVAL(DECLARE_FCA_PREP_FN, type, UL, fca_reduce_type_t *type, *type=fca_ul;);
EVAL(DECLARE_FCA_PREP_FN, type, L,  fca_reduce_type_t *type, *type=fca_sl;);
EVAL(DECLARE_FCA_PREP_FN, type, F,  fca_reduce_type_t *type, *type=fca_f; );
EVAL(DECLARE_FCA_PREP_FN, type, D,  fca_reduce_type_t *type, *type=fca_d; );
EVAL(DECLARE_FCA_PREP_FN, type, LD, fca_reduce_type_t *type, *type=fca_ld;);
#endif 
