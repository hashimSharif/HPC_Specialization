#!/usr/bin/perl

use strict;
use CGI qw(:standard escapehtml);

################################################################################
# upcc.cgi: a CGI script for supporting remote HTTP-based UPC-to-C translation
#
# This script allows you to translate your UPC code to C across an HTTP
# connection.  This is primarily useful if the Berkeley UPC-to-C translator does
# not build on your target system, and so you cannot do the translation locally.
#
# Note that a public version of this script is available at
# http://upc-translator.lbl.gov, and that upcc defaults to using it, 
# so you can simply use our service rather than setting it up yourself.
#
# To set up the script on your own webserver, follow these instructions:
#
# 1) Download and build the Berkeley UPC-to-C translator on your webserver.
#
# 2) Download and build the Berkeley UPC runtime on your webserver.  Configure
#    the upcc.conf file's 'translator' parameter to point to the directory of
#    the UPC-to-C translator that you built in step #1.
#
# 3) Place this script in the appropriate directory for your HTTP server, and
#    make sure that your HTTP server's settings are configured to run it as a
#    CGI script. In order to enable cgi-bin support on Apache, you may need to 
#    add the following options to your http.conf or .htaccess file:
#       Options FollowSymLinks ExecCGI
#       AddHandler cgi-script .cgi
#    The sample.cgi script in this directory can be used to test that basic 
#    cgi-bin functionality is operational.
#
# 4) Modify the '$upcchome' line below to point to the directory location of
#    the bin directory containing the upcc script from the runtime you built in step #2.
#
# 5) A good way to test your setup is by using the 'cgitest.html' page provided
#    in this directory.  Edit the page so that it's "form action" points to your
#    copy of upcc.cgi.  Load the page in your browser, hit the "browse" button
#    and specify the 'foo.tar' file (also in this directory), and submit the
#    form.  If you get a "download file" dialog in your browser, you have
#    configured things correctly.  Otherwise you will get an error from your
#    webserver or upcc.cgi.  Some useful debugging hints:
#     1) run 'perl -c upcc.cgi' on your script, in case you've introduced
#        syntax errors; 
#     2) If you're using the apache webserver, make sure you've
#        set up CGI script permissions correctly, and look at
#        the webserver's error log (/var/log/httpd/error.log by default), which
#        is often more useful than the HTML page error description. 
#     3) Make sure 'upcc.cgi' has executable permission (ie a+rx)
#     4) Try running a netcompile from a remote machine using:
#          upcc -v -translator=http://yourserver.com/upcc.cgi
#        the verbose compile output may give you more information about what's
#        gone wrong.
#     5) If you get errors about missing shared libraries (eg libstdc++.so)
#        Apache lets you tweak the shared library path for the cgi-bin script
#        using an .htaccess file in the same directory with an entry like:
#          SetEnv LD_LIBRARY_PATH /path/to/missing/shared/libs
#        In some cases a similar approach may be required if the translator's
#        own shared libraries (eg be.so, wopt.so, whirl2c.so) cannot be found.
#
# 6) Once you've got things working, set the 'translator' setting in your target
#    system's upcc.conf to the URL for the CGI script.  You should now be able
#    to compile UPC programs on your target system, using the translator on your
#    webserver for UPC-to-C translation. 
#
# 7) The UPCC_CGI_BANNER environment variable can be set in the environment of
#    this script (eg by wrapping it with a shell script or using .htaccess SetEnv)
#    to issue a specified banner message to the user at every UPC-to-C compilation.
#
# Jason Duell <jcduell@lbl.gov>
# $Source: bitbucket.org:berkeleylab/upc-runtime.git/contrib/upcc_CGI/upcc.cgi $
################################################################################

# change this to point to your local UPC runtime's 'upcc' script's directory
# (usually INSTALL_PREFIX/bin)
my $upcchome = "/usr/local/upc/nightly/runtime/inst/bin";

################################################################################
# You shouldn't need to modify anything below this line
################################################################################

sub safeparam {
    my ($name) = @_;
    my @vals = param($name);
    # barf if any suspicious characters sighted
    for (@vals) {
        if (/([;`\$><&(){}])/) {
            die "Illegal characters in upcc.cgi parameter '$name': '$_'\n"
        }
    }
    return wantarray ? @vals : $vals[0];
}


# HTML form parameters - 
my $archsize;
my $network;
my $verbose;
my @upcargs;
my @w2cargs;
my $threads;
my $pthreads;
my ($debug, $opt_g, $opt_tv); # 'debug' is deprecated: we now distinguish between
                              # -g/-tv, using opt_g and opt_tv. But support old
                              # runtimes out there that still use 'debug'
my $lines;
my $temps;
my $compress;
my $infile;

# other global variables
my $cpulimit = 300; # cpu limit in seconds for translation (to prevent runaways)
my $ucmd = "ulimit -t $cpulimit ; $upcchome/upcc --at-remote-http";
my $upccsizes = "upcc-sizes";
my $TMPDIR = (-d $ENV{TMPDIR} ? "$ENV{TMPDIR}" : '/tmp');
my $now = time();
my $tardir = "$TMPDIR/upcc-net.$$.$now";
my $transdir = "$TMPDIR/upcc-trans-net.$$.$now";
my $http_err = "httpcompile.err";
my $http_out = "httpcompile.out";
my $transtar = "trans-archive.tar";
my @toRemove;
my $upcc_exit;


eval {
    $archsize = safeparam("archsize");
    $network = safeparam("network");
    $verbose = safeparam("verbose");
    @upcargs = safeparam("upcargs");
    @w2cargs = safeparam("w2cargs");
    $threads = safeparam("threads");
    $debug = safeparam("debug");
    $opt_g = safeparam("opt_g");
    $opt_tv = safeparam("opt_tv");
    $pthreads = safeparam("pthreads");
    $lines = safeparam("lines");
    $temps = safeparam("temps");
    $compress = safeparam("compress");
    $infile = safeparam("infile");
    

#Check Variables - 
    #Archsize check
    if(!($archsize == 32) && !($archsize == 64))  {
	die "upcc.cgi: Illegal arch_size parameter: '$archsize'";}
    $ucmd .= " --arch-size=$archsize";

    die "No network conduit specified\n" unless $network;
    $ucmd .= " --network=$network";
    
    #Verbose/debug check.
    for (my $i = 0; $i < $verbose; $i++) {
      $ucmd .= " -v";
    }

    # Debugging/Totalview
    if ($opt_g || $opt_tv) {
        $ucmd .= " -g" if $opt_g;
        $ucmd .= " -tv" if $opt_tv;
    } else {
        # backward compatibility: 'debug' used for both -tv/-g, so pass -tv,
        # which is a superset of -g.  But -tv can't be used with pthreads
        if ($debug) {
            $ucmd .= (defined $pthreads ? " -g" : " -tv"); 
        }
    }
    
    #UPC Arg check.
    foreach my $upcarg (@upcargs) {
	if ($upcarg =~ m/[^A-Za-z0-9.=,\-]/) {
	    die "upcc.cgi: upcc Argument '-Wu,$upcarg' contains illegal characters.  (Only [A-Za-z0-9.=,-] are allowed)";
	} else {
	    $ucmd .= " -Wu,$upcarg";
	}
    }  
    #W2C Arg check.
    foreach my $w2carg (@w2cargs) {
	if ($w2carg =~ m/[^A-Za-z0-9.=,\-]/) {
	    die "upcc.cgi: W2C Argument '-Ww,$w2carg' contains illegal characters.  (Only [A-Za-z0-9.=,-] are allowed)";
	} else {
	    $ucmd .= " -Ww,$w2carg";
	}
    }
    
    #Threads check.
    if ($threads =~ /\D/) {
        die "upcc.cgi: Threads, '$threads', is not an integer. (An integer, it must be)";}       
    $ucmd .= " -T $threads" if $threads;
    
    #Pthreads check.
    if (defined $pthreads) {
	if ($pthreads) {
	    $ucmd .= " --pthreads $pthreads";
	} else {
	    $ucmd .= " --pthreads";
	}
    }

    # lines check.
    if (defined $lines) {
	if ($lines) {
	    $ucmd .= " --lines";
	} else {
	    $ucmd .= " --nolines";
	}
    }

    $ucmd .= " -save-all-temps" if $temps;

#Get TAR'd file
    
    die "HTTP request missing 'infile' tarball" unless ($infile);
    # fork and exec 'tar', and write tarball to its stdin:
    # - ignore write errors if tar fails, and capture instead at close()
    $SIG{PIPE} = 'IGNORE';
    mkdir ($tardir,0700) or 
	die"upcc.cgi: Couldn't make directory: $tardir";
    push @toRemove, $tardir;
    chdir "$tardir" or 
	die "upcc.cgi: Couldn't cd into $tardir";
    my $untar = "|tar -xf -";
    $untar = "|gzip -d $untar" if ($compress);
    open (TAR, $untar) or
	die "upcc.cgi: error running 'tar': $^E";
    print TAR while <$infile>;
    close (TAR) or
        die "upcc.cgi: error running 'tar': $^E";
    $SIG{PIPE} = 'DEFAULT';
};
# If error at any point up to here, send back HTTP reply with error message as
# body
if ($@) {
    my $length = length($@);
    my $exitcode = $upcc_exit || -1;
    print "Content-type: text/plain\n";
    print "X-upcc-exit: $exitcode\n";
    print "Content-length: $length\n\n";
    print $@; 
    exit(-1);
}

# after this point, send the stderr/stdout of the translator, if possible
eval {

    open (HTTP_ERR, ">$http_err"); 
    if (my $banner = $ENV{UPCC_CGI_BANNER}) {
      $banner .= "\n" unless ($banner =~ m/\n$/);
      print HTTP_ERR $banner; 
    }
    close HTTP_ERR;

#Finalize command for UPCC call.
    $ucmd .= " --trans --sizes-file=$upccsizes *.i >$http_out 2>>$http_err";

# Run the translator
    $upcc_exit = system($ucmd);

#create reply tarball
    my $save_exts = $temps ? "*.trans.c *.B *.t *.N" : "*.trans.c";
    my $reply_files = "$save_exts $http_err $http_out";
    $reply_files .= " upcr_trans_extra*" if (<upcr_trans_extra*>);
    my $cmd;
    if ($compress) {
      $cmd = "( tar cf - $reply_files | gzip -c -$compress > $transtar )";
    } else {
      $cmd = "tar -cf $transtar $reply_files";
    }
    system("$cmd >/dev/null 2>/dev/null");

#Print header for HTTP response to host.
    my $tarlength = -s $transtar or 
	die "upcc.cgi: $transtar has bad length. Cannot send Content-length in response.";
    print "Content-type: application/x-tar\n";
    print "Content-length: $tarlength\n";
    print "X-upcc-exit: $upcc_exit\n\n";

#Send HTTP response (which contains the needed TARBALL)to the host.
    open TARFILE, "$transtar" or 
	die "upcc.cgi: Can't open $transtar (aka  Can't send TAR to host!)";
    print while <TARFILE>;
    close TARFILE;
};
	
if ($@) {
    my $length = length($@);
    my $exitcode = $upcc_exit || -1;
    print "Content-type: text/plain\n";
    print "X-upcc-exit: $exitcode\n";
    print "Content-length: $length\n\n";
    print $@; 
}

for (@toRemove) {
    system("rm -rf $_ >/dev/null 2>/dev/null");
}
