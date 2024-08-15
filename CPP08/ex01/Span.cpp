/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:56:53 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/22 22:56:53 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
    std::cout << "Span constructor called" << std::endl;
}


Span::Span(Span const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Span & Span::operator=(Span const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
    {
        _N = src._N;
        _v = src._v;
    }
    return *this;
}

unsigned int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements to calculate span");
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    int min = INT_MAX;
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        if (tmp[i + 1] - tmp[i] < min)
            min = tmp[i + 1] - tmp[i];
    }
    return min;
}


unsigned int Span::longestSpan()
{
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements to calculate span");
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::addNumber(int n)
{
    if (_v.size() == _N)
        throw std::out_of_range("No more space to add elements");
    _v.push_back(n);
}

Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
}