/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/23 11:25:06 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test case
// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::formMainAndPendElements() {
  vec.clear();
  vec.insert(vec.end(), pairVec[0].small.begin(), pairVec[0].small.end());
  vec.insert(vec.end(), pairVec[0].large.begin(), pairVec[0].large.end());
  for (size_t i = 1; i < pairVec.size(); i++) {
    vec.insert(vec.end(), pairVec[i].large.begin(), pairVec[i].large.end());
  }
  std::cout << "Main elements: ";
  printSequence(vec);
  std::cout << "Main size: " << vec.size() << std::endl;
}
void PmergeMe::updatePairIndexes(int inserted) {
  for (size_t j = 0; j < vec.size(); j += pairSize / 2) {
    if (vec[j] == inserted) {
      while (j < vec.size() - pairSize / 2) {
        j += pairSize / 2;
        for (size_t i = 0; i < pairVec.size(); ++i) {
          if (pairVec[i].small.back() == vec[j]) {
            pairVec[i].index++;
          }
        }
      }
      return;
    }
  }
}

void PmergeMe::binaryInsertionSort() {
  if (pairSize * 2 > vec.size()) {
    return;
  }
  formMainAndPendElements();
  size_t jacobStahl = jacobsthalSequence[jacobStahlIndex] -
                      jacobsthalSequence[jacobStahlIndex - 1];
  size_t i = jacobStahl - 1;
  if (i >= pairVec.size()) {
    i = pairVec.size() - 1;
  }
  std::cout << "i: " << i << std::endl;
  
  // this loop is inserting in the wrong place !!!
  // we need to update the pair indexes after an insertion is made
  while (i > 0) {
    size_t left = 0;
    size_t right = i;
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (pairVec[i].small.back() < vec[mid * pairSize / 2]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    std::cout << "Inserting: ";
    printSequence(pairVec[i].small);
    std::cout << "Index: " << pairVec[i].index << std::endl;
    vec.insert(vec.begin() + (left * pairSize / 2), pairVec[i].small.begin(),
               pairVec[i].small.end());
    updatePairIndexes(pairVec[i].small.back());
    i--;
  }

  std::cout << "Vec before oddElement insertion: ";
  printSequence(vec);
  if (!oddElement.empty()) {
    size_t left = 0;
    size_t right = vec.size();
    std::cout << "right: " << right << std::endl;
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (oddElement.back() < vec[mid]) {
        std::cout << oddElement.back() << " < " << vec[mid] << std::endl;
        std::cout << "Right: " << right << " Left: " << left << std::endl;
        right = mid;
      } else {
        std::cout << "mid: " << mid << std::endl;
        std::cout << "left = mid + 1" << std::endl;
        left = mid + 1;
      }
    }
    // debugging
    std::cout << "Inserting odd element after " << vec[left] << std::endl;
    
    vec.insert(vec.begin() + left, oddElement.begin(),
               oddElement.end());
  }
  for (size_t i = 0; i < leftovers.size(); i++) {
    vec.push_back(leftovers[i]);
  }
}

void PmergeMe::makePairs() {
  pairVec.clear();
  oddElement.clear();
  leftovers.clear();
  size_t i;
  for (i = 0; i + pairSize <= vec.size(); i += pairSize) {
    Pair pair;
    pair.small.insert(pair.small.end(), vec.begin() + i,
                      vec.begin() + i + pairSize / 2);
    pair.large.insert(pair.large.end(), vec.begin() + i + pairSize / 2,
                      vec.begin() + i + pairSize);
    pair.index = i / pairSize;
    pairVec.push_back(pair);
  }
  if (i <= vec.size() - pairSize / 2) {
    oddElement.insert(oddElement.end(), vec.begin() + i,
                      vec.begin() + i + pairSize / 2);
    i += pairSize / 2;
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
      std::swap_ranges(
          vec.begin() + pairVec[i].index * pairSize,
          vec.begin() + pairVec[i].index * pairSize + (pairSize / 2),
          vec.begin() + pairVec[i].index * pairSize + (pairSize / 2));
    }
  }
}

void PmergeMe::printPairs() {
  std::cout << "Recursion level: " << recursionLevel << std::endl;
  std::cout << "Pair size: " << pairSize << std::endl;
  // Calculate dynamic column widths based on the content
  size_t maxSmallWidth = 5; // Minimum width for "empty" label
  size_t maxLargeWidth = 5; // Minimum width for "empty" label

  for (const auto &pair : pairVec) {
    std::ostringstream ossSmall, ossLarge;
    printSequence(pair.small, ossSmall);
    printSequence(pair.large, ossLarge);

    maxSmallWidth = std::max(maxSmallWidth, ossSmall.str().length());
    maxLargeWidth = std::max(maxLargeWidth, ossLarge.str().length());
  }

  // Print header
  std::cout << std::left << std::setw(10) << "Pair" << std::setw(maxSmallWidth)
            << "Small"
            << " | " << std::setw(maxLargeWidth) << "Large" << std::endl;
  std::cout << std::string(10 + maxSmallWidth + 3 + maxLargeWidth, '-')
            << std::endl;

  // Print each pair
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << std::left << std::setw(10) << ("Pair " + std::to_string(i));

    std::ostringstream ossSmall, ossLarge;
    if (pairVec[i].small.empty()) {
      ossSmall << "empty";
    } else {
      printSequence(pairVec[i].small, ossSmall);
    }

    if (pairVec[i].large.empty()) {
      ossLarge << "empty";
    } else {
      printSequence(pairVec[i].large, ossLarge);
    }

    std::cout << std::setw(maxSmallWidth) << ossSmall.str() << " | "
              << std::setw(maxLargeWidth) << ossLarge.str() << std::endl;
  }

  // Print additional information
  std::cout << "\nOdd element: ";
  if (oddElement.empty()) {
    std::cout << "empty\n";
  } else {
    printSequence(oddElement);
  }

  std::cout << "Leftovers: ";
  if (leftovers.empty()) {
    std::cout << "empty\n";
  } else {
    printSequence(leftovers);
  }

  std::cout << "Vector: ";
  printSequence(vec);
  std::cout << std::endl;
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
  // sortPairs();
  printPairs(); // debugging
  binaryInsertionSort();
  pairSize /= 2;
  recursionLevel--;
  jacobStahlIndex++;
  if (jacobStahlIndex >= jacobsthalSequence.size()) {
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
  std::cout << "Jacobsthal sequence: ";
  printSequence(jacobsthalSequence);
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
  vec = input;
  recursionLevel = 1;
  pairSize = 2;
  keepRecursing = true;
  jacobStahlIndex = 3;
  createJacobsthalSequence();
  fordJohnsonAlgorithm();
  return vec;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
  std::deque<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}