/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:17:40 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 14:44:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T> class Array {
private:
  T *elements;
  unsigned int arraySize;

public:
  Array() : elements(nullptr), arraySize(0) {}

  Array(unsigned int n) : elements(new T[n]()), arraySize(n) {}

  Array(const Array &other) : elements(nullptr), arraySize(other.arraySize) {
    if (arraySize > 0) {
      elements = new T[arraySize];
      for (unsigned int i = 0; i < arraySize; ++i) {
        elements[i] = other.elements[i];
      }
    }
  }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] elements;
      arraySize = other.arraySize;
      if (arraySize > 0) {
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i) {
          elements[i] = other.elements[i];
        }
      } else {
        elements = nullptr;
      }
    }
    return *this;
  }

  ~Array() { delete[] elements; }

  // Subscript operator for non-const
  T &operator[](unsigned int index) {
    if (index >= arraySize) {
      throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
  }

  // Subscript operator for const
  const T &operator[](unsigned int index) const {
    if (index >= arraySize) {
      throw std::out_of_range("Index out of bounds");
    }
    return elements[index];
  }

  // Getter
  unsigned int size() const { return arraySize; }
};