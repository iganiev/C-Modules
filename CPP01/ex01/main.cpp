/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:29:19 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/30 10:29:19 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie* zombiehorde = zombieHorde(N, "Moar Zombie");
    if (!zombiehorde)
        return (1);
    delete [] zombiehorde;
    return 0;
}