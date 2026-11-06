/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:46:45 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/06 15:41:57 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"
#include <cctype>
#include <sstream>
#include <stdexcept>

rpn::rpn( void )
{
}

rpn::rpn( const rpn& other) : _nums(other._nums)
{
}

rpn& rpn::operator=( const rpn& other)
{
	if (this != &other)
		this->_nums = other._nums;
	return (*this);
}

rpn::~rpn( void )
{
}

int rpn::calc( std::string arg )
{
	std::istringstream input(arg);
	std::string token;
	this->_nums = std::stack<int>();

	while (input >> token)
	{
		if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			this->_nums.push(token[0] - '0');
		else if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
			this->_nums.push(solverpn(token[0]));
		else
			throw (rpn::notAValidRPN());
	}
	if (this->_nums.size() != 1)
		throw (rpn::notAValidRPN());
	return (this->_nums.top());
}

int rpn::solverpn( char op )
{
	int n1;
	int n2;

	if (this->_nums.size() < 2)
		throw (rpn::notAValidRPN());

	n2 = this->_nums.top();
	this->_nums.pop();
	n1 = this->_nums.top();
	this->_nums.pop();

	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (op == '/')
	{
		if (n2 == 0)
			throw (rpn::notAValidRPN());
		return (n1 / n2);
	}
	throw (rpn::notAValidRPN());
}

const char* rpn::notAValidRPN::what() const throw ()
{
	return ("not a valid RPN expression");
}
