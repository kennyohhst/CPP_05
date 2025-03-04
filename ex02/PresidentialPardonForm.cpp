#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target(""), _signGrade(145), _executeGrade(137), _type("Presidential Pardon Form") {}

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : _target(Target), _signGrade(145), _executeGrade(137), _type("Presidential Pardon Form") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other),
	_target(other.getName()),
	_signGrade(other.getSignGrade()),
	_executeGrade(other.getExecuteGrade()),
	_type(other.getType())
{
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		// this->_signed = other._signed;
		this->_signature = other._signature;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BBLUE << _target << " has been destroyed" << RESET << "\n";
}

std::string	PresidentialPardonForm::getType() const
{
	return (this->_type);
}


std::string	PresidentialPardonForm::getName() const 
{
	return this->_target;
}

int	PresidentialPardonForm::getSignGrade() const
{
	return this->_signGrade;
}

int	PresidentialPardonForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << BGREEN << this->_target << " has been pardoned by ZaphodBeeblebrox" << RESET << "\n";
}
