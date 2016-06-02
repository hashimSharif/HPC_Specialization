#!/usr/bin/perl

use Getopt::Long;
use IO::File;
use File::Basename;


@prefix = qw(I II III IV V VI VII VIII IX X XI XII XIII);

@compile_fail = qw(I_case_i I_case1_ii I_case1_iii I_case1_iv
		   II_case1_ii II_case2_ii II_case3_ii
		   V_case3_i V_case3_ii);

@no_pass_expr = qw(X_case1_i);

@special = (@compile_fail, @no_pass_expr);

@upc_files = ();

my $sepline = "# " . "-"x60 . "\n";

&gen_sourcefiles();

# print the generic testcase values
print "BEGIN_DEFAULT_CONFIG\n";
print "Flags:\n";
print "Files:          \$TESTNAME\$.upc\n";
print "DynamicThreads: \$DEFAULT\$\n";
print "StaticThreads:  \$DEFAULT\$\n";
print "CompileResult:  pass\n";
print "PassExpr:       ^Success:\n";
print "FailExpr:       ^Failure:\n";
print "ExitCode:       0\n";
print "BuildCmd:       upcc\n";
print "AppArgs:        \n";
print "TimeLimit:      \$DEFAULT\$\n";
print "END_DEFAULT_CONFIG\n";
print "\n\n";

print $sepline;
print "WildCard:  \<\*\>.upc\n";
print "\n";

foreach $cfile (@upc_files) {
    my $root = $cfile;
    $root =~ s/.upc$//;

    next if (! grep(/^$root$/,@special));
    print $sepline;
    printf("TestName:       %s\n",$root);
    if (grep (/^$root$/,@compile_fail)) {
	printf("CompileResult:  fail\n");
    }
    if (grep (/^$root$/,@no_pass_expr)) {
	printf("PassExpr:       0\n");
    }
    printf("\n");
}
	
sub gen_sourcefiles {
    my $p, $s;
    my $cnt;
    
    foreach $p (@prefix) {
	foreach $s ("",1,2,3,4,5) {
	    my $root = sprintf("%s_case%s_",$p,$s);
	    my @a = <${root}*.upc>;
#	    printf "root = [$root]: found %d files\n",scalar(@a);
	    push(@upc_files,@a);
	}
    }
}
