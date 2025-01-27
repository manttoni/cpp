#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void test(Bureaucrat& b)
{
    std::cout << "----------------" << std::endl;

    std::cout << b << std::endl;

    ShrubberyCreationForm shrub = ShrubberyCreationForm("shrub");
    RobotomyRequestForm robo = RobotomyRequestForm("robo");
    PresidentialPardonForm president = PresidentialPardonForm("president");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << president << std::endl;

    std::cout << "----------------" << std::endl;
    
    b.signForm(shrub);
    std::cout << "----" << std::endl;
    b.signForm(robo);
    std::cout << "----" << std::endl;
    b.signForm(president);
    std::cout << "----" << std::endl;
    b.executeForm(shrub);
    std::cout << "----" << std::endl;
    b.executeForm(robo);
    std::cout << "----" << std::endl;
    b.executeForm(president);
}

int main(void)
{

    Bureaucrat high = Bureaucrat("high", 1);
    Bureaucrat mid = Bureaucrat("mid", 75);
    Bureaucrat low = Bureaucrat("low", 150);

    test(low);
    test(mid);
    test(high);

    return 0;
}