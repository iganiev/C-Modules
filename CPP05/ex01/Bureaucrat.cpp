/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:30:23 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/09 09:04:23 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	std::cout << _name << " constructor called" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if (this != &copy)
		_grade = copy._grade;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (bureaucrat.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	out << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << std::endl;
	return out;
}

Bureaucrat &Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	return *this;
}

Bureaucrat &Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return *this;
}



std::string const &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::signForm(Form &form)
{
	if (_grade <= form.getGradeToSign() && _grade <= form.getGradeToExecute())
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	else
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
	}
}



const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " destructor called" << std::endl;
}