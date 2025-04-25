/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:43:41 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/25 00:43:41 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &formName, const std::string &target);

		static AForm* makeShrubbery(const std::string& target);
        static AForm* makeRobotomy(const std::string& target);
        static AForm* makePresidential(const std::string& target);
};

#endif
