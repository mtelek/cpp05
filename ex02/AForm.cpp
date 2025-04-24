/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:52:59 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 00:24:26 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _g_sign(150), _g_exec(150), _target("Default")
{
	std::cout << "Constructor for AForm " << _name << " called\n";
}

AForm::AForm(std::string name, int g_sign, int g_exec, std::string target) : _name(name), _signed(false), _g_sign(g_sign), _g_exec(g_exec), _target(target)
{
	if (_g_sign < 1 || _g_exec < 1)
		throw GradeTooHighException();
	if (_g_sign > 150 || _g_exec > 150)
		throw GradeTooLowException();
	std::cout << "Constructor for AForm " << _name << " called\n";
}

AForm::~AForm() throw()
{
	std::cout << "Destructor for AForm " << _name << " called\n";
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _g_sign(other._g_sign), _g_exec(other._g_exec), _target(other._target)
{
	*this = other;
	std::cout << "Copy constructor for AForm " << _name << " called\n";
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "Copy assignment operator for AForm " <<_name << " called\n";
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_target = other._target;
	}
	return (*this);
}

std::string AForm::getName() const {
	return (_name); }

bool AForm::getSigned() const {
	return (_signed); }

int AForm::getGradeSign() const {
	return (_g_sign); }

int AForm::getGradeExec() const {
	return (_g_exec); }

void AForm::beSigned(Bureaucrat &Bur)
{
	if (Bur.getGrade() > _g_sign)
		throw GradeTooHighException();
	_signed = true;
}


std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.getName() << ", AForms grade to sign " << AForm.getGradeSign() 
		<< ", AForms grade to execute " << AForm.getGradeExec() 
		<< ", AForm signed:" << (AForm.getSigned() ? "true" : "false")
		<< ", Target: " << AForm.getTarget() << "\n";
	return (os);
}

//Exception classes inmplementaions
const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form was not signed, it cannot be executed");
}

const char* AForm::ExecutionTooHigh::what() const throw()
{
	return ("Form cannot be executed, execution grade too high!");
}

const std::string& AForm::getTarget() const {
    return _target;
}


void AForm::setTarget(const std::string& target) {
    _target = target;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeExec())
		throw ExecutionTooHigh();
	executeAction();
}
