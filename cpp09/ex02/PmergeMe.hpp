/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:55:22 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/17 12:35:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other) = delete;
  PmergeMe &operator=(const PmergeMe &other) = delete;
  ~PmergeMe();

  void sortVector(const std::vector<int> &input);
  void sortDeque(const std::deque<int> &input);

  template <typename Container> void printSequence(const Container &sequence);

private:
  
};