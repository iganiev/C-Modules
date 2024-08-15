/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:56:04 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/22 22:56:04 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "---------------------------------------------" << std::endl;
    try
    {
        std::vector<int> myVector;
        Span sp(20000);
        for (int i = 0; i < 20000; i++)
            myVector.push_back(i);
        sp.addRange(myVector.begin(), myVector.end());
        std::cout << "Shortest Span: " <<  sp.shortestSpan() << std::endl;
        std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
        sp.addRange(myVector.begin(), myVector.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}