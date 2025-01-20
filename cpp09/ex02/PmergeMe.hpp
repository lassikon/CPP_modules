/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:22 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/20 22:26:11 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

struct Pair {
  std::vector<int> small;
  std::vector<int> large;
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
  void makePairs();
  void sortPairs();
  std::vector<int> sortVector(const std::vector<int> &input);

  std::deque<int> sortDeque(const std::deque<int> &input);

  template <typename Container> void printSequence(const Container &sequence) {
    for (size_t i = 0; i < sequence.size(); i++) {
      std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n");
    }
  }

private:
  std::vector<int> mainVec;
  std::vector<int> pendVec;
  std::vector<int> vec;
  std::vector<Pair> pairVec;

  size_t recursionLevel;
  size_t pairSize;
  bool keepRecursing;
};