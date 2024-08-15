/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:56:41 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/22 22:56:41 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <string>
# include <climits>

class Span
{
private:
    unsigned int _N;
    std::vector<int> _v;
public:
    Span();
    Span(unsigned int N);
    Span(Span const & src);
    Span & operator=(Span const & src);
    ~Span();


    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename T>
    void addRange(T begin, T end)
    {
        if (_v.size() + std::distance(begin, end) > _N)
            throw std::out_of_range("Not enough space to add range");
        for (T it = begin; it != end; it++)
            _v.push_back(*it);
    }

};



#endif