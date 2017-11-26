#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>

namespace Random {
    uint integer(uint l, uint h);

    double rand();

    double rand(double l, double h);
    double randSigned();

    // save "seed" to log file
    extern std::mt19937 random_engine;
    extern std::uniform_real_distribution<> dis;
}

#endif // __RANDOM_H__