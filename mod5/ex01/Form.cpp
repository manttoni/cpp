#include "Form.hpp"
#include <iostream>

//con- & destructors
Form::Form() : name(""), isSigned(false), grade_sign(150), grade_exec(150) {}

Form::Form(const Form& other) :   name(other.name),
                            isSigned(other.isSigned),
                            grade_sign(other.grade_sign), 
                            grade_exec(other.grade_exec) {}

// can only assign isSigned value
Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return *this;
    isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

Form::Form(std::string name, int grade_sign, int grade_exec) :    name(name),
                                                            isSigned(false),
                                                            grade_sign(grade_sign),
                                                            grade_exec(grade_exec)
{
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
    if (grade_sign < 1 || grade_sign < 1)
        throw GradeTooHighException();
}

// getters
std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGrade_sign() const { return grade_sign; }
int Form::getGrade_exec() const { return grade_exec; }

// other
void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > grade_sign)
        throw GradeTooLowException();
    isSigned = true;
}

// exceptions
const char* Form::GradeTooHighException::what() const noexcept
{
    return "Grade too high!\n";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Grade too low!\n";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Name:                " << form.getName() << std::endl;
    os << "Signed:              " << form.getIsSigned() << std::endl;
    os << "Grade for signing:   " << form.getGrade_sign() << std::endl;
    os << "Grade for executing: " << form.getGrade_exec() << std::endl;
    return os;
}