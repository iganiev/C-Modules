/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:31:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/14 01:34:18 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{

	std::cout << "******************START****************" << std::endl;
	try
	{
	/* do some stuff with bureaucrats */
/* *********************************************** test 1: ShrubberyCreationForm  ************************************ */

 	Bureaucrat bureaucrat("John", 32);
    ShrubberyCreationForm shrubberyForm("home");
	
	bureaucrat.signForm(shrubberyForm);
    bureaucrat.executeForm(shrubberyForm);
	}
	catch (AForm::GradeTooHighException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "***************************************" << std::endl;

	try
	{
	/* do some stuff with bureaucrats */
/* *********************************************** test 2: RobotomyRequestForm  ************************************ */
	 	Bureaucrat bureaucrat("Mike", 15);
    	RobotomyRequestForm robotomyForm("target");
	
		bureaucrat.signForm(robotomyForm);
    	bureaucrat.executeForm(robotomyForm);	
	}
	catch (AForm::GradeTooHighException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "***************************************" << std::endl;

	try
	{
	/* do some stuff with bureaucrats */
/* *********************************************** test 3: PresidentialPardonForm  ************************************ */
	 	Bureaucrat bureaucrat("Bob", 2);
		PresidentialPardonForm pardonForm("someone");
	
		bureaucrat.signForm(pardonForm);
		bureaucrat.executeForm(pardonForm);
	}
	catch (AForm::GradeTooHighException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
	/* handle exception */
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "******************END****************" << std::endl;
	return 0;
}
