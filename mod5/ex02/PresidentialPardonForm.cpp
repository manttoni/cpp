#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm() : AForm("pardon_form", 25, 5, "") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
: AForm(target + "_pardon", 25, 5, target) {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}