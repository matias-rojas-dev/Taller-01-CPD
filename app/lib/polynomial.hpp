#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <vector>
#include <compare>
#include "monomial.hpp"

using namespace std;

class Polynomial
{
public:
    using termsInThePolynomial = vector<Monomio>;
    termsInThePolynomial terms;
    


    
    /**
     * Find the element with major deg
     * 
     *
     * @return Element with major deg
     */
    Monomio::deg deg() const;


    Polynomial(termsInThePolynomial terms);


    // Methods


    /**
     * Calculate the value of the polynomial
     * @return {double} Operation result
     */

    double calculate(double value) const;


    /**
     * Function that calculate the root of the polynomial using the method of Newton-Raphson.
     * @return The root of the polynomial.
     */
    double squareRoot() const;


    /**
     * Fuction that calculate the derivative.
     * @return The derivative of polynomial.
     */
    Polynomial der() const;



};

#endif
