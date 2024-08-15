/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganiev <iganiev@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:27:34 by iganiev           #+#    #+#             */
/*   Updated: 2024/05/13 22:27:34 by iganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
private:
    AForm* (Intern::*func[3])(std::string const &target);

    AForm* createShrubberyCreationForm(std::string const &target);
    AForm* createRobotomyRequestForm(std::string const &target);
    AForm* createPresidentialPardonForm(std::string const &target);

public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &src);
    ~Intern();

    AForm* makeForm(std::string const &name, std::string const &target);
};

#endif