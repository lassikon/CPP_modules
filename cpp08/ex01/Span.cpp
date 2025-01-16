/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:12:40 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 11:51:54 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) { *this = other; }

Span::~Span() {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    N = other.N;
    numbers = other.numbers;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (numbers.size() >= N) {
    throw std::out_of_range("Span is already full");
  }
  numbers.push_back(number);
}

int Span::shortestSpan() {
  if (numbers.size() < 2) {
    throw std::logic_error("Not enough elements to calculate span");
  }
  std::vector<int> sorted = numbers;
  std::sort(sorted.begin(), sorted.end());

  int minSpan = std::abs(sorted[1] - sorted[0]);
  for (size_t i = 1; i < sorted.size() - 1; ++i) {
    int span = std::abs(sorted[i + 1] - sorted[i]);
    if (span < minSpan)
      minSpan = span;
  }

  return minSpan;
}

int Span::longestSpan() {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough elements to calculate span");

  int min = *std::min_element(numbers.begin(), numbers.end());
  int max = *std::max_element(numbers.begin(), numbers.end());

  return max - min;
}