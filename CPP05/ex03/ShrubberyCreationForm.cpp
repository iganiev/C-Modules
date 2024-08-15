/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:26:28 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/09 08:26:28 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
    _target = target;
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
    *this = copy;
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    AForm::operator=(src);
    return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file(((_target + "_shrubbery").c_str()));
    if (file.is_open())
    {
        file << "                                  # #### ####" << std::endl;
        file << "                                ### \\/#|### |/####"  << std::endl;
        file << "                               ##\\/#/ \\||/##/_/##/_#"  << std::endl;
        file << "                             ###  \\/###|/ \\/ # ###" << std::endl;
        file << "                           ##_\\_/\\#\\_\\## | #/###_/_####" << std::endl;
        file << "                          ## #### # \\ #| /  #### ##/##"  << std::endl;
        file << "                           __#_--###`  |{,###---###-~" << std::endl;
        file << "                                     \\ }{" << std::endl;
        file << "                                      }}{" << std::endl;
        file << "                                      }}{" << std::endl;
        file << "                                 ejm  {{}" << std::endl;
        file << "                                , -=-~{ .-^- _" << std::endl;
        file << "                                      `}" << std::endl;
        file << "                                       {" << std::endl;
        file.close();
    }
    else
        throw std::runtime_error("Unable to open file");

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}