/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:11 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/24 23:23:44 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
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

		void signForm(AForm &form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void executeForm(AForm const& form) const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bur);

#endif
