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
#include "operators.naive/buffer_copy.c"
#include "operators.naive/ghosts.c"
#include "operators.reference/exchange_boundary.aggregate.c"
#include "operators.ompif/smooth.c"
#include "operators.ompif/residual.c"
#include "operators.ompif/restriction.c"
#include "operators.ompif/interpolation.c"
#include "operators.naive/misc.c"
#include "operators.ompif/max_norm.c"
//------------------------------------------------------------------------------------------------------------------------------
