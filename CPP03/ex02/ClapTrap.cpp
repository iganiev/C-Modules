/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:28:09 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 10:28:09 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0){
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) 
        : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
    std::cout << "ClapTrap extended constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    this->_name = copy._name;
    this->_hitPoints = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    std::cout << "Copy assigment operator called" << std::endl;

    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "Claptrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                  << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    } 
    else
        std::cout << "ClapTrap " << _name << " can't attack. No hit points or energy left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        _hitPoints = (amount > _hitPoints) ? 0 : _hitPoints - amount;
    }
    else
        std::cout << "ClapTrap " << _name << " is already out of hit points. Can't take damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
        _hitPoints += amount;
        _energyPoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " can't be repaired. No hit points or energy left." << std::endl;
}