/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:53:06 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/27 15:58:19 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form : public GradeTooHighException, public GradeTooLowException
{
	private:
		const std::string _name;
		bool _signed = false;
		const int _g_sign;
		const int _g_exec;

	public:
		Form();
		Form(std::string name, int g_sign, int g_exec);
		~Form() throw();
		Form(const Form &other);
		Form &operator=(const Form &other); 

		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const
		int getGradeExec() const

		void beSigned(Bureaucrat &Bur)

};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif
