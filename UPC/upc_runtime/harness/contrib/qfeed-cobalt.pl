#!/usr/bin/perl
#
# This script "feeds" the cobalt queues on ANL's BG/P
# The purpose is to function within the per-user submit limit
#
# The arguments are
#     qfeed-cobalt Qname Qlimit [file...]
#  Qname is the name of the queue we are "feeding"
#  Qlimit is max number of entries we will allow
#  Files (or stdin by default) should contain one qsub command per line
#
# Example 1. The following will find all the qscipt_* files in the
# current directory, extract the qsub command from the comment on line 2,
# and then submit them.  I use this with the harness -norun option.
#   grep \"qsub qscript* | cut -d\" -f2 | qfeed-cobalt prod-devel 20
#
# Example 2. The following will find all the runlist_* files in the
# current directory, locate the corresponding qscript_* files, extract the
# qsub command from the comment on line 2, and then submit them.  It can
# be used to (re)queue any runlists that did not complete (eg because they
# ran out time).  However, be sure there are no jobs queued for the
# current directory or some may end up queued twice.
#
#   ls -1 runlist_*_{?,??,???} 2>/dev/null | \
#       xargs -i grep -l '\<{}\>' qscript_* | \
#       xargs grep \"qsub | cut -d\" -f2 | \
#       qfeed-cobalt prod-devel 20
#
# This script does NOT check for failure of the qsub command.  So, if you
# have two copies of this script running they may "drop" jobs unless you
# under-report the second argument to allow for multiple simultaneous
# submits.

my $queue = shift @ARGV || die 'Missing Qname argument';
my $limit = shift @ARGV || die 'Missing Qlimit argument';
my $user = $ENV{'USER'};

while (my $line = <>) {
 my $space;
 do {
   $space = $limit;
   open QSTAT, "qstat -u $user $queue|" || die;
   while (<QSTAT>) {
     $space-- if (m/$user/o); # ignores header and errors/warnings
   }
   close QSTAT;
   sleep 10 unless ($space > 0);
 } while ($space < 1);

 my $now = localtime;
 print "---- $now\n$line";
 system $line;
}
my $now = localtime;
print "---- $now\nDONE\n";
