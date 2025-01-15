/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:27:01 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/15 11:59:51 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip> // std::setprecision
#include <iostream>
#include <limits> // std::numeric_limits
#include <string>

enum class ScalarType { Char, Int, Float, Double, SpecialFloat, SpecialDouble };

class ScalarConverter {
public:
  static void convert(const std::string &input);

private:
  ScalarConverter() = delete;
  ~ScalarConverter() = delete;
  ScalarConverter(const ScalarConverter &src) = delete;
  ScalarConverter &operator=(const ScalarConverter &src) = delete;
};