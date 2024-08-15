/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 01:22:39 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/23 01:22:39 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "Using MUtantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Using List:" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator itl = list.begin();
	std::list<int>::iterator itle = list.end();
	++itl;
	--itl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> l(list);

	std::cout << "Other tests:" << std::endl;
	MutantStack<int> mstack2;
	mstack2.push(5);
	mstack2.push(17);
	mstack2.push(3);
	mstack2.push(737);
	mstack2.push(0);
	std::cout << "Top: " << mstack2.top() << std::endl;
	std::cout << "Size: " << mstack2.size() << std::endl;
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	it2 += 2;
	mstack2.insert(it2, 42);
	it2 = mstack2.begin();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}


	return 0;
}
