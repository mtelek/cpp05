/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:52:39 by mtelek            #+#    #+#             */
/*   Updated: 2025/04/24 19:52:39 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() throw() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile)
        throw FileCreationException();
    try {
        outfile << "          *\n"
                << "         / \\\n"
                << "        / o \\\n"
                << "       /_   _\\\n"
                << "         / \\\n"
                << "        / o \\\n"
                << "       /  O  \\\n"
                << "      /_     _\\\n"
                << "        / \\\n"
                << "       / o \\\n"
                << "      /  O  \\\n"
                << "     /   o   \\\n"
                << "    /_       _\\\n"
                << "       |   |\n"
                << "       |   |\n"
                << "      /     \\\n"
                << "     /       \\\n"
                << "    /         \\\n"
                << "   /___________\\\n"
                << "      |  |  |\n"
                << "      |  |  |\n"
                << "     ~ Merry ~\n"
                << "    ~ Christmas ~\n"
                << "   ~   &  Happy  ~\n"
                << "  ~    New Year   ~\n";
        	
		outfile.close();
        
        if (outfile.fail()) {
            throw FileWriteException();
        }
    } catch (const std::exception& e)
	{
        outfile.close();
        throw;
    }
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return ("Failed to create shrubbery file");
}

const char* ShrubberyCreationForm::FileWriteException::what() const throw()
{
    return ("Failed to write to shrubbery file");
}
