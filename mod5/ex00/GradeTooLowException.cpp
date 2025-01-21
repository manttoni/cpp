#include "GradeTooLowException.hpp"
#include "Bureaucrat.hpp"

const char* GradeTooLowException::what() const noexcept
{
    return "Grade too low!\n";
}