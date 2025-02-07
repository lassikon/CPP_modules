/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:32:20 by lkonttin          #+#    #+#             */
/*   Updated: 2025/02/07 15:00:11 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <regex>

class BitcoinExchange {
public:
  BitcoinExchange() = delete;
  BitcoinExchange(const std::string &dbFilePath);
  BitcoinExchange(const BitcoinExchange &other) = delete;
  BitcoinExchange &operator=(const BitcoinExchange &other) = delete;
  ~BitcoinExchange();

  void evaluateInputFile(const std::string &inputFilePath) const;

private:
  std::map<std::string, float> exchangeRates;

  void loadDatabase(const std::string &filePath);
  float getExchangeRate(const std::string &date) const;
  bool isValidDate(const std::string &date) const;
  bool isLeapYear(int year) const;
  bool isValidFloat(std::string &s) const;
};