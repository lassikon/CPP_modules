/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/20 23:08:20 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::binaryInsertionSort() {
  if (pairSize * 2 > vec.size()) {
    return;
  }
  std::vector<int> leftovers;
  size_t i = 0;
  while (i < vec.size()) {
    i++;
  }
  while (i < vec.size()) {
    leftovers.push_back(vec[i]);
    i++;
  }
  mainVec.clear();
  pendVec.clear();

  mainVec.insert(mainVec.begin(), pairVec[0].small.begin(),
                 pairVec[0].small.end());
  mainVec.insert(mainVec.end(), pairVec[0].large.begin(),
                 pairVec[0].large.end());
  for (size_t i = 1; i < pairVec.size(); i++) {
    mainVec.insert(mainVec.end(), pairVec[i].large.begin(),
                   pairVec[i].large.end());
    pendVec.insert(pendVec.begin(), pairVec[i].small.begin(),
                   pairVec[i].small.end());
  }
  std::cout << "MainVec: ";
  printSequence(mainVec);
  pendVec.insert(pendVec.end(), leftovers.begin(), leftovers.end());
  std::cout << "PendVec: ";
  printSequence(pendVec);
  // binary insertion sort the pendVec into the mainVec
  for (size_t i = 0; i < pendVec.size(); i++) {
    size_t left = 0;
    size_t right = mainVec.size();
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (pendVec[i] < mainVec[mid]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    mainVec.insert(mainVec.begin() + left, pendVec[i]);
  }
  vec = mainVec;
}

void PmergeMe::makePairs() {
  std::cout << "Making pairs at recursion level: " << recursionLevel
            << std::endl;
  pairVec.clear();
  for (size_t i = 0; i + (pairSize / 2) < vec.size(); i += pairSize) {
    Pair pair;
    pair.large.clear();
    pair.small.clear();
    for (size_t j = i; j < vec.size() && j < i + pairSize; ++j) {
      if (j - i < pairSize / 2) {
        pair.small.push_back(vec[j]);
      } else {
        pair.large.push_back(vec[j]);
      }
    }
    pairVec.push_back(pair);
  }
}

void PmergeMe::sortPairs() {
  for (size_t i = 0; i < pairVec.size(); i++) {
    if (!pairVec[i].small.empty() && !pairVec[i].large.empty() &&
        pairVec[i].small.back() > pairVec[i].large.back()) {
      std::swap(pairVec[i].small, pairVec[i].large);
      // Sort the pair in the vector
      std::swap_ranges(vec.begin() + i, vec.begin() + i + (pairSize / 2),
                       vec.begin() + i + (pairSize / 2));
    }
  }
}

void PmergeMe::printPairs() {
  // for debugging
  std::cout << "Pair size: " << pairSize << std::endl;
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << "Pair " << i << " small: ";
    printSequence(pairVec[i].small);
    std::cout << "Pair " << i << " large: ";
    printSequence(pairVec[i].large);
  }
  std::cout << "\nVector: ";
  printSequence(vec);
}

void PmergeMe::fordJohnsonAlgorithm() {
  if (keepRecursing && pairSize * 2 <= vec.size()) {
    makePairs();
    sortPairs();
    printPairs(); // debugging
    pairSize *= 2;
    recursionLevel++;
    fordJohnsonAlgorithm(); // Recurse
  }
  keepRecursing = false;
  makePairs();
  sortPairs();
  printPairs(); // debugging
  binaryInsertionSort();
  pairSize /= 2;
  recursionLevel--;
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
  vec = input;
  recursionLevel = 1;
  pairSize = 2;
  keepRecursing = true;
  fordJohnsonAlgorithm();
  return vec;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
  std::deque<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}