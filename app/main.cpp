#include <iostream>
#include <string>
#include <cstdlib>
#include "compilePolynomial.hpp"
#include "polynomial.hpp"

using namespace std;

/**
 * This function receives a polynomial and applies Newton Raphson algorith
 * to calculate its square root
 * For example: "x**4 + 2x - 1"
 * @param polynomial {string} Polynomial 
 * 
 */
void solvePolynomial(string polynomial)
{
    auto compilador = CompilePolynomial(polynomial);
    auto polinomio = compilador.compile();
    auto solucion = polinomio.squareRoot();
    cout << "Solución: " << solucion << '\n';
}

/**
 * Principal function
 * @param argc {int} Arguments qty
 * @param argv {char} Polynomial.
 * @return This function returns the solutions and members 
 */
int main(int argc, char **argv)
{
    if (argv != NULL)
    {   
        solvePolynomial(argv[1]);
    }

    cout << "=== Integrantes ===\n";    
    cout << "Matías Rojas Rojas\n";
    cout << "Maximilinao Araya Mundaca\n";
    return 0;
}



