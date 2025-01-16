/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:52 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 16:46:39 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// Opens and parses the database file
BitcoinExchange::BitcoinExchange(const std::string &dbFilePath) {
  std::ifstream dbFile(dbFilePath);
  if (!dbFile.is_open()) {
    throw std::runtime_error("Error: could not open database file.");
  }

  std::string line;
  // Skip the header line
  if (std::getline(dbFile, line)) {
    if (line != "date,exchange_rate") {
      throw std::runtime_error("Error: invalid database header.");
    }
  }
  while (std::getline(dbFile, line)) {
    size_t commaPos = line.find(',');
    if (commaPos == std::string::npos) {
      std::cerr << "Error: invalid line format in database: " << line
                << std::endl;
      continue; // Skip invalid lines
    }

    std::string date = line.substr(0, commaPos); // Extract the date
    std::string rateStr =
        line.substr(commaPos + 1); // Extract the rate as a string
    try {
      float rate = std::stof(rateStr);
      exchangeRates[date] = rate;
    } catch (const std::exception &e) {
      std::cerr << "Error: invalid rate in line: " << line << std::endl;
    }
  }
}

// Finds the closest (equal or ealier) date in the database
float BitcoinExchange::getExchangeRate(const std::string &date) const {
  auto it = exchangeRates.lower_bound(date);
  if (it == exchangeRates.end() || it->first != date) {
    if (it == exchangeRates.begin()) {
      throw std::runtime_error("Error: no valid date available for lookup.");
    }
    --it; // Use closest earlier date
  }
  return it->second;
}

void BitcoinExchange::evaluateInputFile(
    const std::string &inputFilePath) const {
  std::ifstream inputFile(inputFilePath);
  if (!inputFile.is_open()) {
    std::cerr << "Error: could not open input file." << std::endl;
    return;
  }

  std::string line;
  // Skip the header line
  if (std::getline(inputFile, line)) {
    if (line != "date | value") {
      throw std::runtime_error("Error: invalid header in input file.");
    }
  }
  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string date, valueStr;
    char delimiter;

    if (!(iss >> date >> delimiter >> valueStr) || delimiter != '|') {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    try {
      float value = std::stof(valueStr);
      if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        continue;
      }
      if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        continue;
      }

      float rate = getExchangeRate(date);
      std::cout << date << " => " << value << " = " << value * rate
                << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}