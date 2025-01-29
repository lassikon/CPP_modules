/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/29 15:35:59 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test case
// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

// Take the smallest pair + the larger elements from every other pair
void PmergeMe::formMainSequence() {
  vec.clear();
  vec.insert(vec.end(), pairVec[0].small.begin(), pairVec[0].small.end());
  size_t index = 2 * elementSize - 1;
  pairVec[0].indexInMainSequence = index;
  vec.insert(vec.end(), pairVec[0].large.begin(), pairVec[0].large.end());
  pairVec.erase(pairVec.begin());
  for (size_t i = 0; i < pairVec.size(); i++) {
    vec.insert(vec.end(), pairVec[i].large.begin(), pairVec[i].large.end());
    index += elementSize;
    pairVec[i].indexInMainSequence = index;
  }
}

void PmergeMe::updatePairIndexes(int inserted) {
  for (size_t j = 0; j < pairVec.size(); ++j) {
    if (pairVec[j].large.back() > inserted) {
      pairVec[j].indexInMainSequence += elementSize;
    }
  }
}

// Returns the index in pairVec from where we start inserting
int PmergeMe::getNextJacobsthal() {
  int jacobSthal = jacobsthalSequence[jacobsthalIndex] -
                   jacobsthalSequence[jacobsthalIndex - 1];
  jacobsthalIndex++;
  if (jacobSthal >= static_cast<int>(pairVec.size())) {
    jacobSthal = pairVec.size();
  }
  return jacobSthal - 1;
}

void PmergeMe::binaryInsertionSort() {
  if (elementSize * 2 > vec.size()) {
    return;
  }

  formMainSequence();

  while (!pairVec.empty()) {
    int i = getNextJacobsthal();
    while (i >= 0) {
      int rightBoundary = pairVec[i].indexInMainSequence / elementSize;
      // Perform binary search for insertion point
      int left = 0, right = rightBoundary;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (pairVec[i].small.back() >
            vec[mid * elementSize + elementSize - 1]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      // Calculate the actual index for insertion, and insert the sequence
      int insertIndex = left * elementSize;
      vec.insert(vec.begin() + insertIndex, pairVec[i].small.begin(),
                 pairVec[i].small.end());

      // Update pair indexes and remove the inserted pair
      updatePairIndexes(pairVec[i].small.back());
      pairVec.erase(pairVec.begin() + i);
      i--;
    }
  }

  // Insert the odd element if one exists
  if (!oddElement.empty()) {
    int rightBoundary = (vec.size() - 1) / elementSize;
    int left = 0, right = rightBoundary;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (oddElement.back() > vec[mid * elementSize + elementSize - 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    int insertIndex = left * elementSize;
    vec.insert(vec.begin() + insertIndex, oddElement.begin(), oddElement.end());
  }

  // Add the leftover numbers to the end of the vector
  for (size_t i = 0; i < leftovers.size(); i++) {
    vec.push_back(leftovers[i]);
  }
}

void PmergeMe::makePairs() {
  pairVec.clear();
  oddElement.clear();
  leftovers.clear();
  size_t i;
  for (i = 0; i + elementSize * 2 <= vec.size(); i += elementSize * 2) {
    Pair pair;
    pair.small.insert(pair.small.end(), vec.begin() + i,
                      vec.begin() + i + elementSize);
    pair.large.insert(pair.large.end(), vec.begin() + i + elementSize,
                      vec.begin() + i + elementSize * 2);
    pairVec.push_back(pair);
  }
  if (i <= vec.size() - elementSize) {
    oddElement.insert(oddElement.end(), vec.begin() + i,
                      vec.begin() + i + elementSize);
    i += elementSize;
  }
  if (i < vec.size()) {
    leftovers.insert(leftovers.end(), vec.begin() + i, vec.end());
  }
}

void PmergeMe::sortPairs() {
  for (size_t i = 0; i < pairVec.size(); i++) {
    if (!pairVec[i].small.empty() && !pairVec[i].large.empty() &&
        pairVec[i].small.back() > pairVec[i].large.back()) {
      std::swap(pairVec[i].small, pairVec[i].large);
      // Sort the pair in the vector
      std::swap_ranges(vec.begin() + i * elementSize * 2,
                       vec.begin() + i * elementSize * 2 + (elementSize),
                       vec.begin() + i * elementSize * 2 + (elementSize));
    }
  }
}

void PmergeMe::fordJohnsonAlgorithm() {
  if (keepRecursing && elementSize * 2 <= vec.size()) {
    makePairs();
    sortPairs();
    elementSize *= 2;
    recursionLevel++;
    fordJohnsonAlgorithm(); // Recurse
  }
  keepRecursing = false;
  makePairs();
  binaryInsertionSort();
  elementSize /= 2;
  recursionLevel--;
  jacobsthalIndex = 3;
  if (jacobsthalIndex >= jacobsthalSequence.size()) {
    throw std::out_of_range("Jacobsthal index out of range");
  }
}

void PmergeMe::createJacobsthalSequence() {
  size_t sequenceSize = 20;
  jacobsthalSequence.push_back(0);
  jacobsthalSequence.push_back(1);
  for (size_t i = 2; i < sequenceSize; i++) {
    jacobsthalSequence.push_back(jacobsthalSequence[i - 1] +
                                 2 * jacobsthalSequence[i - 2]);
  }
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
  vec = input;
  recursionLevel = 1;
  elementSize = 1;
  keepRecursing = true;
  jacobsthalIndex = 2;
  createJacobsthalSequence();
  fordJohnsonAlgorithm();
  return vec;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
  std::deque<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}