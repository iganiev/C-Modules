/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:31:57 by iganiev           #+#    #+#             */
/*   Updated: 2024/06/05 22:31:57 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}


RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN& RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}



int RPN::calculate(std::string &str)
{
    std::stack<int> stack;
    std::stringstream ss(str);
    std::string token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Insufficient operands for operator");

            int val2 = stack.top();
            stack.pop();
            int val1 = stack.top();
            stack.pop();
            
            if (token == "+")
                stack.push(val1 + val2);
            else if (token == "-")
                stack.push(val1 - val2);
            else if (token == "*")
                stack.push(val1 * val2);
            else if (token == "/")
            {
                if (val2 == 0)
                    throw std::invalid_argument("Division by zero");
                stack.push(val1 / val2);
            }
        }
        else
        {
            // Check if the token is a valid number
            bool isNumber = true;
            for (size_t i = 0; i < token.size(); ++i)
            {
                if (!std::isdigit(token[i]) && (token[i] != '-' || i != 0))
                {
                    isNumber = false;
                    break;
                }
            }
            if (!isNumber)
                throw std::invalid_argument("Error: " + token);

            stack.push(std::stoi(token));
        }

    }

    if (stack.size() != 1)
        throw std::invalid_argument("Invalid expression");

    return stack.top();
}


RPN::~RPN() {}