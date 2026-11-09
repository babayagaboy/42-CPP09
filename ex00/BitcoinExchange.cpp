/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:01:06 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/14 20:01:06 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _data(other._data)
{	
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& other )
{
	if(this != &other)
		this->_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
}

void BitcoinExchange::readdata()
{
	std::ifstream file("./data.csv");
	std::string line;
	std::string date;
	std::string valueStr;
	std::string::size_type comma;
	double value;

	if (!file.is_open())
		throw std::runtime_error("Unable to open data.csv");
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::runtime_error("Invalid CSV header");
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		date = line.substr(0, comma);
		valueStr = line.substr(comma + 1);
		if (date.empty() || valueStr.empty())
			continue;
		std::istringstream iss(valueStr);
		if (!(iss >> value))
			continue;
		this->_data[date] = value;
	}
}

void BitcoinExchange::printdata()
{
	std::map<std::string, double>::const_iterator it = this->_data.begin();

	for (; it != this->_data.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}