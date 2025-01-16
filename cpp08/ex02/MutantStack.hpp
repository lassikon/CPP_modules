/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:04:49 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 12:15:10 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  // Inherit constructors
  using std::stack<T>::stack;

  // Aliases for iterator types
  using iterator = typename std::deque<T>::iterator;
  using const_iterator = typename std::deque<T>::const_iterator;

  iterator begin() { return this->c.begin(); }

  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }

  const_iterator end() const { return this->c.end(); }
};