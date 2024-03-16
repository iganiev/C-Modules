/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:28:49 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/30 18:28:49 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon:: Weapon(const std::string &type) : _type(type) {}
Weapon::~Weapon(){}

std::string Weapon::getType() const {
    return (this->_type);
}

void Weapon::setType(std::string type) {
    this->_type = type;
}