#include <stdio.h>
#include "bug3038.h"

int flag = 1;

int main(void) {
	set_flag( 0 );
	puts( flag ? "FAIL" : "PASS" );
	return flag;
}
