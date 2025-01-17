#include <iostream>
#include "ClapTrap.hpp"

void attackTest(ClapTrap& attacker, ClapTrap& defender)
{
    bool hasEnergy = attacker.getEnergy() > 0;
    attacker.attack("Defender");
    if (hasEnergy)
        defender.takeDamage(attacker.getDamage());
}

int main(void)
{
    std::cout << std::endl << "--Testing constructors--" << std::endl;
    ClapTrap a = ClapTrap("ClapTrap");
    ClapTrap b;
    b = a;
    ClapTrap c = ClapTrap(b);

    ClapTrap attacker = ClapTrap("Attacker");
    ClapTrap defender = ClapTrap("Defender");

    std::cout << std::endl << "--Testing attack and takeDamage--" << std::endl;
    for (int i = 0; i < 20; ++i)
        attackTest(attacker, defender);

    std::cout << std::endl << "--Testing repair--" << std::endl;
    for (int i = 0; i < 20; ++i)
        defender.beRepaired(1);

    std::cout << std::endl << "--End of main, calling destructors--" << std::endl;
    return 0;
}