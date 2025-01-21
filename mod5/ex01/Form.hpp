#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int grade_sign;
        const int grade_exec;
    public:
        //con- & destructors
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        Form(std::string name, int grade_sign, int grade_exec);

        // getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGrade_sign() const;
        int getGrade_exec() const;

        // other
        void beSigned(const Bureaucrat& b);

        // exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif