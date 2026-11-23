/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:57:39 by hgutterr          #+#    #+#             */
/*   Updated: 2026/11/23 21:50:17 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEMERGEME
# define PEMERGEME

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <cstddef>

template<typename T>
void swap( T &a, T &b )
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename Container>
void swap_groups( Container& c, size_t first_index, size_t second_index, size_t pair_size )
{
	for (size_t i = 0; i < pair_size; ++i)
		swap(c[first_index + i], c[second_index + i]);
}

template <typename Container>
void print_cont( Container& c )
{
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
}

template <typename Container>
void jacobsthal( Container& main, size_t pair_size )
{
	size_t container_size = main.size() / pair_size;
	size_t pairs = container_size / 2;

	if (pairs == 0)
		return ;
	
	Container main_chain;
	Container pending_chain;

	main_chain.push_back(0);

	for(size_t i = 0; i < pairs; ++i) {
		main_chain.push_back(2 * i + 1);

		if (i > 0)
			pending_chain.push_back(2 * i);
	}

	if (container_size % 2 != 0)
		pending_chain.push_back(container_size - 1);
	
	// std::cout << "main_chain: ";
	// print_cont(main_chain);
	// std::cout << std::endl;

	// std::cout << "pending_chain: ";
	// print_cont(pending_chain);
	// std::cout << std::endl;


	size_t inserted = 0;
	size_t prev_jacob = 1;
	size_t jacob = 3;

	while (inserted < pending_chain.size())
	{
		size_t stop = std::min(jacob - 1, pending_chain.size());

		for (size_t k = stop; k > inserted; --k)
		{
			size_t group = pending_chain[k - 1];
			size_t upper = main_chain.size();

			if (group + 1 < container_size)
			{
				for (size_t j = 0; j < main_chain.size(); ++j)
				{
					if (static_cast<size_t>(main_chain[j]) == group + 1)
					{
						upper = j;
						break;
					}
				}
			}

			size_t low = 0;

			while (low < upper)
			{
				size_t mid = low + (upper - low) / 2;

				size_t a = (main_chain[mid] + 1) * pair_size - 1;
				size_t b = (group + 1) * pair_size - 1;

				if (main[a] < main[b])
					low = mid + 1;
				else
					upper = mid;
			}

			main_chain.insert(main_chain.begin() + low, group);
		}

		inserted = stop;

		size_t next = jacob + 2 * prev_jacob;
		prev_jacob = jacob;
		jacob = next;
	}

	Container result;

	for (size_t i = 0; i < main_chain.size(); ++i)
	{
		size_t start = main_chain[i] * pair_size;

		for (size_t j = 0; j < pair_size; ++j)
			result.push_back(main[start + j]);
	}

	for (size_t i = container_size * pair_size; i < main.size(); ++i)
		result.push_back(main[i]);

	main.swap(result);
}

template <typename Container>
void sort( Container& main, size_t pair_size = 1 )
{
	size_t container_size = main.size() / pair_size;

	if (container_size < 2)
		return;

	for (size_t i = 0; i + 1 < container_size; i += 2) {
		size_t first_index = (i + 1) * pair_size - 1;
		size_t second_index = (i + 2) * pair_size - 1;

		if (main[first_index] > main[second_index])
			swap_groups(main, i * pair_size, (i + 1) * pair_size, pair_size);
	}

	// std::cout << "pair_size = " << pair_size << std::endl;
	// print_cont(main);
	// std::cout << std::endl;

	sort(main, pair_size * 2);
	jacobsthal(main, pair_size);
}

#endif