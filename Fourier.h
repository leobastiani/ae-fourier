#ifndef __FOURIER_H__
#define __FOURIER_H__

#include <array>

#define FourierN 50

/**
 * estrutura de dados de uma
 * função de furier
 */

struct Fourier {
    Fourier(double l, double h);
    double A0;
    std::array<double, FourierN> An;
    std::array<double, FourierN> Bn;
    double eval(double x);
};

#endif // __FOURIER_H__