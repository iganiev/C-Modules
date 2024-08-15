/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:19:07 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 14:19:07 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>


class Base
{
public:
    virtual ~Base() {};
};


class A : public Base {};


class B : public Base {};


class C : public Base {};


Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif