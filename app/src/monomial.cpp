#include <iostream>
#include <cmath>
#include "monomial.hpp"

using namespace std;

Monomio::Monomio(firstElement fELement, deg grado) : fELement(fELement), grado(grado) {
}

bool Monomio::null() const
{
    return this -> fELement == 0;
}

bool Monomio::constant() const
{
    return this -> grado == 0;
}

double Monomio::calculate(double x) const
{
    return this -> fELement * pow(x, this->grado);
}

Monomio Monomio::derv() const
{
    if (this->constant())
        return {0.0, 0};

    return {this->fELement * this->grado, this->grado - 1};
}

