/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:08 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/25 14:58:41 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    _name = "Default";
    _grade = 150;
    std::cout << "Constructor for Bureaucrat " << _name << "with a grade of " << _grade << " called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
    _name = name;
    if (grade >= 1 && grade <= 150)
        _grade = grade;
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException;
    else if  (grade > 150)
        throw Bureaucrat::GradeTooLowException;
    std::cout << "Constructor for Bureaucrat " << _name << "with a grade of " << _grade << " called\n";
}

Bureaucrat:~Bureaucrat()
{
    std::cout << "Destructor for Bureaucrat " << _name << "with a grade of " << _grade << " called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    std::cout << "Copy constructor for Bureaucrat " << _name << "with a grade of " << _grade << " called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator for Bureaucrat " << _name << "with a grade of " << _grade << " called\n";
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bur)
{
    os << Bur.getName() << ", bureaucrat grade " << Bur.getGrade() << ".\n";
    return (os);
}

int getGrade() const
{
    return (_grade);
}

void setGrade(int grade)
{
    if (grade >= 1 && grade <= 150)
        _grade = grade;
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if  (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string getName() const
{
    return (_name);
}

void setName(std::string name)
{
    _name = name;
}

void Bureaucrat::GradeTooHighException(Bureaucrat &bur) const
{
    std::cout << "Access denied, grade " << bur._grade << " too high\n";
}

void Bureaucrat::GradeTooLowException(Bureaucrat &bur) const
{
    std::cout << "Acces denied, grade " << bur._grade << " too low\n";
}

void Bureaucrat::GradeIncrement(Bureaucrat &bur)
{
    if (bur._grade <= 1)
        throw Bureaucrat::GradeTooHighException(bur):
    else if (_grade >= 152)
        throw Bureaucrat::GradeTooLowException(bur);
    else
        bur._grade--;
}

void Bureaucrat::GradeDecrement(Bureaucrat &bur)
{
    if (bur._grade < 0)
        throw Bureaucrat::GradeTooHighException(bur);
    else if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException(bur);
    else
        bur._grade++;
}
