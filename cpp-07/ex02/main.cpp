#include "Array.hpp"

int main( void )
{
	std::cout << "\033[32m--------------- Construct ------------------\033[0m" << std::endl;

	unsigned int	i = 0;
	Array< int > intArray( 10 );
	Array< int > intArray2( 5 );

	std::cout << "\033[32m--------------- Setup arrays ---------------\033[0m" << std::endl;
	while ( i < intArray.size())
	{
		intArray[i] = i;
		i++;
	}
	i = 0;
	while ( i < intArray2.size())
	{
		intArray2[i] = i;
		i++;
	}

	std::cout << "Int Array 1: " << intArray << std::endl;
	std::cout << "int Array 2: " << intArray2 << std::endl;

	std::cout << "\033[33m--------------- Switch arrays --------------\033[0m" << std::endl;
	intArray2 = intArray;

	std::cout << "Int Array 1: " << intArray << std::endl;
	std::cout << "int Array 2: " << intArray2 << std::endl;

	std::cout << "\033[35m--------------- Access ---------------------\033[0m" << std::endl;
	try {
		std::cout << "Valid index: " << intArray[5] << std::endl;
		std::cout << "Invalid index: " << intArray2[1000] << std::endl;
	} catch ( Array< int >::OutOfBounds &e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\033[31m--------------- Destruct -------------------\033[0m" << std::endl;

	return ( 0 );
}