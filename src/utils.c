#include "utils.h"

double degreesToRadians(double degrees){
    return degrees * M_PI / 180.0;
}
double randomDouble(){
    return rand() / (RAND_MAX + 1.0);    
}

double randomDoubleInRange(double min, double max){
	return min + (max - min)*randomDouble();
}

double clamp(double x, double min, double max){
	if(x < min){
		return min;
	}
	if(x > max){
		return max;
	}
	return x;
}
