/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:52:13 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 16:15:20 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./btc <filename>\n";
    return 1;
  }

  try {
    BitcoinExchange btc("data.csv");
    std::string input(argv[1]);
    btc.evaluateInputFile(input);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}