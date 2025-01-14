/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:16:48 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 16:29:12 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
  // Nested exception class
  class FormNotFoundException : public std::exception {
  public:
    const char *what() const noexcept override;
  };

public:
  Intern();
  Intern(const Intern &other);
  ~Intern();

  Intern &operator=(const Intern &other);

  AForm *makeForm(const std::string &formName, const std::string &target);

private:
  AForm *createShrubberyCreationForm(const std::string &target);
  AForm *createRobotomyRequestForm(const std::string &target);
  AForm *createPresidentialPardonForm(const std::string &target);
};