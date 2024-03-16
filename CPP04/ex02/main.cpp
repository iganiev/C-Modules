/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:40:44 by iganiev           #+#    #+#             */
/*   Updated: 2024/02/05 23:40:44 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	Animal* animal[2];

	for (int i = 0; i < 2; i++)
	{
		if (i >= 1)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 2; i++)
	{
		animal[i]->getType();
		animal[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 2; i++)
	{
		delete animal[i];
	}
	std::cout << std::endl;

	return 0;
}
