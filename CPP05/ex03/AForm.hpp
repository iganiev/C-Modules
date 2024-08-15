/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:22:47 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/09 08:22:47 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

class FormNotSignedException : public std::exception
{
public:
    virtual const char *what() const throw();
};

    AForm();
    AForm(const AForm &copy);
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm &operator=(const AForm &copy);
    virtual ~AForm();

    std::string const &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    bool beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif