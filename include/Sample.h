#pragma once
#include <iostream>

template<class T>
class Sample
{
  T* data {nullptr};

  public:
  Sample():data(nullptr)
  {
    std::cout<<"Sample()"<<std::endl;
  }

  Sample(T data_):data(new T(data_))
  {
    std::cout<<"Sample(int)"<<std::endl;
  }

  Sample(const Sample& sobj) noexcept
  {
    if (this != &sobj)
    {
      std::cout << "Sample(const Sample&)" << std::endl;
      if(sobj.data)
        this->data = new T(*sobj.data); // Deep copy the data
    }
  }
  Sample& operator=(const Sample& sobj) noexcept
  {
    if (this != &sobj)
    {
      std::cout << "Sample& operator=(const Sample&)" << std::endl;
      if(sobj.data)
        this->data = new T(*sobj.data); // Deep copy the data
    }
    return *this;
  }
  Sample(Sample&& sobj) noexcept
  {
    std::cout<<"Sample(Sample&&)"<<std::endl;
    delete (this->data);
    this->data = std::exchange(sobj.data, nullptr);
  }
  Sample& operator=(Sample&& sobj) noexcept
  {
    if (this != &sobj)
    {
      std::cout << "Sample& operator=(Sample&&)" << std::endl;
      delete (this->data);
      this->data = std::exchange(sobj.data, nullptr);
    }
    return *this;
  }
  ~Sample() noexcept
  {
    std::cout<<"~Sample()"<<std::endl;
  }

  T getData() const noexcept
  {
    return *data;
  }
};