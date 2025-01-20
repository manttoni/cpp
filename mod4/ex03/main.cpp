#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    std::cout << "---- Test from subject ----" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;


    std::cout << std::endl << "---- More tests ----" << std::endl;
    IMateriaSource* ms1 = new MateriaSource();
    ms1->learnMateria(new Ice());
    ms1->learnMateria(new Cure());
    ICharacter* character = new Character("Main character");
    character->equip(ms1->createMateria("ice"));
    ICharacter* morokolli = new Character("Morokolli");
    character->use(0, *morokolli);

    

    delete character;
    delete morokolli;
    delete ms1;


    return 0;
}