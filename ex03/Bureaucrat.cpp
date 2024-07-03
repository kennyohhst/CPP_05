#include "Bureaucrat.hpp"
#include "AForm.hpp"

// CANONICAL CLASS AForm =======================================================

Bureaucrat::Bureaucrat() {}

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
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

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

const char*	Bureaucrat::GradeTooHigh::what() const noexcept
{
	return "too high\n";
}

const char*	Bureaucrat::GradeTooLow::what() const noexcept
{
	return "too low\n";
}

void	Bureaucrat::SignAForm(AForm& AForm)
{
	try 
	{
		AForm.beSigned(*this);
		if (std::size(this->getName()) > 0)
			std::cout << GREEN << this->getName() << " signed " << AForm.getType() << RESET << std::endl;
		else
			std::cout << MAGENTA << "This guy who has no name for some reason" << " signed " << AForm.getType() << RESET << std::endl;
	}
	catch(const std::logic_error& e)
	{
		if (std::size(AForm.getSignature()) > 0)
			std::cerr << BRED << e.what() << AForm.getSignature() << RESET << "\n";
		else
			std::cerr << BRED << e.what() << "some random chump" << RESET << "\n";

	}
	catch(const std::exception& e)
	{
		if (std::size(this->getName()) > 0)
			std::cerr << RED << this->_name << " couldn't sign " << AForm.getType() << " because the poor pleb has ";
		else
			std::cerr << BRED << "This guy who has no name for some reason" << " couldn't sign " << AForm.getType() << " because the poor pleb has ";
		std::cerr << e.what() << RESET;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getBool() == 0)
	{
		std::cout << BRED << "dude, you need to sign the form, wth are you doing????" << RESET << "\n";
		return ;
	}
	try
	{
		form.executeFile(*this);
		if (std::size(this->getName()) > 0)
			std::cout << BGREEN << this->getName() << " has executed " << form.getType() << RESET << "\n"; 
		else
			std::cout << BGREEN << "this nameless chump has executed " << form.getType() << RESET << "\n"; 
	}
	catch(const std::exception& e)
	{
		if (std::size(this->getName()) > 0)
			std::cerr << BRED << this->getName() << " can't execute " << form.getType() << " because well.. "; 
		else
			std::cerr << BRED << "this nameless chump can't execute " << form.getType() << " because well... "; 
		std::cerr << e.what() << RESET;
	}
}



std::ostream	&operator<<(std::ostream &o, Bureaucrat const &x)
{
	o <<  x.getName() << ", bureaucrat grade " << x.getGrade();
	return (o);
}

