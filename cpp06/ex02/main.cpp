/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:46:40 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 13:12:31 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <ctime>
#include <iostream>

Base *generate() {
  std::srand(std::time(0));
  int random = std::rand() % 3;

  switch (random) {
  case 0:
    std::cout << "Generated A\n";
    return new A();
  case 1:
    std::cout << "Generated B\n";
    return new B();
  case 2:
    std::cout << "Generated C\n";
    return new C();
  default:
    return nullptr;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A\n";
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B\n";
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C\n";
  } else {
    std::cout << "Unknown type\n";
  }
}

void idenfity(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A\n";
  } catch (std::bad_cast &e) {
    try {
      (void)dynamic_cast<B &>(p);
      std::cout << "B\n";
    } catch (std::bad_cast &e) {
      try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
      } catch (std::bad_cast &e) {
        std::cout << "Unknown type\n";
      }
    }
  }
}

int main() {
  Base *base = generate();

  std::cout << "Identifying pointer: ";
  identify(base);

  std::cout << "\nIdentifying reference: ";
  idenfity(*base);

  delete base;
  return 0;
}