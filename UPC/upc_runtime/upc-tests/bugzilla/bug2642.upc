#include <stdio.h>

struct one {							// sizeof(struct one)   = 308 bytes
	int a;									// 4 bytes
	struct two {						// sizeof(struct two)   = 152 bytes
		int b;								// 4 bytes
		int c;								// 4 bytes
		struct three {				// sizeof(struct three) = 48 bytes
			struct four {				// sizeof(struct four)  = 12 bytes
				int d;
				struct five {			// sizeof(struct five)  = 8 bytes
					int e;
					int f;
				} five;
			} four[4];
		} three[3];
	} two[2];
} one;

int get_index(int x) { return x+1; }

int main ()
{
	struct one foo, foo_arr[2], *p_foo;
	int size1 = sizeof(struct one);
	int size2 = sizeof(struct two);
	int size3 = sizeof(struct three);
	int size4 = sizeof(struct four);
	int size5 = sizeof(struct five);
	int i, j;

	i = get_index(0);
	j = get_index(1);

	/*******************************************************************
	 **                   Array of Struct TYPE I                      **
	 *******************************************************************/

	p_foo = &foo;
	/*******************************************
	 **  Array of Struct TYPE I: example 1    **
	 *******************************************/
	foo.two[i].b = 101;  
	if ( *(int *)((char *)p_foo + 4 + 1*size2) != 101 )
		fprintf(stderr, "Error: array of struct type I example 1\n");

	/*******************************************
		*  Array of Struct TYPE I: example 2    **
		******************************************/
	foo.two[1].three[2].four[3].d = 102;
	if ( *(int *)((char *)p_foo + 4 + 1*size2 + 8 + 2*size3 + 3*size4) != 102 )
		fprintf(stderr, "Error: array of struct type I example 2\n");

	/*******************************************
	 **  Array of Struct TYPE I: example 3    **
	 *******************************************/
	foo.two[1].three[2].four[3].five.e = 103; 
	if ( *(int *)((char *)p_foo + 4 + 1*size2 + 8 + 2*size3 + 3*size4 + 4) != 103 )
		fprintf(stderr, "Error: array of struct type I example 3\n");


	/*******************************************************************
	 **                   Array of Struct TYPE II                     **
	 *******************************************************************/
	p_foo = foo_arr;

	/*******************************************
	 **  Array of Struct TYPE II: example 1   **
	 *******************************************/
	foo_arr[i].a = 201;
	if ( *(int *)((char *)p_foo + size1) != 201 )
		fprintf(stderr, "Error: array of struct type II example 1\n");

	/*******************************************
	 **  Array of Struct TYPE II: example 1   **
	 *******************************************/
	foo_arr[1].two[1].c = 202;                          
	if ( *(int *)((char *)p_foo + size1 + 4 + 1*size2 + 4) != 202 )
		fprintf(stderr, "Error: array of struct type II example 2\n");

	/*******************************************
	 **  Array of Struct TYPE II: example 1   **
	 *******************************************/
	foo_arr[1].two[1].three[2].four[3].five.e = 203;   
	if ( *(int *)((char *)p_foo + size1 + 4 + 1*size2 + 8 + 2*size3 + 3*size4 + 4) != 203 )
		fprintf(stderr, "Error: array of struct type II example 3\n");


	/*******************************************************************
	 **                   Array of Struct TYPE III                    **
	 *******************************************************************/

	/*******************************************
	 **  Array of Struct TYPE III: example 1  **
	 *******************************************/
	p_foo = &foo;
	foo.two[i].three[j].four[j+1].five.f = 301;
	if ( *(int *)((char *)p_foo + 4 + 1*size2 + 8 + 2*size3 + 3*size4 + 8) != 301 )
		fprintf(stderr, "Error: array of struct type III example 1\n");

	/*******************************************
	 **  Array of Struct TYPE III: example 2  **
	 *******************************************/
	p_foo = &foo_arr[0];
	foo_arr[1].two[1].three[2].four[3].five.f = 302;
	if ( *(int *)((char *)p_foo + size1 + 4 + 1*size2 + 8 + 2*size3 + 3*size4 + 8) != 302 )
		fprintf(stderr, "Error: array of struct type III example 2\n");

	/*******************************************
	 **  Array of Struct TYPE III: example 3  **
	 *******************************************/
	p_foo = &foo_arr[0];
	foo_arr[i].two[i].three[j].four[j+1].five.f = 303;
	if ( *(int *)((char *)p_foo + size1 + 4 + 1*size2 + 8 + 2*size3 + 3*size4 + 8) != 303 )
		fprintf(stderr, "Error: array of struct type III example 2\n");

	printf("done.\n");

	return 0;
}

