#ifndef __IND_H__
#define __IND_H__

#include "Gene.h"


/**
 * o indivíduo
 * ele só tem 1 gene
 * e esse gene pode assumir
 * valores de -1 até 1
 */

class Ind {
private:
public:
    Gene genes[1] = {{-1, 1}};
    double score = 0;
    Ind();
    ~Ind();
    double eval(double x) {return genes[0].eval(x);}
    void transe(Ind &i);

    friend std::ostream& operator<<(std::ostream& stream, const Ind& ind);
};

#endif // __IND_H__