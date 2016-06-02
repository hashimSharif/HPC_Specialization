#include <stdint.h>
uint64_t CycleTime(){
  return((uint64_t)__mftb());
}
