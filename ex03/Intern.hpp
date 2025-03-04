#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include <memory>
# include "Colors.h"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;

class Intern
{
	private:
		AForm	*s_form(std::string target);
		AForm	*r_form(std::string target);
		AForm	*p_form(std::string target);
    public:
	// CANONICAL CLASS AForm
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);

		//Exceptions
		class GradeTooHigh : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class GradeTooLow : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class wrongFormName : public std::exception {
			public:
				const char *what() const noexcept override;
		};


};

std::ostream	&operator<<(std::ostream &o, Intern const &x);

#endif
