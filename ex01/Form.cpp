/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:52:59 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/27 15:58:14 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() _name("Default"), g_sign(150) g_exec(150)
{
	std::cout << "Constructor for Form " << _name << " called\n";
}

Form::Form(std::string name, int g_sign, int g_exec) _name(name)
{
	_g_sign = g_sign;
	_g_exec = _g_exec;
}

Form::~Form() throw()
{
	std::cout << "Destructor for Form " << _name << " called\n";
}

Form::Form(const Form &other)
{
	*this = other;
	std::cout << "Copy constructor for Form " << _name << " called\n";
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Copy assignment operator for Form " <<_name << " called\n";
	if (*this != other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
		this->_g_sign = other._g_sign;
		this->_g_exec = other._g_exec;
	}
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeSign() const
{
	if (_g_sign < 1)
		throw Form::GradeTooHighException();
	else if (_g_sign > 150)
		throw Form::GradeTooLowException();
	else if (_g_sign >= 1 && _g_sign <= 150)
		return (_g_sign);
}

int Form::getGradeExec() const
{
	if (_g_exec < 1)
		throw Form::GradeTooHighException();
	else if (_g_exec > 150)
		throw Form::GradeTooLowException();
	else if (_g_exec >= 1 && _g_exec <= 150)
		return (_g_exec);
}

void Form::beSigned(Bureaucrat &Bur)
{
	if (_g_sign < 1)
		throw Form::GradeTooHighException();
	else if (Bur.getGrade() <= _g_sign)
		_signed = true;
	else if (Bur.getGrade() > g_sign)
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
	os << Form.getName() << ", Forms grade to sign " << Form.getGradeSign() 
		<< ", Forms grade to execute " << Form.getGradeExec() << ", Form signed:" << Form.getSigned() << "\n";
}
