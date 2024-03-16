/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:18:33 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/28 19:18:33 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("FREEED");
    heapZombie->announce();
    delete heapZombie;

    randomChump("GOMEER");

    return 0;
}