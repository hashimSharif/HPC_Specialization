int main() {
  volatile int lv_arr[2];
  lv_arr[1] = 0;
  return lv_arr[1];
}
