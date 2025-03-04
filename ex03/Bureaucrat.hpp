/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:09:18 by code              #+#    #+#             */
/*   Updated: 2024/02/15 19:14:22 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"
# include <memory>
# include "Colors.h"

class AForm;

class Bureaucrat
{
    private:
		const std::string	_name;
		int					_grade;
    public:
	// CANONICAL CLASS AForm
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string	getName() const;
		int 		getGrade() const;
		void		increaseGrade();
		void		decreaseGrade();
		void		SignAForm(AForm& AForm);
		void		executeForm(AForm const & form);

		

		//Exceptions
		class GradeTooHigh : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class GradeTooLow : public std::exception {
			public:
				const char *what() const noexcept override;
		};


};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &x);

#endif
