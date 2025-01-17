#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <climits>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitpoints;
        unsigned int energy;
        unsigned int damage;
    public:
        // Canonical form
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(ClapTrap& other);
        ~ClapTrap();

        // Actions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // Getters
        unsigned int getDamage() const;
        unsigned int getEnergy() const;
        unsigned int getHitpoints() const;
        std::string getName() const;

        //Setters
        void setEnergy(unsigned int value);
        void setHitpoints(unsigned int value);
        void setDamage(unsigned int value);
};

#endif