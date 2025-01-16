/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:32:20 by lkonttin          #+#    #+#             */
/*   Updated: 2025/01/16 15:41:19 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(const std::string &dbFilePath);
  ~BitcoinExchange();

  void loadDatabase(const std::string &filePath);
  float getExchangeRate(const std::string &date) const;
  void evaluateInputFile(const std::string &inputFilePath) const;

private:
  std::map<std::string, float> exchangeRates;
  bool isValidDate(const std::string &date) const;
};