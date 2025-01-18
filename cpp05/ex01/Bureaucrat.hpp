/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:43 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/18 15:14:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Bureaucrat {
private:
  const std::string name;
  int grade;

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
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &other);

  const std::string &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form);
  void validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);