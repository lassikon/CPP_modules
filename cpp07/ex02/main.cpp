/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:38:48 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/23 13:03:26 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

int testsFromSubject() {
  Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main() {
  if (testsFromSubject()) {
    return 1;
  }
  try {
    greenMessage("Test 1: Default constructor");
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    greenMessage("Test 2: Constructor with size");
    Array<int> intArray(5);
    std::cout << "Array size (initialized with 5): " << intArray.size()
              << std::endl;

    greenMessage("Verify default initialization");
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    greenMessage("Modify elements using subscript operator");
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      intArray[i] = i * 10;
    }
    for (unsigned int i = 0; i < intArray.size(); ++i) {
      std::cout << "Modified intArray[" << i << "] = " << intArray[i]
                << std::endl;
    }

    greenMessage("Test 3: Out-of-bounds access");
    try {
      std::cout << intArray[5] << std::endl; // This should throw an exception
    } catch (const std::out_of_range &e) {
      std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    greenMessage("Test 4: Copy constructor");
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;

    for (unsigned int i = 0; i < copiedArray.size(); ++i) {
      std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
    }

    greenMessage(
        "Modify copiedArray and verify original array remains unchanged");
    copiedArray[0] = 1000;
    std::cout << "Modified copiedArray[0] = " << copiedArray[0] << std::endl;
    std::cout << "Original intArray[0] = " << intArray[0] << std::endl;

    greenMessage("Test 5: Assignment operator");
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;

    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
      std::cout << "assignedArray[" << i << "] = " << assignedArray[i]
                << std::endl;
    }

    greenMessage(
        "Modify assignedArray and verify original array remains unchanged");
    assignedArray[1] = 5000;
    std::cout << "Modified assignedArray[1] = " << assignedArray[1]
              << std::endl;
    std::cout << "Original intArray[1] = " << intArray[1] << std::endl;

    greenMessage("Test 6: Array of different types");
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "Array";
    stringArray[2] = "Template";

    std::cout << "String array contents:" << std::endl;
    for (unsigned int i = 0; i < stringArray.size(); ++i) {
      std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    greenMessage("Test 7: Empty array assignment");
    Array<double> emptyAssignArray;
    Array<double> doubleArray(2);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;

    emptyAssignArray = doubleArray;
    std::cout << "Empty array assigned from doubleArray:" << std::endl;
    for (unsigned int i = 0; i < emptyAssignArray.size(); ++i) {
      std::cout << "emptyAssignArray[" << i << "] = " << emptyAssignArray[i]
                << std::endl;
    }

  } catch (const std::exception &e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
  }

  return 0;
}
