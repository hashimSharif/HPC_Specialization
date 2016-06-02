#!/usr/bin/perl
# This script moves jobs from the 'normal' queue to the
# 'development' queue wile honoring the queue limit (3 by default).
# It currenty runs just once exiting with non-zero if the queue
# is empty.  It probably SHOULD keep running until empty.

my $limit = $ARGV[0] || 3;
my ($id, $devel);
my @jobs;

open CMD, 'qstat -r |';
while (<CMD>) {
   if (/^\s*([0-9]+)/) {
     $id = $1;
   } elsif  (/h_rt=?([0-9]+)/) {
     next if ($1 > 7200);  # too long
   } elsif  (/equested PE: .*way\s+([0-9]+)/) {
     next if ($1 > 256);  # too wide
   } elsif  (/equested queues:\s+([a-z]+)/) {
     my $queue = $1;
     if ($queue eq 'development') {
       ++$devel
     } elsif ($queue eq 'normal') {
       push @jobs, $id;
     }
     last if (@jobs >= ($limit - $devel));
   }
}
exit 1 unless (@jobs || $devel);

my $jobs = ($limit - $devel);
if ($jobs > 0) {
  system 'date';
  my $cmd = "qalter -q development " . join(' ', @jobs[0..($jobs-1)]);
  system $cmd;
}
