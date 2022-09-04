#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

using namespace std;

namespace utils
{
    /**
     * If the string has any lowercase letters, this function 
     * converts them to uppercase
     * @param string Polynomial 
     * @return {string} Polynomial without lowercase letters
     */
    string toLowerCase(const string &polynomial);

    /**
     * Remove extra spaces from text
     * @param string Polynomial
     * @return {string} Polynomial without extra spaces
     */
    string trim(const string &polynomial);

    /**
     * If the polynomial contains any negative sign, this function
     * change the sign.
     * For example: "x**4 + 2x - 1" => "x**4 + 2x +  -1"     
     * @return {string} Polynomial with reversed sign
     */
    string changeOfSign(const string &polynomial);

    /**
     * Convert a string polynomial to array
     * @param string Polynomial
     * @param delimiter Character to delimiter the conversion
     * @return {array} Polynomial
     */
    vector<string> convert(const string &polynomial, unsigned char delimiter);
}

#endif
