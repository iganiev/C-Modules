/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:50 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/13 22:27:50 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
    this->func[0] = &Intern::createShrubberyCreationForm;
    this->func[1] = &Intern::createRobotomyRequestForm;
    this->func[2] = &Intern::createPresidentialPardonForm;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern assignation operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 3; i++)
            this->func[i] = src.func[i];
    }
    return *this;
}

AForm* Intern::createShrubberyCreationForm(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &name, std::string const &target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (!name.compare(forms[i]))
        {
            std::cout << "Intern completed " << forms[i] << " form" << std::endl;
            return ((this->*func[i])(target));
        }
    }
    throw std::invalid_argument("Invalid form name");
}


Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}