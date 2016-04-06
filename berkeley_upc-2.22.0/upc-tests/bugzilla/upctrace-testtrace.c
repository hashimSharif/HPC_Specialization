#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv) {
      pid_t child = fork();
      int rc, status;

      if (child < 0) {
          fprintf(stderr, "ERROR: fork() failed\n");
          return 1;
      } else if (child == 0) {
          int i;
          for (i=0; i < argc-1; i++) argv[i] = argv[i+1];
          argv[argc-1] = NULL; 
          execvp(argv[0], argv);
          fprintf(stderr, "ERROR: execvp() returned\n");
          return 1;
      }

      do {
          rc = waitpid(child, &status, 0);
      } while ((rc < 0) && (errno == EINTR));
      fflush(NULL);

      if (WIFSIGNALED(status)) {
            fprintf(stderr, "ERROR: upc_trace died with signal %d\n", 
                            (int)WTERMSIG(status));
            return 1;
      }
      if (WIFEXITED(status)) {
            rc = WEXITSTATUS(status);
            if (rc) {
                  fprintf(stderr, "ERROR: upc_trace exited with status %d\n", rc);
            } else {
              printf("\ndone.\n"); fflush(NULL);
            }
            return rc;
      }
  abort();
}
