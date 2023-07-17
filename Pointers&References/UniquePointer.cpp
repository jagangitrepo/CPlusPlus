#include "common.h"
#include "Sample.h"

/*
 * UniquePointer - Maintains the non copyable and unique custom class pointer
*/
template<typename T>
class UP
{
  T* objPtr{ nullptr };
public:
  UP() = default;
  // Param Constructor
  UP(T* objPtr_)
  {
    std::cout << "UP(T* objPtr_)" << std::endl;
    objPtr = std::move(objPtr_);
  }

  // Deleting the Copy and Assignment operator
  UP(const UP<T>&) = delete;
  UP& operator=(const UP<T>&) = delete;


  // Define the Move and Assignment operator
  UP(UP<T>&& upObj)
  {
    this->objPtr = std::move(upObj.objPtr);
    upObj.objPtr = nullptr;
  }

  UP& operator=(UP&& upObj)
  {
    // We can't compare this two types,
    // if (this != &upObj) 
    // We need to use addressof for template pointer class. 
    if (this != std::addressof(upObj))
    {
      this->objPtr = std::move(upObj.objPtr);
      upObj.objPtr = nullptr;
    }
    return *this;
  }

  ~UP()
  {
    std::cout << "~UP()" << std::endl;
    if (objPtr)
    {
      delete(objPtr);
    }
  }

  operator bool() const noexcept
  {
    return ((objPtr) ? true : false);
  }

  T* operator&()
  {
    return objPtr;
  }

  T* operator->()
  {
    return objPtr;
  }

  T& operator*()
  {
    return *objPtr;
  }
};

void UniquePointer()
{
  std::cout << "UniquePointer Start" << std::endl;
  UP<Sample> sampleptr1(new Sample(400));
  std::cout << (sampleptr1)->getData() << std::endl;
  UP<Sample> sampleptr2;

  // Non copyable
  //sampleptr2 = sampleptr1; 
  //UP<Sample> sampleptr3(sampleptr1);

  sampleptr2 = std::move(sampleptr1);
  if (sampleptr1)
  {
    std::cout << "Sampleptr1: " << (sampleptr1)->getData() << std::endl;
  }
  if (sampleptr2)
  {
    std::cout << "Sampleptr2: " << (sampleptr2)->getData() << std::endl;
  }
  std::cout << "UniquePointer End" << std::endl;
}