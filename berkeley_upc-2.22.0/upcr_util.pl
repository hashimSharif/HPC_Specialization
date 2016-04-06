################################################################################
# upcr_util.pl
#
# Common support functions for Berkeley UPC tools
################################################################################
use strict;


################################################################################
## Your basic multi-purpose min() and max() functions
################################################################################
sub min ($$) { my ($a,$b) = @_; return ($a <= $b) ? $a : $b; }
sub max ($$) { my ($a,$b) = @_; return ($a >= $b) ? $a : $b; }
sub alignup ($$) { my ($a,$b) = @_; return int(($a + $b - 1) / $b) * $b; }
sub aligndown ($$) { my ($a,$b) = @_; return int($a / $b) * $b; }
sub strip_whitespace($) { my ($a) = @_; $a =~ s/\s*//g; return $a; }

# returns the length of the initial matching prefix between two strings
sub str_prefix_matchlen ($$) { 
  my ($a,$b) = @_; 
  my $i = 0;
  $a = reverse($a);
  $b = reverse($b);
  while ($a and $b and (chop($a) eq chop($b)) ) { $i++; }
  return $i; 
}

# format data size as a human-readable string
sub size_str($) {
  my $sz = shift;
  my $require_integer = shift;
  $require_integer = 0 if (!defined $require_integer);  
  if ($require_integer) {
    my $val = int($sz)." bytes";
    for my $ext (" KB"," MB"," GB"," TB") {
      $sz /= 1024;
      if ($sz eq int($sz)) {
        $val = $sz.$ext 
      } else {
	last;
      }
    }
    return $val;
  } else {
    return sprintf("%.3f",$sz/(1024*1024*1024*1024)) . " TB" if ($sz > 1024*1024*1024*1024);
    return sprintf("%.3f",$sz/(1024*1024*1024)) . " GB" if ($sz > 1024*1024*1024);
    return sprintf("%.3f",$sz/(1024*1024)) . " MB" if ($sz > 1024*1024);
    return sprintf("%.3f",$sz/(1024)) . " KB" if ($sz > 1024);
    return $sz . " bytes";
  }
}

# convert human-readable size into numerical value
sub parse_size($$) {
  my $sz = shift;
  my $default_ext = shift;
  $default_ext = "M" if (!defined $default_ext);
  $sz .= $default_ext if ($sz =~ /^\s*([0-9]+)\s*$/);
  return $1*1024*1024*1024*1024 if ($sz =~ /^\s*([0-9]+)\s*[Tt]/);
  return $1*1024*1024*1024 if ($sz =~ /^\s*([0-9]+)\s*[Gg]/);
  return $1*1024*1024 if ($sz =~ /^\s*([0-9]+)\s*[Mm]/);
  return $1*1024 if ($sz =~ /^\s*([0-9]+)\s*[Kk]/);
  return $1 if ($sz =~ /^\s*([0-9]+)\s*[Bb]/);
  die "unrecognized size expression: $sz\n";
} 

################################################################################
## search the PATH for executable and return usable filename
################################################################################
sub find_exec ($$$)
{
    my ($name, $exe_suffix, $silent) = @_;

    if ($name =~ m:/:) {
      # bug1846: need to use -f on cygwin, because -x returns false negatives for some filesystems
      return ($name . $exe_suffix) if ($exe_suffix && -f ($name . $exe_suffix));
      return $name if -x $name;
      return undef if ($silent);
      die "'$name' does not exist or is not an executable\n";
    }

    foreach ('.', split ':', $ENV{PATH}) {
        my $path = "$_/$name";
        return ($path . $exe_suffix) if ($exe_suffix && -f ($path . $exe_suffix));
        return $path if -x $path;
    }

    return undef if ($silent);
    die "cannot find '$name' in \$PATH\n";
}

################################################################################
## verify a given command references an existing executable, if not then attempt
## to find a matching executable in the PATH and modify the command to use it
################################################################################
sub verify_exec($$$) {
    my ($name, $exe_suffix, $silent) = @_;
    my $progname = $name;
    my $args = "";
    # strip off args, with care for quoting
    if ($progname =~ m/^'([^']+)'( .*)$/ || 
        $progname =~ m/^"([^"]+)"( .*)/ || 
        $progname =~ m/^(\S+)( .*)/ ) { 
      $progname = $1;
      $args = $2;
    }
    my $fullpath = ($progname =~ m:^/:);
    # common case - we have a correct full path
    return $name if ($fullpath && (-x $progname || ($exe_suffix && -f ($progname.$exe_suffix))));

    # program was not found as specified - search the path
    my $bareprog = $progname;
    if ($bareprog =~ m@/([^/]+)$@) {
      $bareprog = $1;
    }
    my $pathprog = undef;
    if ($bareprog) {
      $pathprog = find_exec($bareprog, $exe_suffix, 1);
    }
    if ($pathprog) { # found it in PATH
      if ($fullpath) {
 	print "WARNING: '$progname' not found - using '$pathprog' instead.\n";
      }
      return "'$pathprog'$args";
    } elsif ($silent) { 
      return undef;  
    } else {
      print "WARNING: unable to find '$progname' - check conf files or re-run configure\n";
      return $name; # return unmodified input and hope for the best (might not be used)
    }
}


################################################################################
## Given a string, split it into a list of words, like split(/ /,$foo) except
## that we honor single- and double-quotes, and ignore leading whitespace.
##
## usage: 
##  @a = split_quoted($string, "while parsing whatever");
## The second argument (optional) is used when generating error messages.
################################################################################
sub split_quoted
{
    my $string = shift;
    my $where = shift;
    my @result = ();
    my $current = '';

    # Remove leading whitespace
    $string =~ s/^\s*//;

    # Loop while whitespace or quotes remain
    while ($string =~ m/^([^'"\s]*)(['"]|\s+)(.*)$/) {
        $current .= $1;
	my ($sep, $post) = ($2,$3);

	if ($sep eq '"') {
	   unless ($post =~  m/^([^"]*)"(.*)$/) { die ("Unbalanced double quotes $where\n"); }
           $current .= $1;
	   $string = $2;
	} elsif ($sep eq "'") {
	   unless ($post =~  m/^([^']*)'(.*)$/) { die ("Unbalanced single quotes $where\n"); }
           $current .= $1;
	   $string = $2;
	} else {
	   push @result, $current;
	   ($string, $current) = ($post, '');
	}
    }
    $current .= $string;
    push @result, $current if (length $current);

    return @result;
}

################################################################################
## Do actual parsing of config file
##  - Vaguely adapted from the Perl Cookbook, p 299
################################################################################
sub parseconfig {
    my ($config_file, $required, $conf, $section) = @_;

    # Optional 4th argument is for selecting "[section]" of the config file
    $section = '' unless(defined $section);
    my $filter = '^'; # always matches

    if (!open(CONFIG, $config_file)) {
        unless (-e $config_file) {
            die "Config file '$config_file' is missing\n" if ($required);
            return;
        }
        # IF the file exists but we could not open() then die.
        # The alternative is to silently ignore the file, potentially causing much confusion.
        die "Config file '$config_file' is not a regular file\n" unless (-f $config_file);
        die "Config file '$config_file' is not readable\n" unless (-r $config_file);
        die "Config file '$config_file' could not be opened\n";
    }
    # Some platforms allow open() on a directory (note that -d follows symlinks)
    die "Config file '$config_file' is not a regular file\n" if (-d $config_file);

    my $linenum = 0;
    my $line = "";
    my $errname ="";
    while (<CONFIG>) {
        $linenum++;
        $errname = "${config_file}:${linenum}::" if ($line eq "");
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
        if ($line =~ m/^\[(.*)\]$/) {    # Start new [section]
           $filter = "^($1)\$";
           $line = '';
           next;
        }
        unless ($section =~ m/$filter/) { # Skip lines in non-matching section(s)
           $line = '';
           next;
        }
        unless ($line =~ /^\s*\w+\s*=/) {
            die "$errname Invalid line (no '=', nor a comment):\n $line\n";
        }
        # Split into 2 parts at first '='; Allow spaces around '='.
        my ($var, $val) = split /\s*=\s*/, $line, 2;
        # Read each setting, checking to see that it's a valid variable name. 
        unless (defined($conf->{$var})) {
            die "$errname unknown config setting '$var'\n";
        }
        $conf->{$var} = $val;
        $line = "";
    }
    close CONFIG;
    unless ($line eq "") {
        die "$errname unterminated line at EOF:\n $line\n";
    }
    return;
}

# decode a upcc-encoded string
sub upcc_decode {
    my ($in) = @_;
    $in =~ s/@([0-9A-Za-z][0-9A-Za-z])/chr(hex($1))/ge;
    return $in;
}

# user's home directory
sub userhome {
    return ($ENV{'HOME'} || (getpwuid($<))[7]);
}

1;
