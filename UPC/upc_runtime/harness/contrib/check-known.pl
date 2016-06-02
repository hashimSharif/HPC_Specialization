#!/usr/bin/perl

# Takes one or more directories as args: searches them for the .rpt files
#
# XXX:
# Currently lump the results from all platforms together.
# This means that we will not detect if the constraints on a given
# KnownFailure are too broad (such as being O/S or compiler specific).
#
use File::Find;
use strict 'vars';
use strict 'refs';
use warnings;

# Limit to number of NEW failure beforea .rpt file is discarded.
my $new_limit = 99;

# Boolean to decide if "gccupc" in the pathname discards a .rpt file.
my $non_gccupc = 1;

# Do we warn about files w/ too many NEW failures?
my $verbose = 1;

###
### END OF SETTINGS
###

my @topdirs = @ARGV;
@topdirs = qw/./ unless @topdirs;

# Find all knownfailure.rpt files
my @known_rpt;
sub find_known() {
  return unless ($_ eq 'knownfailures.rpt');
  return if ($non_gccupc && $File::Find::dir =~ m/gccupc/);
  push @known_rpt, $File::Find::name;
}
find(\&find_known, @topdirs);

# Find compile.rpt files w/o "too many" NEW failures
my @compile_rpt;
sub find_compile() {
  return unless ($_ eq 'compile.rpt');
  return if ($non_gccupc && $File::Find::dir =~ m/gccupc/);
  push @compile_rpt, $File::Find::name;
}
find(\&find_compile, @topdirs);

# Find run.rpt files w/o "too many" NEW failures
my @run_rpt;
sub find_run() {
  return unless ($_ eq 'run.rpt');
  return if ($non_gccupc && $File::Find::dir =~ m/gccupc/);
  push @run_rpt, $File::Find::name;
}
find(\&find_run, @topdirs);

sub parse_known($$) {
  my $type = shift;
  my $bool = shift;
  my %result;

  foreach my $file (@known_rpt) {
    open FILE, "<$file" || die;
    while ($_ = <FILE>) {
      next unless (m/: ${bool} ; (all|${type}-)/);
      s/: .*; */: /;
      $result{$_} = 1;
    }
    close FILE;
  }
  return %result;
}

my %rpt = ( 'compile' => \@compile_rpt,
            'run'     => \@run_rpt );

foreach my $type (qw/compile run/) {
  # List of failures we can expect to see
  my %known = &parse_known($type, '1');
  open KNOWN, ">Known-${type}" || die;
  print KNOWN (keys %known);
  close KNOWN;
  printf "\t%d\tKnown-%s\n", scalar(keys %known), $type;

  # List of failures we actually saw:
  my %seen;
  my $bad_rpt = 0;
  foreach my $file (@{$rpt{$type}}) {
    my $test = 'UNKNOWN';
    my $count = 0;
    my %tmp = ();
    open FILE, "<$file" || die;
    while ($_ = <FILE>) {
      if (m/^\[(.*)\]/) {
        $test = $1;
        ++$count if (m[/NEW\)] && !m[\(TIME/NEW\)]);
      } elsif (/^ ?Known failure: (.*)$/) {
        my $desc = $1;
        $test =~ s/_st[0-9]+$//;
        $tmp{"$test: $desc\n"} = 1;
      }
    }
    close FILE;
    if ($count > $new_limit) { ++$bad_rpt; print STDERR "BAD FILE: $file\n" if $verbose; }
    else { @seen{keys %tmp} = 1; }
  }
  open SEEN, ">Seen-${type}" || die;
  print SEEN (keys %seen);
  close SEEN;
  printf "\t%d\tSeen-%s\n", scalar(keys %seen), $type;

  # List of failures we expected to see but did not:
  my %unseen = %known;
  foreach my $key (keys %seen) { delete $unseen{$key}; }
  open UNSEEN, ">Unseen-${type}" || die;
  print UNSEEN (keys %unseen);
  close UNSEEN;
  printf "\t%d\tUnseen-%s\n", scalar(keys %unseen), $type;

  # List of failures not tested:
  my %untested = &parse_known($type, '0');
  foreach my $key (keys %known) { delete $untested{$key}; }
  open UNTESTED, ">Untested-${type}" || die;
  print UNTESTED (keys %untested);
  close UNTESTED;
  printf "\t%d\tUntested-%s\n", scalar(keys %untested), $type;

  print STDERR "WARNING: ${bad_rpt} ${type}.rpt files ignored\n"
    if ($verbose && $bad_rpt);
  print "\n";
}
