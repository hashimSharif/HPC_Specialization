#!/usr/bin/env perl

################################################################################
################################################################################
##  'upcc_multi'  multiplexing driver script for the Berkeley UPC compiler 
################################################################################
################################################################################


require 5.005;
use strict;
use File::Basename;
use Cwd;

#########################
### BEGIN SHARED CODE ###
#########################

use vars qw($debug $disable_upcc *debuglog);

# enable debug messages (for debugging this script)
$debug = 0 || grep /^-?-v(erbose)?$/, @ARGV;
sub debugmsg($) {
  my $msg = shift;
  print STDERR "$msg\n" if ($debug);
  if (*debuglog{IO}) {
    local *FH = *debuglog;
    print FH "$msg\n" 
  }
}
debugmsg("Running as: $0 ".join(" ",map(m/[^A-Za-z0-9_-]/ ? "'$_'" : $_,@ARGV)));

my %prohibited_conf_names = qw(bin etc man share upcc upcrun upcc_multi);
my $legal_confname_pat = "[A-Za-z0-9_][A-Za-z0-9_-]*";

sub parse_multiconf_spec {
    my ($config_file, $config_confmods, $interesting_vars) = @_; 
    my %int_vars;
    my @confs;

    if (!open(CONFIG, $config_file)) {
       die "Multiconf spec file '$config_file' is missing\n"
    } else {
       debugmsg("Reading multiconf spec file [$config_file]");
    }

    my $in_global = 1;
    my %ENV_GLOBAL;
    my %enabled_confs;
    my %all_confs;

    my $linenum = 0;
    my $line = "";
    my $errname ="";
    while (<CONFIG>) {
        $linenum++;
        $errname = "ERROR at ${config_file}:${linenum}::" if ($line eq "");
        my $newline = "$_";
        $newline =~ s/^\s+//;            # chop leading whitespace
        $newline =~ s/^#.*//;            # drop comment lines (full lines only)
        if ($newline =~ /.*\\$/) {       # backslash line continuation
           $newline =~ s/\\$//;          # chop trailing backslash
           $newline =~ s/\s+$//;         # chop trailing whitespace
           $line = $line . $newline;
           next;
        }
        $newline =~ s/\s+$//;            # chop trailing whitespace
        $line = $line . $newline;
        next unless length($line);       # ignore empty lines
        if ($line =~ /^\s*;\s*;\s*;\s*$/) { # end of section
	  if (!$in_global) { $line = ""; last; } # begin comment/documentation section
	  $in_global = 0;
	  %ENV_GLOBAL = %ENV;
	  die "$errname ENABLED_CONFS variable not defined in global section:\n $line\n" unless (defined $ENV{ENABLED_CONFS});
	  %enabled_confs = map { $_ => 1 } split(/[,\s]+/,$ENV{ENABLED_CONFS});
	  $config_confmods = trim_whitespace($config_confmods);
	  if ($config_confmods && $config_confmods !~ m/^[+-]/) {
            %enabled_confs = map { $_ => 1 } split(/[,\s]+/,$config_confmods);
	  } else {
            for my $mod (split(/[,\s]+/,$config_confmods)) {
	      if ($mod =~ m/^\+($legal_confname_pat)$/) {
	        $enabled_confs{$1} = 1;
	      } elsif ($mod =~ m/^\-($legal_confname_pat)$/) {
	        debugmsg("Ignoring confmod $mod") unless $enabled_confs{$1};
	        delete $enabled_confs{$1};
	      } else {
	        die "malformed conf_options: $config_confmods\n";
	      }
	    }
	  }
	  if (my @badconfs = grep !/^$legal_confname_pat$/, %enabled_confs) {
	    die "$errname illegal confnames in ENABLED_CONFS: ".join(' ',@badconfs)."\n";
	  } else {
	    debugmsg("Final ENABLED_CONFS=". join(' ',keys %enabled_confs));
	  }

        } elsif ($line =~ /^ALIAS\s+($legal_confname_pat)\s*=\s*($legal_confname_pat)/o) { # alias
          die "$errname ALIAS only permitted in global section:\n $line\n" unless ($in_global);
          my ($from, $to) = ($1, $2);
          if ($config_confmods =~ s/\b$from\b/$to/g) {
            print STDERR "WARNING: rewriting deprecated config name $from as $to\n";
          }
        } elsif ($line =~ /;/) { # conf spec
	  die "$errname missing global section terminator:\n $line\n" if ($in_global);
          unless ($line =~ m/^\s*(\S+)\s*;([^;]*);([^;]*);([^;]*)$/) {
            die "$errname Malformed conf spec:\n $line\n";
          }
          my ($conf_name,$conf_options,$conf_select,$conf_strip) = ($1,$2,$3,$4);
          if (!($conf_name =~ /^$legal_confname_pat$/) || defined $prohibited_conf_names{$conf_name}) {
            die "$errname Invalid conf-name:\n $line\n".
	        " Must match pattern: $legal_confname_pat and not be: ".join(' ',%prohibited_conf_names);
          }
          if (defined $all_confs{$conf_name}) {
            die "$errname duplicate conf-name:\n $line\n" unless ($conf_name eq 'error'); 
          }
	  $all_confs{$conf_name} = 1;
          $conf_select = trim_whitespace($conf_select);
	  $conf_select = "true" if (!$conf_select); # default to match
          $conf_strip = trim_whitespace($conf_strip);
          my @conf_strip_args;
          foreach my $arg (split /[,\s]+/, $conf_strip) {
            if ($arg =~ /^\s*-?-?([A-Za-z0-9][A-Za-z0-9_-]+)\s*$/) {
              push @conf_strip_args, $1;
            } else {
              die "$errname Invalid upcc-arg-strip: [$arg]\n $line\n";
            }
          }
          my %newconf;
          $newconf{name} = $conf_name;
          $newconf{options} = $conf_options;
          $newconf{select} = $conf_select;
          $newconf{strip} = \@conf_strip_args;
          my %envcopy = %ENV;
          $newconf{env} = \%envcopy;
	  %ENV = %ENV_GLOBAL;
          if (0) {
            foreach my $key (keys %{$newconf{env}}) {
              print "$key=".$newconf{env}{$key}." " if ($key eq "FOO" || $key eq "HOME");
            }
            print "\n";
          }
	  my $enabled = "enabled";
          if ($enabled_confs{$conf_name} || ($conf_name eq 'error')) {
	    push @confs, \%newconf;
	  } else {
	    $enabled = "disabled";
          }
          debugmsg("Read $enabled conf: $conf_name ; $conf_options ; $conf_select ; " . join(',',@conf_strip_args));
        } elsif ($line =~ /^\s*\w+\s*=/) { # variable setting
          # Split into 2 parts at first '='; Allow spaces around '='.
          my ($var, $val) = split /\s*=\s*/, $line, 2;
	  $val =~ s/\s+$//g; # remove trailing unquoted space
          if ($val =~ m/^'(.*?)'$/) {
            $val = $1;
          } else {
            if ($val =~ m/^"(.*?)"$/) { $val = $1; }
            # perform expansion of embedded variables
	    $val =~ s/(^|[^\\])\$([A-Za-z0-9_]+)/$1$ENV{$2}/g;
          }
	  if ($in_global && defined $ENV{$var}) { # global vars are overridden by user vars
            debugmsg("NOT setting $var='$val' - (overridden by present value=".$ENV{$var}.")");
	  } else {
            debugmsg("Setting $var='$val'" . (defined $ENV{$var} ? " (overridding ".$ENV{$var}.")" : ""));
            $ENV{$var}=$val;
	  }
	  $int_vars{$var} = 1 unless (grep /^$var$/, qw(CONFIGURE_OPTIONS FORCED_OPTIONS ENABLED_CONFS));
        } else {
            die "$errname Invalid line (no '=', ';', nor a comment):\n $line\n";
        }
        $line = "";
    }
    close CONFIG;
    unless ($line eq "") {
        die "$errname unterminated line at EOF:\n $line\n";
    }
    for my $confname (keys %enabled_confs) {
      die "ERROR: confname '$confname' specified by ENABLED_CONFS is not present in $config_file\n" unless ($all_confs{$confname});
    }
    unless ($#confs >= 0) {
        die "ERROR: $config_file contains no enabled conf specifications!";
    }
    return @confs;
}

sub absolute_path($) {
  my $name = shift;
  $name = getcwd()."/$name" unless ($name =~ m@^/@);
  # file-system independent transforms
  $name =~ s@//@/@g;
  $name =~ s@/\./@/@g;
  $name =~ s@/[^/]+/\.\./@/@g;
  return $name;
}

sub copy_file($$) {
  my ($in, $out, $filter) = @_;
  $in = absolute_path($in);
  $out = absolute_path($out);
  debugmsg("Copying $in -> $out");
  my $outfinal;
  if ($in eq $out) { 
    if ($filter) {
      $outfinal = $out;
      $out .= ".tmp";
    } else {
      debugmsg("no-op copy skipped"); 
      return; 
    }
  }
  open FIN, "<$in" or die "Failed to open $in: $!\n";
  open FOUT, ">$out" or die "Failed to open $out: $!\n";
  if ($filter) {
    while (<FIN>) {
      &$filter();
      print FOUT or die "Failed to write to $out: $!\n";
    }
  } else {
    my $oldslash = $/;
    undef $/;
    print FOUT <FIN> or die "Failed to write to $out: $!\n"; # slurp
    $/ = $oldslash;
  }
  close FIN  or die "Failed to close $in: $!\n";
  close FOUT or die "Failed to close $out: $!\n";
  if ($outfinal) {
    unlink $outfinal;
    rename $out, $outfinal; 
  }
}
sub trim_whitespace($) { my ($a) = @_; $a =~ s/^\s*//g; s/\s*$//g; return $a; }

sub run_command($$) {
  my $cmd = shift;
  my $context = shift;
  my $ignore_failure = shift;
  debugmsg("Running $context: \n$cmd");
  system($cmd);
  my $status = $?;
  if ($status == -1) {
    my $msg = "Failed to spawn command for $context: '$cmd' : $! (status=$status)\n";
    debugmsg($msg);
    die $msg;
  } elsif ($status & 127) {
    my $msg = "Command for $context exited with signal ".($status & 127)."\n";
    debugmsg($msg);
    die $msg;
  } elsif ($status >> 8 && !$ignore_failure) {
    my $msg = "Failed during $context, exit=".($status >> 8)."\n";
    debugmsg($msg);
    die $msg;
  } else {
    debugmsg("$context successful\n");
  }
}


if ($disable_upcc) { return 1; }
#######################
### END SHARED CODE ###
#######################

# find where this script is located
my $startdir = getcwd();
my ($upcr_home, $upcr_etc, $upcr_bin, $upcr_subbin);
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
my $conf_file = "$upcr_bin/multiconf.conf";
if (-f $conf_file) { # build tree
    $upcr_home = $upcr_etc = $upcr_bin;
    $upcr_subbin = "";
} else { # install tree
    $upcr_bin =~ m@^(.*?)/bin$@;
    $upcr_home = $1;
    $upcr_etc = "$upcr_home/etc";
    $conf_file = "$upcr_etc/multiconf.conf";
    $upcr_subbin = "bin/";
    unless (-f $conf_file) {
       die "multiconf.conf neither in '$upcr_bin' directory, nor in '$upcr_etc'\n";
    }
}

### read config file ###
my @confs = parse_multiconf_spec($conf_file);

### parse arguments ###
# avoid getopt here, to eliminate the complication of finding a non-buggy version of that module
# we don't need exact parsing here - just assume that everything that looks like an argument is one
my %opt = map { $_ => 1 } split(/[,\s]+/,$ENV{FORCED_OPTIONS});
foreach my $arg (@ARGV) {
  if ($arg =~ m/^--?([A-Za-z0-9-_]+)(=.*)?$/) {
    $opt{$1} = 1;
  }
}
debugmsg("Options: ".join(" ",keys %opt));

# --show-confs : output multiconfs
my $show_confs = $opt{'show-confs'};
print STDERR "Multiconfs enabled in $conf_file:\n" if ($show_confs);

### choose config ###
foreach my $conf (@confs) {
  my $conf_name = $$conf{name};
  my $conf_select = $$conf{select};
  my $conf_options = $$conf{options};
  my $conf_strip = $$conf{strip};

 # my $result = eval eval "$conf_select";
  my $err;
  my $result = eval $conf_select; 
  $err = join(' ',$@) if ($@);
  chomp($err);
  debugmsg("$conf_name: $conf_select => " . ($err?"ERROR: $err":($result?"TRUE":"FALSE")));
  my $sub_upcc = "$upcr_home/$conf_name/${upcr_subbin}upcc";
  my $sub_upcc_pl = "${sub_upcc}.pl";
  if ($show_confs) {
    print STDERR "$conf_name ; $conf_options ; $conf_select ; ". join(',',map {"-$_"} @$conf_strip) . (-f $sub_upcc_pl?"":" [MISSING]") ."\n"
      unless ($conf_name eq 'error');
  } elsif ($result && $conf_name eq 'error') {
    my $msg = $conf_options;
    $msg =~ s/^\s+//;
    $msg =~ s/\s+$//;
    die "upcc: $msg\n";
  } elsif ($result && ! -f $sub_upcc_pl) {
      print STDERR "WARNING: skipping match for $conf_name, because $sub_upcc_pl does not exist.\n".
                   " You may need to update your Berkeley UPC install or the configure file at: $conf_file\n";
  } elsif ($result) {
    ### strip arguments ###
    my @sub_ARGV;
    if (!@$conf_strip) { @sub_ARGV = @ARGV; }
    else {
      debugmsg("stripping args: ".join(',',@$conf_strip));
      foreach my $arg (@ARGV) {
        unless ($arg =~ m/^--?([A-Za-z0-9-_]+)$/ && grep /^$1$/, @$conf_strip) {
          push @sub_ARGV, $arg;
	}
      }
    }

    $ENV{'UPCRI_CONF_NAME'} = $conf_name;
    $ENV{'UPCRI_EXTRA_HELP'} = $conf_file; # propagate documentation section

    ### run selected install ###
    my $perlpath = $^X; # path to perl interpreter
    if (-x $perlpath) {
      unshift @sub_ARGV, $sub_upcc_pl;
      if ($ENV{PERLSTART_FLAGS}) { unshift @sub_ARGV, split(/\s+/, trim_whitespace($ENV{PERLSTART_FLAGS})); }
      unshift @sub_ARGV, $perlpath; 
    } elsif (-x $sub_upcc) { # try perlstart
      unshift @sub_ARGV, $sub_upcc;
    } else { # last-ditch effort to find perl 
      foreach my $perl ("/usr/bin/perl", "/bin/perl", "/usr/local/bin/perl") {
        if (-x $perl) {
          unshift @sub_ARGV, $sub_upcc_pl;
          unshift @sub_ARGV, $perl; 
	}
      }
    }
    debugmsg("Invoking: ".join(' ',map { "'$_'" } @sub_ARGV));
    exec @sub_ARGV or die "ERROR: Failed to exec sub-upcc:\n  ".join(' ',@sub_ARGV)."\n  error was: $!";
  }
}
exit 0 if ($show_confs);

die "ERROR: No matching Berkeley UPC configuration found in $conf_file!\n";

1;

