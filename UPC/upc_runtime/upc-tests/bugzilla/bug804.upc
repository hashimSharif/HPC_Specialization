#include <upc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct __struct_ptr_t
{
        shared void *ptr;
        int len;
} ptr_t;

void function(ptr_t *str_ptr, char *buf)
{
  int i, pos;
  char str[BUPC_DUMP_MIN_LENGTH];
  shared void *p;
        pos = 0;

        p = str_ptr[0].ptr;
        bupc_dump_shared(p, str, BUPC_DUMP_MIN_LENGTH);
        printf("=== TH%2d: 1st--%s\n",MYTHREAD, str);
        p = str_ptr[1].ptr;
        bupc_dump_shared(p, str, BUPC_DUMP_MIN_LENGTH);
        printf("=== TH%2d: 2nd--%s\n",MYTHREAD, str);

        for(i=0; i<2; i++)
        {
                upc_memput(str_ptr[i].ptr, &buf[pos], str_ptr[i].len);
                pos += str_ptr[i].len ;
        }
}

int main()
{
  int size, i, pos;
  shared [] char *sh_buf;
  ptr_t str_ptr[2];
  char *buf;
  shared void *ptr1, *ptr2;
  char str[BUPC_DUMP_MIN_LENGTH];

  size = 20;
  sh_buf = (shared [] char *)upc_alloc((size+1)*sizeof(char));
  if( !sh_buf )
  {
    printf("TH%2d: upc_alloc Error\n", MYTHREAD);
    upc_global_exit(-1);
  }

  buf = (char *)malloc((size+1)*sizeof(char));
        if( !buf )
        {
                printf("TH%2d: malloc Error\n", MYTHREAD);
                upc_global_exit(-1);
        }

        sprintf(buf,"1234567890abcdefghij");
        printf("--TH%2d: buf %s\n",MYTHREAD, buf); fflush(stdout);

        str_ptr[0].ptr = (shared void *)&sh_buf[0];
        str_ptr[1].ptr = (shared void *)&sh_buf[10];
        str_ptr[0].len = 8;
        str_ptr[1].len = 9;

        bupc_dump_shared(str_ptr[0].ptr, str, BUPC_DUMP_MIN_LENGTH);
        printf("*** TH%2d: 1st--%s\n",MYTHREAD, str);
        bupc_dump_shared(str_ptr[1].ptr, str, BUPC_DUMP_MIN_LENGTH);
        printf("*** TH%2d: 2nd--%s\n",MYTHREAD, str);
        function( str_ptr, buf );

        bupc_dump_shared(sh_buf, str, BUPC_DUMP_MIN_LENGTH);
        printf("--TH%2d: sh_buf %s\n",MYTHREAD, str); fflush(stdout);

        free(buf);
        upc_free(sh_buf);
upc_barrier;
printf("done.\n");
        return 0;
}

