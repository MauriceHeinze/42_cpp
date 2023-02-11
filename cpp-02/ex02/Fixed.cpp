#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : fixedPointValue(0)
{
}

Fixed::Fixed( const int n ) : fixedPointValue( n << fractionalBits ) {
}

Fixed::Fixed( const float n ) : fixedPointValue( std::roundf( n * ( 1 << fractionalBits ) ) ) {
}

Fixed::Fixed( const Fixed &fixedNumber ) {
    this->setRawBits( fixedNumber.getRawBits() );
}

Fixed& Fixed::operator=( const Fixed &fixedNumber ) {
    if (this != &fixedNumber)
        this->fixedPointValue = fixedNumber.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

void Fixed::setRawBits( int const newFixedPoint )
{
	this->fixedPointValue = newFixedPoint; 
}

int Fixed::getRawBits( void ) const
{
	return ( this->fixedPointValue );
}

float Fixed::toFloat( void ) const
{
    return ( static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits ) );
}

int Fixed::toInt( void ) const
{
    return ( this->fixedPointValue >> fractionalBits );
}

// outputs fixed number as float to out stream
std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

// =================== ARITMETHIC OPERATORS ===================
Fixed Fixed::operator+( const Fixed &fixedNumber ) {
    return (Fixed(this->toFloat() + fixedNumber.toFloat()));
}

Fixed Fixed::operator-( const Fixed &fixedNumber ) {
    return (Fixed(this->toFloat() - fixedNumber.toFloat()));
}

Fixed Fixed::operator*( const Fixed &fixedNumber ) {
    return (Fixed(this->toFloat() * fixedNumber.toFloat()));
}

Fixed Fixed::operator/( const Fixed &fixedNumber ) {
    return (Fixed(this->toFloat() / fixedNumber.toFloat()));
}

// =================== COMPARISON ===================
// could use toFloat also, but getRawBits is more accurate since no bits are lost due to conversion
bool Fixed::operator>( const Fixed &fixedNumber ) const {
    return ( this->getRawBits() > fixedNumber.getRawBits() );
}

bool Fixed::operator>=( const Fixed &fixedNumber ) const {
    return ( this->getRawBits() >= fixedNumber.getRawBits() );
}

bool Fixed::operator<( const Fixed &fixedNumber ) const {
    return ( this->getRawBits() < fixedNumber.getRawBits() );
}

bool Fixed::operator<=( const Fixed &fixedNumber ) const {
    return ( this->getRawBits() <= fixedNumber.getRawBits() );
}

// =================== INCREMENT && DECREMENT ===================
Fixed& Fixed::operator ++(void)
{
    ++this->fixedPointValue;
    return ( *this );
}

Fixed Fixed::operator ++(int)
{
    Fixed temp( *this );
    temp.fixedPointValue = this->fixedPointValue++; // increments after value was set
    return ( temp );
}

Fixed& Fixed::operator --(void)
{
    --this->fixedPointValue;
    return ( *this );
}

Fixed Fixed::operator --(int)
{
    Fixed temp( *this );
    temp.fixedPointValue = this->fixedPointValue--;
    return ( temp );
}

// =================== MIN && MAX ===================
Fixed& Fixed::min( Fixed &a, Fixed &b )
{
    if (a.toFloat() > b.toFloat())
        return ( b );
    return ( a );
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
    if (a.toFloat() > b.toFloat())
        return ( b );
    return ( a );
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
    if (a.toFloat() < b.toFloat())
        return ( b );
    return ( a );
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
    if (a.toFloat() < b.toFloat())
        return ( b );
    return ( a );
}