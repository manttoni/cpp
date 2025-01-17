#include <iostream>
#include "DiamondTrap.hpp"

void attackTest(DiamondTrap& attacker, DiamondTrap& defender)
{
    bool hasEnergy = attacker.ScavTrap::getEnergy() > 0;
    attacker.attack("Defender");
    if (hasEnergy)
        defender.ScavTrap::takeDamage(attacker.FragTrap::getDamage());
}

int main(void)
{
    std::cout << std::endl << "--Testing constructors--" << std::endl;
    DiamondTrap a = DiamondTrap("DiamondTrap");
    DiamondTrap b;
    b = a;
    DiamondTrap c = DiamondTrap(b);

    DiamondTrap attacker = DiamondTrap("Attacker");
    DiamondTrap defender = DiamondTrap("Defender");

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
        defender.ScavTrap::beRepaired(1);

    std::cout << std::endl << "--Testing whoAmI()--" << std::endl;
    a.whoAmI();
    b.whoAmI();
    c.whoAmI();
    attacker.whoAmI();
    defender.whoAmI();

    std::cout << std::endl << "--End of main, calling destructors--" << std::endl;
    return 0;
}