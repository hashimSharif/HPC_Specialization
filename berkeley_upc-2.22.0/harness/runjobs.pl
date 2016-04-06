#!/usr/bin/env perl
# $Source: bitbucket.org:berkeleylab/upc-runtime.git/harness/runjobs.pl $

require 5.005;
use strict;
use IO::File;
use IO::Seekable;
use File::Basename;
use POSIX ":sys_wait_h";
use Text::ParseWords;
use Config;

my $warning_blacklist = '^'.
  '(.*?rmsapi: Error:.*?)|'.
  '(.*?libmsql: Socket read.*?)|'.
  '(.*?Retrying allocation .... press control-C to terminate.*?)|'.
  '(.*?Job passed jobfilter.*?)|'.
  '(.*?GASNet reporting enabled.*?)|'.
  '(.*?AMUDP WARNING: Receive buffer full - unable to drain network.*?)|'.
  '(.*?error in locking authority file.*?)|'.
  '(.*?upcc: banner: *?)|'.
  '(.*?ENV parameter:.*?)|'.
  '(.*?FREEZE_ON_ERROR.*?)|'.
  '(.*?using fake authentication data for X11 forwarding.*?)|'.
  '(.*?most recent RAS event text: DDR Correctable Error Summary.*?)|'.
  '()$';

my $mydir = $0;
$mydir =~ s@/[^/]*$@@;
push @INC, $mydir;  # set up search path for our perl includes
require "harness_util.pl";

# Don't let our output and children's intermix in strange ways
use IO::Handle;
STDERR->autoflush(1);
STDOUT->autoflush(1);

# exit codes
my $finished_code = 0;
my $again_code = 1;
my $failure_code = 2;

my $debug = 0;
my $testonly = 0;
#my $arg_count = scalar(@ARGV);

my $got_limit = 0;
my $got_outofmem = 0;
my $got_crash = 0;
my $got_timeout = 0;

my $ran_any = 0;

# gather arguments
my $logdir = shift;
my $run_file = shift;
my $rpt_file = shift;
my $runarg = shift;
my $timelimit = shift;
my $slack = shift || 15;

# the runlist field names and related values
my @runlist_fields = qw(rundir runcmd app wantfail t_limit f_limit e_code pass_expr fail_expr nthread
		     pthreads keep_binary save_output app_args app_env known benchmark);
my $num_runlist_fields = scalar(@runlist_fields);
my $runlist_t_limit = 4; # index of "t_limit" element in runlist_fields
die 'ERROR w/ $runlist_t_limit value'
    unless ($runlist_fields[$runlist_t_limit] eq 't_limit');

my @sig_name = split(' ', $Config{sig_name}) or die "No signals?";
my @timeout_signals = qw/INT TERM/;
unshift @timeout_signals, 'USR1' if is_cygwin();

# sanity checks
if (! defined($logdir) || (! -e $logdir)) {
    print "no such logdir [$logdir]\n";
    exit $failure_code;
}
my $runlist_file = "$logdir/${run_file}";
if (! defined($runlist_file) || (! -e $runlist_file)) {
    print "no such run_file [$runlist_file]\n";
    exit $failure_code;
}
if (! defined($runarg)) {
    print "runarg not defined [$runarg]\n";
    exit $failure_code;
}
if (! defined($timelimit) || ($timelimit !~ /^\d+$/)) {
    print "bad timelimit [$timelimit]\n";
    exit $failure_code;
}


my $header1 = '=' x 78 . "\n";
#my $header2 = sprintf("%-16s %-35s %5s %6s\n",
#		   "TimeStamp","CodeName","Time",
#		   "Result");

my $report_file = "$logdir/$rpt_file";

if (!(-e $report_file)) {
    my $rpt = new IO::File(">> $report_file");
    die "Cant append to $report_file" if !defined($rpt);
    print $rpt $header1;
    #print $rpt $header2;
    undef $rpt;
}

if (-e $runlist_file) {
    my $save = ${runlist_file} . "_" . &gen_timestamp();
    print "Copying $runlist_file to $save\n";
    `cp ${runlist_file} $save`;
}

my $start_time = time();
while (1) {
    # compute time left in seconds
    my $now = time();
    my $elapsed = $now - $start_time;
    my $time_left = $timelimit - $elapsed;

    print "\n";
    print "Time Left = $time_left\n" unless ($timelimit == 0);

    # choose what, if any job to run
    # Note that the code will exit in this routine if there
    # are no jobs to run or if we don't have enough time to
    # run another.
    my $job = &select_job($time_left,$slack);

    # Now run the selected job under the watchfull eye of
    # the watchdog.  This will kill the job if it runs for
    # too long.  It will also report on the success/failure 
    # of the run to the run_rpt file.
    &run_job($job);
}

# we should never get here.
exit 0;
    
# =================================================================
# Choose a job from the file of jobs to run
#
# If no jobs are left to run, exit with the $finished_code.
# If not enough time left to run any of the jobs in the list
# return the $again_code.
# =================================================================
sub select_job {
    my $time_left = shift;
    my $slack = shift;

    my $file = ${runlist_file};

    if (! -e $file) {
	printf("Finished: runlist file [$file] does not exist.\n");
	exit $finished_code;
    }
    my $fh = new IO::File("< $file");
    if (! defined($fh)) {
	printf("Unable top open file [$file] for reading.\n");
	exit $failure_code;
    }

    sub dequote { $_[0] =~ s/^(["'])(.*)\1$/\2/; }

    my $job = undef;
    my @arr = ();
    my $cnt = 0;
    while (<$fh>) {
	chomp;
	s/^\s+//;
	s/\s+$//;
	next if /^\#/;  # skip comment lines
	my @runargs = &parse_line(' ',1,$_);
	my $numarg = scalar(@runargs);
	if ($numarg != $num_runlist_fields) {
	    printf("Invalid number of runlist fields [$_]\n");
	    exit $failure_code;
	}
	dequote(my $t_limit = $runargs[$runlist_t_limit]);
	if (!defined($job) && ($t_limit <= ($time_left - $slack) || ($timelimit == 0))) {
	    # run this job
	    for (my $i = 0; $i < $numarg; $i++) {
		dequote ($job->{$runlist_fields[$i]} = $runargs[$i]);
	    }
	} else {
	    # queue it up to re-write the runlist file
	    push(@arr,$_);
	}
	$cnt++;
    }

    # close the runlist file
    undef $fh;

    if (! defined($job)) {
	if ($cnt == 0) {
	    # nothing left to run, we have finally finished!
	    unlink($file);
	    printf ("Finished: No apps left to run.\n");
            my $rpt = new IO::File(">> $report_file");
            die "Cant append to $report_file" if !defined($rpt);
            printf $rpt "Run of $runlist_file COMPLETE\n";
            undef $rpt;

    	    my $run_done = new IO::File("> $logdir/${run_file}-complete");
    	    if (defined($run_done)) {
           	my $timestamp = &gen_timestamp();
           	printf $run_done "$timestamp\n";
           	undef $run_done;
    	    }
	    exit $finished_code;
	}
	# jobs left to run, but none small enough to fit into our
	# time limit.  Leave the runlist file as it is and tell
	# the job script to re-submit itself, UNLESS we didn't
	# actually run anything (which would indicate one or more
	# jobs are too big to run w/ slack).
	unless ($ran_any) {
	    print "NO JOBS RAN - stopping to avoid inifinite loop.\n";
            my $rpt = new IO::File(">> $report_file");
            die "Cant append to $report_file" if !defined($rpt);
            printf $rpt "Run of $runlist_file FAILED - $cnt unrunnable jobs remain.\n";
            undef $rpt;
            exit $finished_code;
        }
        print $header1;
	print "Time Limit reached, $cnt jobs remain.\n";
	exit $again_code;
    }

    # if we got here, we found a job to run.  Now re-create the
    # runlist file without the job we selected.
    unlink($file);

    # Now re-create runlist file and write remaining jobs to it
    $fh = new IO::File("> $file");
    if (! defined($fh)) {
	printf("Unable to re-create file [$file]\n");
	exit $failure_code;
    }
    my $line;
    foreach $line (@arr) {
	printf $fh ("%s\n",$line);
    }
    undef $fh;

    #printf("Selected job to run [%s]\n",$job->{app});

    $ran_any = 1;
    return $job;
}

# =================================================================
# =================================================================
sub run_job {
    my $job = shift;

    my $rundir    = $job->{rundir};
    my $runcmd    = $job->{runcmd};
    my $wantfail  = $job->{wantfail};
    my $app       = $job->{app};
    my $app_args  = $job->{app_args};
    my $app_env   = $job->{app_env};
    my $timeout   = $job->{t_limit};
    my $f_limit   = $job->{f_limit};
    my $exitcode  = $job->{e_code};
    my $pthreads  = $job->{pthreads};
    my $nth       = $job->{nthread};
    my $keep_output = $job->{save_output};
    my $known     = ($job->{known} eq '') ? undef : $job->{known};
    my $benchmark = ($job->{benchmark} eq '') ? undef : $job->{benchmark};

    my $outbase = $app;
    # bug 1266: prevent output file collisions for tests with multiple dynamic threads 
    #           that the batch system may run concurrently
    $outbase = sprintf("${app}_dy%02d",$nth) if (!($outbase =~ m/_st\d+$/));
    my $app_out = "${outbase}.out";
    my $app_err = "${outbase}.err";

    if (!chdir($rundir)) {
	printf("Unable to cd to rundir [$rundir] for app [$app]\n");
	exit $failure_code;
    }
    my $cur_dir = `pwd`;
    chomp($cur_dir);
    my $suite = basename($cur_dir);

    unlink($app_out) if (-e $app_out);
    unlink($app_err) if (-e $app_err);

    if ( ! -e $app ) {
        my $timestamp = &gen_timestamp();
        my $outstr = "[$suite/$app]   0sec  $timestamp  FAILED (MISSING)\n";
        print $header1;
        print $outstr;

        my $rpt = new IO::File(">> $report_file");
        die "Cant append to $report_file" if !defined($rpt);
        print $rpt $outstr;
        undef $rpt;

        return;
    }

    # these are global vars
    $got_timeout = 0;
    $got_outofmem = 0;
    $got_limit = 0;
    $got_crash = 0;

    if (is_cobalt() || is_bgl_cqsub())  {
        # Dirty hack to deal with stdio redirection on BlueGene (part 1 of 2)
        # Set env vars to tell gasnetrun_mpi.pl where to redirect stdout and stderr
        # Must use distinct files or the output gets lost.
        my $out2 = "${rundir}/${app_out}2";
        my $err2 = "${rundir}/${app_err}2";
        unlink($out2) if (-e $out2);
        unlink($err2) if (-e $err2);
        $app_env .= " GASNETRUN_STDOUT='$out2' GASNETRUN_STDERR='$err2'";
    }

    my $cmd = "";
    if ($runcmd =~ /%[Bb]/) { # is Berkeley upcrun
        $cmd .= "env $app_env " if ($app_env);
	my $berkargs = "";
	$berkargs .= " -p $pthreads" if ($pthreads > 0);
        $runcmd =~ s/%[Bb]/$berkargs/g; 
    } else {
        $cmd .= "env $app_env UPC_QUIET=1";
	$cmd .= " UPC_PTHREADS_PER_PROC=$pthreads" if ($pthreads > 0);
    }
    #print "APPARGS: '$app_args'\n";
    $runcmd =~ s/%[Pp]/.\/$app/g; 
    $runcmd =~ s/%[Aa]/$app_args/g; 
    $runcmd =~ s/%[Nn]/$nth/g; 
    $cmd .= " $runcmd";

    my $app_start = time();
    my $status;
    ($status,$got_timeout) = runjob_withtimeout(sub {
	if ($testonly) {
	    printf("Would exec [$cmd]\n");
	    sleep $timeout/4;
	    exit $exitcode;
	} else {
	    execcmd($cmd, $app_out, $app_err);
	}
    }, $timeout, $debug);
    my $app_stop = time();

    if (is_cobalt() || is_bgl_cqsub())  {
        # Dirty hack to deal with stdio redirection on BlueGene (part 2 of 2)
        # Append the .out2 and .err2 files to the .out and .err
        foreach my $to ($app_out, $app_err) {
            my $from = $to . '2';
            if (-s $from) {
                my $in  = new IO::File("<  $from") || die;
                my $out = new IO::File(">> $to")   || die;
                while (<$in>) { print $out $_; }
            }
            unlink($from) if (-e $from);
        }
    }

    # check the output file for pass/fail strings.
    my $match_result = &pass_fail($app_out,$app_err,$job);

    my $exit_result = "ignore";
    my $exit_signal = $sig_name[$status >> 8];

    # Check the exit code
    if ( $status > 0xff ) {
	$got_crash = 1
	    unless ($got_timeout && grep($_ eq $exit_signal, @timeout_signals));
    } elsif ( $exitcode =~ /^\s*\d+\s*$/ ) {
	if ($status == $exitcode) {
	    $exit_result = "SUCCESS";
	} else {
	    $exit_result = sprintf("EXIT=%d",$status);
	}
    } elsif ( $exitcode =~ /^\s*non-?zero\s*$/i ) {
	if ($status != 0) {
	    $exit_result = "SUCCESS";
	} else {
	    $exit_result = sprintf("EXIT=0",$status);
	}
    }
	    
    my $timestamp = &gen_timestamp();
    my $result = "SUCCESS";
    my $failtype = 'run-unknown';
    # order is very important here, because some failures trigger more than one failure indication
    if ($exit_result =~ /EXIT/) {
      $result = "FAILED ($exit_result";
      $failtype = 'run-exit'; 
    }
    if ($match_result =~ /_EXPR/) {
      $result = "FAILED (MATCH" . (($match_result =~ /PASS_/) ? '!=PASS' : '==FAIL');
      $failtype = 'run-match'; 
    }
    if ($got_limit) {
      $result = "FAILED (LIMIT";
      $failtype = 'run-limit'; 
    }
    if ($got_timeout) {
      $result = "FAILED (TIME";
      $failtype = 'run-time'; 
    }
    if ($got_crash) {
      $result = "FAILED (CRASH";
      $result .= "=SIG$exit_signal" if ($status > 0xff);
      $failtype = 'run-crash'; 
    }
    if ($got_outofmem) {
      $result = "FAILED (MEM"; 
      $failtype = 'run-mem'; 
    }
    if ($wantfail) {
      # Invert SUCCESS, run-crash, run-exit and run-match
      if ($result eq 'SUCCESS') {
        $result = "FAILED (PASS"; 
        $failtype = 'run-pass'; 
      } elsif (grep /$failtype/, qw(run-crash run-exit run-match)) {
        $result =~ s/FAILED/SUCCESS/;
        $result .= ')';
        $failtype = 'run-unknown';
      }
    }
    if ($result =~ /FAILED/) {
      my $knowndesc = undef;
      foreach my $knownfail (split(/\|/,$known)) {
        print "checking failure '$failtype' against knownfailures: $knownfail\n" if ($debug);
        my ($modes,$descstr) = split(/;/,$knownfail);
        my @modelist = split(',',$modes);
        print "  checking modes: ".join(' ',@modelist)."\n" if ($debug);
        if (grep(/^$failtype$/,@modelist) || grep(/^all$/,@modelist) || grep(/^run-all$/,@modelist)) {
          $knowndesc = $descstr;
          last;
        }
      } 
      if (defined($knowndesc)) {
	$result .= "/KNOWN)\nKnown failure: $knowndesc";
      } else {
	$result .= "/NEW)";
      }
    }
    my $secs = $app_stop - $app_start;
    my $outstr = "[$suite/$app]   ${secs}sec  $timestamp  $result\n";
    #$outstr = sprintf(": %-35s %3dsec %6s\n",
    #		       "$suite/$app",$app_stop - $app_start,
    #		       $result);

    print $header1;
    #print $header2;
    print $outstr;
    print "commandline: [$cmd]\n";

    if ($benchmark && -e $app_out) {
 	my $out = new IO::File("< $app_out");
    	my $outtxt = do { local $/; <$out> };
	undef $out;
	if ($outtxt =~ /$benchmark/) {
	  my $result = $1;
	  my $units = $2;
	  $units = "MFLOPS" if (!$units);
	  if (defined($result)) {
	    $result =~ s/:/-/g;
	    $units =~ s/:/-/g;
	    print "BenchmarkResult:$result:$units:THREADS=$nth:PTHREADS_PER_PROC=$pthreads:\n";
	  }
	}
    }

    my $remove_executable;
    if ($result =~ /FAILED/) {
	print "PassExpr: $job->{pass_expr}\n";
	print "FailExpr: $job->{fail_expr}\n";
	$remove_executable = ($job->{keep_binary} == 0); # only remove if user specified always remove
	$keep_output = 1;
    } else { # test succeeded
	$remove_executable = ($job->{keep_binary} == 0 || $job->{keep_binary} == 2); # always remove or auto-remove
    }

    if ($keep_output) {
	if (-e $app_out) {
	  print "--- App stdout ---\n";
	  my $out = new IO::File("< $app_out");
	  if ((stat($out))[7] < $f_limit || !$f_limit) {
	    print <$out>;
	  } else {
	    my $line = 0;
	    while (<$out>) { print; last if ($line++ == 1024); }
	    print "\nHARNESSWARNING: OUTPUT LIMIT EXCEEDED -- OUTPUT TRUNCATED\n" if (<$out>);
	  }
	  undef $out;
	}
	if (-e $app_err) {
	  print "--- App stderr ---\n";
	  my $out = new IO::File("< $app_err");
	  if ((stat($out))[7] < $f_limit || !$f_limit) {
	    print <$out>;
	  } else {
	    my $line = 0;
	    while (<$out>) { print; last if ($line++ == 1024); }
	    print "\nHARNESSWARNING: OUTPUT LIMIT EXCEEDED -- OUTPUT TRUNCATED\n" if (<$out>);
	  }
	  undef $out;
	  print "\nHARNESSWARNING: TIME LIMIT EXCEEDED ($timeout)\n" if ($got_timeout);
	}
	print "------------------\n";
    }
    if ($remove_executable) {
	printf("Removing binary [$app]\n");
	unlink (is_cygwin() ? "${app}.exe" : "$app");
    }

        # append to report file
	my $rpt = new IO::File(">> $report_file");
	die "Cant append to $report_file" if !defined($rpt);
	print $rpt $outstr;
	undef $rpt;
}

sub gen_timestamp {
    my ($sec,$min,$hour,$day,$mon,$year) = (localtime(time))[0..5];
    $year += 1900;
    $mon++;
    return sprintf("%04d%02d%02d_%02d%02d%02d",
		   $year,$mon,$day,$hour,$min,$sec);
}

# ======================================================================
# Determine if the test passed by scanning the output file
# for (possibly) both the pass_expr and the fail_expr.
#
# Return a string indicating the results of the test.  The string
# will be:
#  "ignore" if neither a pass_expr or fail_expr expression is defined.
#  "SUCCESS"     if no fail_expr is found and a pass_expr is found.
#  "FAIL_EXPR" if a fail_expr is found
#  "PASS_EXPR" if no pass_expr is found.
# ======================================================================
sub pass_fail {
    my $fileout = shift;
    my $fileerr = shift;
    my $job = shift;
    my $passed = 1;
    my $result = "ignore";
    my $pass_expr = $job->{pass_expr};
    my $fail_expr = $job->{fail_expr};
    my $f_limit = $job->{f_limit};

    return "FAILED" if (! -e $fileout);
    my $out = new IO::File("< $fileout");
    return "FAILED" if (! -e $fileerr);
    my $err = new IO::File("< $fileerr");

    my ($outtxt, $errtxt);

    if ($f_limit && (stat($out))[7] > $f_limit) {
      $got_limit = 1;
    } else {
      local $/;
      $outtxt = <$out>;
    }

    if ($f_limit && (stat($err))[7] > $f_limit) {
      $got_limit = 1;
    } else {
      local $/;
      $errtxt = <$err>;
    }

    undef $out;
    undef $err;
  
    # remove known-harmless warnings 
    $errtxt =~ s/$warning_blacklist//mg; 
    $outtxt =~ s/$warning_blacklist//mg; 
    my $fulltxt = "$errtxt$outtxt";

    if (${fail_expr} !~ /^\s*0\s*$/) {
	if ( $outtxt =~ m/${fail_expr}/m || $errtxt =~ m/${fail_expr}/m) {
	    $passed = 0;
	    $result = "FAIL_EXPR";
	} else {
	    $result = "SUCCESS";
	}
    }
    if ($passed && (${pass_expr} !~ /^\s*0\s*$/)) {
	if ( $outtxt =~ m/${pass_expr}/m || $errtxt =~ m/${pass_expr}/m) {
	    $result = "SUCCESS";
	} else {
	    $passed = 0;
	    $result = "PASS_EXPR";
	}
    }
    # look for select error messages we generate
    # these are normally all in errtxt, but some job spawners cause them to end up in outtxt
    $got_outofmem = 1 if ($fulltxt =~ /UPC Runtime error:.*out of shared memory/);
    $got_outofmem = 1 if ($fulltxt =~ /UPC Runtime error:.*allocate sufficient shared memory/);
    $got_crash = 1 if ($fulltxt =~ /UPC Runtime error:/ && !$got_outofmem);
    $got_crash = 1 if ($fulltxt =~ /UPC Runtime: GASNet error/);
    $got_crash = 1 if ($fulltxt =~ /Caught a fatal signal/);
    $got_crash = 1 if ($fulltxt =~ /terminated with signal/);
    return $result;
}
