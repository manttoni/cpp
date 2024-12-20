#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		void announce(void);
		void setname(std::string name);
};

Zombie *zombieHorde(int N, std::string name);