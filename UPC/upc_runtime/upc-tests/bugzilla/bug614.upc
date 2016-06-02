#include <stdio.h>
#include <stdlib.h>

#ifdef hz
/* fix a bizarre name space corruption on AIX */
#undef hz
#endif
typedef struct {
                        double p_real;
                        double p_imag;
                } complex;

struct fieldstruct {
                        complex ex;
                        complex ey;
                        complex ez;
                        complex hx;
                        complex hy;
                        complex hz;
                    };

/* Define double-complex multiplication */
complex dcmult(double d, complex c)
{
        complex result;


        result.p_real = d*c.p_real;
        result.p_imag = d*c.p_imag;


        return result;
}

double feed1, feed2, feed3, feed4;

void sourcef(int istep, int **isbox, shared [ ] struct fieldstruct *fields,
             shared [ ] struct fieldstruct *fields_source) {

        complex zero, temp1, temp2, temp3, temp4;
        int i = 0;


temp1 = dcmult(feed1, fields[i].ez);
printf("SUCCESS\n");
}

shared [ ] struct fieldstruct my_fields[10];
int main() { 
sourcef(0, NULL, (shared [ ] struct fieldstruct*)&my_fields, NULL);
return 0; 
}

