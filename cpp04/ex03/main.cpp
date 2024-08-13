/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:27:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/13 11:39:54 by lkonttin         ###   ########.fr       */
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
    bob->unequip(2);
    bob->unequip(3);
    bob->unequip(4); // should output nothing

    // bob->use(0, bob);

    for (int i = 0; i < 20; i++)
    {
        if (trashBin[i])
        {
            delete trashBin[i];
            trashBin[i] = nullptr;
        }
    }
}

int main()
{
    // testsFromSubject();

    IMateriaSource* src = new MateriaSource();
    ICharacter* bob = new Character("Bob");

    fillMateriaSource(src);
    equipCharacter(bob, src);
    
    delete src;
    delete bob;
}