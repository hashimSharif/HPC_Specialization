UPC collectives value interface, v1.2
Copyright 2005, Dan Bonachea <bonachea@cs.berkeley.edu> 
Distributed under BSD license.
http://upc.lbl.gov
$Revision: 1.6 $

********************
*** Introduction ***
********************

This library wrapper provides a value-based convenience interface to the UPC
collectives library that is part of UPC 1.2. There is a small amount of
optimization for Berkeley UPC, but the library is generic and can be used with
any fully UPC-1.2 compliant implementation of the UPC collectives library. All
operations are implemented as thin wrappers around that library.

In most cases, operands to this library are simple values, and nothing is
required to be single-valued except for the data type in use and the root
thread identifier (in the case of rooted collectives). This library does not
provide a bulk (array-based) data movement interface - if you want to perform
collectives over more than a single scalar value per thread, you should use the
full UPC collectives interface. The purpose of this wrapper is to provide 
convenience for scalar-based collective operations, especially in cases where
there are not multiple values available to be communicated in aggregate (in
which case the full array-based UPC collectives interface is likely to use
fewer messages and achieve better performance) or for use in setup code (where
performance is secondary to simplicity).  

***************************
*** Common requirements ***
***************************

All client code should #include <bupc_collectivev.h>

These are all "collective" operations per the UPC spec, so the regular rules
apply - namely, matching calls must be made on all threads in the same order,
and calls may not be invoked between upc_notify and upc_wait.

All 'rootthread' arguments indicate the thread identifier for the root
of the collective operation (eg the source of a broadcast or the destination of
a gather), and must be single-values (all threads must pass the same 'rootthread'
argument).

All 'value' arguments indicate an l-value which is the current thread's data
input to the collective operation. 'value' MUST be an l-value (ie a variable
or array element) - it cannot be a literal or an arbitrary expression. Use a
temporary local variable if necessary. 

All 'TYPE' arguments should be passed the scalar type of the current
value-based collective operation.  If there is a 'value' argument, then 'TYPE'
must be the type of 'value'.  TYPE need not be a built-in type, it may be a
typedef - however it must always match exactly across all threads. In the case
of data movement collectives this may be a scalar type or an aggregate (struct 
or union) type. For the computational collectives (reductions) it must be a 
scalar type.

BUPC_COLLECTIVEV_VERSION_MAJOR and BUPC_COLLECTIVEV_VERSION_MINOR are integral constants
defined by the header which indicate the interface version number implemented,
corresponding to the version number at the top of this document.

Here are the operations currently supported:

*********************************
*** COMPUTATIONAL COLLECTIVES ***
*********************************

All 'reductionop' variables require a upc_op_t constant as defined in the UPC
collectives spec:

  UPC_ADD, UPC_MULT, UPC_AND, UPC_OR, UPC_XOR, 
  UPC_LOGAND, UPC_LOGOR, UPC_MIN, UPC_MAX

UPC_FUNC and UPC_NONCOMM_FUNC are not currently supported.

*** TYPE bupc_allv_reduce(TYPE, TYPE value, int rootthread, upc_op_t reductionop)

Reduce 'value' (which has type TYPE) across all threads using 'reductionop',
and return the result on thread 'rootthread'. Other threads should ignore the
return value. If rootthread is passed -1, then the call is equivalent to 
bupc_allv_reduce_all (ie all threads get the result).

Ex:
double myvalue = ...; 
double result = bupc_allv_reduce(double, myvalue, 0, UPC_ADD); /* sum-reduce to zero */

*** TYPE bupc_allv_reduce_all(TYPE, TYPE value, upc_op_t reductionop)

Reduce 'value' (which has type TYPE) across all threads using 'reductionop',
and return the result on all threads.

Ex:
double myvalue = ...; 
double result = bupc_allv_reduce_all(double, myvalue, UPC_ADD); /* sum-reduce to all */


*** TYPE bupc_allv_prefix_reduce(TYPE, TYPE value, upc_op_t reductionop)

Perform a prefix reduction of 'value' (which has type TYPE) across all 
threads using 'reductionop', and return the corresponding inclusive
prefix-reduction result to each thread (ie thread i gets 
(value0 OP ... OP valuei) ).

Ex:
double myvalue = ...; 
double result = bupc_allv_prefix_reduce(double, myvalue, UPC_ADD);

*********************************
*** DATA MOVEMENT COLLECTIVES ***
*********************************

*** TYPE bupc_allv_broadcast(TYPE, TYPE value, int rootthread)

Broadcast 'value' (which has type TYPE) from thread 'rootthread'. 
The result is returned on all threads.

Ex:
double myvalue = ...; /* init on thread 0 */
double result = bupc_allv_broadcast(double, myvalue, 0); /* broadcast to all */

*** TYPE bupc_allv_scatter(TYPE, int rootthread, TYPE *rootsrcarray)

Scatter an array of THREADS values from a 'rootthread' to each thread.
'rootsrcarray' is a local source array on 'rootthread' containing THREADS
values of type TYPE in order by destination thread.  'rootsrcarray' is ignored
on other threads. All threads return the value they receive.

Ex:
double result; 
if (MYTHREAD != 0) {
  result = bupc_allv_scatter(double, 0, NULL); /* recv scatter from zero */
} else { /* MYTHREAD == i */
  double *src = malloc(THREADS*sizeof(double));
  /* init src[0], src[1]... */
  result = bupc_allv_scatter(double, 0, src); /* send scatter from zero */
  free(src);
}
/* use result ... */

*** TYPE *bupc_allv_gather(TYPE, TYPE value, int rootthread, TYPE *rootdestarray)

Gather a 'value' (which has type TYPE) from each thread to 'rootthread', and
place them (in order by source thread) into the local array 'rootdestarray' on
'rootthread'.  'rootdestarray' is returned on 'rootthread', and ignored on
other threads. If rootthread is passed -1, then the call is equivalent to 
bupc_allv_gather_all (ie all threads get the result).

Ex:
double myvalue = ...; 
if (MYTHREAD != 0) {
  bupc_allv_gather(double, myvalue, 0, NULL); /* gather to zero */
} else { /* MYTHREAD == rootid */
  double *result = malloc(THREADS*sizeof(double));
  bupc_allv_gather(double, myvalue, 0, result); /* gather to zero */
  ... result[0] ... result[1]... /* use result ... */
}

*** TYPE *bupc_allv_gather_all(TYPE, TYPE value, TYPE *destarray)

Gather a 'value' (which has type TYPE) from each thread to all threads, and
place them (in order by source thread) into the local array 'destarray' on each
thread.  Each thread may pass a different 'destarray'. 'destarray' is returned.
'destarray' is permitted to be NULL on some threads, in which case those threads
discard their copy of the gathered data.

Ex:
double myvalue = ...; 
double *result = malloc(THREADS*sizeof(double));
bupc_allv_gather_all(double, myvalue, result); /* gather to all threads */
... result[0] ... result[1]... /* use result ... */


*** TYPE bupc_allv_permute(TYPE, TYPE value, int tothreadid)

Perform a permutation of 'value's across all threads. Each thread passes a
value and a unique thread identifier to receive it - each thread returns the
value it receives.

Ex:
double myvalue = ...; 
int result = bupc_allv_permute(double, myvalue, 
                               (MYTHREAD+1)%THREADS); /* send to right neighbor */


***********************
*** TROUBLESHOOTING ***
***********************

See bupc_collectivev_test.upc for more extensive examples which also serve as a
correctness test for the library.

When compiled in debug mode (automatically for Berkeley UPC debug mode,
otherwise using -DBUPC_COLLECTIVEV_DEBUG=1) the library includes some minimal
sanity checking to try and ensure the usage rules are not being broken.  If the
code deadlocks or produces strange compilation errors, you're probably using it
incorrectly (see usage info above).

