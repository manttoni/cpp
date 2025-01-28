#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <exception>

const std::string tests[] = { "2147483648", "-2147483649", "2147483647", "-2147483648",
                        "99999999999999999999", "999999999999999999999999999999",
                        "9999999999999999999999999999999999999999",
                        "1", "11", "111", "1111",
                        "1.", "11.", "111.", "1111.",
                        "1.1", "11.11", "111.111", "1111.1111",
                        ".1", ".11", ".111", ".1111",
                        "+inf", "-inf", "nan",
                        "asd", "qwe", "zxc",
                        ".", "-", "f", "",
                        "1a", "1.1a", "1.a", ".a1", " " };

static void tryConversion(const std::string& s)
{
    try                         { ScalarConverter::convert(s); }
    catch(std::exception& e)    { std::cerr << "Error: " << e.what() << std::endl; }
}

static void testRun(const std::string& pre, const std::string& post)
{
    for (std::string s : tests)
    {
        std::string input = pre + s + post;
        std::cout << "~~~~:" << input << ":~~~~" << std::endl;
        tryConversion(input);
        std::getline(std::cin, input);
        if (input != "") break;
    }
}

int main(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
        tryConversion(av[i]);
    if (ac != 1)
        return (0);

    std::cout << "====== NO MODIFICATIONS ======" << std::endl;
    testRun("", "");

    std::cout << "====== FLOAT ======" << std::endl;
    testRun("", "f");

    std::cout << "====== NEGATIVE ======" << std::endl;
    testRun("-", "");

    std::cout << "====== NEGATIVE FLOAT ======" << std::endl;
    testRun("-", "f");

    return 0;
}