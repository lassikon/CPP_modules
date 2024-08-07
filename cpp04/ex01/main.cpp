/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:14 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/07 20:03:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    int n = 100;
    Animal *animals[100];
    for (int i = 0; i < n; i++)
    {
        if (i < 50)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "memory address of " << (animals[i]->getType()) << ": " << &animals[i] << " and its brain: ";
        if (animals[i]->getType() == "Cat")
            std::cout << dynamic_cast<Cat*>(animals[i])->getBrain() << std::endl;
        else
            std::cout << dynamic_cast<Dog*>(animals[i])->getBrain() << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete animals[i];
    }
}
