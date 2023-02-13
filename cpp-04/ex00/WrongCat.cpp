#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructed!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed!" << std::endl;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "Wrong sound!" << std::endl;
}