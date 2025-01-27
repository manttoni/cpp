#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        Intern(const Intern& other) = delete;
        Intern& operator=(const Intern& other) = delete;
        ~Intern();
        AForm* makeForm(const std::string& type, const std::string& target);
};

#endif