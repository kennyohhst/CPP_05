#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <memory>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.h"
#include "Intern.hpp"

int main(void)
{

	std::unique_ptr<AForm> s_form = std::make_unique<ShrubberyCreationForm>("Steven");
	std::unique_ptr<AForm> r_form = std::make_unique<RobotomyRequestForm>("peter");
	std::unique_ptr<AForm> p_form = std::make_unique<PresidentialPardonForm>("bob");

	std::unique_ptr<Bureaucrat> William;
	std::unique_ptr<Bureaucrat> bobbie;

	Bureaucrat test;

	Intern bob;

	AForm *form = bob.makeForm("shrubbery creation request", "idk");

	try {
		bobbie = std::make_unique<Bureaucrat>("Bobbie", (1));
		

		William = std::make_unique<Bureaucrat>("William", (150));
		// Bureaucrat test(*William);
		test = *William;
		// test(William);
		// std::cout << CYAN << "s_form test\n" << RESET;
		// bobbie->SignAForm(s_form);
		// William->SignAForm(s_form);
		// test.SignAForm(s_form);
		// William->executeForm(*s_form);
		// test.executeForm(*s_form);
		
		// std::cout << CYAN << "\n\nr_form test\n" << RESET;
		// test.SignAForm(r_form);
		// bobbie->SignAForm(r_form);
		// William->SignAForm(r_form);
		// test.executeForm(*r_form);
		// William->executeForm(*r_form);
		// bobbie->executeForm(*r_form);
		
		// std::cout << CYAN << "\n\np_form test\n" << RESET;
		// test.SignAForm(p_form);
		// William->SignAForm(p_form);
		// test.executeForm(*p_form);
		// William->executeForm(*p_form);


		std::cout << CYAN << "\n\nIntern_form test\n" << RESET;
		// // William->increaseGrade();
		// William->decreaseGrade();

		William->SignAForm(*form);
		William->executeForm(*form);
		William->SignAForm(*form);

		// std::cout << ONWHITE << s_form->getBool() << " signbool" <<  RESET << "\n";
	} catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	delete form;
	return (0);
}
