#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << "Animal constructed!" << std::endl;
	this->type = "undefined";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal constructed with type: " << type << "!" << std::endl;
	this->type = type;
}

Animal::Animal( const Animal& animalOriginal )
{
	std::cout << "Copy operator called for Animal" << std::endl;
	*this = animalOriginal;
}

Animal& Animal::operator=( const Animal &animalOriginal ) {
	std::cout << "Assignment operator called for Animal" << std::endl;
	if (this != &animalOriginal)
		*this = animalOriginal;
	return *this;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructed!" << std::endl;
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal makeSound called!" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->type);
}