/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:08 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 01:18:32 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Default") , _grade(150)
{
	std::cout << "Constructor for Bureaucrat " << _name << " with a grade of " << _grade << " called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Constructor for Bureaucrat " << _name << " with a grade of " << _grade << " called\n";
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if  (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "Destructor for Bureaucrat " << _name << " with a grade of " << _grade << " called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor for Bureaucrat " << _name << " with a grade of " << _grade << " called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator for Bureaucrat " << _name << " with a grade of " << _grade << " called\n";
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bur)
{
	os << Bur.getName() << ", bureaucrat grade " << Bur.getGrade() << ".\n";
	return (os);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if  (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::gradeIncrement()
{
	std::cout << "Attempting to increment grade to " << getGrade() - 1 << "\n";
	if (getGrade() - 1 < 1)
		throw GradeTooHighException();
	setGrade(getGrade()-1);
}

void  Bureaucrat::gradeDecrement()
{
	std::cout << "Attempting to decrement grade to " << getGrade() + 1 << "\n";
	if (getGrade() + 1 > 150)
		throw GradeTooLowException();
	setGrade(getGrade()+1);
}

//Exception classes inmplementaions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low!");
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
		throw;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << getName() << " couldn't execute " << form.getName()
		          << " because " << e.what() << std::endl;
		throw;
	}
}
