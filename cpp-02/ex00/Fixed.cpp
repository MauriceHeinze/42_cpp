#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	// Constructor that initializes fixed point value to zero
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixedNumber) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy constructor that copies Fixed class instance
	// this->setRawBits(fixedNumber.getRawBits());
	this->fixedPointValue = fixedNumber.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &fixedNumber) {
	std::cout << "Copy assignment operator called" << std::endl;
	// Copy assignment operator that defines how to act when = operator is used
	// If left is not equal to right, assign value and then return
	if (this != &fixedNumber) {
		this->fixedPointValue = fixedNumber.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	// Destructor that is called when the object is destroyed
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	// Sets the position of the fixed point as integer
	this->fixedPointValue = raw;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	// Returns the position of the fixed point as integer
	return (this->fixedPointValue);
}