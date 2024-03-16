/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:48:12 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/01 03:48:12 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const val) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = val << this->_fractionalBits;
}

Fixed::Fixed(float const val) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(val *(1 << this->_fractionalBits));

}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat( void ) const {
   return ((float)this->_value / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt( void ) const {
    return (this->_value >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


