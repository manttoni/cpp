#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
        ~ScalarConverter() = delete;

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