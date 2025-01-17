#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        // Constructors and destructors
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();

        // Actions
        void attack(const std::string& target); // overriding to print different message
        void guardGate();
};

std::ostream& operator<<(std::ostream& os, ScavTrap& st);

#endif