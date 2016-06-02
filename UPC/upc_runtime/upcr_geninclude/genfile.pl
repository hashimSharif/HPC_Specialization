# This perl script is used to autogenerate files with repeated
# elements such as are required in the atomic extensions.
#
# Usage:  perl -- genfile.pl subst_file template_file [> outfile]
#
# Summary:
#  Uses tables in "subst_file" to expand lines in the "template_file".
#
# Description:
#  For any line in "template_file" that contains tokens like @FOO@
#  the line is repeated for every expansion of the token(s).  Each
#  expansion step applies one line from "subst_file".  So, if a
#  template line contains multiple @...@ tokens from the same line
#  in the subst file, only a single output line results.  However,
#  with multiple tables in the subst file the expansions due to
#  the tables are "multiplicative".  So, if a template line has
#  tokens from one table with 2 lines and another with 3 lines,
#  then 6 lines of output will result.  However, the relative order
#  of these 6 lines is not currently defined.
#
# Subst file syntax:
#  + blank lines are ignored
#  + '@@' denotes a line comment like C++'s '//'
#  + Take care with whitespace at ends of lines or before '@@', because
#    it is not removed.
#  + A line starting with '@' (followed by anything other than another
#    '@') starts a table and is the "header row".  This line gives the
#    tokens to be replaced by lines in the tabls.
#  + Remaining lines are parsed as table rows, which must contain the
#    same number of fields as the most recent header row.
#  + All fields are separated by TABS, with multiple TABS treated as one.
#  + SPACES are not field separators, and can thus appear in expansions
#  + There is not currently any mechanism to quote TABS
#  + WARNING: There is very little checking of this syntax.
#
# Template file syntax:
#  + Lines that start with '@@' will not appear in the output
#  + '@@' is not significant when not at the start of a line
#  + '@\' at the end of line is a continuation to get substitution in
#    a mult-line input pattern.  The '@\' is removed from the output.
#  + Lines containing one or more @TOKEN@ strings that match subst tables
#    will be output one or more times to generate all possible
#    substitutions of these token.
#  + Lines without any @TOKEN@ are passed to the output unchanged.
#  + Any @TOKEN@ not matching a subst table is passed through unchanged
#
# Example subst file:
#  ---
#  @@ This is a comment before the first table
#  @TBL1_F1@	@tbl1_f2@
#  A		a
#  @@ This is a comment in the middle of a table
#  B		b
#  @TBL2_F1@
#  1
#  2
#  3 @@ The space after this 3 will get subst
#  ---
#
# Example template file:
#  ---
#  @@ This line is not output
#  This text is output unchanged, @EVEN@ @THIS@ @PART@, @@ and this
#  Random text @tbl1_f2@ @TBL2_F1@@tbl1_f2@ @TBL1_F1@
#  This @TBL1_F1@ is a multi-line @\
#   pattern @tbl1_f2@
#  More verbatim text.
#  ---
#
# Result of example subst and template:
#  ---
#  This text is output unchanged, @EVEN@ @THIS@ @PART@, @@ and this
#  Random text a 1a A
#  Random text a 2a A
#  Random text a 3 a A
#  Random text b 1b B
#  Random text b 2b B
#  Random text b 3 b B
#  This A is a multi-line 
#   pattern a
#  This B is a multi-line 
#   pattern b
#  More verbatim text.
#  ---

use strict vars;

open SUBST, "<$ARGV[0]" || die 'Failed to open SUBST file';
open PATT, "<$ARGV[1]" || die 'Failed to open PATT file';

my @subst = ();
my @curr = ();
while (<SUBST>) {
  chomp;
  s/\@\@.*//;
  next if (m/^\s*$/);
  if (m/^@/) {
    s/\@/\\\@/g;
    @curr = split("\t+");
    unshift @subst, [];
  } else {
    my @tmp = split("\t+");
    my $cmd = '';
    die 'Wrong number of fields' unless ($#tmp == $#curr);
    for (my $i=0; $i <= $#curr; $i++) {
      $cmd .= "s/$curr[$i]/$tmp[$i]/g;";
    }
    push @{$subst[0]}, $cmd;
  }
}
     
my $input;
while (defined($input = <PATT>)) {
  if ($input =~ s/\@\\$//) {
    # '@\' is continuation - perl cookbook recipe 8.1
    $input .= <PATT>;
    redo unless eof(PATT);
  }
  next if ($input =~ m/^\@\@/);
  my $output = '';
  foreach my $aref (@subst) {
    foreach my $cmd (@$aref) {
      $_ = $input;
      eval "$cmd";
      last if ($_ eq $input);
      $output .= $_;
    }
    ($input, $output) = ($output||$input, '');
  }
  print $input;
}
