#include "Bureaucrat.hpp"
#include "Form.hpp"

// CANONICAL CLASS Form =======================================================

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) //if u wanna do _name = name on a const, do like this <<< this good, this workie
{
	if (grade < 1)
	{
		std::cout << "Bureaucrat: ";
		throw GradeTooHigh();
	}
	else if (grade > 150)
	{
		std::cout << "Bureaucrat: ";
		throw GradeTooLow();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}


std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::increaseGrade()
{
	this->_grade--;
	if (this->_grade < 1)
	{
		this->_grade++;
		std::cout << "Bureaucrat: ";
		throw GradeTooHigh();
	}	
}

void	Bureaucrat::decreaseGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		this->_grade--;
		std::cout << "Bureaucrat: ";
		throw GradeTooLow();
	}
}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooHigh::what() const noexcept
{
	return "too high\n";
}

const char*	Bureaucrat::GradeTooLow::what() const noexcept
{
	return "too low\n";
}

void	Bureaucrat::SignForm(Form& Form)
{
	try 
	{
		Form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << Form.getName() << " because ";
		std::cout << e.what();
	}
	std::cout << this->getName() << " signed " << Form.getName() << std::endl;
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &x)
{

	o <<  x.getName() << ", bureaucrat grade " << x.getGrade();
	return (o);

}

