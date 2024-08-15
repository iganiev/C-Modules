/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:47:34 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/21 12:47:34 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    data->n = 42;
    data->s1 = "Hello";
    data->s2= "World";

    uintptr_t raw = Serializer::serialize(data);

    std::cout << "Data: " << data << std::endl;
    std::cout << "n: " << data->n << std::endl;
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    std::cout << "Serialized raw: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    
    std::cout << "Deserialized: " << ptr << std::endl;
    std::cout << "n: " << ptr->n << std::endl;
    std::cout << "s1: " << ptr->s1 << std::endl;
    std::cout << "s2: " << ptr->s2 << std::endl;
    
    delete data;
    return 0;
}

