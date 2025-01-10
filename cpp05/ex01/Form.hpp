/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:40:48 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 12:54:26 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

class BureauCrat;

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

  void beSigned(const BureauCrat &bureaucrat);

  void signForm(const BureauCrat &bureaucrat);

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecGrade() const;

  void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Form &form);