#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    std::cout << Bureaucrat("Boss", 1);
    std::cout << Bureaucrat("Some guy", 75);
    std::cout << Bureaucrat("Intern", 150);

    try
    {
        std::cout << "Creating one with grade 0" << std::endl;
        Bureaucrat super = Bureaucrat("Super", 0);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Creating one with grade 151" << std::endl;
        Bureaucrat toolow = Bureaucrat("toolow", 151);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat boss = Bureaucrat("Boss", 1);
    Bureaucrat nonboss = Bureaucrat("Nonboss", 150);
    try
    {
        std::cout << "Promoting a 1" << std::endl;
        boss.promote();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Demoting a 151" << std::endl;
        nonboss.demote();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << boss << nonboss;
    return 0;
}