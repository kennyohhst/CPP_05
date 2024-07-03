#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _signed(false), _signGrade(5), _executeGrade(10), _type(""), _signature("") {}

AForm::AForm(std::string Name, int signGrade, int executeGrade) : _name(Name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade), _type(""), _signature("")
{
	if (signGrade > 150 || executeGrade > 150)
		throw gradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw gradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()), _type(other.getType())
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_signature = other._signature;
	}
	return *this;
}

const char* AForm::gradeTooHighException::what() const noexcept
{
	return "too high\n";
}

AForm::alreadySigned::alreadySigned() : std::logic_error("dude, we don't need your signature, it's already signed by ") {}

std::string	AForm::getSignature()
{
	return (this->_signature);
}

std::string		AForm::getType() const
{
	return (this->_type);
}

std::string    AForm::getName() const
{
    return (this->_name);
}

bool    AForm::getBool() const
{
    return (this->_signed);
}

int	AForm::getSignGrade() const
{
    return (this->_signGrade);
}

int	AForm::getExecuteGrade() const
{
    return (this->_executeGrade);
}

const char*	AForm::gradeTooLowException::what() const noexcept
{
	return "too low rank\n";
}

void	AForm::beSigned(Bureaucrat& bureauC)
{
	if (bureauC.getGrade() > this->getSignGrade())
		throw gradeTooLowException();
	if (this->getBool())
		throw alreadySigned();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, AForm const &f)
{
	o << "Name: " << f.getName() 
	<< "\n" << "signBool: " << f.getBool() 
	<< "\n" << "Excecution Grade: " << f.getExecuteGrade() 
	<< "\n" << "Sign Grade: " << f.getSignGrade() << "\n";
	return (o);
}