/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:27:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/13 16:01:29 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void    testsFromSubject()
{
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
}

void    fillMateriaSource(IMateriaSource* src)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "FILLING MATERIASOURCE MEMORY" << std::endl;
    std::cout << "----------------------------" << std::endl;

    AMateria* ice = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();

    src->learnMateria(ice);
    src->learnMateria(cure1);
    src->learnMateria(ice);
    src->learnMateria(cure2);
    src->learnMateria(ice);
    src->learnMateria(nullptr);
}

void    equipCharacter(ICharacter* bob, IMateriaSource* src)
{
    std::cout << "-------------------" << std::endl;
    std::cout << "CHARACTER INVENTORY" << std::endl;
    std::cout << "-------------------" << std::endl;

    AMateria* tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("cure");
    bob->equip(tmp);
    tmp = src->createMateria("cure");
    bob->equip(tmp);
    tmp = src->createMateria("unknown");
    bob->equip(tmp);
    tmp = src->createMateria("ice");
    bob->equip(tmp);
    tmp = src->createMateria("cure");
    bob->equip(tmp);

    AMateria* trashBin[20]; // to hold unequipped items for deleting
    for (int i = 0; i < 20; i++)
        trashBin[i] = nullptr;

    trashBin[0] = dynamic_cast<Character*>(bob)->getInventory(0);
    bob->unequip(0);
    trashBin[1] = dynamic_cast<Character*>(bob)->getInventory(1);
    bob->unequip(1);
    trashBin[2] = dynamic_cast<Character*>(bob)->getInventory(2);
    bob->unequip(2);
    trashBin[3] = dynamic_cast<Character*>(bob)->getInventory(3);
    bob->unequip(3);
    bob->unequip(4); // should output nothing
    
    delete tmp;

    for (int i = 0; i < 20; i++)
    {
        if (trashBin[i])
        {
            delete trashBin[i];
            trashBin[i] = nullptr;
        }
    }
}

void    useMateria(ICharacter* bob, IMateriaSource* src)
{
    std::cout << "-------------" << std::endl;
    std::cout << "USING MATERIA" << std::endl;
    std::cout << "-------------" << std::endl;

    ICharacter* tim = new Character("Tim");

    bob->equip(src->createMateria("cure"));
    bob->equip(src->createMateria("ice"));

    bob->use(0, *tim);
    bob->use(1, *tim);
    bob->use(2, *tim); // should output nothing

    delete tim;
}

void    copyConstructorTest()
{
    std::cout << "---------------" << std::endl;
    std::cout << "COPY CONSTRUCTOR TESTS" << std::endl;
    std::cout << "---------------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    IMateriaSource* srcCopy = new MateriaSource(*dynamic_cast<MateriaSource*>(src));

    src->learnMateria(new Ice());
    src->learnMateria(new Cure()); // results in full memory  
    
    src->learnMateria(new Ice()); // cannot learn
    srcCopy->learnMateria(new Ice()); // will learn
    std::cout << std::endl;

    ICharacter* pete = new Character("Pete");
    pete->equip(src->createMateria("ice"));
    ICharacter* peteCopy = new Character(*dynamic_cast<Character*>(pete));
    std::cout << "peteCopy name: " << peteCopy->getName() << std::endl;
    peteCopy->use(0, *pete); // can use ice
    pete->equip(src->createMateria("cure"));
    peteCopy->use(1, *pete); // cannot use cure
    std::cout << std::endl;

    AMateria* ice = new Ice();
    AMateria* iceCopy = new Ice(*dynamic_cast<Ice*>(ice));
    iceCopy->use(*pete);

    AMateria* cure = new Cure();
    AMateria* cureCopy = new Cure(*dynamic_cast<Cure*>(cure));
    cureCopy->use(*pete);

    delete src;
    delete srcCopy;
    delete pete;
    delete peteCopy;
    delete ice;
    delete iceCopy;
    delete cure;
    delete cureCopy;
}

void    assignmentOperatorTest()
{
    std::cout << "---------------" << std::endl;
    std::cout << "COPY ASSIGNMENT OPERATOR TESTS" << std::endl;
    std::cout << "---------------" << std::endl;

    MateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    MateriaSource* srcCopy = new MateriaSource();

    *srcCopy = *src;
    srcCopy->learnMateria(new Ice());
    srcCopy->learnMateria(new Cure()); // results in full inventory
    srcCopy->learnMateria(new Ice()); // cannot learn
    src->learnMateria(new Cure()); // will learn
    std::cout << std::endl;

    Character* pete = new Character("Pete");
    Character* peteCopy = new Character("Pete2");
    pete->equip(src->createMateria("ice"));
    *peteCopy = *pete;
    std::cout << "peteCopy name: " << peteCopy->getName() << std::endl;
    peteCopy->use(0, *pete); // can use ice
    pete->equip(src->createMateria("cure"));
    peteCopy->use(1, *pete); // cannot use cure
    std::cout << std::endl;

    Ice* ice = new Ice();
    Ice* iceCopy = new Ice();
    *iceCopy = *ice;
    iceCopy->use(*pete);

    Cure* cure = new Cure();
    Cure* cureCopy = new Cure();
    *cureCopy = *cure;
    cureCopy->use(*pete);

    delete src;
    delete srcCopy;
    delete pete;
    delete peteCopy;
    delete ice;
    delete iceCopy;
    delete cure;
    delete cureCopy;
}

int main()
{
    testsFromSubject();

    IMateriaSource* src = new MateriaSource();
    ICharacter* bob = new Character("Bob");

    fillMateriaSource(src);
    equipCharacter(bob, src);
    useMateria(bob, src);
    copyConstructorTest();
    assignmentOperatorTest();
    
    delete src;
    delete bob;
}