/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:05:36 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/20 12:51:21 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input) {
  std::vector<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input) {
  std::deque<int> sorted = input;
  // Implement Ford-Johnson algorithm here
  return sorted;
}

template <typename Container>
void PmergeMe::printSequence(const Container &sequence) {
  for (size_t i = 0; i < sequence.size(); i++) {
    std::cout << sequence[i] << (i < sequence.size() - 1 ? " " : "\n");
  }
}