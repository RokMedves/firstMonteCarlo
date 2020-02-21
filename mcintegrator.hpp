/*
  class for integrating functions with Monte Carlo method
20. 2. 2020 

*/

//class holding the methods


#include <stdlib.h>
#include <fstream> //ability to add files

class MCintegrate{
public:
  MCintegrate(double low, double high, double (*func)(double), unsigned int seed = 0)
    : lowerBound{low}, upperBound{high}, randomSeed{seed}, integratedFunction{func} // uniform init out memeber vars
  {
    
  }

  double integrate(unsigned int samples = 100000){
    //admittedly this is a bit clucky - could have just done all of this in one step, but at least more methods can be created now to change the private variables etc.
    
    srand(randomSeed);
    double randomNumberx = 0, randomNumbery = 0;
    double inLying = 0;
    std::ofstream inPoints("in.dat");
    std::ofstream outPoints("out.dat");

    for(unsigned int i = 0; i < samples; i++){

      randomNumberx = lowerBound + (upperBound - lowerBound) * ((double)rand() / randmax) ; //random number on given interval
      randomNumbery = (double)((double)rand() - (double)randmax/2) / (randmax / maxhight); //random number from -500 to 500

      if(randomNumbery > 0){
	if(integratedFunction(randomNumberx) > randomNumbery){
	  inLying++;
	  inPoints << randomNumberx << " " << randomNumbery << std::endl;
	} //+ contrib if above 0
	else{outPoints << randomNumberx << " " << randomNumbery << std::endl;}
	
      }if(randomNumbery <= 0){
	if(integratedFunction(randomNumberx) < randomNumbery){
	  inLying--;
	  inPoints << randomNumberx << " " << randomNumbery << std::endl;
	} //- contrib if below 0
	else{outPoints << randomNumberx << " " << randomNumbery << std::endl;}
   
      }
    }

    double ratio = (double)inLying / samples;
    double area = (upperBound - lowerBound) * maxhight;
    double result = ratio * area;
    if (gnuplotResult){gnuplotIt();}
    return result;
  }

  void setFunction(double (*func)(double)){
    integratedFunction = func;
  }
private:
  double lowerBound;
  double upperBound;
  unsigned int randomSeed;
  double (*integratedFunction)(double);

  unsigned int randmax = RAND_MAX;
  double maxhight = 100;

  bool gnuplotResult = true;

  void gnuplotIt(){
    //call gnuplot by yourself for now
  }
};
