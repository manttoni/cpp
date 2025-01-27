#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
    Intern intern;

    AForm* form1 = intern.makeForm("shrubbery", "shrub");
    AForm* form2 = intern.makeForm("robotomy", "Bender");
    AForm* form3 = intern.makeForm("pardon", "Trump");
    AForm* form4 = intern.makeForm("does not exist", "apple");

    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;
    if (form4 != nullptr)
        std::cout << *form4 << std::endl;

    delete form1;
    delete form2;
    delete form3;
    if (form4 != nullptr)
    delete form4;

    return 0;
}