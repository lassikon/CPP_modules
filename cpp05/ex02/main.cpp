/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:53 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/18 15:33:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

static void blueMessage(std::string message) {
  std::cout << "\n\033[34m" << message << "\033[0m\n";
}

static void redMessage(std::string message) {
  std::cout << "\n\033[31m" << message << "\033[0m\n";
}

static void testConstructors() {
  greenMessage("Testing Bureaucrat Constructors");

  // Default constructor
  Bureaucrat defaultBureaucrat;
  std::cout << "Default Bureaucrat: " << defaultBureaucrat << std::endl;

  // Parameterized constructor
  Bureaucrat paramBureaucrat("Alice", 42);
  std::cout << "Parameterized Bureaucrat: " << paramBureaucrat << std::endl;

  // Copy constructor
  Bureaucrat copiedBureaucrat(paramBureaucrat);
  std::cout << "Copied Bureaucrat: " << copiedBureaucrat << std::endl;

  // Assignment operator
  Bureaucrat assignedBureaucrat;
  assignedBureaucrat = paramBureaucrat;
  std::cout << "Assigned Bureaucrat: " << assignedBureaucrat << std::endl;

  redMessage("Testing ShrubberyCreationForm Constructors");

  // Parameterized constructor
  ShrubberyCreationForm form1("Garden");
  std::cout << "Parameterized ShrubberyCreationForm: " << form1 << std::endl;

  // Copy constructor
  ShrubberyCreationForm form2(form1);
  std::cout << "Copied ShrubberyCreationForm: " << form2 << std::endl;

  // Assignment operator
  ShrubberyCreationForm form3("Park");
  form3 = form1;
  std::cout << "Assigned ShrubberyCreationForm: " << form3 << std::endl;

  blueMessage("Testing RobotomyRequestForm Constructors");

  // Parameterized constructor
  RobotomyRequestForm form4("Steve");
  std::cout << "Parameterized RobotomyRequestForm: " << form4 << std::endl;

  // Copy constructor
  RobotomyRequestForm form5(form4);
  std::cout << "Copied RobotomyRequestForm: " << form5 << std::endl;

  // Assignment operator
  RobotomyRequestForm form6("Target");
  form6 = form4;
  std::cout << "Assigned RobotomyRequestForm: " << form6 << std::endl;

  blueMessage("Testing PresidentialPardonForm Constructors");

  // Parameterized constructor
  PresidentialPardonForm form7("Bob");
  std::cout << "Parameterized PresidentialPardonForm: " << form7 << std::endl;

  // Copy constructor
  PresidentialPardonForm form8(form7);
  std::cout << "Copied PresidentialPardonForm: " << form8 << std::endl;

  // Assignment operator
  PresidentialPardonForm form9("Dave");
  form9 = form7;
  std::cout << "Assigned PresidentialPardonForm: " << form9 << std::endl;
}

static void testShrubberyCreationForm() {
  greenMessage("Creating Good Bureaucrat with grade 1");
  Bureaucrat goodBureaucrat("Good Bureaucrat", 1);
  greenMessage("Creating a Bad Bureaucrat with grade 150");
  Bureaucrat badBureaucrat("Bad Bureaucrat", 150);
  greenMessage("Creating a ShrubberyCreationForm with target 'home'");
  ShrubberyCreationForm form("home");
  greenMessage("Trying to sign the form with Bad Bureaucrat");
  try {
    badBureaucrat.signForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  greenMessage("Signing the form with Good Bureaucrat");
  goodBureaucrat.signForm(form);
  greenMessage("Trying to execute the form with Bad Bureaucrat");
  try {
    badBureaucrat.executeForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  greenMessage("Executing the form with Good Bureaucrat");
  goodBureaucrat.executeForm(form);
}

static void testRobotomyRequestForm() {
  redMessage("Creating Good Bureaucrat with grade 1");
  Bureaucrat goodBureaucrat("Good Bureaucrat", 1);
  redMessage("Creating a Bad Bureaucrat with grade 150");
  Bureaucrat badBureaucrat("Bad Bureaucrat", 150);
  redMessage("Creating a RobotomyRequestForm with target 'Steve'");
  RobotomyRequestForm form("Steve");
  redMessage("Trying to sign the form with Bad Bureaucrat");
  try {
    badBureaucrat.signForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  redMessage("Signing the form with Good Bureaucrat");
  goodBureaucrat.signForm(form);
  redMessage("Trying to execute the form with Bad Bureaucrat");
  try {
    badBureaucrat.executeForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  redMessage("Executing the form with Good Bureaucrat");
  goodBureaucrat.executeForm(form);
}

static void testPresidentialPardonForm() {
  blueMessage("Creating Good Bureaucrat with grade 1");
  Bureaucrat goodBureaucrat("Good Bureaucrat", 1);
  blueMessage("Creating a Bad Bureaucrat with grade 150");
  Bureaucrat badBureaucrat("Bad Bureaucrat", 150);
  blueMessage("Creating a PresidentialPardonForm with target 'Bob'");
  PresidentialPardonForm form("Bob");
  blueMessage("Trying to sign the form with Bad Bureaucrat");
  try {
    badBureaucrat.signForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  blueMessage("Signing the form with Good Bureaucrat");
  goodBureaucrat.signForm(form);
  blueMessage("Trying to execute the form with Bad Bureaucrat");
  try {
    badBureaucrat.executeForm(form);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  blueMessage("Executing the form with Good Bureaucrat");
  goodBureaucrat.executeForm(form);
}

int main() {
  testConstructors();
  testShrubberyCreationForm();
  testRobotomyRequestForm();
  testPresidentialPardonForm();
  return 0;
}