#!/usr/bin/perl -w

#use Getopt::Long;
use strict;
use Cwd;
use File::Basename;

#############################
# Global variables
# ---------------
#############################

my @opt_includepaths;
my $opt_outputname;
my $startdir = cwd();
# The hash that stores every includes
my %includers; 
my @files;

#############################
# Getting the Options
#############################

# Getopt module broken on many platforms.  Use our own, which exists in
# different location depending on if we're in build/install tree.

# find where this script is located
my $upcppp_dir = $0;
while (readlink($upcppp_dir)) { 
    my $link = readlink($upcppp_dir);
    if (substr($link, 0, 1) eq "/") {
        $upcppp_dir = $link; 
    } else {
        $upcppp_dir = dirname($upcppp_dir) . "/" . $link; 
    }
}
$upcppp_dir = dirname($upcppp_dir);    # from File::Basename
my $progname = basename($upcppp_dir);
chdir($upcppp_dir) or die "Can't cd to '$upcppp_dir'\n";;
$upcppp_dir = cwd(); # use absolute path
chdir($startdir) or die "Can't cd to '$startdir'\n"; 

# This program lives in either 'detect-upc' (build) or 'libexec' (install)
# subdirectory.  
my ($upcr_include);
if ($upcppp_dir =~ m@^(.*)/libexec$@ && -f "$1/etc/upcc.conf") {
    $upcr_include = "$1/include";
} elsif ($upcppp_dir =~ m@^(.*)/detect-upc$@) {
    $upcr_include = $1;
} else {
    die "$0 is not in an recognizably correct directory.  Aborting";
}
push @INC, $upcr_include;
require "upcr_getopt.pl";
import Getopt::Long;

GetOptions(
	'I=s'		=> \@opt_includepaths,
	'o=s'		=> \$opt_outputname
);

usage(-1) unless @opt_includepaths;



############################
# Recursively Finding the includes
############################

#change the arguments passed in into abs path
my @args;
foreach my $arg (@ARGV) {
	unless ($arg =~ /^\//) {    #if not absolute path
		$arg = "$startdir/$arg";
	}
	unshift @args, $arg;
}
#main recursion algorithm
push @files, @args;
while (@files) {
	my $file = pop @files;
	my (@includes) = get_includes($file);
	for my $header (@includes) {
		unless (defined($includers{$header})) {
			unshift @files, $header;
		}
		push @{$includers{$header}}, $file;
	}
}

################################################################################
# usage info
################################################################################
sub usage
{
    my ($exitcode) = @_;

    print "Usage: $progname -o output -I /inc/dir [ -I more/dirs ] UPC_file\n";
    exit $exitcode;
}

############################
# get_includes Gets the #include header files (in its absolute path)
# (It does not differentiate <> and "" notation
############################
sub get_includes {
	#the headers	
	my @headers;
	open (FILE, $_[0]) || die "Could not open file $_[0] : $!\n";
	#finding #includes
	while (<FILE>) {
		if (/^\s*\#\s*include\s*<(.*)>/ ||
		    /^\s*\#\s*include\s*"(.*)"/) {
			push @headers, $1;
		}			
	}
	close (FILE);		
	return grep $_, map get_abs_path($_), @headers;
}

#############################
# get_abs_path returns the absolute path of the argument 
# (it tries to find the header file in the directories indicated)
#############################

sub get_abs_path {
	my $header = $_[0];
	foreach my $path (@opt_includepaths) {
		my $abs_path;
		if ($path =~ /^\//) {
			$abs_path = "$path/$header";
		} else {	 
			$abs_path = "$startdir/$path/$header";
		}
                $abs_path = clean_path($abs_path);
		return $abs_path if -f $abs_path;
	}
	return 0;
}	
	
###########################
# clean_path returns the canonical path of the given path
###########################

sub clean_path {
	my $path = $_[0];
	while ($path =~ s@/\./@/@) { }
	while ($path =~ s@[^/]+/\.\./@@) { }
	while ($path =~ s@//@/@) { }
	return $path; 		 
}
###########################
# Dump the output into a file
###########################

if ($opt_outputname) {
	open(STDOUT, ">$opt_outputname") 
		or die "Could not write to $opt_outputname: $!\n";
}
while (my ($header, $array) = each %includers) {
	# avoid duplicates
	my %seen = ();
	my @uniq;
        #$header = clean_path($header);
	foreach my $item (@$array) {
                #$item = clean_path($item);
		push (@uniq, $item) unless $seen{$item}++;	
	}
	my $num_files = @uniq;	
	print STDOUT "$header $num_files\n";
	foreach my $item (@uniq) {
		print STDOUT "$item\n";
	}
}
