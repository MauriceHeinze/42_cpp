#include "./RPN.hpp"

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
