/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:45 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/30 13:13:45 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;

    Zombie* zombiehorde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombiehorde[i].setName(name);
        zombiehorde[i].announce();
    }
    return zombiehorde;
}