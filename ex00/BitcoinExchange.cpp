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
#include <limits>

std::string trim(const std::string& str);
bool validdate(const std::string& date);
bool readvalue(const std::string& str, double& value);

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

void BitcoinExchange::run(const std::string& filename)
{
	readdata();
	readinput(filename);
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
		throw std::runtime_error("unable to open data.csv");
	if (!std::getline(file, line) || trim(line) != "date,exchange_rate")
		throw std::runtime_error("invalid CSV header");
	this->_data.clear();
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		comma = line.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("invalid CSV row");
		date = line.substr(0, comma);
		valueStr = line.substr(comma + 1);
		if (!validdate(date) || !readvalue(valueStr, value) || value < 0)
			throw std::runtime_error("invalid CSV row");
		this->_data[date] = value;
	}
	if (file.bad())
		throw std::runtime_error("could not read data.csv");
	if (this->_data.empty())
		throw std::runtime_error("empty exchange database");
}

void BitcoinExchange::readinput(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	if (!std::getline(file, line) || trim(line) != "date | value")
		throw std::runtime_error("invalid input header.");
	while (std::getline(file, line))
	{
		if (!line.empty() && line[line.size() - 1] == '\r')
			line.erase(line.size() - 1);
		try
		{
			exchange(line);
		}
		catch (const std::exception& e)
		{
			std::cout << "error: " << e.what() << std::endl;
		}
	}
	if (file.bad())
		throw std::runtime_error("could not read input file.");
}

void BitcoinExchange::exchange(const std::string& line) const
{
	std::string::size_type separator = line.find('|');
	if (separator == std::string::npos)
		throw std::runtime_error("bad input => " + line);
	std::string date = trim(line.substr(0, separator));
	std::string valueStr = trim(line.substr(separator + 1));
	double value;

	if (!validdate(date) || !readvalue(valueStr, value))
		throw std::runtime_error("bad input => " + line);
	if (value < 0)
		throw std::runtime_error("not a positive number.");
	if (value > 1000)
		throw std::runtime_error("too large a number.");
	std::map<std::string, double>::const_iterator it = this->_data.upper_bound(date);
	if (it == this->_data.begin())
		throw std::runtime_error("no exchange rate available => " + date);
	--it;
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::printdata()
{
	std::map<std::string, double>::const_iterator it = this->_data.begin();

	for (; it != this->_data.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}


std::string trim(const std::string& str)
{
	std::string::size_type start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return ("");
	return (str.substr(start, str.find_last_not_of(" \t\r\n") - start + 1));
}

bool validdate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	
	for (std::string::size_type i = 0; i < date.size(); ++i)
	{
		if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))
			return (false);
	}

	int year;
	int month;
	int day;
	char dash;
	
	std::istringstream input(date);
	
	input >> year >> dash >> month >> dash >> day;
	if (year < 1 || month < 1 || month > 12 || day < 1)
		return (false);
	
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		days[1] = 29;
	
	return (day <= days[month - 1]);
}

bool readvalue(const std::string& str, double& value)
{
	std::istringstream input(str);
	if (!(input >> value))
		return (false);
	input >> std::ws;
	return (input.eof() && value == value
		&& value <= std::numeric_limits<double>::max()
		&& value >= -std::numeric_limits<double>::max());
}
