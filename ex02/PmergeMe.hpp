/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:57:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/20 19:12:43 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEMERGEME
# define PEMERGEME

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>

template<typename T>
void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template <typename Container>
int sort( Container& main )
{
	static int pair_size = 1;
	
	int c_size = main.size() / pair_size;
}

template <typename Container>
void print_cont( Container& c )
{
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
}

#endif