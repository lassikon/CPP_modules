/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:32:20 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/30 12:38:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <regex>

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(const std::string &dbFilePath);
  ~BitcoinExchange();

  void evaluateInputFile(const std::string &inputFilePath) const;

private:
  std::map<std::string, float> exchangeRates;

  void loadDatabase(const std::string &filePath);
  float getExchangeRate(const std::string &date) const;
  bool isValidDate(const std::string &date) const;
  bool isLeapYear(int year) const;
};