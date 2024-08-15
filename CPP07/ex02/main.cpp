/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:33:49 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 22:33:49 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"


int main( void )
{
    try
    {
        std::cout << "Int array:" << std::endl;
        Array<int> a(5);
        for (size_t i = 0; i < a.size(); i++)
        {
            a[i] = i;
            std::cout << a[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Array<int> b;
        for (size_t i = 0; i < b.size(); i++)
        {
            b[i] = i;
            std::cout << b[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Char array:" << std::endl;
        Array<char> c(5);
        for (size_t i = 0; i < c.size(); i++)
        {
            c[i] = i + 65;
            std::cout << c[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "String array:" << std::endl;
        Array<std::string> d(5);
        d[0] = "one";
        d[1] = "two";
        d[2] = "three";
        d[3] = "four";
        d[4] = "five";
        for (size_t i = 0; i < d.size(); i++)
        {
            std::cout << d[i] << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
