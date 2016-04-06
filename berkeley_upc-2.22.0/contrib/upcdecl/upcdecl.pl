#!/usr/bin/env perl

# Vim settings: (indent of 2 spaces)
# ex:set ts=2 et:

# UPC version of cdecl
# Based off the grammar from the C version of cdecl
# Why not update the C version?  It relies on flex and bison, and this
# is completely self-contained.  The grammar was also fairly ambiguous
# and relied on the default S/R conflict handling mechanism of bison/yacc.

# --------------------------------------------------------------------------
#
# Copyright (c) 2005, 2006 Adam Leko, All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# (1) Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# (2) Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
# (3) Neither the name of Lawrence Berkeley National Laboratory,
# U.S. Dept. of Energy nor the names of its contributors may be used to
# endorse or promote products derived from this software without
# specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# --------------------------------------------------------------------------

# new in v0.6:
#  - added upc_*_t types
#  - add UPC keywords as illegal identifiers
#  - add support for THREADS dimension
# new in v0.5:
#  - added missing tokens in @tok_keywords (Dan)
#  - fixed help screen, was too wide (Adam)
#  - better error descriptions (Dan)
#  - rewrite noalias to restrict (Dan)
#  - -V option (Adam)
#  - man page, -H option for help2man (Adam)
#  - more semantic checks (Dan, Adam)
#  - apparently using '' is more efficient than "" when no variables have to
#    be expanded (Adam)
#  - minor grammar tweak for shared english expressions (blocksize is now 
#    optional) (Dan, Adam)
#  - small fix to path inclusion (Dan)
# new in v0.4: (Adam)
#  - int shared x; and int const x; are parsed correctly
#  - easier to specify blocksize in english (see grammar)
#  - can parse parens around blocksize in english ("invertible")
#  - added strict/relaxed keywords
#  - allow "shared array of" syntax
#  - fixed help screen
#  - added "indef" synonym
#  - fixed output for 'explain shared [] int x' (should be indef, got cyclic before)
#  - allow "local" to be parsed as type qualifier, added checks for local/shared conflicts
#  - new flag "-v" (or "set upcverbose") spits out local qualifiers on english descriptions
#    of non-shared data
# new in v0.3:
#  - fixed terminal support (Dan Bonachea)
# new in v0.2:
#  - added immediate input mode (Adam)
# v0.1: initial alpha release (Adam Leko)

use strict;

########################################################################
# global defs

my $version = '0.6';
my $debug = 0;

# setup include path for installed libraries
my $invokename = $0;
if ($invokename =~ m@^(.*?)/bin/[^/]*$@) {
  my $dir = "$1/include";
  #print "$dir\n";
  push @INC, $dir if (-d $dir);
} elsif ($0 =~ m@^(.*?)/[^/]*$@) {
  my $dir = $1;
  push @INC, $dir if (-d $dir);
}


# setup use of ReadLine
BEGIN { $ENV{EDITOR} = ''; } # Ensure ReadLine::Perl behaves properly
my $term = undef;
if (-t STDIN) {
 $term =
 # first try our bundled version of Term::ReadLine::Perl
 eval { require 'upcdecl_R.pl'; use Term::ReadLine; require 'upcdecl_TRP.pl' ; 
       new Term::ReadLine::Perl 'upcdecl' } ||
 eval { use Term::ReadLine; new Term::ReadLine 'upcdecl' } || # use whatever is available
  # To get better command-line editing, install the Term::Readline::Gnu
  # CPAN module ("cpan Term::ReadLine::Gnu")
  # (debian: apt-get install libterm-readline-gnu-perl)
 undef; # give up
}

my $has_color = eval 'use Term::ANSIColor;1' || 0;

my %opts = (
  quiet => 0,
  pointerspaces => 1,
  create => 0,
  files => [],
  testfile => undef,
  immediateinput => undef,
  upcverbose => 0
);

# tokens that can't be NAMEs
my @tok_keywords = qw/declare as cast into explain help quit exit array of function returning pointer to struct union enum int char double float void short long unsigned signed const volatile noalias auto extern register static restrict local indefinite automatic cyclic blocksize upc_lock_t upc_file_t upc_flag_t upc_off_t size_t THREADS MYTHREAD UPC_MAX_BLOCK_SIZE upc_barrier upc_notify upc_wait upc_localsizeof upc_blocksizeof upc_elemsizeof upc_fence upc_forall shared strict relaxed/;

# tokens that were returned
my @ret_tokens;

# column #
my $col;

# parsing C code (explain vs. declare/cast)
my $parse_C = 1;

########################################################################
# entry point -> just run main()
main();

# main program
sub main {
  parseargs();
  # if stdin not a tty, then don't use readline and be quiet
  # (override cmd line args)
  if (!(-t STDIN)) {
    $term = undef;
    $opts{'quiet'} = 1;
  }
  # if stdout not a tty, don't use colors
  if (!(-t STDOUT)) {
    $has_color = 0;
  }
  # immediate input?
  if (defined $opts{'immediateinput'}) {
    # immediate -> quiet
    $opts{'quiet'} = 1;
    my $res;
    eval {
      $_ = $opts{'immediateinput'};
      $res = program();
    };
    if ($@) {
      output_error($@);
      exit(-1);
    } else {
      print $res . "\n";
      exit(0);
    }
  }
  # test mode overrides all other settings
  if (defined $opts{'testfile'}) {
    exit(dotests($opts{'testfile'}));
  }
  # if we get any files in, then just iterate through them in quiet mode
  my $fls = $opts{'files'};
  if (@$fls > 0) {
    $opts{'quiet'} = 1;
    my $fl;
    foreach $fl (@$fls) {
      open INPUT, $fl or die "Can't open $fl\n";
      while (<INPUT>) {
        parse_input();
      }
      close INPUT;
    }
    exit(0);
  }
  print "Type `help' or `?' for help\n" unless $opts{'quiet'};
  # loop until no more input
  if ($term) {
    $term->MinLine(1);
    while (defined ($_ = $term->readline(getprompt()))) {
      parse_input();
    }
  } else {
    print getprompt();
    while (<STDIN>) {
      parse_input();
      print getprompt();
    }
  }
  print "\n" unless $opts{'quiet'};
  exit(0);
}

sub getprompt {
  if ($opts{'quiet'}) {
    return '';
  } else {
    return 'upcdecl> ';
  }
}

# run tests
sub dotests {
  my $fl = shift;
  my @failed = ();
  open INPUT, $fl or die "Can't open test file $fl\n";
  while (<INPUT>) {
    my @fields = split ' \| ';
    my $res;
    eval {
      $_ = $fields[0];
      $res = program();
    };
    if ($@) {
      push @failed, $fields[0];
      failtest("$@", $fields[1], '[error]');
    } else {
      my $r = $res; chomp $r;
      my $e = $fields[1]; chomp $e;
      if (minwhitespace($e) eq minwhitespace($r)) {
        passtest("Passed test '$fields[0]'");
      } else {
        push @failed, $fields[0];
        failtest("Wrong output for '$fields[0]'", $e, $r);
      }
    }
  }
  close INPUT;
  if (@failed > 0) {
    if ($has_color) {
      print color('bold red') . "Failure! Failed tests:\n" . color('reset');
    } else {
      print "Failure! Failed tests:\n";
    }
    my $failt;
    foreach $failt (@failed) {
      print "  $failt\n";
    }
    return -1;
  } else {
    if ($has_color) {
      print color('bold green') . "Passed all tests\n" . color('reset');
    } else {
      print "Passed all tests\n";
    }
    return 0;
  }
  return @failed;
}

# put the min amount of whitespace in a string
sub minwhitespace {
  my $val = shift;
  $val =~ s/(\W)\s*(\w)/$1$2/g;
  $val =~ s/(\w)\s*(\W)/$1$2/g;
  $val =~ s/(\W)\s*(\W)/$1$2/g;
  return $val;
}

sub failtest {
  my $msg = shift;
  my $expected = shift;
  my $got = shift;
  if ($has_color) {
    print color('red') . 'Failed test:' . color("reset") . ' ' .
      color('bold white') . $msg . color('reset') . "\n";
  } else {
    print "Failed test: $msg\n";
  }
  print "  Expected: $expected\n  Got     : $got\n";
}

sub passtest {
  my $msg = shift;
  if ($has_color) {
    print color('green') . 'Passed test:' . color('reset') . " $msg\n";
  } else {
    print "Passed test: $msg\n";
  }
}

# show usage screen
sub usage {
  my $suppressversion = shift;
  if (!$suppressversion) {
    print "upcdecl version $version";
    print " (Berkeley UPC version ".$ENV{'UPCR_VERSION'}.")" if ($ENV{'UPCR_VERSION'});
    print "\n";
  }
  print <<EOF
Usage: upcdecl [options] [ explain | declare | cast | files... ]

Options:
    -h
            See this message.
    -q
            Suppress upcdecl> prompt. Equivalent to the "quiet" set option.
    -r
            Don't use Term::ReadLine for input. Use this option if you have 
            problems with the Perl-based ReadLine that is bundled with the 
            program. Typing `set' with no arguments at the upcdecl prompt will 
            tell you which module is being used for input.
    -p
            Disable spaces around pointers in C output. (Eg, 
            "declare f as pointer to pointer to int" -> "int **f" instead of
            "int * * f".) Equivalent to the "nopointerspaces" set option.
    -c
            Create compilable output. Adds ; to variable declarations and {} to
            function declarations in "declare" output. Equivalent to the
            "create" set option.
    -t <test file>
            Test using file as input. The test file should have the following
            format for each line: input | expected output. Not useful for end
            users.
    -v
            Verbose UPC english explanations. Include implicit "local" in
            english output ("explain int c" -> "declare c as local int").
            Equivalent to the "upcverbose" set option.
    -V
            Show upcdecl version and exit.
EOF
}

# parse command-line args, avoided using builtin GetOpt due to reasons
# listed in BUPC's upcc.pl script
sub parseargs {
  my $arg;
  my @arglist = @ARGV;
  my $files = $opts{'files'};
  my $first = 1;
  my $isimmediateinput = 0;
  my @immediate = ();
  while ($arg = shift @arglist) {
    if ($arg =~ m/^-(.*)/) {
      my $i;
      for ($i = 0; $i < length $1; $i++) {
        my $opt = substr($1, $i, 1);
        if ($opt eq 't') {
          my $tf = shift @arglist;
          $opts{'testfile'} = $tf;
        } elsif ($opt eq 'q') {
          $opts{'quiet'} = 1;
        } elsif ($opt eq 'p') {
          $opts{'pointerspaces'} = 0;
        } elsif ($opt eq 'r') {
          $term = undef;
        } elsif ($opt eq 'c') {
          $opts{'create'} = 1;
        } elsif ($opt eq 'H') {
          usage(1);
          exit(0);
        } elsif ($opt eq 'h') {
          usage();
          exit(0);
        } elsif ($opt eq 'v') {
          $opts{'upcverbose'} = 1;
        } elsif ($opt eq 'V') {
          print "upcdecl version $version\n";
          exit(0);
        } else {
          print STDERR "Error: invalid option $opt\n";
          usage();
          exit(-1);
        }
      }
    } else {
      if ($first) {
        # first argument is the first token of a program means that we take the
        # cmd line args as input
        if (isprogram($arg)) {
          $isimmediateinput = 1;
        }
      }
      if ($isimmediateinput) {
        push @immediate, $arg;
      } else {
        push @$files, $arg;
      }
      $first = 0;
    }
  }
  # convert immediate array to string input if we're doing immediate input
  if ($isimmediateinput) {
    $opts{'immediateinput'} = join ' ', @immediate;
  }
}

sub output_error {
  my $err = shift;
  $err = "Error: ".$err if (!($err =~ /error|warning/i));
  $err =~ s/\n$//g;
  unless ($debug) { # suppress upcdecl line information 
    $err =~ s/ at \S+\/upcdecl.pl line [0-9]+(?:, \S+ (?:line|chunk)? [0-9]+)?\./\./;
  }
  print "$err\n";
}
sub output_warning {
  output_error("Warning: ".shift);
}

# call the parser with some input
sub parse_input {
  @ret_tokens = ();
  $col = 0;
  eval {
    print program() . "\n";
  };
  output_error($@) if ($@);
}

########################################################################
# lexer functions

# tokenizer
# kind of icky, rewrite string in place using regular expressions
# good thing this isn't performance-sensitive
sub tokenize {
  # eat comments and whitespace
  s/^([ \t\n]+)// and return recordtok($1, '');
  s/^(\#.*)// and return recordtok($1, '');
  # variables/numbers/symbols
  s/^([A-Z_a-z][0-9A-Z_a-z]*)// and return recordtok($1, shorthand($1));
  s/^([0-9]+)// and return recordtok($1, $1);
  s/^([\Q,?*+-\%\/&;()[]\E])// and return recordtok($1, $1);
  # if we get here, an invalid token
  s/^(.)// and die "Invalid character $1";
}

# makes a record of column #
sub recordtok {
  my $intok = shift;
  my $retval = shift;
  if (!($intok eq '')) {
    $col += length($intok);
  }
  return $retval;
}

# expands shorthands
sub shorthand {
  my $t = shift;
  if    ($t eq 'character') { return 'char'; }
  elsif ($t eq 'constant') { return 'const'; }
  elsif ($t eq 'enumeration') { return 'enum'; }
  elsif ($t eq 'func') { return 'function'; }
  elsif ($t eq 'integer') { return 'int'; }
  elsif ($t eq 'ptr') { return 'pointer'; }
  elsif ($t eq 'ret') { return 'returning'; }
  elsif ($t eq 'structure') { return 'struct'; }
  elsif ($t eq 'indef') { return 'indefinite'; }
  elsif ($t eq 'noalias') { return 'restrict'; }
  else { return $t; }
}

# grab the next nonempty token
sub nexttok {
  if (@ret_tokens) {
    return shift(@ret_tokens);
  }
  while ($_) {
    my $token = tokenize();
    if (issharedtypename($token)) {
      returntok($token);  # bug2953: filthy hack - implicit shared qualifier on incomplete shared type
      return 'shared';
    }
    if (!($token eq '')) {
      return $token;
    }
  }
  # no more tokens left
  return '';
}

# adds a token back to the token stream (icky but works)
sub returntok {
  my $tok = shift;
  unshift(@ret_tokens, $tok);
}

# returns if we're at the end of this sentence
sub isdone {
  my $t = shift;
  return ($t eq '' || $t eq ';');
}

# returns if a token is a number
sub isnumeric {
  my $tok = shift;
  return ($tok =~ m/^[0-9]+$/ || $tok eq 'THREADS' || $tok eq 'MYTHREAD');
}

sub isnumericexpr {
  my $tok = shift;
  return (isnumeric($tok) || isname($tok) || $tok =~ m/^[+\-\(]$/);
}

sub numericexpr {
  my $t = nexttok();
  if (not isnumericexpr($t)) {
     synerror("expected numeric expression", $t);
  } 
  my $lhs;
  if ($t eq '+' || $t eq '-') { # unary operators
    my $subexpr = numericexpr();
    return "$t$subexpr";
  } elsif ($t eq '(') { # parentheses
    my $subexpr = numericexpr();
    my $nt = nexttok();
    if ($nt ne ')') {
      synerror("unmatched parentheses in numerical expression", $nt);
    }
    $lhs = "( $subexpr )";
  } elsif (isnumeric($t) || isname($t)) { # LHS
    $lhs = $t;
  } else {
      synerror("internal error in numericexpr", $t);
  }
  my $nt = nexttok();
  if ($nt =~ m/^[+\-\*\%\/]$/) { # binary operator
      my $rhs = numericexpr();
      return "$lhs $nt $rhs";
  } else {
      returntok($nt);
      return $lhs;
  }
}

# returns if a token is a name
sub isname {
  my $t = shift;
  my $tok;
  # test against keywords
  foreach $tok(@tok_keywords) {
    if ($t =~ m/^($tok)/) {
      return 0;
    }
  }
  # else test against regexp
  $t =~ m/^([A-Z_a-z][0-9A-Z_a-z]*)/;
}

########################################################################
# misc functions

# member of a list?
sub member {
  my $t = shift;
  my $elem;
  foreach $elem (@_) {
    if ($elem eq $t) {
      return 1;
    }
  }
  return 0;
}

sub synerror {
  if (!$opts{'quiet'}) {
    # subtract off tokens that were put back
    my $t;
    foreach $t(@ret_tokens) {
      $col -= length($t);
    }
    # add back in prompt - 1 to get to end of last token
    $col += 8;
    my $i;
    for ($i = 0; $i < $col; $i++) {
      print ' ';
    }
    print "^\n";
  }
  my $errmsg = shift;
  my $got = shift;
  die "Syntax error: $errmsg, got '$got'";
}

sub mergewithchar {
  my $charsep = shift;
  my $first = 1;
  my $res = '';
  my $item;
  foreach $item (@_) {
    if ((defined $item) && (!($item eq ''))) {
      if ($first) {
        $res = $item;
      } else {
        $res = $res . $charsep . $item;
      }
      $first = 0;
    }
  }
  return $res;
}

# puts spaces between things unless they're empty
sub mergestr {
  my $s = mergewithchar(' ', @_);
  # clean up spaces around *s
  if (!$opts{'pointerspaces'}) {
    $s =~ s/^[\Q*\E][ ]*/*/;
  }
  return $s;
}

# puts commas between things unless they're empty
sub mergecomma {
  return mergewithchar(', ', @_);
}

# same but with \n
sub mergeline {
  return mergewithchar("\n", @_);
}

########################################################################
# stuff that works on parse trees

# semantic checks
# some are done here, some are done during the translation to english
# phase (whichever is eaiser depending on what parts of the tree the
# checks need to access)
sub dosemchecks {
  my $node = shift;
  #use Data::Dumper;
  #print Data::Dumper->Dump([$node]);
  checkallpml($node, \&checkrestrict, 1);
  checkshared($node);
  checkallpml($node, \&checkautoshared, 1);
}

# calls a particular function with a bunch of stuff that might have a pointermodlist
sub checkallpml {
  my $node = shift;
  my $func = shift;
  my $callfunc = shift;
  if ($callfunc) {
    # call the function with this node
    &$func($node);
    # (otherwise we've already called it with that node on the recursion)
  }
  # now call the function with all this node's appropriate children
  # and call ourselves recursively
  my @checkme = qw/adecl cdecl returning/;
  my $key;
  foreach $key (@checkme) {
    my $item = $node->{$key};
    if (defined $item) {
      &$func($item);
      checkallpml($item, $func); 
    }
  }
  my @checklis = qw/args cdeclpost castlist/;
  foreach $key (@checklis) {
    if (defined $node->{$key}) {
      my $lis = $node->{$key};
      my $arg;
      foreach $arg (@$lis) {
        &$func($arg);
        checkallpml($arg, $func);
      }
    }
  }
}

# explain int *restrict **f(int* restrict)(int) -> good
# explain int *restrict **f(int* restrict)(restrict int) -> bad
# explain restrict int *restrict **f(int* restrict)(int) -> bad
sub checkrestrict {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  # Only adecl-pointerto and cdecl-pointer can have restrict qualifier
  my $pml = $node->{'pointermodlist'};
  if ((defined $pml) && !($ntype eq 'adecl-pointerto') && !($ntype eq 'cdecl-pointer')) {
    if (ispml($pml, 'restrict')) {
      output_warning("`restrict' can only qualify a pointer type");
    }
  } 
}

# declare x as array 10 of shared blocksize automatic int => good
# declare x as array 10 of shared blocksize automatic pointer to int => good
# declare x as pointer to shared blocksize automatic int => bad
# explain shared [*] int* x => bad
# explain int shared[*] *x => bad
# explain int *shared[*] x => good
sub checkautoshared {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'adecl-pointerto') {
    my $pml = $node->{'adecl'}{'pointermodlist'};
    if ((defined $pml) && (pmlissharedauto($pml))) {
      output_warning("pointers cannot point to objects with automatic blocksize (UPC 6.5.1)");
    }
  }
  my $pml = $node->{'pointermodlist'};
  if ((defined $pml) && (pmlissharedauto($pml))) {
    my $cdp = $node->{'cdecl'};
    if ((defined $cdp) && ($cdp->{'nodetype'} eq 'cdecl-pointer')) {
      output_warning("pointers cannot point to objects with automatic blocksize (UPC 6.5.1)");
    }
  }
}

# shared int x; => good
# shared auto int x; => bad
# declare x as auto array of shared int => bad
# declare x as auto shared array of int => bad
# declare x as auto shared int => bad
sub checkshared {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'explaindecl' || $ntype eq 'declare') {
    my $st = $node->{'storage'};
    if ($st eq 'auto') {
      checkallpml($node, \&docheckshared, 1);
    }
  }
}

sub docheckshared {
  my $node = shift;
  my $pml = $node->{'pointermodlist'};
  if (defined $pml) {
    if (ispml($pml, 'shared')) {
      output_warning("No object with automatic storage can have a type that is shared-qualified (UPC 6.5.2)");
    }
  }
}

sub ispml {
  my $pml = shift;
  my $tst = shift;
  my $item;
  foreach $item (@$pml) {
    my $nm = $item->{'name'};
    if ($nm eq $tst) {
      return 1;
    }
  }
  return 0;
}

sub pmlissharedauto {
  my $pml = shift;
  my $item;
  foreach $item (@$pml) {
    my $ntype = $item->{'nodetype'};
    if ($ntype eq 'ptrmod-shared-eng') {
      if (($item->{'name'} eq 'shared') && ($item->{'blocksize'} eq 'automatic')) {
        return 1;
      }
    } elsif ($ntype eq 'ptrmod-shared-c') {
      if (($item->{'name'} eq 'shared') && ($item->{'blocksize'} eq '*')) {
        return 1;
      }
    }
  }
  return 0;
}

# gives C code for the english description
sub tree2c {
  my $node = shift;
  dosemchecks($node);
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'declare') {
    my $st = $node->{'storage'};
    my $res = mergestr(
      $st,
      adecl2c($node->{'adecl'}, $node->{'name'})
    );
    my $cr = '';
    if ($opts{'create'}) {
      $cr = ';';
      # add {} if it's a function that's not extern
      if ($node->{'adecl'}{'nodetype'} eq 'adecl-function') {
        $cr = ' { }';
        if ((defined $st) && ($st eq 'extern')) {
          $cr = ';';
        }
      }
    }
    return "$res$cr";
  }
  if ($ntype eq 'docast') {
    my $ad = adecl2c($node->{'adecl'}, '');
    return '(' . $ad . ')' . $node->{'name'};
  }
  # ???
  die "Internal error: Don't know how to translate tree node of type $ntype into C\n";
}

sub adecl2c {
  my $node = shift;
  my $nm = shift;
  my $needparen = shift;
  # base case
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'adecl-type') {
    # check that void doesn't have blocksize
    my $typ = type2c($node->{'type'});
    my $pml;
    if (issharedtypename($typ)) {
      $pml = pointermodlist2c($node->{'pointermodlist'}, 1, 1);
    } elsif ($typ eq 'void') {
      $pml = pointermodlist2c($node->{'pointermodlist'}, 1);
    } else {
      $pml = pointermodlist2c($node->{'pointermodlist'});
    }
    return mergestr(
      $pml,
      $typ,
      $nm
    );
 }
  # recursive calls
  if ($ntype eq 'adecl-array') {
    if ($needparen) {
      $nm = '(' . $nm . ')';
    }
    my $sz = $node->{'size'};
    if ($sz < 0) {
      $nm = $nm . '[]';
    } else {
      $nm = $nm . "[$sz]";
    }
    return adecl2c($node->{'adecl'}, $nm);
  }
  if ($ntype eq 'adecl-pointerto') {
    my $newnm = mergestr('*', pointermodlist2c($node->{'pointermodlist'}), $nm);
    return adecl2c($node->{'adecl'}, $newnm, 1);
  }
  if ($ntype eq 'adecl-function') {
    if ($needparen) {
      $nm = '(' . $nm . ')';
    }
    $nm = $nm . '(' . adecllist2c($node->{'args'}) . ')';
    return adecl2c($node->{'returning'}, $nm);
  }
  # ??
  die "Internal error: Don't know how to translate tree node of type $ntype into C\n";
}

sub adecllist2c {
  my $arr = shift;
  my @lis = ();
  my $item;
  foreach $item (@$arr) {
    push @lis, adecllistitem2c($item);
  }
  return mergecomma(@lis);
}

sub adecllistitem2c {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'name') {
    return $node->{'name'};
  }
  if ($ntype eq 'nameadecl') {
    return adecl2c($node->{'adecl'}, $node->{'name'});
  }
  if ($ntype eq 'adecl') {
    return adecl2c($node->{'adecl'}, '');
  }
  die "Internal error: Don't know how to translate tree node of type $ntype into C\n";
}

sub type2c {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'type-typename') {
    return $node->{'typename'};
  }
  if ($ntype eq 'type-modlist') {
    return mergestr(modlist2c($node->{'modlist'}), $node->{'typename'});
  }
  if ($ntype eq 'type-enum') {
    return 'enum ' . $node->{'name'};
  }
  if ($ntype eq 'type-struct') {
    return 'struct ' . $node->{'name'};
  }
  if ($ntype eq 'type-union') {
    return 'union ' . $node->{'name'};
  }
  die "Internal error: Don't know how to translate tree node of type $ntype into C\n";
}

sub pointermodlist2c {
  my $list = shift;
  my $nosharedblocksize = shift;
  my $stripshared = shift;
  my @str = ();
  my $node;
  my $wasshared = 0; my $waslocal = 0;
  my $wasrelaxed = 0; my $wasstrict = 0;
  foreach $node(@$list) {
    my $ntype = $node->{'nodetype'};
    if ($ntype eq 'ptrmod') {
      my $nm = $node->{'name'};
      if ($nm eq 'relaxed') {
        $wasrelaxed = 1;
      } elsif ($nm eq 'strict') {
        $wasstrict = 1;
      }
      push @str, $nm;
    } elsif ($ntype eq 'ptrmod-shared-c') {
      $wasshared++;
      push @str, ptrmodsharedc2c($node->{'blocksize'}, $nosharedblocksize) unless $stripshared;
    } elsif ($ntype eq 'ptrmod-shared-eng') {
      $wasshared++;
      push @str, ptrmodsharedeng2c($node->{'blocksize'}, $nosharedblocksize) unless $stripshared;
    } elsif ($ntype eq 'ptrmod-local-eng') {
      $waslocal = 1;
    } else {
      die "Internal error: Don't know how to translate tree node of type $ntype into C\n";
    }
  }
  # strict/relaxed only apply to shared?
  if (($wasstrict || $wasrelaxed) && !$wasshared) {
    die "Strict/relaxed qualifers may only be applied to shared types\n";
  }
  # if both local _and_ shared, we've got a problem
  if ($wasshared && $waslocal) {
    die "A type component cannot be qualified both local and shared\n";
  }
  # if both strict _and_ relaxed, we've got a problem
  if ($wasstrict && $wasrelaxed) {
    die "A shared type component cannot be qualified both relaxed and strict\n";
  }
  # check for too many shareds
  if ($wasshared > 1) {
    die "Too many shared qualifiers\n";
  }
  # add local if no shared, we're doing C -> english, and the upcverbose flag is set
  if (!$wasshared && $parse_C && $opts{'upcverbose'}) {
    unshift @str, 'local';
  }
  return mergestr(@str);
}

sub ptrmodsharedc2c {
  my $bs = shift;
  my $noblock = shift;
  if ($noblock) {
    if (defined $bs) {
      output_warning("voids with the shared qualifier can not have a blocksize associated with them (UPC 6.5.1)");
    } else {
      return 'shared';
    }
  }
  my $bstr = 'cyclic';
  if (defined $bs) {
    if ($bs eq '0') {
      $bstr = 'indefinite';
    } elsif ($bs eq '1') {
      $bstr = 'cyclic';
    } elsif ($bs eq '*') {
      $bstr = 'automatic';
    } else {
      $bstr = $bs;
    }
  }
  return "shared (blocksize $bstr)";
}

sub ptrmodsharedeng2c {
  my $bs = shift;
  my $noblock = shift;
  if ($noblock) {
    if (defined $bs) {
      output_warning("voids with the shared qualifier can not have a blocksize associated with them (UPC 6.5.1)");
    } else {
      return 'shared';
    }
  }
  my $bstr = '[1]';
  if (defined $bs) {
    if ($bs eq 'cyclic') {
      $bstr = '[1]';
    } elsif ($bs eq 'automatic') {
      $bstr = '[*]';
    } elsif ($bs eq 'indefinite' || $bs eq '0') {
      $bstr = '[]';
    } else {
      $bstr = "[$bs]";
    }
  }
  return "shared $bstr";
}

sub modlist2c {
  my $list = shift;
  return "@$list";
}

# gives the english description from "explain" gibberish
sub tree2english {
  my $node = shift;
  dosemchecks($node);
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'explaindecl') {
    my $ts = 'int';
    my $warntype = 0;
    if (defined $node->{'type'}) {
      $ts = type2c($node->{'type'});
    } else {
      $warntype = 1;
    }
    my $pml2c;
    if (issharedtypename($ts)) {
      $pml2c = pointermodlist2c($node->{'pointermodlist'}, 1, 1);
    } elsif ($ts eq 'void') {
      $pml2c = pointermodlist2c($node->{'pointermodlist'}, 1);
    } else {
      $pml2c = pointermodlist2c($node->{'pointermodlist'});
    }
    if ($warntype) {
      output_warning("type defaults to `int' for pointer mod `$pml2c'\n");
    }
    return mergestr(
      cdecl2english($node->{'cdecl'}, $node->{'storage'}),
      $pml2c,
      $ts
    );
  }
  if ($ntype eq 'explaincast') {
    my $ts = type2c($node->{'type'});
    my $pml2c;
    if (issharedtypename($ts)) {
      $pml2c = pointermodlist2c($node->{'pointermodlist'}, 1, 1);
    } elsif ($ts eq 'void') {
      $pml2c = pointermodlist2c($node->{'pointermodlist'}, 1);
    } else {
      $pml2c = pointermodlist2c($node->{'pointermodlist'});
    }
    return mergestr(
      'cast',
      $node->{'name'},
      'into',
      cast2english($node->{'cast'}),
      $pml2c,
      $ts
    );
  }
  die "Internal error: Don't know how to translate tree node of type $ntype into english\n"; 
}

sub cdecl2english {
  my $node = shift;
  my $st = shift;
  my $ntype = $node->{'nodetype'};
  # base case of recursion
  if ($ntype eq 'cdecl-type') {
    my $nm = $node->{'name'};
    return mergestr(
      'declare',
      $nm,
      'as',
      $st,
      cdeclpost2english($node->{'cdeclpost'})
    );
  }
  # recursive calls
  if ($ntype eq 'cdecl-pointer') {
    return mergestr(
      cdecl2english(
        $node->{'cdecl'},
        $st
      ),
      pointermodlist2c($node->{'pointermodlist'}),
      'pointer to'
    );
  }
  if ($ntype eq 'cdecl-parens') {
    # these parens are just to guide parsing and don't affect output
    return mergestr(
      cdecl2english($node->{'cdecl'}, $st),
      cdeclpost2english($node->{'cdeclpost'})
    );
  }
  die "Internal error: Don't know how to translate tree node of type $ntype into english\n";
}

sub cdeclpost2english {
  my $cdp = shift;
  my @str = ();
  my $node;
  foreach $node (@$cdp) {
    my $ntype = $node->{'nodetype'};
    if ($ntype eq 'cdeclpost-array') {
      my $sz = $node->{'size'};
      if ($sz >= 0) {
        push @str, "array $sz of";
      } else {
        push @str, 'array of';
      }
    } elsif ($ntype eq 'cdeclpost-parens') {
      my $fnargs = castlist2english($node->{'castlist'});
      push @str, mergestr('function', $fnargs, 'returning');
    } else {
      die "Internal error: Don't know how to handle cdeclpost of type $ntype\n";
    }
  }
  return mergestr(@str);
}

sub castlist2english {
  my @str = ();
  my $cl = shift;
  my $hadone = 0;
  my $node;
  foreach $node (@$cl) {
    $hadone = 1;
    my $ntype = $node->{'nodetype'};
    if ($ntype eq 'castlistitem-name') {
      push @str, $node->{'name'};
    } elsif ($ntype eq 'castlistitem-type') {
      my $str = mergestr(
        cast2english($node->{'cast'}),
        pointermodlist2c($node->{'pointermodlist'}),
        type2c($node->{'type'})
      );
      push @str, $str;
    } else {
      die "Internal error: Don't know how to handle castlist of type $ntype\n";
    }
  }
  if ($hadone) {
    return '(' . mergecomma(@str) . ')';
  }
  return undef;
}

sub cast2english {
  my $node = shift;
  my @arr = ();
  if (defined $node->{'casthead'}) {
    push @arr, casthead2english($node->{'casthead'});
  }
  if (defined $node->{'castpost'}) {
    push @arr, castpost2english($node->{'castpost'});
  }
  return mergestr(@arr);
}

sub casthead2english {
  my $node = shift;
  my $ntype = $node->{'nodetype'};
  if ($ntype eq 'casthead-parens') {
    # if no cast, then it's a function
    my $cst = $node->{'cast'};
    if (!(defined $cst)) {
      return 'function returning';
    }
    my $cl = $node->{'castlist'};
    # if no castlist, the parens are just there for parsing correctly
    if (!(defined $cl)) {
      return cast2english($cst);
    } else {
      # castlist means it's a function w/args returning
      return mergestr(
        cast2english($cst),
        'function',
        castlist2english($node->{'castlist'}),
        'returning'
      );
    }
  }
  if ($ntype eq 'casthead-castlist') {
    return mergestr(
      'function',
      castlist2english($node->{'castlist'}),
      'returning'
    );
  }
  if ($ntype eq 'casthead-pointerto') {
    return mergestr(cast2english($node->{'cast'}), 'pointer to');
  }
  die "Internal error: Don't know how to translate tree node of type $ntype into english\n";
}

sub castpost2english {
  my $cl = shift;
  my @str = ();
  my $node;
  foreach $node (@$cl) {
    my $ntype = $node->{'nodetype'};
    if ($ntype eq 'castpost-array') {
      my $sz = $node->{'size'};
      if ($sz >= 0) {
        push @str, "array $sz of";
      } else {
        push @str, 'array of';
      }
    } else {
      die "Internal error: Don't know how to translate tree node of type $ntype into english\n";
    }
  }
  return mergestr(@str);
}

########################################################################
# parsing stuff

# recursive descent parsing, yay
# unfortunately Perl doesn't seem to include a parsing module by default
# so I did a simple rec desc to make installation easy

# program:
#   NOTHING
# | declare <declare>
# | cast <docast>
# | explain <explain>
# | set <set>
# | help <help> | '?' <help>
# | quit | exit
sub program {
  my $res = '';
  while (1) {
    my $t = nexttok();
    if ($t eq '') {
      return $res;
    } elsif ($t eq 'declare') {
      $parse_C = 0;
      $res = mergeline($res, tree2c(declare()));
    } elsif ($t eq 'cast') {
      $parse_C = 0;
      $res = mergeline($res, tree2c(docast()));
    } elsif ($t eq 'explain') {
      $parse_C = 1;
      $res = mergeline($res, tree2english(explain()));
    } elsif ($t eq 'set') {
      $res = mergeline($res, set());
    } elsif ($t eq 'help' || $t eq '?') {
      $res = mergeline($res, help());
    } elsif ($t eq 'quit' || $t eq 'exit') {
      exit(0);
    } else {
      synerror("expected command", $t);
    }
    # go again?
    $t = nexttok();
    if ($t eq '') {
      return $res;
    } else {
      if (!($t eq ';')) {
        synerror("expected ';'", $t);
      }
    }
  }
}
sub isprogram {
  my $t = shift;
  return ($t eq 'declare' || $t eq 'cast' || $t eq 'explain' || $t eq 'set' 
          || $t eq 'exit' || $t eq 'quit' || $t eq 'help' || $t eq '?');
}

sub help {
  # lifted from cdecl
  my $s = <<EOF
  [] means optional; {} means 1 or more; <> means defined elsewhere
    commands are separated by ';' and newlines
  command:
    declare <name> as <english>
    cast <name> into <english>
    explain <gibberish>
    set or set options
    help, ?
    quit or exit
  english:
    function [( <decl-list> )] returning <english>
    array [<number>] of <english>
    [{ const | volatile | restrict }] pointer to <english>
    <type>
  type:
    {[<storage-class>] [{<modifier>}] [<C-type>]}
    { struct | union | enum } <name>
  decllist: a comma separated list of <name>, <english> or <name> as <english>
  name: a C identifier
  gibberish: a UPC declaration, like 'shared int *x', or cast, like '(int *)x'
  storage-class: extern, static, auto, register
  C-type: int, char, float, double, or void
  modifier:
    short, long, signed, unsigned, const, volatile, <shared>, or restrict
  shared:
    shared
    shared [(] [blocksize] cyclic | indefinite | automatic | * | number [)]
  options: {[no]quiet | [no]pointerspaces | [no]create | [no]upcverbose}
EOF
;
  return $s;
}

sub set {
  my $t = nexttok();
  my $res = '';
  if (isdone($t)) {
    returntok($t);
    # show current options in effect
    $res = 'Current options:';
    my $o;
    foreach $o ('create', 'quiet', 'pointerspaces', 'upcverbose') {
      if ($opts{$o}) {
        $res = $res . " $o";
      } else {
        $res = $res . " no$o";
      }
    }
    $res .= "\nUsing term: ".($term?$term->ReadLine():"dumb");
    return $res . "\n";
  } else {
    # set options
    while (!isdone($t)) {
      my $o;
      my $wasvalid = 0;
      foreach $o ('create', 'quiet', 'pointerspaces', 'upcverbose') {
        if ($t eq $o) {
          $wasvalid = 1;
          $opts{$o} = 1;
        } elsif ($t eq "no$o") {
          $wasvalid = 1;
          $opts{$o} = 0;
        }
      }
      if (!$wasvalid) {
        synerror("invalid option", $t);
      }
      $t = nexttok();
    }
    returntok($t);
  }
  return '';
}

# explain:
#   ( <explaincast>
# | <explaincdecl>
sub explain {
  my $t = nexttok();
  if ($t eq '(') {
    return explaincast();
  } else {
    returntok($t);
    return explaindecl();
  }
}

# explaindecl:
#   <storage>? <ptrmodlist>? <type>? <cdecl> <ptrmodlist>?
sub explaindecl {
  my $t = nexttok();
  my $st;
  my $hadone = 0;
  if (isstorage($t)) {
    returntok($t);
    $hadone = 1;
    $st = storage();
    $t = nexttok();
  }
  my $pml = [];
  if (isptrmodlist($t)) {
    returntok($t);
    $hadone = 1;
    $pml = ptrmodlist();
    $t = nexttok();
  }
  my $ty;
  if (istype($t)) {
    returntok($t);
    $hadone = 1;
    $ty = type();
    $t = nexttok();
  }
  # grab pointermod after type
  if (isptrmodlist($t)) {
    returntok($t);
    $hadone = 1;
    my $newpml = ptrmodlist();
    my $node;
    foreach $node (@$newpml) {
      push @$pml, $node;
    }
    $t = nexttok();
  }
  returntok($t);
  if (!$hadone) {
    synerror("expected storage or pointer mod or type", $t);
  }
  my $cd = cdecl();
  return {nodetype => 'explaindecl', storage => $st, pointermodlist => $pml, type => $ty, cdecl => $cd};
}

# explaincast:
#   <ptrmodlist>? <type> <cast> ) NAME?
sub explaincast {
  my $t = nexttok();
  returntok($t);
  my $pml = [];
  if (isptrmodlist($t)) {
    $pml = ptrmodlist();
  }
  my $ty = type();
  my $cst = cast();
  my $nm;
  $t = nexttok();
  if ($t eq ')') {
    # optional last NAME
    $t = nexttok();
    if (isname($t)) {
      $nm = $t;
    } else {
      returntok($t);
    }
    return {nodetype => 'explaincast', pointermodlist => $pml, type => $ty, cast => $cst, name => $nm};
  } else {
    synerror("expected ')'", $t);
  }
}

# docast:
#   NAME into <adecl>
# | <adecl>
sub docast {
  my $t = nexttok();
  my $varname = 'expression';
  my $dec;
  if (isadecl($t)) {
    returntok($t);
    $dec = adecl();
  } elsif (isname($t)) {
    $varname = $t;
    my $nt = nexttok();
    if ($nt eq 'into') {
      $dec = adecl();
    } else {
      synerror("expected 'into'", $nt);
    }
  } else {
    synerror("expected name", $t);
  }
  return {nodetype => 'docast', name => $varname, adecl => $dec};
}

# declare:
#   NAME as <storage>? <adecl>
# | <storage>? <adecl>
sub declare {
  my $varname = "var";
  my $dec;
  my $st;
  my $t = nexttok();
  if (isname($t)) {
    $varname = $t;
    $t = nexttok();
    if (!($t eq 'as')) {
      synerror("expected 'as'", $t);
    }
    $t = nexttok();
  }
  returntok($t);
  if (isstorage($t)) {
    $st = storage();
  }
  $dec = adecl();
  return {nodetype => 'declare', name => $varname, adecl => $dec, storage => $st};
}

# adecl:
#   function ( <adecllist> returning <adecl>
# | function returning <adecl>
# | <ptrmodlist>? pointer to <adecl>
# | <ptrmodlist>? array NUMBER? of <adecl>
# | <ptrmodlist>? <type>
sub adecl {
  my $t = nexttok();
  if ($t eq 'function') {
    $t = nexttok();
    my $fnargs = ();
    my $ret;
    if ($t eq '(') {
      $fnargs = adecllist();
      $t = nexttok();
      if ($t eq 'returning') {
        $ret = adecl();
      } else {
        synerror("expected 'returning'", $t);
      }
    } elsif ($t eq 'returning') {
      $ret = adecl();
    } else {
      synerror("expected '(' or 'returning'", $t);
    }
    return {nodetype => 'adecl-function', args => $fnargs, returning => $ret};
  } else {
    # ptrmodlist?
    my $pmlist = [];
    if (isptrmodlist($t)) {
      returntok($t);
      $pmlist = ptrmodlist();
      $t = nexttok();
    }
    # pointer to/type
    if ($t eq 'pointer') {
      $t = nexttok();
      my $dec;
      if ($t eq 'to') {
        $dec = adecl();
      } else {
        synerror("expected 'to'", $t);
      }
      return {nodetype => 'adecl-pointerto', pointermodlist => $pmlist, adecl => $dec};
    } elsif ($t eq 'array') {
      # array
      $t = nexttok();
      my $arraysize = -1;
      my $dec;
      if (isnumericexpr($t)) {
        returntok($t);
        $arraysize = numericexpr();
        $t = nexttok();
      }
      if ($t eq 'of') {
        $dec = adecl();
      } else {
        synerror("expected 'of'", $t);
      }
      # tack on the pointermodlist below array if necessary
      if ($pmlist > 0) {
        my $adeclpml = $dec->{'pointermodlist'};
        my $node;
        foreach $node (@$pmlist) {
          unshift @$adeclpml, $node;
        }
      }
      return {nodetype => 'adecl-array', size => $arraysize, adecl => $dec};
    } else {
      # type
      returntok($t);
      my $t = type();
      return {nodetype => 'adecl-type', pointermodlist => $pmlist, type => $t};
    }
  }
}
sub isadecl {
  my $t = shift;
  return ($t eq 'array' || $t eq 'function' || isptrmodlist($t)
       || $t eq 'pointer' || istype($t));
}

# ptrmodlist:
#   <ptrmod> <ptrmodlist>?
sub ptrmodlist {
  my $t = nexttok();
  if (isptrmod($t)) {
    returntok($t);
    my $ptrmod = ptrmod();
    # peek at next symbol to go ahead
    my $nt = nexttok();
    returntok($nt);
    if (isptrmod($nt)) {
      my $rest = ptrmodlist();
      unshift @$rest, $ptrmod;
      return $rest;
    }
    # only one
    return [$ptrmod];
  } else {
    synerror("expected <ptrmodlist>", $t);
  }
}
sub isptrmodlist {
  my $t = shift;
  return isptrmod($t);
}

# ptrmod:
#   const
# | volatile
# | noalias
# | restrict
# | relaxed
# | strict
# | <shared>
sub ptrmod {
  my $t = nexttok();
  if (isptrmod($t)) {
    if (isshared($t)) {
      returntok($t);
      return shared();
    } else {
      return {nodetype => 'ptrmod', name => $t};
    }
  }
  synerror("expected pointer mod", $t);
}
sub isptrmod {
  my $t = shift;
  return member($t, ('const', 'volatile', 'noalias', 'restrict', 'strict', 'relaxed')) || isshared($t);
}

# shared:
#   shared
# The following are valid only in C mode:
# | shared []
# | shared [*]
# | shared [NUMBER]
# Otherwise (english mode):
# | local
# | shared '('? blocksize? NUMBER ')'?
# | shared '('? blocksize? indefinite ')'?
# | shared '('? blocksize? automatic ')'?
# | shared '('? blocksize? cyclic ')'?
sub shared {
  my $t = nexttok();
  if (!$parse_C && $t eq 'local') {
    return {nodetype => 'ptrmod-local-eng'};
  } elsif ($t eq 'shared') {
    my $nt = nexttok();
    if ($parse_C) {
      # parse optional brackets
      my $bs = undef;
      if ($nt eq '[') {
        # brackets w/nothing means blocksize indefinite
        $bs = '0';
        $nt = nexttok();
        if ($nt eq '*') {
          $bs = $nt;
          $nt = nexttok();
        } elsif (isnumericexpr($nt)) {
          returntok($nt);
          $bs = numericexpr();
          $nt = nexttok();
        }
        if (!($nt eq ']')) {
          synerror("expected ']'", $nt);
        }
      } else {
        returntok($nt);
      }
      return {nodetype => 'ptrmod-shared-c', name => $t, blocksize => $bs};
    } else {
      # parse optional parens
      my $was_parens;
      if ($nt eq '(') {
        $was_parens = 1;
        $nt = nexttok();
      }
      # parse optional blocksize statement
      my $wasbs = 0;
      if ($nt eq 'blocksize') {
        $wasbs = 1;
        $nt = nexttok();
      }
      my $bs = undef;
      if (isnumericexpr($nt)) {
        returntok($nt);
        $bs = numericexpr();
      } else {
        if (member($nt, ('cyclic', 'indefinite', 'automatic'))) {
          $bs = $nt;
        } elsif ($nt eq '*') {
          $bs = 'automatic';
        } else {
          if ($wasbs) {
            synerror("expected blocksize specification", $nt);
          } else {
            returntok($nt);
          }
        }
      }
      if ($was_parens) {
        $nt = nexttok();
        if (!($nt eq ')')) {
          synerror("expected ')'", $nt);
        }
      }
      return {nodetype => 'ptrmod-shared-eng', name => $t, blocksize => $bs};
    }
  } else {
    synerror("expected 'shared'", $t);
  }
}
sub isshared {
  my $t = shift;
  return ($t eq 'shared' || (!$parse_C && $t eq 'local'));
}

# cdecl:
#   <cdecl1>
# | * <ptrmodlist>? <cdecl>
sub cdecl {
  my $t = nexttok();
  if ($t eq '*') {
    my $nt = nexttok();
    returntok($nt);
    my $pml = [];
    if (isptrmodlist($nt)) {
      $pml = ptrmodlist();
    }
    my $cd = cdecl();
    return {nodetype => 'cdecl-pointer', pointermodlist => $pml, cdecl => $cd};
  } else {
    returntok($t);
    return cdecl1();
  }
}

# cdecl1:
#   ( <cdecl> ) <cdeclpost>*
# | NAME <cdeclpost>*
sub cdecl1 {
  my $t = nexttok();
  my $ntype;
  my $isname = 0;
  my $nm;
  my $cd;
  if (isname($t)) {
    # record NAME
    $nm = $t;
    $isname = 1;
  } elsif ($t eq '(') {
    $cd = cdecl();
    my $t = nexttok();
    if (!($t eq ')')) {
      synerror("expected ')'", $t);
    }
  } else {
    synerror("expected name or '('", $t);
  }
  my $cdp = [];
  my $nt = nexttok();
  returntok($nt);
  while (iscdeclpost($nt)) {
    push @$cdp, cdeclpost();
    $nt = nexttok();
    returntok($nt);
  }
  if ($isname) {
    return {nodetype => 'cdecl-type', name => $nm, cdeclpost => $cdp};
  } else {
    return {nodetype => 'cdecl-parens', cdecl => $cd, cdeclpost => $cdp};
  }
}

# cdeclpost:
#   ( )
# | ( <castlist>
# | [ ]
# | [ NUMBER ]
sub cdeclpost {
  my $t = nexttok();
  if ($t eq '(') {
    $t = nexttok();
    my $clist;
    if (!($t eq ')')) {
      returntok($t);
      $clist = castlist();
    }
    return {nodetype => 'cdeclpost-parens', castlist => $clist};
  } elsif ($t eq '[') {
    my $sz = -1;
    $t = nexttok();
    if (isnumericexpr($t)) {
      returntok($t);
      $sz = numericexpr();
      $t = nexttok();
    }
    if ($t eq ']') {
      return {nodetype => 'cdeclpost-array', size => $sz};
    } else {
      synerror("expected NUMBER or ']'", $t);
    }
  } else {
    synerror("expected '(' or '['", $t);
  }
}
sub iscdeclpost {
  my $t = shift;
  return member($t, ('(', '['));
}

# cast:
#   <casthead>? <castpost>*
sub cast {
  my $t = nexttok();
  returntok($t);
  my $chead;
  if (iscasthead($t)) {
    $chead = casthead();
  }
  $t = nexttok();
  returntok($t);
  my $cpost = [];
  while (iscastpost($t)) {
    push @$cpost, castpost();
    $t = nexttok();
    returntok($t);
  }
  return {nodetype => 'cast', casthead => $chead, castpost => $cpost};
}
sub iscast {
  # technically cast is nullable, so anything is a cast,
  # but this is used in casthead after the *
  my $t = shift;
  return iscasthead($t) || iscastpost($t);
}

# casthead:
#   ( <castlist>
# | ( <cast>? )
# | ( <cast> ) ( <castlist>?
# | * <cast>?
#
# NOTE: Here we allow just a castlist in parens, which breaks from the original
#       cdecl grammar.  However, this is needed to correctly parse some bits
#       that are actually spit out by cdecl.  Example:
#
#       cdecl> declare f as function (function(a,b,c) returning int) returning int
#       int f(int (a, b, c))
#       cdecl> explain int f(int (a, b, c))
#       syntax error
#
sub casthead {
  my $t = nexttok();
  if ($t eq '(') {
    my $hadcast = 0;
    my $nt = nexttok();
    returntok($nt);
    if (iscastlist($nt)) {
      my $cl = castlist();
      return {nodetype => 'casthead-castlist', castlist => $cl};
    }
    my $cst;
    if (!($nt eq ')')) {
      $cst = cast();
      $hadcast = 1;
    }
    $nt = nexttok();
    if (!($nt eq ')')) {
      synerror("expected ')'", $nt);
    }
    # do a castlist?
    my $clist;
    $nt = nexttok();
    if ($nt eq '(') {
      if (!$hadcast) {
        synerror("expected something inside first ()",  $nt);
      }
      $clist = [];
      $nt = nexttok();
      if (!($nt eq ')')) {
        returntok($nt);
        $clist = castlist();
      }
    } else {
      returntok($nt);
    }
    return {nodetype => 'casthead-parens', cast => $cst, castlist => $clist};
  } elsif ($t eq '*') {
    my $cst;
    my $nt = nexttok();
    returntok($nt);
    if (iscast($nt)) {
      $cst = cast();
    }
    return {nodetype => 'casthead-pointerto', cast => $cst};
  } else {
    synerror("expected '(' or '*'", $t);
  }
}
sub iscasthead {
  my $t = shift;
  return member($t, ('(', '*'));
}

# castpost:
#   [ ]
# | [ NUMBER ]
sub castpost {
  my $t = nexttok();
  if ($t eq '[') {
    $t = nexttok();
    my $sz = -1;
    if (isnumericexpr($t)) {
      returntok($t);
      $sz = numericexpr();
    } else {
      returntok($t);
    }
    $t = nexttok();
    if (!($t eq ']')) {
      synerror("expected ']'", $t);
    }
    return {nodetype => 'castpost-array', size => $sz};
  } else {
    synerror("expected '['", $t);
  }
}
sub iscastpost {
  my $t = shift;
  return member($t, ('['));
}

# type:
#   <typename>
# | <modlist> <typename>?
# | struct NAME
# | union NAME
# | enum NAME
sub type {
  my $t = nexttok();
  if ($t eq 'struct') {
    my $nm = nexttok();
    if (isname($nm)) {
      return {nodetype => 'type-struct', name => $nm};
    } else {
      synerror("expected name", $nm);
    }
  } elsif ($t eq 'union') {
    my $nm = nexttok();
    if (isname($nm)) {
      return {nodetype => 'type-union', name => $nm};
    } else {
      synerror("expected name", $nm);
    }
  } elsif ($t eq 'enum') {
    my $nm = nexttok();
    if (isname($nm)) {
      return {nodetype => 'type-enum', name => $nm};
    } else {
      synerror("expected name", $nm);
    }
  } elsif (istypename($t)) {
    returntok($t);
    my $tn = typename();
    return {nodetype => 'type-typename', typename => $tn};
  } elsif (ismodlist($t)) {
    returntok($t);
    my $ml = modlist();
    my $nt = nexttok();
    returntok($nt);
    my $tn;
    if (istypename($nt)) {
      $tn = typename();
    }
    return {nodetype => 'type-modlist', modlist => $ml, typename => $tn};
  } else {
    synerror("expected type", $t);
  }
}
sub istype {
  my $t = shift;
  return (istypename($t) || ismodifier($t)
       || member($t, ('struct', 'union', 'enum')));
}

# castlist:
#   <castlistitem> (, <castlistitem>)*
# | )
sub castlist {
  my $t = nexttok();
  my $first = 1; 
  my $cl = [];
  while (!isdone($t)) {
    if ($first) {
      # no comma before
      returntok($t);
      push @$cl, castlistitem();
    } else {
      # comma before
      if ($t eq ',') {
        push @$cl, castlistitem();
      } elsif ($t eq ')') {
        # end of list...
        return $cl;
      }
    }
    $first = 0;
    $t = nexttok();
  }
  # ran out of tokens...
  synerror("expected ')'", $t);
}
sub iscastlist {
  my $t = shift;
  return iscastlistitem($t);
}

# castlistitem:
#   NAME
# | <ptrmodlist>? <type> <cast>
sub castlistitem {
  my $t = nexttok();
  if (isptrmodlist($t) || istype($t)) {
    returntok($t);
    my $pml = [];
    if (isptrmodlist($t)) {
      $pml = ptrmodlist($t);
    }
    my $typ = type();
    my $cst = cast();
    return {nodetype => 'castlistitem-type', pointermodlist => $pml, type => $typ, cast => $cst};
  } elsif (isname($t)) {
    # record name
    return {nodetype => 'castlistitem-name', name => $t};
  } else {
    synerror("expected name or type", $t);
  }
}
sub iscastlistitem {
  my $t = shift;
  return (isname($t) || isptrmodlist($t) || istype($t));
}

# adecllist:
#   <adecllistitem> (, <adecllistitem>)*
# | )
sub adecllist {
  my $t = nexttok();
  my $first = 1;
  my $al = [];
  while (!isdone($t)) {
    if ($t eq ')') {
      # end of list
      return $al;
    }
    if ($first) {
      # no comma before
      returntok($t);
      my $li = adecllistitem();
      $al = [$li];
    } else {
      # comma before
      if ($t eq ',') {
        my $li = adecllistitem();
        push @$al, $li;
      } else {
        synerror("expected ','", $t);
      }
    }
    $first = 0;
    $t = nexttok();
  }
  # ran out of tokens...
  synerror("expected ')'", $t);
}

# adecllistitem:
#   NAME
# | NAME as <adecl>
# | <adecl>
sub adecllistitem {
  my $t = nexttok();
  if (isadecl($t)) {
    returntok($t);
    my $dec = adecl();
    return {nodetype => 'adecl', adecl => $dec};
  } elsif (isname($t)) {
    my $nm = $t;
    my $nt = nexttok();
    if ($nt eq 'as') {
      my $dec = adecl();
      return {nodetype => 'nameadecl', name => $nm, adecl => $dec};
    } else {
      returntok($nt);
      return {nodetype => 'name', name => $nm};
    }
  } else {
    synerror("expected name", $t);
  }
}

# typename:
#   int | char | double | float | void | UPC library type | C library type
sub typename {
  my $t = nexttok();
  if (issharedtypename($t)) {
    return $t;
  } elsif (istypename($t)) {
    return $t;
  }
  synerror("expected type name", $t);
}
sub issharedtypename { # UPC typedefs with incomplete shared type
  my $t = shift;
  return member($t, ('upc_lock_t', 'upc_file_t'));
}
sub istypename {
  my $t = shift;
  return member($t, ('int', 'char', 'double', 'float', 'void', 
                     'upc_flag_t', 'upc_off_t', 'size_t')) 
                     || issharedtypename($t);
}

# modlist:
#   <modifier> <modlist>?
sub modlist {
  my $t = nexttok();
  if (ismodifier($t)) {
    my $mod = $t;
    # peek at next symbol to go ahead
    my $nt = nexttok();
    returntok($nt);
    if (ismodlist($nt)) {
      my $rest = modlist();
      unshift @$rest, $mod;
      return $rest;
    }
    # only one
    return [$mod];
  } else {
    synerror("expected <modlist>", $t);
  }
}
sub ismodlist {
  my $t = shift;
  return ismodifier($t);
}

# modifier:
#   short
# | long
# | unsigned
# | signed
# | <ptrmod>
sub modifier {
  my $t = nexttok();
  if (ismodifier($t)) {
    return $t;
  }
  synerror("expected modifier", $t);
}
sub ismodifier {
  my $t = shift;
  return member($t, ('short', 'long', 'unsigned', 'signed'))
      || isptrmod($t);
}

# storage:
#   auto
# | extern
# | register
# | static
sub storage {
  my $t = nexttok();
  if (isstorage($t)) {
    return $t;
  }
  synerror("expected storage", $t);
}
sub isstorage {
  my $t = shift;
  return member($t, ('auto', 'extern', 'register', 'static'));
}

