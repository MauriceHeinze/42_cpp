#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

void	createPriceDB( std::ifstream &fileName );
void 	createAmountDB( std::ifstream &fileName );
void	printResult( std::ifstream &priceFileName, std::ifstream &amountFileName );

class InvalidDate : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return ("Invalid Date!");
		};
};
class InvalidValue : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return ("Invalid Value!");
		};
};
class BadInput : public std::exception {
	public:
		virtual const char* what() const throw()
		{
			return ("Bad Input!");
		};
};

#endif