#!/usr/bin/perl

use Getopt::Std;
use IO::File;
use File::Basename;

# Generate a harness.conf file for the MUPC tests

@c_files = <*.c>;
@types = qw(int long float double);

@static_only = qw(test_app_matmult);
@dynamic_only = ();

# default is to do both static and dynamic threads
$do_static = 1;
$do_dynamic = 1;
getopts('t:SDf:d');
$debug = $opt_d;
@types = ("$opt_t") if defined($opt_t);
if (defined($opt_f)) {
    print "opt_f = [$opt_f]\n" if $debug;
    @c_files = glob($opt_f);
}
if (defined($opt_S)) {
    # turn off static threads
    print "opt_S = [$opt_S]\n" if $debug;
    $do_static = 0;
}
if (defined($opt_D)) {
    # turn off dynamic threads
    $do_dynamic = 0;
}

my $sepline = "# " . "-"x60 . "\n";

foreach $typ (@types) {

    print $sepline;
    printf("BEGIN_DEFAULT_CONFIG\n");
    printf("Flags:           -DDATA=%s\n",$typ);
    printf("CompileResult:   pass\n");
    printf("PassExpr:        ^Success:\n");
    printf("FailExpr:        ^Error:\n");
    printf("ExitCode:        ignore\n");
    printf("BuildCmd:        upcc\n");
    printf("AppArgs:         \n");
    printf("TimeLimit:       \$DEFAULT\$\n");
    if ($do_dynamic) {
	printf("DynamicThreads:  \$DEFAULT\$\n");
    }
    if ($do_static) {
	printf("StaticThreads:   \$DEFAULT\$\n");
    }
    printf("END_DEFAULT_CONFIG\n\n");

    foreach $cfile (@c_files) {
	my $root = $cfile;
	$root =~ s/.c$//;
	my $testname = sprintf("%s-%s",$root,$typ);
	printf("TestName: %s\n",$testname);
	printf("Files: %s\n",$cfile);
	if ($do_dynamic && (grep (/^$root$/,@static_only))) {
	    # cancel the dynamic threads case
	    printf("DynamicThreads: 0\n");
	}
	if ($do_static && (grep (/^$cfile$/,@dynamic_only))) {
	    # cancel the static threads case
	    printf("StaticThreads: %d\n");
	}
	printf("\n");
    }
    print "\n";
}

	
