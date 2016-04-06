/* NOTE: the #line directive that follows is needed to correctly reproduce
   the bug, which related to warnings in SYSTEM HEADERS. */
#line 1 "/usr/include/bug1223.upc"

#define pthread_attr_t int
#define pid_t int
#define uid_t int
#define __uint32_t int
#define timer_t int
#define clock_t int

typedef union ABC_sigval
{
  int ABCsival_int;                        /* integer signal value */
  void  *ABCsival_ptr;                     /* pointer signal value */
} ABC_sigval_t;

typedef struct ABC_sigevent
{
  ABC_sigval_t ABCsigev_value;                 /* signal value */
  int sigev_signo;                      /* signal number */
  int sigev_notify;                     /* notification type */
  void (*ABCsigev_notify_function) (ABC_sigval_t); /* notification function */
  pthread_attr_t *ABCsigev_notify_attributes; /* notification attributes */
} ABC_sigevent_t;

typedef struct
{
  int ABCsi_signo;                         /* signal number */
  int ABCsi_code;                          /* signal code */
  pid_t ABCsi_pid;                         /* sender's pid */
  uid_t ABCsi_uid;                         /* sender's uid */
  int ABCsi_errno;                         /* errno associated with signal */

  union
  {
    __uint32_t __pad[32];               /* plan for future growth */
    union
    {
      /* timers */
      struct
      {
        union
        {
          struct
          {
            timer_t ABCsi_tid;             /* timer id */
            unsigned int ABCsi_overrun;    /* overrun count */
          };
          ABC_sigval_t ABCsi_sigval;           /* signal value */
          ABC_sigval_t ABCsi_value;            /* signal value */
        };
      };
    };

    /* SIGCHLD */
    struct
    {
      int ABCsi_status;                    /* exit code */
      clock_t ABCsi_utime;                 /* user time */
      clock_t ABCsi_stime;                 /* system time */
    };

    /* core dumping signals */
    void *ABCsi_addr;                      /* faulting address */
  };
} ABC_siginfo_t;

int main() {
return 0;
}
