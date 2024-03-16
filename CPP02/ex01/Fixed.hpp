/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:48:28 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/01 03:48:28 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        // Default constructor
        Fixed();

        // Copy constructor
        Fixed(const Fixed &other);

        Fixed(int const val);

        Fixed(float const val);

        // Copy assignment operator
        Fixed &operator=(const Fixed &other);

        // Destructor
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif