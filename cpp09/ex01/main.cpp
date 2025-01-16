/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:33:09 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 17:42:46 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./rpn <expression>\n";
    return 1;
  }

  try {
    RPN rpn(argv[1]);
    int result = rpn.evaluate();
    std::cout << result << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}