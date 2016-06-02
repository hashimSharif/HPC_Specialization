#if 0
  #include <iostream.h>
#else
  #include <iostream>
  using namespace std;
#endif
#include <stdlib.h>
#include <unistd.h>

#include <bupc_extern.h>

#include "upclib.h"

class myThread {
private:
    int mythread; 
public:
    myThread(int val): mythread(val) {}
    int getmyThread() { return mythread; }
};

void do_it()
{
    myThread foo(my_UPC_get_thread());

    cout << "My C++ program sez mythread()=" << foo.getmyThread() << endl;
    cout << "Done" << endl;
}

int main(int argc, char **argv)
{
    bupc_init(&argc, &argv);
    do_it();
    bupc_exit(0);
    return 0;
}


