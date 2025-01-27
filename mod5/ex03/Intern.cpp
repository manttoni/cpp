#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& type, const std::string& target)
{
    std::string types[] = {"shrubbery", "robotomy", "pardon"};
    int i;
    for (i = 0; i < 3; ++i)
        if (types[i] == type)
            break;
    AForm* form;
    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form =  new PresidentialPardonForm(target);
            break;
        default:
            form = nullptr;
    }
    if (form == nullptr)
        std::cout << "Form type not found!" << std::endl;
    else
        std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}
