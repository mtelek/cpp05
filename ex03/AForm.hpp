/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:53:06 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/24 23:17:46 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _g_sign;
		const int _g_exec;
		std::string _target;

	public:
		AForm();
		AForm(const std::string name, int g_sign, int g_exec, std::string target);
		virtual ~AForm() throw();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other); 

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(Bureaucrat &Bur);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
			const char* what() const throw();
		};
		class ExecutionTooHigh : public std::exception {
			public:
			const char* what() const throw();
		};
		
		void setTarget(const std::string &target);
		const std::string &getTarget() const;
		virtual void execute(const Bureaucrat& executor) const;
		virtual void executeAction() const = 0;


};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif
