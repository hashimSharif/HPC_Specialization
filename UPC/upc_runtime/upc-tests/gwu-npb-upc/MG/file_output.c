#include <stdio.h>
#include <upc_relaxed.h>

#include "globals.h"
#include "file_output.h"

shared [] char sh_filename[64];

void file_output(void)
{
    int th, i, j, k, m;
    FILE *out;
    char filename[64];

    if( MYTHREAD == 0 )
    {
        sprintf(filename, "output.MG.%c.%d.txt", Class, THREADS);
        upc_memput( sh_filename, filename, sizeof( filename ));
    }

    for( th=0; th<THREADS; th++ )
    {
        if( th==MYTHREAD )
        {
            upc_memget( filename, sh_filename, sizeof( filename ));

            printf("TH%02d: dumping vars into %s\n",
                    MYTHREAD, filename );

            if( MYTHREAD == 0 )
                out = fopen(filename, "wt");
            else
                out = fopen(filename, "at");

            if( out == NULL )
            {
                printf("TH%02d: can not open file %s\n",
                        MYTHREAD, filename );
                upc_global_exit(0);
            }

            // file output for THREAD th
            fprintf( out, "TH%02d: sh_a = { %.6lf %.6lf %.6lf %.6lf }\n",
                    MYTHREAD, sh_a[0], sh_a[1], sh_a[2], sh_a[3] );
            fprintf( out, "TH%02d: sh_c = { %.6lf %.6lf %.6lf %.6lf }\n",
                    MYTHREAD, sh_c[0], sh_c[1], sh_c[2], sh_c[3] );
            fprintf( out, "TH%02d: -- %d %d %d %d %d %d %.6lf %.6lf --\n",
                    MYTHREAD, sh_nit, sh_nx, sh_ny, sh_nz, sh_lt, sh_lb,
                    s, max);
            fprintf( out, "TH%02d: -- %d %d --\n",
                    MYTHREAD, lt, lb );
            for( m=0; m<MAXLEVEL+1; m++ )
            {
                fprintf( out, "TH%02d: [%2d] nx[]=%d ny[]=%d nz[]=%d\n",
                        MYTHREAD, m, nx[m], ny[m], nz[m] );
                fprintf( out, "TH%02d: [%2d] m1[]=%d m2[]=%d m3[]=%d",
                        MYTHREAD, m, m1[m], m2[m], m3[m] );
                if( m != MAXLEVEL )
                    fprintf( out, " ir[]=%d", ir[m] );
                fprintf( out, "\n");
                fprintf( out, "TH%02d: [%2d] nbr[4][2][] = { %d %d %d %d %d %d %d %d }\n",
                        MYTHREAD, m, 
                        nbr[0][0][m], nbr[0][1][m],
                        nbr[1][0][m], nbr[1][1][m],
                        nbr[2][0][m], nbr[2][1][m],
                        nbr[3][0][m], nbr[3][1][m] );
                fprintf( out, "TH%02d: [%2d] dead[]=%d give_ex[4][]={ %d %d %d %d } take_ex[4][]={ %d %d %d %d }\n",
                        MYTHREAD, m, 
                        dead[m],
                        give_ex[0][m], give_ex[1][m], give_ex[2][m], give_ex[3][m],
                        take_ex[0][m], take_ex[1][m], take_ex[2][m], take_ex[3][m] );
            }

            // sh_u
            for( m=lt; m>=1; m-- )
            {
                for( k=0; k<m3[m]; k++ )
                {
                    for( j=0; j<m2[m]; j++ )
                    {
                        for( i=0; i<m1[m]; i++ )
                        {
                            fprintf( out, "TH%02d: sh_u[%3d].arr[%d][%d][%d] = %.6lf\n",
                                    MYTHREAD, MYTHREAD+(m*THREADS),
                                    k, j, i,
                                    sh_u[MYTHREAD+(m*THREADS)].arr[(((k*m2[m])+j)*m1[m])+i]);
                        }
                    }
                }
            }

            // sh_r
            for( m=lt; m>=1; m-- )
            {
                for( k=0; k<m3[m]; k++ )
                {
                    for( j=0; j<m2[m]; j++ )
                    {
                        for( i=0; i<m1[m]; i++ )
                        {
                            fprintf( out, "TH%02d: sh_r[%3d].arr[%d][%d][%d] = %.6lf\n",
                                    MYTHREAD, MYTHREAD+(m*THREADS),
                                    k, j, i,
                                    sh_r[MYTHREAD+(m*THREADS)].arr[(((k*m2[m])+j)*m1[m])+i]);
                        }
                    }
                }
            }

            // sh_v
            for( k=0; k<m3[lt]; k++ )
            {
                for( j=0; j<m2[lt]; j++ )
                {
                    for( i=0; i<m1[lt]; i++ )
                    {
                        fprintf( out, "TH%02d: sh_u[%3d].arr[%d][%d][%d] = %.6lf\n",
                                MYTHREAD, MYTHREAD+(m*THREADS),
                                k, j, i,
                                sh_v[MYTHREAD].arr[(((k*m2[lt])+j)*m1[lt])+i]);
                    }
                }
            }

            fclose( out );
        }
        upc_barrier;
    }
}
