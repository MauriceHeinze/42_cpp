#include "./BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "\033[1;31mError:\033[0m could not open file." << std::endl;
	else
	{
		std::ifstream priceFile("data.csv");
		std::ifstream inputFile(argv[1]);

		BitcoinExchange exchange(priceFile, inputFile);
	}

	return 0;
}
