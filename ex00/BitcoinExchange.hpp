/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:01:14 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/14 20:01:14 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& other );
		BitcoinExchange& operator=( const BitcoinExchange& other );
		~BitcoinExchange( void );
	
		void run(const std::string& filename);
		void readdata();
		void printdata();
		void readinput(const std::string& filename) const;
		void exchange(const std::string& line) const;
};

#endif
