#include <iostream>
#include "ScavTrap.hpp"

// Constructors
// Default
ScavTrap::ScavTrap() : ClapTrap()
{
    setHitpoints(100);
    setEnergy(50);
    setDamage(20);
    std::cout << "ScavTrap default constructor" << std::endl;
}

// Constructor with name as param
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    setHitpoints(100);
    setEnergy(50);
    setDamage(20);
    std::cout << "ScavTrap constructor with name as param" << std::endl;
}

// Copy
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor" << std::endl;
}

// Actions
// Attack. Override to print different message than ClapTrap.attack()
void ScavTrap::attack(const std::string& target)
{
    if (getEnergy() == 0)
    {
        std::cout << "ScavTrap " << getName() << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getDamage() << " points of damage" << std::endl;
    setEnergy(getEnergy() - 1);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, ScavTrap& st)
{
    os << "--" << std::endl;
    os << "Name: " << st.getName() << std::endl;
    os << "Hitpoints: " << st.getHitpoints() << std::endl;
    os << "Energy: " << st.getEnergy() << std::endl;
    os << "Damage: " << st.getDamage() << std::endl;
    return os;
}