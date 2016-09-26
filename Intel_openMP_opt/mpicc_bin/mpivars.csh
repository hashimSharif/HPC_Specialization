#! /bin/tcsh
#
# Copyright (C) 2003-2014 Intel Corporation.  All Rights Reserved.
# 
# The source code contained or described herein and all documents
# related to the source code ("Material") are owned by Intel Corporation
# or its suppliers or licensors.  Title to the Material remains with
# Intel Corporation or its suppliers and licensors.  The Material is
# protected by worldwide copyright and trade secret laws and treaty
# provisions.  No part of the Material may be used, copied, reproduced,
# modified, published, uploaded, posted, transmitted, distributed, or
# disclosed in any way without Intel's prior express written permission.
# 
# No license under any patent, copyright, trade secret or other
# intellectual property right is granted to or conferred upon you by
# disclosure or delivery of the Materials, either expressly, by
# implication, inducement, estoppel or otherwise.  Any license under
# such intellectual property rights must be express and approved by
# Intel in writing.
#

setenv I_MPI_ROOT /opt/intel//impi/5.0.2.044

if !($?PATH) then
    setenv PATH ${I_MPI_ROOT}/intel64/bin
else
    setenv PATH ${I_MPI_ROOT}/intel64/bin:${PATH}
endif

if !($?LD_LIBRARY_PATH) then
    setenv LD_LIBRARY_PATH ${I_MPI_ROOT}/intel64/lib
else
    setenv LD_LIBRARY_PATH ${I_MPI_ROOT}/intel64/lib:${LD_LIBRARY_PATH}
endif

if !($?MANPATH) then
    if ( `uname -m` == "k1om" ) then
        setenv MANPATH ${I_MPI_ROOT}/man
    else
        setenv MANPATH ${I_MPI_ROOT}/man:`manpath`
    endif
else
    setenv MANPATH ${I_MPI_ROOT}/man:${MANPATH}
endif

if ( $# > 0 ) then
    if ( "$1" == "debug" || "$1" == "release" || "$1" == "debug_mt" || "$1" == "release_mt" ) then
        setenv LD_LIBRARY_PATH ${I_MPI_ROOT}/intel64/lib/${1}:${LD_LIBRARY_PATH}
    endif
endif
