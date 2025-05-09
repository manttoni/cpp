#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade; // [1,150]
    public:
        // orthodox canonical form
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other) = delete;
        ~Bureaucrat();

        // other constructors
        Bureaucrat(const std::string name, int grade);

        // getters
        const std::string getName() const;
        int getGrade() const;

        // grade increment/decrement
        void promote();
        void demote();

        // other
        void signForm(AForm& form);
        void executeForm(AForm const & form);

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

// << overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif