/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:53 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 12:26:25 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

static void testConstructors() {
  greenMessage("Testing constructors");
  Bureaucrat b0;
  Bureaucrat b1("Bureaucrat 1", 1);
  Bureaucrat b2("Bureaucrat 2", 150);

  std::cout << b1;
  std::cout << b2;

  try {
    Bureaucrat b3("Bureaucrat 3", 0);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat b4("Bureaucrat 4", 151);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat b5("Bureaucrat 5", -99999);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat b6("Bureaucrat 6", 934989348);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
}

static void testOperators() {
  greenMessage("Testing operators");
  Bureaucrat b1("Bureaucrat 1", 1);
  Bureaucrat b2("Bureaucrat 2", 150);
  Bureaucrat b3("Bureaucrat 3", 1);

  std::cout << b1;
  std::cout << b2;
  std::cout << b3 << std::endl;

  b1 = b2;
  std::cout << b1 << std::endl;

  b1 = b3;
  std::cout << b1 << std::endl;
}

static void testIncrementDecrement() {
  greenMessage("Testing increment and decrement");
  Bureaucrat b1("Bureaucrat 1", 1);
  Bureaucrat b2("Bureaucrat 2", 150);

  std::cout << b1;
  std::cout << b2 << std::endl;

  try {
    b1.incrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    b2.decrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    b1.decrementGrade();
    b2.incrementGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << b1;
  std::cout << b2 << std::endl;
}

int main() {
  testConstructors();
  testOperators();
  testIncrementDecrement();

  return 0;
}