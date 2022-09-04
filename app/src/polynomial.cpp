#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "polynomial.hpp"


Polynomial::Polynomial(termsInThePolynomial terms) : terms(terms) {
}

Monomio::deg Polynomial::deg() const {
    
    auto mayor = std::max_element(this->terms.begin(), this->terms.end(),
                                  [](const Monomio &fistAux, const Monomio &aux)
                                  { return fistAux < aux; });
    return mayor->grado;
}

double Polynomial::calculate(double x) const {
    auto resultado = 0.0;

    for (const auto &monomio : this->terms)
        resultado += monomio.calculate(x);

    return resultado;
}

double Polynomial::squareRoot() const {
    const auto dev = this->der();
    double x = 0.0, fx, fdx;

    while (std::fabs(fx = this->calculate(x)) >= 0.001) {
        fdx = dev.calculate(x);
        x -= fx / fdx;
    }

    return x;
}

Polynomial Polynomial::der() const {
    termsInThePolynomial ders;

    for (const auto &monomio : this->terms){
        auto der = monomio.derv();
        if (!der.null()){
            ders.push_back(der);
        }
    }

    return Polynomial(ders);
}
