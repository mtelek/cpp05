/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:43:33 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 00:43:33 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) {
    return (*this); }

AForm* Intern::makeShrubbery(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (*formCreators[3])(const std::string&) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (formCreators[i](target));
        }
    }
    std::cerr << "Intern: Error! Unknown form name '" << formName << "'\n";
    return (0);
}
