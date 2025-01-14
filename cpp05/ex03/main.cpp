/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:53 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 16:42:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

void testIntern() {
  Intern intern;
  AForm *form;

  greenMessage("Testing valid forms");

  form = intern.makeForm("shrubbery creation", "Home");
  if (form) {
    std::cout << *form << std::endl;
    delete form;
  }
  std::cout << std::endl;

  form = intern.makeForm("robotomy request", "Bender");
  if (form) {
    std::cout << *form << std::endl;
    delete form;
  }
  std::cout << std::endl;

  form = intern.makeForm("presidential pardon", "Zaphod");
  if (form) {
    std::cout << *form << std::endl;
    delete form;
  }
  std::cout << std::endl;

  greenMessage("Testing invalid form");

  form = intern.makeForm("invalid form", "Target");
  if (!form) {
    std::cout << "Failed to create form." << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  testIntern();
  return 0;
}