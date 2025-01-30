/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:52:23 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/30 12:44:59 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class RPN {
public:
  RPN() = delete;
  RPN(const std::string &input);
  ~RPN();

  int evaluate();

private:
  std::string input;

private:
  bool isOperator(char token) const;
  bool isNumber(char token) const;
  bool willOverflow(int a, int b, char op);
  int calculate(int a, int b, char op);
};