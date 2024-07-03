#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        const std::string   _name;
        bool				_signed;
        const int           _signGrade;
		const int			_executeGrade;
		const std::string	_type;
		std::string			_signature;


    public:
		AForm();
		AForm(std::string Name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = default;
		
		virtual std::string	getType() const;
		virtual std::string getName() const = 0;
		std::string			getSignature();
		bool 				getBool() const;
		int 				getSignGrade() const;
		int					getExecuteGrade() const;
		virtual void 		executeFile(Bureaucrat const & executor) const = 0;
		virtual void 		beSigned(Bureaucrat& BureauC) = 0;

		// beexecuted func (it's just like sign and besigned)
		
		class gradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class gradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class alreadySigned : public std::logic_error {
			public:
				alreadySigned();
				// const char *what() const noexcept override;
		};

};

std::ostream &operator<<(std::ostream &o, AForm const &f);


#endif