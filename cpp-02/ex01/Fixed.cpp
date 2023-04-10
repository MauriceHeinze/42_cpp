#include "Fixed.hpp"
#include <cmath>

// constructor inits fixed point value to zero
Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

// constructor to initialize with an int value
Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	// shift the int value to the left by the number of fractional bits
	// and store the result as the fixed point value
	this->fixedPointValue = n << fractionalBits;
}

// constructor to initialize with a float value
Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	// multiply the float value by 2^(fractionalBits)
	// and round the result to the nearest integer
	// store the result as the fixed point value
	this->fixedPointValue = std::roundf( n * ( 1 << fractionalBits ));
}

// copy constructor
Fixed::Fixed( const Fixed &fixedNumber ) : fixedPointValue(0) // inits object
{
	std::cout << "Copy constructor called" << std::endl;
	// copy the object
	*this = fixedNumber;
}

// copy assignment operator
Fixed& Fixed::operator=( const Fixed &fixedNumber )
{
	std::cout << "Copy assignment operator called" << std::endl;
	// check if left operand is not equal to right operand
	if (this != &fixedNumber)
		// assign the fixed point value of the right operand to the fixed point value of the left operand
		this->fixedPointValue = fixedNumber.getRawBits();
	// return the left operand
	return *this;
}

// destructor
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	// print a message indicating that the destructor is called
}

// set the raw bits of the fixed point value
void Fixed::setRawBits( int const newFixedPoint )
{
	this->fixedPointValue = newFixedPoint;
}

// get the raw bits of the fixed point value
int Fixed::getRawBits( void ) const
{
	return (this->fixedPointValue);
}

// convert the fixed point value to a float value
float Fixed::toFloat( void ) const
{
	// cast the fixed point value to a float and divide it by 2^(fractionalBits)
	return static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits );
}

// convert the fixed point value to an integer value
int Fixed::toInt( void ) const
{
	// shift the fixed point value to the right by the number of fractional bits
	return this->fixedPointValue >> fractionalBits;
}

// output the fixed point value as a float to an output stream
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return (o);
}