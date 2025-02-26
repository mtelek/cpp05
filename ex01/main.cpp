/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:14 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/26 21:52:38 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main()
{
	// Test valid Bureaucrat creation
	std::cout << CYAN << "=== Valid Bureaucrat Creation ===" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1); // Grade 1 (Highest)
		std::cout << bob << std::endl;

		Bureaucrat jane("Jane", 100); // Grade 100
		std::cout << jane << std::endl;

		Bureaucrat alice("Alice", 150); // Grade 150 (Lowest)
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	// Test invalid Bureaucrat creation (too high grade)
	std::cout << YELLOW << "=== Invalid Bureaucrat Creation (Too High) ===" << RESET << std::endl;
	try
	{
		Bureaucrat highGrade("HighGrade", 0); // Invalid grade (Too high)
	}
	catch (const GradeTooHighException &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET;	
	}
	std::cout << std::endl;
	// Test invalid Bureaucrat creation (too low grade)
	std::cout << YELLOW << "=== Invalid Bureaucrat Creation (Too Low) ===" << RESET << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 151); // Invalid grade (Too low)
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET;
	}
	std::cout << std::endl;
	// Test grade increment and decrement
	std::cout << BLUE << "=== Grade Increment and Decrement ===" << RESET << std::endl;
	try
	{
		Bureaucrat testBureaucrat("Test", 50); // Starting with grade 50
		std::cout << testBureaucrat << std::endl;

		testBureaucrat.gradeIncrement(); // Should become grade 49
		std::cout << "After Increment: " << testBureaucrat << std::endl;

		testBureaucrat.gradeDecrement(); // Should become grade 50 again
		std::cout << "After Decrement: " << testBureaucrat << std::endl;

		testBureaucrat.gradeDecrement(); // Should become grade 51
		std::cout << "After Another Decrement: " << testBureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	// Test Exception handling for invalid grade modification
	std::cout << MAGENTA << "=== Exception Handling for Grade Modification ===" << RESET << std::endl;
	try
	{
		Bureaucrat extreme("Extreme", 1); // Grade 1 (Highest)
		std::cout << extreme << std::endl;
		extreme.gradeIncrement(); // This will throw GradeTooHighException
	}
	catch (const GradeTooHighException &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET;
	}
	try
	{
		Bureaucrat extremeLow("ExtremeLow", 150); // Grade 150 (Lowest)
		std::cout << extremeLow << std::endl;
		extremeLow.gradeDecrement(); // This will throw GradeTooLowException
	}
	catch (const GradeTooLowException &e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET;
	}
	return (0);
}
