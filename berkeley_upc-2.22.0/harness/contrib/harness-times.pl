#!/usr/bin/perl

sub fmt($$) {
    my ($t0, $t1) = @_;
    return ' --:--' unless defined $t1;
    my $min = ($t1 - $t0 + 30 ) / 60;
    return sprintf("% 3d:%02d", ($min / 60), ($min % 60));
}
    
foreach my $dir (@ARGV) {
    my @mtime = ();
    foreach my $file (qw( download.log
                          check.log
                          harness/qscript_000
                          harness/compile.rpt
                          harness/run.rpt
                          harness-opt/qscript_000
                          harness-opt/compile.rpt
                          harness-opt/run.rpt
                      ) ) {
        push @mtime, (stat("$dir/$file"))[9];
    }

    print "$dir\n";
    print "\tRuntime Bld\t", fmt($mtime[0], $mtime[1]), "\n";
    print "\tDBG Compile\t", fmt($mtime[2], $mtime[3]), "\n";
    print "\tDBG     Run\t", fmt($mtime[3], $mtime[4]), "\n";
    print "\tOPT Compile\t", fmt($mtime[5], $mtime[6]), "\n";
    print "\tOPT     Run\t", fmt($mtime[6], $mtime[7]), "\n";
    print "\t===========\n";
    print "\t      TOTAL\t", fmt($mtime[0], $mtime[7]), "\n\n";
}
