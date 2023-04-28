#include "./RPN.hpp"

// ./RPN "0 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + + + + + + + +"
// // should output 45

// ./RPN "3 2 1 * +"
// // should output 5

// ./RPN "1 2 + 3 4 + *"
// // should output 21

// ./RPN "2 2 * 2 * 2 *"
// // should output 16

// ./RPN "5 5 5 5 5 + + + +"
// // should output 30

// ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// // should output 42

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "\033[1;31mError:\033[0m no inverted Polish mathematical expression provided." << std::endl;
	else
	{
		RPN calculator(argv[1]);
		calculator.executeRNP();
	}
	return 0;
}
