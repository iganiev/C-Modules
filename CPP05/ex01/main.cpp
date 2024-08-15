/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:31:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/14 09:31:05 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
	/* do some stuff with bureaucrats */
		Bureaucrat b1;
		Bureaucrat b2("Mark", 148);
		Bureaucrat b3("Clark", 3);
		Bureaucrat b4("Lee", 147);

		Form f1("Form1", 150, 140);
		Form f2("Form2", 1, 1);
		Form f3("Form3", 150, 1);

/* *********************************************** test 1 ************************************ */

		std::cout << "------------------- test 1 -------------------" << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		
	
		b2.signForm(f2);
		b3.signForm(f3);
		b4.signForm(f1);


/* *********************************************** test 2 ************************************ */

		std::cout << "------------------- test 2 -------------------" << std::endl;
		
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		
		std::cout << b1.incrementGrade() << std::endl;
		std::cout << b2.incrementGrade() << std::endl;
		std::cout << b3.incrementGrade() << std::endl;
		std::cout << b4.incrementGrade() << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
	
		b2.signForm(f2);
		b3.signForm(f3);
		b4.signForm(f1);

	
/* *********************************************** test 3 ************************************ */

		std::cout << "------------------- test 3 -------------------" << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	
		std::cout << b1.decrementGrade() << std::endl;
		std::cout << b2.decrementGrade() << std::endl;
		std::cout << b3.decrementGrade() << std::endl;
		std::cout << b4.decrementGrade() << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
	
		b2.signForm(f2);
		b3.signForm(f3);
		b4.signForm(f1);
	
	}
	catch (Form::GradeTooHighException & e)
	{
	/* handle exception */
		std::cerr << "Error1: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
	/* handle exception */
		std::cerr << "Error2: " << e.what() << std::endl;
	}	
	catch (Bureaucrat::GradeTooHighException & e)
	{
	/* handle exception */
		std::cerr << "Error3: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
	/* handle exception */
		std::cerr << "Error4: " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
	/* handle exception */
		std::cerr << "Default Error: " << e.what() << std::endl;
	}
	
	return 0;
}
