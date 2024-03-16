/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:08:37 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/28 21:08:37 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;
private:
    std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
