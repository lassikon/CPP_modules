/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:38:16 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 12:01:19 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

static void redMessage(std::string message) {
  std::cout << "\033[31m" << message << "\033[0m";
}

void basicTests() {
  greenMessage("Basic Tests:");

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl; // 2
  std::cout << sp.longestSpan() << std::endl;  // 14
}

void exceptionTests() {
  greenMessage("Exception Tests:");

  Span sp(2);

  try {
    sp.shortestSpan();
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl; // Not enough elements
  }

  sp.addNumber(5);

  try {
    sp.shortestSpan();
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl; // Not enough elements
  }

  sp.addNumber(10);

  try {
    sp.addNumber(20);
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl; // Span is already full
  }
}

void largeDataSetTest() {
  Span sp(10000);
  std::srand(std::time(0));

  // Generate 10,000 random numbers
  for (int i = 0; i < 10000; ++i) {
    sp.addNumber(std::rand() % 1000000);
  }

  greenMessage("Large Data Set Test:");
  try {
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl;
  }
}

void rangeInsertionTest() {
  Span sp(10);
  std::vector<int> numbers = {1, 3, 5, 7, 9};

  greenMessage("Range Insertion Test:");

  try {
    sp.addNumbers(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << sp.shortestSpan()
              << std::endl; // Should print 2
    std::cout << "Longest span: " << sp.longestSpan()
              << std::endl; // Should print 8
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl;
  }

  // Try to add more numbers than the capacity allows
  try {
    std::vector<int> moreNumbers = {11, 13, 15, 17, 19, 21};
    sp.addNumbers(moreNumbers.begin(), moreNumbers.end());
  } catch (const std::exception &e) {
    redMessage("Exception: ");
    std::cout << e.what() << std::endl; // Span is already full
  }
}

int main() {
  basicTests();
  exceptionTests();
  largeDataSetTest();
  rangeInsertionTest();

  return 0;
}