#include "AForm.hpp"
#include <iostream>

//con- & destructors
AForm::AForm() : name(""), isSigned(false), grade_sign(150), grade_exec(150), target("") {}

AForm::AForm(const AForm& other) :   name(other.name),
                            isSigned(other.isSigned),
                            grade_sign(other.grade_sign), 
                            grade_exec(other.grade_exec) {}


AForm::~AForm() {}

AForm::AForm(const std::string& name, 
                int grade_sign,
                int grade_exec,
                const std::string& target) : name(name),
                                        isSigned(false),
                                        grade_sign(grade_sign),
                                        grade_exec(grade_exec),
                                        target(target)
{
    if (grade_sign > 150 || grade_exec > 150)
        throw AForm::GradeTooLowException();
    if (grade_sign < 1 || grade_exec < 1)
        throw AForm::GradeTooHighException();
}

// getters
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGrade_sign() const { return grade_sign; }
int AForm::getGrade_exec() const { return grade_exec; }
std::string AForm::getTarget() const { return target; }

// sign & execute
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > grade_sign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (isSigned == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > grade_exec)
        throw AForm::GradeTooLowException();
    executeAction();
}

// exceptions
const char* AForm::GradeTooHighException::what() const noexcept
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Name:                " << form.getName() << std::endl;
    os << "Signed:              " << form.getIsSigned() << std::endl;
    os << "Grade for signing:   " << form.getGrade_sign() << std::endl;
    os << "Grade for executing: " << form.getGrade_exec() << std::endl;
    os << "Target:              " << form.getTarget() << std::endl;
    return os;
}