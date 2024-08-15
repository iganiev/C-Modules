/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:31:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/14 02:11:27 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	std::cout << "******************START****************" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		Bureaucrat bureaucrat("Mike", 15);
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	catch (AForm::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "***************************************" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		Bureaucrat bureaucrat("John", 2);
		bureaucrat.signForm(*ppf);
		bureaucrat.executeForm(*ppf);
		delete ppf;
	}
		catch (AForm::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "***************************************" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *scf << std::endl;
		Bureaucrat bureaucrat("John", 2);
		bureaucrat.signForm(*scf);
		bureaucrat.executeForm(*scf);
		delete scf;
	}
	catch (AForm::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "***************************************" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery", "Bender");
		if (scf)
			std::cout << *scf << std::endl;
		else
			throw std::runtime_error("Form not found");
	}
	catch (AForm::GradeTooHighException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (AForm::FormNotSignedException & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "******************END****************" << std::endl;
	return 0;
}
