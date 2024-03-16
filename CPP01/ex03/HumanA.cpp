/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:45:40 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/30 18:45:40 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA(){};

void HumanA::attack() const {
    if (&_weapon)
        std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
    else
        std::cout << _name << " does not have weapon" << std::endl;
}