/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:34:24 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 22:34:24 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T>
class Array
{
    private:
        T *array;
        size_t length;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        ~Array();

        Array &operator=(Array const &src);
        T &operator[](size_t i);

        size_t size() const;
};

#endif