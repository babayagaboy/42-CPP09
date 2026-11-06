/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:46:51 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/06 15:40:31 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class rpn
{
	private:
		std::stack<int> _nums;
	public:
		rpn( void );
		rpn( const rpn& other);
		rpn& operator=( const rpn& other);
		~rpn( void );
		
		int calc( std::string arg );
		int solverpn( char op );
		
		class notAValidRPN : public std::exception {
			public:
				virtual const char* what() const throw ();
		};
};


#endif