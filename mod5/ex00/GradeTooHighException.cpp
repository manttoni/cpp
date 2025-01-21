#include "GradeTooHighException.hpp"

const char* GradeTooHighException::what() const noexcept
{
    return "Grade too high!\n";
}