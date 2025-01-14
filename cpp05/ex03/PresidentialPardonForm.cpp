/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:14 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 14:11:37 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5, "Default") {
  std::cout << "Default PresidentialPardonForm has been created.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5, target) {
  std::cout << "PresidentialPardonForm for " << target
            << " has been created.\n";
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other) {
  std::cout << "A copy of PresidentialPardonForm for " << other.getTarget()
            << " has been created.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm for " << getTarget()
            << " has been destroyed.\n";
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

void PresidentialPardonForm::executeAction() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}