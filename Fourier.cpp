#include <iostream>
#include <math.h>
#include "Fourier.h"
#include "Random.h"

using namespace std;

/**
 * calculando a função de fourier
 */
double Fourier::eval(double x) {
    double res = A0;
    for(int i=0; i<FourierN; i++) {
        res += An[i]*cos((i+1)*x) + Bn[i]*sin((i+1)*x);
    }
    return res;
}

Fourier::Fourier(double l, double h) {
    const double mean = (l+h) / 2.0;
    const double distance = h-l;
    const double limit = distance*3;
    A0 = Random::rand(-limit+mean, +limit+mean);
    for(int i=0; i<FourierN; i++) {
        An[i] = Random::rand(-limit+mean, +limit+mean);
        Bn[i] = Random::rand(-limit+mean, +limit+mean);
    }
}