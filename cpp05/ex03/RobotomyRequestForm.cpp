/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:04:31 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 14:08:35 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45, "Default") {
  std::cout << "Default RobotomyRequestForm has been created.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request Form", 72, 45, target) {
  std::cout << "RobotomyRequestForm for " << target << " has been created.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {
  std::cout << "A copy of RobotomyRequestForm for " << other.getTarget()
            << " has been created.\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm for " << getTarget()
            << " has been destroyed.\n";
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

void RobotomyRequestForm::executeAction() const {
  std::cout << "*drilling noises*\n";
  if (rand() % 2) {
    std::cout << getTarget() << " has been robotomized successfully.\n";
  } else {
    std::cout << "Robotomization of " << getTarget() << " has failed.\n";
  }
}