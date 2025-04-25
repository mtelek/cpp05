/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:52:59 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 14:43:14 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _g_sign(150), _g_exec(150)
{
	std::cout << "Constructor for Form " << _name << " called\n";
}

Form::Form(std::string name, int g_sign, int g_exec) : _name(name), _signed(false), _g_sign(g_sign), _g_exec(g_exec)
{
	if (_g_sign < 1 || _g_exec < 1)
		throw GradeTooHighException();
	if (_g_sign > 150 || _g_exec > 150)
		throw GradeTooLowException();
	std::cout << "Constructor for Form " << _name << " called\n";
}

Form::~Form() throw()
{
	std::cout << "Destructor for Form " << _name << " called\n";
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _g_sign(other._g_sign), _g_exec(other._g_exec)
{
	*this = other;
	std::cout << "Copy constructor for Form " << _name << " called\n";
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Copy assignment operator for Form " <<_name << " called\n";
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

std::string Form::getName() const {
	return (_name); }

bool Form::getSigned() const {
	return (_signed); }

int Form::getGradeSign() const {
	return (_g_sign); }

int Form::getGradeExec() const {
	return (_g_exec); }

void Form::beSigned(Bureaucrat &Bur)
{
	if (Bur.getGrade() > _g_sign)
		throw GradeTooHighException();
	_signed = true;
}


std::ostream &operator<<(std::ostream &os, const Form &Form)
{
	os << Form.getName() << ", Forms grade to sign " << Form.getGradeSign() 
		<< ", Forms grade to execute " << Form.getGradeExec() 
		<< ", Form signed:" << (Form.getSigned() ? "true" : "false");
	return (os);
}

//Exception classes inmplementaions
const char* Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low!");
}
