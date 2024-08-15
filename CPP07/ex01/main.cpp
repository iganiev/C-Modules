/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:16:04 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 22:16:04 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
    std::cout << "Int array:" << std::endl;
    int tab[] = { 0, 1, 2, 3, 4 };
    ::iter(tab, 5, print<int>);

    std::cout << "Char array:" << std::endl;
    char tab2[] = { 'a', 'b', 'c', 'd', 'e' };
    ::iter(tab2, 5, print<char>);

    std::cout << "String array:" << std::endl;
    std::string tab3[] = { "one", "two", "three", "four", "five" };
    ::iter(tab3, 5, print<std::string>);


    return 0;
}

