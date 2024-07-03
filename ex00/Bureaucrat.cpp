#include "Bureaucrat.hpp"

// CANONICAL CLASS AForm =======================================================

Bureaucrat::Bureaucrat() : _name(""), _grade(0) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHigh();
	else if (grade > 150)
		throw GradeTooLow();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName())
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->_name;
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
		throw GradeTooHigh();
	}
}

void	Bureaucrat::decreaseGrade()
{
	this->_grade++;
	if (this->_grade > 150)
	{
		this->_grade--;
		throw GradeTooLow();
	}
}


const char*	Bureaucrat::GradeTooHigh::what() const noexcept
{
	return "too high\n";
}

const char*	Bureaucrat::GradeTooLow::what() const noexcept
{
	return "too low\n";
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &x)
{
	o <<  x.getName() << ", bureaucrat grade " << x.getGrade();
	return o;
}

