#ifndef COMPILEPOLYNOMIAL_HPP
#define COMPILEPOLYNOMIAL_HPP

#include <string>
#include <regex>
#include "polynomial.hpp"

/**
 * Tipos de tokens que se pueden encontrar en una expresión de monomio.
 */
enum TipoToken
{
    EXPRESION = 0,
    SIGNO,
    COEFICIENTE,
    VARIABLE,
    GRADO,
};

class CompilePolynomial
{
public:
    using token_t = std::string;
    using tokensAuxiliar = std::vector<token_t>;

    std::string expresion;

    /**
     * Patrón de un monomio.
     */
    static const std::regex monomial;

    /**
     * Constructor de la clase Compilador.
     */
    CompilePolynomial(std::string expresion);

    /**
     * Función que compila la expresión en un polinomio.
     * @return El polinomio compilado a partir de la expresión.
     */
    Polynomial compile() const;

private:
    /**
     * Función que determina si la expresión es válida.
     * @return true si la expresión es válida, false en caso contrario.
     */
    bool isToken(const std::string &token) const;

    /**
     * Función que separa la expresión en tokens.
     * @return Los tokens extraídos de la expresión.
     */
    tokensAuxiliar convert() const;

    /**
     * Función que extrae componentes de un token.
     * @param token El token a extraer.
     * @return El resultado de la extracción de componentes.
     */
    std::smatch getTerm(const std::string &token) const;

    /**
     * Función que convierte un token a monomio.
     * @return El monomio convertido a partir del token.
     */
    Monomio checkToken(const std::string &token) const;

    /**
     * Función que adapta la expresión para ser tokenizada.
     * @return La expresión adaptada.
     */
    std::string adaptive() const;

    /**
     * Función que parsea el coeficiente de un monomio.
     * @param token_signo El token del signo del monomio.
     * @param token_coeficiente El token del coeficiente del monomio.
     * @return El coeficiente del monomio.
     */
    Monomio::firstElement
    compareCoef(const std::string &token_signo,
                      const std::string &token_coeficiente) const;

    /**
     * Función que parsea el grado de un monomio.
     * @param token_signo El token de la variable del monomio.
     * @param token_coeficiente El token del grado del monomio.
     * @return El grado del monomio.
     */
    Monomio::deg compareDeg(const std::string &token_variable, const std::string &token_grado) const;
};

#endif
