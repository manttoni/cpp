#include <iostream>
#include "FragTrap.hpp"

// Constructors
// Default
FragTrap::FragTrap() : ClapTrap()
{
    setHitpoints(100);
    setEnergy(100);
    setDamage(30);
    std::cout << "FragTrap default constructor" << std::endl;
}

// Constructor with name as param
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    setHitpoints(100);
    setEnergy(100);
    setDamage(30);
    std::cout << "FragTrap constructor with name as param" << std::endl;
}

// Copy
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor" << std::endl;
}

// Actions
// Attack. Override to print different message than ClapTrap.attack()
void FragTrap::attack(const std::string& target)
{
    if (getEnergy() == 0)
    {
        std::cout << "FragTrap " << getName() << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage" << std::endl;
    setEnergy(getEnergy() - 1);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " high fives guys" << std::endl;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, FragTrap& ft)
{
    os << "--" << std::endl;
    os << "Name: " << ft.getName() << std::endl;
    os << "Hitpoints: " << ft.getHitpoints() << std::endl;
    os << "Energy: " << ft.getEnergy() << std::endl;
    os << "Damage: " << ft.getDamage() << std::endl;
    return os;
}