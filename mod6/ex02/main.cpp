#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>

Base * generate(void)
{
	srand(time(nullptr));
	int r = rand() % 3;
	switch (r)
	{
		case 0:
			std::cout << "Created A" << std::endl;
			return new A();
		case 1:
			std::cout << "Created B" << std::endl;
			return new B();
		case 2:
			std::cout << "Created C" << std::endl;
			return new C();
	}
	return nullptr;
}

void identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	} catch(const std::exception& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void) b;
			std::cout << "B" << std::endl;
		} catch(const std::exception& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "C" << std::endl;
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main(void)
{
	Base *r = generate();
	std::cout << "Identifying: " << std::endl;
	identify(r);
	identify(*r);
	delete r;
	return (0);
}