#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

        void whoAmI();
        void attack(const std::string& target);

        std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, DiamondTrap& dt);

#endif