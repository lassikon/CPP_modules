/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:51 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 16:13:18 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const noexcept {
  return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept {
  return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const noexcept {
  return "Form is not signed!";
}

AForm::AForm()
    : name("Default"), isSigned(false), signGrade(150), execGrade(150),
      target("Default") {
  std::cout << "Default AForm has been created.\n";
}

AForm::AForm(const std::string &name, int signGrade, int execGrade,
             const std::string &target)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade),
      target(target) {
  validateGrade(signGrade);
  validateGrade(execGrade);
  std::cout << "AForm " << name << " has been created.\n";
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade),
      execGrade(other.execGrade), target(other.target) {
  std::cout << "A copy of AForm " << name << " has been created.\n";
}

AForm::~AForm() { std::cout << "AForm " << name << " has been destroyed.\n"; }

AForm &AForm::operator=(const AForm &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecGrade() const { return execGrade; }

const std::string &AForm::getTarget() const { return target; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > signGrade) {
    throw AForm::GradeTooLowException();
  }
  isSigned = true;
  std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

void AForm::validateGrade(int grade) {
  if (grade < 1) {
    throw AForm::GradeTooHighException();
  } else if (grade > 150) {
    throw AForm::GradeTooLowException();
  }
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!isSigned) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > execGrade) {
    throw AForm::GradeTooLowException();
  }
  executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form Name: " << form.getName() << "\n"
     << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
     << "Grade Required to Sign: " << form.getSignGrade() << "\n"
     << "Grade Required to Execute: " << form.getExecGrade();
  return os;
}