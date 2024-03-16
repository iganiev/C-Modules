/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:12:15 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/24 12:12:15 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *makeItLoud(char *msg)
{
    int i;

    i = 0;
    while (msg[i])
    {
        msg[i] = toupper(msg[i]);
        i++;
    }
    return (msg);
}

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else   
    {
        i = 1;
        while (av[i])
        {
            makeItLoud(av[i]);
            std::cout << av[i];
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}