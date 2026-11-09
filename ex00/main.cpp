/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:00:08 by hgutterr          #+#    #+#             */
/*   Updated: 2026/07/14 20:00:08 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if(ac != 2)
		return (1);

	BitcoinExchange be;

	try
	{
		be.readdata();
		be.printdata();
	}
	catch(const std::exception& e)
	{

	}	
	return (0);
}