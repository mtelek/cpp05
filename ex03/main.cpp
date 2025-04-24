/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:14 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 01:22:39 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main()
{
	std::cout << CYAN << "\n=== INTERN FORM CREATION TESTS ===\n" << RESET;

	Intern someIntern;
	AForm* shrubbery = someIntern.makeForm("ShrubberyCreationForm", "Backyard");
	AForm* robotomy  = someIntern.makeForm("RobotomyRequestForm", "Bender");
	AForm* pardon    = someIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
	AForm* unknown   = someIntern.makeForm("VolcanopSacrificeForm", "Goat");

	std::cout << YELLOW << "\n=== HIGH-GRADE BUREAUCRAT FORM EXECUTION ===\n" << RESET;
	Bureaucrat boss("The Boss", 1);
	if (shrubbery)
	{
		std::cout << MAGENTA << "\n--- ShrubberyCreationForm ---\n" << RESET;
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);
	}
	if (robotomy)
	{
		std::cout << MAGENTA << "\n--- RobotomyRequestForm ---\n" << RESET;
		boss.signForm(*robotomy);
		for (int i = 0; i < 3; ++i) {
			try {
				boss.executeForm(*robotomy);
			} catch (std::exception& e) {
				std::cerr << RED << "[FAILURE] " <<"Exception: " << e.what() << RESET << std::endl;
			}
		}
	}
	if (pardon)
	{
		std::cout << MAGENTA << "\n--- PresidentialPardonForm ---\n" << RESET;
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
	}
	std::cout << YELLOW << "\n=== LOW-GRADE BUREAUCRAT TESTS ===\n" << RESET;
	Bureaucrat intern("Intern Timmy", 150);
	if (shrubbery)
	{
		std::cout << BLUE << "\nTrying to sign with low grade:\n" << RESET;
		try {
			intern.signForm(*shrubbery);
		} catch (const std::exception& e) {
			std::cout << RED << "[FAILURE] " << "Form couldnt be signed by the intern, signing grade too high!" << RESET << "\n";
		}
		std::cout << BLUE << "\nTrying to execute with low grade:\n" << RESET;
		try
		{
			intern.executeForm(*shrubbery);
		}
		catch (std::exception& e)
		{
			std::cerr << RED << "[FAILURE] " << e.what() << RESET << std::endl;
		}
	}
	std::cout << GREEN << "All tests completed.\n" << RESET;
	std::cout << GREEN << "\n=== CLEANUP ===\n" << RESET;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	delete unknown;
	return (0);
}
