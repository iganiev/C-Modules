/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:40:59 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/08 23:40:59 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << _name << " constructor called" << std::endl;
}

Form &Form::operator=(Form &copy)
{
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

std::string const &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
    {
        _signed = true;
        return true;
    }
    return false;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    if (form.getGradeToSign() < 1 || form.getGradeToExecute() < 1)
        throw Form::GradeTooHighException();
    if (form.getGradeToSign() > 150 || form.getGradeToExecute() > 150)
        throw Form::GradeTooLowException();
    out << form.getName() << " form is " << (form.getSigned() ? "signed" : "not signed") << std::endl;
    return out;
}

Form::~Form()
{
    std::cout << _name << " destructor called" << std::endl;
}