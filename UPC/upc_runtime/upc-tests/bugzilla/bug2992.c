#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct vec {
    int32_t i32;
    int64_t i64;
};

int32_t sum1(int cnt, struct vec *a) {
  int32_t sum = 0;
  for (int i = 0; i < cnt; ++i) {
    sum += a[i].i64;
  }
  return sum;
}

int32_t sum2(int cnt, struct vec *a) {
  int32_t sum = 0;
  for (int i = 0; i < cnt; ++i) {
    int32_t tmp = a[i].i64;
    sum += tmp;
  }
  return sum;
}

int64_t sum3(int cnt, struct vec *a) {
  int64_t sum = 0;
  for (int i = 0; i < cnt; ++i) {
    sum += a[i].i64;
  }
  return sum;
}

struct vec array[] = {{1,1},{2,2},{3,3},{4,4},{5,5}};

int main(void) {
  int len = sizeof(array) / sizeof(array[0]);
  int s1 = sum1(len, array);
  int s2 = sum2(len, array);
  int s3 = sum3(len, array);
  int pass = (s1 == 15) && (s2 == 15) && (s3 == 15);
  printf("Sums: %i %i %i\n", s1, s2, s3);
  puts(pass ? "PASS" : "FAIL");
  return !pass;
}
