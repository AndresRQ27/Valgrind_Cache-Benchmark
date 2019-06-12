#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>

static void testVector(int size);
static void testList(int size);

static void testList(const int size){
  std::list<double> list;
  //std::cout << list.max_size() << std::endl;
  
  ///Random number generator between -1.0 and 1.0
  std::random_device generator;
  std::uniform_real_distribution<double> distribution(-1.0,1.0);
  
  ///Fills the vector with random numbers
  for (int j = 0; j < size; ++j) {
    double number = distribution(generator);
    list.push_back(number);
  }
  //std::cout << list.size() << std::endl; //Verifies the amount of numbers
  
  ///Declares the parameters
  //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); //Starts the timer
  
  double y;
  auto i = list.cbegin();
  
  y = (*i + *i++)/2; //Calculates the first iteration
  for (; i != --list.cend(); ++i) {
    y = (*i-- + *i + *i++)/3;
  }
  ++i;
  y = (*i-- + *i)/2; //Calculates the last iteration
  
  ///Grooming
  //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now(); //Stops the timer
  //std::chrono::high_resolution_clock::duration d = t2 - t1;
  //std::cout << "Process list finished at: " << d.count() << std::endl;
  
}

static void testVector(const int size){
  std::vector<double> vector; //Declares the vector
  //std::cout << vector.max_size() << std::endl; //Prints the max size
  vector.reserve(size); //Reserves space in memory
  
  ///Random number generator between -1.0 and 1.0
  std::random_device generator;
  std::uniform_real_distribution<double> distribution(-1.0,1.0);
  
  ///Fills the vector with random numbers
  for (int j = 0; j < size; ++j) {
    double number = distribution(generator);
    vector.push_back(number);
  }
  //std::cout << vector.size() << std::endl; //Verifies the amount of numbers
  
  ///Declares the parameters
  //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(); //Starts the timer
  
  double y;
  auto i = vector.cbegin();
  
  y = (*i + *i++)/2; //Calculates the first iteration
  for (; i != --vector.cend(); ++i) {
    y = (*i-- + *i + *i++)/3;
  }
  ++i;
  y = (*i-- + *i)/2; //Calculates the last iteration
  
  ///Grooming
  //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now(); //Stops the timer
  //std::chrono::high_resolution_clock::duration d = t2 - t1;
  //std::cout << "Process vector finished at: " << d.count() << std::endl;
  
}

int main() {
  testVector(50000000);
  testList(50000000);
  return 0;
}

