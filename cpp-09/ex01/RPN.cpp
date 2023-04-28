#include "RPN.hpp"

RPN::RPN(std::string input) : input(input)
{
	// std::cout << "RPN constructed!" << std::endl;
}

RPN::RPN( const RPN& src )
{
	// std::cout << "Copy operator called for RPN" << std::endl;
	*this = src;
}

RPN& RPN::operator=( const RPN &src ) {
	// std::cout << "Assignment operator called for RPN" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

RPN::~RPN( void )
{
	// std::cout << "RPN destructed!" << std::endl;
}

void RPN::executeRNP( void )
{
	int result = 0;

	// std::cout << input << std::endl;
    for (size_t i = 0; i < input.length(); i++) 
	{
        // std::cout << input[i] << " ";
		char c = input[i];

		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			// check if enough numbers are available
			if (numbers.size() != 2)
			{
				std::cout << "\033[1;31mError:\033[0m no valid Polish mathematical expression provided." << std::endl;
				return ;
			}
			int a = numbers.top();
			numbers.pop();
			int b = numbers.top();
			// std::cout << b << std::endl;
			numbers.pop();
			if (c == '+')
				result = a + b;
			else if (c == '-')
				result = a - b;
			else if (c == '*')
				result = a * b;
			else if (c == '/')
				result = a / b;
			numbers.push(result);
			// std::cout << result << std::endl;
			// do operation

		}
		else if (c >= 48 && c <= 57) // add number to stack
		{
			int nbr = std::stoi(input.substr(i, 1));
			numbers.push(nbr);
		}
		else if (c == ' ' || c == '\t')
			continue;
		else
		{
			std::cout << "\033[1;31mError:\033[0m no valid Polish mathematical expression provided." << std::endl;
			return ;
		}
	}
	std::cout << result << std::endl;

	// iterate over string
	// when you find operator, do something
	// when you find number, do something else

}