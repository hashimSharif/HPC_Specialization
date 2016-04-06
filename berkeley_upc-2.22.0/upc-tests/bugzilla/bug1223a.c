// This is a variant of bug1223.upc with names added to the
// nested struct and union types to make this valid ISO C99.
// Type names conflicting with system headers have been replaced with int.

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
  int *ABCsigev_notify_attributes; /* notification attributes */
} ABC_sigevent_t;

typedef struct
{
  int ABCsi_signo;                         /* signal number */
  int ABCsi_code;                          /* signal code */
  int ABCsi_pid;                         /* sender's pid */
  int ABCsi_uid;                         /* sender's uid */
  int ABCsi_errno;                         /* errno associated with signal */

  union
  {
    int __pad[32];               /* plan for future growth */
    union
    {
      /* timers */
      struct
      {
        union
        {
          struct
          {
            int ABCsi_tid;             /* timer id */
            unsigned int ABCsi_overrun;    /* overrun count */
          } a;
          ABC_sigval_t ABCsi_sigval;           /* signal value */
          ABC_sigval_t ABCsi_value;            /* signal value */
        } b;
      } c;
    } d;

    /* SIGCHLD */
    struct
    {
      int ABCsi_status;                    /* exit code */
      int ABCsi_utime;                 /* user time */
      int ABCsi_stime;                 /* system time */
    } e;

    /* core dumping signals */
    void *ABCsi_addr;                      /* faulting address */
  } f;
} ABC_siginfo_t;

int main() {
return 0;
}
