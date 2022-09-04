#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include <cstddef>
#include <compare>

class Monomio
{
public:
    using firstElement = double;
    using deg = size_t;

    firstElement fELement;
    deg grado;

    /**
     * Constructor de la clase Monomio.
     */
    Monomio(firstElement fELement, deg grado);

    /**
     * Función que indica si el monomio es cero.
     * @return true si el monomio es cero, false en caso contrario.
     */
    bool null() const;

    /**
     * Función que determina si el monomio es constante.
     * @return true si el monomio es constante, false en caso contrario.
     */
    bool constant() const;

    /**
     * Función que calcula el valor del monomio para un valor de x.
     * @return El valor del monomio para un valor de x.
     */
    double calculate(double x) const;

    /**
     * Función que calcula el derivado del monomio.
     * @return El derivado del monomio.
     */
    Monomio derv() const;

    /**
     * Operador de comparaciones de igualdad y ordenamiento.
     * @param otro El monomio comparado.
     */
    auto operator<=>(const Monomio &otro) const
    {
        if (grado < otro.grado) return -1;
        if (grado > otro.grado) return 1;
        return 0;
    }

    /**
     * Operador de comparaciones de igualdad.
     * @param otro El polinomio comparado.
     */
    bool operator==(const Monomio &otro) const = default;

    /**
     * Operador de salida.
     * @param out El stream de salida.
     * @param monomio El monomio de salida.
     * @return El stream de salida.
     */
    friend std::ostream& operator<<(std::ostream& out, const Monomio& monomio);
};

#endif
