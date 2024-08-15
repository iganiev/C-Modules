/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:22:35 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/09 08:22:35 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << name << " constructor called" << std::endl;
}

AForm &AForm::operator=( const AForm &copy)
{
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

std::string const &AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
    {
        _signed = true;
        return true;
    }
    return false;
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}



std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    if (form.getGradeToSign() < 1 || form.getGradeToExecute() < 1)
        throw AForm::GradeTooHighException();
    if (form.getGradeToSign() > 150 || form.getGradeToExecute() > 150)
        throw AForm::GradeTooLowException();
    out << form.getName() << " form is " << (form.getSigned() ? "signed" : "not signed") << std::endl;
    return out;
}

AForm::~AForm()
{
    std::cout << _name << " destructor called" << std::endl;
}