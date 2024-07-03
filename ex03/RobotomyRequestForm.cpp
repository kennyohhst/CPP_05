#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target(""), _signGrade(72), _executeGrade(45), _type("Robotomy Request Form") {}

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : _target(Target), _signGrade(72), _executeGrade(45), _type("Robotomy Request Form") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
	AForm(other),
	_target(other.getName()),
	_signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade()),
	_type(other.getType())
{
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_signature = other._signature;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BBLUE << _target << " has been destroyed" << RESET << "\n";
}

std::string	RobotomyRequestForm::getType() const
{
	return (this->_type);
}

std::string	RobotomyRequestForm::getName() const 
{
	return this->_target;
}

int	RobotomyRequestForm::getSignGrade() const
{
	return this->_signGrade;
}

int	RobotomyRequestForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void	RobotomyRequestForm::executeFile(Bureaucrat const &executor) const
{
	if (executor.getGrade() > 45)
		throw gradeTooLowException();
	std::cout << BBLUE << "DRILLDRILLDRILL\n" << RESET;
	std::cout << BBLUE << "DRILLDRILLDRILL\n" << RESET;
	std::cout << BBLUE << "DRILLDRILLDRILL\n" << RESET;
    std::srand(std::time(0)); // seeding the random func
	int i = rand() % 2;
	std::cout << ONIWHITE << i << RESET << std::endl;

	if (i == 1)
		std::cout << BRED << "Robotomy FAILED!" << RESET << "\n";
	else
		std::cout << BGREEN << _target << " has been robotomized successfully!" << RESET << "\n";
}

void	RobotomyRequestForm::beSigned(Bureaucrat& BureauC)
{
	if (BureauC.getGrade() > this->getSignGrade())
		throw gradeTooLowException();
	if (this->_signed == true)
		throw alreadySigned();
	
	this->_signature = BureauC.getName();
	this->_signed = true;
}