################################################################################
# ctuple.pl
#
# Support functions for configuration tuple checking (and sizes info, too)
################################################################################

use strict;

# extract embedded keywords from binary UPC/Gasnet file
{
  my %ctuple_cache;
  sub extract_ctuples
  {
    my ($filename) = @_;
    my (%gasnet_ctuples, %upcr_ctuples, %upcr_sizes, %misc_info);

    if (exists $ctuple_cache{$filename}) {
      return @{$ctuple_cache{$filename}};
    }

    # Try to use .ct cachefile for lib.a unless mtime is older
    my $cachefile = $filename;
    if (!($cachefile =~ s/\.a$/.ct/) ||
        ((stat($filename))[9] > (stat($cachefile))[9]) ||
        !open(FILE, $cachefile)) {
      open (FILE, $filename) or die "can't open file '$filename'\n";
    }

    # use $ as the line break symbol, to make grepping for ident-style strings
    # simpler and more efficient.
    local $/ = '$';
    while (<FILE>) {
      my $c = substr($_,0,1);
      next unless ($c eq 'G' || $c eq 'U'); # Reject most lines quickly
      if (/^GASNet/) { # Divide ...
        if (/^GASNetConfig:
                  \s+
                  \( ([^)]+) \)                     # $1: filename (in parens)
                  \s+
                  ([^\$]+?)                         # $2: config string
                  \ \$                              # space followed by $
            /x) 
        {
            $gasnet_ctuples{$1} = $2;
        } elsif (/^(GASNet\S+): \s+                 # $1: other misc UPCR ident string
                  ([^\$]+)                          # $2: value
                  \ \$				    # space followed by $
                /x) {
            $misc_info{$1} = $2;
        }
      } elsif (/^UPC/) { # ... and conquer.
        if (/^UPCRConfig:
                  \s+
                  \( ([^)]+) \)                     # $1: filename (in parens)
                  \s+
                  ([^\$]+?)                         # $2: config string
                  \ \$                              # space followed by $
            /x) 
        {
            $upcr_ctuples{$1} = $2;
        } elsif (/^UPCRSizeof: \s+ 
                      ([A-Za-z0-9_]+)               # $1: type
                      =
                      ([\%-~])                      # char in %...~ range
                      \ \$
                 /x) {
                # subtract ASCII '$' from '%...~' to get 1...90 size
                $upcr_sizes{$1} = ord($2) - ord('$');
        } elsif (/^UPCRDefaultHeapSizes: \s+
                      UPC_SHARED_HEAP_OFFSET=([0-9]+[A-Za-z]*) 
                      \s+
                      UPC_SHARED_HEAP_SIZE=([0-9]+[A-Za-z]*) 
		      (?: \s+
                          UPC_SHARED_HEAP_SIZE_MAX=([0-9]+[A-Za-z]*) )?
                      \ \$
                 /x) {
                $upcr_sizes{UPC_SHARED_HEAP_OFFSET} = $1;
                $upcr_sizes{UPC_SHARED_HEAP_SIZE} = $2;
                $upcr_sizes{UPC_SHARED_HEAP_SIZE_MAX} = $3 if ($3);
        } elsif (/^UPCRDefaultPthreadCount: \s+
                  ([0-9]+)                          # $1: count
                  \ \$                              # space followed by $
		/x) {
		$misc_info{DefaultPthreadCount}{'<link>'} = $1;
        } elsif (/^(UPC\S+): \s+                    # $1: other misc UPCR per-file ident string
                  \( ([^)]+) \)                     # $2: filename (in parens)
                  \s+
                  ([^\$]+?)                         # $3: value
                  \ \$                              # space followed by $
		/x) {
		$misc_info{$1}{$2} = $3;
        } elsif (/^(UPCR\S+): \s+                   # $1: other misc UPCR ident string
                  ([^\$]+)                          # $2: value
                  \ \$				    # space followed by $
                /x) {
            $misc_info{$1} = $2;
        }
      }
    }
    close (FILE);

    # return by ref to avoid flattening
    my @result = (\%gasnet_ctuples, \%upcr_ctuples, \%upcr_sizes, \%misc_info);
    $ctuple_cache{$filename} = \@result;
    return @result;
  }
}

# check a .trans.c source file contains the proper ctuple strings
sub check_ctuple_trans

{
    my $filename = $_[0];
    open (TRANS_FILE, $filename) or die "could not read $filename: $!\n";
    my $oldsep = $/;
    undef $/;                # open maw
    my $transtxt = <TRANS_FILE>; # slurp!
    $/ = $oldsep;            # close maw
    close TRANS_FILE;

    unless (
     ($transtxt =~ m/UPCRI_IdentString_.*_GASNetConfig_gen/) &&
     ($transtxt =~ m/UPCRI_IdentString_.*_GASNetConfig_obj/) &&
     ($transtxt =~ m/UPCRI_IdentString_.*_UPCRConfig_gen/) &&
     ($transtxt =~ m/UPCRI_IdentString_.*_UPCRConfig_obj/)  
    ) { die "file $filename is missing mandatory configuration strings!\n"; }
}

# Check the consistency of a UPC object by comparing its configuration tuples,
# both internally and optionally with a canonical model
{
 my $mismatch_warned = 0;
 my $dynamic_warned = 0;
 sub check_ctuple_obj {
    my ($filename, $allow_missing, $canon_gasnet, $canon_upcr) = @_;
    my ($gasnet_ctuples, $upcr_ctuples, $upcr_sizes, $misc_info) = extract_ctuples($filename);
    my @ctup = (%$gasnet_ctuples,%$upcr_ctuples);
    my $upofile = 1 unless $filename =~ m/.*_startup_tmp.o$/;
    sub strdiff($$) {
      my ($a,$b) = @_;
      return "" if ($a eq $b);
      my $cnt = str_prefix_matchlen($a,$b);
      return " " . (" " x $cnt)."^\n";
    }
    sub dynamic_vs_static($$) {
      # If obj is dynamic-threads but link is static then rewrite obj to match
      my ($obj_ctup, $link_ctup) = @_;
      my $link_thr = substr($link_ctup, rindex($link_ctup, ','));
      if (($link_thr ne ',dynamicthreads') && $obj_ctup =~ s/,dynamicthreads$/$link_thr/) {
        printf STDERR "upcc: warning: Linking dynamic-threads object into static-threads executable.\n".
                      " This is supported by Berkeley UPC, but may not be portable.\n"
            unless ($dynamic_warned);
        $dynamic_warned = 1;
      }
      return $obj_ctup;
    }
    if (@ctup == 0 && $allow_missing) {
        return 0;  # not a UPC object: presumably C object
    }
    if (($upofile && @ctup != 8) || (!$upofile && @ctup != 4)) {
        return "missing build config strings in '${filename}'\n";
    }
    if ($upofile) {
        # Get uniform ordering (.trans.c before .o) independent of hash ordering.
        # This ordering is assumed in dynamic_vs_static() call w/ pthreads,
        # and additionally provides for consistency in error outputs.
        @ctup[0..3] = @ctup[2,3,0,1] unless ($ctup[0] =~ m/\.trans\.c$/);
        @ctup[4..7] = @ctup[6,7,4,5] unless ($ctup[4] =~ m/\.trans\.c$/);
    }
    if ($upofile) {
        # Allow dynamic-threads .trans.c in a static-threads link,
        # but ONLY for the delayed compilation of pthreaded objects.
        my $temp_ctup = ($ctup[7] =~ m/,SHMEM=pthreads/)
            ? dynamic_vs_static($ctup[5], $ctup[7]) : $ctup[5];

        return "inconsistent build configuration in '${filename}':\n" .
               $ctup[0] . ":\n " . $ctup[1] . "\n" .
               $ctup[2] . ":\n " . $ctup[3] . "\n" . strdiff($ctup[1],$ctup[3]) .
               $ctup[4] . ":\n " . $ctup[5] . "\n" .
               $ctup[6] . ":\n " . $ctup[7] . "\n" . strdiff($ctup[5],$ctup[7])
            unless (($ctup[1] eq $ctup[3]) && ($temp_ctup eq $ctup[7]));
    }
    if ($canon_upcr) {
        # Allow dynamic-threads obj in a static-threads link
        my $temp_ctup = dynamic_vs_static($ctup[@ctup - 1], $canon_upcr);

        return   "UPCR build configuration in '${filename}':\n" .
                 " " . $ctup[@ctup - 1] . "\n" .
                 "doesn't match link configuration:\n" .
                 " $canon_upcr\n" . strdiff($ctup[@ctup - 1], $canon_upcr)
            unless ($temp_ctup eq $canon_upcr);
    }
    if ($canon_gasnet && $ctup[1] ne $canon_gasnet) {
        return   "GASNet build configuration in '${filename}':\n" .
                 " " . $ctup[1] . "\n" .
                 "doesn't match link configuration:\n" .
                 " $canon_gasnet\n" . strdiff($ctup[1],$canon_gasnet);
    } 

    if ($$misc_info{UPCRConfigureMismatch} && !$mismatch_warned &&
	$ctup[@ctup - 1] !~ /,TRANS=(g(cc)?|clang)upc,/) { # bug 1853
       foreach my $filen (keys %{$$misc_info{UPCRConfigureMismatch}}) {
         my $comppath = $$misc_info{UPCRBackendCompiler}{$filen} || "*unknown path*";
         my $buildcomp = $$misc_info{UPCRBuildCompiler}{$filen} || "*unknown id*";
         my $confcomp = $$misc_info{UPCRConfigureCompiler}{$filen} || "*unknown id*";
	 $comppath = upcc_decode($comppath);
         print STDERR "upcc: warning: Configuration mismatch detected!\n".
                      " This install of Berkeley UPC was configured with backend C compiler '$comppath', which was identified as:\n".
	  	      "   $confcomp\n".
		      " However this C compiler now identifies as:\n".
		      "   $buildcomp\n".
		      " This usually indicates the C compiler was changed/upgraded and UPC was not reinstalled. ".
		    "Berkeley UPC is a source-to-source compilation system, and is therefore sensitive to details of the C compiler setup, even after installation. This configure/use mismatch is likely to cause correctness/performance problems - please re-configure and re-install Berkeley UPC with the new C compiler.\n";
         $mismatch_warned = 1; # warn at most once per compile
	 last;
       }
    }
    return undef;
 }
}

1;
