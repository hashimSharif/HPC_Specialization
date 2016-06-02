#include <stdlib.h>
#include <stdio.h>
#include <upc.h>


#define PAGE_SIZE 4096/sizeof(double)
#define CACHE_LINE_SIZE 64/sizeof(double)
#define NUM_ITER 5
#define TOTAL_DATA 1048576  /* 1M */
#define U2 2
#define U4 4
#define U8 8
#define ULAST U8
#define ROWS THREADS
#define COLUMNS 1024

extern double timer_read(int n);



struct entry8 {
  double x;
};

struct entry64 {
  double x[8];
};

struct entry512 {
  double x[64];
};




struct entry64 e64[ULAST];
struct entrye512 e512[ULAST]; /* spelling mistake intentional */



int main(int argc, char** argv) {
  return 0; 
}
