/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:11 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/26 21:06:13 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class GradeTooHighException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char *what() const throw();
};

class Bureaucrat : public GradeTooHighException , public GradeTooLowException
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        virtual ~Bureaucrat() throw();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        int getGrade() const;
        void setGrade(int grade);
        std::string getName() const;

        void gradeIncrement();
        void gradeDecrement();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bur);

#endif
