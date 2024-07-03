#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(false), _signGrade(5), _executeGrade(10) {}

Form::Form(std::string Name, int signGrade, int executeGrade) : _name(Name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
	{
		std::cout << "Form: ";
		throw gradeTooLowException();
	}
	if (signGrade < 1 || executeGrade < 1)
	{
		std::cout << "Form: ";
		throw gradeTooHighException();
	}
	std::cout << _name << " build and filled\n";
}

Form::Form(const Form& other) : _name(other.getName()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	*this = other;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}


Form::~Form()
{
    std::cout << _name << " destroyed\n";
}

const char* Form::gradeTooHighException::what() const noexcept
{
	return "too high\n";
}




std::string    Form::getName() const
{
    return (this->_name);
}

bool    Form::getBool() const
{
    return (this->_signed);
}

int	Form::getSignGrade() const
{
    return (this->_signGrade);
}

int	Form::getExecuteGrade() const
{
    return (this->_executeGrade);
}

const char*	Form::gradeTooLowException::what() const noexcept
{
	return "too low rank\n";
}

void	Form::beSigned(Bureaucrat& bureauC)
{
	if (bureauC.getGrade() > this->getSignGrade())
		throw gradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
	o 	<< "Name: " << f.getName()
		<< "\n" << "signBool: " << f.getBool() 
		<< "\n" << "Excecution Grade: " << f.getExecuteGrade() 
		<< "\n" << "Sign Grade: " << f.getSignGrade() << "\n";
	return (o);
}