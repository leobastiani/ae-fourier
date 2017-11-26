/**
 * Este algoritmo visa conseguir os termos para que a função de fourier se assemelhe
 * a função f declarada logo abaixo
 * para isso, um algoritmo evolutivo compara funções de fourier inicializadas aletoriamente
 * e com a melhor função interpola as demais
 */

#include <iostream>
#include <map>
#include "Random.h"
#include "Gene.h"
#include "Ae.h"
#include "Limit.h"

using namespace std;


/**
 * Função f(x)
 * o algoritmo evolutivo tenta se assemelhar a essa função
 */
double f(double x) {
    // insira qualquer função no intervalo de -1 a 1
    return sin(x*M_PI);
}

#ifdef TEST
int main(int argc, char *argv[]) {
    cout << "Teste de número aleatório 10 a 20: " << Random::integer(10, 20) << endl;
    cout << "Teste de número aleatório 0 a 1: " << Random::rand() << endl;
    cout << "Teste de número aleatório 10 a 15: " << Random::rand(10, 15) << endl << endl;
    Gene x(-1, 1);
    cout << x << endl;
    cout << "Eval de x: " << x.eval(0) << endl;

    Ae ae(10, f);
    std::cout << "ae: " << ae << std::endl;

    ae.run();
    return 0;
}
#endif // TEST


#ifndef TEST

int main(int argc, char *argv[]) {
    Ae ae(10, f);
    ae.run();
    return 0;
}

#endif // TEST