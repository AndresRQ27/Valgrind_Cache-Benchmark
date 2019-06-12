/**
 * g++ -std=c++11 testVector.cpp -o testVector.o
 */

#include <iostream>
#include <list>
#include <random>

static void testList(int size);

static void testList(const int size){
  std::list<double> list;
  
  ///Random number generator between -1.0 and 1.0
  std::random_device generator;
  std::uniform_real_distribution<double> distribution(-1.0,1.0);
  
  ///Fills the vector with random numbers
  for (int j = 0; j < size; ++j) {
    double number = distribution(generator);
    list.push_back(number);
  }
  
  ///Declares the parameters  
  double y;
  auto i = list.cbegin();
  
  y = (*i + *i++)/2; //Calculates the first iteration
  for (; i != --list.cend(); ++i) {
    y = (*i-- + *i + *i++)/3;
  }
  ++i;
  y = (*i-- + *i)/2; //Calculates the last iteration
  
}

// 50000000 is a good number
int main(int argc, char **arg) {
  int n = std::stoi(arg[1]);
  testList(n);
  return 0;
}

