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

#include <iostream>
#include <string>

class Zombie {
public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(std::string mane);
private:
    std::string _name;
};

Zombie* zombieHorde( int N, std::string name );
