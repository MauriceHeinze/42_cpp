#include "BitcoinExchange.hpp"

std::map<std::string, float> priceDB;
std::map<std::string, float> amountDB;

// struct tm date;

bool	checkDate(std::string date)
{
	// std::cout << date << "|" << date.length() << std::endl;
	if (date.find_first_not_of("0123456789-") != std::string::npos)
		return (false);
	if (date.substr(0, 4).find_first_not_of("0123456789") != std::string::npos)
		return (false); // year
	if (date.substr(5, 2).find_first_not_of("0123456789") != std::string::npos)
		return (false); // month
	if (date.substr(8).find_first_not_of("0123456789") != std::string::npos)
		return (false); // day
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	return (true);
}

bool	checkPrice(std::string price)
{
	// std::cout << price << "|" << std::endl;
	if (price.length() == 0)
		return (false);
	if (price.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	if (std::count(price.begin(), price.end(), '.') > 1)
		return (false);
	return (true);
}

void	createPriceDB( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	std::string	price;
	int			comma;

	while (getline(fileName, tmp))
	{
		comma = tmp.find(',');
		date = tmp.substr(0, comma);
		price = tmp.substr(comma + 1);

		if (checkDate(date) == false)
			throw (InvalidDate());
		if (checkPrice(price) == false)
			throw (InvalidValue());
		priceDB[date] = std::stof(price);
	}
	std::cout << priceDB["2015-07-13"] << std::endl;
}

void	createAmountDB( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	std::string	amount;
	int			delimiter;

	while (getline(fileName, tmp))
	{
		delimiter = tmp.find(" | ");
		date = tmp.substr(0, delimiter);
		amount = tmp.substr(delimiter + 3);

		if (checkDate(date) == false)
			throw (InvalidDate());
		if (checkPrice(amount) == false) // in this case the traded amount
			throw (InvalidValue());
		amountDB[date] = std::stof(amount);
	}
	std::cout << amountDB["2015-07-13"] << std::endl;
}

// void	printResult( std::ifstream &fileName )
// {
// 	// float	price;
// 	// float	amount;

// 	// run through vector
// 	// find date of input file in price database
// 		// if you can't find it, choose the closest one
// 	// multiply that price with the traded amount
// 	// print it

// 	for (size_t k = 0; k < amountDB.size(); k++)
// 	{
// 		std::cout << amountDB["23"] << std::endl;
// 		// if (std::stof(amount) < 0.0 || std::stof(amount) > 1000.0)
// 		// 	std::cout << "Rate out of range" << std::endl;
// 	}
// }