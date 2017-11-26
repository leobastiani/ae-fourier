#ifndef __AE_H__
#define __AE_H__

#include <iostream>
#include <vector>
#include <map>
#include "Limit.h"
#include "Ind.h"

/**
 * o algoritmo evolutivo em si
 */

class Ae {
    // limits low e high
    double (*f)(double);
public:
    Ind *inds;
    int nInd;
    Ae(uint nInd, double (*f)(double));
    ~Ae();

    double getScore(Ind &ind);
    run();

    friend std::ostream& operator<<(std::ostream& stream, const Ae& ae);
};


#endif // __AE_H__