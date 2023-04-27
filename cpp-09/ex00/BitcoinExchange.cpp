#include "BitcoinExchange.hpp"

std::map<int, double> priceDB;
std::map<int, double> amountDB;

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
	if (std::count(price.begin(), price.end(), '.') > 1)
		return (false);
	return (true);
}

void	createPriceDB( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	int			dateInt;
	std::string	price;
	int			comma;

	while (getline(fileName, tmp))
	{
		comma = tmp.find(',');
		date = tmp.substr(0, comma);
		price = tmp.substr(comma + 1);

		if (checkDate(date) == false && checkPrice(price) == false)
			priceDB[-1] = -1;
		else if (checkDate(date) == false)
			priceDB[-1] = 0;
		else if (checkPrice(price) == false)
			priceDB[0] = -1;
		else // convert to int, so we can search container properly
		{
			date.erase(4, 1);
			date.erase(6, 1);
			dateInt = std::atoi(date.c_str());
			priceDB[dateInt] = std::stod(price);
		}
	}
	// std::cout << priceDB[20150713] << std::endl;
}

void	createAmountDB( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	int			dateInt;
	std::string	amount;
	int			delimiter;

	while (getline(fileName, tmp))
	{
		delimiter = tmp.find(" | ");
		date = tmp.substr(0, delimiter);
		amount = tmp.substr(delimiter + 3);

		if (checkDate(date) == false && checkPrice(amount) == false)
			amountDB[-1] = -1;
		else if (checkDate(date) == false)
			amountDB[-1] = 0;
		else if (checkPrice(amount) == false) // in this case the traded amount
			amountDB[0] = -1;
		else // convert to int, so we can search container properly
		{
			date.erase(4, 1);
			date.erase(6, 1);
			dateInt = std::atoi(date.c_str());
			amountDB[dateInt] = std::stod(amount);
		}
	}
	// std::cout << amountDB[20150713] << std::endl;
}

float		getExchangerate(int date)
{
    std::map<int, double>::iterator it = priceDB.lower_bound(date);

    if (it == priceDB.end())
        it--; // the key is greater than all the keys in the map
    else if (it != priceDB.begin() && date - (*(--it)).first < it->first - date)
        it--; // the key is closer to the previous key
    return (priceDB[it->first]);
}

void	getTradeVolume( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	int			dateInt;
	std::string	amount;
	int			delimiter;

	double			exchangeRate;

	while (getline(fileName, tmp))
	{

		delimiter = tmp.find(" | ");
		date = tmp.substr(0, delimiter);
		amount = tmp.substr(delimiter + 3);

		if (checkDate(date) == false && checkPrice(amount) == false)
			std::cout << "Error: Invalid date and price!" << std::endl;
		else if (checkDate(date) == false)
			std::cout << "Error: Invalid date!" << std::endl;
		else if (checkPrice(amount) == false) // in this case the traded amount
			std::cout << "Error: Invalid volume!" << std::endl;
		else // convert to int, so we can search container properly
		{
			date.erase(4, 1);
			date.erase(6, 1);
			dateInt = std::atoi(date.c_str());
			exchangeRate = getExchangerate(dateInt);
			std::cout.precision(10);
			// std::cout << "Date: " << tmp.substr(0, delimiter) << " -- exchangeRate: " << exchangeRate << " | amount: " << amount << std::endl;
			// 2011-01-03 => 3 = 0.9
			std::cout << tmp.substr(0, delimiter) << " => " << amount << " = " << exchangeRate << std::endl;
		}
	}
}

void	printResult( std::ifstream &priceFileName, std::ifstream &amountFileName  )
{
	createPriceDB(priceFileName);
	getTradeVolume(amountFileName);
}