/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:09:18 by code              #+#    #+#             */
/*   Updated: 2024/02/15 19:14:22 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"
# include <memory>

class Form;

class Bureaucrat
{
    private:
		const std::string	_name;
		int					_grade;
    public:
	// CANONICAL CLASS Form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//operator overload "=" is needed
		//because we need to be able
		//to use it outside of the try catch block
		// Bureaucrat& operator=(const Bureaucrat& b_copy);

		std::string getName() const;
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		void SignForm(Form& Form);
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
