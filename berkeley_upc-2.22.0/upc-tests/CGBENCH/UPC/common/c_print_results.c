/*****************************************************************/
/******     C  _  P  R  I  N  T  _  R  E  S  U  L  T  S     ******/
/*****************************************************************/
#include <stdlib.h> 
#include <stdio.h>  
void c_print_results( const char   *name,
                      char   class,
                      int    n1,
                      int    n2,
                      int    n3,
                      int    niter,
		      int    nthreads,
                      double t,
                      double mops,
		      const char   *optype,
                      int    passed_verification,
                      const char   *npbversion,
                      const char   *compiletime,
                      const char   *cc,
                      const char   *clink,
                      const char   *c_lib,
                      const char   *c_inc,
                      const char   *cflags,
                      const char   *clinkflags,
		      const char   *rand)
{
    const char *evalue="1000";
	FILE * f_pt= fopen("upc_result", "a+");

    fprintf(f_pt, "\n\n %s Benchmark Completed\n", name );

    fprintf( f_pt, " Class           =                        %c\n", class );

    if( n2 == 0 && n3 == 0 )
        fprintf(f_pt, " Size            =             %12d\n", n1 );   /* as in IS
*/
    else
        fprintf( f_pt, " Size            =              %3dx%3dx%3d\n", n1,n2,n3 );

    fprintf( f_pt, " Iterations      =             %12d\n", niter );

    fprintf( f_pt, " Threads         =             %12d\n", nthreads );

    fprintf( f_pt, " Time in seconds =             %12.2f\n", t );

    fprintf( f_pt, " Mop/s total     =             %12.2f\n", mops );

    fprintf( f_pt, " Operation type  = %24s\n", optype);

    if( passed_verification )
        fprintf( f_pt, " Verification    =               SUCCESSFUL\n" );
    else
        fprintf( f_pt, " Verification    =             UNSUCCESSFUL\n" );

    fprintf( f_pt, " Version         =             %12s\n", npbversion );

    fprintf( f_pt, " Compile date    =             %12s\n", compiletime );

    fprintf( f_pt, "\n Compile options:\n" );

    fprintf( f_pt, "    CC           = %s\n", cc );

    fprintf( f_pt, "    CLINK        = %s\n", clink );

    fprintf( f_pt, "    C_LIB        = %s\n", c_lib );

    fprintf( f_pt, "    C_INC        = %s\n", c_inc );

    fprintf( f_pt, "    CFLAGS       = %s\n", cflags );

    fprintf( f_pt, "    CLINKFLAGS   = %s\n", clinkflags );

    fprintf( f_pt, "    RAND         = %s\n", rand );
#ifdef SMP
    evalue = getenv("MP_SET_NUMTHREADS");
    fprintf( f_pt, "   MULTICPUS = %s\n", evalue );
#endif

    fclose(f_pt);

/*    printf( "\n\n" );
    printf( " Please send the results of this run to:\n\n" );
    printf( " NPB Development Team\n" );
    printf( " Internet: npb@nas.nasa.gov\n \n" );
    printf( " If email is not available, send this to:\n\n" );
    printf( " MS T27A-1\n" );
    printf( " NASA Ames Research Center\n" );
    printf( " Moffett Field, CA  94035-1000\n\n" );
    printf( " Fax: 415-604-3957\n\n" );*/
}

