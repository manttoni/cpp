#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <iomanip>
#include <cmath>
#include <cfloat>

static bool isType(const std::string &s)
{
    size_t len = s.size();
    if (len == 1)
        return true;
    if (len == 0)
        throw std::runtime_error("input is empty");

    if (s.find_first_of("f") < s.size() - 1)
        throw std::runtime_error("\'f\' is not last");

    if (s.find_last_of("-") != std::string::npos && s.find_last_of("-") > 0)
        throw std::runtime_error("\'-\' is not first");

    if (s.find_first_of(".") != s.find_last_of("."))
        throw std::runtime_error("multiple \'.\'");

    if (s.find_first_not_of("f-.1234567890") != std::string::npos)
        throw std::runtime_error("forbidden character");

    if (s.find_first_of("1234567890") == std::string::npos)
        throw std::runtime_error("no number");

    return true;
}

static bool isFloat(const std::string &s)
{
    return s.back() == 'f';
}

static bool isInt(const std::string &s)
{
    try
    {
        return stod(s) == (double)stoi(s);
    }
    catch (std::exception &e)
    {
        return false;
    }
}

static bool isChar(const std::string &s)
{
    if (s.size() > 1)
        return false;
    if (s[0] >= '0' && s[0] <= '9')
        return false;
    return true;
}

static type getType(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return FLOAT;
    else if (s == "-inf" || s == "+inf" || s == "nan")
        return DOUBLE;

    if (isType(s) == false)
        return NONE;
    if (isChar(s) == true)
        return CHAR;
    if (isFloat(s) == true)
        return FLOAT;
    if (isInt(s) == true)
        return INT;
    return DOUBLE;
}

static size_t getPrecision(const std::string &s)
{
    size_t pos = s.find('.');
    if (pos == std::string::npos)
        return 1;
    size_t i = 0;

    for (; i + pos + 1 < s.size(); ++i)
        if (s[pos + i + 1] == 'f')
            break;
    return i > 1 ? i : 1;
}

void ScalarConverter::convert(const std::string &s)
{
    type t = getType(s);

    char c;
    int i;
    float f;
    double d;

    switch (t)
    {
    case CHAR:
        std::cout << "CHAR" << std::endl;
        c = static_cast<char>(s[0]);
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
        break;
    case INT:
        std::cout << "INT" << std::endl;
        i = stoi(s);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        break;
    case FLOAT:
        std::cout << "FLOAT" << std::endl;
        try
        {
            f = stof(s);
        }
        catch (std::exception &e)
        {
            f = std::numeric_limits<float>::infinity();
            if (s[0] == '-')
                f *= -1;
        }
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        break;
    case DOUBLE:
        std::cout << "DOUBLE" << std::endl;
        d = stod(s);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        break;
    default:
        throw std::runtime_error("Not any supported type");
    }

    std::cout << "char:   ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << c << std::endl;

    std::cout << "int:    ";
    if (std::isnan(d) || std::isinf(d))
        std::cout << "impossible" << std::endl;
    else if (d - 1 >= INT_MAX || d + 1 <= INT_MIN)
        std::cout << "overflow" << std::endl;
    else
        std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(getPrecision(s));

    std::cout << "float:  " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}