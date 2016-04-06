#!/usr/bin/env perl

require 5.005;
use strict;
use Cwd;

# --with-multiconf[=<conf_options>] : enables selected confs
# --with-multiconf-file=conffile : selects multiconf.conf input file (defaults to multiconf.conf.in)
# --with-multiconf-force=name : asserts $opt{name} to allow use w/o passing that arg explicitly
# --reboot : force a Bootstrap before configures are run

# new configure options:
# --without-multiconf : legacy behavior
# --with-multiconf-magic=confname : used by multiconf for sub-configures

my $top_builddir = getcwd(); 
chdir($top_builddir) or die "Failed to chdir($top_builddir): $!";
my $top_srcdir = $0;
$top_srcdir =~ s@/[^/]*$@@;
chdir($top_srcdir) or die "Failed to chdir($top_srcdir): $!";
$top_srcdir = getcwd();
chdir($top_srcdir) or die "Failed to chdir($top_srcdir): $!";
push @INC, $top_srcdir;  # set up search path for our perl includes
chdir($top_builddir) or die "Failed to chdir($top_builddir): $!";

my $config_shell = '';
if (defined($ENV{'CONFIG_SHELL'})) {
  $config_shell = $ENV{'CONFIG_SHELL'};
  die "If set, environment variable CONFIG_SHELL must be " .
      "the full path to a Bourne-compatible shell.\n"
	unless ($config_shell =~ m:^/:);
  $config_shell .= ' ';
}

# bug 3153 - we cannot let SuSE (et al.) set ${libdir} to ${prefix}/lib64
$ENV{'CONFIG_SITE'} = '/dev/null' if defined $ENV{'CONFIG_SITE'};

# establish a global configure warning summary file
my $configure_warn_file =  "$top_builddir/.multiconf_configure_warnings.tmp";
$ENV{'GASNET_CONFIGURE_WARNING_GLOBAL'} = $configure_warn_file;
open CONFWARN,">$configure_warn_file" or die "failed to create $configure_warn_file: $!";
close CONFWARN;
# suppress a confusing warning when using multiconf
$ENV{'GASNET_SUPPRESS_DEBUG_WARNING'} = 1;
$| = 1; # autoflush output to ensure correct behavior with forks and output piped to files

# shared functions
use vars qw($debug $disable_upcc *debuglog);
$disable_upcc = 1;
my $debuglog_file = "$top_builddir/config.log";
open DEBUGLOG,">$debuglog_file" or die "failed to create $debuglog_file: $!";
*debuglog = *DEBUGLOG{IO}; # bug 2476 - old perl requires this nastiness, avert your eyes...
require "upcc_multi.pl";

my %opt;
my %cond_opt;
my %cond_env;
my %cond_confs;
my @sub_ARGV;


debugmsg("top_srcdir=$top_srcdir");
debugmsg("top_builddir=$top_builddir");

### parse arguments ###
# avoid getopt here, to eliminate the complication of finding a non-buggy version of that module
my $lastopt = '';
foreach my $arg (@ARGV) {
  my $skip;
  if ($arg =~ m/^--?([A-Za-z0-9-_]+)(=(.*))?$/) {
    my ($argb, $set, $argv) = ($1,$2,$3);
    $skip = 1 if ($argb eq "prefix"); # avoid redundant prefix arg to subconfigure
    if ($set) {
      $opt{$argb} = $argv;
      $lastopt = undef;
    } else {
      $opt{$argb} = "yes";
      $lastopt = $argb;
    }
    if ($argb =~ m/^(reboot)|(dry-run)$/) # strip non-autoconf compliant arg names that make it barf
      { $skip = 1; $lastopt = undef; }
    if ($argb =~ m/^with-(.+)$/) { delete $opt{"without-$1"}; $lastopt = undef; }
    if ($argb =~ m/^without-(.+)$/) { delete $opt{"with-$1"}; $lastopt = undef; }
    if ($argb =~ m/^enable-(.+)$/) { delete $opt{"disable-$1"}; $lastopt = undef; }
    if ($argb =~ m/^disable-(.+)$/) { delete $opt{"enable-$1"}; $lastopt = undef; }
  } elsif ($lastopt) { # assume it's an argument to last arg
    $skip = 1 if ($lastopt eq "prefix"); # avoid redundant prefix arg to subconfigure
    $opt{$lastopt} = $arg;
    $lastopt = undef;
  } elsif ($arg =~ m/^([A-Za-z0-9-_]+)=(.*)$/) { # detect command-line environment variables
    my ($var,$val) = ($1,$2);
    $ENV{$var} = $val;
    print "Setting from command-line: $var=".$ENV{$var}."\n";
    $skip = 1;
  } elsif ($arg =~ m/^([A-Za-z0-9-_,]+):(.*)$/) { # conditional (subconfig-specific) argument
    my @confs = split ',', $1;
    my $subarg = $2;
    if ($subarg =~ m/^--?([A-Za-z0-9-_]+)(=.*)?$/) { # conditional --argument
      foreach my $subconf (@confs) {
        $cond_opt{$subconf} .= ' ' . $subarg;
        $cond_confs{$subconf} = 1;
      }
      $skip = 1;
    } elsif ($subarg =~ m/^([A-Za-z0-9-_]+)=(.*)$/) { # conditional VAR=VAL
      foreach my $subconf (@confs) {
        $cond_env{$subconf}->{$1} = $2;
        $cond_confs{$subconf} = 1;
      }
      $skip = 1;
    } else {
      debugmsg("ignoring strange conditional argument:".$arg);
    }
  } else {
    debugmsg("ignoring strange argument:".$arg);
  }
  push @sub_ARGV, "'$arg'" unless ($skip);
}
debugmsg("args: ".join(' ', map { ($opt{$_} eq "yes" ? "--$_" : "--$_=$opt{$_}") } keys %opt));

my $top_prefix = $opt{prefix} || "/usr/local/berkeley_upc";
$debug = 1 if ($opt{'dry-run'});

if ($opt{h} || $opt{help}) {
  run_command("$config_shell$top_srcdir/configure --with-multiconf-magic=help ".join(' ',@sub_ARGV),"configure help",1);
  print STDERR <<EOF;
multiconf options:

  --with-multiconf[=<conf_options>]  
	 Enable use of multiconf build configuration manager.  The optional
	 <conf_options> can be used to modify the default ENABLED_CONFS setting
	 in the multiconf config file, using one of the following syntaxes:
          conf1,conf2,conf3      set ENABLED_CONFS=conf1,conf2,conf3
	  +conf1,+conf2,-conf3   modify default ENABLED_CONFS, appending conf1,conf2
                                 and removing conf3

  --with-multiconf-file=<conf_file>
         Enable use of multiconf, with given config file (defaults to multiconf.conf.in)
				  
  --with-multiconf-force=<opt>
         Comma-delimited list of multi-conf specific upcc options to assert.
         Typically used to configure for sole use of a non-Berkeley translator.
				  
  --without-multiconf   Disable use of multiconf - legacy configure behavior
  --prefix=pathname     Use pathname as base prefix for multiconf installation
  --reboot[=<args>]     Bootstrap the source directory before invoking configure
  --verbose             Show operations verbosely
  --dry-run             Skip actual configure invocations, to debug configurations
  --help                This help screen

  [[confs:]arg]         Other arguments are passed through to configure
  [[confs:]var=val]     Environment variables will be set when running configure
      Where "confs:" is an optional comma-seprated, colon-terminated list of
      configurations (default is to pass arg, or set var, for all configurations)

EOF
  # dont leave junk laying around for a --help invocation
  close *debuglog;
  unlink $debuglog_file;
  unlink $configure_warn_file;
  exit 1;
}

if ($opt{reboot}) {
  my $bootstrap_args = ($opt{reboot} eq 'yes') ? '' : $opt{reboot};
  run_command("cd $top_srcdir && ./Bootstrap $bootstrap_args","reboot Bootstrap");
}

if ($opt{'without-multiconf'}) { # used for non-multiconf reboot
  my @args = grep !/^-?-reboot/, @ARGV;
  close *debuglog;
  unlink $debuglog_file;
  unlink $configure_warn_file;
  undef $ENV{'GASNET_CONFIGURE_WARNING_GLOBAL'};
  run_command("$config_shell$top_srcdir/configure ".join(' ',@args),"configure");
  exit 0;
}

# parse conffile
my @interesting_vars;
delete $opt{'with-multiconf'} if ($opt{'with-multiconf'} eq "yes");
delete $opt{'with-multiconf-file'} if ($opt{'with-multiconf-file'} eq "yes");
delete $opt{'with-multiconf-force'} if ($opt{'with-multiconf-force'} eq "yes");
my $multiconf_confmods = $opt{'with-multiconf'};
my $multiconf_spec = $opt{'with-multiconf-file'} || "multiconf.conf.in";
my $multiconf_forced = $opt{'with-multiconf-force'};
$multiconf_spec = "$top_srcdir/$multiconf_spec" if (! -f $multiconf_spec && -f "$top_srcdir/$multiconf_spec");
my @confs = parse_multiconf_spec($multiconf_spec, $multiconf_confmods, \@interesting_vars);
my @conf_names = grep { $_ ne 'error' } map { $$_{name} } @confs;
my $conf_names = join(' ', @conf_names);
my $default_conf_name = $confs[$#confs]{name};
my $numconfs = $#conf_names+1;
debugmsg("Enabled confs ($numconfs): $conf_names\nDefault conf: $default_conf_name");

# copy conffile to builddir with substitutions
copy_file($multiconf_spec, "$top_builddir/multiconf.conf",
          sub { s/^\s*ENABLED_CONFS=.*$/ENABLED_CONFS=$conf_names/;
                s/^\s*FORCED_OPTIONS=.*$/FORCED_OPTIONS=$multiconf_forced/;
              });

my @badopts;
foreach my $badopt ( ( map { ("enable-$_","disable-$_") } split(/,/,$ENV{BLACKLISTED_ENABLE_OPTIONS}) ),
                     ( map { ("with-$_","without-$_") }   split(/,/,$ENV{BLACKLISTED_WITH_OPTIONS}  ) ) ) {
  push(@badopts, "--$badopt") if ($opt{$badopt});
}
if (@badopts && !$opt{"enable-blacklisted-options"}) {
  die "multiconf error: You passed the following configure options which are " .
      "blacklisted by the current multiconf configuration script:\n" . 
      "  " . join(" ",@badopts) . "\n" .
      "These options are incorporated by the multiplexing nature of the config script " .
      "and should be handled using --with-multiconf= options appropriate to the script. " .
      "See the section 'BLACKLISTED TOP-LEVEL CONFIGURE OPTIONS' in $multiconf_spec for " .
      "more detailed usage information to solve this problem.\n";
}


# create top-level Makefile in builddir
my $makefile = "Makefile";
debugmsg("Writing makefile [$makefile] with confs: $conf_names");
open MAKEFILE, ">$makefile";
print MAKEFILE <<'EOF';
# Berkeley UPC top-level multiconf Makefile driver

# Supported multiconf configurations:
EOF
print MAKEFILE "CONFS=$conf_names\n";
print MAKEFILE <<EOF;

DEFAULT_CONF=$default_conf_name
top_srcdir=$top_srcdir
top_builddir=$top_builddir
prefix=$top_prefix
PERL=$^X
EOF

open MAKEFILE_IN, "<$top_srcdir/Makefile.multiconf";
my $oldslash = $/;
undef $/;
print MAKEFILE <MAKEFILE_IN>; # slurp
$/ = $oldslash;
close MAKEFILE_IN;

exit 0 if ($opt{'regen-makefile'});

foreach my $conf (@confs) {
  my $conf_name = $$conf{name};
  next if ($conf_name eq 'error');

  # Merge in CONF:... options & vars
  $$conf{options} .= $cond_opt{$conf_name};
  foreach my $var (keys %{$cond_env{$conf_name}}) {
    my $val = $cond_env{$conf_name}->{$var};
    $$conf{env}->{$var} = $val;
    print "Setting from command-line: $var=$val\n";
  }
  delete $cond_confs{$conf_name};

  print <<EOF;
--------------------------------------------------------------------
           === Multiconf configuring: $conf_name ===
--------------------------------------------------------------------
EOF

  # Create conf dir
  debugmsg("Creating directory: $conf_name");
  if ( ! -d $conf_name ) {
    mkdir($conf_name,0777) || die "Failed to create directory '$conf_name': $!";
  }

  # set conf_env
  my $conf_env = $$conf{env};
  %ENV = %$conf_env;
  if ($debug) {
    foreach my $var (@interesting_vars) {
      print "$var=".$ENV{$var}."\n" if (defined $ENV{$var});
    }
  }

  my $conf_options;
  $conf_options .= " " . $ENV{CONFIGURE_OPTIONS} if ($ENV{CONFIGURE_OPTIONS}); # conf file general options -- lowest priority
  $conf_options .= " " . $$conf{options}; # per-config options, medium priority
  $conf_options .= " " . join(' ',@sub_ARGV); # command-line pass-thru configure options -- highest priority

  # run configure for this conf
  my $cmd = "cd $conf_name && $config_shell$top_srcdir/configure $conf_options --prefix='$top_prefix/$conf_name' --with-multiconf-magic=$conf_name";
  if ($opt{'dry-run'}) { 
    debugmsg("Skipping $conf_name configure:\n$cmd");
    system("cd $conf_name && touch config.status && mkdir -p gasnet/other");
    copy_file("$top_srcdir/gasnet/other/perlstart.in", "$conf_name/gasnet/other/perlstart");
    open MAKEFILE,">$conf_name/Makefile";
    print MAKEFILE <<EOF;
%:
	\@echo "MULTICONF DRY RUN: $conf_name conf skipping \$@..."
EOF
    close MAKEFILE;
  } else { 
    run_command($cmd, "$conf_name configure");
  }
}

if (-s $configure_warn_file) { # non-empty warning file
  for my $FH (*debuglog, *STDOUT) {
    print $FH <<EOF;
--------------------------------------------------------------------
           === Multiconf configure warning summary ===
--------------------------------------------------------------------
EOF
    open CONFWARN,"$configure_warn_file";
    while (<CONFWARN>) { print $FH $_; }
    close CONFWARN;
    print $FH <<EOF;
--------------------------------------------------------------------
EOF
  }
}
unlink $configure_warn_file;
foreach my $conf_name (keys %cond_confs) {
  for my $FH (*debuglog, *STDOUT) {
    print $FH "WARNING: conf-specific command-line options unused for conf=$conf_name\n";
  }
}
close *debuglog;

print "\n\nSUCCESS! The configure step is now complete. You should now proceed with:\n gmake ; gmake install\n";
exit 0;
