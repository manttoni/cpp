#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "---- Testing constructors ----" << std::endl;
    Cat cat_with_idea = Cat();
    cat_with_idea.addIdea("This is the idea it has. It hopes it doesn't get stolen.");

    Cat cat_with_better_idea = Cat();
    cat_with_better_idea.addIdea("A better idea. Would be beneficial for a clone.");

    std::cout << "--cat_with_idea:" << std::endl;
    cat_with_idea.getBrain().printIdeas();

    std::cout << "--cat_with_better_idea: " << std::endl;
    cat_with_better_idea.getBrain().printIdeas();

    Cat idea_stealing_cat = Cat(cat_with_idea);

    std::cout << "--idea_stealing_cat: " << std::endl;
    idea_stealing_cat.getBrain().printIdeas();

    Cat clone = cat_with_better_idea;

    std::cout << "--clone: " << std::endl;
    clone.getBrain().printIdeas();

    Cat normal_cat;
    normal_cat = cat_with_idea;

    std::cout << "--normal_cat: " << std::endl;
    normal_cat.getBrain().printIdeas();

    cat_with_idea.addIdea("An original idea. No other cat has this.");
    cat_with_better_idea.addIdea("The clone will not have this idea.");
    idea_stealing_cat.addIdea("The thief cat got an idea!");
    clone.addIdea("Clones have ideas too");
    normal_cat.addIdea("no brain cells left");

    std::cout << "---- Testing if copies are shallow or not ----" << std::endl;

    std::cout << "--cat_with_idea:" << std::endl;
    cat_with_idea.getBrain().printIdeas();
    std::cout << "--cat_with_better_idea: " << std::endl;
    cat_with_better_idea.getBrain().printIdeas();
    std::cout << "--idea_stealing_cat: " << std::endl;
    idea_stealing_cat.getBrain().printIdeas();
    std::cout << "--clone: " << std::endl;
    clone.getBrain().printIdeas();
    std::cout << "--normal_cat: " << std::endl;
    normal_cat.getBrain().printIdeas();

    std::cout << "---- Subjects tests ----" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    //...

    std::cout << "---- Objective from subject ----" << std::endl;

    // Create array
    Animal *array[100];
    for (int i = 0; i < 100; ++i)
    {
        if (i < 50)
            array[i] = new Cat();
        else
            array[i] = new Dog();
        array[i]->addIdea("Idea id: " + std::to_string(i));
    }

    // print animal types and ideas
    for(int i = 0; i < 100; ++i)
    {
        std::cout << "--" << std::endl << "Type: " << array[i]->getType() << std::endl;
        array[i]->getBrain().printIdeas();
    }

    // delete all 100 animals
    for (int i = 0; i < 100; ++i)
        delete array[i];

    return 0;
}