/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:28:26 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 10:28:26 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    
public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &copy);
        ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();

        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        virtual void attack(const std::string &target);
};

#endif