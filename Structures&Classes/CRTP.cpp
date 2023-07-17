#include "common.h"
#include "Sample.h"

/*
* Example - It uses the CRTP ( Curiously recurring template pattern) to create the shared pointer object from the current object 
*/
class Example : public std::enable_shared_from_this<Example>
{
  int data{ 0 };
public:
  Example(int data_):data(data_)
  {
    std::cout << "Example(int)" << std::endl;
  }
  ~Example()
  {
    std::cout << "~Example()" << std::endl;
  }

  std::shared_ptr<Example> create()
  {
    return shared_from_this();
  }
};

void CRTP()
{
  std::cout << "CRTP Start" << std::endl;
  std::shared_ptr<Example> ep = std::make_shared<Example>(100);
  auto& epsp1 = ep->create();
  auto& epsp2 = ep->create();
  auto& epsp3 = ep->create();
  std::cout << "CRTP End" << std::endl;
}