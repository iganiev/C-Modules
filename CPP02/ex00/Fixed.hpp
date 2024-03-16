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

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;

    public:
        // Default constructor
        Fixed();

        // Copy constructor
        Fixed(const Fixed &other);

        // Copy assignment operator
        Fixed &operator=(const Fixed &other);

        // Destructor
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif