#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( std::ifstream &priceFileName, std::ifstream &amountFileName )
{
	// std::cout << "BitcoinExchange constructed!" << std::endl;
	printResult(priceFileName, amountFileName);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src )
{
	// std::cout << "Copy operator called for BitcoinExchange" << std::endl;
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange &src ) {
	(void) src;
	// std::cout << "Assignment operator called for BitcoinExchange" << std::endl;
	// if (this != &src)
	// 	input = src.input;
	return *this;
}

BitcoinExchange::~BitcoinExchange( void )
{
	// std::cout << "RPN destructed!" << std::endl;
}
bool	BitcoinExchange::checkDate(std::string date)
{
	// std::cout << date << " === " << date.length() << std::endl;
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

	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8));

	if (month < 1 || month > 12)
	{
		if (month % 2 == 0) // Feb, Apr, Jun
		{
			if ((day < 1 || day > 31) && month != 2)
				return (false);
			else if ((day < 1 || day > 28) && month == 2)
				return (false);
		}
		else if (month % 2 == 1) // Jan, Mar, May
		{
			if ((day < 1 || day > 30))
				return (false);
		}
		return (false);
	}

	return (true);
}

bool	BitcoinExchange::checkPrice(std::string price)
{
	double priceDouble = std::stod(price);

	// std::cout << price << "|" << std::endl;
	if (price.length() == 0)
		return (false);
	if (price.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	if (std::count(price.begin(), price.end(), '.') > 1)
		return (false);
	if (std::count(price.begin(), price.end(), '.') > 1)
		return (false);
	if (priceDouble > 1000)
		return (false);
	if (priceDouble < 0)
		return (false);
	return (true);
}

void	BitcoinExchange::createPriceDB( std::ifstream &fileName )
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

float	BitcoinExchange::getExchangerate(std::string date)
{
	date.erase(4, 1);
	date.erase(6, 1);
	int dateInt = std::atoi(date.c_str());
    std::map<int, double>::iterator it = priceDB.lower_bound(dateInt);

    if (it == priceDB.end())
        it--; // the key is greater than all the keys in the map
    else if (it != priceDB.begin() && dateInt - (*(--it)).first < it->first - dateInt)
        it--; // the key is closer to the previous key
	// std::cout << "Test: " << priceDB[it->first] << std::endl;
    return (priceDB[it->first]);
}

bool	BitcoinExchange::errorHandling(std::string date, std::string amount, double exchangeRate)
{
	if (checkDate(date) == false && checkPrice(amount) == false)
	{
		std::cout << "\033[1;31mError:\033[0m bad input! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	else if (checkDate(date) == false)
	{
		std::cout << "\033[1;31mError:\033[0m invalid date! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	else if (checkPrice(amount) == false) // in this case the traded amount
	{
		std::cout << "\033[1;31mError:\033[0m invalid volume! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	else if (exchangeRate > 1000)
	{
		std::cout << "\033[1;31mError:\033[0m too large a number! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	else if (exchangeRate == -1)
	{
		std::cout << "\033[1;31mError:\033[0m no data existing at this point of history yet! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	else if (exchangeRate < 0)
	{
		std::cout << "\033[1;31mError:\033[0m not a positive number.! Input was: #Date " << date << " #amount " << amount << " #exchangeRate " << exchangeRate << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::getTradeVolume( std::ifstream &fileName )
{
	std::string	tmp;
	std::string	date;
	std::string	amount;
	int			delimiter;

	double		exchangeRate;

	while (getline(fileName, tmp))
	{

		delimiter = tmp.find(" | ");
		date = tmp.substr(0, delimiter);
		amount = tmp.substr(delimiter + 3);
		exchangeRate = getExchangerate(date);

		if (errorHandling(date, amount, exchangeRate))
		{
			std::cout.precision(10);
			std::cout << tmp.substr(0, delimiter) << " => " << amount << " = " << exchangeRate << std::endl;
		}
	}
}

void	BitcoinExchange::printResult( std::ifstream &priceFileName, std::ifstream &amountFileName  )
{
	createPriceDB(priceFileName);
	getTradeVolume(amountFileName);
}