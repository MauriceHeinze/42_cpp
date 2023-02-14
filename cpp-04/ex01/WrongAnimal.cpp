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

WrongAnimal::WrongAnimal( const WrongAnimal& wrongAnimalOriginal )
{
	std::cout << "Copy operator called for WrongAnimal" << std::endl;
	*this = wrongAnimalOriginal;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &wrongAnimalOriginal ) {
	std::cout << "Assignment operator called for WrongAnimal" << std::endl;
	if (this != &wrongAnimalOriginal)
		*this = wrongAnimalOriginal;
	return *this;
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