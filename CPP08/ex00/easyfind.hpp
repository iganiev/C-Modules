/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:50:37 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/22 10:50:37 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>
# include <vector>
# include <string>

template <typename T>
int easyfind(T &a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw std::out_of_range("Value not found!");
    return *it;
}

#endif