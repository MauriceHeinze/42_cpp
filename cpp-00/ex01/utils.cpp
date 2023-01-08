//
// Created by Maurice Heinze on 1/7/23.
//

#include "./phonebook.hpp"

std::string	get_input()
{
	int			i;
	int			char_found;
	std::string	input;

	i = 0;
	char_found = 0;
	std::getline(std::cin, input);
	while (input[i] && (char_found == 0))
	{
		if (input[i] > 32 && input[i++] < 127)
			char_found = 1;
	}
	if (char_found == 0)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter something: ";
		return (get_input());
	}

	return (input);
}

std::string	get_input_phone()
{
	int			i;
	int			non_digit;
	std::string	input;

	i = 0;
	non_digit = 0;
	std::getline(std::cin, input);
	while (input[i] && (non_digit == 0))
	{
		if (input[i] < 47 || input[i++] > 58)
			non_digit = 1;
	}
	if (input.length() == 0)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter a phone number: ";
		return (get_input_phone());
	}
	else if (non_digit == 1)
	{
		std::cout << "\033[31m" << "Error! " << "\033[0m" << "Please enter digits only: ";
		return (get_input_phone());
	}

	return (input);
}