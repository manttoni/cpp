#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        // Constructors and destructors
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap& other);
        ~FragTrap();

        // Actions
        void attack(const std::string& target); // overriding to print different message
        void highFivesGuys(void);
};

std::ostream& operator<<(std::ostream& os, FragTrap& ft);

#endif