/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:30:53 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/06 14:30:53 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);

	rpn st;
	std::string arg;
	for (int i = 1; i < ac; ++i)
	{
		if (i > 1)
			arg += ' ';
		arg += av[i];
	}

	try
	{
		std::cout << st.calc(arg) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}