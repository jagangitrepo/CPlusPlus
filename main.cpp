#include "include/common.h"

extern void SharedPointer();
extern void UniquePointer();

int main()
{
  SharedPointer();
  UniquePointer();
  return 0;
}