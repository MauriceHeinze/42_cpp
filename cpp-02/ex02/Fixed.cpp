#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed( void )
{
	// Set fixed point value to 0
	this->fixedPointValue = 0;
	// Print message to console
	std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed( const int n )
{
	// Convert int to fixed point value by shifting it by fractionalBits
	this->fixedPointValue = n << fractionalBits;
	// Print message to console
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed( const float n )
{
	// Convert float to fixed point value by rounding it to the nearest integer
	// after multiplying it by 2^fractionalBits
	this->fixedPointValue = std::roundf( n * ( 1 << fractionalBits ));
	// Print message to console
	std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed( const Fixed &fixedNumber )
{
	// Set raw bits of the new Fixed object to the raw bits of the existing Fixed object
	this->setRawBits( fixedNumber.getRawBits() );
}

// Assignment operator
Fixed& Fixed::operator=( const Fixed &fixedNumber )
{
	// Check if the objects are different
	if (this != &fixedNumber)
		// Set the fixed point value to the raw bits of the existing Fixed object
		this->fixedPointValue = fixedNumber.getRawBits();
	// Return the new Fixed object
	return *this;
}

// Destructor
Fixed::~Fixed( void )
{
}

// Set raw bits of Fixed object
void Fixed::setRawBits( int const newFixedPoint )
{
	this->fixedPointValue = newFixedPoint;
}

// Get raw bits of Fixed object
int Fixed::getRawBits( void ) const
{
	return ( this->fixedPointValue );
}

// Convert Fixed object to float
float Fixed::toFloat( void ) const
{
	// Convert fixed point value to float by dividing it by 2^fractionalBits
	return ( static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits ) );
}

// Convert Fixed object to int
int Fixed::toInt( void ) const
{
	// Convert fixed point value to int by shifting it to the right by fractionalBits
	return ( this->fixedPointValue >> fractionalBits );
}

// Output Fixed object to out stream as float
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

// =================== ARITMETHIC OPERATORS ===================
// Addition operator
Fixed Fixed::operator+( const Fixed &fixedNumber )
{
	return (Fixed(this->toFloat() + fixedNumber.toFloat()));
}

// Subtraction operator
Fixed Fixed::operator-( const Fixed &fixedNumber )
{
	return (Fixed(this->toFloat() - fixedNumber.toFloat()));
}

// Multiplication operator
Fixed Fixed::operator*( const Fixed &fixedNumber )
{
	return (Fixed(this->toFloat() * fixedNumber.toFloat()));
}

// Division operator
Fixed Fixed::operator/( const Fixed &fixedNumber )
{
	return (Fixed(this->toFloat() / fixedNumber.toFloat()));
}

// =================== COMPARISON ===================
// Greater than operator
bool Fixed::operator>( const Fixed &fixedNumber ) const
{
	return ( this->getRawBits() > fixedNumber.getRawBits() );
}

// Greater than or equal to operator
bool Fixed::operator>=( const Fixed &fixedNumber ) const
{
	return ( this->getRawBits() >= fixedNumber.getRawBits() );
}

bool Fixed::operator<( const Fixed &fixedNumber ) const
{
	// Compare the raw bit value of this object to the raw bit value of the argument object
	return ( this->getRawBits() < fixedNumber.getRawBits() );
}

bool Fixed::operator<=( const Fixed &fixedNumber ) const
{
	// Compare the raw bit value of this object to the raw bit value of the argument object or if they are equal
	return ( this->getRawBits() <= fixedNumber.getRawBits() );
}

// =================== INCREMENT && DECREMENT ===================
Fixed& Fixed::operator ++(void)
{
	// Prefix increment operator: increment the value of the object and return a reference to the object
	++this->fixedPointValue;
	return ( *this );
}

Fixed Fixed::operator ++(int)
{
	// Postfix increment operator: create a temporary object with the same value as this object, increment the value of this object, and return the temporary object
	Fixed temp( *this );
	temp.fixedPointValue = this->fixedPointValue++; // increments after value was set
	return ( temp );
}

Fixed& Fixed::operator --(void)
{
	// Prefix decrement operator: decrement the value of the object and return a reference to the object
	--this->fixedPointValue;
	return ( *this );
}

Fixed Fixed::operator --(int)
{
	// Postfix decrement operator: create a temporary object with the same value as this object, decrement the value of this object, and return the temporary object
	Fixed temp( *this );
	temp.fixedPointValue = this->fixedPointValue--;
	return ( temp );
}

// =================== MIN && MAX ===================
Fixed& Fixed::min( Fixed &a, Fixed &b )
{
	// Return the object with the smaller value
	if (a.toFloat() > b.toFloat())
		return ( b );
	return ( a );
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
	// Return the object with the smaller value (const version)
	if (a.toFloat() > b.toFloat())
		return ( b );
	return ( a );
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
	// Return the object with the larger value
	if (a.toFloat() < b.toFloat())
		return ( b );
	return ( a );
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
	// Return the object with the larger value (const version)
	if (a.toFloat() < b.toFloat())
		return ( b );
	return ( a );
}
