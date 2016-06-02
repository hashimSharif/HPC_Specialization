
#ifndef __DETECT_UPC_H
#define __DETECT_UPC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void handle_include(char *line_directive);
void mark_as_upc(char *keyword, int isPragma);
void mark_as_c(char *keyword);
void insert_pragma(char *text);
void print_out(char *str, int len);

/* mode flags */
extern int prefix_threads;
extern int xform_misc;
extern int do_output;
extern int in_c;

/* suspend/resume pragma insertion */
extern int insert_suspend;

enum mark_reason {
    PRAGMA = 1,
    SUFFIX,
    LEXXER
};

/* This gets rid of a flex warning */
#define YY_NO_UNPUT

#endif /* __DETECT_UPC_H */

