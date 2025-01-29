/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/29 15:24:58 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// test case
// ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::formMainSequence() {
  std::cout << "Forming main sequence" << std::endl;
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
    std::cout << "Index in main sequence: " << pairVec[i].indexInMainSequence
              << std::endl;
  }
  std::cout << "Main elements: ";
  printSequence(vec);
  std::cout << "Main size: " << vec.size() << std::endl;
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
    std::cout << "Skipping binaryInsertionSort at recursion level: "
              << recursionLevel << std::endl;
    return;
  }
  formMainSequence();

  while (!pairVec.empty()) {
    int i = getNextJacobsthal();
    std::cout << "Jacobsthal: " << i << std::endl;

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

      // Calculate the actual index for insertion
      int insertIndex = left * elementSize;
      std::cout << "Inserting: ";
      printSequence(pairVec[i].small);
      std::cout << "At main index: " << insertIndex << std::endl;

      // Insert the sequence into vec at the determined position
      vec.insert(vec.begin() + insertIndex, pairVec[i].small.begin(),
                 pairVec[i].small.end());

      std::cout << "Vec after insertion: ";
      printSequence(vec);
      std::cout << std::endl;

      // Update pair indexes and remove the inserted pair
      updatePairIndexes(pairVec[i].small.back());
      pairVec.erase(pairVec.begin() + i);
      i--;
    }
  }

  if (!oddElement.empty()) {
    std::cout << "Vec before oddElement insertion: ";
    printSequence(vec);
    int rightBoundary = (vec.size() - 1) / elementSize;
    // Perform binary search for insertion point
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
    std::cout << "Inserting: ";
    printSequence(oddElement);
    std::cout << "At main index: " << insertIndex << std::endl;
    vec.insert(vec.begin() + insertIndex, oddElement.begin(), oddElement.end());
    std::cout << "Vec after oddElement insertion: ";
    printSequence(vec);
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
  std::cout << "Sorting pairs" << std::endl;
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << "Sorting pair " << i << std::endl;
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

void PmergeMe::printPairs() {
  std::cout << "Recursion level: " << recursionLevel << std::endl;
  std::cout << "Element size: " << elementSize << std::endl;
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
  if (keepRecursing && elementSize * 2 <= vec.size()) {
    makePairs();
    sortPairs();
    printPairs(); // debugging
    elementSize *= 2;
    recursionLevel++;
    fordJohnsonAlgorithm(); // Recurse
  }
  keepRecursing = false;
  makePairs();
  // sortPairs();
  printPairs(); // debugging
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
  std::cout << "Jacobsthal sequence: ";
  printSequence(jacobsthalSequence);
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