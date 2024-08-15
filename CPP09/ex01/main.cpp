/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:31:31 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/05 22:31:31 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        std::string str = av[1];
        std::cout << rpn.calculate(str) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}