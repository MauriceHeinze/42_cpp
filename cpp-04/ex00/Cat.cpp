#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat constructed!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructed!" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}