#include "dyn_arr.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray() {
  this->capacity = 8;
  this->data = new float[this->capacity];
}

DynamicArray::DynamicArray(std::int64_t capacity) {
  // check if user is dumb
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1"); // https://en.cppreference.com/w/cpp/error/exception.html
    // std::exception like an animal
    // std::invalid_argument like a dog (heir of animal)
  }
  this->capacity = capacity;
  this->data = new float[this->capacity];
}

DynamicArray::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new float[this->capacity]; // (*this).data

  for (int i = 0; i <= size; ++i) {
    this->data[i] = other.data[i];
  }
}

DynamicArray::~DynamicArray() {
  // deallocate if allocated
  if (this->data) {
    delete[] this->data;
  }
}

void DynamicArray::push_back(float x) {
  // reallocate memory
  // increase capacity
  // copy data
  // dealloc old
  // assign new to old
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[++size] = x;
  // data[size + 1] = x;
  // ++size;
}

float DynamicArray::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

float DynamicArray::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMax = -1e+38; // -1 * 10^38
  // float currentMax = std::numeric_limits<float>::lowest();
  for (int i = 0; i <= size; ++i) {
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

float DynamicArray::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMin = 1e+38; // -1 * 10^38
  // float currentMin = std::numeric_limits<float>::max();
  for (int i = 0; i <= size; ++i) {
    if (data[i] <= currentMin) {
      currentMin = data[i];
    }
  }
  return currentMin;
}

void DynamicArray::clear() {
  if (this->data) {
    delete[] this->data;
    this->data = nullptr;
  }
  size = -1;
  capacity = 8;
}

void DynamicArray::reinitialize() {
  clear();
  data = new float[capacity](); // init with zeros
}

void DynamicArray::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

float DynamicArray::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx > size) {
    throw std::invalid_argument("Out of range");
  }
  return data[size - idx]; // Arabic operator[]
  // return data[idx];     // European operator[]
}

float DynamicArray::operator()() {
  if (isEmpty()) {
    return 0;
  }
  float sum = 0;
  for (int i = 0; i <= size; ++i) {
    sum += data[i];
  }
  return sum;
}
// ПОШЛО ДЗ

void DynamicArray::push_front(float x){
  if (isEmpty()){
    data[0] = x;
    size++;
    return;
  }

  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }

  size++;
  for (int i = 0; i < size+1; ++i){
    data[size-i+1] = data[size-i];
  }
  data[0] = x;
  return;
}

void DynamicArray::front(){
  std::cout<<data[0];
  return;
}

void DynamicArray::back(){
  std::cout << data[size];
  return;
}

void DynamicArray::insert(int idx, float val){
  if (idx > size || idx < 0) {
    throw std::invalid_argument("out of range");
  }
  if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  for (int i = 0; i < size-idx+1; ++i){
    data[size+1-i] = data[size-i];
  }
  data[idx] = val;
  return;
}

void DynamicArray::del(int idx){
  if (idx > size || idx < 0) {
    throw std::invalid_argument("out of range");
  }
  for (int i = 0; i < size-idx; ++i){
    data[idx+i] = data[idx+i+1];
  }
  size--;
  return;
}

void DynamicArray::erace_after(int idx){
  if (idx > size || idx < 0) {
    throw std::invalid_argument("out of range");
  }
  size = idx;
};

void DynamicArray::increase_capacity(std::int64_t new_capacity){
  if (new_capacity < capacity){
    throw std::invalid_argument("new capacity must be greater, use decrease_capacity method");
  }
  float* tempArray = new float[new_capacity];
  for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
  delete[] data;
  data = tempArray;
  capacity = new_capacity;
}

void DynamicArray::decrease_capacity(std::int64_t new_capacity){
  if (new_capacity > capacity){
    throw std::invalid_argument("new capacity must be less, use increase_capacity method");
  }
  
  float* tempArray = new float[new_capacity];
  for (int i = 0; i < capacity; ++i) {
      tempArray[i] = data[i];
    }
  delete[] data;
  data = tempArray;
  capacity = new_capacity;
}