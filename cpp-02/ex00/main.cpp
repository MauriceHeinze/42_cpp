#include <iostream>
#include "./Fixed.hpp"

int main( void ) {
	// create instance a of Fixed using the default constructor
	Fixed a;
	// create instance b of Fixed using the copy constructor and pass in a
	Fixed b( a );
	// create instance c of Fixed using the default constructor
	Fixed c;
	// assign the value of b to c using the copy assignment operator
	c = b;
	// print the raw fixed point value of a
	std::cout << a.getRawBits() << std::endl;
	// print the raw fixed point value of b
	std::cout << b.getRawBits() << std::endl;
	// print the raw fixed point value of c
	std::cout << c.getRawBits() << std::endl;
	return 0;
}