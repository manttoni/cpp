#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <exception>

static bool tryConversion(const std::string& s)
{
    try {
        ScalarConverter::convert(std::string(s));
        return true;
    }
    catch(std::exception& e) { 
        std::cerr << e.what() << std::endl;
        return false;
    }
}

int main(void)
{
    /*
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " <str to convert>" << std::endl;
        return 1;
    }
    */

    std::string asd;

    std::string tests[] = { "12345678901234567890",
                            "1", "11", "111", "1111",
                            "1.", "11.", "111.", "1111.",
                            "1.1", "11.11", "111.111", "1111.1111",
                            "+inf", "-inf", "nan",
                            "asd", "qwe", "zxc",
                            "1234567890", "",
                            "a", "aa", "aaa", "aaaa",
                            ".1", ".11", ".111", ".1111" };

    std::cout << "====== NO MODIFICATIONS ======" << std::endl;
    for (std::string s : tests)
    {
        std::cout << "~~~~: " << s << " :~~~~" << std::endl;
        tryConversion(s);
        std::getline(std::cin, asd);
    }

    std::cout << "====== AS FLOAT ======" << std::endl;
    for (std::string s : tests)
    {
        std::cout << "~~~~: " << s + "f" << " :~~~~" << std::endl;
        tryConversion(s + "f");
        std::getline(std::cin, asd);
    }

    std::cout << "====== NEGATIVE ======" << std::endl;
    for (std::string s : tests)
    {
        std::cout << "~~~~: " << "-" + s << " :~~~~" << std::endl;
        tryConversion("-" + s);
        std::getline(std::cin, asd);
    }

    std::cout << "====== BOTH MODS ======" << std::endl;
    for (std::string s : tests)
    {
        std::cout << "~~~~: " << "-" + s << " :~~~~" << std::endl;
        tryConversion("-" + s);
        std::getline(std::cin, asd);
    }

    return 0;
}