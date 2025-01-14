/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:17:17 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 16:35:42 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { std::cout << "Default Intern has been created.\n"; }

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "A copy of Intern has been created.\n";
}

Intern::~Intern() { std::cout << "Intern has been destroyed.\n"; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  std::cout << "Copy assignment operator called\n";
  return *this;
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {
  const std::string validFormNames[] = {
      "shrubbery creation", "robotomy request", "presidential pardon"};
  for (int i = 0; i < 3; i++) {
    if (formName == validFormNames[i]) {
      switch (i) {
      case 0:
        return createShrubberyCreationForm(target);
      case 1:
        return createRobotomyRequestForm(target);
      case 2:
        return createPresidentialPardonForm(target);
      }
    }
  }
  std::cerr << "Error: Form '" << formName << "' does not exist.\n";
  return nullptr;
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
  std::cout << "Intern creates a ShrubberyCreationForm for " << target << ".\n";
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
  std::cout << "Intern creates a RobotomyRequestForm for " << target << ".\n";
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
  std::cout << "Intern creates a PresidentialPardonForm for " << target
            << ".\n";
  return new PresidentialPardonForm(target);
}