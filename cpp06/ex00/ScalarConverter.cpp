/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:26:59 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/14 22:34:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void printChar(int64_t c) {
  if (std::isprint(c)) {
    std::cout << "char: '" << static_cast<char>(c) << "'\n";
  } else {
    std::cout << "char: Non displayable\n";
  }
}

static void printInt(int64_t i) {
  if (i > std::numeric_limits<int>::max() ||
      i < std::numeric_limits<int>::min()) {
    std::cout << "int: impossible\n";
  } else {
    std::cout << "int: " << static_cast<int>(i) << "\n";
  }
}

static void printFloat(float f) {
  if (f > std::numeric_limits<float>::max() ||
      f < -std::numeric_limits<float>::max()) {
    std::cout << "float: impossible\n";
  } else {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
  }
}

static void printDouble(double d) {
  if (d > std::numeric_limits<double>::max() ||
      d < -std::numeric_limits<double>::max()) {
    std::cout << "double: impossible\n";
  } else {
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
  }
}

static void handleChar(char c) {
  printChar(c);
  printInt(c);
  printFloat(c);
  printDouble(c);
}

static void handleInt(int64_t i) {
  printChar(i);
  printInt(i);
  printFloat(i);
  printDouble(i);
}

static void handleFloat(float f) {
  printChar(f);
  printInt(f);
  printFloat(f);
  printDouble(f);
}

static void handleDouble(double d) {
  printChar(d);
  printInt(d);
  printFloat(d);
  printDouble(d);
}

static ScalarType getType(const std::string &input) {
  if (input.length() == 1 && !std::isdigit(input[0])) {
    return ScalarType::Char;
  }
  if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan" ||
      input == "+nan" || input == "-nan") {
    return ScalarType::Double;
  }
  if (input == "+inff" || input == "-inff" || input == "nanf" ||
      input == "+nanf" || input == "-nanf") {
    return ScalarType::Float;
  }
  try {
    std::stod(input);
    return ScalarType::Double;
  } catch (...) {
  }
  try {
    std::stoi(input);
    return ScalarType::Int;
  } catch (...) {
  }
  try {
    std::stof(input);
    return ScalarType::Float;
  } catch (...) {
  }
  throw std::invalid_argument("Invalid input");
}

void ScalarConverter::convert(const std::string &input) {
  try {
    switch (getType(input)) {
    case ScalarType::Char:
      handleChar(input[0]);
      break;
    case ScalarType::Int:
      handleInt(std::stoll(input));
      break;
    case ScalarType::Float:
      handleFloat(std::stof(input));
      break;
    case ScalarType::Double:
      handleDouble(std::stod(input));
      break;
    }
  } catch (...) {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
  }
}