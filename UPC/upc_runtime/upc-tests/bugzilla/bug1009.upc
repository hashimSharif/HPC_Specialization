 #include <upc.h>
typedef struct stat_rec {
    int      active;
    int      ncall;
    long long start;
    double   min_time;
    double   max_time;
    double   cum_time;
    double   meansq;
} stat_t;
                                                                                 
               
#define NUM_STATS 10
static shared [NUM_STATS]  stat_t stat_arr[THREADS][NUM_STATS];
void f() {
  stat_t s;
  int i=(THREADS-1), j=3;
  s = stat_arr[i][j];
}
