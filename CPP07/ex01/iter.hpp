/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:15:30 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 22:15:30 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void print(T const  &var)
{
    std::cout << var << std::endl;
}

#endif