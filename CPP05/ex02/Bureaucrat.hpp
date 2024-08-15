/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:30:02 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/13 10:39:09 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;


public:
class GradeTooHighException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char *what() const throw();
};

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat &operator=(Bureaucrat const &copy);

	Bureaucrat &incrementGrade();
	Bureaucrat &decrementGrade();
	void signForm(AForm &form);

	void executeForm(AForm const &form);

	
	std::string const &getName() const;
	int getGrade() const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif