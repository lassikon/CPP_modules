/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:48 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 13:45:20 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool isSigned;
  const int signGrade;
  const int execGrade;
  const std::string target;

  // Nested exception classes
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class FormNotSignedException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

public:
  AForm();
  AForm(const std::string &name, int signGrade, int execGrade,
        const std::string &target);
  AForm(const AForm &other);
  virtual ~AForm();

  AForm &operator=(const AForm &other);

  // Getters
  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;
  const std::string &getTarget() const;

  void beSigned(const Bureaucrat &bureaucrat);
  void validateGrade(int grade);
  void execute(const Bureaucrat &executor) const;
  virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);