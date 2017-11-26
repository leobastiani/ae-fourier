#ifndef __GENE_H__
#define __GENE_H__

#include <iostream>
#include "Fourier.h"

/**
 * um gene
 * um indíviduo pode ter mais genes
 * mas neste exercicio, ele tem um gene somente
 */

class Gene {
    // limits low e high
    Fourier f;
public:
    double l;
    double h;
    Gene(double l, double h);
    ~Gene();
    inline double eval(double x) {return f.eval(x);};
    void transe(Gene &g, double score);


    friend std::ostream& operator<<(std::ostream& stream, const Gene& gene);
};

#endif // __GENE_H__