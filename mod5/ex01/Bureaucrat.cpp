#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// orthodox canonical form
Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this == &other)
        return *this;
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// other constructors
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

// getters
const std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// grade increment/decrement
void Bureaucrat::promote()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::demote()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

// << overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low!\n";
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed form " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}