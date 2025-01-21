#include "GradeTooHighException.hpp"
#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high!\n";
}