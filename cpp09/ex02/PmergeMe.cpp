/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/20 16:07:26 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::makeAndSortPairs(std::vector<int> &vec) {
  std::cout << "Making pairs at recursion level: " << recursionLevel
            << std::endl;
  pairVec.clear();
  for (size_t i = 0; i < vec.size() - pairSize; i += pairSize) {
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
    if (!pair.small.empty() && !pair.large.empty() &&
        pair.small.back() > pair.large.back()) {
      std::swap(pair.small, pair.large);
      // Sort the pair in the vector
      std::swap_ranges(vec.begin() + i, vec.begin() + i + (pairSize / 2),
                       vec.begin() + i + (pairSize / 2));
    }
    pairVec.push_back(pair);
  }
  // for debugging
  std::cout << "Pair size: " << pairSize << std::endl;
  for (size_t i = 0; i < pairVec.size(); i++) {
    std::cout << "Pair " << i << " small: ";
    printSequence(pairVec[i].small);
    std::cout << "Pair " << i << " large: ";
    printSequence(pairVec[i].large);
  }
  std::cout << "\nVector after pair sorting: ";
  printSequence(vec);

  pairSize *= 2;
  if (pairSize > vec.size()) {
    keepRecursing = false;
  }
  if (keepRecursing) {
    recursionLevel++;
    makeAndSortPairs(vec);
  }
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
  vec = input;
  recursionLevel = 1;
  pairSize = 2;
  keepRecursing = true;
  makeAndSortPairs(vec);
  return vec;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
  std::deque<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}