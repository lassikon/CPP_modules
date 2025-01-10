/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:55:53 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/10 16:09:32 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void greenMessage(std::string message) {
  std::cout << "\n\033[32m" << message << "\033[0m\n";
}

static void testConstructors() {
  greenMessage("Testing constructors");

  try {
    Form form0;
    std::cout << form0 << std::endl;

    Form form1("Form 1", 1, 1);
    std::cout << form1 << std::endl;

    Form form2("Form 2", 150, 150);
    std::cout << form2 << std::endl;

    Form form3("Form 3", 0, 0);
  } catch (std::exception &e) {
    std::cout << std::endl;
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  Form form4 = Form("Form 4", 1, 1);
  Form form5 = Form(form4);
  std::cout << std::endl;
  std::cout << form4;
  std::cout << form5;
}

static void testOperatorOverload() {
  greenMessage("Testing operator overloads");

  Form form1("Form 1", 1, 1);
  Form form2("Form 2", 150, 150);
  Form form3("Form 3", 1, 1);
  Bureaucrat b1("Bureaucrat 1", 1);
  std::cout << std::endl;

  form2.signForm(b1);

  std::cout << form1;
  std::cout << form2;
  std::cout << form3;
  std::cout << std::endl;

  form1 = form2;
  form2 = form3;
  std::cout << std::endl;

  std::cout << form1;
  std::cout << form2;
  std::cout << form3;
  std::cout << std::endl;
}

static void testSignForm() {
  greenMessage("Testing signForm");

  Bureaucrat b1("Bureaucrat 1", 1);
  Bureaucrat b2("Bureaucrat 2", 150);
  Form form1("Form 1", 1, 1);
  Form form2("Form 2", 150, 150);
  std::cout << std::endl;

  std::cout << b1;
  std::cout << b2;
  std::cout << form1;
  std::cout << form2;
  std::cout << std::endl;

  try {
    form1.signForm(b1);
    form2.signForm(b2);
    form1.signForm(b2);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;

  std::cout << form1;
  std::cout << form2;
  std::cout << std::endl;
}

int main() {
  testConstructors();
  testOperatorOverload();
  testSignForm();

  return 0;
}