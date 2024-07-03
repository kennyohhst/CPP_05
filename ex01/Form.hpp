#ifndef Form_HPP
# define Form_HPP

# include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool				_signed;
        const int           _signGrade;
		const int			_executeGrade;

    public:
		Form();
		Form(std::string Name, int signGrade, int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		
		std::string	getName() const;
		bool		getBool() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		void		beSigned(Bureaucrat& BureauC);
		
		class gradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class gradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif