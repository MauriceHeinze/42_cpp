#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : fixedPointValue( n << fractionalBits ) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : fixedPointValue( std::roundf( n * ( 1 << fractionalBits ) ) ) {
    std::cout << "Float constructor called" << std::endl;
}

// copies Fixed class instance
Fixed::Fixed( const Fixed &fixedNumber ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(fixedNumber.getRawBits());
}

// defines how to act when = operator is used 
// (if left is not equal to right, assign value and then return)
Fixed& Fixed::operator=( const Fixed &fixedNumber ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixedNumber)
        this->fixedPointValue = fixedNumber.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// defines the position of the fixed point as integer
void Fixed::setRawBits( int const newFixedPoint )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = newFixedPoint; 
}

// returns the position of the fixed point as integer
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

// move fixed point value, cast to float and then return
float Fixed::toFloat( void ) const
{
    return static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits );
}

// just move fixed point back to zero
int Fixed::toInt( void ) const
{
    return this->fixedPointValue >> fractionalBits;
}

// outputs fixed number as float to out stream
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
    o << i.toFloat();
    return (o);
}