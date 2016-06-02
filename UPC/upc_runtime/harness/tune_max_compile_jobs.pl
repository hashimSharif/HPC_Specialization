#!/usr/bin/perl
#
# usage: tune_max_compile_jobs [--limit=<limit> | -l <limit>]
#                              [--start-load-ave=<load> | -s <load>]
#                              [harness switches ...]
# 
# Iterate over values of the -jobs=N parameter for
# N in the range (1..<limit>) (defauit: 10).
# 
# The --start-load-ave <load> (default: 0.20) value is the maximum
# load average that must be present before each test run will start.
# 
# All remaining switches will be passed to the harness script.
# A typical use of the switches  is to pass the
# -suite=<suite> argument to the harness script,
# which will restrict the test run to use the specified test suite.
#
# Each output line has the form (N, S, L).  N is
# the value of -jobs=N, S is the number of seconds elapsed
# and L is an estimate of the maximum load average seen
# during the run.
#
# Note: running this test on the full harness test suite
# can take a long time and can place a significant load on the
# test system.  On a 4-core Opteron system, it takes 6.5 hours
# to run a test sequence that iterates the -jobs=N parameter
# over the range 1..10 .
#
# Here are the results from a test run with the full harness,
# on a 4c/2p Opteron system.
#
#       N SECS LOAD
#       1 4181 3.24
#       2 2278 4.32
#       3 1701 4.99
#       4 1507 8.14
#       5 1530 17.62
#       6 1437 12.52
#       7 1465 11.29
#       8 1474 13.08
#       10 1444 15.36
#
# Copyright (c) 2009, The Regents of the University of California,
# through Lawrence Berkeley National Laboratory.
# Terms of use are as specified in LICENSE.TXT.
#
# $Source: bitbucket.org:berkeleylab/upc-runtime.git/harness/tune_max_compile_jobs.pl $
#
use strict;
eval 'use warnings';  # Groan - not in perl 5.005
use IO::File;
use Getopt::Long;
use POSIX ':sys_wait_h';

my $mydir = $0;
$mydir =~ s@/[^/]*$@@;
push @INC, $mydir;  # set up search path for our perl includes
require "harness_util.pl";

my $have_cpu_load = defined((&cpu_load)[0]);
print STDERR "WARNING: System CPU load average is unavailable.\n"
    unless ($have_cpu_load);

my $limit = 10;		# default --limit=10
my $start_load = 0.20;	# default --start-load-ave=0.20

sub print_usage_and_quit
{
    print STDERR <<EOF;
usage: tune_max_compile_jobs [--limit=<limit> | -l <limit>]
                             [--start-load-ave=<load> | -s <load>]
                             [harness switches ...]

Iterate over values of the -jobs=N parameter for
N in the range (1..<limit>) (defauit: 10).

The --start-load-ave <load> (default: 0.20) value is the maximum
load average that must be present before each test run will start.

All remaining switches will be passed to the harness script.  A typical
use of these switches is to pass the -suite=<suite> argument to the
harness script, which restricts the test run to use the specified
test suite.

EOF
    exit 2;
}

# Parse this command's switches, leave the rest alone.
Getopt::Long::Configure('pass_through');
GetOptions ('help|h' => \&print_usage_and_quit,
            'limit|l=i' => \$limit,
	    'start-load-ave|s=f' => \$start_load);
if ($limit < 1 || $limit > 1000) {
  die "limit ($limit) must be in the range 1..1000\n";
}
if ($start_load < 0.0 || $start_load > 1000.0) {
  die "starting load average level ($start_load)"
      . " must be in the range 0.0..1000.0\n";
}

# Capture the remaining args
my @harness_cmd = ("$mydir/harness", '-clean', '-compileonly', @ARGV);

# Use '-dryrun' to check the remaining switches to make sure
my $child = open(CHILD,'-|');
if ($child == 0) {
  open STDERR, '>&STDOUT' or die 'failed to merge stderr with stdout';
  exec (@harness_cmd, "-dryrun");
}
my $child_out = do { local $/; <CHILD> }; # slurp!
close CHILD; # Does waitpid() and puts status in $?
if ($?) {
  my $line = ('-' x 80);
  print "$line\n$child_out$line\n\n";
  print "Command (below) failed with the output shown above.\n";
  print "Please verify the arguments.\n";
  print "\t@harness_cmd\n";
  exit 1;
}

my ($start, $end, $secs, $load, $rc);
open OUTPUT, '>&STDOUT' or die 'Could not dup STDOUT';
open STDOUT, '>/dev/null' or die;
select OUTPUT; $| = 1;
print "   N   SECS   LOAD\n";
$, = ' ';
for my $max_jobs (1..$limit) {
    # Wait until the system has recovered from
    # a previous run, and the current load average
    # is less than $start_load.
    while ($have_cpu_load && (&load_ave() >= $start_load)) {
      sleep 6;
    }
    # Begin this compilation run.
    $start = time;
    my @cmd = (@harness_cmd, "-jobs=$max_jobs");
    my $child = fork;
    if ($child == 0) {
      exec @cmd;
      die "failed to exec: @cmd\n";
    } elsif (!$child) {
      die "fork() failed: $!";
    }
    # Poll load while waiting for child to terminate
    # We can't easily use SIGCHLD since load_ave() could also
    # spawn children (e.g. "/usr/bin/uptime|".)
    $load = 0;
    while (!($rc = waitpid($child, WNOHANG))) {
      my $tmp = load_ave();
      $load = $tmp if ($tmp > $load);
      sleep 5;  # NOTE: limits resolution of reported timings
    }
    $end = time;
    die "waitpid failed: $!" unless ($rc == $child);
    die "job failed: @cmd\n" unless (!$?);
    # Compilation finished, collect and report statistics.
    $secs = $end - $start;
    printf "%4d%7d%7.2f\n", $max_jobs, $secs, $load;
}
