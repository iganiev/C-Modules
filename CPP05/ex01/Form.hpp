/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:35:48 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/08 23:35:48 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;
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

    Form();
    Form(Form &copy);
    Form(std::string const &name, int gradeToSign, int gradeToExecute);
    Form &operator=(Form &copy);
    ~Form();

    std::string const &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    bool beSigned(Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif