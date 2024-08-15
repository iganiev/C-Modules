/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:16:19 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/15 01:16:19 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConvert::ScalarConvert(const ScalarConvert &src)
{
    *this = src;
    std::cout << "Copy constructor called" << std::endl;
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &src)
{
    (void)src;
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}


void ScalarConvert::convert(const std::string &str)
{
    char charVal;
    int intVal;
    float floatVal;
    double doubleVal;

    try 
    {
        charVal = static_cast<char>(std::stoi(str));
        if (std::isprint(charVal) && !std::isdigit(charVal) && !is_pseudo_literal(str))
            std::cout << "char: '" << charVal << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } 
    catch (std::invalid_argument& e)
    {
        std::cerr << "char: impossible" << std::endl;
    }
    catch (std::out_of_range& e)
    {
        std::cerr << "char: impossible" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "char: impossible" << std::endl;
    }
    try
    {
        intVal = std::stoi(str);
        std::cout << "int: " << intVal << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "int: impossible" << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "int: impossible" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "int: impossible" << std::endl;
    }
    try
    {
        floatVal = std::stof(str);
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "float: impossible" << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "float: impossible" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "float: impossible" << std::endl;
    }
    try
    {
        doubleVal = std::stod(str);
        std::cout << "double: " << doubleVal << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "double: impossible" << std::endl;
    } 
    catch (const std::out_of_range& e)
    {
        std::cerr << "double: impossible" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "double: impossible" << std::endl;
    }

}

bool is_pseudo_literal(const std::string str)
{
    if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf" || str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    return false;
}

ScalarConvert::~ScalarConvert()
{
    std::cout << "Destructor called" << std::endl;
}





// void ScalarConvert::convert(const std::string &str)
// {
//         char charVal;
//         int intVal;
//         float floatVal;
//         double doubleVal;
        
//         std::istringstream iss(str);
//         iss >> intVal;
//         if (!iss.fail())
//         {
//             charVal = static_cast<char>(intVal);
//             if (std::isprint(charVal) && !std::isdigit(charVal) && !is_pseudo_literal(str))
//                 std::cout << "char: '" << charVal << "'" << std::endl;
//             else
//                 std::cout << "char: Non displayable" << std::endl;
//             std::cout << "int: " << intVal << std::endl;
//         }
//         else
//         {
//             std::cerr << "char: impossible" << std::endl;
//             std::cerr << "int: impossible" << std::endl;
//         }
        
//         iss.clear();
//         iss.str(str);
//         if (is_pseudo_literal(str))
//             std::cout << "float: " << str << "f" <<std::endl;
//         else
//         {
//             iss >> floatVal;
//             if (!iss.fail())
//                 std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
//             else
//                 std::cerr << "float: impossible" << std::endl;
//         }
        
//         iss.clear();
//         iss.str(str);
//         if (is_pseudo_literal(str))
//             std::cout << "double: " << str << std::endl;
//         else
//         {
//             iss >> doubleVal;
//             if (!iss.fail())
//                 std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
//             else
//                 std::cerr << "double: impossible" << std::endl;
//         }

// }

