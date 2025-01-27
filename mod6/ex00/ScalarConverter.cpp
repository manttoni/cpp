#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

static type getType(std::string s)
{
    if (s[0] == '-') s.erase(0,1);
    if (s.empty()) return NONE;
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return FLOAT;
    else if (s == "-inf" || s == "+inf" || s == "nan")
        return DOUBLE;

    int periods = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s.length() == 1) break;
        if (s[i] == 'f' && i < s.length() - 1)
            return NONE;
        if (s[i] == '.' && periods != 0)
            return NONE;
        if ((s[i] > '9' || s[i] < '0') && s[i] != '.' && s[i] != 'f')
            return NONE;
    }

    if (s.length() == 1 && (s[0] > '9' || s[0] < '0'))
        return CHAR;
    if (s.back() == 'f')
        return FLOAT;
    if (s.find('.') == std::string::npos)
        return INT;
    return DOUBLE;
}

static size_t getPrecision(const std::string& s)
{
    size_t pos = s.find('.');
    if (pos == std::string::npos) return 1;
    size_t i = 0;

    for (; i + pos + 1 < s.size(); ++i)
        if (s[pos + i + 1] == 'f') break;
    return i > 1 ? i : 1;
}

void ScalarConverter::convert(const std::string& s)
{
    type t = getType(s);
    int precision = 1;

    char    c;
    int     i;
    float   f;
    double  d;

    switch (t)
    {
        case CHAR:
            //std::cout << "CHAR" << std::endl;
            c = static_cast<char>(s[0]);
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case INT:
            //std::cout << "INT" << std::endl;
            i = stoi(s);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case FLOAT:
            //std::cout << "FLOAT" << std::endl;
            f = stof(s);
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            precision = getPrecision(s);
            break;
        case DOUBLE:
            //std::cout << "DOUBLE" << std::endl;
            d = stod(s);
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            precision = getPrecision(s);
            break;
        default:
            throw std::runtime_error("Not any supported type");
    }

    std::cout << "char:   ";
    if (i < 0 || i > 127)       std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126) std::cout << "Non printable" << std::endl;
    else                        std::cout << c << std::endl;

    std::cout << "int:    ";
    if (std::isnan(d) || std::isinf(d)) std::cout << "impossible" << std::endl;
    else                                std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float:  " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
