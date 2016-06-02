/*  $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_preinclude/pupc.h $ */
/* Description: UPC Profiling end-user interface */
/* Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> */

#ifndef _PUPC_H_
#define _PUPC_H_
#pragma upc upc_code

#if !defined(__BERKELEY_UPC_FIRST_PREPROCESS__) && !defined(__BERKELEY_UPC_ONLY_PREPROCESS__)
#error This file should only be included during initial preprocess
#endif

#if UPCRI_LIBWRAP
/* handled by upcr.h */
#else
/* these all compile away to nothing if profiling is off */
unsigned int pupc_create_event(const char *name, const char *desc);
int pupc_control(int on);
void pupc_event_start(unsigned int evttag, ...);
void pupc_event_end(unsigned int evttag, ...);
void pupc_event_atomic(unsigned int evttag, ...);
#endif

#endif
