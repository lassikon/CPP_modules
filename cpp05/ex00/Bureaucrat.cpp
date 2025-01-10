/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:51 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 12:07:45 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "Grade is too low!";
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
  std::cout << "Default Bureaucrat has been created.\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name(name), grade(grade) {
  validateGrade(grade);
  std::cout << "Bureaucrat " << name << " has been created.\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "A copy of Bureaucrat " << name << " has been created.\n";
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << name << " has been destroyed.\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    grade = other.grade;
  }
  return *this;
}

const std::string &Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
  validateGrade(grade - 1);
  grade--;
}

void Bureaucrat::decrementGrade() {
  validateGrade(grade + 1);
  grade++;
}

void Bureaucrat::validateGrade(int grade) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".\n";
  return os;
}