/**
 * g++ -std=c++11 testVector.cpp -o testVector.o
 */

#include <iostream>
#include <vector>
#include <random>

static void testVector(int size);

static void testVector(const int size){
  std::vector<double> vector; //Declares the vector
  //vector.reserve(size); //Reserves space in memory
  
  ///Random number generator between -1.0 and 1.0
  std::random_device generator;
  std::uniform_real_distribution<double> distribution(-1.0,1.0);
  
  ///Fills the vector with random numbers
  for (int j = 0; j < size; ++j) {
    double number = distribution(generator);
    vector.push_back(number);
  }
  
  ///Declares the parameters  
  double y;
  auto i = vector.cbegin();
  
  y = (*i + *i++)/2; //Calculates the first iteration
  for (; i != --vector.cend(); ++i) {
    y = (*i-- + *i + *i++)/3;
  }
  ++i;
  y = (*i-- + *i)/2; //Calculates the last iteration
  
}

// 50000000 is a good number
int main(int argc, char **arg) {
  int n = std::stoi(arg[1]);
  testVector(n);
  return 0;
}

