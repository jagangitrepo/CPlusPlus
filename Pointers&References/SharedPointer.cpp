#include "common.h"
#include "Sample.h"

/**
 * Reference_Counter - Maintain the atomic counter variable 
 */
class Reference_Counter
{
  std::atomic_int counter{ 0 };
public:
  Reference_Counter& operator++() noexcept
  {
    ++counter;
    return *this;
  }

  Reference_Counter& operator--() noexcept
  {
    --counter;
    return *this;
  }

  int getCounter() const noexcept
  {
    return counter;
  }
};

/**
 * SP - Shared Pointer RAII class to store the custom class object pointer
 */
template<typename T>
class SP
{
  T* objPtr {nullptr};
  Reference_Counter* refPtr{ nullptr };
  static int refCount;

public:
  // Default Constructor
  SP() noexcept
  {
    std::cout << "SP()" << std::endl;
  }

  // Parameterized Constructor
  SP(T* objPtr_):objPtr(objPtr_), refPtr(new Reference_Counter())
  {
    std::cout << "SP(T* objPtr_)" << std::endl;
    ++(*this->refPtr);
  }

  // Copy Constructor
  SP(const SP<T>& spObj)
  {
    std::cout << "SP(const SP& spObj)" << std::endl;
    objPtr = spObj.objPtr;
    refPtr = spObj.refPtr;
    ++(*this->refPtr);
  }

  // Default Destructor
  ~SP()
  {
    std::cout << "~SP()" << std::endl;
    if (refPtr || objPtr)
    {
      --(*this->refPtr);
      if (this->refPtr->getCounter() == 0)
      {
        std::cout << "~SP() Deleting the Object" << std::endl;
        delete(objPtr);
        delete(refPtr);
      }
    }
  }

  // Dereference Overload Function
  T& operator*() const noexcept
  {
    return *objPtr;
  }

  // Reference Overload Function
  T* operator&() const noexcept
  {
    return ((objPtr) ? objPtr : nullptr);
  }

  // bool operator 
  operator bool() const noexcept
  {
    return ((objPtr) ? true : false);
  }

  // Returns the reference count
  int getRefCount() const noexcept
  {
    return this->refPtr->getCounter();
  }
};

void SharedPointer()
{
  std::cout << "SharedPointer Start" << std::endl;
  SP<Sample> samplesp(new Sample(10));

  SP<int> sp(new int(100));
  {
    SP<int> sp1;
    if (sp1)
    {
      std::cout << "SP<int>: " << *sp1 << std::endl;
      std::cout << "SP<int>: " << &sp1 << std::endl;
      std::cout << "SP<int>: RefCount " << sp1.getRefCount() << std::endl;
    }
  }
  {
    SP<int> sp1(sp);
    std::cout << "SP<int>: " << *sp1 << std::endl;
    std::cout << "SP<int>: " << &sp1 << std::endl;
    std::cout << "SP<int>: RefCount " << sp1.getRefCount() << std::endl;
  }
  std::cout << "SP<int>: " << *sp << std::endl;
  std::cout << "SP<int>: " << &sp << std::endl;
  std::cout << "SP<int>: RefCount " << sp.getRefCount() << std::endl;
  std::cout << "SharedPointer End" << std::endl;
}