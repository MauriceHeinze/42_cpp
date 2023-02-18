#include "./ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter nbr(argv[1]);
		std::cout << nbr << std::endl;
	}

	return (0);
}
