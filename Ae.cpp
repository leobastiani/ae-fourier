#include <iostream>
#include <algorithm>
#include "Ae.h"
#include "Fourier.h"
#include "Gene.h"


using namespace std;

double compass;

Ae::Ae(uint nInd, double (*f)(double)) : nInd(nInd), f(f) {
    inds = new Ind[nInd];
    Gene &g = inds[0].genes[0];
    compass = (g.h-g.l)/(25.0);
}

Ae::~Ae() {
    delete []inds;
}


int sortInd(void *a, void *b) {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    return -1;
}

Ae::run() {
    /**
     * para cada geração
     */
    for(long unsigned int g=1; ; g++) {
        // vamos analisar a função fit
        // para cada ind
        for(int i=0; i<nInd; i++) {
            inds[i].score = getScore(inds[i]);
        }

        std::sort(inds, inds + nInd,
              [](Ind const & a, Ind const & b) -> bool
              { return a.score < b.score; } );

        // agr eu transo
        for(int i=1; i<nInd; i++) {
            inds[0].transe(inds[i]);
        }

        
        /**
         * imprimo de pouco em pouco
         */
        if(g % 10000 == 0) {
            for(int i=0; i<nInd; i++) {
                cout << inds[i] << endl;
            }
            cout << endl << endl;
        }

        /**
         * se meu erro foi baixo
         * posso encerrar e imprimir
         */
        bool erroBaixo = inds[0].score < 1e-4;
        if(g % 100000 == 0 || erroBaixo) {
            cout << "Pontos:" << endl;
            double x = inds[0].genes[0].l;
            const double limit = inds[0].genes[0].h;
            while(x <= limit) {
                cout << inds[0].eval(x) << endl;
                x += compass;
            }
            cout << endl << endl;
            std::cout << "getScore(inds[0]): " << getScore(inds[0]) << std::endl;
            std::cout << "inds[0].genes[0]: " << inds[0].genes[0] << std::endl;
            cout << "Gerações: " << g << endl;

            if(erroBaixo) {
                break;
            }
        }
    }
}


ostream& operator<<(ostream& stream, const Ae& ae) {
    stream << "Ae<>";
    return stream;
}

/**
 * o quão cada indívudo pontua
 */
double Ae::getScore(Ind &ind) {
    double score = 0;
    double x = ind.genes[0].l;
    const double limit = ind.genes[0].h;
    while(!(x > limit)) {
        double dscore = abs(f(x) - ind.eval(x));
        // elevo ao quadrado
        // dscore *= dscore;
        score += dscore;
        x += compass;
    }
    return score;
}