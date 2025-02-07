/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:09:52 by lkonttin          #+#    #+#             */
/*   Updated: 2025/02/07 15:00:11 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

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
      if (isValidFloat(rateStr)) {
        float rate = std::stof(rateStr);
        exchangeRates[date] = rate;
      } else {
        std::cerr << "Error: invalid rate in line: " << line << std::endl;
      }
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
      throw std::runtime_error("no valid date available for lookup.");
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

    if (!isValidDate(date)) {
      std::cerr << "Error: invalid date: " << date << std::endl;
      continue;
    }

    try {
      if (!isValidFloat(valueStr)) {
        std::cerr << "Error: invalid value." << std::endl;
        continue;
      }
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

bool BitcoinExchange::isValidDate(const std::string &date) const {
  std::regex pattern(R"((\d{4})-(\d{2})-(\d{2}))");
  std::smatch match;
  if (!std::regex_match(date, match, pattern)) {
    return false;
  } else {
    int year = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int day = std::stoi(match[3].str());
    int days[] = {31, (isLeapYear(year) ? 29 : 28),
      31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12 || day < 1 || day > days[month - 1]) {
      return false;
    } else {
      return true;
    }
  }
}

bool BitcoinExchange::isLeapYear(int year) const {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidFloat(std::string &s) const {
    if (s.empty() || (s.find_first_not_of("0123456789.-") != std::string::npos)) {
        return false;
    }
    try {
        size_t pos;
        std::stof(s, &pos);
        return pos == s.size();  // Ensure the entire string was consumed
    } catch (...) {
        return false;
    }
}