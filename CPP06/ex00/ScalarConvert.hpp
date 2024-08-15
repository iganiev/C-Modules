/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:58:16 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/15 00:58:16 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <string>
# include <iomanip>
#include <sstream>
# include <exception>


class ScalarConvert
{
public:
    ScalarConvert();
    ScalarConvert(const ScalarConvert &src);
    ScalarConvert &operator=(const ScalarConvert &src);
    ~ScalarConvert();

    static void convert(const std::string &str);

};

bool is_pseudo_literal(const std::string str);

#endif