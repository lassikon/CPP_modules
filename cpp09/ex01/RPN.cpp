/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:08:31 by lkonttin          #+#    #+#             */
/*   Updated: 2025/02/05 16:39:55 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype> // std::isdigit
#include <iostream>
#include <sstream> // std::istringstream
#include <stack>
#include <stdexcept>
#include <limits>

RPN::RPN(const std::string &input) : input(input) {}

RPN::~RPN() {}

bool RPN::isOperator(char token) const {
  return token == '+' || token == '-' || token == '*' || token == '/';
}

bool RPN::isNumber(char token) const { return std::isdigit(token); }

bool RPN::willOverflow(int a, int b, char op) {
  switch (op) {
    case '*':
      if (b > 0)
        return (a > std::numeric_limits<int>::max() / b || a < std::numeric_limits<int>::min() / b);
      else if (b < 0)
        return (a < std::numeric_limits<int>::max() / b || a > std::numeric_limits<int>::min() / b);
      return false; // Multiplication by zero is always safe

    case '+':
      if (b > 0)
        return (a > std::numeric_limits<int>::max() - b);
      else
        return (a < std::numeric_limits<int>::min() - b);

    case '-':
      if (b > 0)
        return (a < std::numeric_limits<int>::min() + b);
      else
        return (a > std::numeric_limits<int>::max() + b);

    case '/':
      return (b == 0 || (a == std::numeric_limits<int>::min() && b == -1)); // Prevent division overflow (INT_MIN / -1)

    default:
      return false;
  }
}


int RPN::calculate(int a, int b, char op) {
  if (willOverflow(a, b, op)) {
    throw std::overflow_error("Arithmetic overflow");
  }
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0) {
      throw std::runtime_error("Division by zero");
    }
    return a / b;
  default:
    throw std::runtime_error("Invalid operator");
  }
}

int RPN::evaluate() {
  std::stack<int> stack;
  std::istringstream iss(input);
  char token;

  while (iss >> token) {
    if (isNumber(token)) {
      stack.push(token - '0'); // Converts char to int
    } else if (isOperator(token)) {
      if (stack.size() < 2) {
        throw std::runtime_error("Invalid RPN expression");
      }
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      stack.push(calculate(a, b, token));
    } else {
      throw std::runtime_error("Invalid token: " + std::string(1, token));
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Invalid RPN expression");
  }
  return stack.top();
}