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
     * Constructor of the class Monomio.
     */
    Monomio(firstElement fELement, deg grado);

    /**
     * Function that indicates if the monomio is zero.
     * @return true if the monomio is zero, false otherwise.
     */
    bool null() const;

    /**
     * Function that determines if the monomio is constant.
     * @return true if the monomio is constant, false otherwise.
     */
    bool constant() const;

    /**
     * Function that calculate the value of the monomio for a value of x.
     * @return the value of the monomio for a value of x.
     */
    double calculate(double x) const;

    /**
     * Function that calculate the derivative of the monomio.
     * @return the derivative of the monomio.
     */
    Monomio derv() const;

    /**
     * Operator of comparisons of equality and ordering.
     * @param another monomio compared.
     */
    auto operator<=>(const Monomio &otro) const
    {
        if (grado < otro.grado) return -1;
        if (grado > otro.grado) return 1;
        return 0;
    }

    /**
     * Operator of comparisons of equality.
     * @param another monomio compared.
     */
    bool operator==(const Monomio &otro) const = default;

    /**
     * Exit operator.
     * @param the output stream.
     * @param monomio the output monomio.
     * @return the output stream.
     */
    friend std::ostream& operator<<(std::ostream& out, const Monomio& monomio);
};

#endif
