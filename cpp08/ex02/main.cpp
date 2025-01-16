/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:17:11 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 12:28:02 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

static void greenMessage(std::string message) {
  std::cout << "\033[32m" << message << "\033[0m\n";
}

void basicTests() {
  greenMessage("Testing MutantStack:");

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(4);
  mstack.push(44);
  mstack.push(444);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

static void testListForComparison() {
  greenMessage("\nTesting std::list for comparison:");

  std::list<int> lst;

  lst.push_back(5);
  lst.push_back(17);

  std::cout << lst.back() << std::endl; // Equivalent to mstack.top()

  lst.pop_back();

  std::cout << lst.size() << std::endl;

  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(4);
  lst.push_back(44);
  lst.push_back(444);
  lst.push_back(0);

  std::list<int>::iterator it = lst.begin();
  std::list<int>::iterator ite = lst.end();

  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::list<int> s(lst);
}

int main() {
  basicTests();
  testListForComparison();
}