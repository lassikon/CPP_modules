/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:15 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 14:01:18 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137, "Default") {
  std::cout << "Default ShrubberyCreationForm has been created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation Form", 145, 137, target) {
  std::cout << "ShrubberyCreationForm for " << target << " has been created.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  std::cout << "A copy of ShrubberyCreationForm for " << other.getTarget()
            << " has been created.\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm for " << getTarget()
            << " has been destroyed.\n";
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

void ShrubberyCreationForm::executeAction() const {
  std::ofstream file((getTarget() + "_shrubbery").c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: Unable to create file " + getTarget() +
                             "_shrubbery");
    return;
  }

  file << "      /\\ \n"
          "     /  \\ \n"
          "    /    \\ \n"
          "   /      \\ \n"
          "  /        \\ \n"
          " /          \\ \n"
          "/____________\\ \n"
          "      ||\n"
          "      ||\n";
  file.close();
  std::cout << "Shrubbery has been created in " << getTarget()
            << "_shrubbery\n";
}