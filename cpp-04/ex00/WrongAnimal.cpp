#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal constructed!" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal constructed with type: " << type << "!" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed!" << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound called!" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}