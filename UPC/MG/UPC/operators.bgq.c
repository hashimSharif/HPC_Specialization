//------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
//------------------------------------------------------------------------------------------------------------------------------
#include "timer.h"
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"
//------------------------------------------------------------------------------------------------------------------------------
#include "operators.bgq/buffer_copy.c"
#include "operators.bgq/ghosts.c"
#include "operators.reference/exchange_boundary.aggregate.c"
#include "operators.bgq/smooth.c"
#include "operators.reference/residual.c"
#include "operators.naive/restriction.c"
#include "operators.naive/interpolation.c"
#include "operators.naive/misc.c"
#include "operators.naive/max_norm.c"
//------------------------------------------------------------------------------------------------------------------------------
//#warning Sam, you commented out the include for _xlc_v4d.h on Tuesday 2/19
//#include "/soft/compilers/ibmcmp-aug2012-interim120809/vac/bg/12.1/include/internal/_xlc_v4d.h"
