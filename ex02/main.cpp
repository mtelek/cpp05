/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:14 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 00:24:04 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void printTitle(const std::string& title)
{
	std::cout << "\n" << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

void tryExecute(Bureaucrat& bureaucrat, AForm& form)
{
	std::cout << CYAN << bureaucrat.getName() << " attempts to execute " << form.getName() << RESET << std::endl;
	try
	{
		bureaucrat.executeForm(form);
		std::cout << GREEN << "✓ Execution succeeded." << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "✗ Execution failed: " << e.what() << RESET << std::endl;
	}
}

void trySign(Bureaucrat& bureaucrat, AForm& form)
{
	std::cout << MAGENTA << bureaucrat.getName() << " attempts to sign " << form.getName() << RESET << std::endl;
	try
	{
		form.beSigned(bureaucrat);
		std::cout << GREEN << "✓ Signed successfully." << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << "✗ Signing failed: " << e.what() << RESET << std::endl;
	}
}

int main()
{
	// Bureaucrats
	Bureaucrat highRank("Alice", 1);
	Bureaucrat midRank("Bob", 50);
	Bureaucrat lowRank("Charlie", 150);

	// Forms
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Rick");

	// UNSIGNED EXECUTION TEST
	printTitle("Try to execute unsigned forms");
	tryExecute(highRank, shrubbery);
	tryExecute(highRank, robotomy);
	tryExecute(highRank, pardon);

	// SIGN FORMS
	printTitle("Signing all forms with high-rank bureaucrat");
	trySign(highRank, shrubbery);
	trySign(highRank, robotomy);
	trySign(highRank, pardon);

	// EXECUTE WITH SUFFICIENT GRADE
	printTitle("Executing forms with high-rank bureaucrat");
	tryExecute(highRank, shrubbery);
	tryExecute(highRank, robotomy);
	tryExecute(highRank, pardon);

	// EXECUTE WITH INSUFFICIENT GRADE
	printTitle("Try executing with low-rank bureaucrat (should fail)");
	tryExecute(lowRank, shrubbery);
	tryExecute(lowRank, robotomy);
	tryExecute(lowRank, pardon);

	// TEST ROBOTOMY MULTIPLE TIMES FOR RANDOMNESS
	printTitle("Robotomy randomness test (x5)");
	for (int i = 0; i < 5; ++i) {
		tryExecute(highRank, robotomy);
	}
	return (0);
}
