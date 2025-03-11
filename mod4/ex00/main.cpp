#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl << "--Tests from subject--" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta; meta = nullptr;
	delete j; j = nullptr;
	delete i; i = nullptr;

	std::cout << std::endl << "--More tests--" << std::endl;
	Animal animal = Animal();
	Animal cat = Cat();
	Animal dog = Dog();

	std::cout << "Type of animal: " << animal.getType() << std::endl;
	std::cout << "Type of cat: " << cat.getType() << std::endl;
	cat.makeSound();
	std::cout << "Type of dog: " << dog.getType() << std::endl;
	dog.makeSound();

	Cat catcat = Cat();
	Dog dogdog = Dog();

	std::cout << "Type of catcat: " << catcat.getType() << std::endl;
	catcat.makeSound();
	std::cout << "Type of dogdog: " << dogdog.getType() << std::endl;
	dogdog.makeSound();

	std::cout << std::endl << "--Testing animal constructors and their makeSound--" << std::endl;
	Animal a = Animal();
	Animal b;
	b = a;
	Animal c = Animal(b);
	std::cout << "-- Making sounds --" << std::endl;
	a.makeSound();
	b.makeSound();
	c.makeSound();
	std::cout << "-- Stopped making sounds --" << std::endl;
	
	std::cout << std::endl << "--Testing Cat constructors and their makeSound" << std::endl;
	Cat c1 = Cat();
	Cat c2;
	c2 = c1;
	Cat c3 = Cat(c2);
	std::cout << "-- Making sounds --" << std::endl;
	c1.makeSound();
	c2.makeSound();
	c3.makeSound();
	std::cout << "-- Stopped making sounds --" << std::endl;

	

	return 0;
}