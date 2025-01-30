/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:21:59 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/30 16:01:49 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <iostream>
#include <stdexcept>

template <typename Container> void printSequence(const Container &cont) {
  for (typename Container::const_iterator it = cont.begin(); it != cont.end();
       ++it) {
    if (it != cont.begin())
      std::cout << " ";
    std::cout << *it;
  }
  std::cout << std::endl;
}

static int validateInput(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    try {
      int num = std::stoi(argv[i]);
      if (num < 0) {
        std::cerr << "Error: Negative input '" << argv[i] << "'" << std::endl;
        return 1;
      }
    } catch (std::invalid_argument &e) {
      std::cerr << "Error: Invalid input '" << argv[i] << "'" << std::endl;
      return 1;
    } catch (std::out_of_range &e) {
      std::cerr << "Error: Out of range input '" << argv[i] << "'" << std::endl;
      return 1;
    }
  }
  return 0;
}

static int sortWithVector(int argc, char **argv) {
  PmergeMe<std::vector<int>> pm;
  std::vector<int> vec;
  std::vector<int> sorted;

  try {
    for (int i = 1; i < argc; ++i)
      vec.push_back(std::stoi(argv[i]));
    auto start = std::chrono::high_resolution_clock::now();
    sorted = pm.sort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Before: ";
    printSequence(vec);
    std::cout << "After: ";
    printSequence(sorted);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << elapsed.count() << " us\n";
  } catch (std::exception &e) {
    std::cerr << "Error (vector): " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

static int sortWithDeque(int argc, char **argv) {
  PmergeMe<std::deque<int>> pm;
  std::deque<int> deq;
  std::deque<int> sorted;

  try {
    for (int i = 1; i < argc; ++i)
      deq.push_back(std::stoi(argv[i]));
    auto start = std::chrono::high_resolution_clock::now();
    sorted = pm.sort(deq);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque: " << elapsed.count() << " us\n";
  } catch (std::exception &e) {
    std::cerr << "Error (deque): " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [integers...]\n";
    return 1;
  }
  if (validateInput(argc, argv) != 0)
    return 1;
  if (sortWithVector(argc, argv) || sortWithDeque(argc, argv))
    return 1;
  return 0;
}