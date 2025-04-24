/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:14 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/24 17:20:28 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include "Form.hpp"
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void print_test_header(const std::string& title)
{
	std::cout << MAGENTA << "\n===== " << title << " =====" << RESET << "\n";
}

void print_success(const std::string& message)
{
	std::cout << GREEN << "[SUCCESS] " << message << RESET << "\n";
}

void print_failure(const std::string& message)
{
	std::cout << RED << "[FAILURE] " << message << RESET << "\n";
}

void print_info(const std::string& message)
{
	std::cout << BLUE << "[INFO] " << message << RESET << "\n";
}

void print_warning(const std::string& message)
{
	std::cout << YELLOW << "[WARNING] " << message << RESET << "\n";
}

void check_signed(Form &form)
{
	std::cout << std::boolalpha << "Form has been signed: " << form.getSigned() << "\n";
}

void test_form_creation()
{
	print_test_header("FORM CREATION TESTS");

	try {
		print_info("Creating form with valid grades (50, 50)");
		Form form1("Standard Form", 50, 50);
		print_success("Form created successfully: " + form1.getName());
	} catch (const std::exception& e) {
		print_failure(e.what());
	}

	try {
		print_info("Creating form with too high sign grade (0)");
		Form form2("High Grade Form", 0, 50);
		print_failure("Should have thrown exception");
	} catch (const std::exception& e) {
		print_success(std::string("Caught expected exception: ") + e.what());
	}

	try {
		print_info("Creating form with too low exec grade (151)");
		Form form3("Low Grade Form", 50, 151);
		print_failure("Should have thrown exception");
	} catch (const std::exception& e) {
		print_success(std::string("Caught expected exception: ") + e.what());
	}
}

void test_signing_scenarios()
{
	print_test_header("FORM SIGNING SCENARIOS");

	Bureaucrat lowGradeBob("Low Grade Bob", 100);
	Bureaucrat midGradeAlice("Mid Grade Alice", 50);
	Bureaucrat highGradeEve("High Grade Eve", 1);

	Form easyForm("Easy Form", 100, 100); 
	Form mediumForm("Medium Form", 50, 50);
	Form hardForm("Hard Form", 1, 1);

	print_info("Testing Easy Form (grade 100 to sign)");
	try {
		lowGradeBob.signForm(easyForm);
		print_success("Bob signed the form successfully");
	} catch (const std::exception& e) {
		print_failure(e.what());
	}
	check_signed(easyForm);

	print_info("Testing Medium Form (grade 50 to sign)");
	try {
		lowGradeBob.signForm(mediumForm);
		print_failure("Bob shouldn't be able to sign this");
	} catch (const std::exception& e) {
		print_success(std::string("Correctly prevented signing: ") + e.what());
	}
	check_signed(mediumForm);

	try {
		midGradeAlice.signForm(mediumForm);
		print_success("Alice signed the form successfully");
	} catch (const std::exception& e) {
		print_failure(e.what());
	}
	check_signed(mediumForm);

	print_info("Testing Hard Form (grade 1 to sign)");
	try {
		midGradeAlice.signForm(hardForm);
		print_failure("Alice shouldnt be able to sign this");
	} catch (const std::exception& e) {
		print_success(std::string("Correctly prevented signing: ") + e.what());

	}
	check_signed(hardForm);
	
	try {
		highGradeEve.signForm(hardForm);
		print_success("Eve signed the form successfully");
	} catch (const std::exception& e) {
		print_failure(e.what());
	}
	check_signed(hardForm);

	print_info("Testing signing an already signed form");
	try {
		highGradeEve.signForm(easyForm);
		print_warning("No error when signing already signed form (expected behavior)");
	} catch (const std::exception& e) {
		print_failure(std::string("Unexpected error: ") + e.what());
	}
	check_signed(easyForm);
	
}

int main()
{
	test_form_creation();
	test_signing_scenarios();

	return (0);
}
