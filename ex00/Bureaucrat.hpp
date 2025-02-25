/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:34:11 by mtelek            #+#    #+#             */
/*   Updated: 2025/02/25 14:51:14 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        
        int getGrade() const;
        void setGrade(int grade);
        std::string getName() const;
        void setName(std::string name);

        void GradeTooHighException() const;
        void GradeTooLowException() const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bur);

void GradeIncrement(Bureaucrat &bur);
void GradeDecrement(Bureaucrat &bur);

#endif
