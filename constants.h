
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants 
{
    const int max_dev = 20; // juvenile development time (egg to adult) expressed as days left till eclosion (eclosion on day 0)
    const int num_gen = 6; // number of different genotypes in the mosquito population
    const double PI = 3.14159265;
}

enum BoundaryType{Toroid, Edge};
enum DispersalType{DistanceKernel, Radial};

#endif //CONSTANTS_H