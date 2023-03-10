#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat( const Cat& catOriginal )
{
	std::cout << "Copy operator called for Cat" << std::endl;
	*this = catOriginal;
}

Cat& Cat::operator=( const Cat &catOriginal ) {
	std::cout << "Assignment operator called for Cat" << std::endl;
	if (this != &catOriginal)
		*this = catOriginal;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructed!" << std::endl;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow!" << std::endl;
}