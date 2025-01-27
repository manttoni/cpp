#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy_request", 72, 45, "") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
: AForm(target + "_robotomy", 72, 45, target) {}

static bool coinFlip()
{
    srand((unsigned) time(NULL));
    return rand() % 2 == 0;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << " * Drilling noises *" << std::endl;
    if (coinFlip())
        std::cout << getTarget() << " has been successfully robotomized." << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}