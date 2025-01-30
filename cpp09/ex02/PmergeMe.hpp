/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:22 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/30 15:56:52 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

template <typename Container> class PmergeMe {
public:
  PmergeMe();
  ~PmergeMe();
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;

  Container sort(const Container &input);

private:
  struct Pair {
    Container small;
    Container large;
    size_t indexInMainSequence;
  };

  void createJacobsthalSequence();
  void formMainSequence();
  void updatePairIndexes(int inserted);
  int getNextJacobsthal();
  void binaryInsertionSort();
  void makePairs();
  void sortPairs();
  void fordJohnsonAlgorithm();

  Container seq;
  std::vector<Pair> pairs;
  Container oddElement;
  Container leftovers;
  std::vector<size_t> jacobsthalSequence;
  size_t elementSize;
  size_t jacobsthalIndex;
  bool keepRecursing;
};

template <typename Container> PmergeMe<Container>::PmergeMe() {
  createJacobsthalSequence();
  elementSize = 1;
  jacobsthalIndex = 3;
  keepRecursing = true;
}

template <typename Container> PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
void PmergeMe<Container>::createJacobsthalSequence() {
  size_t sequenceSize = 20;
  jacobsthalSequence.push_back(0);
  jacobsthalSequence.push_back(1);
  for (size_t i = 2; i < sequenceSize; ++i) {
    jacobsthalSequence.push_back(jacobsthalSequence[i - 1] +
                                 2 * jacobsthalSequence[i - 2]);
  }
}

// Take the smallest pair + the larger elements from every other pair
template <typename Container> void PmergeMe<Container>::formMainSequence() {
  seq.clear();
  seq.insert(seq.end(), pairs[0].small.begin(), pairs[0].small.end());
  size_t index = 2 * elementSize - 1;
  pairs[0].indexInMainSequence = index;
  seq.insert(seq.end(), pairs[0].large.begin(), pairs[0].large.end());
  pairs.erase(pairs.begin());
  for (size_t i = 0; i < pairs.size(); ++i) {
    seq.insert(seq.end(), pairs[i].large.begin(), pairs[i].large.end());
    index += elementSize;
    pairs[i].indexInMainSequence = index;
  }
}

// Returns the index in pairs from where we start inserting
template <typename Container>
void PmergeMe<Container>::updatePairIndexes(int inserted) {
  for (size_t j = 0; j < pairs.size(); ++j) {
    if (pairs[j].large.back() > inserted) {
      pairs[j].indexInMainSequence += elementSize;
    }
  }
}

template <typename Container> int PmergeMe<Container>::getNextJacobsthal() {
  int jacobSthal = jacobsthalSequence[jacobsthalIndex] -
                   jacobsthalSequence[jacobsthalIndex - 1];
  jacobsthalIndex++;
  if (jacobSthal >= static_cast<int>(pairs.size())) {
    jacobSthal = pairs.size();
  }
  return jacobSthal - 1;
}

template <typename Container> void PmergeMe<Container>::binaryInsertionSort() {
  if (elementSize * 2 > seq.size()) {
    return;
  }

  formMainSequence();

  while (!pairs.empty()) {
    int i = getNextJacobsthal();
    while (i >= 0) {
      int rightBoundary = pairs[i].indexInMainSequence / elementSize;
      // Perform binary search for insertion point
      int left = 0, right = rightBoundary;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (pairs[i].small.back() > seq[mid * elementSize + elementSize - 1]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      // Calculate the actual index for insertion, and insert the sequence
      int insertIndex = left * elementSize;
      seq.insert(seq.begin() + insertIndex, pairs[i].small.begin(),
                 pairs[i].small.end());

      updatePairIndexes(pairs[i].small.back());
      pairs.erase(pairs.begin() + i);
      --i;
    }
  }

  // Insert the odd element if one exists
  if (!oddElement.empty()) {
    int rightBoundary = (seq.size() - 1) / elementSize;
    int left = 0, right = rightBoundary;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (oddElement.back() > seq[mid * elementSize + elementSize - 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    int insertIndex = left * elementSize;
    seq.insert(seq.begin() + insertIndex, oddElement.begin(), oddElement.end());
  }

  // add the leftover numbers to the end of the sequence
  if (!leftovers.empty()) {
    for (size_t i = 0; i < leftovers.size(); ++i) {
      seq.push_back(leftovers[i]);
    }
  }

  if (elementSize == 1 && seq.back() < seq[seq.size() - 2]) {
    std::swap(seq.back(), seq[seq.size() - 2]);
  }
}

template <typename Container> void PmergeMe<Container>::makePairs() {
  pairs.clear();
  oddElement.clear();
  leftovers.clear();
  size_t i;
  for (i = 0; i + elementSize * 2 <= seq.size(); i += elementSize * 2) {
    Pair pair;
    pair.small.insert(pair.small.end(), seq.begin() + i,
                      seq.begin() + i + elementSize);
    pair.large.insert(pair.large.end(), seq.begin() + i + elementSize,
                      seq.begin() + i + elementSize * 2);
    pairs.push_back(pair);
  }
  if (i <= seq.size() - elementSize) {
    oddElement.insert(oddElement.end(), seq.begin() + i,
                      seq.begin() + i + elementSize);
    i += elementSize;
  }
  if (i < seq.size()) {
    leftovers.insert(leftovers.end(), seq.begin() + i, seq.end());
  }
}

template <typename Container> void PmergeMe<Container>::sortPairs() {
  for (size_t i = 0; i < pairs.size(); ++i) {
    if (!pairs[i].small.empty() && !pairs[i].large.empty() &&
        pairs[i].small.back() > pairs[i].large.back()) {
      std::swap(pairs[i].small, pairs[i].large);
      // Sort the pair in the seqtor
      std::swap_ranges(seq.begin() + i * elementSize * 2,
                       seq.begin() + i * elementSize * 2 + elementSize,
                       seq.begin() + i * elementSize * 2 + elementSize);
    }
  }
}

template <typename Container> void PmergeMe<Container>::fordJohnsonAlgorithm() {
  if (keepRecursing && elementSize * 2 <= seq.size()) {
    makePairs();
    sortPairs();
    elementSize *= 2;
    fordJohnsonAlgorithm(); // Recurse
  }

  keepRecursing = false;
  makePairs();
  binaryInsertionSort();
  elementSize /= 2;
  jacobsthalIndex = 3;
  if (jacobsthalIndex >= jacobsthalSequence.size()) {
    throw std::out_of_range("Jacobsthal index out of range");
  }
}

template <typename Container>
Container PmergeMe<Container>::sort(const Container &input) {
  seq = input;
  fordJohnsonAlgorithm();
  return seq;
}