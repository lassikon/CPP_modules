/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:22 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/23 11:04:15 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iomanip> // for debugging with printPairs()
#include <iostream>
#include <ostream> // for printSequence()
#include <vector>

struct Pair {
  std::vector<int> small;
  std::vector<int> large;
  size_t index;
};

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe();

  void printPairs(); // debugging

  void fordJohnsonAlgorithm();
  void binaryInsertionSort();
  void formMainAndPendElements();
  void insertPendIntoMain();
  void makePairs();
  void sortPairs();
  void updatePairIndexes(int i);
  void createJacobsthalSequence();
  std::vector<int> sortVector(const std::vector<int> &input);

  std::deque<int> sortDeque(const std::deque<int> &input);

  // template <typename Container> void printSequence(const Container &sequence)
  // {
  //   for (size_t i = 0; i < sequence.size(); i++) {
  //     std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n");
  //   }
  // }

  template <typename Container>
  void printSequence(const Container &sequence, std::ostream &os = std::cout) {
    for (size_t i = 0; i < sequence.size(); i++) {
      os << sequence[i] << (i < sequence.size() - 1 ? " " : "");
    }
    if (&os == &std::cout) { // Only print a newline if outputting to std::cout
      os << "\n";
    }
  }

private:
  std::vector<int> mainVec;
  std::vector<int> pendVec;
  std::vector<int> vec;
  std::vector<Pair> pairVec;
  std::vector<int> oddElement;
  std::vector<int> leftovers;

  std::vector<size_t> jacobsthalSequence;
	size_t jacobStahlIndex;
  size_t recursionLevel;
  size_t pairSize;
  bool keepRecursing;
};