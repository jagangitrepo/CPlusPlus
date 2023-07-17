#include "include/common.h"

extern void RunSample();
extern void SharedPointer();
extern void UniquePointer();

int main()
{
  RunSample();
  SharedPointer();
  UniquePointer();
  return 0;
}