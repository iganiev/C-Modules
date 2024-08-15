/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:54:37 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/05 10:54:37 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}  

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _exchange(copy._exchange)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)  
        _exchange = copy._exchange;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string &filename) {
    if (!isCsvFile(filename)) {
        throw std::runtime_error("Error: exchange rates file must have a .csv extension.");
    }

    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
        throw std::runtime_error("Error: could not open exchange rates file.");

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        file.close();
        throw std::runtime_error("Error: exchange rates file is empty.");
    }

    std::string line, dateStr, rateStr;
    double rate;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(std::getline(iss, dateStr, ',') && std::getline(iss, rateStr)))
            continue;
        
        try {
            rate = std::stod(rateStr);
        } 
        catch (const std::exception &e) {
            continue;
        }

        _exchange[dateStr] = rate;
    }
    file.close();
}


void BitcoinExchange::calculateExchange(const std::string &inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }


    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        double value;

        if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr))) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim whitespace from date and valueStr
        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date)) {
            std::cout << "Error: bad input date => " << date << std::endl;
            continue;
        }

        if (!isValidValue(valueStr)) {
            std::cout << "Error: not a valid positive number => " << valueStr << std::endl;
            continue;
        }

        value = std::stod(valueStr);
        if (value < 0 || value > 1000) {
            std::cout << "Error: value out of valid range (0 - 1000) => " << valueStr << std::endl;
            continue;
        }

        std::string closestDate = findClosestDate(_exchange, date);
        double rate = _exchange[closestDate];
        double result = value * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}

// Utility function to trim whitespace from a string
std::string BitcoinExchange::trim(const std::string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }
    return str.substr(first, last - first + 1);
}


std::string BitcoinExchange::findClosestDate(const std::map<std::string, double> &exchange, const std::string &date)
{
    std::map<std::string, double>::const_iterator it = exchange.lower_bound(date);

    // Check if the iterator points to the end or if the exact date was not found
    if (it == exchange.end() || it->first != date)
    {
        if (it != exchange.begin())
            --it;
    }

    // Return the closest date
    return it->first;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    try
    {
        year = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    }
    catch (...) {
        return false;
    }

    if (year < 2009 || year > 2022)
        return false;

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeap))
            return false;
    }

    return true;
}


bool BitcoinExchange::isValidValue(const std::string &value)
{
    char *endptr = 0;
    double val = strtod(value.c_str(), &endptr);
    return endptr != value.c_str() && *endptr == '\0' && val >= 0;
}

bool BitcoinExchange::isCsvFile(const std::string &filename)
{
    if (filename.size() < 4)
        return false;
    return filename.substr(filename.size() - 4) == ".csv";
}


