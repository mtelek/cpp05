/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:27:09 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/24 22:27:09 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm() throw() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::executeAction() const
{

	std::cout << "Drilling noise....\n";
	static bool seeded = false;
    if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
    }	
	int result = std::rand() % 2;
	if (result == 0)
		std::cout << getTarget() << "has been robotimzed succesfully\n";
	else
		throw BadLuckException();
}

const char* RobotomyRequestForm::BadLuckException::what() const throw() {
    return ("Robotomy has failed succesfully");
}
