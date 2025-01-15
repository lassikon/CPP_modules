/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:12:35 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 15:31:22 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int N;
  std::vector<int> numbers;

public:
  Span() = delete;
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();

  Span &operator=(const Span &other);

  void addNumber(int number);
  template <typename It> void addNumbers(It begin, It end);

  int shortestSpan();
  int longestSpan();
};