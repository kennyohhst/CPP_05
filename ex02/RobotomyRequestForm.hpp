#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>
# include <ctime>
# include "Colors.h"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        const std::string   _target;
        const int           _signGrade;
		const int			_executeGrade;
		const std::string	_type;
    public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string Target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string	getType() const override;
		std::string	getName() const override; 
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		executeFile(Bureaucrat const &executor) const override;
		void		beSigned(Bureaucrat& BureauC) override;

};

#endif