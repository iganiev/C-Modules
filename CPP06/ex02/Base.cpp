/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:20:16 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 14:20:16 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate()
{
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0)
    {
        std::cout << "A class generated" << std::endl;
        return new A;
    }
    else if (random == 1)
    {
        std::cout << "B class generated" << std::endl;
        return new B;
    }
    else if (random == 2)
    {
        std::cout << "C class generated" << std::endl;
        return new C;
    }
    else
    {
        std::cout << "Unknown class generated" << std::endl;
        return NULL;
    }
}

void identify(Base *p)
{
    const char *type = NULL;
    if (dynamic_cast<A*>(p))
        type = "A";
    else if (dynamic_cast<B*>(p))
        type = "B";
    else if (dynamic_cast<C*>(p))
        type = "C";
    else
        type = "Unknown";
    std::cout << "Pointer identified as " << type << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Reference identified as A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}

    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Reference identified as B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}

    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Reference identified as C" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}

    std::cout << "Reference identified as Unknown" << std::endl;
}