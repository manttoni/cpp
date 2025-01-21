#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low!\n";
}