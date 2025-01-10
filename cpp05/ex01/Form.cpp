/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:51 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 15:58:51 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const noexcept {
  return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept {
  return "Grade is too low!";
}

Form::Form()
    : name("Default"), isSigned(false), signGrade(150), execGrade(150) {
  std::cout << "Default Form has been created.\n";
}

Form::Form(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
  validateGrade(signGrade);
  validateGrade(execGrade);
  std::cout << "Form " << name << " has been created.\n";
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade),
      execGrade(other.execGrade) {
  std::cout << "A copy of Form " << name << " has been created.\n";
}

Form::~Form() { std::cout << "Form " << name << " has been destroyed.\n"; }

Form &Form::operator=(const Form &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > signGrade) {
    throw GradeTooLowException();
  }
  isSigned = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
  try {
    beSigned(bureaucrat);
    std::cout << bureaucrat.getName() << " signed " << name << std::endl;
  } catch (std::exception &e) {
    std::cout << bureaucrat.getName() << " couldn't sign " << name
              << " because " << e.what() << "\n";
  }
}

const std::string &Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getSignGrade() const { return signGrade; }

int Form::getExecGrade() const { return execGrade; }

void Form::validateGrade(int grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName() << " is ";
  if (form.getIsSigned()) {
    os << "signed";
  } else {
    os << "not signed";
  }
  os << " and requires grade " << form.getSignGrade() << " to sign and grade "
     << form.getExecGrade() << " to execute.\n";
  return os;
}