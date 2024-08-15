/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:53:27 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/05 10:53:27 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;

    try
    {
        btcExchange.loadExchangeRates("data.csv");
    } 
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    btcExchange.calculateExchange(av[1]);

    return 0;
}