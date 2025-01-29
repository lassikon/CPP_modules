/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:22 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/29 21:19:24 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iomanip> // for debugging with printPairs()
#include <iostream>
#include <ostream> // for printSequence()
#include <vector>

class PmergeMe {
public:
  struct Pair {
    std::vector<int> small;
    std::vector<int> large;
    size_t indexInMainSequence;
  };

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe();

  void fordJohnsonAlgorithm();
  void binaryInsertionSort();
  void formMainSequence();
  void makePairs();
  void sortPairs();
  void updatePairIndexes(int inserted);
  void createJacobsthalSequence();
  int getNextJacobsthal();
  std::vector<int> sortVector(const std::vector<int> &input);

  std::deque<int> sortDeque(const std::deque<int> &input);

  template <typename Container> void printSequence(const Container &sequence) {
    for (size_t i = 0; i < sequence.size(); i++) {
      std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n");
    }
  }

private:
  std::vector<int> vec;
  std::vector<Pair> pairVec;
  std::vector<int> oddElementVec;
  std::vector<int> leftoversVec;

  std::deque<int> deq;
  std::deque<Pair> pairDeq;
  std::deque<int> oddElementDeq;
  std::deque<int> leftoversDeq;

  std::vector<size_t> jacobsthalSequence;
  size_t jacobsthalIndex;
  size_t elementSize;
  bool keepRecursing;
};