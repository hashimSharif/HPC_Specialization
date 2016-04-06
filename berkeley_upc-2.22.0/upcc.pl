#!/usr/bin/env perl

################################################################################
################################################################################
##  'upcc'  driver script for the Berkeley UPC compiler 
################################################################################
################################################################################


require 5.005;
use strict;
#use Getopt::Long;   # We now 'require' our own version, to avoid old buggy ones
use File::Basename;
use Socket;          # for HTTP-based remote translation
use Cwd;

################################################################################
# "Global" variables 
#  -----------------
# (actually, they're file-scoped lexicals, kind of like "static" in C)
################################################################################

# enable debug messages (for debugging this script)
my $debug_on = 0;

# All the network APIs we support
my (@all_networks) = qw/mpi udp smp ibv shmem portals4 gemini aries pami ofi mxm/;

# Configuration parameters.
#   Each config file variable must be set here, either to its default value, or
#   to 'nodefault' if there is no default value.  Adding a variables not in this
#   list to the config file will result in a (helpful) error message.  So will
#   failure to provide a value for variables with no default value.
my %conf = (
    arch_size               => '32',
    conduits                => 'nodefault',
    upcc_version            => 'nodefault',
    runtime_spec            => 'nodefault',
    upc_spec                => 'nodefault',
    configure_args	    => 'nodefault',
    configure_id	    => 'nodefault',
    configure_system	    => 'nodefault',
    configure_tuple	    => 'nodefault',
    configure_features	    => 'nodefault',
    nm                      => '', # optional program
    dig                     => '', # optional program
    nslookup                => '', # optional program
    exe_suffix              => 'nodefault',
    gmake                   => 'nodefault',
    gzip                    => 'gzip',
    tar                     => 'tar',
    ssh                     => 'ssh',
    strip                   => 'strip',
    SIGINT                  => 'nodefault',
    SIGTERM                 => 'nodefault',
    SIGKILL                 => 'nodefault',
    remote_tmpdir           => '/tmp',
    default_network         => 'nodefault',
    heap_offset             => 'nodefault',
    shared_heap             => 'nodefault',
    shared_heap_max         => '', # default to configure flag
    pshm_support            => 'nodefault',
    pthreads_support        => 'nodefault',
    default_pthreads        => 'nodefault',
    translator              => 'nodefault',
    http_retry              => '2',
    http_proxy              => '',
    top_srcdir              => 'nodefault',
    top_prefix              => 'nodefault',
    totalview_supported     => 'no',
    totalview_libs          => '',
    using_gccupc            => 'no',
    using_cupc              => 'no',
    using_cupc2c            => 'no',
    clang_pts_opts          => '',
    clang_upc               => 'no',
    redef_gnuc              => '',
    gccupc_tls              => 'no',
    gccupc_version          => 'nodefault',
    cupc_version            => 'nodefault',
    smart_output            => 'no',
    default_options         => '',
    inst_supported          => 'no',
    thrille_supported       => 'no',
    thrille_dir             => '',
    profile_flags           => '',
    warning_blacklist       => '',
    extra_cflags            => '',
    extra_ldflags           => '',
    mpi_incompatible        => 'nodefault',
    system_header_dirs      => '/usr/include',
    conf_name               => 'nodefault',
    perl                    => '/usr/bin/perl'
);
foreach (@all_networks) {
    $conf{$_."_options"} = '';
}

# if skipping $HOME/.upccrc or specifying an alternate
my ($opt_norc, $opt_upccrc);

# control certain default behaviors based on build configuration
my ($dbg_build, $opt_build);

# directories
my ($startdir, $upcr_home, $upcr_bin, $upcr_etc, $upcr_lib,
    $upcr_include, $upcr_include_src, $prefix);
my $TMPDIR = (-d $ENV{TMPDIR} ? "$ENV{TMPDIR}" : '/tmp');
my ($tmp, $rtmp_req, $rtmp_rep); # temp directory and remote req/teply tmp dirs
my ($saveall_dir, $pthread_linkdir); # for -save-all-temps, and pthread linking
# files or URIs
my ($trans, $proxy);
my ($conftrans);                # saved full spec of translator for --version
# installed?
my ($in_build_tree);

# Command-line switches
my ( 
    $opt_ssh_remote,   # 'nettrans_ssh' hack
    $opt_http_remote,  # 'nettrans_http' hack
    $opt_http_compress,
    $opt_arch_size,    #  overrides config file setting: for HTTP compile
    $opt_compileonly,
    $opt_debug,
    @opt_defines,
    $opt_echo_var,
    $opt_extern_main,  # if main() outside UPC code
    $opt_help,
    @opt_includes,
    $opt_lines,
    $opt_nightly,
    $opt_link_cache,
    $opt_checks,
    $opt_outputname,
    $opt_optimize,
    $opt_pow2_symptr,
    $opt_preprocessonly,
    $opt_profile,
    $opt_inst,
    $opt_inst_local,
    $opt_inst_functions,
    $opt_inst_toolname,
    $opt_thrille,
    $opt_thrille_local,
    $opt_pthreads,
    $opt_heap_offset,
    $opt_print_include,
    $opt_print_mpicc,
    $opt_require_size,
    $opt_shared_heap,
    $opt_shared_heap_max,
    $opt_save_temps,
    $opt_save_all_temps,
    $opt_size_warn,
    $opt_sizes_file,         # use specified sizes file: for HTTP compile
    $opt_show_sizes,
    $opt_print_translator,
    $opt_smart_output,
    $opt_stable,
    $opt_strip,
    $opt_threadcount,
    $opt_totalview,         # compile for totalview
    $opt_trace,
    $opt_translator,
    $opt_http_proxy,
    $opt_translateonly,
    $opt_transopt,          # TEMPORARY: force translator to use optimizations
    $opt_ansi_alias,        # turn on C99 type-based aliasing rule 
    $opt_uses_threads,
    $opt_uses_mpi,
    $opt_user_ld,
    $opt_versiononly,
    $opt_verbose,
    $opt_yesterday,
    $opt_allow_deprecated,
    @opt_opts,              # --opt-{en,dis}able
    @opt_CPP_args,          # Arbitrary arguments to the C preprocessor,
    @opt_UPC_args,          # the UPC-to-C front end, the whirl2C output 
    @opt_W2C_args,          # engine, the C compiler, and the linker, 
    @opt_CC_args,           # passed via the '-Wp,/-Wu,/-Ww,/-Wc,/-Wl,' 
    @opt_LD_args            # flags.
);
use vars qw/$opt_network/;  # needs to be true global so 'local' can override

# default values
$opt_link_cache=1;
$opt_checks=1;
$opt_size_warn = 1;
$opt_http_compress = 6; # the gzip default compression level

my ($shared_heap_size, $shared_heap_size_max, $shared_heap_offset);

# target executable name (if linking), and basename
my ($target, $targetbase);

# We parse ARGV into ARGVoodoo
my @ARGVoodoo;

# saves a copy of original argv
my @save_ARGV;

# Supporting which compiler or translator?
my ($gccupc);    # GNU UPC compiler
my ($cupc);      # Clang UPC compiler
my ($cupc2c);    # clang-upc2c UPC-to-C translator
my ($bupc);      # Berkeley UPC-to-C translator

# Name of supported compiler or translator
my ($whoami);

# array of precompiled regexes for filtering warnings
my @warning_blacklist = ();

# for remote translation via ssh/http
my ($use_nettrans_ssh, $nettrans_host, @nettrans_ssh_ARGV); 
my ($use_nettrans_http, $nettrans_http_port, $nettrans_http_path); 
my ($at_remote);

# Files to preprocess/translate/compile/link, and list of temp files to remove
my (@toPreprocess, @toTranslate, @toCompile, @toLink, @toRemove);
my (@toLinkUPC);      # files that are UPC objects
my (@toLinkPthreads); # pthreads: .o files that are really still source files

# map basename -> Source file name the user passed in,
# and basename -> original directory
my (%origPathName, %origDir);

# type sizes that we need to pass to the translator, and 
# file we store them in 
my (%translator_typesizes, $maxblocksz);
my $sizesfile = "upcc-sizes";
# stoopid Power alignment exceptions
my ($dbl_1st_struct_align,  $int64_1st_struct_align, $sharedptr_1st_struct_align, $psharedptr_1st_struct_align);
my ($dbl_inner_struct_align,  $int64_inner_struct_align, $sharedptr_inner_struct_align, $psharedptr_inner_struct_align);
my $struct_promote;

# extra flags for preprocessing/compilation
my $extra_cppflags;

# UPC-specific flags for preprocessing/compilation
my $upc_cppflags;

# Berkeley UPC and runtime spec versions
my ($version_major, $version_minor, $version_patchlevel);
my ($spec_major, $spec_minor);
my $buildtime;

# network APIs supported
my @conduits;

# 'ctuples': configuration tuples embedded into objects/libraries
# in order to enforce executables are consistently built 
my $upcrlib_ctuple;
my $gasnetlib_ctuple;

# utility incantations
my $gmake;
my $gmake_upcc;

# set to 'seq', 'par', 'thr', or 'tv', depending on use of pthreads
my $parseq;

# 32/64 bit architecture size
my $arch_size;

# if conduit+platform can support fast pow2 symmetric pointers
my $have_pow2_symptr;

my $host = `hostname`;
chomp($host);

main();


################################################################################
## Initialize and run 
################################################################################
sub main {
    # Wrap everything in an exception handler, both for uniform error
    # formatting, and so we can always clean up temporary files

    $startdir = getcwd();  

    eval {
        local $SIG{'INT'} = sub { die "compilation terminated by signal SIGINT" };
        local $SIG{'TERM'} = sub { die "compilation terminated by signal SIGTERM" };

        initialize();
        runDriver();
    };
    chdir($startdir) or die "Failed to chdir($startdir): $!";
    my $exception = $@;  # save in case clean_up() ever does an eval
    if ($opt_save_all_temps && $saveall_dir) {
        system("rm -rf \'$saveall_dir\' >/dev/null 2>/dev/null") if $saveall_dir;
        my $cmd = "cp -r \'$tmp\' \'$saveall_dir\'";
        system($cmd);
        $cmd = "/bin/sh -c \"cp -r \'$tmp\'/*.B \'$tmp\'/*.N \'$tmp\'/*.t \'$startdir\' >/dev/null 2>&1\"";
        system($cmd);
    }
    system("rm -rf \'$TMPDIR/$rtmp_req\' \'$TMPDIR/$rtmp_req.tar\'") if $rtmp_req;
    system("rm -rf \'$TMPDIR/$rtmp_rep\' \'$TMPDIR/$rtmp_rep.tar\'") if $rtmp_rep;

    clean_up();
    if ($exception) {
      $exception = ($exception =~ /error|warning/i ? 'upcc: ' : 'upcc: Error: ') . $exception;
      unless ($opt_verbose) { # suppress upcc line information 
        $exception =~ s/ at \S+\/upcc.pl line [0-9]+(?:, \S+ (?:line|chunk)? [0-9]+)?\./\./;
      }
      die $exception;
    }
    exit(0);
}

################################################################################


################################################################################
## Show program usage message, then exit
################################################################################
sub usage 
{
    my ($h2mhelp) = @_;
    my $network_str = join(", ",@all_networks);
    $network_str  =~ s/([^\n]{0,48})( |\b)/$1\n/g;  # break at space
    $network_str  =~ s/^/                        /gm; # indent
    $network_str  =~ s/\s+$//; # trim trailing w/s

    my $extra_help; # multiconf-related help options
    my $extra_help_file = $ENV{'UPCRI_EXTRA_HELP'};
    if ($extra_help_file && -f $extra_help_file) {
      my $sec_cnt = 0;
      open EHELP, "<$extra_help_file";
      while (<EHELP>) {
        last if (m/^\s*;\s*;\s*;\s*$/ && (++$sec_cnt == 2));
      }
      while (<EHELP>) { $extra_help .= $_; }
      close EHELP;
    }

    print <<EOF; 
Usage: upcc [options] foo.upc [ bar.c someobject.o ... ] 
EOF
    unless ($h2mhelp) {
        print <<EOF;
For detailed documentation, please see man upcc(1) or http://upc.lbl.gov/docs/
EOF
    }
    print <<EOF; 

Standard C compiler options:
   -c                 Compile source files, but do not link.
   -DFOO[=bar]        Define preprocessor symbol FOO [to optional value].
   -E                 Preprocess source files (output sent to stdout).
   -g                 Generate debug objects/executables 
   -I path            Add path to directories searched for header files.
   -lfoo              Link executable with libfoo.a.
   -Ldir              Add 'dir' to library search path.
   -O                 Generate optimized objects/executables
                      Does *not* enable experimental translator optimizations.
   -opt               Enable EXPERIMENTAL UPC translator optimizations
   -o name            Output file will be called 'name'.
   -pg                Generate OS-specific sequential performance profiling 
                      information in the executable (on supported platforms)
   -s                 Strip the symbolic information from the final executable.
   -UBAR              Undefine preprocessor symbol BAR.
$extra_help
UPC-related options:
   -network=<type>    Set network API use for communication.
                      Valid types include:
$network_str
                      Run 'upcc -version' to see which are available in this
                      installation, and which is the default.
   -shared-heap=NUM   Specify default amount (per UPC thread) of shared memory.
                      Defaults to megabytes: use '1GB' for 1 gigabyte.  Can
                      override at startup via the UPC_SHARED_HEAP_SIZE
                      environment variable. 
   -T=NUM             Generate code for a fixed number NUM of UPC threads 
                      This allows optimization of certain operations 
                      (such as pointer-to-shared arithmetic), especially 
                      when NUM is a power of 2. The disgusting syntax 
                      -f(upc-)threads-NUM is also accepted, for compatibility 
                      with other UPC compilers.

General options:
   -h -? -help        Print this message.
   -conf=FILE         Read FILE instead of \$HOME/.upccrc configuration file.
   -norc              Do not read \$HOME/.upccrc configuration file.  
                      This can also be achieved by setting the UPCC_NORC
                      environment variable.  Overrides -conf.
   -smart-output      Output file name will be auto-generated based on first 
                      .c/.upc/.o file on command line (ignored if -o passed).
   -V -version        Show version information.
   -v                 Verbose: display programs invoked by compiler.
   -vv                Extra verbose: pass verbose flag to programs invoked.

Advanced options:
   -allow-deprecated  Disable warnings for use of deprecated bupc_ functions.
   -[no]checks        Turn off build consistency checking.  Caveat nerdtor...
   -compress=NUM      Specify a gzip compression level for the HTTP netcompile
                      data stream, from 0 (off) to 9 (best). Higher values may
                      speed compilation over slow links, at an increase in CPU
                      cost.
   -echo-var VAR      Print value for VAR used by the internal upcc Makefile 
                      framework (for internal use only)
   -extern-main       Use if main() is declared in a non-UPC object or library.
   -[no]fast-symptr   Use fast symmetric pointers for power-of-two static 
                      threads.  (Available only for '-network=smp -pthreads' 
                      (or '-network=shmem' on the Cray X1).  If available, on 
                      by default if -T passed a power-of-two value.
   -opt-enable=OPT1[,OPT2]
   -opt-disable=OPT3[,OPT4]
                      Selectively enable/disable specified optimizations in the
                      BUPC UPC-to-C translator. See translator documentation
                      for the available optimizations.
   -shared-heap-max=NUM
                      Specify the hard limit (per UNIX process) of the 
                      shared memory heap. This constitutes an upper limit on
                      -shared-heap (although unlike -shared-heap this is a 
                      per-NODE setting, so under -pthreads, all UPC threads on 
                      a node share this space). Setting this value too high
                      can lead to long application startup times or memory 
                      exhaustion on some systems.
                      Defaults to megabytes: use '1GB' for 1 gigabyte.  Can
                      be overridden at startup via the GASNET_MAX_SEGSIZE
                      environment variable on *most* networks. 
   -heap-offset=num   Embed a default offset betwen the starting addresses of
                      the regular and shared heaps into executable.  Defaults
                      to megabytes: use '2GB' for 2 gigabytes.  Can override
                      at startup via the UPC_SHARED_HEAP_OFFSET environment
                      variable. 
   -http-proxy=URL    Set an HTTP proxy to use for HTTP netcompile, overriding
                      the http_proxy setting in the configuration file.
   -[no]lines         Insert line directives for original UPC code into
                      translated C code (if applicable).  On by default.
   -[no]link-cache    Disable the use of the pthread-link cache directory used 
                      to speed up linking of multi-file pthread applications.
   -link-with <PROG>  Use PROG to as the back-end linker.  Use to combine
                      UPC code with external C++ and/or MPI code.
   -nightly           Use nightly build of UPC-to-C translator at
                      http://upc-translator.lbl.gov/upcc-nightly.cgi
   -nopthreads        Alias for -pthreads=0.
   -print-include-dir Prints full path to directory in which <bupc_extern.h>
                      is located.
   -print-mpicc       Prints full pathname of an MPI compiler compatible with
                      this installation of upcc, or error if MPI not supported.
   -inst-local
   -inst-functions    Used internally by GASP performance tool wrapper scripts.
                      End-users should not normally need these options.
   -thrille=mode      Set mode for Thrille active testing, if supported.
   -thrille-local     Enable Thrille instrumentation of local accesses.
   -trace             Request that the compilation fail unless support for
                      the upc_trace utility is available.
   -pthreads[=N]      Generate a pthreaded UPC executable, and optionally set
                      the default number of pthreads per process (which can be
                      overridden at startup via the UPC_PTHREADS_PER_PROC or
                      UPC_PTHREADS_MAP environment variables).  A value of
                      N=0 disables creation of a pthreaded executable.
   -[no]require-size  Die at startup if amount of shared memory available is
                      less than requested: off by default. Can be overridden at 
                      startup by setting the UPC_REQUIRE_SHARED_SIZE 
                      environment variable to 'yes' or 'no'
   -[no]save-temps    Save 'interesting' temporary files (.i, .trans.c, .o) 
                      generated during translation/compilation.
   -[no]save-all-temps
                      Save all files used during translation/compilation.
                      Most are placed in a '{target}_temps' subdirectory.
   -show-sizes        Show the internally used platform sizes file
   -[no]size-warn     Warn at startup if amount of shared memory available is
                      less than requested: on by default. Can be overridden at
                      at startup by setting the UPC_SIZE_WARN environment 
                      variable to 'yes' or 'no'.
   -stable            Use latest 'stable' build of UPC-to-C translator at
                      http://upc-translator.lbl.gov/upcc-stable.cgi
   -trans             Stop after translating UPC to C (outputs 'foo.trans.c').
   -translator=<path> Use UPC-to-C translator at <path>, which is formatted
                      identically to the 'translator' conf-file option
   -tv                Compile an executable that can be debugged by TotalView:
                      Implies -g.  Not supported on all platforms.
   -uses-mpi          MPI interoperability support.  Pass at compile-time if a 
                      UPC file contains calls to MPI functions.  Pass at link
                      time if any objects (including libraries) use MPI.
   -W?,<option>       Pass an arbitrary option directly to a specific phase
                      (determined by the character replacing `?' as listed
                      below) when invoked by the compiler driver.
                      Use repeatedly to pass multiple options.  If you need to
                      use spaces, quote the option (ex: -Wp,"--option value").
		      Commas after the first DO NOT break the argument into
                      multiple options as with some other compilers.
       Supported phases:
        -Wp,<option>  Pass an arbitrary option to the UPC preprocessor.
        -Wu,<option>  Pass an arbitrary option to the first (or only) phase of
                      source-to-source translation.
        -Ww,<option>  Pass an arbitrary option to the second (or only) phase of
                      source-to-source translation.
        -Wc,<option>  Pass an arbitrary option to the compiler phase (the one
                      generating object code from either UPC source or from
                      translated C source).
        -Wl,<option>  Pass an arbitrary option to the linker.
                      NOTE: In most configurations the "linker" will be a C
                      compiler, not ld or its equivalent.  So, to truly pass
                      options to the system linker you need to get them past
                      the C compiler first.  For instance to pass "--foo bar"
                      to ld when gcc is the C compiler, you will need
                          -Wl,-Wl,--foo,bar
                      Conventions for passing linker arguments through other C
                      compilers will vary.
   -yesterday|-hier   Use yesterday's UPC-to-C translator at
                      http://upc-translator.lbl.gov/upcc-yesterday.cgi
EOF
    exit(0);
}

# Output format for --version info
my ($version_var, $version_value, $version_extra);
format VERSION_FORMAT = 
----------------------+---------------------------------------------------------
 @<<<<<<<<<<<<<<<<<<< | ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
$version_var,    $version_value
~~                    | ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                      $version_value
~~                    |   ^<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                      $version_extra
.

sub print_compiler_version_item 
{
    my ($label, $command) =@_;
 
    my $info = "$command"; 
    my $luser = $ENV{USER};
    my $tmpfile = "$TMPDIR/upcc-compilerver-$luser-$$.c";
    open (TMPDUMMY, ">$tmpfile"); 
    if (-f "$upcr_include_src/portable_platform.h") {
      print TMPDUMMY "#define PLATFORM_SHOW 1\n#include <$upcr_include_src/portable_platform.h>\n";
    } elsif (-f "$upcr_include_src/gasnet/other/portable_inttypes.h") {
      print TMPDUMMY "#define PLATFORM_SHOW 1\n#include <$upcr_include_src/gasnet/other/portable_platform.h>\n";
    } else {
      print TMPDUMMY "int main() { return 0; }\n";
    }
    close TMPDUMMY;
    my $prestr = `$command -E $tmpfile 2>&1`; 
    my $idstr = "";
    if ($prestr =~ m/^COMPILER_IDSTR *= *(.*)$/m) {
      my $val = $1;
      $val =~ s/\"\s+\"//g;
      $val =~ s/^\"//g;
      $val =~ s/\\?\"/$1/g;
      foreach my $keyw ("COMPILER_FAMILY", "COMPILER_VERSION", "misc") {
        if ($val =~ m/\|\s*$keyw\s*:([^\|]+)\|/) {
	  my $t = $1;
	  $t =~ s/^\s*//g; $t =~ s/\s*$//g;
	  $idstr .= "$t/";
        } 
      }
      $idstr =~ s%/*$%%;
    }
    # try to extract a version number from the backend compiler
    # following algorithm is carefully chosen to work across all known compiler version outputs
    # -qversion must come first for xlc
    # -V must precede -v for Intel C
    # pickup optional trailing line after version identifier for several compilers
    my $val = undef;
    my $maxlines = 5;
    foreach my $opt ("-qversion", "-V", "-v", "-V $tmpfile", "-v $tmpfile") {
      my $result = `$command $opt 2>&1`; 
      # recognize known-bad "try again" strings
      $result =~ s/^.*?-qversion.*?$//sg; # filter errors from non-xlc
      $result =~ s/^.*?option must have argument.*?$//g; # gcc
      $result =~ s/^.*?no input files.*?$//mg; # gcc
      foreach my $pat (
	'^(.*[vV]ersion[^-].*(\n.*)?)$', # most compilers
	'^(.*Rev.*(\n.*)?)$', # Compaq
	'^(.*[0-9]\.[0-9].*(\n.*)?)$' # catch-all
      ) {
        while ($result =~ /$pat/m && $maxlines-->0) { 
          $val .= "$1\r"; $result =~ s{\Q$1\E}{};
        } 
      }
      last if ($val);
    }
    $val =~ s/^usage:.*$//m; # Sun C
    $val =~ s/^.*undefined reference.*$//im; # icc
    $val =~ s/^.*in function.*_start.*$//im; # icc
    $val =~ s/^.*\/collect2.*crt1\.o.*$//m; # mpich ld
    $val =~ s/^\s+//;
    $val =~ s/[\s\n\r]+$//;
    unlink $tmpfile;
    $val = "$idstr\r$val" if ($idstr);
    
    print_version_item($label, $info, $val);
}

sub print_version_item
{
    my ($name, $val, $extra) =@_;
    
    $version_var = "$name";
    $version_value = "$val";
    $version_extra = "$extra";
    write;
}

sub labeled_version {
    my ($version) = @_;
    $version = "$version_major.$version_minor.$version_patchlevel" if (!$version);
    if ($version =~ m/^([^0-9]*)([0-9]+)\.([0-9]+)\.([0-9]+)(.*)$/) {
      my ($pre, $major, $minor, $patchlevel, $post) = ($1, $2, $3, $4, $5);
      if ($minor % 2) {
        if ($patchlevel % 2) {
            $version = "$pre$major.$minor.$patchlevel (UNSTABLE)$post" 
        } else {
            $version = "$pre$major.$minor.$patchlevel (STABLE)" 
        }
      }
    } 
    return $version;
}

sub print_version
{
    $~ = "VERSION_FORMAT";  # select format
    $: = " \n,";            # only break on whitespace or commas, not '-'

    my $version = labeled_version();

    print <<EOF;
This is upcc (the Berkeley Unified Parallel C compiler), v. $version
EOF
    if ($conftrans =~ /:/) {
      print "  (getting remote translator settings...)\n";
    }
    my ($trans_ver, $trans_spec) = get_translator_version();

#    print "--------------------------------------------------------------------------------\n";
#    print "Settings for this installation\n";

    print_version_item("UPC Runtime", 
                       "v. $version, $buildtime");
    print_version_item("UPC-to-C translator", $trans_ver);
    print_version_item("Translator location", $conftrans);
    print_version_item("networks supported", "@conduits");
    print_version_item("default network", $conf{default_network});
    if ($conf{pthreads_support} =~ /par/i ) {
        my $def_pt = $conf{default_pthreads};
        print_version_item("pthreads support", 
            "available (if used, default is $def_pt pthreads per process)");
    } else {
        print_version_item("pthreads support", "not available");
    }
    print_version_item("Configured with", "$conf{configure_args}");
    print_version_item("Configure features", "$conf{configure_features}");
    print_version_item("Configure id", "$conf{configure_system} $conf{configure_id}");
    print_version_item("Binary interface", "$conf{arch_size}-bit $conf{configure_tuple}");
    print_version_item("Runtime interface #", 
                        "Runtime supports $spec_major.0 -> $spec_major.$spec_minor: Translator uses $trans_spec");
    print_version_item("", " --- BACKEND SETTINGS (for $opt_network".($parseq eq "par"?"/pthreads":"")." network) ---");
    print_compiler_version_item("C compiler", get_make_value('UPCR_CC'));
    print_version_item("C compiler flags", get_make_value('GASNET_CFLAGS'));
    print_compiler_version_item("linker", get_make_value('UPCR_LD'));
    print_version_item("linker flags", 
        get_make_value('UPCR_LDFLAGS') . ' ' . get_make_value('UPCR_LIBS'));
    print "----------------------+---------------------------------------------------------\n";
}

# runs 'make' and returns value of arbitrary Make/environment variable,
# given current conduit/parseq/etc. settings
sub get_make_value
{
    my ($varname) = @_;

    my $cmd = $gmake_upcc
        . qq| echovar VARNAME=$varname|
        . qq| EXTRA_CPPFLAGS="$extra_cppflags" |
        . qq| UPCR_CONDUIT=$opt_network UPCR_PARSEQ=$parseq|;
    return runCmd($cmd, "error getting value of '$varname' from GASNet makefile", 
                  $tmp);
}

# gross way to get translator version: compile a dummy file, and parse it out
# from the trans.c file
sub get_translator_version 
{
    my ($trans_version, $trans_spec); 
    if ($gccupc) {
        ($trans_version, $trans_spec) = get_gccupc_compiler_version();
    } elsif ($cupc) {
        ($trans_version, $trans_spec) = get_cupc_compiler_version();
    } elsif ($cupc2c) {
        ($trans_version, $trans_spec) = get_cupc2c_compiler_version();
    } else {
        ($trans_version, $trans_spec) = get_berkeley_translator_version();
    }
    map { $_ = "<unable to determine>" unless defined $_ } ($trans_version, $trans_spec);
    return ($trans_version, $trans_spec); 
}

sub get_gccupc_compiler_version
{
    my $trans_version = undef;
    my $trans_spec = "(N/A)";
    my $gccupc_v = `/bin/sh -c "$trans --version 2>&1"`;
    if ($gccupc_v =~ /^x?g?(upc|gcc).*[ -](\d+\.\d+\.\d+[.-]\d+)/) {
        $trans_version = $2;
    }
    (my $trans_base = $trans) =~ s/ .*//; # drop any arguments
    if (my @stat = stat($trans_base)) {
        my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($stat[9]);
        my @mstr = ("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");
        $year += 1900;
        $trans_version .= ", built on ".$mstr[$mon]." $mday $year at ".
	                  sprintf("%02i:%02i:%02i",$hour,$min,$sec);
    }
    return ($trans_version, $trans_spec);
}

sub get_cupc_compiler_version
{
    my $trans_version = undef;
    my $trans_spec = "(unknown)"; # TODO: implement this
    my $cupc2c_v = `/bin/sh -c "$trans --version 2>/dev/null"`;
    if ($cupc2c_v =~ /^clang.*UPC (\d+([.-]\d+)+(\s+\d\d\d\d\d\d\d\d)?)/) {
        $trans_version = $1;
    }
    (my $trans_base = $trans) =~ s/ .*//; # drop any arguments
    if (my @stat = stat($trans_base)) {
        my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($stat[9]);
        my @mstr = ("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");
        $year += 1900;
        $trans_version .= ", built on ".$mstr[$mon]." $mday $year at ".
	                  sprintf("%02i:%02i:%02i",$hour,$min,$sec);
    }
    return ($trans_version, $trans_spec);
}

sub get_cupc2c_compiler_version
{
    my $trans_version = undef;
    my $trans_spec = "(unknown)"; # TODO: implement this
    my $cupc2c_v = `/bin/sh -c "$trans --version 2>/dev/null"`;
    if ($cupc2c_v =~ /^clang.*UPC (\d+([.-]\d+)+(\s+\d\d\d\d\d\d\d\d)?)/) {
        $trans_version = $1;
    }
    (my $trans_base = $trans) =~ s/ .*//; # drop any arguments
    if (my @stat = stat($trans_base)) {
        my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($stat[9]);
        my @mstr = ("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");
        $year += 1900;
        $trans_version .= ", built on ".$mstr[$mon]." $mday $year at ".
	                  sprintf("%02i:%02i:%02i",$hour,$min,$sec);
    }
    return ($trans_version, $trans_spec);
}

sub get_berkeley_translator_version 
{
    my ($trans_version, $trans_spec);
    my $tmpupc = "$tmp/version.upc";
    open (TMPUPC, ">$tmpupc") or die "Can't open '$tmpupc' for writing\n"; 
    print TMPUPC <<EOF;
/* This file exists just to get the UPC-to-C translator version number */
#include <upc.h>
int foo;
int main() { return 0; }
EOF
    close TMPUPC;
    $0 =~ /(.*)\.pl$/;
    my $myscript = $1;
    unless ($myscript =~ m@^/@) {
        $myscript = "$startdir/$myscript";
    }
    my (@no_version_ARGV) = grep { !/-version/ && !/-V/ } @save_ARGV;
    # trim other dangerous options
    @no_version_ARGV = grep { !/^--$/ } @no_version_ARGV; 
    if (grep { /^-echo-var/ } @no_version_ARGV) { # parse out problematic -echo-var option
      my @tmp; my $skip = 0;
      foreach my $arg (@no_version_ARGV) {
        if ($skip) { $skip = 0; }
        elsif ($arg =~ /^-echo-var=./) {}
        elsif ($arg =~ /^-echo-var/) { $skip = 1; }
        else { push @tmp, $arg; }
      }
      @no_version_ARGV = @tmp;
    }
    @no_version_ARGV = grep { !/^-print-/ } @no_version_ARGV; 
    foreach my $file (@ARGVoodoo) { # strip any user files that may cause spurious errors
      @no_version_ARGV = grep { !/^$file$/ } @no_version_ARGV;
    }
    map(s|[^\w!%+,./:=@^-]|\\$&|g, @no_version_ARGV); # escape whitespace and metachars
    eval { 
	my $perl = verify_exec($conf{perl}, $conf{exe_suffix});
        runCmd("$perl \'$myscript\' @no_version_ARGV -trans -save-temps $tmpupc", 
               "compiling file for version number", $tmp);
    };
    unless ($@) {
        my $transupc = "$tmp/version.trans.c"; 
        open (TRANSUPC, $transupc) or die "Can't open '$transupc' for reading\n"; 
        while (<TRANSUPC>) {
            if (/UPC Runtime specification expected:\s*(\d+\.\d+)/) {
                $trans_spec = $1;
            }
            if (/UPC translator version:\s*(.*?)\s*\*\//) {
                $trans_version = $1;
                if ($trans_version =~ m/release\s+(\d+)\.(\d+)\.(\d+)(.*)$/) {
                    my $rest = $4;
                    $trans_version = labeled_version("v. $1.$2.$3");
                    $rest =~ s/, (host|\w+cc) /\r$1 /g;
                    # Trailing spaces work-around perl bug prior to 5.8.4
                    $trans_version .= $rest . (' ' x 80);
                } else {
                    die "invalid version from translator: '$trans_version'";
                }
            }
            last if defined $trans_version && defined $trans_spec;
        }
        close TRANSUPC;
    }
    map { $_ = "<unable to determine>" unless defined $_ } ($trans_version, $trans_spec);
    return ($trans_version, $trans_spec); 
}

# Get mpi compiler used by MPI conduit 
sub get_mpicc {
    unless (grep /mpi/, @conduits) {
        die "This upcc was not configured with MPI support\n";
    }
    local $opt_network = 'mpi';
    return get_make_value("UPCR_LD");
}

# Return true if power of two
sub is_powerof2 {
    my $num = shift;
    return !($num & ($num-1));
}

################################################################################
## Speak if asked to
################################################################################
sub verbose 
{
    print "@_\n" if $opt_verbose || $debug_on;
}

sub stagemsg 
{
    my ($msg) = @_;

    verbose('-' x 80 . "\n$msg"); 
}

################################################################################
## Parse and verify heap size values
################################################################################
sub get_heapval {
    my ($optval, $confval, $optname, $allowempty) =@_;
    $$optval = $confval unless (defined $$optval);
    return undef if (!$$optval && $allowempty);
    if ($$optval =~ /^(\d+)\s*(MB)?$/) {
        if ($1 > 4096 && $arch_size == 32) {
            die "$optname value ($$optval) too large for 32 bits\n";
        }
        $$optval = "$1MB";
        return "((uint64_t)$1) << 20"; 
    } elsif ($$optval =~ /^(\d+)\s*GB$/) {
        if ($1 > 4 && $arch_size == 32) {
            die "$optname value ($$optval) too large for 32 bits\n";
        }
        $$optval = "$1GB";
        return "((uint64_t)$1) << 30"; # keep as string to avoid overflow
    } else {
        die "illegal value for $optname: $$optval\n";
    }
}

################################################################################
### Initialization code
################################################################################
sub initialize 
{
    # hack: if we're being called by help2man as part of generating the upcc man
    # page, we use a different 'version' option (we can't use the regular one,
    # since we'll have no valid upcc.conf file to read yet)
    my (@v) = grep {s/^-h2mversion=([0-9.]+)/$1/} @ARGV;
    if (@v) {
        # help2man format
        print "upcc @v\n";
        exit(0);
    }
    # same thing, but for help2man's -h2mhelp call
    if (grep { /-h2mhelp/ } @ARGV) {
        usage(1);
    }

    # find where this script is located
    $upcr_bin = $0;
    while (readlink($upcr_bin)) { 
        my $link = readlink($upcr_bin);
        if (substr($link, 0, 1) eq "/") {
            $upcr_bin = $link; 
        } else {
            $upcr_bin = dirname($upcr_bin) . "/" . $link; 
        }
    }
    $upcr_bin = dirname($upcr_bin);    # from File::Basename
    chdir($upcr_bin) or die "Can't cd to '$upcr_bin': $!\n";;
    $upcr_bin = getcwd(); # use absolute path
    chdir($startdir) or die "Can't cd to '$startdir': $!\n"; 

    # if we're in build tree, or at remote end of a nettrans_ssh, everything in
    # same dir
    if (-f "$upcr_bin/upcc.conf") {
        $in_build_tree = 1;
        $upcr_home = $upcr_etc = $upcr_lib = $upcr_include = $upcr_bin;
    } else {
        # should be in $prefix/bin part of an installed tree, with 'include' and
        # 'etc' siblings
        $in_build_tree = 0;
        $upcr_bin =~ m@^(.*?)/bin$@;
        $upcr_home = $1;
        $upcr_etc = "$upcr_home/etc";
        $upcr_lib = "$upcr_home/lib";
        $upcr_include = "$upcr_home/include";
        unless (-f "$upcr_etc/upcc.conf") {
            die "upcc.conf neither in upcc directory, nor in '$upcr_etc'\n";
        }
    }

    push @INC, $upcr_include;       # set up search path for our perl includes
    require "upcr_ctuple.pl";       # ctuple config checking library
    require "upcr_util.pl";         # misc utility library

    # We use our own copy of Getopt::Long, since some older versions out there
    # can't handle '-network=smp' type arguments (they're broken if only one
    # dash is provided, and a long arg is passed with an '=value').
    # - This can be replaced with the 'use Getopt::Long' at the start of this
    #   file if/when all our platforms have more recent versions of Getopt.
    # GetOpt::Long options:
    # bundling_override--allow bundling of single char flags (-vc), but also
    #   recognize long flags with either a single or double dash.
    # permute & pass_through: allow us to custom-handle -DFOO=BAR, which 
    #   standard getopt call mysteriously truncates to -DFOO
    require "upcr_getopt.pl";
    import Getopt::Long;
    Getopt::Long::Configure("bundling_override");
    Getopt::Long::Configure("permute");
    Getopt::Long::Configure("pass_through");

    # Chicken and egg situation #1:
    # We need to read our config file(s) to get the default args, but the
    # search for config files depends on certain options.
    # This little trick lets us parse these options from the
    # command-line without actually modifying @ARGV.
    {
      local @ARGV = @ARGV;
      Getopt::Long::Configure("no_auto_abbrev");
      exit(-1) unless GetOptions(
        'at-remote-ssh'     => \$opt_ssh_remote,
        'conf=s'            => \$opt_upccrc,
        'norc'              => \$opt_norc
      );
      Getopt::Long::Configure("auto_abbrev");
    }
    $opt_norc = 1 if defined $ENV{UPCC_NORC};

    # Now read the correct config file(s)
    readconfig();

    # finish some settings that depend on $conf
    if ($in_build_tree) {
      $upcr_include_src = $conf{'top_srcdir'};
      $prefix = $conf{'top_prefix'};
    } else {
      $upcr_include_src = $upcr_include;
      $prefix = $upcr_home . ($conf{'conf_name'} ? '/..' : '');
    }

    # prepend the default options set in the environment (if any)
    if ($ENV{UPCC_FLAGS}) { 
      my @env_args = split_quoted($ENV{UPCC_FLAGS}, "while parsing UPCC_FLAGS");
      if ((my $invalid) = grep /^-?-(norc|conf)/, @env_args) {
        die "$invalid is not permitted in UPCC_FLAGS\n"
      }
      unshift @ARGV, @env_args;
    }

    # Chicken and egg situation #2:
    # Conduit-specific args depend on both the config file and the network
    # setting, but the network selection could be a default in a config file,
    # or an option in UPCC_FLAGS or on the command line.  The last two are
    # not a problem, but we want the conduit-specific options to have higher
    # precedence than the default_options for all other settings.
    {
      local @ARGV = (split_quoted($conf{default_options}, "while parsing default_options"), @ARGV);
      exit(-1) unless GetOptions(
        'network=s'     => \$opt_network,
      );
    }
    unless (defined $opt_network) {
        $opt_network = $conf{default_network};
    }

    # prepend the conduit-specifc options set in config file(s) (if any)
    if ($conf{"${opt_network}_options"}) { 
      my @conduit_args = split_quoted($conf{"${opt_network}_options"}, "while parsing ${opt_network}_options");
      if ((my $invalid) = grep /^-?-(network|norc|conf)/, @conduit_args) {
        die "$invalid is not permitted in ${opt_network}_options\n"
      }
      unshift @ARGV, @conduit_args;
    }
    # prepend the default options set in config file(s) (if any)
    if ($conf{default_options}) { 
      my @default_args = split_quoted($conf{default_options}, "while parsing default_options");
      if ((my $invalid) = grep /^-?-(norc|conf)/, @default_args) {
        die "$invalid is not permitted in default_options\n"
      }
      unshift @ARGV, @default_args;
    }

    # accept -f[upc-]threads-N for compatibility with other UPC compilers
    map { s/^-f(upc-)?threads[=\-]([0-9]+)$/-T=$2/g } @ARGV;
    map { s/^-f(upc-)?threads$/-T/g } @ARGV;
    if ($debug_on || ((grep /^-?-v+$/, @ARGV) && !(grep /^-?-echo-var$/, @ARGV))) { 
      print "*** upcc running as: '@ARGV'\n" 
    }

    # Determine now which compiler/translator we are running
    # We need this in &opt_control(), and thus before GetOptions()
    if ($conf{using_gccupc} =~ /^y/i) {
      $gccupc = 1;
      $whoami = 'GNU UPC';
    } elsif ($conf{using_cupc} =~ /^y/i) {
      $cupc = 1;
      $whoami = 'Clang UPC';
    } elsif ($conf{using_cupc2c} =~ /^y/i) {
      $cupc2c = 1;
      $whoami = 'Clang UPC2C';
    } else {
      $bupc = 1;
      $whoami = 'Berkeley UPC';
    }
    
    @save_ARGV = @ARGV; # save a complete copy of argv

    exit(-1) unless GetOptions(
        'arch-size=i'       => \$opt_arch_size,
        'c'                 => \$opt_compileonly,
	'E'	            => \$opt_preprocessonly,
        'network=s'         => \$opt_network,
        'checks!'           => \$opt_checks,
	'link-cache!'	    => \$opt_link_cache,
        'at-remote-ssh'     => \$opt_ssh_remote,
        'at-remote-http'    => \$opt_http_remote,
        'compress=i'        => \$opt_http_compress,
        'g'                 => \$opt_debug,
	'fast-symptr!'	    => \$opt_pow2_symptr,
	'echo-var=s'        => \$opt_echo_var,
        #'D=s'              # handled by do_ARGVoodoo
        'extern-main'       => \$opt_extern_main,
        'h|?|help'          => \$opt_help,
        'print-include-dir' => \$opt_print_include,
        'print-mpicc'       => \$opt_print_mpicc,
        'print-translator'  => \$opt_print_translator,
        'I=s'               => \@opt_includes,
        'l=s'               => \&parse_lib,
        'L=s'               => \&parse_libpath,
        'link-with=s'       => \$opt_user_ld,
        'lines!'            => \$opt_lines,
        'nightly'           => \$opt_nightly,
        'norc'              => \$opt_norc,
        'conf=s'            => \$opt_upccrc,
        'O'                 => \$opt_optimize,
        'o=s'               => \$opt_outputname,
        'opt'               => \$opt_transopt,
        'opt-enable=s'      => \&opt_control,
        'opt-disable=s'     => \&opt_control,
	'ansi-alias'        => \$opt_ansi_alias,		       
        'pg'                => \$opt_profile,
        'inst'              => \$opt_inst,
        'inst-local'        => \$opt_inst_local,
        'inst-functions'    => \$opt_inst_functions,
        'inst-toolname=s'   => \$opt_inst_toolname,
        'thrille=s'         => \$opt_thrille,
        'thrille-local'     => \$opt_thrille_local,
        'heap-offset=s'     => \$opt_heap_offset,
        'require-size!'     => \$opt_require_size,
        'shared-heap=s'     => \$opt_shared_heap,
        'shared-heap-max=s' => \$opt_shared_heap_max,
        'save-temps!'       => \$opt_save_temps,
        'size-warn!'        => \$opt_size_warn,
        'sizes-file=s'      => \$opt_sizes_file,
        'show-sizes'        => \$opt_show_sizes,
        'save-all-temps!'   => \$opt_save_all_temps,
        'smart-output'      => \$opt_smart_output,
        'stable'            => \$opt_stable,
        's'                 => \$opt_strip,
        'T=i'               => \$opt_threadcount,
        "pthreads:$conf{default_pthreads}"	# Optional integer w/ a default
                            => \$opt_pthreads,
        'nopthreads'        => sub { $opt_pthreads = 0; },
        'allow-deprecated'  => \$opt_allow_deprecated,
        'trace'             => \$opt_trace,
        'trans'             => \$opt_translateonly,
        'translator=s'      => \$opt_translator,
        'http-proxy=s'      => \$opt_http_proxy,
        'tv'                => \$opt_totalview,
        'uses-mpi'          => \$opt_uses_mpi,
        'uses-threads'      => \$opt_uses_threads,
        'v+'                => \$opt_verbose,
        'V|version'         => \$opt_versiononly,
        #'U=s'              # handled by do_ARGVoodoo
#        'W=s'              # handled by do_ARGVoodoo
        'yesterday|hier'    => \$opt_yesterday,
        '<>'                => \&do_ARGVoodoo
    );
    # files may remain in ARGV if user passed '--' flag
    push @ARGVoodoo, @ARGV;

    $at_remote = 1 if ($opt_ssh_remote || $opt_http_remote);
    if ($at_remote) {
	my $scriptname = "$upcr_bin/".basename($0);
	my $modtime = localtime((stat($scriptname))[9]) || "unknown time";
        verbose("*** REMOTE upcc is: ".$host.":$scriptname ($modtime)") if ($at_remote);
    }

    @conduits = split /\s+/, $conf{conduits};

    usage() if $opt_help;

    if ($conf{upcc_version} =~ /^(\d+)\.(\d+)\.(\d+)$/) {
        $version_major = $1;
        $version_minor = $2;
        $version_patchlevel = $3;
    } else {
        die "Invalid upcc version string '$conf{version}' in configuration file\n";
    }
    if ($conf{runtime_spec} =~ /^(\d+)\.(\d+)$/) {
        $spec_major = $1;
        $spec_minor = $2;
    } else {
        die "Invalid Runtime spec version string '$conf{runtime_spec}' in configuration file\n";
    }

    die "UPC Specification version missing\n" unless $conf{upc_spec};

    # -save-all-temps implies -save-temps
    $opt_save_temps = 1 if $opt_save_all_temps;

    # lines is on by default unless --nolines passed 
    $opt_lines = 1 unless defined($opt_lines);

    # those naughty users...
    if ($opt_preprocessonly + $opt_translateonly + $opt_compileonly > 1) {
        die "only one of the '-E', '-c', and '-trans' flags may be used\n";
    }

    # Totalview support
    if ($opt_totalview && $conf{totalview_supported} !~ /^y/i && !$opt_http_remote) {
        die "-tv: this copy of Berkeley UPC was not built with --enable-totalview\n";
    }
    if ($opt_totalview && $opt_pthreads) {
        die "-tv and -pthreads cannot be used together\n";
    }
    if ($opt_totalview && $opt_transopt) {
        die "-tv and -opt cannot be used together\n";
    }
    $opt_debug = 1 if $opt_totalview;  # -tv implies -g

    # Check if pthreads option should be allowed
    if ($opt_pthreads) {
        if ($cupc) {
            die "$whoami does not support pthreads\n";
        } elsif ($gccupc && $conf{gccupc_tls} !~ /yes/i) {
            die "this configuration does not support pthreads (no GCC '__thread' attribute)\n";
        }
    }

    # Check for BUPC-specific options
    unless ($bupc) {
        my $errs = '';
        my @prohibited =
            ( [1, $opt_yesterday, '--yesterday'],
              [1, $opt_nightly, '--nightly'],
              [1, $opt_stable, '--stable'],
              [1, $opt_transopt, '--opt'],
            ) ;
        push @prohibited,
              [1, $opt_translateonly, '--trans'],
              [0, $opt_lines, '--nolines'],
              [1, 0+@opt_UPC_args, '-Wu,*'],
              [1, 0+@opt_W2C_args, '-Ww,*']
            unless ($cupc2c);

        for (@prohibited)
        {
            if (!$$_[0] == !$$_[1]) {  # Equality of values as booleans
                $errs .= "'$$_[2]' is not supported for ${whoami}\n      ";
            }
        }
        if ($errs) {
            $errs =~ s/ +$//;
            die $errs;
        }
    }

    $trans = $conf{translator};
    # special overrides for nightly/stable/hier builds of translator 
    if ( ($opt_yesterday + $opt_nightly + $opt_stable + $opt_translator) > 1) {
        die "only one of {-nightly | -yesterday | -stable | -translator} can be passed\n";
    }
    $trans = "http://upc-translator.lbl.gov/upcc-yesterday.cgi" if $opt_yesterday;
    $trans = "http://upc-translator.lbl.gov/upcc-nightly.cgi" if $opt_nightly;
    $trans = "http://upc-translator.lbl.gov/upcc-stable.cgi" if $opt_stable;
    $trans = $opt_translator if $opt_translator;
    $conftrans = $trans;  # save full config file spec for --version

    $trans =~ s!^\$prefix/!$prefix/!; # handle prefix-relative setting

    # use HTTP-based remote translation if translator starts with 'http://'
    # Otherwise, if we see 'host:path' for trans, use SSH
    if ($trans =~ m!^http://!) {
	die "'translator=$trans'\n  remote translation over http is not supported for $whoami"
            unless $bupc;
        if ($trans =~ m!^http://([^/:]+)(:(\d+))?(/.*)!) {
            $use_nettrans_http = 1;
            $nettrans_host = $1;
            $nettrans_http_port = $3;
            $nettrans_http_path = $4;
        } else {
            die "Bad URL for translator: $trans\n";
        }
        $proxy = $conf{http_proxy};
        $proxy = $opt_http_proxy if $opt_http_proxy;
        if ($proxy) {
	  if ($proxy =~ m!^http://([^/:]+)(:(\d+))?(/.*)?!) {
              $nettrans_host = $1;
              $nettrans_http_port = $3;
              $nettrans_http_path = $trans; # Proxy request must use the full URI
          } else {
              die "Bad URL for http proxy: $proxy\n";
          }
        }
    } elsif ($trans =~ /^([^:]+):(.*)$/) {
	die "'translator=$trans'\n  remote translation over ssh is not supported for $whoami"
            unless $bupc;
        $use_nettrans_ssh = 1;
        $nettrans_host = $1;
        $trans = $2;
    } elsif (!$bupc) {
        (my $trans_base = $trans) =~ s/ .*//; # drop any arguments
        die "$whoami UPC translator '$trans_base' does not exist!\n"
            unless (-f $trans_base);
    } else {
        die "Berkley UPC translator setting '$trans' is not a directory!\n"
            unless (-d $trans || $use_nettrans_http || ($use_nettrans_ssh && !$opt_ssh_remote));
    }

    # For bug 3037.  Translator and backend must agree on writable strings.
    if ($bupc && ($dbg_build || $opt_debug)) {
      push @opt_UPC_args, "-Wf,-Wwrite-strings";
    }

    if ($opt_transopt) {
	print STDERR "upcc: warning: Enabling *experimental* UPC translator optimizations (--opt).\n";
	if ($opt_ansi_alias) {
	    push @opt_UPC_args, "-O1 -OPT:alias=typed";
	} else {
	    push @opt_UPC_args, "-O1";
	}
	# As of 2.18.2 we want split-phase disabled.
	# This helps ensure that happens even with older translators.
	for ('-no-split-phase', @opt_opts) {
	    push @opt_UPC_args, "-Wb,$_";
	    push @opt_W2C_args, $_;
	}
    }

    if ($opt_profile) {
       my $prof_flags = $conf{profile_flags};
       if (!$prof_flags) {
         print STDERR "upcc: warning: Ignoring -pg flag - binary profiling not supported in this configuration.\n";
         $opt_profile = 0;
       } else {
         push @opt_CC_args, $prof_flags;
         push @opt_LD_args, $prof_flags;
       }
    }

    # GASP instrumentation support
    if ($conf{inst_supported} =~ /^y/i && !$opt_inst_toolname && !$opt_ssh_remote) {
	die "-inst: upcc should not be invoked directly for instrumenting compilations - call the GASP-based performance tool's compile wrapper instead (eg upcc-dump)\n";
    }
    if ($opt_inst || $opt_inst_local || $opt_inst_functions) { 
      if ($conf{inst_supported} !~ /^y/i) {
        die "-inst: this copy of Berkeley UPC was not built with GASP instrumentation support - reconfigure with --enable-inst\n";
      }
      my $inst_flags = (($gccupc || $cupc) ? \@opt_CPP_args : \@opt_CC_args);
      push @$inst_flags, "-DUPCRI_INST_TOOLNAME=$opt_inst_toolname";
      push @$inst_flags, "-DUPCRI_INST_UPCCFLAG=1";
      push @$inst_flags, "-DUPCRI_INST_LOCAL=1" if ($opt_inst_local);
      push @$inst_flags, "-DUPCRI_INST_FUNCTIONS=1" if ($opt_inst_functions);
    } 

    # Thrille active testing support
    if ($opt_thrille && $conf{thrille_supported} !~ /^y/i) {
      die "-thrille: this copy of Berkeley UPC was not built with Thrille active testing support - reconfigure with --enable-thrille\n";
    }

    # upc_trace support
    if ($opt_trace) {
      die "upcc: this copy of Berkeley UPC was not built with support for -trace\n"
          unless (",$conf{configure_features}," =~ m/,trace,/);
      die "upcc: -trace not supported for $whoami\n"
          unless ($bupc || $cupc2c);
    }

    # pthreads
    if ($conf{default_pthreads} <= 0) {
	die "Illegal setting 'default_pthreads=$opt_pthreads' in config file\n"
    }
    if (defined $opt_pthreads) {
	if ($opt_pthreads == 0) {
	    # Allow -pthreads=0 to explictly disable pthreads.
	    $opt_pthreads = undef;
	} elsif ($conf{pthreads_support} !~ /par/i) {
            die "pthreads not allowed in this configuration of Berkeley UPC\n";
        } elsif ($opt_pthreads < 0) {
            die "Illegal setting '-pthreads=$opt_pthreads'\n"
        } elsif ($opt_network eq 'shmem') {
            die "-pthreads does not work with 'shmem' network\n";
        }
    } elsif ($opt_network eq "smp" && 
             defined $opt_threadcount && $opt_threadcount > 1) {
	die "-network=smp only supports 1 static thread without -pthreads\n"
           unless ($at_remote || $conf{pshm_support} =~ /yes/i);
    } 

    # user-spawned threads 
    if (defined $opt_uses_threads) {
	if ($conf{pthreads_support} !~ /par/i) {
            die "thread support is not present in this configuration of Berkeley UPC\n";
        } elsif (defined $opt_pthreads) {
            die "-pthreads and -uses-threads are incompatible\n";
        } elsif ($opt_network eq 'shmem') {
            die "-uses-threads does not work with 'shmem' network\n";
        }
    }

    # user-provided linker 
    if ($opt_user_ld) {
        # To support passing args like --link-with="/Program Files/gcc -m64",
        # try truncating from last space, repeatedly, until no spaces
        eval { my $pathname = find_exec($opt_user_ld, $conf{exe_suffix}); };
        if ($@) {
            my $strippee = $opt_user_ld;
            # try lopping off spaces, in case they're arguments
            while ($strippee =~ s/^(.*)\s+(\S+)$/$1/) {
                eval { my $pathname = find_exec($strippee, $conf{exe_suffix}); };
                last unless $@;
            }
            die "--link-with: $@" if $@;
        }
    }

    # ditto for network conduit
    unless ($opt_http_remote || grep { $opt_network eq $_ } @conduits ) {
	my $types = "  valid network types for this configuration of upcc are: ".join(", ",@conduits);
        if (grep { $opt_network eq $_ } @all_networks) {
            die "'$opt_network' network is not supported in this configuration of upcc.\n$types\n";
        } else {
            die "'$opt_network' is not a valid network type.\n$types\n";
        }
    }

    # watch out for jokers and resurrected PDP-10 systems
    $arch_size = $opt_arch_size || $conf{arch_size};
    if ($arch_size != 32 && $arch_size != 64) {
        die "upcc does not presently support $arch_size-bit architectures\n";
    }

    # precompile the regexes used for filtering warnings unless verbose
    if ("$conf{warning_blacklist}" ne "" && !$opt_verbose) {
        foreach my $re (split /\@/,$conf{warning_blacklist}) { 
            next if $re =~ m/^\s*$/; # skip any element containing only whitespace
            push @warning_blacklist, ('^' . $re . '$');
        }
    }

    # use default amount for shared/local memory unless user
    # provides on command line
    $shared_heap_offset = get_heapval(\$opt_heap_offset,$conf{heap_offset},"-heap-offset");
    $shared_heap_size = get_heapval(\$opt_shared_heap,$conf{shared_heap},"-shared-heap");
    $shared_heap_size_max = get_heapval(\$opt_shared_heap_max,$conf{shared_heap_max},"-shared-heap-max",1);
    if ($opt_shared_heap_max && parse_size($opt_shared_heap) > parse_size($opt_shared_heap_max)) {
        verbose("*** increasing -shared-heap-max value to: $opt_shared_heap ".
                "to accomodate -shared-heap=$opt_shared_heap\n");
       $opt_shared_heap_max = $opt_shared_heap;
       $shared_heap_size_max = $shared_heap_size;
    } 

    # use smart naming instead of a.out if chosen
    unless (defined $opt_smart_output) {
        $opt_smart_output = $conf{smart_output} =~ /yes/i;
    }

    if ($opt_totalview) {
        $parseq = 'tv';
    } elsif (defined $opt_pthreads) {
        $parseq = 'par';
    } elsif (defined $opt_uses_threads) {
        $parseq = 'thr';
    } else {
        $parseq = 'seq';
    }

    $gmake = verify_exec($conf{gmake}, $conf{exe_suffix});
    $gmake_upcc = "$gmake -f $upcr_include/upcc.mak UPCR_HOME=$upcr_home";

    # see if we can enable symmptr with pow2 arithmetic
    my $symfail_reason = undef;
    $have_pow2_symptr = 0; 
    if (!(",$conf{configure_features}," =~ m/,symmetricsptr,/)) {
	$symfail_reason = "this install of Berkeley UPC was configured without --enable-sptr-symmetric";
    } elsif ( defined $opt_threadcount && !is_powerof2($opt_threadcount) ) {
       $symfail_reason = "symmetric pointers require a power-of-two thread count";
    } elsif ($opt_network eq "smp") {
        if ($opt_pthreads) { $have_pow2_symptr = 1; }
	else { $symfail_reason = "smp conduit only supports symmetric pointers with -pthreads"; }
    } elsif ($opt_network eq "shmem") {
	# check for crayx1 only in shmem
	my $platform = `uname -m`;
	chomp $platform;
	if ($platform =~ m/crayx1/) { $have_pow2_symptr = 1; }
	else { $symfail_reason = "this platform does not support fast symmetric pointers with shmem conduit"; }
    } else {
    	$symfail_reason = "$opt_network does not support symmetric pointers.";
    }

    if ($opt_pow2_symptr && !$have_pow2_symptr) {
	die "this configuration does not support fast symmetric pointers, because:\n\t$symfail_reason\n";
    }

    # Optimization enabled in static threads environment with threads power of
    # two or dynamic threads environment where user explicitly sets the option.

    # Enable the power-of-two optimization if it is available and not disabled,
    # as well as if we are given a static compilation environment with a power
    # of two number of threads.
    if ($have_pow2_symptr &&
       (( defined $opt_threadcount && is_powerof2($opt_threadcount) && 
          (!defined $opt_pow2_symptr || $opt_pow2_symptr)) ||
        (!defined $opt_threadcount && defined $opt_pow2_symptr && $opt_pow2_symptr))) {

	# Check to see if user passed a non-power-of-two shared heap size
	# We also validate this at runtime in case the size changed
	if (! is_powerof2($shared_heap_size)) {
	    die "$opt_network with fast symmetric pointer support requires " .
	        "power-of-two shared heap size (disable support with " .
		"-nofast-symptrs or specify a power-of-two shared heap size)\n";
	}
	$opt_pow2_symptr = 1;
	verbose("*** Enabled Power-of-two symmetric pointer optimization\n");
    }
    else {
	$opt_pow2_symptr = 0;
    }

    # get temp directory 
    if ($opt_ssh_remote) {
        # we're in it
        $tmp = $startdir;
    } else {
        # for temp directory, use a generated name which is unlikely to conflict
        # with other compilations, so concurrent compilation works.
        my $pid = $$;
        my $now = time();
        my $luser = $ENV{USER};
	# Cygwin stupidly allows spaces in user names, 
	# remove anything the shell may find offensive
	$luser =~ s/[^0-9a-zA-Z_-]/\_/g;
        $tmp = "$TMPDIR/upcc-$luser-$pid-$now";
        $rtmp_req = "$host-$luser-$pid-$now-to-$nettrans_host";
        $rtmp_rep = "$nettrans_host-to-$host-$luser-$pid-$now";
        if (-d $tmp) {
            die "temporary directory '$tmp' already exists!\n";
        }
        mkdir($tmp,0700) 
            or die "Can't create temporary directory '$tmp'\n";
        push @toRemove, $tmp;
    }

    # set up command line for remote invocation, if needed
    if ($use_nettrans_ssh) {
        # nettrans_ssh only needs a small subset of arguments
	for (my $i=0; $i < $opt_verbose; $i++) {
          push @nettrans_ssh_ARGV, '-v';
	}
        push @nettrans_ssh_ARGV, '-g' if $opt_debug;
        push @nettrans_ssh_ARGV, '-tv' if $opt_totalview;
        push @nettrans_ssh_ARGV, '-O' if $opt_optimize;
        push @nettrans_ssh_ARGV, $opt_lines ? '-lines' : '-nolines';
        push @nettrans_ssh_ARGV, '-nochecks' if ! $opt_checks;
        push @nettrans_ssh_ARGV, '-save-temps' if $opt_save_temps;
        push @nettrans_ssh_ARGV, '-save-all-temps' if $opt_save_all_temps;
        push @nettrans_ssh_ARGV, "-T", $opt_threadcount if $opt_threadcount;
        push @nettrans_ssh_ARGV, "--norc", if $opt_norc;
        for (@opt_UPC_args) {
            push @nettrans_ssh_ARGV, "-Wu,$_";
        }
        for (@opt_W2C_args) {
            push @nettrans_ssh_ARGV, "-Ww,$_";
        }
        if (defined ($opt_pthreads)) {
            push @nettrans_ssh_ARGV, '-pthreads', $opt_pthreads 
        }
        push @nettrans_ssh_ARGV, "-translator=$trans";
    }

    #
    # Get config strings and type sizes by parsing target runtime library,
    # or from sizes file if during netcompilation
    # 
    if ($at_remote) {
        open (SIZES, $sizesfile) 
            or die "Forgot to copy '$sizesfile' to remote host\n";
        while (<SIZES>) {
            $upcrlib_ctuple = $1 if /UPCRConfig\s+(\S+)/;
            $gasnetlib_ctuple = $1 if /GASNetConfig\s+(\S+)/;
        }
	close (SIZES);
    } else {
        my $targetlib = "$upcr_lib/libupcr-$opt_network-$parseq.a";
        my ($gastup_ref, $upcrtup_ref, $sizes_ref, $misc_ref) = extract_ctuples($targetlib);

        $buildtime = $$misc_ref{UPCRBuildTimestamp};
        die "No runtime build timestamp in $targetlib\n" unless $buildtime;

        # make sure all type sizes needed are present, and store them
        for (qw/shared_ptr pshared_ptr mem_handle reg_handle void_ptr ptrdiff_t int 
                char short long longlong float double longdouble size_t _Bool/) 
        {
            my $size = $$sizes_ref{$_};
            my $align = $$sizes_ref{"alignof_$_"};
            if ($size) {
                $translator_typesizes{$_} = $size;
            } else {
                die "'$targetlib' is missing size information for '$_'"
                   . " (try rebuilding the library)\n";
            }
            if ($align) {
                $translator_typesizes{"alignof_$_"} = $align;
            } else {
                die "'$targetlib' is missing alignment information for '$_'"
                   . " (try rebuilding the library)\n";
            }
        }

        # silly exceptions for structs on Power/PowerPC
	# Depending slightly on the ABI (AIX vs Darwin) the various 64 bit types
	# may have either 4- or 8-byte alignment constraints under most conditions.
	# However, when they appear as the first member of a structure type, they
	# have alignment of 8.
	# We look at the size of structs that contain the relavent type as the
	# first member to determine if the alignment is "exceptional".
	sub align_exception($$) {
	    my ($struct_name, $type_name) = @_;

	    my $struct_sz = $$sizes_ref{$struct_name};
            die "'$targetlib' is missing $struct_name information "
                . "(try rebuilding the library)\n" unless $struct_sz;

	    my $base_sz = $$sizes_ref{$type_name};
	    my $base_align = $$sizes_ref{"alignof_$type_name"};
	    
	    # return the exceptional alignment, or zero if alignment is normal.
	    # This expression works only because alignment <= sizeof (no padding at end).
	    return ($struct_sz != ($base_sz + $base_align)) ? ($struct_sz - $base_sz) : 0;
	}
        $dbl_1st_struct_align = align_exception('dblchar_struct', 'double');
	$sharedptr_1st_struct_align = align_exception('sptrchar_struct', 'shared_ptr');
	$psharedptr_1st_struct_align = align_exception('psptrchar_struct', 'pshared_ptr');
	sub align_innerstruct($$$) {
	    my ($struct_name, $type_name, $align_exception) = @_;
	    my $innerstruct_align = $$sizes_ref{$struct_name};
            die "'$targetlib' is missing $struct_name information "
                . "(try rebuilding the library)\n" unless $innerstruct_align;

	    # return the exceptional alignment, or zero if alignment is normal.
	    return ($align_exception && $innerstruct_align == $align_exception ? $align_exception : 0);
	}
        $dbl_inner_struct_align = align_innerstruct('dbl_innerstruct', 'double', $dbl_1st_struct_align);
	$sharedptr_inner_struct_align = align_innerstruct('sptr_innerstruct', 'shared_ptr', $sharedptr_1st_struct_align);
	$psharedptr_inner_struct_align = align_innerstruct('psptr_innerstruct', 'pshared_ptr', $psharedptr_1st_struct_align);
	{ # First identify a 64-bit integral type
	    my ($type64) = grep {$$sizes_ref{$_} == 8} (qw/int long longlong/);
	    die "'$targetlib' is missing an 8-byte type" unless $type64;
	    $int64_1st_struct_align = align_exception('int64char_struct', $type64);
	    $int64_inner_struct_align = align_innerstruct('int64_innerstruct', $type64, $int64_1st_struct_align);
	}
        # promotion to strictest alignment when structs are nested
        $struct_promote = (($$sizes_ref{'struct_promote'} == 24) &&
                           ($$sizes_ref{'int64char_struct'} == 16)) ? '1' : '0';

        # maxblocksize is stored as number of bits in shared pointer's phase field
        my $phasebits = $$sizes_ref{'phasebits'};
        die "'$targetlib' is missing size information for 'phasebits'"
            . " (try rebuilding the library)\n" unless $phasebits;
	if ($phasebits >= 31) { # prevent 32-bit overflow
	  $maxblocksz = (1 << 31) - 1;
	} else {
          $maxblocksz = 1 << $phasebits;
	}
         
        # get gasnet and runtime libraries' ctuples, for ensuring consistent
        # configuration among all objects built into an application
        die "'$targetlib' is missing UPCRConfig setting (try rebuilding library)\n"
            unless $upcrlib_ctuple = $$upcrtup_ref{'libupcr.a'};
        die "'$targetlib' is missing GASNetConfig setting (try rebuilding library)\n"
            unless $gasnetlib_ctuple = $$gastup_ref{'libupcr.a'};
        $upcrlib_ctuple =~ s/SHAREDPTRREP=symmetric/SHAREDPTRREP=fsymmetric/ if ($opt_pow2_symptr);
    }

    #
    # set up extra cpp flags for preprocess and compilation stages
    #

    # Quote options passed to preprocessor/sgiupc/whirl2c/compiler/linker if needed
    #   -also need to quote for nettrans_ssh's ARGV
    for (@opt_CPP_args, @opt_UPC_args, @opt_W2C_args, @opt_CC_args, @opt_LD_args) { 
        if (/\s/) {
            my $old = $_;
            s/\,(.*)$/,"$1"/;
            my $new = qq<"$_">;
            for (@nettrans_ssh_ARGV) {
                s/$old/$new/;
            }
        }
    }

    # set up cpp flags in one place here, since we use them multiple times
    $extra_cppflags  =  "-D__BERKELEY_UPC_RUNTIME__=1";
    $extra_cppflags .= " -D__BERKELEY_UPC_RUNTIME_DEBUG__=1" if (",$conf{configure_features}," =~ m/,debug,/);
    $extra_cppflags .= " -D__BERKELEY_UPC_RUNTIME_RELEASE__=$version_major"
                    .  " -D__BERKELEY_UPC_RUNTIME_RELEASE_MINOR__=$version_minor"
                    .  " -D__BERKELEY_UPC_RUNTIME_RELEASE_PATCHLEVEL__=$version_patchlevel"
                    .  " -D__BERKELEY_UPC_".uc($opt_network)."_CONDUIT__=1";
    $extra_cppflags .= " -DGASNETT_USE_GCC_ATTRIBUTE_DEPRECATED=0" if ($opt_allow_deprecated);

    # Wrap any -D/-I values that contain spaces in quotes
    # - goal: allow users to pass macro string values via -D FOO=\"bar\" (or
    #   -D FOO="\"with spaces\"" if string contains spaces), and/or pass in -I
    #   directories that contain spaces via -I "/program files"
    # - TODO This fix is not complete:  nasty users can pass in strings that
    #        contain double quotes.  To gcc:  -D BAR="\"don't \\\"fix\\\" me\""
    #        will result in BAR expanding to 'don't "fix" me'.  This approach
    #        somehow loses the quotes around "fix".  
    for (@opt_defines) { 
        s/"/\\\\\\"/g;
        s/=(.*)$/=\\"$1\\"/ if /\s/; 
        $extra_cppflags .= " $_" 
    };
    for (@opt_includes) { 
        # turn relative paths into absolute paths, since we use a temp directory
        s|^(.*)$|$startdir/$1| unless m|^/|;
        s/"/\\\\\\"/g;
        s/^(.*)$/\\"$1\\"/ if /\s/; 
        $extra_cppflags .= " -I$_" 
    };

    # UPC language defines for the back-end compiler and bupc translator
    $upc_cppflags .= " -D__UPC__=1 -D__UPC_VERSION__=$conf{upc_spec}";
    if ($opt_threadcount) {
       	$upc_cppflags .= " -D__UPC_STATIC_THREADS__=1 -DTHREADS=$opt_threadcount";
    } else {
       	$upc_cppflags .= " -D__UPC_DYNAMIC_THREADS__=1";
    }
    # standardized features available in UPCR
    $extra_cppflags   .= " -D__UPC_COLLECTIVE__=1";
    $extra_cppflags   .= " -D__UPC_PUPC__=1";
    $extra_cppflags   .= " -D__UPC_IO__=2";
    $extra_cppflags   .= " -D__UPC_TICK__=1";
    $extra_cppflags   .= " -D__UPC_CASTABLE__=1";
    $extra_cppflags   .= " -D__UPC_NB__=1";
    # features available in current configuration or with current command-line
    $extra_cppflags   .= " -D__BERKELEY_UPC_PSHM__=1" if ($conf{pshm_support} =~ /yes/i);
    $extra_cppflags   .= " -D__BERKELEY_UPC_PTHREADS__=1" if ($opt_pthreads);
    $extra_cppflags   .= " -D__BERKELEY_UPC_USER_THREADS__=1" if ($opt_uses_threads);
    $extra_cppflags   .= " -D__BERKELEY_UPC_POW2_SYMPTR__=1" if ($opt_pow2_symptr);
    if ($bupc) {
	# berkeley-specific defines
	# version info is currently identical to RUNTIME_RELEASE values
        $extra_cppflags .= " -D__BERKELEY_UPC__=$version_major"
                        .  " -D__BERKELEY_UPC_MINOR__=$version_minor"
                        .  " -D__BERKELEY_UPC_PATCHLEVEL__=$version_patchlevel"
                        .  " -DUPC_MAX_BLOCK_SIZE=$maxblocksz";
    }
    if ($bupc || $cupc2c) {
        $extra_cppflags .= $upc_cppflags;
    }
    # if given a sizes file at an arbitrary location (used by HTTP translation)
    if ($opt_sizes_file) {
        unless (-r $opt_sizes_file) { 
            die "--sizes-file '$opt_sizes_file' does not exist!\n" 
        }
        if ($opt_sizes_file =~ m@^/@) {
            $sizesfile = $opt_sizes_file 
        } else {
            $sizesfile = "$startdir/$opt_sizes_file";
        }
    }

    # use MPI compiler/linker if -uses-mpi passed, but allow user to override 
    if ($opt_uses_mpi) {
        if (grep {$_ eq $opt_network} (split /\s+/, $conf{mpi_incompatible})) {
            die "'--uses-mpi' does not work with '--network=$opt_network'\n";
        }
        die "'--uses-mpi' does not currently work with '-pthreads'\n"
            if $opt_pthreads;

        # NOTE: for now, we require CC=mpicc during configure for MPI support:
        # at some point, we'll build a separate gasnet lib with CC=MPI_CC, and
        # select for it here 
        #my $mpicc = get_mpicc();
        #$opt_user_ld = $mpicc unless $opt_user_ld;
    }
}

################################################################################
### Library arguments
################################################################################
sub parse_lib {
    my $arg = $_[1];
    push @opt_LD_args, "-l$arg";
}

sub parse_libpath {
    my $arg = $_[1];
    push @opt_LD_args, "-L$arg";
}

################################################################################
# Stoopid perl getopt can't deal with '-Dfoo=bar' for some reason: it silently
# drops the '=bar' (it works fine with both '-Dfoo' and '-D foo=bar': go
# figure).  So we deal with them here.  But since we need the 'permute' flag to be
# on to do this, we also need to process all non-flag arguments in ARGV,
# including the files to be processed.
# We also deal with the -U options here, to ensure order with -D options is preserved
#   - -Wc,-flag=VALUE has same problem, so these are also handled here.
################################################################################
sub do_ARGVoodoo {
    my $arg = $_[0];
    if ($arg =~ /^-([DU])(.*)$/) {
	my $variety = $1;
        if ($2) {
	    die "upcc: bad -U option" if ($variety eq "U" && $arg =~ /=/);
            push @opt_defines, $arg;
        } else {
            my $nextarg = shift @ARGV;
            die "upcc: -$variety option missing argument" if (!defined($nextarg) || $nextarg =~ /^-/);
	    die "upcc: bad -U option" if ($variety eq "U" && $nextarg =~ /=/);
            push @opt_defines, "-$variety$nextarg";
        }
    } elsif ($arg =~ /^-W([puwcl]),(.*)/) {
        ### handle gcc-style '-Wu,--flag=foo' type args
        my ($stage,$opts) = ($1,$2);
        if ($stage eq 'p') {
            push @opt_CPP_args, $opts;
        } elsif ($stage eq 'u') {
            push @opt_UPC_args, $opts;
        } elsif ($stage eq 'w') {
            push @opt_W2C_args, $opts;
        } elsif ($stage eq 'c') {
            push @opt_CC_args, $opts;
        } elsif ($stage eq 'l') {
            push @opt_LD_args, $opts;
        } else {
            die("upcc: invalid option '$arg'\n");
        }
    } elsif ($arg =~ /^-/) {
        die "upcc: unrecognized flag '$arg'\n";
    } else {
        push @ARGVoodoo, $arg;
    }
}

################################################################################
### Handle --opt-enable/opt-disable flags
################################################################################
sub opt_control { 
  unless ($bupc) {
    die "upcc: --opt-enable/--opt-disable not supported for $whoami\n";
  }
  my ($en,$opts) = @_;
  if ($en eq "opt-enable") {
    $en = "do";
  } elsif ($en eq "opt-disable") {
    $en = "no";
  } else {
    die "upcc: unrecognized opt_control flag $en\n";
  }
  foreach (split /,/,$opts) { 
    push @opt_opts, "-$en-$_";
  } 
}

################################################################################
### Find site and user config file(s), and read in settings
################################################################################
sub userconfig {
    if ($opt_ssh_remote) {
        return '.upccrc';
    } elsif ($opt_upccrc) {
        return $opt_upccrc;
    } else {
        return userhome() . '/.upccrc'
    }
}
sub readconfig {
    my $upcc_conf = "$upcr_etc/upcc.conf";
    my $section = $ENV{UPCRI_CONF_NAME} || '';
    # parse main upcc.conf file
    parseconfig($upcc_conf, 1, \%conf, $section);

    # Users may also put prefs in a ~/.upccrc file (which we'll have copied to
    # the current directory if we're doing a nettrans_ssh) or pass -conf=FILE.
    # In the -conf=FILE case the file must exist.
    unless ($opt_norc) {
        my $upccrc = userconfig();
        my $section = $ENV{UPCRI_CONF_NAME} || $conf{conf_name};
        parseconfig($upccrc, defined($opt_upccrc), \%conf, $section);
    }

    # check to see all variables without default values have been set 
    for my $key (keys(%conf)) {
        if ($conf{$key} eq 'nodefault') {
            die "Setting for '$key' missing from config file '$upcc_conf' for '$key'\n";
        }
    }

    $conf{conf_name} = $ENV{UPCRI_CONF_NAME} if exists($ENV{UPCRI_CONF_NAME});
    $dbg_build = ($conf{conf_name} =~ m/^dbg/);
    $opt_build = ($conf{conf_name} =~ m/^opt/);
}

################################################################################
## Run an external command (in optional directory)
## - prints STDOUT unless $shutupifOK nonzero
## - always prints STDERR (but filters through warning_blacklist)
## - always returns contents of STDOUT if successful
## - dies w/error msg if command fails
## - runs command in current directory, or specified $dir
################################################################################
sub runCmd {
    my ($cmd, $contextMsg, $dir, $shutupifOK) = @_;
    my $out = "$tmp/upcc.stdout.tmp";
    my $err = "$tmp/upcc.stderr.tmp";
    my $oldslash = $/;
    my $olddir = getcwd();
    chomp ($olddir);
    undef $/; # slurp!

    if ($dir) {
        chdir($dir) or die "couldn't chdir to '$dir': $!\n";
    }

    # escape any double quotes in the command
# DOB: this is broken for some reason
#   $cmd =~ s/([^\\])"/$1\\"/g;
#   verbose(qq{upcc running /bin/sh -c "$cmd"});
#   my $exitval = system(qq{/bin/sh -c "$cmd >$out 2>$err"});
    verbose("*** " . ($at_remote ? "REMOTE ": "") 
            . "upcc running: '$cmd'" 
            . ($dir ? " in $dir" : "")
            . " ***");

    # Ensure we get a POSIX compliant bourne shell on Tru64,
    # which stupidly gives you a very broken bourne-like shell by default
    $ENV{'BIN_SH'}="xpg4" if (!$ENV{BIN_SH});

    # magic variable to disable Cray XT cc's target INFO warning
    # which annoyingly appears multiple times per upcc invocation
    $ENV{'XTPE_INFO_MESSAGE_OFF'}="1" if (!$ENV{XTPE_INFO_MESSAGE_OFF});

    my $exitval = system("$cmd >\'$out\' 2>\'$err\'");

    open(GETOUT, "$out") or die "Can't open temp file $out\n";
    my $stdout = <GETOUT>; # slurp!
    close GETOUT;
    if ($opt_verbose || $debug_on) {
        print $stdout unless ($shutupifOK && $exitval == 0);
    }
    # do 'chomp' manually, since it don't work normally when $/ undefined
    $stdout =~ s/[ \t\n]+$//;

    open(GETERR, "$err") or die "Can't open temp file $err\n";
    my $errtxt = <GETERR>;  # slurped
    close GETERR;
    $/ = $oldslash;
    foreach my $re (@warning_blacklist) { $errtxt =~ s/$re//mg; }
    $errtxt =~ s/^\s*(.*)$/$1/sg; # trim any leading/trailing whitespace
    $errtxt =~ s/^(.*\S)\s*$/$1/sg; 

    if (($exitval & 127) == $conf{'SIGINT'}) { # detect user-generated kill signals
        die "compilation terminated by signal SIGINT" . ($opt_verbose?"\n '$cmd':\n $errtxt\n":'');
    } elsif (($exitval & 127) == $conf{'SIGTERM'}) {
        die "compilation terminated by signal SIGTERM" . ($opt_verbose?"\n '$cmd':\n $errtxt\n":'');
    } elsif (($exitval & 127) == $conf{'SIGKILL'}) {
        die "compilation terminated by signal SIGKILL" . ($opt_verbose?"\n '$cmd':\n $errtxt\n":'');
    } elsif ($exitval) {
	# some tools (ex ld on darwin) stupidly dump errors to stdout, leaving at most a gmake error in stderr
	my $tmp = $errtxt;
	$tmp =~ s/^g?make(?:\[[0-9]*\])?:.*$//g;
        $errtxt = "$stdout\n$errtxt" if ($tmp eq "");
	die "$contextMsg: " . ($opt_verbose?"'$cmd'":''), "\n$errtxt\n";
    } elsif ($errtxt && !$shutupifOK) { 
        # be sure to print warnings and non-fatal messages
        print STDERR "$errtxt\n";
    }
    if ($dir) {
        chdir($olddir) or die "couldn't chdir back to '$olddir': $!\n";
    }

    return $stdout;
}

# get the UPCR thread configuration string in effect
sub get_threadconfig
{
    if ($opt_threadcount) {
       return ",staticthreads=$opt_threadcount";
    } else { 
      return ",dynamicthreads";
    }
}

################################################################################
## Figure out what we're compiling and/or linking, and then do it.
################################################################################
sub runDriver
{
    if ($opt_versiononly) {
        # turn off verbosity - allow -vvv to show gory details
        $opt_verbose = 0 if ($opt_verbose < 3); 
        print_version();
	return; # bug569 - return to cleanup temps
    }
    if ($opt_print_include) {
        # turn off verbosity - allow -vvv to show gory details
        $opt_verbose = 0 if ($opt_verbose < 3); 
        print get_make_value('UPCR_EXTERN_INCLUDEDIR'), "\n";
	return; # bug569 - return to cleanup temps
    }
    if ($opt_print_mpicc) {
        # turn off verbosity - allow -vvv to show gory details
        $opt_verbose = 0 if ($opt_verbose < 3); 
        print get_mpicc(), "\n";
	return; # bug569 - return to cleanup temps
    }

    if ($opt_echo_var) {
        # turn off verbosity - allow -vvv to show gory details
        $opt_verbose = 0 if ($opt_verbose < 3); 
	my $val = get_make_value($opt_echo_var);
	print "$val\n";
	return; # bug569 - return to cleanup temps
    }

    if ($opt_print_translator) {
        if ($use_nettrans_ssh) {
            print "$nettrans_host:$trans\n";
        } else {
            print "$trans\n";
        }
        return;
    }

    if ($opt_show_sizes) {
	$sizesfile = "$tmp/upcc-sizes";
	create_sizes_file("$sizesfile");
	open SIZES, "<$sizesfile" or die "failed to open sizes file: $!\n";
	while (<SIZES>) { print; }
	close SIZES;
	return; # bug569 - return to cleanup temps
    }

    for my $file (@ARGVoodoo) {
        die "'$file' does not exist!\n" unless -e $file;
        die "'$file' is not a regular file!\n" unless -f $file;

        # handle '[]', '\', and '*' specially
        my $unsupported_filename_chars = '(`$\'"{}|<>%)^?:;!#&';
        if ($file =~ /[$unsupported_filename_chars\[\]\\*]/o) {
            die "'$file': upcc does not support filenames containing any of "
              . "the following characters: [$unsupported_filename_chars\\*]\n";
        }
        if ($file =~ /^-/) {
            die "'$file': upcc does not support filenames starting with '-'\n";
        }

        unless ($file =~ m@^(?:(.*)/)?([^/]+?)(?:\.(trans\.c|[^.]+))?$@) {
            die "internal regex error matching file='$file'\n";
        }
        my $dir = $1 || $startdir;
        my $basename = $2;
        my $ext = $3;
        # preserve original file names so we can recover them later
        $origPathName{$basename} = $file; 
        $origDir{$basename} = $dir; 

        # By their names ye shall know them...
        if ($ext =~ m@^(upc|c|trans\.c|i)$@) {

            my ($preprocessed, $translated);
            if ($ext eq 'i') {
                $preprocessed = 1;
                # copy file to temp dir (already there if nettrans_ssh) 
                unless ($opt_ssh_remote) {
                    my $copycmd = "cp -f \'$file\' \'$tmp\'";
                    runCmd($copycmd, "error copying $file to $tmp");
                }
            } elsif ($ext eq 'trans.c') {
                $preprocessed = 1;
                $translated = 1;
                # copy file to temp dir
                my $copycmd = "cp -f \'$file\' \'$tmp\'";
                runCmd($copycmd, "error copying $file to $tmp");
            } 
            if ($opt_preprocessonly) {
                die "'$file' already preprocessed!\n" if $preprocessed;
                push @toPreprocess, $basename;
            } elsif ($opt_translateonly) {
                die "'$file' already translated!\n" if $translated;
                push @toPreprocess, $basename unless $preprocessed;
                push @toTranslate, $basename;
            } elsif ($opt_compileonly) {
                push @toPreprocess, $basename unless $preprocessed;
                push @toTranslate, $basename unless $translated;
                push @toCompile, $basename;
            } else {
                push @toPreprocess, $basename unless $preprocessed;
                push @toTranslate, $basename unless $translated;
                push @toCompile, $basename;
                if ($opt_pthreads && !($gccupc||$cupc)) {
                    get_target_names($basename);
                    push @toLinkPthreads, "$tmp/$basename.o";
                    push @toLinkUPC, "$pthread_linkdir/${basename}_obj.o";
                    push @toLink, "$pthread_linkdir/${basename}_obj.o";
                } else {                
                    push @toLinkUPC, "$tmp/$basename.o";
                    push @toLink, "$tmp/$basename.o";
                }
            }
        } else {
            if (is_upc_obj($file)) {
                if ($opt_pthreads && !($gccupc||$cupc)) {
                    die("Illegal attempt to link non-pthreads object '$file' with -pthreads\n")
                            unless is_upc_pthreads_obj($file);
                    get_target_names($basename);
                    push @toLinkPthreads, $file;
                    push @toLinkUPC, "$pthread_linkdir/${basename}_obj.o";
                    push @toLink, "$pthread_linkdir/${basename}_obj.o";
                } else {
                    push @toLinkUPC, $file;
                    push @toLink, $file;
                }
            } else {
                push @toLink, $file;
            }
        }
    }

    unless (@toPreprocess || @toTranslate || @toCompile || @toLink) {
        die("no input files\n");
    }

    if (@toLink && $opt_preprocessonly) {
        die("-E flag used, but object files '@toLink' passed\n");
    }
    if (@toCompile && $opt_preprocessonly) { # need this to check for .trans.c files
        die("-E flag used, but files '@toCompile' passed\n");
    }
    if (@toLink && $opt_compileonly) {
        die("-c flag used, but object files '@toLink' passed\n");
    }
    if ($opt_translateonly && $opt_outputname && (@toTranslate > 1)) {
        die("cannot specify -o with -trans for multiple files\n");
    }
    if ($opt_compileonly && $opt_outputname && (@toCompile > 1)) {
        die("cannot specify -o with -c for multiple files\n");
    }
    if ($conf{thrille_supported} =~ /^y/i) {
      my $mode = $opt_thrille || 'empty';
      $extra_cppflags .= " -DUPCR_THRILLE_" . uc($mode) . "=1";
      if (@toLink) {
        my $basename = 'upct_mode_' . $mode;
        my $dir = $upcr_include . '/thrille/';
        $dir = $conf{thrille_dir} . '/src/' unless (-f "${dir}${basename}.c");
        die "unknown Thrille mode '$mode' requested\n" unless (-f "${dir}${basename}.c");
        $origPathName{$basename} = $dir . $basename . '.c';
        $origDir{$basename} = $dir; 
        { # Take a brief detour to translate the upct_ file WITHOUT instrumentation 
          my @saveP = @toPreprocess; @toPreprocess = ( $basename );
          my @saveT = @toTranslate;  @toTranslate  = ( $basename );
           do_preprocess();
           do_translate();
           unlink "$tmp/$basename.i"; # HACK: do not send this .i to remote
          @toTranslate  = @saveT;
          @toPreprocess = @saveP;
        }
        push @toCompile, $basename;
        if ($opt_pthreads && !$gccupc) {
          get_target_names($basename);
          push @toLinkPthreads, "$tmp/$basename.o";
          push @toLinkUPC, "$pthread_linkdir/${basename}_obj.o";
          push @toLink, "$pthread_linkdir/${basename}_obj.o";
        } else {                
          push @toLinkUPC, "$tmp/$basename.o";
          push @toLink, "$tmp/$basename.o";
        }
      }
      push @opt_UPC_args, '-Wb,-run-thrille' if ($opt_thrille_local);
    }
    if (@toLink && !@toTranslate && $bupc) {
      # for a link-only invocation, ensure we translate at least one file
      # in order to get the translator's helper C files
      # TODO: we might eventually add local caching to prevent this extra connection
      my $tmpupc = "trans_extra_linkdummy";
      open (TMPUPC, ">$tmp/$tmpupc.i") or die "Can't open '$tmpupc' for writing\n";
      print TMPUPC <<EOF;
#pragma upc upc_code
static int upcc_trans_extra_dummyvar;
static void upcc_trans_extra_dummyfn() {}
EOF
      close TMPUPC;
      push @toTranslate, $tmpupc; # do not preprocess or link this file
    }
    get_target_names();

    if ($cupc2c) {
      do_preprocess_cupc2c() if $opt_preprocessonly; # Only for -E
      do_translate_cupc2c() if @toTranslate;
    } else {
      do_preprocess() if @toPreprocess && !$opt_ssh_remote;
      do_translate() if @toTranslate;
    }
    do_compile() if @toCompile;
    do_link() if @toLink; 
}

# figures out target executable name, if any, and names for 
# -save-all-temps directory and pthread build directory.
sub get_target_names
{
    # since we need to call this at different places, ensure that it only gets
    # run once
    return if $target;

    # chicken-and-egg workaround:  if pthreads, we may need to derive target
    # name from first object, but can't add first object to @toLink until we 
    # know the pthreads_linkdir.  So allow it to be passed as an argument.
    my ($firstobj) = @_;

    if (@toLink || $firstobj) {
        my $dumbname;
        my $smartname = $firstobj || $toLink[0];
        $smartname =~ s/\.[^.]+$//;
        $smartname = basename($smartname);
        if ($conf{exe_suffix} ne "") {
            $smartname .= $conf{exe_suffix};
            $dumbname = "a$conf{exe_suffix}";
            if ($opt_outputname && !($opt_outputname =~ /$conf{exe_suffix}$/)) {
                $opt_outputname .= $conf{exe_suffix};
            }
        } else {
            $dumbname = "a.out";
        }
        $target = $opt_outputname || 
                  ($opt_smart_output ? $smartname : $dumbname);
    } elsif (@toCompile) {
        if ($opt_outputname) {
            $target = $opt_outputname;
        } else {
            # use name(s) of .o files generated, with '_' joining them.
            # Only used for save-all-temps directory name
            for (@toCompile) {
                $target .= "${_}.o_";
            }
        }
    } elsif (@toTranslate) {
        if ($opt_outputname) {
            $target = $opt_outputname;
        } else {
            # use name(s) of .trans.c files generated, with '_' joining them.
            # Only used for save-all-temps directory name
            for (@toTranslate) {
                $target .= "${_}.trans.c_";
            }
        }
    } elsif (@toPreprocess) {
        if ($opt_outputname) {
            $target = $opt_outputname;
        } else {
            # use name(s) of .trans.c files generated, with '_' joining them.
            # Only used for save-all-temps directory name
            for (@toPreprocess) {
                $target .= "${_}.i_";
            }
        }
    } else {
        die "internal error in get_target_names()\n";
    }
    $targetbase = basename($target);
    if ($targetbase =~ /_$/) {
        $saveall_dir = "$startdir/${targetbase}temps";
    } else {
        $saveall_dir = "$startdir/${targetbase}_temps";
    }
    $pthread_linkdir = "$startdir/${targetbase}_pthread-link";
}

################################################################################
## Common support code for clang-upc2c
################################################################################
sub get_cupc2c_cppflags
{
    my $cupc2c_cppflags;

    $cupc2c_cppflags = '-D__BERKELEY_UPC_FIRST_PREPROCESS__=1';

    # TODO - do we need something as complex as gcc_as_cc.pl to get
    # exactly the same preprocessor defines as the backend compiler?
    $cupc2c_cppflags .= " $conf{redef_gnuc}" if $conf{redef_gnuc};

    # Disable various non-portable system header transformations:
    # TODO - should this be in PRETRANS_CPPFLAGS instead of here?
    $cupc2c_cppflags .= ' -U__OPTIMIZE__';

    # clang-upc2c requires -fupc-threads, even for preprocessing
    $cupc2c_cppflags .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;

    # Ensure PTS rep matches:
    $cupc2c_cppflags .= " $conf{clang_pts_opts}";

    # Append any options provided by user via -Wp (last to override our options)
    $cupc2c_cppflags .= " @opt_CPP_args" if @opt_CPP_args;

    return $cupc2c_cppflags;
}

################################################################################
## Preprocess UPC source code using backend C compiler's preprocessor
################################################################################
sub do_preprocess
{
    stagemsg("PREPROCESSING");

    # Since preprocessors write to stdout, and for IBM cc at least -v also goes
    # to stdout, we can't ever pass it, no matter how verbose the user wants
    # us to be.
    #$extra_cppflags .= " -v" if $opt_verbose > 1;

    # Construct once those options which are indepent of file
    my $Ipaths;
    for (@opt_includes) { $Ipaths .= "-I '$_' "; }
    my $detect_upc_flags = ($opt_verbose > 1) ? "-v" : "";
    my $xtraflags;
    $xtraflags .= " -g" if $opt_debug;
    $xtraflags .= " -O" if $opt_optimize;
    my $makevars;
    if ($gccupc) {
        $makevars = "USE_GCCUPC_COMPILER=yes GCCUPC=\"$trans\"";
        $detect_upc_flags .= " -b"; # use 'both' C and UPC pragmas for gccupc
        $xtraflags .= " -fupc-pthreads-model-tls" if $opt_pthreads;
        # GCC/UPC requires -fupc-threads, even for preprocess
        $xtraflags .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;
        # TODO: Need? Specifies default # of pthreads: checked by gccupc
        #$xtraflags .= " -fupc-pthreads-per-process-$opt_pthreads"
        #    if $opt_pthreads;
        $xtraflags .= " -D__BERKELEY_UPC_ONLY_PREPROCESS__=1";
    } elsif ($cupc) {
        $makevars = "USE_CUPC_COMPILER=yes CUPC=\"$trans\"";
        $detect_upc_flags .= " -b"; # use 'both' C and UPC pragmas for Clang UPC
        # Clang UPC requires -fupc-threads, even for preprocess
        $xtraflags .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;
        $xtraflags .= " -D__BERKELEY_UPC_ONLY_PREPROCESS__=1";
    } else {
        $xtraflags .= " -D__BERKELEY_UPC_FIRST_PREPROCESS__=1";
        $detect_upc_flags .= " -t"; # prefix "THREADS" and "MYTHREAD" in C mode
        $detect_upc_flags .= " -T"; # transform "__thread" to attribute in C mode
    }
    # Append any options provided by user via -Wp (last to override our options)
    $xtraflags .= " @opt_CPP_args" if @opt_CPP_args;

    foreach my $basename (@toPreprocess) {
        my $cfile = "$basename.c";
        my $ifile = "$basename.i";

        # need to add -I with home directory of file (as absolute path), since
        # we compile in temporary directory (for #include "foo.h" to work)
        my $abshome = $origDir{$basename};
        $abshome = "$startdir/$abshome" unless $abshome =~ m|^/|;

        # copy file to temp dir (using '.c' extension)
        my $src = $origPathName{$basename};
        my $dst = ">$tmp/$cfile";
        open (SRC, $src) or die "Can't open '$src'\n";
        open (DST, $dst) or die "Can't open '$dst'\n";
        if ($gccupc||$cupc) {
            # NOTE: we need upcr.h only for the ctuple strings to expand: we
            # could move relevant macros into separate .h files
            print DST "#include <upcr.h>\n";
            print DST "#line 1 \"$src\"\n";
            print DST while <SRC>;
            # embed config strings in UPC source, so gccupc will compile them in
            # HACK: use "trans.c" in ctuple macros when that's what we usually
            # do when !gccupc.  Otherwise our fragile ctuple voodoo barfs.
            print DST get_ctuple_macros("$basename.o", "$basename.trans.c");
        } else {
	    # DOB: UPC spec requires MYTHREAD and THREADS be available without upc.h
	    # PHH: pragmas allow detect-upc to remove these lines
	    #      if the top-level file is found to actually be C.
	    print DST "#pragma upc start_upc_only\n";
	    print DST "extern const int MYTHREAD;\n";
	    print DST "extern const int THREADS;\n" unless ($opt_threadcount);
            print DST "#if defined(__APPLE__) && defined(__MACH__) && !defined(__INTEL_COMPILER)\n";
            print DST "  #define __asm(X)\n"; # fix for fprintf&friends in XCode tools 2.0+
            print DST "  #if __APPLE_CC__ >= 5026\n"; # fix for OS{Read,Write}SwapInt{16,32} in XCode tools 2.1+
            print DST "    #define volatile(...)\n";
            print DST "    #if __APPLE_CC__ >= 5247\n";
            print DST "      #define __asm__(...)\n"; 
            print DST "    #else\n";
            print DST "      #define __asm__\n"; 
            print DST "    #endif\n";
            print DST "  #endif\n";
            print DST "#endif\n";
	    print DST "#pragma upc end_upc_only\n";
            print DST "#include <upcr_config.h>\n"; # support logic in portable_platform.h
            print DST "#include <portable_platform.h>\n"; # support logic in upcr_geninclude/*.h
	    print DST "#ifdef __MTA__\n"; # define compiler-specific types used in headers
	    print DST "  #define __short16 short\n";
	    print DST "  #define __short32 short\n";
	    print DST "  #define __int64 int\n";
	    print DST "  #define __sync\n";
	    print DST "#endif\n";
            print DST "#ifdef PLATFORM_COMPILER_SUN\n";
            print DST "  #pragma error_messages(off, E_INC_USR_INC_MAY_NOT_PORTABLE)\n";
            print DST "  #include <stdint.h>\n"; # suck in inttypes early to workaround a buggy sys/types.h on Linux which omits int64_t
            print DST "#endif\n";
	    print DST "#line 1 \"$src\"\n";
            print DST while <SRC>;
        }
	close(SRC);
	close(DST);

        # Run backend C compiler's preprocessor on UPC code: use makefile
        # framework to get appropriate -D flags
        my $cmd = $gmake_upcc
             . qq| EXTRA_CPPFLAGS="$extra_cppflags -I\'$abshome\' $xtraflags"|
             . qq| UPCPPP_INCLUDEDIRS="$Ipaths -I '$abshome'"|
             . qq| DETECT_UPC_FLAGS="$detect_upc_flags"|
             . qq| UPCR_CONDUIT=$opt_network UPCR_PARSEQ=$parseq $makevars|
             . qq| PREPROCNAME='$cfile'|
             . qq| ORIGNAME='$origPathName{$basename}' '$ifile'|;
        runCmd($cmd, "error during preprocessing", $tmp); 

        # dump to stdout if -E passed
        if ($opt_preprocessonly) {
            open(PREPROC, "$tmp/$ifile") or die "failed to open '$ifile': $!\n";
            while (<PREPROC>) {
                print $_;
            }
            close(PREPROC);
        }

        # save copy in working dir if -save-temps
        if ($opt_save_temps) {
            runCmd("cp \'$tmp/$ifile\' \'$startdir\'", 
                "error while moving preprocessor output from temporary directory");
        }

        # get rid of .c file we copied to (else in 'compile' step make will pick
        # .c file instead of .i file when gccupc used).
        $cmd = "rm -f '$tmp/$cfile'";
        runCmd($cmd, "Error deleting temporary C file during preprocessing", $tmp);
    }
}

# This is a "preprocessonly" to support use of -E
sub do_preprocess_cupc2c
{
    # clang-upc2c does not handle "-E" option. We need to use clang-upc.
    my $preproc = $conf{clang_upc};
    $preproc =~ s!^\$prefix/!$prefix/!; # handle prefix-relative setting
    die "-E is not supported in this build (no clang-upc)\n" if ($preproc eq 'no');

    # Additional clang-upc options
    my $xtraflags = get_cupc2c_cppflags();

    stagemsg("PREPROCESS CLANG-UPC2C");

    foreach my $basename (@toPreprocess) {
        my $src = $origPathName{$basename};
        my $abshome = $origDir{$basename};
        $abshome = "$startdir/$abshome" unless $abshome =~ m|^/|;

        # Run Clang based preprocessor and send output to STDOUT
        my $cmd = $gmake_upcc
                . qq| do-preproc PREPROC="$preproc -x upc"|
                . qq| EXTRA_CPPFLAGS="$extra_cppflags -I\'$abshome\' $xtraflags"|
                . qq| I_OR_ISYSTEM=isystem|
                . qq| SRC='$src'|;
        print runCmd($cmd, "error during preprocessing", undef, 1);
    }
}


sub create_sizes_file
{
    my ($sizesfile) = @_;
    #my $upc_header_dir = "$upcr_include_src/upcr_preinclude";
    # bug1443 - use substring match to prevent mismatches due to non-unique absolute paths
    my $upc_header_dir = "/upcr_preinclude/"; 
    open(SIZES, ">$sizesfile") or die "can't create '$sizesfile' for writing\n";
    my $idstr = "Generated on $conf{configure_system} ($conf{configure_tuple}) at ".scalar(localtime())." by $ENV{USER}";
    print SIZES <<"EOF";
# This file is passed from upcc to the UPC-to-C translator, to provide type size
# and consistency information
# $idstr
shared_ptr          $translator_typesizes{shared_ptr}
alignof_shared_ptr  $translator_typesizes{alignof_shared_ptr}
pshared_ptr         $translator_typesizes{pshared_ptr}
alignof_pshared_ptr $translator_typesizes{alignof_pshared_ptr}
mem_handle          $translator_typesizes{mem_handle}
alignof_mem_handle  $translator_typesizes{alignof_mem_handle}
reg_handle          $translator_typesizes{reg_handle}
alignof_reg_handle  $translator_typesizes{alignof_reg_handle}
void_ptr            $translator_typesizes{void_ptr}
alignof_void_ptr    $translator_typesizes{alignof_void_ptr}
ptrdiff_t           $translator_typesizes{ptrdiff_t}
alignof_ptrdiff_t   $translator_typesizes{alignof_ptrdiff_t}
char                $translator_typesizes{char}
alignof_char        $translator_typesizes{alignof_char}
int                 $translator_typesizes{int}
alignof_int         $translator_typesizes{alignof_int}
short               $translator_typesizes{short}
alignof_short       $translator_typesizes{alignof_short}
long                $translator_typesizes{long}
alignof_long        $translator_typesizes{alignof_long}
longlong            $translator_typesizes{longlong}
alignof_longlong    $translator_typesizes{alignof_longlong}
float               $translator_typesizes{float}
alignof_float       $translator_typesizes{alignof_float}
double              $translator_typesizes{double}
alignof_double      $translator_typesizes{alignof_double}
longdouble          $translator_typesizes{longdouble}
alignof_longdouble  $translator_typesizes{alignof_longdouble}
size_t              $translator_typesizes{size_t}
alignof_size_t      $translator_typesizes{alignof_size_t}
_Bool               $translator_typesizes{_Bool}
alignof__Bool       $translator_typesizes{alignof__Bool}
# alignof_*_1st nonzero only if struct with given type as 1st field needs exceptional alignment
alignof_dbl_1st                $dbl_1st_struct_align 
alignof_int64_1st              $int64_1st_struct_align 
alignof_sharedptr_1st          $sharedptr_1st_struct_align 
alignof_psharedptr_1st         $psharedptr_1st_struct_align 
# alignof_*_innerstruct nonzero only if struct with given type as 1st field still gets
# exceptional alignment when that struct is enclosed in another struct
alignof_dbl_innerstruct        $dbl_inner_struct_align 
alignof_int64_innerstruct      $int64_inner_struct_align 
alignof_sharedptr_innerstruct  $sharedptr_inner_struct_align 
alignof_psharedptr_innerstruct $psharedptr_inner_struct_align 
# exception to previous exception
alignof_struct_promote         $struct_promote
maxblocksz          $maxblocksz
UPCRConfig          $upcrlib_ctuple
GASNetConfig        $gasnetlib_ctuple
runtime_spec        $spec_major.$spec_minor
upc_header_dir      $upc_header_dir
use_type_interface  0
EOF
    if ($opt_verbose) {
      print SIZES "system_header_dirs  :\n";
    } else {
      my $dirs = ":$conf{system_header_dirs}:";
      $dirs =~ s/::/:/g;
      print SIZES "system_header_dirs  $dirs\n";
    }
    close (SIZES);
}
# resolve a (hostname, portname)
# returns a priority-ordered array of references to [IP,port,hostname]
sub resolve_host {
    my ($hostname,$hostport,$recurse) = @_;
    my @iaddrs;
    if ($hostname =~ m/[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+/) { # simple IP address, skip resolution
      $hostport = 80 unless ($hostport > 0); # default port is 80
      my $tmp = inet_aton($hostname) || die "Cannot resolve host: $hostname";
      $iaddrs[0] = [$tmp,$hostport,$hostname];
    }
    if (!$recurse) { # bug 1528: start with a SRV query against the given name
      my $dig = verify_exec($conf{dig}, $conf{exe_suffix}, 1); # dig is optional
      my $nslookup = verify_exec($conf{nslookup}, $conf{exe_suffix}, 1); # nslookup is optional

      if (!$iaddrs[0] && $dig) { # try dig command
        my $cmd = "$dig SRV +search +ndots=3 _http._tcp.$hostname";
        my $res = `$cmd 2>&1`;
        #print "$res\n"; 
	foreach my $line (split(/\n/,$res)) {
	  if ($line =~ m/^\s*\S+\s+\S+\s+IN\s+SRV\s+(\d+)\s+(\d+)\s+(\d+)\s+(\S+)\s*$/i) {
	    my ($priority,$weight,$port,$target) = ($1,$2,$3,$4);
	    $target =~ s/\.$//; # remove trailing dot
	    #print "$priority,$weight,$port,$target\n";
	    $port = $hostport if ($hostport > 0); # user can override port in SRV record
	    foreach my $srv (resolve_host($target,$port,1)) {
	      push(@iaddrs, [$$srv[0],$$srv[1],$target,$priority]);
	    }
	  }
	}
	@iaddrs = sort { $$a[3] cmp $$b[3] } @iaddrs if (@iaddrs); # priority sort
      }
      if (!$iaddrs[0] && $nslookup) { # try nslookup command
        my $cmd = "$nslookup -type=SRV _http._tcp.$hostname";
        my $res = `$cmd 2>&1`;
	# nslookup on Tru64, AIX and MSWindows wraps lines, so unwrap them (using indentation as a guide)
	$res =~ s/\r?\n[\t ]+/ /mg;
        #print "$res\n";
        foreach my $line (split(/\n/,$res)) {
          if ($line =~ m/^\s*\S+\s+service\s*=\s*(\d+)\s+(\d+)\s+(\d+)\s+(\S+)\s*$/i # recent nslookup
	   || $line =~ m/\s+priority\s*=\s*(\d+),?\s*weight\s*=\s*(\d+),?\s*port\s*=\s*(\d+),?\s*(?:host|svr hostname)\s*=\s*(\S+)/i # old nslookup
	     ) {
            my ($priority,$weight,$port,$target) = ($1,$2,$3,$4);
	    $target =~ s/\.$//; # remove trailing dot
            #print "$priority,$weight,$port,$target\n";
	    $port = $hostport if ($hostport > 0); # user can override port in SRV record
            foreach my $srv (resolve_host($target,$port,1)) {
              push(@iaddrs, [$$srv[0],$$srv[1],$target,$priority]);
            }
          }
        }
        @iaddrs = sort { $$a[3] cmp $$b[3] } @iaddrs if (@iaddrs); # priority sort
      }
    }
    if (!$iaddrs[0]) { # SRV query failed, fall back to regular A/CNAME lookup
      $hostport = 80 unless ($hostport > 0); # default port is 80
      my @he = gethostbyname($hostname);
      if (@he) {
        @iaddrs = map { [$_, $hostport, $hostname] } @he[4..$#he];
      }
    }
    unless ($iaddrs[0]) { # last hope
      my $tmp = inet_aton($hostname);
      $iaddrs[0] = [$tmp,$hostport,$hostname] if ($tmp);
    }
    if (!$recurse) {
      die "Cannot resolve host: $hostname" unless ($iaddrs[0]);
      verbose("*** Resolved $hostname to: ". join(", ",map { join(".",unpack('C4',$$_[0])).":".$$_[1]."[".$$_[2]."]" } @iaddrs));
    }
    return @iaddrs;
}

################################################################################
## Compile UPC source code into C output (.upc|.c -> .trans.c)
################################################################################
sub do_translate
{
    return if $gccupc||$cupc;

    stagemsg("TRANSLATING") unless $at_remote;

    # Some of the translator's failure modes include grabbing ridiculous 
    # amounts of memory before eventually crashing - this causes all sorts
    # of bad swapping behavior and annoys admins, so cut it off early
    my $hush = " > /dev/null 2>&1";
    my $reslimit = "ulimit -v 524288 $hush ; ulimit -d 524288 $hush ; ulimit -m 524288 $hush ;\n";

    # base invocation string for upc compiler
    my $upc_compilebase = "$reslimit$trans/driver.nue/sgiupc -noinline -S -keep "
	 . "-Yf,$trans/gccfe -Yb,$trans/be ";
    $upc_compilebase .= " -save-temps" if $opt_save_temps;
    $upc_compilebase .= " -ia$arch_size" if $arch_size == 32;
    $upc_compilebase .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;
    $upc_compilebase .= " @opt_UPC_args" if @opt_UPC_args;
    $upc_compilebase .= " -show -v" if $opt_verbose > 1;
    $upc_compilebase .= " -Wb,-trlow -Wb,-tropt" if $opt_save_all_temps;
    $upc_compilebase .= " -fconfig-$sizesfile";
    $upc_compilebase .= " -g2" if $opt_totalview;

    # whirl-to-C translator
    my $whirl2c_base = "$reslimit$trans/whirl2c/whirl2c -lang=upc -std=upc";
    $whirl2c_base .= " -TARG:abi=ia$arch_size" if $arch_size == 32;
    $whirl2c_base .= " -pthreads" if $opt_pthreads;
    $whirl2c_base .= " @opt_W2C_args" if @opt_W2C_args;
    $whirl2c_base .= " -v" if $opt_verbose > 1;
    $whirl2c_base .= " -g2" if $opt_totalview;
    $whirl2c_base .= " -CLIST:emit_linedirs" if $opt_lines;

    # create temporary sizes file to give to the translator
    unless ($opt_ssh_remote || $opt_http_remote) {
        if ($opt_sizes_file) { # use a 'canned' sizes file
          my $cmd = "cp \'$sizesfile\' $tmp/upcc-sizes";
          runCmd($cmd, "error copying sizesfile: $!");
         # $sizesfile =~ s@^.*?/([^/]+)$@$1@;
          $sizesfile = "upcc-sizes";
        } else {
          create_sizes_file("$tmp/$sizesfile");
        }
    }

    if ($use_nettrans_http) {
	my @iaddrs = resolve_host($nettrans_host,$nettrans_http_port);
        my $request_tar = "$tmp/http_request.tar";
        my $reply_tar = "$tmp/http_reply.tar";
        my $http_err = "httpcompile.err";
        my $http_out = "httpcompile.out";
        my $request_files = "*.i $sizesfile";
        my $boundary = "---------------------------20162983320442174861929795759";
        my $tar   = verify_exec($conf{tar}, $conf{exe_suffix});
        my $gzip;
	$opt_http_compress = 0 if ($opt_http_compress < 0);
	$opt_http_compress = 9 if ($opt_http_compress > 9);
        if ($opt_http_compress) {
          $gzip = verify_exec($conf{gzip}, $conf{exe_suffix}, 1); # gzip is optional
        }
        if ($gzip) {
	  $request_tar .= ".gz";
	  $reply_tar .= ".gz";
          my $cmd = "( $tar cf - $request_files | $gzip -c -$opt_http_compress > $request_tar )"; 
          runCmd($cmd, "error making compressed tar file for HTTP request", $tmp);
	} else {
	  $opt_http_compress = 0;
          my $cmd = "$tar cf $request_tar $request_files"; 
          runCmd($cmd, "error making tar file for HTTP request", $tmp);
        }

        # construct multipart/form-data HTTP request 
        my $http_req_body  = multipart_form_text("archsize", 
                                                 $arch_size, $boundary);
        $http_req_body .= multipart_form_text("network", $opt_network ,
                                              $boundary);
        $http_req_body .= multipart_form_text("verbose", 
                              ($opt_verbose ? $opt_verbose : '0'), $boundary);

        if ($opt_threadcount) {
            $http_req_body .= multipart_form_text("threads", $opt_threadcount,
                                                  $boundary);
        }
        if ($opt_totalview) {
            $http_req_body .= multipart_form_text("opt_tv", $opt_totalview,
                                                  $boundary);
            # Pass old 'debug', in case we're using an older upcc.cgi script
            $http_req_body .= multipart_form_text("debug", $opt_totalview,
                                                  $boundary);
        }
        if ($opt_debug) {
            $http_req_body .= multipart_form_text("opt_g", $opt_debug,
                                                  $boundary);
        }
        if ($opt_pthreads) {
            $http_req_body .= multipart_form_text("pthreads", $opt_pthreads,
                                                  $boundary);
        }
        if ($opt_http_compress) {
            $http_req_body .= multipart_form_text("compress", $opt_http_compress,
                                                  $boundary);
        }
        if (defined $opt_lines) {
            $http_req_body .= multipart_form_text("lines", $opt_lines, $boundary);
        }
        if ($opt_save_all_temps) {
            $http_req_body .= multipart_form_text("temps", 'yes', $boundary);
        }
        for (@opt_UPC_args) {
            $http_req_body .= multipart_form_text("upcargs", $_, $boundary);
        }
        for (@opt_W2C_args) {
            $http_req_body .= multipart_form_text("w2cargs", $_, $boundary);
        }
        $http_req_body .= multipart_form_file("infile", $request_tar, $boundary);

        $http_req_body .= "--$boundary--\r\n";

        my $length = length($http_req_body);

        # ignore sigpipe signals if anything goes wrong--catch at close()
        $SIG{PIPE} = 'IGNORE';

	my ($connected, $posthost, @connecterrs);
	my $retries = $conf{"http_retry"};
	$retries = 1 if ($retries < 1);
	my $retry = 1;
	retry_loop:
	for ( ; $retry <= $retries; $retry++) {
          foreach my $iaddr_full (@iaddrs) {
	    my ($iaddr,$iport,$ihost) = @$iaddr_full;
	    my $iaddrstr = ($proxy?'proxy ':'').join(".",unpack('C4',$iaddr)).":".$iport;
            my $paddr = sockaddr_in($iport, $iaddr)
              or die "Bad host/port: $iaddr:$iport";
            verbose("*** Making HTTP request to $trans ($iaddrstr)");
            # open socket to host
            socket(SOCK, PF_INET, SOCK_STREAM, (getprotobyname('tcp'))) 
              or die "Error creating socket for HTTP translation: $^E";
            if (connect(SOCK,$paddr)) {
	      $connected = 1;
	      $posthost = "$ihost:$iport";
	      $retry++;
	      last retry_loop;
	    } else {
              verbose("*** Failed connection to $trans at $iaddrstr: $^E");
	      push(@connecterrs, $^E) unless($connecterrs[0] == $^E);
	    }
	  }
          if (!$connected && $retry < $retries) {
            verbose("*** Pausing before retry ".($retry+1));
	    sleep 5;
	  }
	}
	$connected
          or die "Can't connect to $trans: ".join(", ",@connecterrs)."\n";

        my $http_req_head  = 
                 "POST $nettrans_http_path HTTP/1.0\r\n"
               . "Host: $posthost\r\n"
               . "User-Agent: upcc.pl\r\n"
               . "Content-Type: multipart/form-data; boundary=$boundary\r\n"
               . "Content-Length: $length\r\n\r\n";

        my $oldfh = select SOCK; $| = 1; select $oldfh; # unbuffer socket I/O

        # send HTTP request
        print SOCK "$http_req_head", "$http_req_body";

        # parse out exit code from reply headers, and untar reply
        open (REPLY_TAR, ">$reply_tar") 
            or die "Couldn't open $reply_tar for writing";
        my $upcc_exit;
        my $line = <SOCK>;
	if (!defined $line) { 
	  # occasionally, the connection may break or be dropped while we're
	  # uploading the request, with no output from the server.
	  # if that happens, treat it as a connection failure and initiate retry
	  $connected = 0;
	  my $reason = "Connection broken or server misconfigured";
          verbose("*** $reason while contacting $posthost");
	  push(@connecterrs, $reason) unless($connecterrs[0] == $reason);
          verbose("*** Pausing before retry $retry");
	  sleep 5;
	  goto retry_loop;
	}
        unless ($line =~ m!^HTTP/1.\d\s+200!) {
            $line =~ s!^HTTP/1.\d\s+!!;
            die "HTTP error: $trans $line";
        }
	my $contenttype = undef;
        while ($line = <SOCK>) {
            if ($line =~ m@^X-upcc-exit:\s*(\S+)@) {
                $upcc_exit = $1;
            } elsif ($line =~ m/^Content-type:\s*(\S+)/i) {
	        $contenttype = $1;
		chomp($contenttype);
	    } elsif ($line =~ /^\s*$/) {
	        # end of headers and beginning of HTTP contents
                last;
            }
        }
        unless (defined $upcc_exit) {
            die "Error: $trans not returning X-upcc-exit header\n";
        }
        unless (defined $contenttype) {
            die "Error: $trans not returning Content-type header\n";
        }
	if ($contenttype =~ "^text/plain") {
	    my $errmsg = "";
	    while (<SOCK>) { $errmsg .= $_; }
            die "error while contacting $trans:\n$errmsg";
	}
        print REPLY_TAR while <SOCK>;
        close SOCK or die "error during HTTP request: $!\n";
        close REPLY_TAR; 
        $SIG{PIPE} = 'DEFAULT';

        die "Error: empty HTTP reply from $trans\n" unless -s $reply_tar;
        if ($opt_http_compress) {
          $reply_tar =~ s/\.gz$//;
          my $cmd = "( $gzip -d -c $reply_tar.gz > $reply_tar )";
          runCmd($cmd, "Error decompressing reply tarball", $tmp, 1);
        }
        # some versions of tar (like GNU tar) exit OK even on non-tar file:
        # so demand a file listing and check it to see if tar file is OK
        my $cmd = "$tar tvf $reply_tar";
        my $listing = `$cmd 2>/dev/null`;
        if ($listing !~ /httpcompile.out/) {
            # assume CGI script failed before tarball: read contents as error
            open(ERRORS, $reply_tar) or die "Can't open $reply_tar\n";
            my $oldsep = $/;
            undef $/;
            my $errs = <ERRORS>;
	    close(ERRORS);
            die "Error during remote HTTP translation:\n$errs\n";
        }
        $cmd = "$tar xf $reply_tar";
        runCmd($cmd, "Error extracting reply tarball", $tmp, 1);

        # update timestamp, in case remote computer's clock faster than ours
        for (glob("$tmp/*.trans.c")) {
            fix_line_directives($_);
        }
        if (glob("$tmp/*.i")) {
            $cmd = "touch *.i";
            runCmd($cmd, "error touching *.i files", $tmp);
        }

        if ($upcc_exit) {
            print STDERR "Error during remote HTTP translation:\n";
            open(REMOTE_LOG, "$tmp/$http_out")
                or die "Output log from HTTP translation is missing\n";
            print STDERR while (<REMOTE_LOG>);
            close REMOTE_LOG; 
            open(REMOTE_LOG, "$tmp/$http_err")
                or die "Error log from HTTP translation is missing\n";
            my $oldslash = $/; undef $/;
            my $err = <REMOTE_LOG>;
            $/ = $oldslash;
            close REMOTE_LOG; 
            $err =~ s/^upcc: //;
            die "$err\n";
        } elsif ($opt_verbose) {
            open(REMOTE_LOG, "$tmp/$http_out")
                or die "Output log from HTTP translation is missing\n";
            print while (<REMOTE_LOG>);
            close REMOTE_LOG; 
	}
        # always print stderr contents (may contain non-fatal compiler warnings)
        open(REMOTE_LOG, "$tmp/$http_err")
           or die "Error log from HTTP translation is missing\n";
        my $oldslash = $/; undef $/;
        my $err = <REMOTE_LOG>;
        $/ = $oldslash;
        close REMOTE_LOG; 
        foreach my $re (@warning_blacklist) { $err =~ s/$re//mg; }
        print STDERR $err;
    } elsif ($use_nettrans_ssh && !$opt_ssh_remote) {
        my $tar = verify_exec($conf{tar}, $conf{exe_suffix});
        # base tarball name on tmp dir, to allow concurrent compilations
        my $tar_req = "$rtmp_req.tar";
        my $tar_rep_raw = "$rtmp_rep.tar.raw"; # contains cut marks and other stray output
        my $tar_rep = "$rtmp_rep.tar";
        my $net_err = 'nettrans_ssh.err';
        my $net_out = "nettrans_ssh.out";
        my $hush  = ">/dev/null";

        # make tarball to send to remote node: use different directory name for
        # tarball, in case user is doing nettrans_ssh to local node.
        if (-d "$TMPDIR/$rtmp_req") {
            die "temporary directory '$TMPDIR/$rtmp_req' already exists!\n";
        }
        if (-d "$TMPDIR/$rtmp_rep") {
            die "temporary directory '$TMPDIR/$rtmp_rep' already exists!\n";
        }
        if (-f "$TMPDIR/$rtmp_req.tar") {
            die "temporary fail '$TMPDIR/$rtmp_req.tar' already exists!\n";
        }
        if (-f "$TMPDIR/$rtmp_rep.tar") {
            die "temporary file '$TMPDIR/$rtmp_rep.tar' already exists!\n";
        }
        my $cmd = "cp -r \'$tmp\' $TMPDIR/$rtmp_req";
        runCmd($cmd, "error copying temp directory for nettrans_ssh");
        $cmd = "cp $upcr_bin/upcc.pl $upcr_etc/upcc.conf"
                    . " $upcr_include/upcr_ctuple.pl"
                    . " $upcr_include/upcr_getopt.pl"
                    . " $upcr_include/upcr_util.pl"
                    . " $TMPDIR/$rtmp_req";
        runCmd($cmd, "error copying files for nettrans_ssh");
        unless ($opt_norc) {
            my $upccrc = userconfig();
            $cmd = "cp '$upccrc' $TMPDIR/$rtmp_req/.upccrc";
            runCmd($cmd, "error copying config file '$upccrc' for nettrans_ssh") if (-e $upccrc);
        }
        $cmd = "$tar cf \'$tmp/$tar_req\' $rtmp_req";
        runCmd($cmd, "error making tar file for nettrans_ssh", "$TMPDIR");

        # Run translator on remote side, communicating via tarballs:
        # Recursive call to this script on remote machine executes the code
        # in the bottom branch, below.  
        foreach my $basename (@toTranslate) {
            push @nettrans_ssh_ARGV, "$basename.i"; 
	}

        # escape all quotes that may be in @nettrans_ssh_ARGV
        my $quoted_ARGV = "@nettrans_ssh_ARGV";
	my $cut_mark = "BERKELEY_UPC_CUT_MARK_"; # MUST be fragmented to prevent false positive matches while sending this script
        #$quoted_ARGV =~ s/(["])/\\$1/g;
        #$quoted_ARGV =~ s/'/'"'"'/g;
        my $ssh = verify_exec($conf{ssh},$conf{exe_suffix});
        $cmd = <<EOF;
$ssh -a -x -e none $nettrans_host \\
    /bin/sh -c \\
    "'"'umask 077 && cat >$conf{remote_tmpdir}/$tar_req && \\
        cd $conf{remote_tmpdir} $hush && \\
        tar xf $tar_req $hush 2>/dev/null && \\
        cd $rtmp_req $hush && \\
        perl ./upcc.pl -at-remote-ssh -trans $quoted_ARGV -network $opt_network >$net_out && \\
        cd $conf{remote_tmpdir} $hush && \\
        mv -f $rtmp_req $rtmp_rep $hush && \\
        tar cf $tar_rep $rtmp_rep $hush 2>/dev/null && \\
	echo ${cut_mark}BEGIN && \\
        cat $tar_rep && \\
	echo ${cut_mark}END ; \\
        exitcode=\$?; \\
        cd $conf{remote_tmpdir} $hush && rm -rf $tar_req $tar_rep $rtmp_req $rtmp_rep $hush; \\
        exit \$exitcode'"'"
EOF
        chomp $cmd;
        verbose($cmd);
        open (TARBALL, "$tmp/$tar_req") 
            or die "Can't open temporary file '$tmp/$tar_req'\n";
        # open(HANDLE, "| cmd") returns OK if fork() succeeds, i.e., it doesn't
        # tell if command ran OK or not.  Ignore SIGPIPE if we write to
        # bad/exited command, and instead capture via checking close() exit
        # value.
        $SIG{PIPE} = 'IGNORE';
        eval {
            open (SSH, "| $cmd >\'$tmp/$tar_rep_raw\' 2>\'$tmp/$net_err\'") 
                or die "nettrans_ssh: error while running \n  $cmd\n";
            print SSH $_ while(<TARBALL>);
            close TARBALL;
            close SSH;  # closing piped command does wait() and sets $?
            if ($?) {
                my $extra = '';
                if ( open (TARBALL_RAW, "$tmp/$tar_rep_raw") ) {
                    local $/;
                    my $tarball = <TARBALL_RAW>; # slurp!
                    if ($tarball =~ m/^(.*?)${cut_mark}BEGIN\n(.*?)${cut_mark}END\n(.*?)$/s) {
                        $extra = "$1$3";
                        chomp($extra);
                    }
                 }
                die "nettrans_ssh: error while running \n  $cmd\n$extra";
            }
        };
        if ($@) {
            my $diemsg = $@;
            if (open(ERRFILE, "$tmp/$net_err")) {
                $diemsg .= $_ while <ERRFILE>;
                close(ERRFILE);
            }
            die $diemsg;
        } else { # always print stderr contents (may contain non-fatal compiler warnings)
            open(ERRFILE, "$tmp/$net_err")
		or die "Failed to open netcompile error log.\n";
            my $oldslash = $/; undef $/;
            my $err = <ERRFILE>;
            $/ = $oldslash;
            close ERRFILE; 
            foreach my $re (@warning_blacklist) { $err =~ s/$re//mg; }
            print STDERR $err;
	}
        $SIG{PIPE} = 'DEFAULT';
	# unpack output tarball - trim extraneous output (from ssh login) at cutmarks
        open (TARBALL_RAW, "$tmp/$tar_rep_raw") 
            or die "Can't open temporary file '$tmp/$tar_rep_raw'\n";
        open (TARBALL, ">$tmp/$tar_rep") 
            or die "Can't open temporary file '$tmp/$tar_rep'\n";
    	my $oldslash = $/; undef $/;
    	my $tarball = <TARBALL_RAW>; # slurp!
    	$/ = $oldslash;
    	if ($tarball =~ m/^(.*?)${cut_mark}BEGIN\n(.*?)${cut_mark}END\n(.*?)$/s) {
      	  my $extra = "$1$3";
      	  print TARBALL $2;
      	  chomp($extra); 
      	  verbose("*** upcc ignoring extraneous ssh output: $extra") if ($extra);
    	} else {
      	  die "Missing cut marks in ssh-netcompile response tarball\n";
    	}
	close TARBALL_RAW;
	close TARBALL;
        # untar results
        $cmd = "$tar xf \'$tmp/$tar_rep\'";
        runCmd($cmd, "error extracting results from nettrans_ssh", "$TMPDIR", 1);
        # touch trans.c file to avoid timestamp error from gmake if remote host's
        # clock is in our future
        for (glob("$TMPDIR/$rtmp_rep/*.trans.c")) {
            fix_line_directives($_);
        }
        if (glob("$tmp/*.i")) {
            $cmd = "touch *.i";
            runCmd($cmd, "error touching *.i files", $tmp);
        }
        # get trans.c files 
        $cmd = "cp *.trans.c " . join(' ', <$TMPDIR/$rtmp_rep/upcr_trans_extra*>) . " \'$tmp\'";
        runCmd($cmd, "error fetching result files from nettrans_ssh", 
               "$TMPDIR/$rtmp_rep", 1);
        if ($opt_verbose) {
            open(REMOTE_LOG, "$TMPDIR/$rtmp_rep/$net_out") 
                or die "Log from nettrans_ssh is missing\n";
            print while (<REMOTE_LOG>);
            close REMOTE_LOG; 
        }
    } else {
        foreach my $basename (@toTranslate) {
	    ## setup shared library search paths for translator
    	    my $dlopenpath = "$trans/be:$trans/wopt:$trans/lno:$trans/ipl:$trans/whirl2c";
       	    print STDERR "*** upcc setting:\n" if $opt_verbose > 1;
    	    for my $var ("LD_LIBRARY_PATH", 	# Linux & others
            	     	 "DYLD_LIBRARY_PATH",	# OSX
                 	 "LIBPATH",          	# AIX
                 	 "LD_LIBRARYN32_PATH",  # IRIX
                 	 "LD_LIBRARY64_PATH",   # IRIX
                 	 "SHLIB_PATH",         	# HPUX
                 	 "LD_LIBRARY_PATH_32",  # Solaris
                 	 "LD_LIBRARY_PATH_64",  # Solaris
                 	) {
		$ENV{$var} = "$dlopenpath".($ENV{$var}?":".$ENV{$var}:"");
        	print STDERR " $var=".$ENV{$var}."\n" if $opt_verbose > 1;
    	    }

            ### Call UPC translator
            my $ifile = "$basename.i";
            my $workdir = $opt_ssh_remote ? "" : $tmp;
            my $compile_cmd = "$upc_compilebase \'$ifile\'";
            runCmd($compile_cmd, 
                   "error during UPC-to-C translation (sgiupc stage)", $workdir);

            ### Call whirl2c
            my $whirl_cmd = "$whirl2c_base '$ifile' '-fB,$basename.N'";
            runCmd($whirl_cmd, 
                   "error during UPC-to-C translation (whirl2c stage)", $workdir);

            ### Create a single .trans.c file out of .w2c.[ch] files
            my $tmpprefix = $opt_ssh_remote ? "" : "$tmp/";
            my $w2hfile = "${tmpprefix}${basename}.w2c.h";
            my $w2cfile = "${tmpprefix}${basename}.w2c.c";
            my $transfile = "${tmpprefix}${basename}.trans.c";
            my $file_mangled = mangle_filename("$basename.o");
            open (W2H,"$w2hfile") 
                or die "Can't open generated file '$w2hfile'\n";
            open (W2C,"$w2cfile") 
                or die "Can't open generated file '$w2cfile'\n";
            open (TRANS,">$transfile") 
                or die "Can't open file '$transfile' for writing\n";
            ### ------------ Rewriting of w2c file  ----------
            ### Translated file header
            # UPCR headers precede all user headers to prevent identifier name capture (bug 905)
            print TRANS <<EOF;
/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
EOF
            my $w2cline = 0;
	    my $extra_idents = "";
	    my $killsrcpos = 0;
            while (<W2C>) {
                $w2cline++;
	        my $patname = $basename;
                # translator emits #lines with temp directory: convert back
                if (/\Q$basename\E\.u?p?c/) {
                    s/^(#[^"]*?)"[^"]*\Q$basename\E\.u?p?c"/$1"$origPathName{$basename}"/;
                }
                # merge w2c.h header into trans.c file
                if (/^\s*#\s*include\s*(?:"|<)\Q$basename\E\.w2c\.h(?:"|>)/) {
                    print TRANS qq|#line 1 "$basename.w2c.h"\n| if $opt_lines;
                    while (<W2H>) { # strip translator-generated includes of our UPCR headers
		      s/\bstruct\s+bupc_mangled_va_list\s*\*/va_list /g; # for bug 137
		      s/\bbupc_mangled_va_listp\b/va_list /g; # for bug 137
                      print TRANS unless (/^#include\s*(?:"|<)(?:upcr|upcr_proxy|whirl2c)\.h(?:"|>)/);
                    }
                } elsif (m@^\s*#\s*include\s*(?:"|<)/.*/(upcr_geninclude/.+)(?:"|>)@) {
		  # Must use *relative* path to our wrappers (bug 1321)
		  print TRANS "#include \"$1\"\n"
                } elsif (/^\s*#\s*pragma\s*(?:pupc|PUPC)\s*(\S+)/) { # GASP support
		  if (uc($1) eq "ON") {
		    print TRANS "#undef UPCR_PRAGMA_PUPC\n#define UPCR_PRAGMA_PUPC 1\n";
                  } elsif (uc($1) eq "OFF") {
		    print TRANS "#undef UPCR_PRAGMA_PUPC\n#define UPCR_PRAGMA_PUPC 0\n";
		  } else {
                    print TRANS; # ignore it
		  }
                } elsif (/^\s*#\s*pragma\s*(?:upcr|UPCR)\s*(\S+)/) {
		  if (uc($1) eq "NO_SRCPOS") {
	            $killsrcpos = 1;
		  } else {
                    print TRANS; # ignore it
		  }
	  	} elsif (/^upcr_startup_(?:p)?shalloc_t (?:p)?info/) { # static shared data tally
	          print TRANS;
                  while (<W2C>) {
                    $w2cline++;
	            print TRANS;
		    if (/{&\s*([A-Za-z0-9_]+)\s*,\s*([0-9]+)\s*,\s*([0-9]+)\s*,\s*([0-9]+)\s*}\s*,/ ||
		        /UPCRT_STARTUP_(?:P)?SHALLOC\s*\(\s*([A-Za-z0-9_]+)\s*,\s*([0-9]+)\s*,\s*([0-9]+)\s*,\s*([0-9]+)(?:\s*,\s*([0-9]+)\s*,\s*"(\S+)")?/) {
			#print "got one: $1 $2 $3 $4\n";
			$extra_idents .= "GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_shareddata_$1,\n";
                        my $more = ($5 ? " $5 $6": "");
			$extra_idents .= " \"\$UPCRStaticSharedData: ($1) $2 $3 $4$more \$\");\n";
		    } else {
			last;
		    }
                  }
                } elsif (/UPC translator version:\s*(.*?)\s*\*\//) {
	          print TRANS;
                  my $trans_version = $1;
                  if ($trans_version =~ m/release\s+(\d+)\.(\d+)\.(\d+)(.*)$/) {
                    my $rest = $4;
                    $trans_version = labeled_version("$1.$2.$3");
                    $trans_version .= $4;
		    $extra_idents .= "GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_transver_$1,\n";
		    $extra_idents .= " \"\$UPCTranslatorVersion: ($basename.o) $trans_version \$\");\n";
                  } else {
                    die "invalid version from translator: '$trans_version'";
                  }
		} elsif (/\bbupc_mangled_va_/) {
		  # Undo name-shifting and stringification used to protect stdarg (bug #137)
		  s/\bbupc_mangled_(va_(end|copy)\s*\()/$1/g;
		  s/\bstruct\s+bupc_mangled_va_list\s*\*/va_list /g;
		  s/\bbupc_mangled_va_listp\b/va_list /g;
		  my $line = '';
		  while (/(.*?)\b(bupc_mangled_va_(start|arg)\s*\(\s*)(.*)/s) {
		    my $kind = $3;
		    $line .= $1;
		    $_ = $4;
		    # find the closing ')' and work backwards to locate start/end of string:
		    # $rp is index of right-hand ')' character
		    # $rq is index of right-hand '"' character
		    # $lq is index of left-hand '"' character
		    my ($rp, $count) = (0, 1);
		    foreach my $c (split '') {
		      if ($c eq '(') {
		        $count++;
		      } elsif ($c eq ')') {
		        $count--;
		      }
		      $rp++;
		      last unless ($count);
		    }
		    my $rq = rindex($_, '"', $rp);
		    my $lq = rindex($_, '"', $rq-1);
		    if ($count || ($rq < 0) || ($lq < 0)) {
		      # Failed to parse, let this instance go unmodified
		      $line .= $2;
		    } elsif ($kind eq 'start') {
		      $line .= 'va_start(';
		      substr($_, $rq, 1) = '';
		      substr($_, $lq, 1) = '';
		    } else {
		      # Not 'va_start', so must be 'va_arg'
		      my $comma = index($_, ',', $rq); # The comma between type and ptr
		      if ($comma < 0) {
		        # Failed to parse, let this instance go unmodified
		        $line .= $2;
		      } else {
		        my $ap = substr($_, 0, $lq); # includes trailing ','
		        my $type = substr($_, $lq+1, $rq-($lq+1));
		        my $ptr = substr($_, $comma+1, $rp-($comma+1)); # Includes trailing ')'
			if (" $type " =~ m/[^A-Za-z0-9_]shared[^A-Za-z0-9_]/) { # type includes shared qualifier
			  if ($type =~ m/shared\s*(\[[^\]]*\])?[^\*]*\s*\*\s*[^\*]*$/) {
			    my $blockf = $1;
			    if ((!$blockf && !(" $type " =~ m/[^A-Za-z0-9_]void[^A-Za-z0-9_]/)) ||
                                $blockf =~ m/\[\s*(0|1)?\s*\]/) {
                              $type = "upcr_pshared_ptr_t";
			    } else {
                              $type = "upcr_shared_ptr_t";
			    }
	                  } else { # other uses of shared must be a pointer component type
			    $type = "void *";
			  }
                        }
		        $line .= "(*(${ptr}=va_arg(${ap}${type}))";
		        substr($_, 0, $rp) = '';
		      }
		    }
		  }
		  $line .= $_;
		  print TRANS $line;
                } else {
                    print TRANS;
                }
            }
            close (W2C);
            close (W2H);

            ### append ctuple strings for configuration consistency checks
	    my $now = localtime;
	    (my $save_ARGV_string = join ' ', @save_ARGV) =~ s/(["\\])/\\$1/g;
            # use separate config strings for trans.c and .o, so we can catch
            # inconsistent settings across 'upcc -trans foo.upc' and 
            # 'upcc -c foo.trans.c' invocations
            print TRANS get_ctuple_macros("$basename.o", $transfile);
	    print TRANS $extra_idents;
            close(TRANS);

	    if ($killsrcpos) { # profiling support - allow upc files to indivudually suppress srcline support
              runCmd("mv -f '$transfile' '$transfile.tmp'", "error applying #pragma UPCR NO_SRCPOS");
              open (TRANSORIG,"<$transfile.tmp")
                or die "Can't open file '$transfile.tmp' for reading: $!\n";
              open (TRANS,">$transfile")
                or die "Can't open file '$transfile' for writing: $!\n";
              print TRANS "#define UPCR_NO_SRCPOS\n";
	      while (<TRANSORIG>) { print TRANS; }
              close (TRANSORIG);
              close (TRANS);
	      unlink "$transfile.tmp" or die "Failed to delete '$transfile.tmp': $!\n";
            }
        }
    }
    if ($opt_ssh_remote) {
        clean_up();
        exit(0);
    }

    unless ($opt_http_remote || $opt_ssh_remote) {
        foreach my $basename (@toTranslate) {
            validate_spec_version("$tmp/$basename.trans.c");
            add_totalview_tcl("$tmp/$basename.trans.c", $origPathName{$basename});
        }
    }

    if ($opt_save_temps || $opt_translateonly) {
        foreach my $basename (@toTranslate) {
            my $transfile = "$basename.trans.c";  
            my $cmd;
            if ($opt_translateonly && $opt_outputname) {
                $cmd = "cp \'$tmp/$transfile\' \'$opt_outputname\'";
            } else {
                $cmd = "cp \'$tmp/$transfile\' \'$startdir\'";
            }
            runCmd($cmd, 
                "error while moving translator output from temporary directory");
        }
    }
    if ($opt_http_remote) {
       foreach my $trans_extra_file (<$tmp/upcr_trans_extra*>) {
            my $cmd = "cp \'$trans_extra_file\' \'$startdir\'";
            runCmd($cmd, "error while moving translator output from temporary directory");
       }
    }
}

sub do_translate_cupc2c
{
    # Additional clang-upc2c options
    my $xtraflags = get_cupc2c_cppflags();

    $xtraflags .= ' -g' if $opt_debug;
    $xtraflags .= ' -O' if $opt_optimize;
    $xtraflags .= ' -v' if $opt_verbose > 1;
    $xtraflags .= ' -P' unless $opt_lines;
    $xtraflags .= " -pthread" if $opt_pthreads;

    # It seems that warning on unused arguments is clang specific:
    $xtraflags .= ' -Qunused-arguments';

    # Append any options provided by user via  -Ww or -Wu
    $xtraflags .= " @opt_UPC_args" if @opt_UPC_args;
    $xtraflags .= " @opt_W2C_args" if @opt_W2C_args;

    stagemsg("TRANSLATE CLANG-UPC2C");

    foreach my $basename (@toTranslate) {
        my $src = $origPathName{$basename};
        my $dst = "${tmp}/${basename}.trans.c";
        my $abshome = $origDir{$basename};
        $abshome = "$startdir/$abshome" unless $abshome =~ m|^/|;

        # Run Clang based translator
        my $cmd = $gmake_upcc
                . qq| do-trans TRANS="$trans -x upc"|
                . qq| EXTRA_CPPFLAGS="$extra_cppflags -I\'$abshome\' $xtraflags"|
                . qq| I_OR_ISYSTEM=isystem|
                . qq| SRC='$src' DST='${dst}.tmp'|;
        runCmd($cmd, "error during UPC-to-C translation");

        open(TRANSTMP, "<${dst}.tmp") or die "Could not open ${dst}.tmp for reading.";
        open(TRANS, ">$dst") or die "Could not open $dst for writting.";
        {
            # Further transform the output
            while(<TRANSTMP>) {
                if (/^\s*#\s*pragma\s*(?:pupc|PUPC)\s*([^\s;]+);?/) { # GASP support
                    if (uc($1) eq "ON") {
                        print TRANS "#undef UPCR_PRAGMA_PUPC\n#define UPCR_PRAGMA_PUPC 1\n";
                        next;
                    } elsif (uc($1) eq "OFF") {
                        print TRANS "#undef UPCR_PRAGMA_PUPC\n#define UPCR_PRAGMA_PUPC 0\n";
                        next;
                    }
                }
                # TODO: SRCPOS suppression
                print TRANS;
            }

            # Append ctuples
            print TRANS get_ctuple_macros("$basename.o", "$basename.trans.c");
        }
        close(TRANS);
        close(TRANSTMP);
        unlink "${dst}.tmp" or die "Failed to delete '${dst}.tmp': $!\n";

        # save copy in working dir if -save-temps or -trans
        if ($opt_save_temps || $opt_translateonly) {
            my $copyto = ($opt_translateonly && $opt_outputname)
                                 ? $opt_outputname : $startdir;
            runCmd("cp \'$dst\' \'$copyto\'",
                "error while moving translator output from temporary directory");
        }
    }
}

sub mangle_filename {
    my $file_mangled = shift;
       $file_mangled =~ s/[^A-Za-z0-9_]/_/g;
       $file_mangled = $file_mangled . "_" . time();
    return $file_mangled;
}

sub get_mismatch_ctuple_macros {
    my ($ofile) = @_;
    my $file_mangled = mangle_filename($ofile);
    my $str = qq|
#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_configuremismatch, 
   "\$UPCRConfigureMismatch: ($ofile) 1 \$");
  GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_configuredcompiler, 
   "\$UPCRConfigureCompiler: ($ofile) " GASNETT_PLATFORM_COMPILER_IDSTR " \$");
  GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_buildcompiler, 
   "\$UPCRBuildCompiler: ($ofile) " PLATFORM_COMPILER_IDSTR " \$");
#endif
|;
    return $str;
}

sub get_ctuple_macros
{
    my ($ofile, $transfile) = @_;
    my $identFile = $transfile || $ofile;

    die "get_ctuple_macros called with no object file name" unless $ofile;
    die "get_ctuple_macros called with gasnetlib_ctuple not set" if (!$gasnetlib_ctuple);
    die "get_ctuple_macros called with upcrlib_ctuple not set" if (!$upcrlib_ctuple);

    ### append ctuple strings for configuration consistency checks
    my $file_mangled = mangle_filename($ofile);
    my $threadconfig = get_threadconfig();
    my $mismatch_macros = get_mismatch_ctuple_macros($ofile);
    my $now = localtime;

    my $version = labeled_version();
    (my $save_ARGV_string = join ' ', @save_ARGV) =~ s/(["\\])/\\$1/g;
    # use separate config strings for trans.c and .o, so we can catch
    # inconsistent settings across 'upcc -trans foo.upc' and 
    # 'upcc -c foo.trans.c' invocations
    my $str = qq|
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_GASNetConfig_gen, 
 "\$GASNetConfig: ($identFile) ${gasnetlib_ctuple} \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_UPCRConfig_gen,
 "\$UPCRConfig: ($identFile) ${upcrlib_ctuple}${threadconfig} \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_translatetime, 
 "\$UPCTranslateTime: ($ofile) $now \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_GASNetConfig_obj, 
 "\$GASNetConfig: ($ofile) " GASNET_CONFIG_STRING " \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_UPCRConfig_obj,
 "\$UPCRConfig: ($ofile) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_translator, 
 "\$UPCTranslator: ($ofile) $trans ($host) \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_upcver, 
 "\$UPCVersion: ($ofile) $version \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_compileline, 
 "\$UPCCompileLine: ($ofile) $0 $save_ARGV_string \$");
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_compiletime, 
 "\$UPCCompileTime: ($ofile) " __DATE__ " " __TIME__ " \$");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_${file_mangled}_backendcompiler, 
 "\$UPCRBackendCompiler: ($ofile) " _STRINGIFY(UPCRI_CC) " \$");
$mismatch_macros
/**************************************************************************/
|;
    return $str;
}

################################################################################
# Put original filename back into line directives, when remote upcc has put 
# 'foo.i' in for 'foo.c' or 'foo.upc'
################################################################################
sub fix_line_directives {
    my ($filename) = @_;
    my ($basename) = basename($filename);
    $basename =~ s/\.trans\.c$//;

    my $tmpfile = "$filename.tmp";
    open (TRANS, $filename) or die "can't open '$filename' for reading\n";
    open (TMP, ">$tmpfile") or die "can't open '$tmpfile' for writing\n";
    while (<TRANS>) {
        # translator emits #lines with temp directory: convert back
        if (/\Q$basename\E\.i/) {
            s/^(#[^"]*?)"[^"]*\Q$basename\E\.i"/$1"$origPathName{$basename}"/;
        }
        print TMP;
    }
    close TRANS;
    close TMP;
    runCmd("mv -f '$tmpfile' '$filename'", "error fixing line directives", $tmp, 1);
}

################################################################################
# Make sure trans.c file from translator expects compatible runtime version.
# Done as a double safety check (the translator should already
# have barfed on the spec version we provided in upcc-sizes if mismatched)
################################################################################
my $spec_warned_already = 0;
sub validate_spec_version {
    my ($transfile) = @_;
    open(TRANSFILE, $transfile) or die "Couldn't open '$transfile'\n";
    my ($expected_major, $expected_minor);
    while (<TRANSFILE>) {
        if (/UPC Runtime specification expected:\s*(\d+)\.(\d+)/) {
            $expected_major = $1;
            $expected_minor = $2;
            last;
        }
    }
    close TRANSFILE;
    # backup version check:  translator should have caught any mismatch already,
    # so it's considered a system error if we catch it here.
    if (defined $expected_major && defined $expected_minor) {
        if ($expected_major != $spec_major || $expected_minor > $spec_minor) {
            die "error: translator failed to catch incompatible runtime (translator needs interface $expected_major.$expected_minor, this upcc provides $spec_major.$spec_minor)\n"
            . "Please report this error to upc-devel\@lbl.gov\n";
        }
    } elsif ($cupc2c) {
        # TODO - provide cupc2c compiler version check
    } elsif ($opt_checks && !$spec_warned_already++) {
        print STDERR "warning: you are using an outdated UPC-to-C translator\n"
    }
}


################################################################################
## Compile C source code into object files (.trans.c -> .o)
################################################################################
sub do_compile
{
    stagemsg("COMPILING");

    my $cmd;
    foreach my $basename (@toCompile) {
        my $out = "$tmp/$basename.o";
        my $in = ($gccupc||$cupc) ? "$tmp/$basename.i" : "$tmp/$basename.trans.c";
        check_ctuple_trans("$in") if $opt_checks;
        validate_spec_version("$in") unless ($gccupc||$cupc);

        if (!($gccupc||$cupc)) { # find the translator-generated ALLOC/INIT functions
          my %fns;
          open(TRANS, $in) or die "Can't open '$in' for reading\n";
            while (<TRANS>) {
              if ($_ =~ /(UPCRI_(?:ALLOC|INIT)_[A-z_0-9]+)/) { $fns{"$1"} = 1; }
            }
          close TRANS;
          if ( (scalar (keys %fns))) {
           open(TRANS, ">>$in") or die "Can't open '$in' for append\n";
            foreach my $fn (keys %fns) { # embed ident locators
              my $name = $fn;
              $name =~ s/^UPCRI_//;
              my $ident = (($name =~ m/^ALLOC/) ? "UPCRAllocFn" : "UPCRInitFn");
              print TRANS "GASNETT_IDENT(UPCRI_IdentString_$name,".
                          "\"\$$ident: ($basename.trans.c) $fn \$\");\n";
            }
           close TRANS;
          }
        }

        if ($opt_pthreads && !($gccupc||$cupc)) {
            # Assume for now that pthreads uses the 'global struct' approach,
            # in which we don't actually call the C compiler until link time.
            $cmd = "cp \'$in\' \'$out\'";
            runCmd($cmd, "error while copying object file");
        } else {
            # Run C compiler on generated C code: use makefile framework to get
            # all the appropriate flags for the network conduit and platform.
            if ($gccupc) {
                gccupc_compile("$basename.o", 
                               "error compiling translated C code", 1);
            } elsif ($cupc) {
                cupc_compile("$basename.o", 
                               "error compiling translated C code", 1);
            } else {
                my $extra_cflags = $conf{extra_cflags};
                $extra_cflags .= " -v" if $opt_verbose > 1;
                $extra_cflags .= " @opt_CC_args"; # at the end to allow user overrides
                $cmd = $gmake_upcc
                     . qq| EXTRA_CFLAGS="$extra_cflags"|
                     . qq| EXTRA_CPPFLAGS="$extra_cppflags|
                     . qq| -I\'$origDir{$basename}\'"|
                     . qq| UPCR_CONDUIT=$opt_network UPCR_PARSEQ=$parseq|
                     . qq| \'$basename.trans.o\'|;
                runCmd($cmd, "error compiling translated C code", $tmp);
                $cmd = "cp \'$tmp/$basename.trans.o\' \'$out\'";
                runCmd($cmd, "error while moving object file");
            }

            # verify ctuple consistency
            # - catches if different options were passed with -trans than
            #   those used to compile the resulting *.trans.c file.
	    if ($opt_checks) {
            	my $error = check_ctuple_obj("$out");
            	die "$error\n" if ($error);
	    } 
        }
        if ($opt_save_temps || $opt_compileonly) {
            if ($opt_compileonly && $opt_outputname) {
                $cmd = "cp \'$out\' \'$opt_outputname\'";
            } else {
                $cmd = "cp \'$out\' \'$startdir\'";
            }
            runCmd($cmd, "error copying object file");
        }
    }
}


################################################################################
## Link UPC application
################################################################################
sub do_link
{
    stagemsg("LINKING");

    unless (@toLinkUPC) {
        die("UPC linker: application must contain at least one UPC file\n") 
    }

    # if pthread, we need to actually compile the objects (unless using gccupc/clang-upc)
    if ($opt_pthreads && !($gccupc||$cupc)) {
        for (@toLinkPthreads) {
            check_ctuple_trans($_) if $opt_checks; # .o is still a source file
        }
        pthread_late_compile();
    }

    # verify ctuple consistency across UPC objects (internally and against link
    # commmand-line)
    my $threadconfig = get_threadconfig();
    my $gasnet_linkconfigstr = $gasnetlib_ctuple;
    my $upcr_linkconfigstr = "${upcrlib_ctuple}${threadconfig}";
    if ($opt_checks) {
      foreach my $obj (@toLinkUPC) {
        my $error = check_ctuple_obj($obj, 0, $gasnet_linkconfigstr,
                                     $upcr_linkconfigstr);
        die "$error\n" if ($error);
      }
    }

    my $extra_ldflags = "$conf{extra_ldflags} @opt_LD_args";
    my @toLinkQuoted = @toLink;
    map { s@^(.*)$@'$1'@ } @toLinkQuoted;

    if ($gccupc) {
        for (qw/begin end/) { gccupc_compile_marker_file($_); }
        # 'start' object MUST come first in link order
        unshift @toLinkQuoted, "'$tmp/gccupc_begin.o'";
    }
    if ($cupc) {
        for (qw/begin end/) { cupc_compile_marker_file($_); }
        # 'start' object MUST come first in link order
        unshift @toLinkQuoted, "'$tmp/cupc_begin.o'";
    }

    # compile bootstrap C file
    create_bootstrap_file();
    my $link_o = "${targetbase}_startup_tmp.o";
    my $extra_cflags = $conf{extra_cflags};
    $extra_cflags .= " -v" if $opt_verbose > 1;
    $extra_cflags .= " @opt_CC_args"; # at the end to allow user overrides
    my $cppflags = $extra_cppflags;
    if (! ($bupc || $cupc2c)) {
	# UPC cpp flags omitted when invoking upc or cupc2c, but need them for bootstrap C file
	$cppflags .= "$upc_cppflags";
    } else {
        $cppflags .= $opt_pthreads ? " -I\'$pthread_linkdir\' -DUPCRI_USING_TLD" : "";
    }
    my $cmd = $gmake_upcc
            . qq| UPCR_CONDUIT=$opt_network|
            . qq| UPCR_PARSEQ=$parseq EXTRA_CPPFLAGS="$cppflags" |
            . qq| EXTRA_CFLAGS="$extra_cflags" \'$link_o\'|;
    runCmd($cmd, "error compiling C linkage file", $tmp);
  
    # check ctuples in linkage file
    if ($opt_checks) {
      my $error = check_ctuple_obj("$tmp/$link_o", 0, $gasnet_linkconfigstr, 
                                 $upcr_linkconfigstr);
      die "$error\n" if ($error);
    }
    push @toLinkQuoted, "'$tmp/$link_o'";

    # compile trans_extra files
    if (!($gccupc||$cupc)) {
      foreach my $trans_extra_file (sort <$tmp/upcr_trans_extra*.c>) {
        # skip the trans_extra file we append to startup_tmp.c
        next if ($trans_extra_file =~ m@/upcr_trans_extra\.c$@);
        $trans_extra_file =~ s@.*/([^/]*)\.c$@$1.o@;

        my $cmd = $gmake_upcc
                . qq| UPCR_CONDUIT=$opt_network|
                . qq| UPCR_PARSEQ=$parseq EXTRA_CPPFLAGS="$cppflags" |
                . qq| EXTRA_CFLAGS="$extra_cflags" \'$trans_extra_file\'|;
        runCmd($cmd, "error compiling trans_extra file $trans_extra_file", $tmp);
        push @toLinkQuoted, "'$tmp/$trans_extra_file'";
      }
    }

    # build the application
    die "Link target '$target' already exists as a directory\n" if (-d $target);
    $extra_ldflags .= " -v" if $opt_verbose > 1;
    my $extra_libs = ''; # Only TV currently, but available for generalization
    $extra_libs .= " $conf{totalview_libs}" if $opt_totalview;
    my $cmd = $gmake_upcc
            . qq| UPCR_CONDUIT=$opt_network|
            . qq| UPCR_PARSEQ=$parseq OBJS="@toLinkQuoted"|
            . qq| EXTRA_LDFLAGS="$extra_ldflags" OUT="$target"|;
    $cmd .= " GCCUPC_LASTOBJ='$tmp/gccupc_end.o'" if $gccupc;
    $cmd .= " CUPC_LASTOBJ='$tmp/cupc_end.o'" if $cupc;
    $cmd .= " EXTRA_LIBS='$conf{totalview_libs}'" if $extra_libs;
    $cmd .= qq{ UPCC_USER_LD="$opt_user_ld"} if $opt_user_ld;
    runCmd($cmd, "error running '$gmake' to link application");

    die "Link failed - target '$target' is missing\n" if (!-f $target);

  if ($opt_checks) {
    # final ctuple checks - check for mismatched libraries
    my ($gasnet_ctuples,$upcr_ctuples) = extract_ctuples($target);
    my $error;
    if (!$$gasnet_ctuples{"libgasnet.a"}) {
        $error = "missing GASNet library configuration string in libgasnet";
    } elsif (!$$gasnet_ctuples{"libupcr.a"} || !$$upcr_ctuples{"libupcr.a"}) {
        $error = "missing library configuration strings in libupcr";
    } elsif ($$gasnet_ctuples{"libgasnet.a"} ne $gasnetlib_ctuple) {
        my $ctstr = $$gasnet_ctuples{"libgasnet.a"};
        $error = "GASNet library configuration: \n  $ctstr\n" .
               " doesn't match link configuration:\n  $gasnetlib_ctuple";
    } elsif ($$gasnet_ctuples{"libupcr.a"} ne $gasnetlib_ctuple) {
        my $ctstr = $$gasnet_ctuples{"libupcr.a"};
        $error = "UPCR library GASNet configuration: \n  $ctstr\n" .
               " doesn't match link configuration:\n  $gasnetlib_ctuple";
    } else {
      my $ctstr = $$upcr_ctuples{"libupcr.a"};
      $ctstr  =~ s/SHAREDPTRREP=symmetric/SHAREDPTRREP=fsymmetric/ if ($opt_pow2_symptr);
      if ($ctstr ne $upcrlib_ctuple) {
        $error = "UPCR library configuration: \n  $ctstr\n" .
               " doesn't match link configuration:\n  $upcrlib_ctuple";
      }
    }
    if ($error) {
        push @toRemove, $target;
        die "$error\n"; 
    }
  }
  if ($opt_strip) {
     my $strip = verify_exec($conf{strip}, $conf{exe_suffix}, 1); # strip is optional
     if (!$strip) {
       print STDERR "upcc: warning: Ignoring -s because no strip support detected.\n";
     } else {
       my $cmd = "$strip $target";
       runCmd($cmd, "error stripping executable");
     }
  }
}

sub create_bootstrap_file {
    my ($alloc_protos, $alloc_calls, $init_protos, $init_calls);
    my $nm = verify_exec($conf{nm}, $conf{exe_suffix}, 1); # nm is optional

    # Create C file with calls to per-file alloc/init calls
    #   - also check for MPI calls, in case user forgot '--uses-mpi' flag 
    foreach my $obj (@toLink) {
      my (@allocs, @inits);
      my $nmout = undef;  
      if ($nm) { # try to use nm if we have it, to preserve MPI checks
        verbose("*** upcc running '$nm $obj'");
        $nmout = `/bin/sh -c "$nm \'$obj\' 2>/dev/null"`;
        if ($?) {
            $nmout = undef; # we now handle nm failure gracefully
            #die "'$nm $obj' failed: Check your 'nm' setting in upcc.conf\n" 
        }
      }
      if ($nmout) { # nm worked
        if ($nmout =~ /(UPCRI_ALLOC_[A-z_0-9]+)/) {
          push(@allocs,$1);
        }
        if ($nmout =~ /(UPCRI_INIT_[A-z_0-9]+)/) {
          push(@inits,$1);
        }

        unless ($opt_uses_mpi) {
            if ($nmout =~ /MPI_/) {
                print STDERR "upcc: warning: 'MPI_*' symbols seen at link time: "
                           . "should you be using '--uses-mpi'?\n";
            }
        }
      } else { # platforms lacking a working nm (eg Cray X1)
        my ($gasnet_ctuples,$upcr_ctuples,$sizes_ref,$misc_ref) = extract_ctuples($obj);
        foreach my $alloc (values %{$$misc_ref{'UPCRAllocFn'}}) {
          push(@allocs,$alloc);
        }
        foreach my $init (values %{$$misc_ref{'UPCRInitFn'}}) {
          push(@inits,$init);
        }
      }
      foreach my $alloc (@allocs) {
        $alloc_protos .= "void $alloc(void);\n";
        $alloc_calls .= "    $alloc();\n";
      }
      foreach my $init (@inits) {
        $init_protos .= "void $init(void);\n";
        $init_calls .= "    $init();\n";
      }
    }
    # Berkeley UPC translator transforms 'main' into 'user_main': 
    # The gccupc/clang-upc compiler uses 'upc_main'
    my $main_name = (($gccupc||$cupc) ? "upc_main" : "user_main");
    my $link_c = "${targetbase}_startup_tmp.c";
    my $compiled_thread_count = $opt_threadcount || "0";
    my $compiled_pthread_count = $opt_pthreads || "0";
    my $progress_thread = $opt_totalview || "0";
    my $attach_flags = "UPCR_ATTACH_ENV_OVERRIDE";
    $attach_flags .= "|UPCR_ATTACH_REQUIRE_SIZE" if $opt_require_size;
    $attach_flags .= "|UPCR_ATTACH_SIZE_WARN" if $opt_size_warn;;
    (my $save_ARGV_string = join ' ', @save_ARGV) =~ s/(["\\])/\\$1/g;
    open (LINK_C, ">$tmp/$link_c") 
        or die "Can't open temp file '$tmp/$link_c'\n";
    print LINK_C <<EOF;
/* 
 * This file was generated at link time by the upcc compiler to handle
 * initialization busywork.   Please avert your eyes...
 */
EOF

    if ($opt_uses_mpi) {
        print LINK_C <<EOF;
#include <mpi.h>
EOF
    }
    print LINK_C <<EOF;
#define UPCR_NO_SRCPOS
#include <upcr.h>
EOF

    if ($opt_pthreads) {
        print LINK_C <<EOF;
GASNETT_IDENT(UPCRI_IdentString_DefaultPthreadCount, 
 "\$UPCRDefaultPthreadCount: $opt_pthreads \$");

#if UPCRI_USING_TLD
  #undef UPCR_TLD_DEFINE
  #define UPCR_TLD_DEFINE(name, size, align) extern char name[size];
  #define UPCR_TRANSLATOR_TLD(type, name, initval) extern type name;
  #include "global.tld"
  #include <upcr_translator_tld.h>
  #undef UPCR_TLD_DEFINE
  #undef UPCR_TRANSLATOR_TLD
#endif /* UPCRI_USING_TLD */

upcri_pthreadinfo_t*
upcri_linkergenerated_tld_init(void)
{
    struct upcri_tld_t *_upcri_p = UPCRI_XMALLOC(struct upcri_tld_t, 1);

#if UPCRI_USING_TLD
  #define UPCR_TRANSLATOR_TLD(type, name, initval) memcpy(&_upcri_p->name, &name, sizeof(type));
  #include <upcr_translator_tld.h>
  #define UPCR_TLD_DEFINE(name, size, align) memcpy(&_upcri_p->name, &name, size);
  #include "global.tld"
#endif /* UPCRI_USING_TLD */
    return (upcri_pthreadinfo_t *) _upcri_p;
}

EOF
    }
    my ($pre_spawn_init_func, $per_pthread_init_func, $static_init_func, 
        $heap_init_func, $cache_init_func);
    if ($gccupc||$cupc) {
        print LINK_C <<EOF;
void gccupc_pre_spawn_init(void);
void gccupc_per_pthread_init(void);
void gccupc_heap_init (void * start, uintptr_t len);
void gccupc_static_data_init (void *start, uintptr_t len);
void gccupc_cache_init (void *start, uintptr_t len);

/* User's main program entry point (renaming of 'main') */
extern int upc_main (int argc, char **argv);

EOF
    $pre_spawn_init_func = "&gccupc_pre_spawn_init";
    $per_pthread_init_func = "&gccupc_per_pthread_init";
    $static_init_func = "&gccupc_static_data_init";
    $heap_init_func = "&gccupc_heap_init";
    $cache_init_func = "&gccupc_cache_init";
    } else {
        print LINK_C <<EOF;
 /* startup allocation functions */
$alloc_protos

 /* startup initialization functions */
$init_protos

static
void perfile_allocs(void) 
{
    $alloc_calls
}

static
void perfile_inits(void)
{
    $init_calls
}

void (*UPCRL_trans_extra_procinit)(void);
void (*UPCRL_trans_extra_threadinit)(void);

static
void static_init(void *start, uintptr_t len)
{
    UPCR_BEGIN_FUNCTION();
    /* we ignore the start/len params, since we allocate all static 
     * data off the heap */

    if (UPCRL_trans_extra_procinit) {
      UPCR_SET_SRCPOS("_EXTRA_PROCINIT", 0);
      upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
      upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);
      if (upcri_mypthread() == 0) (*UPCRL_trans_extra_procinit)();
      upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
      upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);
    }

    /* Call per-file alloc/init functions */
    perfile_allocs();

    /* Do a barrier to make sure all allocations finish, before calling
     * initialization functions.  */
    /* UPCR_SET_SRCPOS() was already done in perfile_allocs() */ ;
    upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
    upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);

    /* now set any initial values (also for TLD) */
    perfile_inits();

    if (UPCRL_trans_extra_threadinit) {
      UPCR_SET_SRCPOS("_EXTRA_THREADINIT", 0);
      upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
      upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);
      (*UPCRL_trans_extra_threadinit)();
      upcr_notify(0, UPCR_BARRIERFLAG_ANONYMOUS);
      upcr_wait(0, UPCR_BARRIERFLAG_ANONYMOUS);
    }
}

extern void upcri_init_heaps(void *start, uintptr_t len);
extern void upcri_init_cache(void *start, uintptr_t len);

EOF
    $pre_spawn_init_func = "NULL";
    $per_pthread_init_func = "NULL";
    $static_init_func = "&static_init";
    $heap_init_func = "&upcri_init_heaps";
    $cache_init_func = "&upcri_init_cache";
}
    my $shared_heap_size_max_str="";
    if ($shared_heap_size_max) {
      $shared_heap_size_max_str="uint64_t gasnet_max_segsize = $shared_heap_size_max; /* set to $opt_shared_heap_max */";
    } else {
      $shared_heap_size_max_str="/* uint64_t gasnet_max_segsize = 0; */ /* not set */";
    }
    print LINK_C <<EOF;
/* Magic linker variables, for initialization */
upcr_thread_t   UPCRL_static_thread_count       = $compiled_thread_count;
uintptr_t       UPCRL_default_shared_size       = $shared_heap_size;
uintptr_t       UPCRL_default_shared_offset     = $shared_heap_offset;
$shared_heap_size_max_str
int             UPCRL_progress_thread           = $progress_thread;
uintptr_t	UPCRL_default_cache_size        = 0;
int		UPCRL_attach_flags              = $attach_flags;
const char *	UPCRL_main_name;
upcr_thread_t   UPCRL_default_pthreads_per_node = $compiled_pthread_count;
int             UPCRL_segsym_pow2_opt		= $opt_pow2_symptr;
void (*UPCRL_pre_spawn_init)(void)                   = $pre_spawn_init_func;
void (*UPCRL_per_pthread_init)(void)                 = $per_pthread_init_func;
void (*UPCRL_static_init)(void *, uintptr_t)         = $static_init_func;
void (*UPCRL_heap_init)(void * start, uintptr_t len) = $heap_init_func;
void (*UPCRL_cache_init)(void *start, uintptr_t len) = $cache_init_func;
void (*UPCRL_mpi_init)(int *pargc, char ***pargv);
void (*UPCRL_mpi_finalize)(void);
void (*UPCRL_profile_finalize)(void);

EOF

    my $version = labeled_version();
    my $confargs = $conf{configure_args};
    my $conffeatures = $conf{configure_features};
    my $confid = "$conf{configure_system} $conf{configure_id}";
    my $ABI = "$conf{arch_size}-bit $conf{configure_tuple}";
    my $heapsz_max = ($shared_heap_size_max ? " UPC_SHARED_HEAP_SIZE_MAX=$opt_shared_heap_max" : "");
    my $mismatch_macros = get_mismatch_ctuple_macros("<link>");
    print LINK_C <<EOF;
/* strings for configuration consistency checks */
GASNETT_IDENT(UPCRI_IdentString_link_GASNetConfig, 
 "\$GASNetConfig: (<link>) " GASNET_CONFIG_STRING " \$");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRConfig,
 "\$UPCRConfig: (<link>) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " \$");
GASNETT_IDENT(UPCRI_IdentString_link_upcver, 
 "\$UPCVersion: (<link>) $version \$");
GASNETT_IDENT(UPCRI_IdentString_link_compileline, 
 "\$UPCCompileLine: (<link>) $0 $save_ARGV_string \$");
GASNETT_IDENT(UPCRI_IdentString_link_compiletime, 
 "\$UPCCompileTime: (<link>) " __DATE__ " " __TIME__ " \$");
GASNETT_IDENT(UPCRI_IdentString_HeapSz, 
 "\$UPCRDefaultHeapSizes: UPC_SHARED_HEAP_OFFSET=$opt_heap_offset UPC_SHARED_HEAP_SIZE=$opt_shared_heap$heapsz_max \$");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRConfigureArgs,
 "\$UPCRConfigureArgs: $confargs \$");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRFeatures,
 "\$UPCRConfigureFeatures: $conffeatures \$");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRConfId,
 "\$UPCRConfigureId: $confid \$");
GASNETT_IDENT(UPCRI_IdentString_link_UPCRABI,
 "\$UPCRBinaryInterface: $ABI \$");
GASNETT_IDENT(UPCRI_IdentString_link_backendcompiler, 
 "\$UPCRBackendCompiler: (<link>) " _STRINGIFY(UPCRI_CC) " \$");
GASNETT_IDENT(UPCRI_IdentString_link_backendlinker, 
 "\$UPCRBackendLinker: " _STRINGIFY(UPCRI_LD) " \$");
$mismatch_macros
EOF
    
    if ($opt_uses_mpi) {
        print LINK_C <<EOF;
#include <mpi.h>
/* Ensure MPI is bootstrapped just once */

static void mpi_err(const char *MPI_funcname, int err)
{
    char buf[MPI_MAX_ERROR_STRING + 1];
    int result_len;
    
    if (MPI_Error_string(err, buf, &result_len) != MPI_SUCCESS) 
        upcri_err("MPI Function '%s' failed with errcode=%d",
                  MPI_funcname, err);
    /* MPI spec doesn't say if result NULL-terminated */
    buf[result_len] = 0;
    upcri_err("MPI function failed: %s: %s", MPI_funcname, buf);
}

static int MPI_was_init_already;

static void maybe_MPI_Init(int *pargc, char ***pargv)
{
    int err;

    /* only init MPI if it's not already initialized by GASNet */
    err = MPI_Initialized(&MPI_was_init_already);
    if (err != MPI_SUCCESS) 
	mpi_err("MPI_Initialized", err);
    if (!MPI_was_init_already) { 
        err = MPI_Init(pargc, pargv);
	if (err != MPI_SUCCESS)
            mpi_err("MPI_Init", err);
    }
}

static void maybe_MPI_Finalize(void)
{
    int err;

    if (!MPI_was_init_already) {
        int err = MPI_Finalize();
        /* If failed, issue error and hope for the best */
        if (err != MPI_SUCCESS) {
            char buf[MPI_MAX_ERROR_STRING + 1];
            int result_len;
            if (MPI_Error_string(err, buf, &result_len) != MPI_SUCCESS) {
                upcri_warn("MPI_Finalize failed with errcode=%d", err);
            } else {
                buf[result_len] = 0;
                upcri_warn("MPI_Finalize failed : %s", buf);
            }
        }
    }
}

void (*UPCRL_mpi_init)(int *pargc, char ***pargv) = &maybe_MPI_Init;
void (*UPCRL_mpi_finalize)(void) = &maybe_MPI_Finalize;

EOF
    }

    if ($opt_profile) {
        print LINK_C <<EOF;
#if HAVE_SYS_GMON_H
  #include <sys/gmon.h>
#endif
#if HAVE_MON_H
  #include <mon.h>
#endif
#if HAVE_ROUEXIT 
  extern void __rouexit(void); /* PGI's undocumented profile cleanup function */
#endif
#if HAVE_MCLEANUP || HAVE_MONCONTROL || HAVE_MONITOR_SIGNAL || HAVE_MONITOR || HAVE_MONITOR5 || HAVE_ROUEXIT
  #include <sys/stat.h>
  #include <sys/types.h>
  static void upcri_do_mcleanup(void) {
    UPCR_BEGIN_FUNCTION();
    if (gasnet_nodes() > 1) { /* attempt to chdir into a private per-process dir */
      char path[80];
      sprintf(path,"./gmon.out.%i", (int)gasnet_mynode());
      mkdir(path, 0777); /* ignore errors - if it fails, it fails */
      chdir(path);
    }
    /* note that order is quite particular here, as some platforms have several */
    #if HAVE_ROUEXIT /* PGI (must precede mcleanup) */
      __rouexit(); 
    #elif HAVE_MCLEANUP /* gcc */
      _mcleanup(); 
    #elif HAVE_MONITOR_SIGNAL /* Tru64 (must precede monitor(*)) */
      putenv("PROFFLAGS=-dirname .");
      putenv("PROFDIR=.");
      monitor_signal(0);
    #elif HAVE_MONITOR /* AIX, ... */
      monitor(0);
    #elif HAVE_MONITOR5 /* SunC, ... (must come after mcleanup) */
      monitor(0,0,0,0,0);
    #else
      #error unknown profiling system
    #endif
  }
  void (*UPCRL_profile_finalize)(void) = &upcri_do_mcleanup;
#endif
EOF
   }

    if ($opt_totalview) {
	# directories where our Totalview libs & TCL scripts live
	my ($tv_lib_dir, $tv_tcl_dir);
	if (-f "$upcr_bin/upcc.conf") {
	    # If in build tree, shared libs are hidden by libtool in '.libs/'
	    $tv_lib_dir = "$upcr_lib/totalview/assistant/.libs";
	    $tv_tcl_dir = "$upcr_lib/totalview/tcl";
	} else {
	    $tv_lib_dir = $upcr_lib;
	    $tv_tcl_dir = "$upcr_lib/tcl";
	}
        my $assistant_lib = "$tv_lib_dir/libupcda-$opt_network-tv.so";

	print LINK_C <<EOF;
/* Totalview debugger support */
GASNETT_IDENT(upcri_IdentString_Totalview, "\$UPCRTotalview: 1 \$");
extern char volatile __TV_s2s_prologue[];
char volatile __TV_s2s_prologue[] =
    "dset ::TV::Private::upc_assistant_library $assistant_lib; "
    "if {![info exists env(UPC_TV_SCRIPT_HOME)]} "
    "	{set env(UPC_TV_SCRIPT_HOME) $tv_tcl_dir}; "
    "source \$env(UPC_TV_SCRIPT_HOME)/s2s_prologue.tvd";
EOF
    } else {
	print LINK_C <<EOF;
/* NO Totalview debugger support */
GASNETT_IDENT(upcri_IdentString_Totalview, "\$UPCRTotalview: 0 \$");
GASNETT_IDENT(__TV_s2s_disabled, "This executable lacks Totalview support: recompile with 'upcc -tv'.");
EOF
    }

    unless ($opt_extern_main) {
        print LINK_C <<EOF;
/* The main() event */
extern int user_main(int, char**);
const char * UPCRL_main_name = "$main_name";

int main(int argc, char **argv)
{
    bupc_init_reentrant(&argc, &argv, &$main_name);
    return 0;
}
EOF
    }

    # append the two "primary" translator-provided supporting files   
    foreach my $trans_extra_file ("$tmp/upcr_trans_extra.w2c.h", "$tmp/upcr_trans_extra.c") {
      next unless -f $trans_extra_file;
      print LINK_C "#line 1 \"$trans_extra_file\"\n";
      open (TRANS_EXTRA, "<$trans_extra_file")
        or die "Can't open '$trans_extra_file'\n";
      while (<TRANS_EXTRA>) {
	print LINK_C;
      }
      close (TRANS_EXTRA);
    }
    # do not put anything here, translator files come last to preserve #line info
    close (LINK_C);
}

sub gccupc_compile {
    my ($obj, $errmsg, $preprocessed_input) = @_;
    my $is_debug = $dbg_build || $opt_debug;

    my $extra_cflags = $conf{extra_cflags};
    $extra_cflags .= " -fpreprocessed" if $preprocessed_input;
    $extra_cflags .= " -v" if $opt_verbose > 1;
    $extra_cflags .= " -g" if $is_debug;
    $extra_cflags .= " -O3 --param max-inline-insns-single=35000 --param inline-unit-growth=10000 --param large-function-growth=200000 -Winline" unless $is_debug; # default is same as opt
    my ($ver_A, $ver_B, $ver_C, $ver_D) = ($conf{'gccupc_version'} =~ /(\d+)\.(\d+)\.(\d+)[.-](\d+)/);
    my $gccupc_version = ($ver_A<<24)|($ver_B<<16)|($ver_C<<8)|$ver_D;
    $extra_cflags .= " -fupc-libcall" if ($gccupc_version >= 0x03030209)
                                         && ($gccupc_version < 0x04000000);
    $extra_cflags .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;
    $extra_cflags .= " -fupc-pthreads-model-tls" if $opt_pthreads;
    # TODO: Need? Specifies default # of pthreads: checked by gccupc
    #$xtraflags .= " -fupc-pthreads-per-process-$opt_pthreads" 
    #    if $opt_pthreads;
    $extra_cflags .= " @opt_CC_args"; # at the end to allow user overrides
    my $cmd = qq|$gmake_upcc GCCUPC="$trans" EXTRA_CFLAGS="$extra_cflags" UPCR_PARSEQ=$parseq USE_GCCUPC_COMPILER=yes '$obj'|;
    $errmsg = "error invoking gccupc compiler" unless $errmsg;
    runCmd($cmd, $errmsg, $tmp);
}

sub cupc_compile {
    my ($obj, $errmsg, $preprocessed_input) = @_;
    my $is_debug = $dbg_build || $opt_debug;

    my $extra_cflags = "$conf{extra_cflags} -Wno-unused-value";
    $extra_cflags .= " -v" if $opt_verbose > 1;
    $extra_cflags .= " -O0 -g" if $is_debug;
    $extra_cflags .= " -O3" unless $is_debug; # default is same as opt
    $extra_cflags .= " -fupc-threads-$opt_threadcount" if $opt_threadcount;
    $extra_cflags .= " @opt_CC_args"; # at the end to allow user overrides
    my $cmd = qq|$gmake_upcc CUPC="$trans" EXTRA_CFLAGS="$extra_cflags" UPCR_PARSEQ=$parseq USE_CUPC_COMPILER=yes '$obj'|;
    $errmsg = "error invoking clang upc compiler" unless $errmsg;
    runCmd($cmd, $errmsg, $tmp);
}

# Create start and end symbols that identify start/end of shared linker section.
# GCCUPC uses different linker section names for these on different platforms,
# so use UPC files and have gccupc compile them.
sub gccupc_compile_marker_file
{
    my ($name) = @_;   # 'begin' or 'end'
    my $cfile = "$tmp/gccupc_$name.c";
    my $obj =   "$tmp/gccupc_$name.o";
    my ($ver_A, $ver_B, $ver_C, $ver_D) = ($conf{'gccupc_version'} =~ /(\d+)\.(\d+)\.(\d+)[.-](\d+)/);
    my $gccupc_version = ($ver_A<<24)|($ver_B<<16)|($ver_C<<8)|$ver_D;
    my $os = $^O;
    my $sect_prefix = "";

    if ($os eq "darwin") { $sect_prefix = "__DATA,"; }

    open (C_FILE, ">$cfile") or die "Can't create '$cfile' for writing\n";
    if ($name eq 'begin') {
      # Allocate guard page at the beginning of the shared section
      # for UPCR compatibility.  The value, 0x10000 (64K) is sufficiently
      # large to ensure that the GCCUPC's packed sptr rep. will never
      # generate an sptr that refers to the first page in remote memory.
      print C_FILE "char __upc_shared_start[0x10000] __attribute__((section(\"".$sect_prefix."upc_shared\")));\n";
    } else {
      print C_FILE "char __upc_shared_end[] __attribute__((section(\"".$sect_prefix."upc_shared\"))) = {};\n";
    }

    if ($gccupc_version >= 0x04020002) {
      print C_FILE "void (*UPCRL_init_array_$name\[1]) (void) __attribute__((section(\"".$sect_prefix."upc_init_array\")));\n";
    }
    close C_FILE;

    # Compile as C code to avoid interpreting init_array as thread-local
    # when compiled in -pthreads mode.
    my $extra_cflags = " -x c";
    my $cmd = qq|$gmake_upcc GCCUPC="$trans" EXTRA_CFLAGS="$extra_cflags" UPCR_PARSEQ=$parseq USE_GCCUPC_COMPILER=yes '$obj'|;
    my $errmsg = "error compiling linker marker file '$cfile'";
    runCmd($cmd, $errmsg, $tmp);
}

# Create start and end symbols that identify start/end of shared linker section.
# Clang UPC uses different linker section names for these on different platforms,
# so use UPC files and have Clang UPC compile them.
sub cupc_compile_marker_file
{
    my ($name) = @_;   # 'begin' or 'end'
    my $cfile = "$tmp/cupc_$name.c";
    my $obj =   "$tmp/cupc_$name.o";
    my $os = $^O;
    my $sect_prefix = "";

    if ($os eq "darwin") { $sect_prefix = "__DATA,"; }

    open (C_FILE, ">$cfile") or die "Can't create '$cfile' for writing\n";
    if ($name eq 'begin') {
      # Allocate guard page at the beginning of the shared section
      # for UPCR compatibility.  The value, 0x10000 (64K) is sufficiently
      # large to ensure that the GCCUPC's packed sptr rep. will never
      # generate an sptr that refers to the first page in remote memory.
      print C_FILE "char __upc_shared_start[0x10000] __attribute__((section(\"".$sect_prefix."upc_shared\")));\n";
    } else {
      print C_FILE "char __upc_shared_end[] __attribute__((section(\"".$sect_prefix."upc_shared\"))) = {};\n";
    }

    print C_FILE "void (*UPCRL_init_array_$name\[1]) (void) __attribute__((section(\"".$sect_prefix."upc_init_array\")));\n";
    close C_FILE;

    # Compile as C code to avoid interpreting init_array as thread-local
    # when compiled in -pthreads mode.
    my $extra_cflags = " -x c";
    my $cmd = qq|$gmake_upcc CUPC="$trans" EXTRA_CFLAGS="$extra_cflags" UPCR_PARSEQ=$parseq USE_CUPC_COMPILER=yes '$obj'|;
    my $errmsg = "error compiling linker marker file '$cfile'";
    runCmd($cmd, $errmsg, $tmp);
}

################################################################################
# determines if an object file is from UPC source
#   - also handles pthreads case, where .o file is really still source code
################################################################################
sub is_upc_obj {
    my ($obj) = @_;
      my ($gasnet_ctuples,$upcr_ctuples) = extract_ctuples($obj);
      return scalar(keys %{$upcr_ctuples});
}

################################################################################
# determines if an object file is from UPC source (pthreads only)
################################################################################
sub is_upc_pthreads_obj {
  my ($obj) = @_;

  if ($gccupc) {
    my ($gasnet_ctuples,$upcr_ctuples) = extract_ctuples($obj);
    return grep(/,SHMEM=pthreads/,values %{$upcr_ctuples});
  } elsif ($cupc) {
    return 0;
  } else { # pthreads objects from source-to-source are just source
    my $signature = 'upcc-generated strings for configuration consistency checks';
    return (0 == system("grep '$signature' \'$obj\' >/dev/null 2>/dev/null"));
  }
}

################################################################################
# Deletes temporary files generated during execution
################################################################################
sub clean_up {
    chdir($startdir) # all files added relative to start dir
       or print "Failed to chdir($startdir): $!";
    system("/bin/sh -c 'rm -rf @toRemove >/dev/null 2>/dev/null'");
}


################################################################################
# Helper functions for HTTP remote translation
################################################################################

# Creates an HTTP multipart/form-data string for a HTML form text field.
sub multipart_form_text {
    my ($var, $value, $break) = @_;
    my $temp_req = "--$break\r\n"
	           . "Content-Disposition: form-data; name=\"$var\"\r\n\r\n"
	           . "$value\r\n";
    return $temp_req or die "Couldn't return $temp_req for $value";
}

# Creates an HTTP multipart/form-data string for a HTML form file upload field.
sub multipart_form_file {
    my ($name, $file, $break) = @_;
    my $temp_req = "--$break\r\n"
       . "Content-Disposition: form-data; name=\"$name\"; filename=\"$file\"\r\n"
       . "Content-Type: application/x-tar\r\n\r\n";
    open (FILE, $file) or die "Couldn't open $file";
    undef $/;
    my $stuff = <FILE>;
    close FILE;
    $/ = "\n";
    #$stuff =~ s/\W/*/g;
    $temp_req .= "$stuff\r\n";
    return $temp_req;
}

################################################################################
# Totalview debugging support
################################################################################

# Adds TCL code (as a string) to translated code
sub add_totalview_tcl {
    my ($file, $origfile) = @_;

    return unless ($opt_totalview);

    open (FILE, ">>$file") or die "Couldn't open '$file' for appending";

    # directories where our Totalview libs & TCL scripts live
    my ($tv_lib_dir, $tv_tcl_dir);
    if (-f "$upcr_bin/upcc.conf") {
        # If in build tree, shared libs are hidden by libtool in '.libs/'
        $tv_lib_dir = "$upcr_lib/totalview/assistant/.libs";    
        $tv_tcl_dir = "$upcr_lib/totalview/tcl";
    } else {
        $tv_lib_dir = $upcr_lib;
        $tv_tcl_dir = "$upcr_lib/tcl";
    }
    my ($assistant_lib) = "$tv_lib_dir/libupcda-$opt_network-tv.so";
    my $file_mangled = mangle_filename($origfile);


    print FILE <<"EOF";

/************************************************************************* 
 * Totalview debugger support */
static const char __TV_s2s_skim[] = 
    "set bupc_file $origfile; "
    "set bupc_trans_file $file; "
    "source \$env(UPC_TV_SCRIPT_HOME)/s2s_skim.tvd";
static const char __TV_s2s_lines[] = 
    "set bupc_file $origfile; "
    "set bupc_trans_file $file; "
    "source \$env(UPC_TV_SCRIPT_HOME)/s2s_lines.tvd";
static const char __TV_s2s_symbols[] = 
    "set bupc_file $origfile; "
    "set bupc_trans_file $file; "
    "source \$env(UPC_TV_SCRIPT_HOME)/s2s_symbols.tvd";
/************************************************************************/

EOF

    close FILE;
}


################################################################################
# Pthread 'global struct' infrastructure
#  - You are advised to read the "Handling static data in the UPC runtime"
#    document before trying to understand this code.
################################################################################

# build UPC object files, ensuring that each is compiled with the correct global
# struct info (skipping recompilation if not necessary).
sub pthread_late_compile 
{
    my (%osrc, %odest);
    my (@basenames) = map { my $b = basename($_); 
                            $b =~ s/\.[^.]+$//;  # remove extension
                            $osrc{$b} = $_;
                            $odest{$b} = "$pthread_linkdir/${b}_obj.c";
                            $b; # return basename for @basenames array
                          } @toLinkPthreads;

    # Check to see that same executable is being linked (same files, same
    # configuration), or scrub directory and create new Makefile
    my $makefile = "$pthread_linkdir/Makefile";
    my $useprev = 1;
    if (-r $makefile) {
        open(OLDMAKE, $makefile) or die "Perl lied to me!\n";
        while (<OLDMAKE>) {
            if (/^OBJS\s+=\s+(\w.*)$/) {
                my @objs = split $1;
                if (scalar(@objs) == scalar(@basenames)) {
                    for (my $i = 0; $i < @objs; $i++) {
                        if ($objs[$i] ne "$basenames[$i]_obj.o") {
                            $useprev = 0;
                            last;
                        }
                    }
                }
                last;
            }
        }
	close(OLDMAKE);
    } else {
        $useprev = 0;
    }
    if ($useprev) {
        # check configuration of one of the files, to make sure it matches what
        # user specified
        my $threadconfig = get_threadconfig();
        my $gasnet_linkconfigstr = $gasnetlib_ctuple;
        my $upcr_linkconfigstr = "${upcrlib_ctuple}${threadconfig}";
        if (check_ctuple_obj($osrc{$basenames[0]}, 0, $gasnet_linkconfigstr,
                             $upcr_linkconfigstr)) {
            $useprev = 0;
        }
    }
    # destroy/create directory if needed
    unless ($useprev) {
        if (-e $pthread_linkdir) {
            runCmd("rm -rf \'$pthread_linkdir\'", 
                   "error removing pthread link directory");
        }
        mkdir($pthread_linkdir,0700) or die "Could not mkdir $pthread_linkdir\n";

        pthread_create_makefile(\@basenames);
    }
    push @toRemove, $pthread_linkdir if (! $opt_link_cache);

    # copy fake object files to pthread directory if changed (or missing)
    for my $b (@basenames) {
        if (files_differ($osrc{$b}, $odest{$b})) {
            runCmd("cp \'$osrc{$b}\' \'$odest{$b}\'",
                    "error copying $osrc{$b} to $odest{$b}");
            # create/update .tld file if needed
            update_tld_file($b);
        }
    }

    # compile the subset of fake object files needed
    runCmd("$gmake", "Error building pthread objects with thread-local data",
           $pthread_linkdir);

}

sub pthread_create_makefile 
{
    my ($rbasenames) = @_;
    my (@objfiles) = map { "${_}_obj.o" } @$rbasenames;
    map { s/([ ])/\\$1/g } @objfiles;
    map { s/\$/\$\$/g } @objfiles;
#    map { s/([^a-zA-Z0-9_\-\.])/\\$1/g } @objfiles;
    my (@tldfiles) = map { "${_}_obj.tld" } @$rbasenames;
    map { s/\$/\$\$/g } @tldfiles;
    my @quoted_tldfiles = @tldfiles;
    map { s/(^.*$)/\'$1\'/g } @quoted_tldfiles;
    map { s/([ ])/\\$1/g } @tldfiles;
#    map { s/([^a-zA-Z0-9_\-\.])/\\$1/g } @tldfiles;
    my $makefile = "$pthread_linkdir/Makefile";
    my $extra_cflags = $conf{extra_cflags};
    $extra_cflags .= " -v" if $opt_verbose > 1;
    $extra_cflags .= " @opt_CC_args"; # at the end to allow user overrides

    open (MAKEFILE, ">$makefile") or die "Can't create '$makefile'\n";
    print MAKEFILE <<EOF;
# Makefile generated by upcc, the Berkeley UPC compiler.
# The files in this directory were created to link the executable 
#   '$target'.  
#
# You may delete this directory at any time, but keeping it may speed 
# up building the application again.
#
# Why this is here:  under pthreads, all UPC .o files are really still C source
# files.  At link time we must create a single large 'struct' that contains all
# the thread-local variables in the application, and ensure that 'real' .o
# files have been compiled with that struct definition.  We use this directory
# and Makefile to avoid recompiling every source file each time you link:
# recompiling all files is only required if the struct has changed (i.e. you
# have added, removed, or changed an unshared global/static variable in your
# application).

OBJS    = @objfiles

.SUFFIXES: .c .o


all_objs: \$(OBJS)

# sort by alignment, then eliminate duplicate tentative entries with same
# size/alignment.  Other duplicate names will cause linker error (good)
global.tld:  @tldfiles
	cat @quoted_tldfiles | sort -u -k 3,3rn -k 1,1 >global.tld
	echo '/* this comment avoids empty file warnings */' >>global.tld

EOF

    for (@$rbasenames) {
	my $quoted_name = ${_};
	#$quoted_name =~ s/([^a-zA-Z0-9_\-\.])/\\$1/g;
        $quoted_name =~ s/([ ])/\\$1/g;
        $quoted_name =~ s/\$/\$\$/g;
        print MAKEFILE <<END_OBJ_RULE
${quoted_name}_obj.o: ${quoted_name}_obj.c global.tld
	$gmake_upcc \\
	EXTRA_CFLAGS="$extra_cflags"    \\
	EXTRA_CPPFLAGS="$extra_cppflags -DUPCRI_USING_TLD -I\'$origDir{$_}\' -I\'$pthread_linkdir\'" \\
	UPCR_CONDUIT=$opt_network UPCR_PARSEQ=$parseq \'\$\@\'

END_OBJ_RULE
    }

    close(MAKEFILE);
}

# Greps out TLD declarations from translated code, and stores in .tld file 
#   - doesn't touch file if it would not change, so Make can skip it 
sub update_tld_file 
{
    my ($basename) = @_;
    my @tld_macros;

    my $cfile = "$pthread_linkdir/${basename}_obj.c";
    open(OBJ, $cfile) or die "Can't open '$cfile' for reading\n";
    while (<OBJ>) {
        # no need to distinguish tentative declarations for global struct
        s/UPCR_TLD_DEFINE_TENTATIVE/UPCR_TLD_DEFINE/;
	if (m/UPCR_TLD_DEFINE(\([^;]+\))/) { 
	  # bug 2228 - handle nested parens in args, but watch for parens in initializer
	  my $text = reverse($1);
	  my $args = "";
	  my $nestlvl = 0;
	  while (defined $text) {
	    my $char = chop($text);
	    $args .= $char;
	    $nestlvl++ if ($char eq '(');
	    $nestlvl-- if ($char eq ')');
            last if ($nestlvl == 0);
	  }
          push @tld_macros, "UPCR_TLD_DEFINE$args\n";
	}
    }
    close OBJ;

    # sort macros, and discard duplicate definitions
    my @tld = sort sort_tld @tld_macros; 
    my $prev = "";
    @tld = grep { my $ok = $prev ne $_; $prev = $_; $ok } @tld;

    my $tldfile = "$pthread_linkdir/${basename}_obj.tld";

    # if existing .tld file is identical, leave it to avoid recompile
    if (-r $tldfile) {
        open (TLD, $tldfile) or die "Can't open '$tldfile' for reading\n";
        my @oldtld = <TLD>; # slurp!
        close TLD;
        my $i; 
        if (scalar(@tld) == scalar(@oldtld)) {
            my $i;
            my $equal = 1;
            for ($i = 0; $i < @tld; $i++) {
                if ($tld[$i] ne $oldtld[$i]) {
                    $equal = 0;
                    last;
                }
            }
            return if $equal;
        }
    }
    # create new tld file 
    open (TLD, ">$tldfile") or die "Can't open '$tldfile' for writing\n"; 
    for (@tld) {
        print TLD;
    }
    close(TLD);
}

# sorts 'UPCR_TLD_DEFINE(foo, size, align)' style declarations by alignment (descending)
sub sort_tld {
    $a =~ /,\s*(\d+)\s*\)/; 
    die "Invalid UPCR_TLD_DEFINE: $a\n" unless $1;
    my $asize = $1;
    $b =~ /,\s*(\d+)\s*\)/; 
    die "Invalid UPCR_TLD_DEFINE: $b\n" unless $1;
    my $bsize = $1;
    return $bsize <=> $asize;
}

sub files_differ
{
    my ($file1, $file2) = @_;

    return 1 unless -r $file1 && -r $file2;
    return(system("/bin/sh -c \"cmp \'$file1\' \'$file2\' >/dev/null 2>/dev/null\""));
}

