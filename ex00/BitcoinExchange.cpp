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
	std::ifstream file;

	file.open("./data.csv");

	std::string a;
	std::getline(file, a);
	if(a != "date,exchange_rate")
		throw ;

	std::string::size_type comma;
	while (std::getline(file, a))
	{
		// comma = a;
		std::cout << a << std::endl;
	}
}