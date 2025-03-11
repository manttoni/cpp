#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery_creation", 145, 137, "nobody") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
: AForm(target + "_shrubbery", 145, 137, target) {}

static std::ofstream createFile(const std::string& file)
{
    std::ofstream treeFile(file);
	if (treeFile.is_open() == false)
		throw std::ios_base::failure("Failed to write to file: " + file);
    return treeFile;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream treeFile = createFile(getTarget() + "_shrubbery");

    treeFile << "   🌳         🌲           🌲             🌳" << std::endl;
    treeFile << "  /|\\        /|\\          /|\\          /////\\\\\\" << std::endl;
    treeFile << " / | \\      //|\\\\        //|\\\\       ///  |||  \\\\\\" << std::endl;
    treeFile << "   |       ///|\\\\\\      ///|\\\\\\     ///   |||      \\\\\\" << std::endl;
    treeFile << "             |||       ////|\\\\\\\\  /       |||         \\" << std::endl;
    treeFile << "             |||      /////|\\\\\\\\\\        |||||" << std::endl;
    treeFile << "                          |||            |||||" << std::endl;
    treeFile << "                          |||" << std::endl;

    treeFile.close();
}