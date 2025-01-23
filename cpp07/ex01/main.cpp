/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:07:33 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/23 13:39:54 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include <string>

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

void printInt(int &value) { std::cout << value << " "; }

void incrementInt(int &value) { value++; }

void printString(std::string &value) { std::cout << value << " "; }

struct Person {
  std::string name;
  int age;

  Person(std::string n, int a) : name(n), age(a) {}
};

void printPerson(Person &p) {
  std::cout << "{ Name: " << p.name << ", Age: " << p.age << " } ";
}

void incrementAge(Person &p) {
  p.age++;
}

int main() {
  greenMessage("Testing with integers");
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
  std::cout << "Original int array: ";
  iter(intArray, intLength, printInt);
  std::cout << "\nIncrementing int array: ";
  iter(intArray, intLength, incrementInt);
  iter(intArray, intLength, printInt);
  std::cout << std::endl;

  greenMessage("Testing with strings");
  std::string strArray[] = {"Bob", "Cat", "Dog", "Templates"};
  size_t strLength = sizeof(strArray) / sizeof(strArray[0]);
  std::cout << "String array: ";
  iter(strArray, strLength, printString);
  std::cout << std::endl;

  greenMessage("Testing with structs");
  Person people[] = {
      {"Alice", 25},
      {"Bob", 30},
      {"Charlie", 35},
      {"Dana", 40},
  };
  size_t peopleLength = sizeof(people) / sizeof(people[0]);
  std::cout << "Original people array: ";
  iter(people, peopleLength, printPerson);
  std::cout << "\nIncrementing ages: ";
  iter(people, peopleLength, incrementAge);
  iter(people, peopleLength, printPerson);
  std::cout << std::endl;

  return 0;
}