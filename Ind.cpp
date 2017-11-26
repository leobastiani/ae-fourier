#include <iostream>
#include "Ind.h"

using namespace std;

Ind::Ind() {
}

Ind::~Ind() {
}


ostream& operator<<(ostream& stream, const Ind& ind) {
    stream << "Ind<"<<ind.score<<">;";
    return stream;
}


void Ind::transe(Ind &i) {
    genes[0].transe(i.genes[0], score);
}