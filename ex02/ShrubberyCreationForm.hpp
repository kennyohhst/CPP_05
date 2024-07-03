#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include "Colors.h"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string   _target;
        const int           _signGrade;
		const int			_executeGrade;
		const std::string	_type;
    public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string Target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string	getName() const override; 
		std::string	getType() const override;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		execute(Bureaucrat const &executor) const override;		
};

#endif