#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

void	printResult( std::ifstream &priceFileName, std::ifstream &amountFileName );

class BitcoinExchange
{
	private:
        BitcoinExchange();
		std::map<int, double> priceDB;
        std::map<int, double> amountDB;
	public:
		BitcoinExchange( std::ifstream &priceFileName, std::ifstream &amountFileName );
		BitcoinExchange( const std::string input );
		BitcoinExchange( const BitcoinExchange &src );
		BitcoinExchange& operator=( const BitcoinExchange &src );
		~BitcoinExchange( void );
        bool	checkDate( std::string date );
        bool	checkPrice( std::string price );
        void	createPriceDB( std::ifstream &fileName );
        float	getExchangerate( std::string date );
        bool	errorHandling( std::string date, std::string amount, double exchangeRate );
		void	getTradeVolume( std::ifstream &fileName );
        void	printResult( std::ifstream &priceFileName, std::ifstream &amountFileName );
};

#endif