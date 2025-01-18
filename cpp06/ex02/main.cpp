/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:46:40 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/18 16:00:22 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <ctime>
#include <iostream>

Base *generate() {
  static bool seeded = false; // Seed only once
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }

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

// Using dynamic_cast on a pointer returns nullptr if the cast fails
void identify(Base *p) {
  if (!p) {
    std::cout << "Pointer is null\n";
    return;
  }
  
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

// Using dynamic_cast on a reference throws a std::bad_cast if the cast fails
void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A\n";
    return;
  } catch (const std::bad_cast &) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B\n";
    return;
  } catch (const std::bad_cast &) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C\n";
    return;
  } catch (const std::bad_cast &) {
    std::cout << "Unknown type\n";
  }
}

int main() {
  Base *base = generate();

  std::cout << "Identifying pointer: ";
  identify(base);

  std::cout << "\nIdentifying reference: ";
  identify(*base);

  delete base;
  return 0;
}