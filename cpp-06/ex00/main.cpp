#include "./ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "Please enter a number or char to convert" << std::endl;
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	return (0);
}
