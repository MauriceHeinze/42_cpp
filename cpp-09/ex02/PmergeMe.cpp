#include "PmergeMe.hpp"

// PmergeMe::PmergeMe(std::string input) : input(input)
// {
// 	// std::cout << "PmergeMe constructed!" << std::endl;
// }

// PmergeMe::PmergeMe( const PmergeMe& src )
// {
// 	// std::cout << "Copy operator called for PmergeMe" << std::endl;
// 	*this = src;
// }

// PmergeMe& PmergeMe::operator=( const PmergeMe &src ) {
// 	// std::cout << "Assignment operator called for PmergeMe" << std::endl;
// 	if (this != &src)
// 		input = src.input;
// 	return *this;
// }

// PmergeMe::~PmergeMe( void )
// {
// 	// std::cout << "PmergeMe destructed!" << std::endl;
// }

// void PmergeMe::executeRNP( void )
// {
// 	int result = 0;

//     for (size_t i = 0; i < input.length(); i++) 
// 	{
// 		char c = input[i];

// 		if (c == '+' || c == '-' || c == '*' || c == '/')
// 		{
// 			if (numbers.size() < 2)
// 			{
// 				std::cout << "\033[1;31mError:\033[0m no valid Polish mathematical expression provided." << std::endl;
// 				return ;
// 			}
// 			int b = numbers.top();
// 			numbers.pop();
// 			int a = numbers.top();
// 			numbers.pop();
// 			if (c == '+')
// 				result = a + b;
// 			else if (c == '-')
// 				result = a - b;
// 			else if (c == '*')
// 				result = a * b;
// 			else if (c == '/')
// 				result = a / b;
// 			numbers.push(result);
// 		}
// 		else if (c >= 48 && c <= 57) // add number to stack
// 		{
// 			int nbr = std::stoi(input.substr(i, 1));
// 			numbers.push(nbr);
// 		}
// 		else if (c == ' ' || c == '\t')
// 			continue;
// 		else
// 		{
// 			std::cout << "\033[1;31mError:\033[0m no valid Polish mathematical expression provided." << std::endl;
// 			return ;
// 		}
// 	}
// 	std::cout << result << std::endl;
// }