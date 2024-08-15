/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:23:49 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/23 01:23:49 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <iostream>
# include <stack>
# include <list>
# include <algorithm>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {
		std::cout << "Default constructor called" << std::endl;
	}
	MutantStack(MutantStack const & src) : std::stack<T>(src) {
		std::cout << "Copy constructor called" << std::endl;
		*this = src;
	}
	MutantStack &operator=(MutantStack const & src)
	{
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}

	iterator end()
	{
		return std::stack<T>::c.end();
	}

	iterator insert(iterator position, const T &val)
	{
		return std::stack<T>::c.insert(position, val);
	}
};


#endif