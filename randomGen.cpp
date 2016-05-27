#include "randomGen.h"
#include <climits>
#include <iostream>

randomGen::randomGen(int seed){
    this->seed = seed;
    modulo = UINT_MAX;
    constant =  1664525;
    multiplier = 1013904223;
    lastRandom = seed;
}

int randomGen::getSeed(){
    return seed;
}

void randomGen::setSeed(int newSeed){
    lastRandom = newSeed;
    seed = newSeed;
}

double randomGen::getRandom(double lowerLimit, double upperLimit){
    unsigned int randomNumber = ((multiplier*lastRandom)+constant) % modulo;
    lastRandom = randomNumber;
    //Now convert inbetween limits
    double randomDouble = ((((double) randomNumber)/UINT_MAX)*(upperLimit-lowerLimit))+lowerLimit;
    return randomDouble;
}

