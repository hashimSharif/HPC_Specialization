#!/usr/bin/perl
# This collects up the -suite and -test argument needed to rerun only failures
# Contributed by Gary Funck and modified by Paul Hargrove.
use strict;
use warnings;
my $checkfail_cmd;
if (defined ($ARGV[0]) && $ARGV[0] =~ m/^-cmd=(.*)/) {
  $checkfail_cmd = $1;
  shift;
} elsif (-x './checkfail') {
  $checkfail_cmd = './checkfail';
} elsif (-x '../checkfail') {
  $checkfail_cmd = '../checkfail';
} else {
  die "can't find checkfail command.\n";
}
my $cmd = "$checkfail_cmd -n";
$cmd .= ' ' . join(' ', @ARGV) if @ARGV;
open CMD, "$cmd |" or die "can't execute: $cmd\n";
my %tests = ();
while (<CMD>) {
  chomp;
  die "$_\n" if m'^ERROR';
  next unless my ($suite, $test) = m{^\[(.*?)/(.*?)\]};
  $test =~ s/_st\d+$//;
  $test =~ s/_\d+$//;
  $tests{$suite}->{$test} = 1;
}
close CMD;
if ($?) { die "$cmd returned with non-zero status\n"; }
if (%tests) {
  print "-suite=" . join (',', sort keys %tests);
  print " -test=" . join (',', sort map {keys %{$tests{$_}}}
                                  keys %tests);
  print "\n";
}
exit 0;
1;
