#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool				_signed;
        const int           _signGrade;
		const int			_executeGrade;
    public:
		const std::string	_type;
		std::string			_signature;
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
		virtual void 		execute(Bureaucrat const & executor) const = 0;
		void 				beSigned(Bureaucrat& BureauC);
		
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
		};
		class signedOrNot : public std::logic_error {
			public:
				signedOrNot();
		};

};

std::ostream &operator<<(std::ostream &o, AForm const &f);


#endif