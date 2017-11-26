#include <iostream>
#include "Limit.h"

/**
 * A classe limite
 * definem os limites h e l (high e low)
 */

using namespace std;

Limit::Limit(double l, double h) : l(l), h(h) {
}

Limit::~Limit() {
}


ostream& operator<<(ostream& stream, const Limit& limit) {
    stream << "Limit<" << limit.l << ", " << limit.h << ">;";
    return stream;
}