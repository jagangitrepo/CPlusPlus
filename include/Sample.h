#pragma once
#include <iostream>

class Sample
{
  int data {0};
  public:
  Sample():data(0)
  {
    std::cout<<"Sample()"<<std::endl;
  }
  Sample(int data_):data(data_)
  {
    std::cout<<"Sample(int)"<<std::endl;
  }
  Sample(const Sample& sobj) noexcept
  {
    if (this != &sobj)
    {
      std::cout << "Sample(const Sample&)" << std::endl;
      this->data = sobj.data;
    }
  }
  Sample& operator=(const Sample& sobj) noexcept
  {
    if (this != std::addressof(sobj))
    {
      std::cout << "Sample& operator(const Sample&)" << std::endl;
      this->data = sobj.data;
    }
    return *this;
  }
  Sample(Sample&& sobj) noexcept
  {
    std::cout<<"Sample(Sample&&)"<<std::endl;
    this->data = std::exchange(sobj.data, 0);
  }
  Sample& operator=(Sample&& sobj) noexcept
  {
    if (this != std::addressof(sobj))
    {
      std::cout << "Sample& operator(Sample&&)" << std::endl;
      this->data = std::exchange(sobj.data, 0);
    }
    return *this;
  }
  ~Sample() noexcept
  {
    std::cout<<"~Sample()"<<std::endl;
  }

  int getData() const noexcept
  {
    return data;
  }
};