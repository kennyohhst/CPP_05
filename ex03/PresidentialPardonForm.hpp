#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include "Colors.h"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        const std::string   _target;
        const int           _signGrade;
		const int			_executeGrade;
		const std::string	_type;

    public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string Target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string	getType() const override;
		std::string	getName() const override; 
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		executeFile(Bureaucrat const & executor) const override;
		void		beSigned(Bureaucrat& BureauC) override;


};



#endif