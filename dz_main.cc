#include "dyn_arr.h"
#include <iostream>

int main() {
  DynamicArray arr;
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);
  arr.printData();
  std::cout << arr.min() << std::endl;
  std::cout << arr.max() << std::endl;
  std::cout << arr.add(0, 2) << std::endl;
  // arr.clear();
  arr.printData();
  std::cout << arr[2] << std::endl;
  // std::cout << arr.operator[](2) << std::endl;
  // std::cout << arr() << std::endl;
  std::cout << arr.operator()() << std::endl;
  ///////// homework checking
  arr.push_back(2.5);
  arr.push_front(10);
  //std::cout<< arr[0] << std::endl;
  arr.printData();
  arr.front();
  std::cout<<std::endl;

  arr.back();
  std::cout<<std::endl;

  arr.insert(2, 11);

  arr.del(1);

  
  arr.printData();


  return 0;
}
