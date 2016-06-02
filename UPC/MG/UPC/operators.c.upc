#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include "supc.h"

#include "timer.h"
#include "defines.h"
#include "box.h"
#include "mg.h"
#include "operators.h"

#include "../operators.naive/buffer_copy.c"
#include "../operators.naive/ghosts.c"
#include "operators.upc/exchange_boundary.aggregate.c"
#include "../operators.ompif/smooth.c"
#include "../operators.reference/residual.c"
#include "../operators.ompif/restriction.c"
#include "../operators.ompif/interpolation.c"
#include "../operators.naive/misc.c"
#include "operators.upc/max_norm.c"
