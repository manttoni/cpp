#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int grade_sign;
        const int grade_exec;
        std::string target;
    public:
        //con- & destructors
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other) = delete;
        ~AForm();
        AForm(const std::string& name, int grade_sign, int grade_exec, const std::string &target);

        // getters
        std::string getName() const;
        bool getIsSigned() const;
        int getGrade_sign() const;
        int getGrade_exec() const;
        std::string getTarget() const;

        // other
        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif