#pragma once
#include <iostream>

class Sample
{
  public:
  Sample()
  {
    std::cout<<"Sample()"<<std::endl;
  }
  Sample(int)
  {
    std::cout<<"Sample(int)"<<std::endl;
  }
  Sample(const Sample&)
  {
    std::cout<<"Sample(const Sample&)"<<std::endl;
  }
  Sample& operator=(const Sample&)
  {
    std::cout<<"Sample& operator(const Sample&)"<<std::endl;
    return *this;
  }
  Sample(Sample&&)
  {
    std::cout<<"Sample(Sample&&)"<<std::endl;
  }
  Sample& operator=(Sample&&)
  {
    std::cout<<"Sample& operator(Sample&&)"<<std::endl;
    return *this;
  }
  ~Sample()
  {
    std::cout<<"~Sample()"<<std::endl;
  }
};