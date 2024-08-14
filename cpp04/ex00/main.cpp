/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:51:14 by lkonttin          #+#    #+#             */
/*   Updated: 2024/08/14 12:10:01 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
	std::cout << "---------------------" << std::endl;
    std::cout << "TEST FROM THE SUBJECT" << std::endl;
    std::cout << "---------------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl << "WrongAnimal & WrongCat:" << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();
	
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the wronganimal sound!
	wrongAnimal->makeSound();
	
	delete(meta);
	delete(j);
	delete(i);
	delete(wrongAnimal);
	delete(cat);
	}

	{
	std::cout << "----------------------" << std::endl;
    std::cout << "COPY CONSTRUCTOR TESTS" << std::endl;
    std::cout << "----------------------" << std::endl;

	const Dog* dog = new Dog();
	const Dog* dogCopy = new Dog(*dog);
	std::cout << "dogCopy type: " << dogCopy->getType() << std::endl;
	dogCopy->makeSound();

	delete dog;
	delete dogCopy;
	}

	{
	std::cout << "------------------------------" << std::endl;
    std::cout << "COPY ASSIGNMENT OPERATOR TESTS" << std::endl;
    std::cout << "------------------------------" << std::endl;

	const Dog* dog = new Dog();
	Dog* dogCopy = new Dog();
	*dogCopy = *dog;
	std::cout << "dogCopy type: " << dogCopy->getType() << std::endl;
	dogCopy->makeSound();

	delete dog;
	delete dogCopy;
	}

	return 0;
}
