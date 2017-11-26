#include "Random.h"

namespace Random {
    // save "seed" to log file
    std::mt19937 random_engine(4);
    std::uniform_real_distribution<> dis(0, 1);

    uint integer(uint l, uint h) {
        return (random_engine() % (h - l + 1)) + l;
    }

    double rand() {
        return random_engine() / (double) random_engine.max();
    }

    double randSigned() {
        return 2.0*(Random::rand() - 0.5);
    }

    double rand(double l, double h) {
        return rand() * (h-l) + l;
    }
}