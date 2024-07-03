#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target(""), _signGrade(145), _executeGrade(137), _type("Shrubbery Creation Form") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : _target(Target), _signGrade(145), _executeGrade(137), _type("Shrubbery Creation Form") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other),
	_target(other.getName()),
	_signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade()),
	_type(other.getType())
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		// this->_signed = other._signed;
		this->_signature = other._signature;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BBLUE << _target << " has been destroyed" << RESET << "\n";
}

std::string	ShrubberyCreationForm::getType() const
{
	return (this->_type);
}

std::string	ShrubberyCreationForm::getName() const 
{
	return this->_target;
}

int	ShrubberyCreationForm::getSignGrade() const
{
	return this->_signGrade;
}

int	ShrubberyCreationForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file;
	std::string nameOfFile = this->_target;

	nameOfFile.append("_shrubbery");

	file.open(nameOfFile);

	file << "             ,@@@@@@@,\n";
	file << "     ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << " `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "     |o|        | |         | |\n";
	file << "     |.|        | |         | |\n";
	file << " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	file.close();
}