#!/usr/bin/env perl
# $Source: bitbucket.org:berkeleylab/upc-runtime.git/harness/harness_util.pl $

require 5.005;
use strict;
use POSIX ":sys_wait_h";

my $debug = 0;

# is_cygwin() returns true iff this is a cygwin platform
# is_unicos() returns true iff this is a unicos platform
# is_cobalt() returns true iff this is a BG/P cobalt environment
# is_bgl_cqsub() returns true iff this is a BG/L (cobalt) environment
{
 my $is_cygwin_result = undef;
 sub is_cygwin() {
  if (!defined $is_cygwin_result) {
    $is_cygwin_result = ($^O =~ /cygwin/i) ? 1 : 0;
  }
  return $is_cygwin_result;
 }
 my $is_unicos_result = undef;
 sub is_unicos() {
  if (!defined $is_unicos_result) {
    my $sysname = `uname`;
    chomp($sysname);
    $is_unicos_result = ($sysname =~ /UNICOS/i) ? 1 : 0;
  }
  return $is_unicos_result;
 }
 sub is_cobalt() {
  return exists($ENV{'COBALT_JOBID'});
 }
 my $is_bgl_cqsub_result = undef;
 sub is_bgl_cqsub() {
  if (!defined $is_bgl_cqsub_result) {
    $is_bgl_cqsub_result = (-d '/bgl' && -e '/usr/bin/cqsub');
  }
  return $is_bgl_cqsub_result;
 }
}

# get_tmpfilename() returns a unique name of a tmpfile 
{
  my $TMPDIR = (-d $ENV{TMPDIR} ? "$ENV{TMPDIR}" : '/tmp');
  my $USER = ( $ENV{USER} || "x" );
  my $tmpfile_id = 0;
  sub get_tmpfilename() {
    $tmpfile_id++;
    my $filename = "$TMPDIR/harness-$USER-$$-$tmpfile_id";
    unlink($filename) if (-e $filename);
    return $filename;
  }
}

# exec a command string, redirect stdout and stderr, and try to preserve signal forwarding
sub execcmd($$$) {
  my $cmd = shift;
  my $out = shift;
  my $err = shift;
  if (is_cygwin()) {
    # try backticks so shell can handle redirection
    $_ = `$cmd >$out 2>$err`;
    exit ($? >> 8); 
  } else {
    # Go to some trouble to avoid spawning a subshell which might
    # mess with signalling.
    my @cmdlist;
    # be sure to honor quoting of spaces in command
    # this doesn't implement the full shell quoting rules, but it's probably close enough 
    my $quot = undef;
    my $arg = undef;
    foreach my $char (split //, $cmd) {
      if ($char =~ /['"]/ && !$quot) { # open quote
        $quot = $char;
        $arg .= ""; # ensure non-empty
      } elsif ($char eq $quot) { # close quote
        $quot = undef;
      } elsif ($char =~ /[ \n\t]/ && !$quot) {
        push @cmdlist, $arg if (defined $arg);
        $arg = undef;
      } else {
        $arg .= $char;
      }
    }
    push @cmdlist, $arg if (defined $arg);
    #print "EXECARGS: " .(join "|", @cmdlist)."\n";
    open STDOUT, ">$out"
                or die "unable to redirect stdout to $out: $!\n";
    open STDERR, ">$err"
                or die "unable to redirect stderr to $err: $!\n";
    exec(@cmdlist);
    die "exec failed: $!";
  }
}


my $got_timeout = 0;
my $child_pid = undef;

sub runjob_withtimeout($$) {
    my $childfn = shift;
    my $timeout = shift;
    # set the signal handler to catch an alarm
    $SIG{'ALRM'} = 'catch_alarm';

    $got_timeout = 0;
    $child_pid = undef;
    $child_pid = fork();

    if (defined($child_pid) && ($child_pid == 0)) {
        # we are the child
        eval { setpgrp(0,0); }; # try to create a new process group to assist signalling
	&$childfn();
        exit $?;
    } elsif (!defined($child_pid) || ($child_pid < 0)) {
	# fork failed... bail
	die "fork failed: $!";
    }

    #if we got here, we are the parent
    # timeout must be a non-negative integer - round it up to conform
    $timeout++ if ($timeout != int($timeout));
    $timeout = int($timeout);
    alarm $timeout if $timeout;

    # wait for the job to complete
    waitpid($child_pid,0);

    # recover the exit code of the child process
    # we swap 2 lowest bytes to make status==exitcode in the natural case
    my $status = $?;
    $status = ((($status & 0xff00) >> 8) || (($status & 0x007f) << 8));
    if (is_unicos()) { $status &= 0xff; } # bug 1835

    # disable the alarm if it has not gone off
    alarm 0;

    return ($status,$got_timeout);
}

# ======================================================================
# The child killer!
# Terminate a child process
#
# At least one mpirun (LAM) is known to leave orphans if it gets
# SIGTERM.  So, we try sending SIGINT first.
# ======================================================================
sub kill_child {
    my @signals = qw/INT TERM/;
    if (is_cygwin()) {
	# I don't know why, but it prevents runaways -PHH
	unshift @signals, 'USR1';
    }
    if (is_cobalt()) {
        foreach my $dir (qw(/bgsys/drivers/ppcfloor/bin /software/common/apps/misc-scripts)) {
            $ENV{'PATH'} .= ":$dir" unless (":$ENV{'PATH'}:" =~ m,:${dir}:,);
        }
    }
    my $signals = @signals;
    my $limit = $signals*2;

    sub alive {
        my $pid = waitpid($child_pid, &WNOHANG);
	if ($pid == 0) {
	    # the child is still running
	    return 1;
	} elsif (($pid == -1) || WIFEXITED($?) || WIFSIGNALED($?)) {
	    # the child has exited
	    return 0;
	} else {
	    # the child is stopped?
	    kill 'CONT', $child_pid;
	    return 0;
	}
    }

    my $count = 0;
    my $grpid = undef;
    eval { $grpid = getpgrp($child_pid); # lookup child process group
           $grpid = undef if ($grpid == getpgrp(0)); # be careful not to kill ourselves
         };

    while (&alive && ($count < $limit)) {
        my $sig = $signals[$count % $signals];
        if (is_cobalt()) {
          # Try to signal the compute job w/ mpikill
          my $bgjobid = undef;
          open LISTBLOCKS, "bg-listblocks --id $ENV{'COBALT_PARTNAME'}|";
          while (<LISTBLOCKS>) {
            if (/..:.. ([0-9]+)/) { 
              $bgjobid = $1;
              last;
            }
          }
          close LISTBLOCKS;
          if ($bgjobid) {
            print "CALLING: mpikill -s $sig --job $bgjobid\n" if ($debug);
            system("mpikill -s $sig --job $bgjobid");
            sleep 30;
            ++$count;
            next;
          }
        }
	if ($grpid) { # give preference to a process group kill, 
                      # which is less likely to leave zombies due to incorrect signal propagation
	  print "SENDING: kill $sig, -$grpid\n" if ($debug);
	  kill $sig, -$grpid || 
	    print "WARNING: failed to kill $sig -$grpid: $!\n";
	  for (my $i = 0; $i < 15; ++$i) {
	    sleep 1;
	    last if (!&alive);
	  }
        }
	print "SENDING: kill $sig, $child_pid\n" if ($debug);
	kill $sig, $child_pid || 
	  print "WARNING: failed to kill $sig $child_pid: $!\n";
	for (my $i = 0; $i < 15; ++$i) {
	  sleep 1;
	  last if (!&alive);
	}
	++$count;
    }

    # Give up on being polite
    if (&alive) {
      print "SENDING: kill KILL, $child_pid\n" if ($debug);
      kill 'KILL', $child_pid || 
	  print "WARNING: failed to kill KILL $child_pid: $!\n";
    }

    if (0 && is_cobalt()) {  # DISABLED: has not been necessary for a while.
      # Stall until the partition reaches a state valid for reuse
      my $done = 0;
      my $partition = $ENV{'COBALT_PARTNAME'};
      $count = 0;
      while (!$done && ($count < $limit)) {
        sleep 30; # yes, we really want to sleep first
        open LISTBLOCKS, "bg-listblocks --id $partition |";
        while (<LISTBLOCKS>) {
          if (/^$partition .* [ABCFI] /) {
            $done = 1;
            last;
          }
        }
        close LISTBLOCKS;
        ++$count;
      }
      if ($count == $limit) {
        print "WARNING: partition did not return to valid state\n";
      }
    }
}


# ======================================================================
# The signal handler for an alarm.
# Record the fact that the alarm went off and kill the child process.
# ======================================================================
sub catch_alarm {
    return if ($child_pid <= 0);
    $got_timeout = 1;
    kill_child();
}


# ======================================================================
# load_ave()  Uses Sys::CpuLoad::load, if available.
# Otherwise, use our own implementation.
# ======================================================================

sub cpu_load {
    my ($la1, $la5, $la15) = (undef, undef, undef);
    my ($la_fh, $line);
    if ($la_fh = new IO::File('/proc/loadavg', 'r')) {
         $line = <$la_fh>;
    } else {
	 # Disabled setting LC_NUMERIC since it can cause MANY warnings.
	 # Besides, in the perlstart logic we already set LC_ALL=C. -PHH
	 #local %ENV = %ENV;
	 # ensure that decimal separator is a dot
	 #$ENV{'LC_NUMERIC'} = 'POSIX';
	 $la_fh = new IO::File('/usr/bin/uptime|')
		  || new IO::File('/usr/ucb/uptime|');
         if ($la_fh) {
             $line = <$la_fh>;
	     $line =~ s/^.*load averages?:\s*//;
	 }
    }
    if ($line && $line =~ /^(\d+\.\d+)((?:\s*,)?\s+(\d+\.\d+)){2}/) {
	($la1, $la5, $la15) = (+$1, +$2, +$3);
    }
    return ($la1, $la5, $la15);
}

BEGIN {
    eval 'use Sys::CpuLoad;
          *cpu_load = \*Sys::CpuLoad::load;';
}

sub load_ave { return (&cpu_load)[0]; }

# ======================================================================

1;
