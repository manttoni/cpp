#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor" << std::endl;
    name = "";
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergy(50);
    FragTrap::setDamage(30);
    ScavTrap::setDamage(30);
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
                                                    FragTrap(name), 
                                                    ScavTrap(name), 
                                                    name(name)
{
    std::cout << "DiamondTrap constructor with name as param" << std::endl;
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergy(50);
    FragTrap::setDamage(30);
    ScavTrap::setDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :    ClapTrap(other),
                                                        FragTrap(other), 
                                                        ScavTrap(other), 
                                                        name(other.name)
{
    std::cout << "DiamondTrap copy constructor" << std::endl;
    FragTrap::setHitpoints(other.getHitpoints());
    ScavTrap::setEnergy(other.getEnergy());
    FragTrap::setDamage(other.getDamage());
    ScavTrap::setDamage(other.getDamage());
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Name: " << name << " | ClapTrap name: " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const { return this->name; }

// ostream overload
std::ostream& operator<<(std::ostream& os, DiamondTrap& dt)
{
    os << "--" << std::endl;
    os << "Name: " << dt.getName() << std::endl;
    os << "Hitpoints: " << dt.FragTrap::getHitpoints() << std::endl;
    os << "Energy: " << dt.ScavTrap::getEnergy() << std::endl;
    os << "Damage: " << dt.FragTrap::getDamage() << std::endl;
    return os;
}