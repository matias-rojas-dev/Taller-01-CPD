#include <iostream>
#include <charconv>
#include <regex>
#include <algorithm>
#include "utils.hpp"
#include "compilePolynomial.hpp"
#include "monomial.hpp"

using namespace std;

#define REGEXMON "^([\\-\\+])?(\\d*\\.?\\d+)?(?:(x)(?:(?:\\*\\*)([0-9]))?)?$"

const regex CompilePolynomial::monomial = regex(REGEXMON);

CompilePolynomial::CompilePolynomial(string expresion) {
    using namespace utils;
    this->expresion = changeOfSign(toLowerCase(trim(expresion)));
}

CompilePolynomial::tokensAuxiliar CompilePolynomial::convert() const {
    return utils::convert(this->expresion, '+');
}

smatch CompilePolynomial::getTerm(const string &term) const {
    return *sregex_iterator(term.begin(), term.end(), CompilePolynomial::monomial);
}

Monomio CompilePolynomial::checkToken(const string &token) const {
    if (!this->isToken(token))
        throw invalid_argument("El token no es válido: " + token);

    smatch match = this->getTerm(token);
    auto compareDeg = this->compareCoef(match[TipoToken::SIGNO], match[TipoToken::COEFICIENTE]);
    auto deg = this->compareDeg(match[TipoToken::VARIABLE], match[TipoToken::GRADO]);

    return {compareDeg, deg};
}


Monomio::firstElement CompilePolynomial::compareCoef(const string &tSignal, const string &tCoef) const {
    auto tokenAUx = tCoef.empty() ? "1.0" : tCoef;
    return stod(tSignal + tokenAUx);
}

Monomio::deg CompilePolynomial::compareDeg(const string &token_variable, const string &token_grado) const {
    if (token_grado.empty())
        return !token_variable.empty();

    return stoul(token_grado);
}


Polynomial CompilePolynomial::compile() const {
    Polynomial::termsInThePolynomial terms;

    for (const auto &token : this->convert())
        terms.push_back(this->checkToken(token));

    return {terms};
}

bool CompilePolynomial::isToken(const string &token) const {
    return regex_match(token, CompilePolynomial::monomial);
}

