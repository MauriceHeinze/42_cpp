#include "Fixed.hpp"

// constructor inits fixed point value to zero
Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;

}

// copies Fixed class instance
Fixed::Fixed( const Fixed &fixedNumber )
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(fixedNumber.getRawBits());
}

// defines how to act when = operator is used
// (if left is not equal to right, assign value and then return)
Fixed& Fixed::operator=( const Fixed &fixedNumber )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixedNumber)
		this->fixedPointValue = fixedNumber.getRawBits();
	return *this;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// defines the position of the fixed point as integer
void Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

// returns the position of the fixed point as integer
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}