/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:27:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/13 13:05:15 by lkonttin         ###   ########.fr       */
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

    delete src;
    delete srcCopy;
}

void    assignmentOperatorTest()
{
    std::cout << "---------------" << std::endl;
    std::cout << "COPY ASSIGNMENT OPERATOR TESTS" << std::endl;
    std::cout << "---------------" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    IMateriaSource* src2 = new MateriaSource();

    src2 = src;
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure()); // results in full inventory
    src2->learnMateria(new Ice()); // cannot learn
    src->learnMateria(new Cure()); // will learn

    delete src;
    delete src2;
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