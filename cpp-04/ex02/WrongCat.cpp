#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructed!" << std::endl;
}

WrongCat::WrongCat( const WrongCat& wrongCatOriginal )
{
	std::cout << "Copy operator called for WrongCat" << std::endl;
	*this = wrongCatOriginal;
}

WrongCat& WrongCat::operator=( const WrongCat &wrongCatOriginal ) {
	std::cout << "Assignment operator called for WrongCat" << std::endl;
	if (this != &wrongCatOriginal)
		*this = wrongCatOriginal;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed!" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Wrong sound!" << std::endl;
}