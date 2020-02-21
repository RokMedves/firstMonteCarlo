/*
Trying to write a MC for simple curve integration
20. 2. 2020
Rok Medves
 */

#include <iostream>
#include "mcintegrator.hpp"
#include <math.h>
#include <time.h>

double f(double x){
    return x*x;
}

double g(double x){
  return sin(x);
}


int main(int argc, char* argv[]){
  
  //std::cout << "hello" << std::endl;
  MCintegrate integ {0, 2 * M_PI, f, (unsigned int)time(NULL)};

  std::cout << integ.integrate(100000) << std::endl;
  
  integ.setFunction(g);
  //std::cout << integ.integrate(100000) << std::endl;
  return 0;
}
