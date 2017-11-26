#include <iostream>
#include "Gene.h"
#include "Random.h"

using namespace std;

Gene::Gene(double l, double h) :  f(l, h), l(l), h(h) {
}

Gene::~Gene() {
}


ostream& operator<<(ostream& stream, const Gene& gene) {
    const Fourier &f = gene.f;
    stream << "Gene:" << endl;
    stream << "A0: " << f.A0 << endl;
    for(int i=0; i<f.An.size(); i++) {
        stream << "An[" << i << "]: " << f.An[i] << "\t\t";
        stream << "Bn[" << i << "]: " << f.Bn[i] << endl;
    }
    return stream;
}

void transeDouble(double &a, double &b, double score) {
    const double mutacao = score*0.01*Random::randSigned();
    a = (a+b)/2.0 + mutacao;
}

/**
 * misture um gene com o outro
 */
void Gene::transe(Gene &g, double score) {
    transeDouble(g.f.A0, f.A0, score);
    for(int i=0; i<FourierN; i++) {
        transeDouble(g.f.An[i], f.An[i], score);
        transeDouble(g.f.Bn[i], f.Bn[i], score);
    }
}