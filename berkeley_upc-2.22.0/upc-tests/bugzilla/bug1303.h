#include <unistd.h>
struct SOLARIS_FILE
{
        ssize_t _cnt;
        unsigned char *_ptr;

        unsigned char *_base;
        unsigned char _flag;
        unsigned char _file;
        unsigned __orientation:2;
        unsigned __ionolock:1;
        unsigned __seekable:1;
        unsigned __filler:4;
};
static int sizeof_SOLARIS_FILE() { return (int)sizeof(struct SOLARIS_FILE); }
