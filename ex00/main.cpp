#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat x("hi", (2));
		try {
			// x.decreaseGrade();
			x.increaseGrade();
			x.increaseGrade();
			x.increaseGrade();

		} catch (const std::exception& e)
		{
			std::cerr << e.what();
		}

		std::cout << x << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}
