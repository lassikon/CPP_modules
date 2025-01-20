/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:21:59 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/20 12:58:34 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <iostream>
#include <stdexcept>

static int validateInput(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    try {
      std::stoi(argv[i]);
    } catch (std::invalid_argument &e) {
      std::cerr << "Invalid input: " << e.what() << std::endl;
      return 1;
    }
  }
}

static int sortWithVector(int argc, char **argv) {
  PmergeMe pm;
  std::vector<int> vec;
  std::vector<int> sorted;
  try {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < argc; i++) {
      vec.push_back(std::stoi(argv[i]));
    }
    sorted = pm.sortVector(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Before: ";
    pm.printSequence(vec);
    std::cout << "After: ";
    pm.printSequence(sorted);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << elapsed.count() << "s"
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

static int sortWithDeque(int argc, char **argv) {
  PmergeMe pm;
  std::deque<int> deq;
  std::deque<int> sorted;
  try {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i < argc; i++) {
      deq.push_back(std::stoi(argv[i]));
    }
    sorted = pm.sortDeque(deq);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque: " << elapsed.count() << "s"
              << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: ./PMergeMe [integers...]" << std::endl;
    return 1;
  }
  if (!validateInput(argc, argv)) {
    return 1;
  }
  if (!sortWithVector(argc, argv) || !sortWithDeque(argc, argv)) {
    return 1;
  }
  return 0;
}