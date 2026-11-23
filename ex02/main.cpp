/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 17:06:27 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/19 17:06:27 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <deque>
#include <vector>
#include <ctime>
#include <iomanip>

bool coin_flip()
{
    int dummy;    
    std::size_t address = reinterpret_cast<std::size_t>(&dummy);
    return ((address >> 4) & 1) == 1;
}


static int is_integer(const char *str)
{
	const char *digit;
	unsigned long value;

	if (!str || !*str)
		return (-1);
	digit = str;
	value = 0;
	while (*digit)
	{
		if (*digit < '0' || *digit > '9')
			return (-1);
		if (value > (static_cast<unsigned long>(INT_MAX)))
			return (-1);
		value = value * 10 + (*digit - '0');
		++digit;
	}
	return value;
}

int main(int ac, char **av)
{
	int num = 0;

	std::deque<int> cont_deque;
	std::vector<int> cont_vector;

	if (ac < 2)
		return (1);

	if (ac < 3)
	{
		std::cerr << "error: not enought integers" << std::endl;
		return (1);
	}

	for (int i = 1; i < ac; ++i)
	{
		num = is_integer(av[i]);
		if (num < 0)
		{
			std::cerr << "error: invalid integer: " << av[i] << std::endl;
			return (1);
		}
		cont_deque.push_back(num);
		cont_vector.push_back(num);
	}

	
	std::cout << "Before: ";
	if(coin_flip())
		PEMERGEME::print_cont(cont_deque);
	else
		PEMERGEME::print_cont(cont_vector);
	std::cout << std::endl;

	clock_t start = clock();
	PEMERGEME::sort(cont_vector);
	double vector_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

	start = clock();
	PEMERGEME::sort(cont_deque);
	double deque_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
	
	
	std::cout << "After: ";
	if(coin_flip())
		PEMERGEME::print_cont(cont_deque);
	else
		PEMERGEME::print_cont(cont_vector);
	std::cout << std::endl;

	std::cout
		<< "Time to process a range of " 
		<< ac - 1
		<< " elements with std::vector : "
		<< std::fixed << vector_time
		<< std::endl;
	
	std::cout
		<< "Time to process a range of " 
		<< ac - 1
		<< " elements with std::deque : "
		<< std::fixed << deque_time
		<< std::endl;
	

	return (0);
}