#include <vector>
#include <string>
#include <regex>
#include "utils.hpp"

using namespace std;

namespace utils
{
    string toLowerCase(const string &polynomial)
    {
        string aux = polynomial;
        /**
         *   template <class InputIterator, class OutputIterator, class UnaryOperation>
         *   OutputIterator transform (InputIterator first1, InputIterator last1,
         *   OutputIterator result, UnaryOperation op);
         * 
         * https://cplusplus.com/reference/algorithm/transform/
         */
        transform(aux.begin(), aux.end(), aux.begin(),[]( char characterAux){ return tolower(characterAux); });
        return aux;
    }

    string trim(const string &polynomial)
    {
        string aux = polynomial;
        // https://cplusplus.com/reference/algorithm/remove/
        aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
        return aux;
    }

        vector<string> convert(const string &polynomial,unsigned char delimitador)
    {
        int start = 0u;
        vector<string> characters;
        auto end = polynomial.find(delimitador); // int or character

        while (end != string::npos)
        {
            characters.push_back(polynomial.substr(start, end - start)); // push elements into a vector from the back
            start = end + 1; // increment the start value to use again
            end = polynomial.find(delimitador, start); // helps to search for an element in the specified range
        }

        characters.push_back(polynomial.substr(start, end));
        return characters;
    }

    string changeOfSign(const string &polynomial)
    {
        return regex_replace(polynomial, regex("-"), "+-");
    }


}
