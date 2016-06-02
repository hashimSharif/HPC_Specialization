#!/usr/bin/env perl

################################################################################
################################################################################
##  'upcrun:'  job spawning script for the Berkeley UPC compiler
################################################################################
################################################################################


require 5.004;
use strict;
#use Getopt::Long;    # We use our own known-good version
use File::Basename;
use IO::File;
#use File::Temp qw/tempfile/; # module not portable
use POSIX qw(tmpnam ceil);
use Cwd;

################################################################################
# "Global" variables 
#  -----------------
# (actually, they're file-scoped lexicals, kind of like "static" in C)
################################################################################


# Configuration parameters.
#   Each config file variable must be set here, either to its default value, or
#   to 'nodefault' if there is no default value.  Adding a variables not in this
#   list to the config file will result in a (helpful) error message.  So will
#   failure to provide a value for variables with no default value.
my %conf = (
    default_options         => '',
    default_environment     => '',
    default_cpus_per_node   => 0,
    conduits                => 'nodefault',
    arch_size               => 'nodefault',
    exe_suffix              => 'nodefault',
    size_cmd                => '', # optional command
    debugmalloc             => 'no',
    debugmalloc_var         => '',
    debugmalloc_val         => '',
    upcrun_version          => 'nodefault',
    top_srcdir              => 'nodefault',
    top_builddir            => 'nodefault',
    totalview_exec          => 'totalview',
    totalview_timeout       => '120',
    enable_fca_by_default   => '',
    enable_fca              => 0
);
my (@all_conduits) = ('mpi', 'udp', 'smp', 'ibv', 'shmem', 'portals4', 'gemini', 'aries', 'pami', 'ofi', 'mxm');
foreach (@all_conduits) {
    $conf{$_."_spawn"}       = 'nodefault';
    $conf{$_."_spawn_nodes"} = '';
    $conf{$_."_options"}     = '';
    $conf{$_."_environment"} = '';
}

# directories
my ($cwd, $in_build_tree, $upcr_home, $upcr_bin, $upcr_etc, $upcr_include, $upcr_share);

# Command-line switches
my ( 
    $opt_help,
    $opt_help_gasnet,
    $opt_numthreads,
    $opt_heap_offset,
    $opt_shared_heap,
    $opt_shared_heap_max,
    $opt_versiononly,
    $opt_showonly,
    $opt_infoonly,
    $opt_localhost,
    $opt_polite_sync,
    $opt_quiet,
    $opt_verbose,
    $opt_verboseexpansion,
    $opt_th_per_proc,
    $opt_cpus_per_node,
    $opt_pshm_width,
    $opt_numnodes,
    $opt_abort,
    $opt_encode_args,
    $opt_encode_env,
    $opt_freeze,
    $opt_freeze_early,
    $opt_freeze_earlier,
    $opt_freeze_on_error,
    $opt_backtrace,
    $opt_backtrace_type,
    $opt_trace,
    $opt_trace_all,
    $opt_tracefile,
    $opt_totalview,
    $opt_norc,
    $opt_upcrunrc,
    $opt_bind_threads,
    $opt_fca_enable,
    $opt_fca_np,
    $opt_fca_verbose,
    $opt_fca_enable_ops
);
my %options_spec = (
    'h|?|help'          => \$opt_help,
    'help-gasnet:s'     => \$opt_help_gasnet,
    'heap-offset=s'     => \$opt_heap_offset,
    'shared-heap=s'     => \$opt_shared_heap,
    'shared-heap-max=s' => \$opt_shared_heap_max,
    'np=i'              => \$opt_numthreads,
    'n=s'               => \$opt_numthreads,
    'localhost'         => \$opt_localhost,
    'polite-sync'       => \$opt_polite_sync,
    'pthreads|p=i'      => \$opt_th_per_proc,
    'cpus-per-node|c=i'	=> \$opt_cpus_per_node,
    'nodes|N=i'		=> \$opt_numnodes,
    'pshm-width=i'      => \$opt_pshm_width,
    'show!'             => \$opt_showonly,
      't'               => \$opt_showonly,
    'info!'             => \$opt_infoonly,
      'i'               => \$opt_infoonly,
    'verbose!'          => \$opt_verbose,
      'v'               => \$opt_verbose,
    'quiet!'            => \$opt_quiet,
      'q'               => \$opt_quiet,
    'abort!'            => \$opt_abort,
    'encode!'           => sub { ($opt_encode_args, $opt_encode_env) = ($_[1], $_[1]) },
    'encode-args!'      => \$opt_encode_args,
    'encode-env!'       => \$opt_encode_env,
    'freeze-on-error!'  => \$opt_freeze_on_error,
    'freeze:s'          => \$opt_freeze,
    'freeze-early:s'    => \$opt_freeze_early,
    'freeze-earlier'    => \$opt_freeze_earlier,
    'backtrace!'        => \$opt_backtrace,
    'backtrace-type=s'  => sub { ($opt_backtrace_type, $opt_backtrace) = ($_[1], 1) }, # so -nobacktrace works right 
    'trace!'            => \$opt_trace,
    'traceall!'         => sub { ($opt_trace_all, $opt_trace) = ($_[1], 1) }, # so -notrace works right 
    'tracefile=s'       => sub { ($opt_tracefile, $opt_trace) = ($_[1], 1) }, # so -notrace works right 
    'version'           => \$opt_versiononly,
    'tv'		=> \$opt_totalview,
    'tv-freeze'		=> sub { $opt_totalview = 'freeze'; },
    'norc'		=> \$opt_norc,
    'conf=s'		=> \$opt_upcrunrc,
    'bind-threads'	=> \$opt_bind_threads,
    'fca_enable=i' => \$opt_fca_enable,
    'fca_np=i' => \$opt_fca_np,
    'fca_verbose=i' => \$opt_fca_verbose,
    'fca_ops=s' => \$opt_fca_enable_ops
);
sub getOpts
{   # Returns an array of "left overs", the non-option argumets
    my $dryrun = shift;	# opt_* are unset if this var is set
    local @ARGV = @_;	# Icky!!
    exit(-1) unless Getopt::Long::GetOptions(%options_spec);
    if (defined $opt_help_gasnet) {
	my $run_data_dir = ".";
	if ($opt_help_gasnet eq "") {
	  if ($in_build_tree) {
	    info_helpfile("$conf{top_srcdir}/gasnet/README");
	  } else {
	    info_helpfile("$upcr_share/doc/GASNet/README");
	  }
	} else {
	  $opt_help_gasnet =~ s/-conduit//;
	  my $conduit_list = " ".join(' ',@all_conduits)." extref ";
	  unless ($conduit_list =~ / $opt_help_gasnet /) {
	    die "unknown GASNet network conduit README: ".$opt_help_gasnet."\n".
                " the recognized conduit READMEs are: $conduit_list\n";
          }
	  if ($in_build_tree) {
	    if ($opt_help_gasnet eq "extref") {
	      info_helpfile("$conf{top_srcdir}/gasnet/extended-ref/README");
 	    } else {
	      info_helpfile("$conf{top_srcdir}/gasnet/".$opt_help_gasnet."-conduit/README");
	    }
	  } else {
	    info_helpfile("$upcr_share/doc/GASNet/README-".$opt_help_gasnet);
	  }
	}
    }
    usage() if $opt_help;
    if ($opt_versiononly) {
        print_version();
        exit(0);
    }
    if ($dryrun) { map { $$_ = undef unless (ref($_) eq 'CODE'); } (values %options_spec); }
    return @ARGV;
}

# Berkeley UPC version
my ($version_major, $version_minor, $version_patchlevel);

# network conduits supported and the one we're using
my @conduits;
my $conduit;

# name of the executable and its arguments
my $exename; # the Berkeley UPC exectable
my $spawn_exename; # the executable we'll actually spawn (might be a wrapper around exename)
my @exeargs;

# shared memory model
my $shmem_model;

# number of "native" threads per process
my $default_th_per_proc = 1;

# env settings we need to propagate to executable
my %envvars;

# 32/64 bit architecture size
my $arch_size;

# list of compute nodes
my $UPC_NODES;

# 'ctuples': configuration tuples embedded into objects/libraries
# in order to enforce executables are consistently built 
my $upcrlib_ctuple;
my $gasnetlib_ctuple;
my $upcrexe_sizes;
my $upcrexe_miscinfo;

# information extracted from executable
my $compiled_threads;
my @compilelines;
my ($gasnet_trace, $gasnet_stats, $gasnet_debug);

main();


################################################################################
## Initialize and run 
################################################################################
sub main {
    # Wrap everything in an exception handler, both for uniform error
    # formatting, and so we can always clean up temporary files
    eval {
        initialize();
        runDriver();
    };
    my $exception = $@;  # save in case clean_up() ever does an eval
    clean_up();
    die "upcrun: $exception" if $exception;
    exit(0);
}

################################################################################


################################################################################
## Show program usage message, then exit
################################################################################
sub usage 
{
    my ($errormsg, $h2mhelp) = @_;

    print <<EOF; 
Usage: upcrun [options] program-name [ program-arguments ... ] 
EOF
    unless ($h2mhelp) {
        print <<EOF;
For detailed documentation, please see man upcrun(1)
or visit http://upc.lbl.gov/docs/
EOF
    }
    print <<EOF; 

Options:
    -h -? -help
            See this message
    -help-gasnet [network_name]
            See the GASNet documentation, or the GASNet documentation
            for a particular network conduit.
    -conf=FILE
            Read FILE instead of the \$HOME/.upcrunrc configuration file.
    -norc
            Do not read the \$HOME/.upcrunrc configuration file.  
            This can also be achieved by setting the UPCRUN_NORC
            environment variable.  Overrides -conf.
    -n <num>
            Spawn <num> UPC threads. If the executable was compiled
            for dynamic thread count then this flag is required. When
            compiled for a static thread count, this flag is optional,
            but must agree with the compiled-in setting if present.
            (-np is a synonym for -n)
    -N -nodes <num>
            Specifies the number of compute nodes to use for
            execution. See the THREAD LAYOUT section of the man page
            for more details.
    -c -cpus-per-node <num>
            Specifies the number of UPC threads to execute on each
            compute node. See the THREAD LAYOUT section of the man
            page for more details.
    -p -pthreads <num>
            If the UPC executable was compiled with pthreads support
            then this option overrides the compiled-in default number
            of pthreads per process. A value of zero resets to the
            compiled-in default or the UPC_PTHREADS_PER_PROC
            environment variable. This flag is not legal with an
            executable not compiled with pthreads support.
    -pshm-width <num>
            If the UPC executable was compiled with PSHM support then this
            option sets the maximum number of processes which can comprise
            a shared-memory "supernode".  If more than this many processes
            are co-located on the same compute node, then they will become
            multiple supernodes for the purpose of PSHM.
            Note that this is a limit on processes, not on UPC threads,
            which will be different if pthreads is also in use.
            A value of 0 (the default) means no limit is imposed.
            A value of 1 essentially disables PSHM.
    -bind-threads
            Bind (aka pin) UPC threads to processors.
            (Silently ignored on unsupported platforms).
    -polite-sync
            Cause your UPC application to yield (rather than CPU spin) while
            waiting for locks/barriers.  This will slow down your 
            application if you are running on an uncontended system where 
            (CPUs >= UPC threads), which is why it is off by default.  
            However, if you are on a busy system, and/or are running more UPC
            threads per machine than there are CPUs, you should set this, 
            or your performance (and that of the whole machine) may suffer.
    -shared-heap <sz>
            Requests the given amount of shared memory (per UPC
            thread). Units of <sz> default to megabytes; use '2GB' to
            request 2 gigabytes per thread.
    -shared-heap-max <sz>
            Specify the hard limit (per UNIX process) of the 
            shared memory heap. This constitutes an upper limit on
            -shared-heap (although unlike -shared-heap this is a 
            per-NODE setting, so under -pthreads, all UPC threads on
            a node share this space). Setting this value too high
            can lead to long application startup times or memory 
            exhaustion on some systems.
            Units of <sz> default to megabytes; use '2GB' to request 
            2 gigabytes per process.
    -heap-offset <sz>
            Request the given offset between the starting addresses of
            the regular and shared heaps. Units of <sz> default to
            megabytes; use '2GB' to request 2 gigabytes.
    -[no]trace
            Enable tracing. This option is only effective if the
            executable was built with tracing enabled.
    -traceall
            Enable tracing of all events, including low-level events
            that are unnecessary for upc_trace. May impose significant
            run time and tracefile size penalties.  Implies -trace.
    -tracefile <file>
            Override the default destination for tracing output.
            If present, an optional `%' character in the filename
            will expand into a distinct integer for each process.
            This option implies -trace.
    -freeze[=<threadid>]
            Cause thread <threadid> to freeze at startup immediately
            before main() is called, to wait for a debugger to attach.
            <threadid> defaults to 0.
    -freeze-early[=<nodeid>]
            Cause node <nodeid> to freeze and await debugger attach
            early in the UPC runtime startup procedure, to assist in 
            debugging problems with the UPC runtime. 
            <threadid> defaults to 0.
            See the Berkeley UPC user guide for further info.
    -freeze-earlier
            Freeze program execution as early as possible in the 
            GASNet initialization procedure.
    -[no]freeze-on-error
            Freeze and await a debugger to attach on most program 
            errors or crashes.  Note this option has the potential to 
            create zombie processes that will need to be manually killed.
    -[no]abort
            Attempt to generate a core file on most program errors 
            or crashes. Core file generation must usually also be 
            enabled in the shell limits and OS policies.
    -[no]backtrace
            Enable backtraces. This option requests generation of
            a stack backtrace on most fatal errors, if supported
            on a given platform. These backtraces are valuable when
            reporting bugs. Note backtrace results are generally 
            more useful when the application was built with 
            'upcc -g'.  Also note that some types of program crashes 
            may cause the backtrace code to hang, potentially creating 
            zombie processes that will need to be manually killed. 
    -backtrace-type=<list>
            Tweak the mechanisms used to generate the backtrace.
            The list of available mechanisms is platform-specific,
            and can be viewed by running with -verbose.
            This option implies -backtrace.
    -encode-args -encode-env -encode
            Use a "safe" encoding for the command-line arguments,
            environment variables, or both. This may fix problems 
            with correct propagation on some spawners, especially
            for arguments or values containing spaces or other
            special characters.
    -q -[no]quiet
            Suppress initialization messages from UPC runtime.
    -v -[no]verbose
            Verbose: display commands invoked, environment variables
            set and other diagnostics.
    -t -[no]show
            Testing: don't actually start the job, just output the
            system commands that would have been used to do so.
    -i -[no]info
            Display useful information about the executable and exit
    -version
            Show version information for upcrun
EOF

if ($conf{enable_fca}) {
    print <<EOF;
    -fca_enable <1|0>
            Enable FCA for UPC collectives; default - 0
            This also can be set via environment variable GASNET_FCA_ENABLE_CMD_LINE
    -fca_np <np>
            Use FCA collectives if THREADS > <np>; default - 64
            This also can be set via environment variable GASNET_FCA_NP_CMD_LINE
    -fca_verbose <level>
            Set FCA verbosity level; default - 0
            This also can be set via environment variable GASNET_FCA_VERBOSE_CMD_LINE
    -fca_ops <+/->[op_list]
            op_list - comma separated list of collective operations. If provided with starting +/-
            then only specified operations are enabled/disabled. Allowed operation names are: 
            barrier (br), bcast (bt), reduce (rc).
            Each operation can be also enabled/disabled via environment variable:
            GASNET_FCA_ENABLE_BARRIER, GASNET_FCA_ENABLE_BCAST, GASNET_FCA_ENABLE_REDUCE.
            +/- provided without op_list enables/disables all operations.
            By default all operations are enabled.
EOF
}
    if (defined $errormsg) {
	print "ERROR: $errormsg\n";
	exit (-1);
    } else {
	exit(0);
    }
}

sub print_version
{
    printf <<EOF;
This is upcrun, job spawner for the Berkeley UPC compiler (http://upc.lbl.gov).
upcrun version $version_major.$version_minor.$version_patchlevel
Network conduits supported by this installation: @conduits
EOF
}

sub info_helpfile(@) {
  my $file = $_[0];                                                          
  my $pager = $ENV{PAGER}; # prefer the user's pager variable
  $pager = verify_exec($pager, $conf{exe_suffix}, 1) if ($pager);
  # if that fails, try some other favorites
  $pager = find_exec("less", $conf{exe_suffix}, 1) if (!$pager);
  $pager = find_exec("more", $conf{exe_suffix}, 1) if (!$pager);
  $pager = find_exec("cat", $conf{exe_suffix}, 1) if (!$pager);
  if (!$pager) { # give up and barf it manually
      open(MYFILE,"$file") or die "Can't open file $file\n";
      print while <MYFILE>;
      close MYFILE;
      exit 1;
  }                                                                        
  system "$pager $file" || die "Failed to find a suitable pager program";
  exit 1;                                                                    
}           

################################################################################
## Pthreads-related tests
################################################################################
sub isPthreads
{
    return $$upcrexe_miscinfo{DefaultPthreadCount}{'<link>'};
}
sub pthreadsPerProc
{
    return $ENV{'UPC_PTHREADS_PER_PROC'} || $$upcrexe_miscinfo{DefaultPthreadCount}{'<link>'};
}

################################################################################
## Node file input
################################################################################
sub parseNodeFile
{
  my ($nodefile) = @_;
  my @nodelist;
  my $fh = new IO::File("< $nodefile");
  return "" if (!defined($fh));
  while (<$fh>) {
    my @fields = split(' ',$_);
    foreach my $field (@fields) {
      if ($field =~ /\d+\.\d+\.\d+\.\d+/) { # IP Address
	push @nodelist, $field;
      } elsif ($field =~ /[A-Za-z_][A-Za-z0-9_.-]*/) { # legal DNS hostname
	push @nodelist, $field;
      } else {
	last; # assume anything else begins a comment or cpu count
      }
    }
  }
  undef $fh;
  return join(',', @nodelist);
}

################################################################################
## Speak if asked to
################################################################################
sub verbose 
{
    print "@_\n" if $opt_verbose;
}

################################################################################
## Encode args and env for safe consumption by GASNet
################################################################################

sub gasnet_encode {
    my ($in) = @_;
    $in =~ s!%(0[0-9A-Fa-f]{2})!%025$1!g; # prevent false decodes
    $in =~ s!([^A-Za-z0-9%_,\./:+=@^-])!'%0'.unpack("H2",$1)!ge;
    return $in;
}

################################################################################
### Initialization code
################################################################################
sub initialize 
{
    # hack: if we're being called by help2man as part of generating the upcrun
    # man page, we use a different 'version' option (we can't use the regular
    # one, since we'll have no valid conf file to read)
    #print "ARGS: " . join ('|',@ARGV)."\n";
    my (@v) = grep {s/^-h2mversion=([0-9.]+)$/$1/} @ARGV;
    if (@v) {
        # help2man format
        print "upcrun @v\n";
        exit(0);
    }
    # same thing, but for help2man's -h2mhelp call
    if (grep { /-h2mhelp/ } @ARGV) {
        usage(undef, 1);
    }

    # current directory
    $cwd = getcwd();  

    # find where this script is located
    $upcr_bin = $0;
    while (readlink($upcr_bin)) { 
      my $target = readlink($upcr_bin);
      if (substr($target,0,1) eq "/") {
        $upcr_bin = $target; 
      } else {
        $upcr_bin = dirname($upcr_bin) . "/" . $target; 
      }
    }
    $upcr_bin = dirname($upcr_bin);    # from File::Basename
    # if we're in build tree, everything in same dir
    if (-f "$upcr_bin/upcrun.conf") {
        $upcr_home = $upcr_etc = $upcr_include = $upcr_share = $upcr_bin;
	$in_build_tree = 1;
    } else {
        # should be in $prefix/bin part of an installed tree, with 'include' and
        # 'etc' siblings
        $upcr_bin =~ m@^(.*?)/bin$@;
        $upcr_home = $1;
        $upcr_etc = "$upcr_home/etc";
        $upcr_include = "$upcr_home/include";
        $upcr_share = "$upcr_home/share";
        unless (-f "$upcr_etc/upcrun.conf") {
            die "upcrun.conf neither in upcrun directory, nor in '$upcr_etc'\n";
        }
	$in_build_tree = 0;
    }

    # load the getopt, ctuple config checking and utility libraries
    push @INC, $upcr_include;
    require "upcr_ctuple.pl";
    require "upcr_util.pl";
    require "upcr_getopt.pl";

    # Chicken and egg situation:
    # We need to read our config file(s) to get the default args, but the
    # search for config files depends on certain options.
    # This little trick lets us parse these options from the
    # command-line without actually modifying @ARGV.
    { 
      local @ARGV = @ARGV;
      Getopt::Long::Configure("permute","pass_through","no_auto_abbrev");
      exit(-1) unless Getopt::Long::GetOptions(
        'conf=s'            => \$opt_upcrunrc,
        'norc'              => \$opt_norc
      );
      Getopt::Long::Configure("no_permute","no_pass_through","auto_abbrev");
    }
    $opt_norc = 1 if defined $ENV{UPCRUN_NORC};

    # GetOpt::Long--allow bundling of single char flags, but also recognize long
    # flags with either a single or double dash (see 'perldoc Getopt::Long').
    Getopt::Long::Configure("bundling_override","require_order");

    # read and validate config file(s)
    readconfig();
    $arch_size = $conf{arch_size};
    if ($arch_size != 32 && $arch_size != 64) {
	# watch out for jokers and resurrected PDP-10 systems
        die "upcrun does not presently support $arch_size-bit architectures\n";
    }
    if ($conf{upcrun_version} =~ /^(\d+)\.(\d+)\.(\d+)$/) {
        $version_major = $1;
        $version_minor = $2;
        $version_patchlevel = $3;
    } else {
        die "Invalid upcrun version string '$conf{version}' in configuration file\n";
    }
    @conduits = split /\s+/, $conf{conduits};

    # Parse the command line, discarding the resulting option settings
    # We do this so we can find the executable, which determines the
    # correct conduit, which in turn determines the full set of options.
    ($spawn_exename, @exeargs) = getOpts(1, @ARGV);
    # ensure we can find spawn executable
    usage("missing program name") unless (length $spawn_exename);
    $spawn_exename = find_exec($spawn_exename, $conf{exe_suffix});
    
    # Now parse the executable
    foreach my $tryexe ($spawn_exename, @exeargs) { # allow the Berkeley UPC executable to appear later in args
      $exename = $tryexe; 
      eval { # silence any "bad executable" messages
        parseExecutable();
      };
      if ($@) { $exename = undef; next; }
      else { last; } # found it
    }
    if (!$exename) { # failed to find it, report failure now
      $exename = $spawn_exename;
      parseExecutable() 
    }

    # Now we can parse all the options with correct precedence
    my @args_out;
    @args_out = getOpts(0, split_quoted($conf{default_options},"while parsing default_options"));
    die "Non-option argment '$args_out[0]' found in default_options\n"
	if (@args_out);
    @args_out = getOpts(0, split_quoted($conf{"${conduit}_options"},"while parsing ${conduit}_options"));
    die "Non-option argment '$args_out[0]' found in ${conduit}_options\n"
	if (@args_out);
    @args_out = getOpts(0, split_quoted($ENV{UPCRUN_FLAGS},"while parsing UPCRUN_FLAGS"));
    die "Non-option argment '$args_out[0]' found in UPCRUN_FLAGS\n"
	if (@args_out);
    @args_out = getOpts(0, @ARGV);

    unless (grep { /$conduit/ } @conduits or $opt_infoonly) {
        die "'$exename' was compiled for an unsupported network conduit: '$conduit'\n";
    }

    $opt_verboseexpansion = $opt_verbose; # only expand %V to -v if the user passed -v
    $opt_verbose = 1 if ($opt_showonly);
    $ENV{"GASNET_VERBOSEENV"} = 1 if ($opt_verbose);
    pushVar("UPC_POLITE_SYNC", 1) if $opt_polite_sync;

    # for debug builds enable any plaform-specific malloc debugging
    if ($gasnet_debug && ($conf{debugmalloc} eq 'yes')) {
        die "debugmalloc=yes but debugmalloc_var is unset or empty" unless($conf{debugmalloc_var});
        die "debugmalloc=yes but debugmalloc_val is unset or empty" unless($conf{debugmalloc_val});
	pushVar($conf{debugmalloc_var},$conf{debugmalloc_val})
            unless defined($ENV{$conf{debugmalloc_var}});
    }

    if ($opt_infoonly) {
        print_info();
        exit(0);
    }

    # Now we parse environment settings with correct precedence
    # Note that options processing may override these later
    foreach my $setting ("default_environment", "${conduit}_environment") {
      foreach my $varval (split_quoted($conf{$setting},"while parsing $setting")) {
        # Split into 2 parts at first '='
        my ($var, $val) = split /=/, $varval, 2;
        if (!defined($var)) {
	  die "Syntax error while parsing $setting\n";
        } elsif (defined($val)) {
	  # FOO=BAR - set unless user has a value
	  pushVar($var,$val) unless (defined($ENV{$var}));
        } elsif ($var =~ m/^!(.*)/) {
	  # !FOO - remove from our list if we (might have) set it earlier
	  pushVar($1,undef);
        } else {
	  # FOO - set to user's value, a no-op unless spawner needs envlist (thus undocumented)
	  pushVar($var,$ENV{$var});
        }
      }
    }
    # Slurp the enviroment bits now so later processing will see them
    while (my ($var, $val) = (each %envvars)) {
      if (defined($val)) {
        $ENV{$var} = $val;
      }
    }

    if (defined $opt_quiet) {
	# -noquiet removes UPC_QUIET from the environment
	pushVar('UPC_QUIET', $opt_quiet ? 1 : undef);
    }

    #################################################################
    # Parsing FCA parameters
    #################################################################
    if (defined $opt_fca_enable) {
        if (!$conf{enable_fca}){
            print "Invalid option \"fca_enable\": this upc build does not support FCA\n";
            exit(-1);
        }
        $opt_fca_enable =~ s/^p([0-1])$/$1/;
        die "Value \"$opt_fca_enable\" may be 0 or 1\n"
        unless ($opt_fca_enable =~ /^[0-1]$/);

        pushVar('GASNET_FCA_ENABLE_CMD_LINE', $opt_fca_enable);
    }
    elsif ($conf{enable_fca}){
        pushVar('GASNET_FCA_ENABLE_CMD_LINE', $conf{enable_fca_by_default}, 1);
    }

    if (defined $opt_fca_np) {
        if (!$conf{enable_fca}){
            print "Invalid option \"fca_np\": this upc build does not support FCA\n";
            exit(-1);
        }
        $opt_fca_np =~ s/^p([0-9][0-9]*)$/$1/;
        die "Value \"$opt_fca_np\" is not correct np value\n"
        unless ($opt_fca_np =~ /^[0-9][0-9]*$/);

        pushVar('GASNET_FCA_NP_CMD_LINE', $opt_fca_np);
    }
    elsif ($conf{enable_fca}){
        pushVar('GASNET_FCA_NP_CMD_LINE', 64, 1);
    }

    if (defined $opt_fca_verbose) {
        if (!$conf{enable_fca}){
            print "Invalid option \"fca_verbose\": this upc build does not support FCA\n";
            exit(-1);
        }
        $opt_fca_verbose =~ s/^p([0-9][0-9]*)$/$1/;
        die "Value \"$opt_fca_verbose\" is not correct verbose value\n"
        unless ($opt_fca_verbose =~ /^[0-9][0-9]*$/);

        pushVar('GASNET_FCA_VERBOSE_CMD_LINE', $opt_fca_verbose);
    }
    elsif ($conf{enable_fca}){
        pushVar('GASNET_FCA_VERBOSE_CMD_LINE', 0, 1);
    }

    if (defined $opt_fca_enable_ops) {
        if (!$conf{enable_fca}){
            print "Invalid option \"fca_ops\": this upc build does not support FCA\n";
            exit(-1);
        }
        my @allowed = ('barrier','br','bcast','bt','reduce','rc');
        my $short_to_long = {br => 'barrier',bt => 'bcast',rc => 'reduce',};

        my %allowed_map = map { $_ => 1} @allowed;
        my $enabled_ops = {barrier => 1,bcast   => 1,reduce  => 1,};
        $opt_fca_enable_ops =~ s/^(.)//;
        my $sign = $1;
        if ($sign ne "+" && $sign ne "-"){
            print("Wrong format! Use <+/-><operation identifier>\n");
            exit(0);
        }

        if (($opt_fca_enable_ops eq "" and $sign eq "-") or
            ($opt_fca_enable_ops ne "" and $sign eq "+")){
            $enabled_ops = {barrier => 0,bcast   => 0,reduce  => 0,};
        }

        my @ops = grep length, split(/\s*,\s*/,$opt_fca_enable_ops);
        foreach my $op (@ops){
            if (!exists($allowed_map{$op})){
                print("<$op> is not allowed operation identifier. Allowed are:".join(',',@allowed).".\n");
                exit(0);
            }
            if ($short_to_long->{$op}){
                $op = $short_to_long->{$op};
            }
            if ($sign eq "+"){
                $enabled_ops->{$op} = 1;}
            else{
                $enabled_ops->{$op} = 0;}

        }

        pushVar('GASNET_FCA_ENABLE_BARRIER', $enabled_ops->{'barrier'});
        pushVar('GASNET_FCA_ENABLE_BCAST', $enabled_ops->{'bcast'});
        pushVar('GASNET_FCA_ENABLE_REDUCE', $enabled_ops->{'reduce'});
    }   
    elsif ($conf{enable_fca}){
        pushVar('GASNET_FCA_ENABLE_BARRIER', 1, 1);
        pushVar('GASNET_FCA_ENABLE_BCAST', 1, 1);
        pushVar('GASNET_FCA_ENABLE_REDUCE', 1, 1);
    }
    #################################################################

    # user override of heap sizes
    my $shared_heapoffset = $$upcrexe_sizes{UPC_SHARED_HEAP_OFFSET};
    $shared_heapoffset = $ENV{UPC_SHARED_HEAP_OFFSET} if ($ENV{UPC_SHARED_HEAP_OFFSET});
    if (defined $opt_heap_offset) {
      if (parse_size($opt_heap_offset) ne parse_size($shared_heapoffset)) {
        pushVar("UPC_SHARED_HEAP_OFFSET", strip_whitespace(size_str(parse_size($opt_heap_offset),1)));
      }
    }
    my $shared_heapsz = $$upcrexe_sizes{UPC_SHARED_HEAP_SIZE};
    $shared_heapsz = $ENV{UPC_SHARED_HEAP_SIZE} if ($ENV{UPC_SHARED_HEAP_SIZE});
    if (defined $opt_shared_heap) {
      if (parse_size($opt_shared_heap) eq parse_size($shared_heapsz)) {
	$opt_shared_heap = undef;
      } else {
        $shared_heapsz = $opt_shared_heap;
      }
    }
    # shared heap max: lowest priority is configured default
    my $default_shared_heapsz_max = $$upcrexe_miscinfo{GASNetDefaultMaxSegsize};
    if ($default_shared_heapsz_max) { # decode the GASNet C size expression
	$default_shared_heapsz_max =~ s/\(_*u?int(32|64)_t\)//g;
	$default_shared_heapsz_max =~ s/([0-9])[uU][lL]{0,2}/\1/g;
	$default_shared_heapsz_max = eval $default_shared_heapsz_max;
        $default_shared_heapsz_max .= "B"; # value is in bytes
    }
    # then value embedded by upcc
    $default_shared_heapsz_max = $$upcrexe_sizes{UPC_SHARED_HEAP_SIZE_MAX} if ($$upcrexe_sizes{UPC_SHARED_HEAP_SIZE_MAX});
    # then GASNet environment variable
    if ($ENV{GASNET_MAX_SEGSIZE}) {
      $default_shared_heapsz_max = $ENV{GASNET_MAX_SEGSIZE};
      # GASNET_MAX_SEGSIZE defaults to units of bytes, so make that explicit to parse_size
      $default_shared_heapsz_max .= "B" if ($default_shared_heapsz_max =~ m/^[0-9\s]+$/);
    }
    my $shared_heapsz_max = $default_shared_heapsz_max;
    # then UPC environment variable to this script
    $shared_heapsz_max = $ENV{UPC_SHARED_HEAP_SIZE_MAX} if ($ENV{UPC_SHARED_HEAP_SIZE_MAX});
    $shared_heapsz_max = $opt_shared_heap_max if (defined $opt_shared_heap_max);
    # finally, allow upcrun command-line override
    if ($default_shared_heapsz_max && $shared_heapsz_max && 
          parse_size($shared_heapsz_max) eq parse_size($default_shared_heapsz_max)) {
	$opt_shared_heap_max = undef; # just using the default
    } else {
	$opt_shared_heap_max = $shared_heapsz_max; # default override
    }

    my ($shared_fixedsz, $shared_perthreadsz, $shared_threadzerosz) = get_static_sharedsz();
    my $pagesz = $$upcrexe_miscinfo{UPCRPageSize} || 16*1024;
    my $sharedsz = alignup($shared_threadzerosz, $pagesz);
    my $minsz = ($sharedsz > 0 ? $sharedsz + 2*$pagesz + 1024*1024 : 0);
    if (parse_size($shared_heapsz) < $minsz) {
	my $min_str = size_str($minsz,1);
        my $shared_size_str = get_static_sharedstr();
	print "upcrun: WARNING: increasing UPC_SHARED_HEAP_SIZE to: $min_str\n".
              "upcrun: WARNING: to accomodate static shared data size of: $shared_size_str\n";
        $opt_shared_heap = $min_str;
    }
    if ($upcrlib_ctuple =~ m/SHAREDPTRREP=fsymmetric/) {
        my $prev = parse_size($shared_heapsz);
        my $tmp = 1 << POSIX::ceil( log( $prev ) / log(2.0) );
        if ($tmp ne $prev) {
	    $opt_shared_heap = size_str($tmp,1);
	    print "upcrun: WARNING: increasing UPC_SHARED_HEAP_SIZE to: $opt_shared_heap\n".
                  "upcrun: WARNING: to accomodate power-of-two alignment requirement.\n";
        }
    }
    if (defined $opt_shared_heap) {
        pushVar("UPC_SHARED_HEAP_SIZE", strip_whitespace(size_str(parse_size($opt_shared_heap),1)));
        $shared_heapsz = $opt_shared_heap;
    }


    # Parse/validate/use $opt_numthreads
    if (defined $opt_numthreads) {
        $opt_numthreads =~ s/^p([1-9][0-9]*)$/$1/;
	die "Value \"$opt_numthreads\" is not a valid thread count\n"
            unless ($opt_numthreads =~ /^[1-9][0-9]*$/);
    }
    if ($compiled_threads && $opt_numthreads && $opt_numthreads != $compiled_threads) {
	die "Requested thread count ($opt_numthreads) differs from compiled static thread count ($compiled_threads)\n";
    } elsif ($compiled_threads && !$opt_numthreads) {
 	$opt_numthreads = $compiled_threads; # default to static thread count
    } elsif ($conduit eq "smp") {
	# for smp conduit we need some special cases
	if ($opt_numthreads) {
	  # Ensure pthreads or PSHM is present if > 1 thread requested
	  die "When network=smp compile with '-pthreads' or PSHM support to run with > 1 thread\n"
	    if (($opt_numthreads > 1) && ($shmem_model eq 'none'));
	} else {
 	  # Set UPC thread count to the pthread count or 1 if there is no other source.
	  $opt_numthreads = pthreadsPerProc() || 1;
	}
    } elsif (!$opt_numthreads) {
 	die "Missing thread count\n";
    }

    # th_per_proc
    if ($shmem_model !~ m/pthreads/) {
	if (defined $opt_th_per_proc) {
	    die "illegal option -pthreads=$opt_th_per_proc\n";
	} else {
	    $opt_th_per_proc = 1;
	}
    } elsif (($conduit eq 'smp') && ($shmem_model !~ m/pshm/)) {
	if (!$opt_th_per_proc) {
	    $opt_th_per_proc = $opt_numthreads;
	} elsif ($opt_th_per_proc != $opt_numthreads) {
	    die "with network=smp UPC threads ($opt_numthreads) and pthreads ($opt_th_per_proc) must agree\n";
	}
    } elsif (!$opt_th_per_proc) {
	$opt_th_per_proc =  $default_th_per_proc;
    }
    if ($opt_th_per_proc < 1) {
	die "illegal option -pthreads=$opt_th_per_proc\n";
    }

    # bug 2191: estimate GASNet's auxseg utilization to include in GASNET_MAX_SEGSIZE
    # GASNet provides us with ident strings of the form $GASNetAuxSeg_<module>: <expr> $
    # where expr is an arithmetic expression that estimates the auxseg usage of that module, in bytes
    # expr may include environment variable lookups of the form:  <varname>:<default_value_expr>
    # we add up the contribution of each module, rounding to cache line boundaries and round the result to a page
    my $shared_heapsz_max_padding = 0;
    foreach my $varname (keys %{$upcrexe_miscinfo}) {
      if ($varname =~ m/GASNetAuxSeg_/) {
        my $valstr = $$upcrexe_miscinfo{$varname};
	while ($valstr =~ m/([a-zA-Z]\w*):/) {
	  my $envvar = $1;
	  my $envval = $ENV{$envvar} || 0;
	  my $parsedval = 0;
          eval { $parsedval = parse_size($envval,"b"); } ;
	  $valstr =~ s/$envvar:/$parsedval||/;
	}
	my $val = 0;
	eval { $val = eval $valstr; };
        #print "$varname = $valstr ($val)\n";
	$val = alignup($val,128);
	$shared_heapsz_max_padding += $val if ($val > 0);
      }
    }
    $shared_heapsz_max_padding = alignup($shared_heapsz_max_padding, $pagesz);

    my $shared_heapsz_max_minval = $opt_th_per_proc*parse_size($shared_heapsz) + $shared_heapsz_max_padding;
    if (defined $shared_heapsz_max && parse_size($shared_heapsz_max) < $shared_heapsz_max_minval) {
        $opt_shared_heap_max = size_str($shared_heapsz_max_minval, 1);
	verbose("*** upcrun: increasing UPC_SHARED_HEAP_SIZE_MAX to: $opt_shared_heap_max ".
                "to accomodate UPC_SHARED_HEAP_SIZE = $shared_heapsz ($opt_th_per_proc threads / process)");
    } elsif ($shared_heapsz) {
        # Try to LOWER GASNet's segment search while padding by larger of 10% or 16MB.
        my $tmp = $shared_heapsz_max_minval;
        if ($upcrlib_ctuple =~ m/SHAREDPTRREP=fsymmetric/) {
          # UPCR will round up to next power-of-2, so we should too
          $tmp = 1 << POSIX::ceil( log($tmp) / log(2.0) );
        } else {
          my $pad = max(int(0.10 * $tmp), 16777216);
          $tmp = alignup(($tmp + $pad), $pagesz);
        }
        if (!defined($shared_heapsz_max) || (parse_size($shared_heapsz_max) > $tmp)) {
            $opt_shared_heap_max = size_str($tmp, 1)
        }
    }
    if (defined $opt_shared_heap_max) {
        pushVar("GASNET_MAX_SEGSIZE", strip_whitespace(size_str(parse_size($opt_shared_heap_max),1)));
    }

    # cpus_per_node and numnodes
    die "Invalid setting default_cpus_per_node='$conf{default_cpus_per_node}'\n"
	unless (($conf{default_cpus_per_node} =~ m/\d*/) && ($conf{default_cpus_per_node} >= 0));
    die "Invalid setting -nodes='$opt_numnodes'\n"
	unless ($opt_numnodes >= 0);
    die "Invalid setting -cpus_per_node='$opt_cpus_per_node'\n"
	unless ($opt_cpus_per_node >= 0);

    # pshm-width
    if (defined $opt_pshm_width) {
        die "illegal option -pshm-width='$opt_pshm_width'\n"
	    unless ($shmem_model =~ m/pshm/);
        die "Invalid setting -pshm-width='$opt_pshm_width'\n"
            unless ($opt_pshm_width >= 0);
        if (($conduit eq 'smp') && ($opt_pshm_width != 0) &&
            ($opt_pshm_width < int(($opt_numthreads + $opt_th_per_proc - 1) / $opt_th_per_proc))) {
            print "upcrun: WARNING: ignoring -pshm-width=$opt_pshm_width, which is too small for $opt_numthreads UPC threads.\n";
            $opt_pshm_width = 0;
        }
        pushVar("GASNET_SUPERNODE_MAXSIZE", $opt_pshm_width);
    }

    if ($opt_localhost) {
        die "-localhost can only be used if -network=udp\n" unless $conduit eq 'udp';
        pushVar("GASNET_SPAWNFN", "L");
        # UPC_POLITE_SYNC is no longer needed since we now detect the overcommit.
        # However, we keep this to avoid the warning and for consistent
        # behavior across releases and across thread counts.
        pushVar("UPC_POLITE_SYNC", "1", 1);
    } else {
        # parse node files and environment variables into UPC_NODES
        # precedence ordering: 
        # UPC_NODES - list of nodes to use
        # UPC_NODEFILE - file of nodes to use
        # GASNET_NODEFILE - file of nodes to use
        # PBS_NODEFILE - file of nodes to use
        # PE_HOSTFILE - file of nodes to use
        # SSS_HOSTLIST - list of nodes to use
        # LSB_HOSTS - list of nodes to use
        $UPC_NODES = $ENV{UPC_NODES};
        my $recognized_file = 0;
        if (!$UPC_NODES && $ENV{UPC_NODEFILE} && -f $ENV{UPC_NODEFILE}) {
            $UPC_NODES = parseNodeFile($ENV{UPC_NODEFILE});
        }
        if (!$UPC_NODES && $ENV{GASNET_NODEFILE} && -f $ENV{GASNET_NODEFILE}) {
            $UPC_NODES = parseNodeFile($ENV{GASNET_NODEFILE});
            $recognized_file = 1;
        }
        if (!$UPC_NODES && $ENV{PBS_NODEFILE} && -f $ENV{PBS_NODEFILE}) {
            $UPC_NODES = parseNodeFile($ENV{PBS_NODEFILE});
            $recognized_file = 1;
        }
        if (!$UPC_NODES && $ENV{PE_HOSTFILE} && -f $ENV{PE_HOSTFILE}) {
            $UPC_NODES = parseNodeFile($ENV{PE_HOSTFILE});
	    # Only "recognized" for mpi- and ssh-spawners:
            $recognized_file = grep($_ eq $conduit, qw(mpi ofi mxm ibv));
        }
        if (!$UPC_NODES && $ENV{SLURM_NODELIST}) {
            $UPC_NODES = `scontrol show hostnames $ENV{SLURM_NODELIST}`
		or die 'failed to "scontrol show hostnames"';
            $UPC_NODES =~ tr/\n/ /;
        }
        if (!$UPC_NODES && $ENV{SSS_HOSTLIST}) {
            $UPC_NODES = $ENV{SSS_HOSTLIST};
        }
        if (!$UPC_NODES && $ENV{LSB_HOSTS}) {
            $UPC_NODES = $ENV{LSB_HOSTS};
        }
        if ($UPC_NODES) {
          pushVar('UPC_NODES', $UPC_NODES);

          if ($conduit eq 'mpi'
                            && !$recognized_file) { # create a GASNET_NODEFILE holding UPC_NODES
            #my ($fh, $filename) = tempfile("gasnet-nodefile-XXXXXXX"); # tempfile not portable
            my ($fh, $filename);
            do { $filename = tmpnam() }
              until $fh = IO::File->new($filename, O_RDWR|O_CREAT|O_EXCL);
            foreach my $node (split(/[\s,\/;]+/,$UPC_NODES)) {
                print $fh "$node\n";
            }
            undef $fh;
            pushVar('GASNET_NODEFILE', $filename);
            pushVar('GASNET_RM_NODEFILE', 1);
          }
        } elsif ($conduit eq 'udp' && !defined $ENV{GASNET_SPAWNFN}) {
            die "nodes not specified!  See RUNNING UDP-BASED UPC JOBS in 'man upcrun'\n";
        } 
    
    }

    # other misc spawning helper variables that require name translation
    if ($ENV{UPC_SSH}) {
      pushVar('GASNET_SSH_CMD', $ENV{UPC_SSH})
        if (!$ENV{GASNET_SSH_CMD} && !$ENV{AMUDP_SSH_CMD} && !$ENV{SSH_CMD});
    }

    # Altix requires MPI_DSM_DISTRIBUTE to be set for parallel jobs, or else
    # processes are not guaranteed to be bound to CPUs
    if ((-d "/dev/hw/cpunum" || -c "/dev/xpmem") && !$ENV{'MPI_DSM_DISTRIBUTE'}) {
	pushVar('MPI_DSM_DISTRIBUTE', 1);
    }

    # Task and memory affinity on AIX/POE are harmful to pthreads runs (bug 1553)
    if (isPthreads() && ($^O =~ /AIX/i)) {
	pushVar('MP_TASK_AFFINITY', '-1');
	pushVar('MEMORY_AFFINITY', '-1');
    }

    # setup tracing if requested
    if ($opt_trace) {
	die "Tracing requested, but not enabled in the executable\n"
	    unless ($gasnet_trace);
	foreach my $line (@compilelines) {	# loop over compilation units
	    my $have_lines = 1;
	    foreach my $option (split " ", $line) {	# loop over options
		# these options are toggles 
	        $have_lines = 1 if ($option eq '-lines');
	        $have_lines = 0 if ($option eq '-nolines');
	    }
	    # If any one compilation unit lacks line info we will warn.
	    if (!$have_lines) {
		print "upcrun: WARNING: tracing an executable compiled with `-nolines'.  Trace information may not correspond to original source lines.\n";
		last;
	    }
	}
	(my $shortname = $exename) =~ s|.*/||;
	my $trace_id = join('-', ($shortname, $opt_numthreads, $$));
	pushVar("GASNET_TRACEFILE", ($opt_tracefile || "upc_trace-${trace_id}-%"));
        pushVar("UPC_TRACE_ID", uc($trace_id));
	if ($opt_trace_all) {
	  if (defined $ENV{'GASNET_TRACEMASK'}) {
	    verbose("*** upcrun: Unsetting user's GASNET_TRACEMASK for -traceall");
	    delete $ENV{'GASNET_TRACEMASK'};
          }	
	} elsif (defined $ENV{'GASNET_TRACEMASK'}) {
	    verbose("*** upcrun: Keeping user's GASNET_TRACEMASK");
	    pushVar("GASNET_TRACEMASK", $ENV{'GASNET_TRACEMASK'});
	} else {
	    pushVar("GASNET_TRACEMASK", "GPBHWXIN");
	}
	if ($opt_trace_all) {
	  if (defined $ENV{'GASNET_STATSMASK'}) {
	    verbose("*** upcrun: Unsetting user's GASNET_STATSMASK for -traceall");
	    delete $ENV{'GASNET_STATSMASK'};
          }	
	} elsif (defined $ENV{'GASNET_STATSMASK'}) {
	    verbose("*** upcrun: Keeping user's GASNET_STATSMASK");
	    pushVar("GASNET_STATSMASK", $ENV{'GASNET_STATSMASK'});
	} else {
	    # default to a statsmask of everything
	    # the runtime cost of collecting/outputting statistics is lost in the noise 
            # relative to tracing, and it provides useful summary info at the end of each trace
	    # which are human-readable and may even be useful to gasnet_trace someday
	    #pushVar("GASNET_STATSMASK", "");
	}
    }

    # Setup for Totalview debugger if requested (and supported)
    if ($opt_totalview) {
	die "Invalid request for Totalview launch: executable not built with -tv\n"
	    unless ($$upcrexe_miscinfo{UPCRTotalview});
	if ($opt_totalview eq 'freeze') {
	    # We just tell the application to freeze until use attaches Totalview
	    pushVar("UPC_TOTALVIEW_FREEZE", 1);
	} else {
	    # We launch Totalview to attach automatically to the application

	    # Check for perl support to allow graceful failure
	    eval { require Socket; };
	    die "Totalview launch requires missing Socket perl module\n" if ($@);
	    eval { require Sys::Hostname; };
	    die "Totalview launch requires missing Sys::Hostname perl module\n" if ($@);

	    # Create listening socket
	    require Socket;
	    require Sys::Hostname;
	    socket(L, &Socket::PF_INET, &Socket::SOCK_STREAM, getprotobyname('tcp'))	|| die "socket: $!";
	    bind(L, Socket::sockaddr_in(0, &Socket::INADDR_ANY))			|| die "bind: $!";
	    listen(L, &Socket::SOMAXCONN)						|| die "listen: $!";
	    (my $port, undef) = Socket::unpack_sockaddr_in(getsockname(L));
	    pushVar("UPC_TOTALVIEW_SOCKET", &Sys::Hostname::hostname . " $port");

	    # Create child to read host/pid/exec from the socket and then spawn totalview
	    my $main_pid = $$;
	    my $child_pid = fork();
	    die "fork() failed in Totalview launch\n"
	        unless defined($child_pid);
	    if (!$child_pid) { # I am child
		local $SIG{ALRM} = sub { die "Timeout waiting for Totalview launch\n"; };
		alarm $conf{totalview_timeout};
		accept(S,L)	|| die "accept: $!";
		close L;
		my ($host, $pid, $exec);
		{   local $/; # to slurp entire "file"
		    ($host, $pid, $exec) = split(" ", <S>);
		    close S;
		}
		alarm 0;
		my @tv_cmd = ($conf{totalview_exec}, '-remote', $host, '-pid', $pid, $exec);
		eval { runCmd(@tv_cmd) };
		# Send the bad news if we failed to exec totalview
		(kill TERM => $main_pid) || exit 0;
		die "'" . join(' ', @tv_cmd) . "' failed: $@";
	    } else {
		close L;
	    }
	}
        if ($opt_backtrace) {
	  print "upcrun: WARNING: Requested both Totalview and backtraces - backtraces disabled.\n";
	  undef $opt_backtrace;
	  undef $opt_backtrace_type;
        }
    }

    # propagate misc settings
    pushVar("UPC_ABORT", 1) if ($opt_abort);
    pushVar("GASNET_BACKTRACE", 1) if ($opt_backtrace);
    pushVar("GASNET_BACKTRACE_TYPE", $opt_backtrace_type) if ($opt_backtrace_type);
    pushVar("UPC_FREEZE", $opt_freeze || 0) if (defined $opt_freeze);
    pushVar("UPC_FREEZE_EARLY", $opt_freeze_early || 0) if (defined $opt_freeze_early);
    pushVar("GASNET_FREEZE", 1) if (defined $opt_freeze_earlier);
    pushVar("GASNET_FREEZE_ON_ERROR", $opt_freeze_on_error) if ($opt_freeze_on_error);
}

################################################################################
### Read relevant information from the executable
################################################################################
sub parseExecutable {
  $exename = find_exec($exename, $conf{exe_suffix});
  # get gasnet and runtime built-in ctuples, which contain important info
  my ($gastup_ref, $upcrtup_ref, $sizes_ref, $misc_ref) = extract_ctuples($exename);
  $upcrlib_ctuple = $$upcrtup_ref{'<link>'};
  $gasnetlib_ctuple = $$gastup_ref{'<link>'};
  $upcrexe_sizes = $sizes_ref;
  $upcrexe_miscinfo = $misc_ref;
  if (!$upcrlib_ctuple || !$gasnetlib_ctuple) {
    die "'$exename' is not a Berkeley UPC executable\n";
  }

  my $bitwidth = ($$upcrexe_sizes{void_ptr} * 8);
  if ($bitwidth != $arch_size) {
    die "'$exename' is a ${bitwidth}-bit executable, not ${arch_size}-bit\n";
  }

  # get compiled-in thread count from UPCR config
  if ($upcrlib_ctuple =~ /,dynamicthreads$/) {
    $compiled_threads = 0;
  } elsif ($upcrlib_ctuple =~ /,staticthreads=([0-9]+)$/) {
    $compiled_threads = $1;
  } else {
    die "'$exename' is missing thread information\n";
  }

  # get shmem model from UPCR config
  if ($upcrlib_ctuple =~ m:SHMEM=([A-Za-z0-9/_-]+):) {
    $shmem_model = lc($1);
    if ($shmem_model eq 'none') {
       $default_th_per_proc = 1;
    } elsif ($shmem_model =~ m/pthreads/) {
       $default_th_per_proc = pthreadsPerProc();
    } elsif ($shmem_model eq 'pshm') {
       $default_th_per_proc = 1;
    } else {
      die "'$exename' has unknown shmem model '$shmem_model'\n";
    }
  } else {
    die "'$exename' is missing shmem model information\n";
  }

  if ($gasnetlib_ctuple =~ /CONDUIT=([A-Za-z0-9]+)/) {
    $conduit = lc($1);
  } else {
    die "'$exename' is missing network conduit information\n";
  }

  $gasnet_trace = ($gasnetlib_ctuple =~ ",trace");
  $gasnet_stats = ($gasnetlib_ctuple =~ ",stats");
  $gasnet_debug = ($gasnetlib_ctuple =~ ",debug");

  @compilelines = ();
  for my $line (values %{$$upcrexe_miscinfo{UPCCompileLine}}) {
    if ($line ne $$upcrexe_miscinfo{UPCCompileLine}{'<link>'}) {
      push @compilelines, $line;
    }
  }
  push @compilelines, $$upcrexe_miscinfo{UPCCompileLine}{'<link>'};

  # If we can get tbss/tdata info, then use it.
  # XXX: This is pretty crude; not bothering to determine whether
  # we are running on a system where TLS counts against the pthread
  # stack allocation.  At the moment, the theory is that asking for
  # too large a stack is "mostly harmless" as it is just virtual
  # memory (probably not a good assumption on a 32-bit system).
  my $tls_size = 0;
  if ($conf{size_cmd} && open(SIZE_CMD, "$conf{size_cmd} $exename|")) {
    while (<SIZE_CMD>) {
      if (m/^\.t(data|bss)\s+([0-9]+)/) { $tls_size += $2; }
    }
    close SIZE_CMD;
    # ignore for some definition of "small"
    if ($tls_size < 4096) { $tls_size = 0; }
  }
  # Preserve and propogate user's setting, if any:
  if ($ENV{'GASNET_THREAD_STACK_PAD'} || $tls_size) {
    pushVar('GASNET_THREAD_STACK_PAD',
            ($ENV{'GASNET_THREAD_STACK_PAD'} || $tls_size));
  }
  if ($ENV{'UPC_STACK_PAD'} || $tls_size) {
    pushVar('UPC_STACK_PAD',
            ($ENV{'UPC_STACK_PAD'} || $tls_size));
  }
}

# read info about static shared data from the executable
sub get_static_sharedsz() {
    my $shared_fixedsz = 0;
    my $shared_perthreadsz = 0;
    my $shared_threadzerosz = 0;
    foreach my $varname (keys %{$$upcrexe_miscinfo{UPCRStaticSharedData}}) {
	if ($$upcrexe_miscinfo{UPCRStaticSharedData}{$varname} =~ /([0-9]+) ([0-9]+) ([0-9]+)/) {
	    my ($blockbytes, $numblocks, $mult_by_threads) = ( $1, $2, $3 );
	    if ($mult_by_threads) {
		$shared_perthreadsz += ($numblocks * $blockbytes);
		$shared_threadzerosz += ($numblocks * $blockbytes);
	    } else {
		$shared_fixedsz += ($numblocks * $blockbytes);
		if ($compiled_threads > 0) {
		  $shared_threadzerosz += (int(($numblocks+$compiled_threads-1)/$compiled_threads) * $blockbytes);
		} else { # numblocks should be 1
		  $shared_threadzerosz += ($numblocks * $blockbytes);
		}
	    } 
	}
    }
    return ($shared_fixedsz, $shared_perthreadsz, $shared_threadzerosz);
}
# format static shared data size info
sub get_static_sharedstr() {
    my ($shared_fixedsz, $shared_perthreadsz, $shared_threadzerosz) = get_static_sharedsz();
    my $shared_size_str = "";
    $shared_size_str .= size_str($shared_fixedsz) if ($shared_fixedsz > 0);
    if ($shared_perthreadsz > 0) {
       $shared_size_str .= " + " if (length $shared_size_str);
       $shared_size_str .= "( THREADS * " . size_str($shared_perthreadsz) . " )";
    }
    if ($shared_threadzerosz > 0) {
       $shared_size_str .= " total, " if (length $shared_size_str);
       $shared_size_str .= size_str($shared_threadzerosz) . " on thread 0";
    }
    $shared_size_str = "0 bytes" if (!length $shared_size_str);
    return $shared_size_str;
}

sub uniquify {
    my @in = @_;
    my %saw;
    return grep(!$saw{$_}++, @in);
}

################################################################################
## Print info about the executable
################################################################################
sub print_info 
{
    my $threadstr = ($compiled_threads ?
                     "$compiled_threads static thread".($compiled_threads>1?"s":"") :
                     "dynamic threads");
    if (isPthreads()) {
	$threadstr .= ", -pthreads=$$upcrexe_miscinfo{DefaultPthreadCount}{'<link>'}";
    }
    my $tracestr = ($gasnet_trace?"enabled":"disabled");
    my $statsstr = ($gasnet_stats?"enabled":"disabled");
    my $debugstr = ($gasnet_debug?"enabled":"disabled");
    my $upcver = $$upcrexe_miscinfo{UPCVersion}{'<link>'};
    my $ABI = $$upcrexe_miscinfo{UPCRBinaryInterface};
    my $trans = join(', ', uniquify(values %{$$upcrexe_miscinfo{UPCTranslator}})); 
    my $shared_size_str = get_static_sharedstr();
    my $maxstr = "";
    $maxstr = "    (Max: ".$$upcrexe_sizes{UPC_SHARED_HEAP_SIZE_MAX}." / node)" if ($$upcrexe_sizes{UPC_SHARED_HEAP_SIZE_MAX});
    $upcrlib_ctuple =~ m/SHAREDPTRREP=([^,]*)/;
    my $sptr_rep_str = $1;
    my $misc_data;
    my $transver = join(', ', uniquify(values %{$$upcrexe_miscinfo{UPCTranslatorVersion}}));
    my $trans_buildtime = undef;
    if ($transver) {
      if ($transver =~ m/(built on .*)$/) {
         $trans_buildtime = $1;
	 $transver =~ s/\s*,?\s*built on .*$//;
      }
      $transver = "Berkeley UPC Translator v. $transver";
    }
format MISC_FORMAT =
     ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
     $misc_data
~~     ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
       $misc_data
.
    $~ = "MISC_FORMAT";  # select format
    $: = " \n,";            # only break on whitespace or commas, not '-'

    print STDOUT <<EOF; 
Information about '$exename':
  Compilation environment: $threadstr
  Architecture: $ABI
  Network: ${conduit}-conduit

  Default shared heap size:   $$upcrexe_sizes{UPC_SHARED_HEAP_SIZE} / thread$maxstr
  Minimum shared heap offset: $$upcrexe_sizes{UPC_SHARED_HEAP_OFFSET}
  Static shared data size:    $shared_size_str
  Pointer-to-shared rep:      $sptr_rep_str

  Debug mode:       $debugstr
  Comm. Statistics: $statsstr
  Comm. Tracing:    $tracestr

  Translator: $transver
EOF
$misc_data = $trans; write;
if ($trans_buildtime) {
  $misc_data = "timestamp: $trans_buildtime"; write;
}

print "  Compile line(s):\n";
for my $k (keys %{$$upcrexe_miscinfo{UPCCompileLine}}) {
  if ($k ne '<link>' && 
      $$upcrexe_miscinfo{UPCCompileLine}{$k} ne $$upcrexe_miscinfo{UPCCompileLine}{'<link>'}) {
    $misc_data = $$upcrexe_miscinfo{UPCCompileLine}{$k}.
           "  (".$$upcrexe_miscinfo{UPCCompileTime}{$k}.")";
    write;
  }
}
$misc_data = $$upcrexe_miscinfo{UPCCompileLine}{'<link>'}.
       "  (".$$upcrexe_miscinfo{UPCCompileTime}{'<link>'}.")";
write;

print "  Backend compiler: ".upcc_decode(join(', ',uniquify(values %{$$upcrexe_miscinfo{UPCRBackendCompiler}})))."\n";
if (defined $$upcrexe_miscinfo{GASNetCompilerID}) {
  $misc_data = $$upcrexe_miscinfo{GASNetCompilerID}; write;
}
print "  Backend linker:   ".upcc_decode($$upcrexe_miscinfo{UPCRBackendLinker})."\n";
print "  UPC Runtime Configuration: Berkeley UPCR v. $upcver\n";
$misc_data = "ctuple:    ".$upcrlib_ctuple; write;
$misc_data = "confid:    ".$$upcrexe_miscinfo{UPCRConfigureId}; write;
$misc_data = "confargs:  ".$$upcrexe_miscinfo{UPCRConfigureArgs}; write;
$misc_data = "features:  ".$$upcrexe_miscinfo{UPCRConfigureFeatures}; write;
$misc_data = "timestamp: ".$$upcrexe_miscinfo{UPCRBuildTimestamp}; write;
print "  GASNet Configuration:\n";
$misc_data = $gasnetlib_ctuple; write;

}

################################################################################
### Find site config file, and read in settings
################################################################################
sub readconfig {
    my $upcrun_conf = "$upcr_etc/upcrun.conf";
    # parse main upcrun.conf file
    parseconfig($upcrun_conf, 1, \%conf);
    
    # Users may also put prefs in a ~/.upcrunrc file 
    unless ($opt_norc) {
        if (defined $opt_upcrunrc) {
            parseconfig($opt_upcrunrc, 1, \%conf);
        } else {
            parseconfig(userhome() . '/.upcrunrc', 0, \%conf);
        }
    }

    # check to see all variables without default values have been set 
    for my $key (keys(%conf)) {
        if ($conf{$key} eq 'nodefault') {
            die "Setting for '$key' missing from config file '$upcrun_conf' for '$key'\n";
        }
    }
}

################################################################################
## Run an external command
################################################################################
sub runCmd {
    my @cmd = @_;

    verbose("*** upcrun running: '" . join(' ', @cmd) . "'");
    if ($opt_showonly) {
	exit(0);
    }

    # Using exec(@list) to avoid an intermediate shell.
    exec(@cmd);
    die "exec failed: $!\n";
}

################################################################################
## Push an environment variable we need to set for executable
################################################################################
sub pushVar {
    my ($var,$val,$keep) = @_;
	if (defined $keep && exists $ENV{$var}) {
      $val = $ENV{$var};
      verbose("*** upcrun keeping: $var='$val'");
	} elsif (defined $val) {
	verbose("*** upcrun setting: $var='$val'");
    } else {
	verbose("*** upcrun unsetting: $var");
    }
    $envvars{$var} = $val;
}

################################################################################
## Quote a string to make it shell-friendly
################################################################################
sub shquote 
{
   my ($str) = @_;
   if ($str =~ / /) {
     $str = "\'$str\'";
   }
   return "$str";
}

################################################################################
## Figure out how to run the spawner, and then do it.
################################################################################
sub runDriver
{
    # Determine number of nodes to use (or to let spawner choose)
    my ($numnodes, $cpus_per_node) = ($opt_numnodes, $opt_cpus_per_node);
    if ($cpus_per_node && $numnodes) {
	# Both set explicitly to non-zero and thus must agree
	die "The -nodes and -cpus-per-node flags disagree\n"
	    unless ($numnodes == int(($opt_numthreads + $cpus_per_node - 1) / $cpus_per_node));
    } elsif ($numnodes) {
	# we use the user's -nodes setting and compute cpus-per-node
	$cpus_per_node = int(($opt_numthreads + $numnodes - 1) / $numnodes);
    } else {
	# Use the user's -cpus-per-node setting or default_cpus_per_node if either is given
	$cpus_per_node ||= $conf{default_cpus_per_node};
	if ($cpus_per_node == 0) {
	    # We are left trusting the spawner
	    $cpus_per_node = $opt_th_per_proc;	# simplifies PTHREAD_MAP logic below
	} else {
	    $numnodes = int(($opt_numthreads + $cpus_per_node - 1) / $cpus_per_node);
	    $cpus_per_node = int(($opt_numthreads + $numnodes - 1) / $numnodes);
	}
    }
    die "The given settings require $numnodes nodes, which is not possible with network=smp\n"
	if (($conduit eq 'smp') && ($numnodes > 1)); # 0 and 1 are both OK

    #simplify further math
    $cpus_per_node = min($cpus_per_node, $opt_numthreads);
    $opt_th_per_proc = min($opt_th_per_proc, $cpus_per_node);

    # Determine number of processes needed
    # Currently handle cases where $opt_numthreads fails to devide evenly by
    # just truncating the final proc's count ("blocked" layout).
    # We are also assuming block layout of processes by the spawner!!
    my $numproc = 0;
    my $max_th_per_proc = 0;
    if (!isPthreads()) {
	# No pthreads -> easy case
        $numproc = $opt_numthreads;
    } elsif (defined(my $pthread_map = $ENV{'UPC_PTHREADS_MAP'})) {
	# User gave an explicit map, validate it
	# XXX No check for cpu overcommit
	my $sum = 0;
        for my $x (split " ", $pthread_map) {
            die "Value '$x' in UPC_PTHREADS_MAP is not a valid thread count.\n"
		unless ($x =~ /^[1-9][0-9]*$/);
            $sum += $x;
            $max_th_per_proc = max($max_th_per_proc, $x);
            $numproc++;
        }
        die "UPC_PTHREADS_MAP does not match the number of UPC threads ($opt_numthreads).\n"
	    unless ($sum == $opt_numthreads);
    } elsif (!($opt_numthreads % $opt_th_per_proc) && !($cpus_per_node % $opt_th_per_proc)) {
	# Things layout uniformly
        $numproc = int($opt_numthreads / $opt_th_per_proc);
	pushVar('UPC_PTHREADS_PER_PROC', $opt_th_per_proc);
        $max_th_per_proc = $opt_th_per_proc;
    } else {
	# $opt_th_per_proc fails to evenly divide one or both of $opt_numthreads or $cpus_per_node
	# Start building a UPC_PTHREADS_MAP assuming blocked layout of procs->nodes.
	my $map = "";
	my ($full_nodes, $part_nodes);

	if ($numnodes > 1) {
	    $full_nodes = ($opt_numthreads - $numnodes * int($opt_numthreads / $numnodes)) || $numnodes;
	    $part_nodes = $numnodes - $full_nodes;
	} elsif ($numnodes) {
	    ($full_nodes, $part_nodes) = (1,0);
	} else {
	    $full_nodes = int($opt_numthreads / $opt_th_per_proc);
	    $part_nodes = 1;
	}

	# Layout nodes that have full thread count
        {
	    my $threads = $cpus_per_node;
	    my $quotient = int($threads / $opt_th_per_proc);
	    my $remainder = $threads - ($quotient * $opt_th_per_proc);
	    my $is_remainder = $remainder ? 1 : 0;

	    $map .= ((" $opt_th_per_proc" x $quotient) . (" $remainder" x $is_remainder)) x $full_nodes;
	    $numproc += $full_nodes * ($quotient + $is_remainder);
	}

	# Layout nodes that have less than full thread count
        if ($part_nodes) {
	    my $threads = ($opt_numthreads - $full_nodes * $cpus_per_node) / $part_nodes;
	    my $quotient = int($threads / $opt_th_per_proc);
	    my $remainder = $threads - ($quotient * $opt_th_per_proc);
	    my $is_remainder = $remainder ? 1 : 0;

	    $map .= ((" $opt_th_per_proc" x $quotient) . (" $remainder" x $is_remainder)) x $part_nodes;
	    $numproc += $part_nodes * ($quotient + $is_remainder);
	}

	# Trim whitespace
	$map =~ s/^ //;
	
        pushVar('UPC_PTHREADS_MAP', $map);
        $max_th_per_proc = $opt_th_per_proc;
    }

    # This is harmless if unused
    if ($max_th_per_proc && grep($_ eq $conduit, qw(aries gemini)) && !exists $ENV{'GASNET_DOMAIN_COUNT'}) {
      my $pthreads_per_domain = $ENV{'GASNET_GNI_PTHREADS_PER_DOMAIN'} || 1;
      my $domains = ($max_th_per_proc + $pthreads_per_domain - 1) / $pthreads_per_domain;
      pushVar('GASNET_DOMAIN_COUNT', $domains);
    }

    if ($numnodes > $numproc) {
	print "upcrun: WARNING: Requested $numnodes nodes for only $numproc processes - reducing nodes to $numproc.\n"
	    unless ($opt_quiet);
	$numnodes = $numproc;
    }

    # Chose the appropriate spawner
    my ($spawncmd, $cmdsource);
    if ($numnodes) {
	$cmdsource = "${conduit}_spawn_nodes";
	$spawncmd = $conf{$cmdsource};
	my $tmp = "UPC_" . uc($conduit) . "_SPAWN_NODESCMD";
	($spawncmd, $cmdsource) = ($ENV{$tmp}, $tmp) if ($ENV{$tmp});
	
	if (!$spawncmd && !$opt_quiet) {
	    print "upcrun: WARNING: Given options request $numnodes nodes for $numproc processes, \n";
	    print "upcrun: WARNING: but there is no setting for '${conduit}_spawn_nodes'.\n";
	    print "upcrun: WARNING: Will use setting for '${conduit}_spawn' instead.\n";
	    print "upcrun: WARNING: THREAD LAYOUT MIGHT NOT MATCH YOUR REQUEST.\n";
	}
    } 
    if (!$spawncmd) {
	$cmdsource = "${conduit}_spawn";
	$spawncmd = $conf{$cmdsource};
	my $tmp = "UPC_" . uc($conduit) . "_SPAWNCMD";
	($spawncmd, $cmdsource) = ($ENV{$tmp}, $tmp) if ($ENV{$tmp});
    }

    if ($conduit eq 'udp') { # bug 1213 - special case handling for udp nodes
      if ($numnodes && $numproc > $numnodes) { # duplicate node names as needed
        my $ppn = int($numproc / $numnodes);
	my $full = $numproc - $numnodes * $ppn;  # nodes carrying ($ppn + 1) procs
	my $part = $numnodes - $full;       # nodes carrying $ppn procs
	my @oldnodes = split(/ /,$UPC_NODES);
	my @tmp;
        for (my $i = 0; $i < $full; ++$i) {
          my $elem = shift @oldnodes;
          for (my $j = 0; $j <= $ppn; ++$j) { push @tmp, $elem; }
        }
        for (my $i = 0; $i < $part; ++$i) {
          my $elem = shift @oldnodes;
          for (my $j = 0; $j < $ppn; ++$j) { push @tmp, $elem; }
        }

	$UPC_NODES = join(',',@tmp);
        pushVar('UPC_NODES', $UPC_NODES);
      }
    }

    # use UPC_NODES to set other nodelist variables we might need
    pushVar('GASNET_SSH_SERVERS', $UPC_NODES)
       if (!$ENV{GASNET_SSH_SERVERS} && !$ENV{AMUDP_SSH_SERVERS} && !$ENV{SSH_SERVERS});

    # smp-conduit needs a little help (safer than 'env GASNET_PSHM_NODES=%N' in spawner)
    pushVar("GASNET_PSHM_NODES", $numproc)
       if (($conduit eq 'smp') && ($shmem_model =~ m/pshm/));

    pushVar('UPC_BIND_THREADS', 1)
       if ($opt_bind_threads);

    # Add/remove necessary strings in the environment
    while (my ($var, $val) = (each %envvars)) {
      if (defined($val)) {
	$ENV{$var} = $val;
      } else {
	delete $ENV{$var};
      }
    }

    # Form an array of names of UPC_ environment vars, ensure it is non-empty
    my $envlist = join(',', (grep {m/^UPC_/} (keys %ENV)));

    # UPC_ENVPREFIX may be set to a comma-delimited list of environment variable name prefixes
    # for any prefix in $UPC_ENVPREFIX, ensure all currently-set env vars matching ^$prefix 
    # are propagated to all compute nodes (where prefix may contain perl regexs)
    my $magicprefixflag = 'UPC_ENVPREFIX';
    if (defined $ENV{$magicprefixflag}) {
        my @pats = split(/[, :]/,$ENV{$magicprefixflag});
	foreach my $pat (@pats) {
          foreach (keys %ENV) {
            if (m/^$pat/) {
	        $envlist .= "," if ($envlist);
                $envlist .= $_;
            }
	  }
        }
    }
    $envlist = $envlist || 'UPCRI_NON_EMPTY_KLUDGE'; # ensure envlist is non-empty
    #print "env list is $envlist\n";

    # perform encoding (NOTE: too late to use pushVar here)
    if ($opt_encode_env) {
      my @vars = split(/,/,$envlist);
      push(@vars, grep {m/^GASNET_/} (keys %ENV));
      for my $varname (@vars) {
        if (defined (my $val = $ENV{$varname})) {
	  my $encval = gasnet_encode($val);
	  $ENV{$varname} = $encval if ($encval ne $val);
	}
      }
      $ENV{'GASNET_DISABLE_ENVDECODE'} = 0 if (defined $ENV{'GASNET_DISABLE_ENVDECODE'});
    }
    if ($opt_encode_args) {
      map { $_ = gasnet_encode($_); } @exeargs;
      $ENV{'GASNET_DISABLE_ARGDECODE'} = 0 if (defined $ENV{'GASNET_DISABLE_ARGDECODE'});
    }

    # Escape '%' in the potential substitution variables.
    # This makes subsequent processing easier than "%%" would.
    $spawn_exename =~ s/%/%@/g;
    $envlist =~ s/%/%@/g;
    (my $tmp_cwd = $cwd) =~ s/%/%@/g;

    # Massage the spawncmd slightly to aid parsing
    $spawncmd =~ s/%%/%@/g;		# Externally we use "%%"
    $spawncmd =~ s/%[Cc]/%P %A/g;	# Supported alias

    # Ensure *something* for %M
    # XXX prohibit when not using <conduit>_spawn_nodes ??
    $numnodes = 1 unless $numnodes;
    
    # Provide something for %R (ppn)
    # XXX prohibit when not using <conduit>_spawn_nodes ??
    my $ppn = int( ($numproc + $numnodes - 1) / $numnodes );
    
    # Replace %[ADLNPQV@] in $spawncmd while parsing it into a list and
    # passing @exeargs without any modification.
    # At the end we generate one or more list elemets to go in @spawncmd.
    # If the current word is exactly "%A" we splice in the entire @exeargs.
    # (Remember that map creates an array made up of the last expression
    # evaluated in each iteration of the block.)
    # XXX: Only allows "%A" alone
    my @spawncmd = map {  if (m/^%[Aa]$/) {
			    @exeargs;	# No further processing
	                  } elsif (m/^%[Qq]$/) {
			    map { "'$_'" } @exeargs;	# No further processing
	                  } elsif (m/^%[Vv]$/) {
			    ($opt_verboseexpansion?"-v":undef);
			  } else {
			    while ($in_build_tree && m,(\$\(UPCR_HOME\)/bin/(\S+)\b),) {
			      # We must be running uninstalled.  Find the spawner.
			      my $match = $1;
			      my @dirs = (
				"$conf{top_builddir}/gasnet/other/amudp",
				"$conf{top_builddir}/gasnet/${conduit}-conduit/contrib",
				"$conf{top_srcdir}/gasnet/${conduit}-conduit/contrib",
				"$conf{top_builddir}/gasnet/${conduit}-conduit",
				"$conf{top_srcdir}/gasnet/${conduit}-conduit",
				"$conf{top_builddir}/gasnet/mpi-conduit/contrib",
				"$conf{top_srcdir}/gasnet/mpi-conduit/contrib");
			      my $file = $2;
			      my $path;

			      while ($path = (shift @dirs)) {
				last if (-f "${path}/${file}");
			      }
			      die "Unable to locate spawner '$file'" unless ($path);
			      s,\Q${match},${path}/${file},g;
			    }
			    s/\$\(UPCR_HOME\)/$upcr_home/g;
			    s/%[Dd]/$tmp_cwd/g; 
			    s/%[Nn]/$numproc/g; 
			    s/%[Mm]/$numnodes/g;
			    s/%[Pp]/$spawn_exename/g; 
			    s/%[Rr]/$ppn/g; 
			    s/%[Ll]/$envlist/g; 
			    s/%[Tt]/$opt_th_per_proc/g; 
			    s/%[@]/%/g;	# % last
			    $_;
			  }
	               } split_quoted($spawncmd,"while parsing $cmdsource");
  
    # delete any empty arguments introduced by %V expanding to nothing
    @spawncmd = grep(defined, @spawncmd); 

    runCmd(@spawncmd); 
}

################################################################################
## Any required cleanup
################################################################################
sub clean_up 
{
}
