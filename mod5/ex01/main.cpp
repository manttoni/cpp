#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::endl;

    Bureaucrat boss = Bureaucrat("Boss", 1);
    Bureaucrat mid = Bureaucrat("Mid", 75);
    Bureaucrat low = Bureaucrat("Low", 150);

    std::cout << boss << std::endl << mid << std::endl << low << std::endl;

    Form a = Form("A", 75, 1);
    Form b = Form("B", 150, 75);
    Form c = Form("C", 150, 150);
    Form d = Form("D", 1, 1);

    std::cout << a << std::endl << b << std::endl << c << std::endl << d << std::endl;

    low.signForm(a);
    low.signForm(b);
    low.signForm(c);
    low.signForm(d);

    std::cout << std::endl;

    mid.signForm(a);
    mid.signForm(b);
    mid.signForm(c);
    mid.signForm(d);

    std::cout << std::endl;

    boss.signForm(a);
    boss.signForm(b);
    boss.signForm(c);
    boss.signForm(d);

    std::cout << std::endl << "---- Trying to create 3 invalid forms ----" << std::endl;
    try { Form inv1 = Form("", 0, 151); }
    catch(std::exception& e) { std::cout << e.what(); }
    try { Form inv1 = Form("", 1, 151); }
    catch(std::exception& e) { std::cout << e.what(); }
    try { Form inv1 = Form("", 0, 150); }
    catch(std::exception& e) { std::cout << e.what(); }

    return 0;
}