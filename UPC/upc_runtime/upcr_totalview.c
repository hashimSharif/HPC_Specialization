/*
 * UPC Runtime Totalview process pickup code
 *
 * $Source: bitbucket.org:berkeleylab/upc-runtime.git/upcr_totalview.c $
 */

#include <upcr_internal.h>
#include <upcr_barrier.h>

#if !defined(PLATFORM_OS_CATAMOUNT)
#define UPCRI_SUPPORT_SOCKETS 1
#endif

#if UPCRI_SUPPORT_TOTALVIEW /* File is empty otherwise */

#if UPCRI_SUPPORT_SOCKETS
#include <sys/types.h>     /* amudp says "Solaris 2.5.1 fix: u_short, required by sys/socket.h" */
#include <sys/socket.h>
#include <netinet/in.h>
#if HAVE_NETINET_TCP_H
  #include <netinet/tcp.h>
#endif
#include <netdb.h>
#endif

/* Type used to communicate w/ TotalView */
typedef struct {
  char	*host_name;
  char	*executable_name;
  int	pid;
} MPIR_PROCDESC;

/* Variables used to communicate w/ TotalView
 * Note use of tentative decl avoids link conflict w/ other runtimes (such as mpi)
 */
volatile MPIR_PROCDESC *MPIR_proctable;
volatile int MPIR_proctable_size;
volatile int MPIR_being_debugged;
volatile int MPIR_debug_state;
enum {
  MPIR_debug_state_SPAWNED = 1,
  MPIR_debug_state_ABORTING = 2
};

/* PRESENCE of these symbols tells TV important stuff about us.
 * Use of volatile ensures(?) compiler/linker doesn't discard them.
 */
volatile int MPIR_ignore_queues; /* don't look for MPI queue - we're not MPI */
volatile int MPIR_partial_attach_ok; /* a barrier follows MPIR_Breakpoint() call */
volatile int MPIR_force_to_main; /* don't show initialization code - show main */
volatile int MPIR_acquired_pre_main; /* don't show initialization code - show main */

static void *MPIR_Breakpoint(void);

/* If TV will attach to node 0, setup so it can pickup the other procs as well.
 * Two ways to tell us to expect TV via the environment:
 * 1) UPC_TOTALVIEW_FREEZE (yes/no)
 *      We freeze waiting for user to manually attach Totalview.
 * 2) UPC_TOTALVIEW_SOCKET ("host port" of a TCP listener)
 *      We must send "host pid" to somebody who will spawn TotalView to attach to us.
 * If you set either env var while spawning under Totalview, chaos may result.
 */
int
_upcri_startup_totalview(char **argv UPCRI_PT_ARG)
{
 #if UPCRI_SUPPORT_SOCKETS
  const char *tv_socket = upcr_getenv("UPC_TOTALVIEW_SOCKET");
 #else 
  const char *tv_socket = NULL;
 #endif
  int tv_attach = tv_socket || gasnett_getenv_yesno_withdefault("UPC_TOTALVIEW_FREEZE",0);
  struct pid_and_host {
    int pid;
    char host[256];	/* long enough? */
  };

  if (!tv_attach) return 0;

#if UPCRI_UPC_PTHREADS
  if (upcri_mypthread() == 0) /* Distinguish one pthread per node if TV+pthreads ever supported */
#endif
  {
    /* Gather pid/host info */
    upcr_shared_ptr_t allph_sptr = UPCR_NULL_PSHARED;
    struct pid_and_host *allph = NULL;
    #if UPCRI_COLL_USE_LOCAL_TEMPS
      struct pid_and_host myph;
    #else
      upcr_shared_ptr_t myph_sptr = UPCR_NULL_PSHARED;
      struct pid_and_host *myph = NULL;
    #endif

    /* mpich sometimes palys with this */
    MPIR_being_debugged = 0;

    /* Build in-segment gather source */
    #if UPCRI_COLL_USE_LOCAL_TEMPS
      myph.pid = getpid();
      gethostname(myph.host, sizeof(myph.host));
    #else
      myph_sptr = upcr_alloc(sizeof(struct pid_and_host));
      myph = upcr_shared_to_local(myph_sptr);
      myph->pid = getpid();
      gethostname(myph->host, sizeof(myph->host));
    #endif

    if (gasnet_mynode() == 0) {
      /* Allocate in-segment for gather target */
      allph_sptr = upcr_alloc(gasnet_nodes() * sizeof(struct pid_and_host));
      allph = upcr_shared_to_local(allph_sptr);
    }
    
    #if UPCRI_COLL_USE_LOCAL_TEMPS
      gasnet_coll_gather(GASNET_TEAM_ALL, 0, allph, &myph, sizeof(struct pid_and_host),
			  (GASNET_COLL_LOCAL |
			   GASNET_COLL_DST_IN_SEGMENT |
			   GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));
    #else
      gasnet_coll_gather(GASNET_TEAM_ALL, 0, allph, myph, sizeof(struct pid_and_host),
			  (GASNET_COLL_LOCAL |
			   GASNET_COLL_SRC_IN_SEGMENT | GASNET_COLL_DST_IN_SEGMENT |
			   GASNET_COLL_IN_MYSYNC | GASNET_COLL_OUT_MYSYNC));
      upcr_free(myph_sptr);
    #endif

    if (gasnet_mynode() == 0) {
      /* Construct process table on thread 0 for debugger (includes self) */
      int i;
      char *argv0 = upcri_strdup(argv[0]);
      MPIR_proctable_size = gasnet_nodes();
      MPIR_proctable = upcri_malloc(gasnet_nodes() * sizeof(MPIR_PROCDESC));
      for (i = 0; i < gasnet_nodes(); ++i) {
	MPIR_proctable[i].host_name = upcri_strdup(allph[i].host);
	MPIR_proctable[i].executable_name = argv0;
	MPIR_proctable[i].pid = allph[i].pid;
      }

    #if UPCRI_SUPPORT_SOCKETS
      if (tv_socket) {
	/* Tell upcrun where to point Totalview */
        struct sockaddr_in sock_addr;
        int addr_len;
        static const int one = 1;
        struct hostent *h;
        char *string, *host;
        int port, s;
        FILE *fp;

        host = string = upcri_strdup(tv_socket);
        string += strcspn(string, " \t\n");
        if (*string) *(string++) = '\0';
        port = atoi(string);
        if (!host[0] || !port)
	  upcri_err("upcri_startup_totalview: unable to parse UPC_TOTALVIEW_SOCKET");
        if ((h = gethostbyname(host)) == NULL)
	  upcri_err("upcri_startup_totalview: gethostbyname(%s) failed", host);
        if ((s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	  upcri_err("upcri_startup_totalview: socket() failed");
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port);
        sock_addr.sin_addr = *(struct in_addr *)(h->h_addr_list[0]);
        addr_len = sizeof(sock_addr);
        if (connect(s, (struct sockaddr *)&sock_addr, addr_len) < 0)
	  upcri_err("upcri_startup_totalview: connect(host=%s, port=%d) failed w/ errno=%d", host, port, errno);
          (void)setsockopt(s, IPPROTO_TCP, TCP_NODELAY, (char *) &one, sizeof(one));
        if ((fp = fdopen(s, "w")) == NULL)
	  upcri_err("upcri_startup_totalview: fdopen() failed");
        fprintf(fp, "%s\n%d\n%s\n", MPIR_proctable[0].host_name, MPIR_proctable[0].pid, argv[0]);
        fflush(fp);
        fclose(fp);
	upcri_free(host);
      } else 
    #endif /* UPCRI_SUPPORT_SOCKETS */
      {
	/* Tell USER where to point Totalview */
        fprintf(stderr, "### Waiting for 'totalview -remote %s -pid %d \"%s\"'\n",
        		MPIR_proctable[0].host_name, MPIR_proctable[0].pid, argv[0]);
        fflush(stderr);
      }

      /* Spin wait for debugger to attach */
      while (!MPIR_being_debugged)
	gasnett_sched_yield(); /* allow debugger to execute */
    }

    upcr_free(allph_sptr);
  }

  /* NOTE: Must have a barrier to ensure full process pickup. */
  UPCRI_SINGLE_BARRIER();

  return 1;
}

/* MPIR_Breakpoint() exists so TV can set a breakpoint here and wait for us to reach it */
volatile int upcri_always_zero = 0;
static void *MPIR_Breakpoint(void) {
  /* Fake recursion to hopefully ensure compiler does not inline */
  if (upcri_always_zero) {
    upcri_always_zero = 0;
    return MPIR_Breakpoint();
  }
  return NULL;
}

#endif  /* UPCRI_SUPPORT_TOTALVIEW */
