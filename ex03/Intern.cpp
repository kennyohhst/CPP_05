#include "Intern.hpp"
#include "AForm.hpp"


// CANONICAL CLASS AForm =======================================================

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
		*this = other;
    return (*this);
}

Intern::~Intern() {}

const char*	Intern::wrongFormName::what() const noexcept
{
	return "give better input please\n";
}


AForm	*Intern::s_form(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::r_form(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::p_form(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm* (Intern::*funcptr[3])(std::string) = {&Intern::s_form, &Intern::r_form, &Intern::p_form};
	std::string	arr[4] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};
	int i = 0;

	while (i < 3 && formName != arr[i])
		i++;
	
	switch (i)
		case 3:
			throw wrongFormName();
    return (this->*funcptr[i])(target);
}