#include "Bureaucrat.hpp"
#include "Form.hpp"
// #include <memory>

int main(void)
{
	try {
		Form form("some form", 10, 10);
		Bureaucrat bureauC("Bob", 11);
		// bureauC = std::make_unique<Bureaucrat>("Bob", (115));
		try {
			bureauC.decreaseGrade();
			bureauC.increaseGrade();
		} catch (const std::exception& e)
		{
			std::cerr << e.what();
		}
		std::cout << form;
		bureauC.SignForm(form);
		std::cout << form;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}
