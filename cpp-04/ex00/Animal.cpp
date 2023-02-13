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

Animal::~Animal()
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