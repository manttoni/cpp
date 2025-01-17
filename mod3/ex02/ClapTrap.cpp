#include <iostream>
#include "ClapTrap.hpp"

// Canonical form
// Default
ClapTrap::ClapTrap() : name(""), hitpoints(10), energy(10), damage(0)
{
    std::cout << "ClapTrap default constructor" << std::endl;
}

// With name
ClapTrap::ClapTrap(const std::string& name) : name(name), hitpoints(10), energy(10), damage(0)
{
    std::cout << "ClapTrap constructor with name as param" << std::endl;
}

// Copy
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), 
                                            hitpoints(other.hitpoints), 
                                            energy(other.energy),
                                            damage(other.damage)
{
    std::cout << "ClapTrap copy constructor" << std::endl;
}

// Copy assignment
ClapTrap& ClapTrap::operator=(ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator" << std::endl;
    if (this == &other)
        return *this;
    this->name = other.name;
    this->hitpoints = other.hitpoints;
    this->energy = other.energy;
    this->damage = other.damage;
    return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor" << std::endl;
}

// Actions
// Attack if enough energy and print a message
void ClapTrap::attack(const std::string& target)
{
    if (energy == 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage" << std::endl;
    energy--;
}

// Lose hitpoints equal to amount unless its more than hitpoints
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " damage (" << hitpoints;
    if (amount > hitpoints)
        amount = hitpoints;
    hitpoints -= amount;
    std::cout << " -> " << hitpoints << ")" << std::endl;
}

// Be repaired up to UINT_MAX
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy == 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " is repaired for the amount of " << amount << " (" << hitpoints;
    if (amount > UINT_MAX - hitpoints)
        amount = UINT_MAX - hitpoints;
    hitpoints += amount;
    std::cout << " -> " << hitpoints << ")" << std::endl;
    energy--;
}

// Getters
unsigned int ClapTrap::getDamage() const { return damage; }
unsigned int ClapTrap::getEnergy() const { return energy; }
unsigned int ClapTrap::getHitpoints() const { return hitpoints; }
std::string ClapTrap::getName() const { return name; }

// Setters
void ClapTrap::setEnergy(unsigned int value) { energy = value; }
void ClapTrap::setHitpoints(unsigned int value) { hitpoints = value; }
void ClapTrap::setDamage(unsigned int value) { damage = value; }