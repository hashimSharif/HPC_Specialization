/* _test_globalexit.c: test the functionality of the upc_global_exit().

        Date created    : December 16, 2002
        Date modified   : December 16, 2002

	Function tested: upc_globalexit.

        Description:
	- Test correctness of upc_global_exit() function. 

        Platform Tested         No. Proc        Date Tested             Success
	UPC0			2,4		December 16, 2002	No
	CSE0			2,4,8,12	December 16, 2002	No
	LION			2,4,8,16,32	December 16, 2002	No

	Bugs Found:
	[12/16/2002] On upc0, the upc_global_exit function has not been implemented on MuPC
		     yet. The following error message was received:
				Unresolved:
				_UPCRTS_global_exit
	[12/16/2002] On cse0, Same as above. 
	[12/16/2002] On lionel, same as above.
*/

#include <upc.h>
#include <stdio.h>
#include <string.h>

int main (void) 
{
	upc_global_exit(0);
   
        printf("Error: test_globalexit.c failed! [th=%d]\n", THREADS);
	return 1;
}

