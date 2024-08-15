/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:54:28 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/05 10:54:28 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <iomanip>
# include <ctime>


class BitcoinExchange
{

private:
    std::map<std::string, double> _exchange;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    ~BitcoinExchange();

    void loadExchangeRates(const std::string &filename);
    void calculateExchange(const std::string &inputFile);
    static std::string findClosestDate(const std::map<std::string, double> &exchange, const std::string &date);
    static bool isValidDate(const std::string &date);
    static bool isValidValue(const std::string &value);
    static bool isCsvFile(const std::string &filename);

private:
    std::string trim(const std::string &str);

};



#endif