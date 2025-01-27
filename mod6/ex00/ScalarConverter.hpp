#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string& s);
};

typedef enum
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NONE
} type;

#endif