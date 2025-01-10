/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:48 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 15:01:04 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool isSigned;
  const int signGrade;
  const int execGrade;

  // Nested exception classes
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

public:
  Form();
  Form(const std::string &name, int signGrade, int execGrade);
  Form(const Form &other);
  ~Form();

  Form &operator=(const Form &other);

  void beSigned(const Bureaucrat &bureaucrat);

  void signForm(const Bureaucrat &bureaucrat);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Form &form);