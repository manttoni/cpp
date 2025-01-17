#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "--Tests from subject--" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta; meta = nullptr;
    delete j; j = nullptr;
    delete i; i = nullptr;

    std::cout << "--More tests--" << std::endl;
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

    return 0;
}