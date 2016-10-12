import sys
import os
import subprocess as sp
import errno

explain_LLVM_COMPILER = """

The environment variable 'LLVM_COMPILER' is a switch. It should either
be set to 'clang' or 'dragonegg'. Anything else will cause an error.

"""

explain_LLVM_DRAGONEGG_PLUGIN = """

You need to set the environment variable LLVM_DRAGONEGG_PLUGIN to the
full path to your dragonegg plugin. Thanks.

"""

explain_LLVM_CC_NAME = """

If your clang compiler is not called clang, but something else, then
you will need to set the environment variable LLVM_CC_NAME to the
appropriate string. For example if your clang is called clang-3.5 then
LLVM_CC_NAME should be set to clang-3.5.

"""

explain_LLVM_CXX_NAME = """

If your clang++ compiler is not called clang++, but something else,
then you will need to set the environment variable LLVM_CXX_NAME to
the appropriate string. For example if your clang++ is called ++clang
then LLVM_CC_NAME should be set to ++clang.

"""

explain_LLVM_COMPILER_PATH = """

Your compiler should either be in your PATH, or else located where the
environment variable LLVM_COMPILER_PATH indicates. It can also be used
to indicate the directory that contains the other LLVM tools such as
llvm-link, and llvm-ar.

"""

explain_LLVM_LINK_NAME = """

If your llvm linker is not called llvm-link, but something else, then
you will need to set the environment variable LLVM_LINK_NAME to the
appropriate string. For example if your llvm-link is called llvm-link-3.5 then
LLVM_LINK_NAME should be set to llvm-link-3.5.

"""

explain_LLVM_AR_NAME = """

If your llvm archiver is not called llvm-ar, but something else,
then you will need to set the environment variable LLVM_AR_NAME to
the appropriate string. For example if your llvm-ar is called llvm-ar-3.5
then LLVM_AR_NAME should be set to llvm-ar-3.5.

"""

class Checker(object):
    def __init__(self):
        path = os.getenv('LLVM_COMPILER_PATH')
 
        if path and path[-1] != os.path.sep:
            path = path + os.path.sep

        self.path = path if path else ''

    def check(self):
        if not self.checkOS():
            print 'I do not think we support your OS. Sorry.'
            return 1

        success = self.checkCompiler()

        if success:
            self.checkAuxiliaries()
    
        return 0 if success else 1

        

    def checkOS(self):
        return (sys.platform.startswith('freebsd') or
                sys.platform.startswith('linux') or 
                sys.platform.startswith('darwin'))
    
            
    def checkSwitch(self):
        compiler_type = os.getenv('LLVM_COMPILER')
        if compiler_type == 'clang':
            return (1, '\nGood, we are using clang.\n')
        elif compiler_type == 'dragonegg':
            return (2, '\nOK, we are using dragonegg.\n')
        else:
            return (0, explain_LLVM_COMPILER)


    def checkClang(self):

        cc_name = os.getenv('LLVM_CC_NAME')
        cxx_name = os.getenv('LLVM_CXX_NAME')

        cc =  '{0}{1}'.format(self.path, cc_name if cc_name else 'clang')
        cxx = '{0}{1}'.format(self.path, cxx_name if cxx_name else 'clang++')

        return self.checkCompilers(cc, cxx)

    
    def checkDragonegg(self):

        if not self.checkDragoneggPlugin():
            return False

        pfx = ''
        if os.getenv('LLVM_GCC_PREFIX') is not None:
            pfx = os.getenv('LLVM_GCC_PREFIX')

        cc  = '{0}{1}gcc'.format(self.path, pfx)
        cxx = '{0}{1}g++'.format(self.path, pfx)

        return self.checkCompilers(cc, cxx)

    
    def checkDragoneggPlugin(self):
        plugin = os.getenv('LLVM_DRAGONEGG_PLUGIN')

        if not plugin:
            print explain_LLVM_DRAGONEGG_PLUGIN
            return False

        if os.path.isfile(plugin):
            try: 
                open(plugin)
                pass
            except IOError as e:
                print "Unable to open {0}".format(plugin)
            else:
                return True
        else:
            print "Could not find {0}".format(plugin)
            return False
        

    def checkCompiler(self):
        (code, comment) = self.checkSwitch()

        if code == 0:
            print comment
            return False
        elif code == 1:
            print comment
            return self.checkClang()
        elif code == 2:
            print comment
            return self.checkDragonegg()
        else:
            print 'Insane\n'
            return False


    def checkCompilers(self, cc, cxx):

        (ccOk, ccVersion) = self.checkExecutable(cc)
        (cxxOk, cxxVersion) = self.checkExecutable(cxx)

        if not ccOk:
            print 'The C compiler {0} was not found or not executable.\nBetter not try using wllvm!\n'.format(cc)
        else:
            print 'The C compiler {0} is:\n{1}\n'.format(cc, ccVersion)

        if not cxxOk:
            print 'The CXX compiler {0} was not found or not executable.\nBetter not try using wllvm++!\n'.format(cxx)
        else:
            print 'The C++ compiler {0} is:\n\n{1}\n'.format(cxx, cxxVersion)

        if not ccOk or  not cxxOk:
            print  explain_LLVM_COMPILER_PATH
            if not ccOk:
                print  explain_LLVM_CC_NAME
            if not cxxOk:
                print  explain_LLVM_CXX_NAME
               

        
        return ccOk or cxxOk
        

    def checkExecutable(self, exe, version_switch='-v'):
        cmd = [exe, version_switch]
        try:
            compiler = sp.Popen(cmd, stdout=sp.PIPE, stderr=sp.PIPE)
            output = compiler.communicate()
            compilerOutput = '{0}{1}'.format(output[0], output[1])
        except OSError as e:
            if e.errno == errno.EPERM:
                return (False, '{0} not executable'.format(exe))
            elif e.errno == errno.ENOENT:
                return (False, '{0} not found'.format(exe))
            else:
                return (False, '{0} not sure why, errno is {1}'.format(exe, e.errno))
        else:
            return (True, compilerOutput)
        

    
    def checkAuxiliaries(self):
        link_name = os.getenv('LLVM_LINK_NAME')
        ar_name = os.getenv('LLVM_AR_NAME')

        if not link_name:
            link_name = 'llvm-link'

        if not ar_name:
            ar_name = 'llvm-ar'
        
        link = '{0}{1}'.format(self.path,link_name) if self.path else link_name
        ar = '{0}{1}'.format(self.path,ar_name) if self.path else ar_name

        (linkOk, linkVersion) = self.checkExecutable(link, '-version') 

        (arOk, arVersion) =  self.checkExecutable(ar, '-version') 

        if not linkOk:
            print 'The bitcode linker {0} was not found or not executable.\nBetter not try using extract-bc!\n'.format(link)
            print  explain_LLVM_LINK_NAME
        else:
            print 'The bitcode linker {0} is:\n\n{1}\n'.format(link, linkVersion)

        if not arOk:
            print 'The bitcode archiver {0} was not found or not executable.\nBetter not try using extract-bc!\n'.format(ar)
            print  explain_LLVM_AR_NAME
        else:
            print 'The bitcode archiver {0} is:\n\n{1}\n'.format(ar, arVersion)

        
