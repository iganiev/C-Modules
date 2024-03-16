/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:12 by iganiev           #+#    #+#             */
/*   Updated: 2024/01/31 14:04:12 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void) {
        std::cout << "HARL: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    }

void Harl::info(void) {
    std::cout << "HARL: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "HARL: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "HARL: This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
	std::string announce[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    ComplaintFunction ft_complain = NULL;

    for (int i = 0; i < 4; i++)
	{
        if (level == announce[i])
		{
            switch(i)
			{
                case 0:
                    ft_complain = &Harl::debug;
                    break;
                case 1:
                    ft_complain = &Harl::info;
                    break;
                case 2:
                    ft_complain = &Harl::warning;
                    break;
                case 3:
                    ft_complain = &Harl::error;
                    break;
            }
            (this->*ft_complain)();
            return;
        }
	}
}
