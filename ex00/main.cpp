/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: code <code@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:08:35 by code              #+#    #+#             */
/*   Updated: 2024/03/08 17:00:07 by code             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
