/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:31:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/14 09:29:58 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
	/* do some stuff with bureaucrats */
		Bureaucrat b1("Mark", 148);
		Bureaucrat b2("Clark", 3);
		Bureaucrat b3("Lee", 147);
		Bureaucrat b4("Rob", 1);
		
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;	
	
		std::cout << b1.incrementGrade() << std::endl;
		std::cout << b2.incrementGrade() << std::endl;
		std::cout << b3.incrementGrade() << std::endl;
		std::cout << b4.incrementGrade() << std::endl;
	
	
		std::cout << b1.decrementGrade() << std::endl;
		std::cout << b2.decrementGrade() << std::endl;
		std::cout << b3.decrementGrade() << std::endl;
		std::cout << b4.decrementGrade() << std::endl;
	
	}
	catch (std::exception & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}	
	return 0;
}
