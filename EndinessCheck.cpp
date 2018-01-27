#include <iostream>

using namespace std;

#define LSB 0
#define MSB 1

bool IsSysLittleEndiness()
{
  union{
    short int data;
    char mem[2];
  }sys;
  
  sys.data = 0x01;
  
  if(sys.mem[LSB] == 1)
    return true;
  else
    return false;
}

int main()
{
  if(IsSysLittleEndiness())
    cout<<"Little Endine"<<endl;
  else
    cout<<"Big Endine"<<endl;
  return 0;
}
