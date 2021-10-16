#include "utils.h"

double degreesToRadians(double degrees){
    return degrees * M_PI / 180.0;
}
double randomDouble(){
    return rand() / (RAND_MAX + 1.0);
    
}
