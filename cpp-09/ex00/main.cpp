#include "./BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	// 1. read in file with prices
	// 2. read in file with amount of traded bitcoins
	// 3. Check each line for correct format -> date | value
	// 		- valid date format: Year-Month-Day
	// 		- valid value: float or a positive integer between 0 and 1000
	// 4. if correct format, multiply with traded amount
	// 		- if date does not exist in db, find closest date. Use the lower and not the upper one.
	// 5. else throw error that format is invalid

	(void) argc;
	std::ifstream priceFile("data.csv");
    std::ifstream inputFile(argv[1]);

	printResult(priceFile, inputFile);
	
	return 0;
}
