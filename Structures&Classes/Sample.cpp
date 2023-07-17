#include "Sample.h"
#include "common.h"


// Factory Method to create the Sample object
template<typename T, typename ARGS>
Sample<T> createSample(ARGS&& args)
{
  // Copy Ellison
  return Sample<T>(std::forward<ARGS>(args));
}

// Factory Method to create the Sample object
template<typename T, typename ARGS>
Sample<T> createDefaultSample(ARGS&& args)
{
  // Named Copy Ellison
  Sample<T> sobj(std::forward<ARGS>(args));
  return sobj;
}

void RunSample()
{
  Sample<int> sp1; // Default Constructor
  Sample<int> sp2(sp1); // Copy Constructor
  
  Sample<int> sp3; // Default Constructor
  sp3 = sp1; // Assignment Operator

  Sample<int> sp4(std::move(sp1)); // Move Constructor
  Sample<int> sp5;
  sp5 = std::move(sp2); // Move operator

  auto& obj1 = createDefaultSample<int>(200);
  std::cout << "createDefaultSample: " << obj1.getData() << std::endl;

  auto& obj2 = createSample<char>('K');
  std::cout << "createSample: " << obj2.getData() << std::endl;
}