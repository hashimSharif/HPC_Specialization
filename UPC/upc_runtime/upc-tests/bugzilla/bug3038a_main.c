#include <stdio.h>
#include "bug3038a.h"

int flag = 1;
shared int error = 0;

int main(void) {
	set_flag( MYTHREAD );
	upc_barrier;

	if ( flag != MYTHREAD ) error = 1;
	upc_barrier;

	if ( !MYTHREAD )
		puts( error? "FAIL" : "PASS" );
	return error;
}
