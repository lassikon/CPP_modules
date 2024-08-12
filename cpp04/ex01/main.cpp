/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:14 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/12 10:52:42 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void    testFromSubject()
{
    std::cout << "---------------------" << std::endl;
    std::cout << "TEST FROM THE SUBJECT" << std::endl;
    std::cout << "---------------------" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;
}

void    animalArrayTest()
{
    std::cout << "------------------------------------" << std::endl;
    std::cout << "ARRAY OF 10 ANIMALS, 5 CATS & 5 DOGS" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    Animal *animals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 50)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << "memory address of " << (animals[i]->getType()) << ": " << &animals[i] << " and its brain: ";
        if (animals[i]->getType() == "Cat")
            std::cout << dynamic_cast<Cat*>(animals[i])->getBrain() << std::endl;
        else
            std::cout << dynamic_cast<Dog*>(animals[i])->getBrain() << std::endl;
    }
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
}

void    deepCopyTest()
{
    std::cout << "---------------" << std::endl;
    std::cout << "DEEP COPY TESTS" << std::endl;
    std::cout << "---------------" << std::endl;

    Dog *dog = new Dog();
    (*dog).getBrain()->setIdea("Original idea 1", 0);
    (*dog).getBrain()->setIdea("Original idea 2", 50);

    std::cout << "ORIGINAL IDEAS:" << std::endl;
    std::cout << (*dog).getBrain()->getIdea(0) << std::endl;
    std::cout << (*dog).getBrain()->getIdea(50) << std::endl;
    std::cout << std::endl;

    Dog *dogCopy = new Dog(*dog);
    std::cout << "DOG COPY'S IDEAS:" << std::endl;
    std::cout << (*dogCopy).getBrain()->getIdea(0) << std::endl;
    std::cout << (*dogCopy).getBrain()->getIdea(50) << std::endl;
    std::cout << std::endl;
    
    (*dogCopy).getBrain()->setIdea("New idea 1", 0);
    (*dogCopy).getBrain()->setIdea("New idea 2", 50);
    std::cout << "DOG COPY'S NEW IDEAS:" << std::endl;
    std::cout << (*dogCopy).getBrain()->getIdea(0) << std::endl;
    std::cout << (*dogCopy).getBrain()->getIdea(50) << std::endl;
    std::cout << std::endl;

    std::cout << "ORIGINAL DOG'S IDEAS:" << std::endl;
    std::cout << (*dog).getBrain()->getIdea(0) << std::endl;
    std::cout << (*dog).getBrain()->getIdea(50) << std::endl;
    std::cout << std::endl;

    delete dog;
    delete dogCopy;
}

void    assignmentOperatorTest()
{
    
}

int main()
{
    testFromSubject();
    animalArrayTest();
    deepCopyTest();
    assignmentOperatorTest();
}
