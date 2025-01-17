#include <iostream>
#include "ScavTrap.hpp"

void attackTest(ScavTrap& attacker, ScavTrap& defender)
{
    bool hasEnergy = attacker.getEnergy() > 0;
    attacker.attack("Defender");
    if (hasEnergy)
        defender.takeDamage(attacker.getDamage());
}

int main(void)
{
    std::cout << std::endl << "--Testing constructors--" << std::endl;
    ScavTrap a = ScavTrap("ScavTrap");
    ScavTrap b;
    b = a;
    ScavTrap c = ScavTrap(b);

    ScavTrap attacker = ScavTrap("Attacker");
    ScavTrap defender = ScavTrap("Defender");

    std::cout << std::endl << "--Created objects--" << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << attacker << std::endl;
    std::cout << defender << std::endl;

    std::cout << std::endl << "--Testing attack and takeDamage--" << std::endl;
    for (int i = 0; i < 60; ++i)
        attackTest(attacker, defender);

    std::cout << std::endl << "--Testing repair--" << std::endl;
    for (int i = 0; i < 60; ++i)
        defender.beRepaired(1);

    std::cout << "--Testing guardGate()--" << std::endl;
    attacker.guardGate();
    defender.guardGate();

    std::cout << std::endl << "--End of main, calling destructors--" << std::endl;
    return 0;
}