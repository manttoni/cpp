#include <iostream>
#include "FragTrap.hpp"

void attackTest(FragTrap& attacker, FragTrap& defender)
{
    bool hasEnergy = attacker.getEnergy() > 0;
    attacker.attack("Defender");
    if (hasEnergy)
        defender.takeDamage(attacker.getDamage());
}

int main(void)
{
    std::cout << std::endl << "--Testing constructors--" << std::endl;
    FragTrap a = FragTrap("FragTrap");
    FragTrap b;
    b = a;
    FragTrap c = FragTrap(b);

    FragTrap attacker = FragTrap("Attacker");
    FragTrap defender = FragTrap("Defender");

    std::cout << std::endl << "--Created objects--" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << attacker << std::endl;
    std::cout << defender << std::endl;

    std::cout << std::endl << "--Testing attack and takeDamage--" << std::endl;
    for (int i = 0; i < 110; ++i)
        attackTest(attacker, defender);

    std::cout << std::endl << "--Testing repair--" << std::endl;
    for (int i = 0; i < 110; ++i)
        defender.beRepaired(1);

    std::cout << std::endl << "--Testing highFivesGuys()--" << std::endl;
    attacker.highFivesGuys();
    defender.highFivesGuys();

    std::cout << std::endl << "--End of main, calling destructors--" << std::endl;
    return 0;
}