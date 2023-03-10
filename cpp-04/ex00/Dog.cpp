#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog constructed!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructed!" << std::endl;
}

Dog::Dog( const Dog& dogOriginal )
{
	std::cout << "Copy operator called for Dog" << std::endl;
	*this = dogOriginal;
}

Dog& Dog::operator=( const Dog &dogOriginal ) {
	std::cout << "Assignment operator called for Dog" << std::endl;
	if (this != &dogOriginal)
		*this = dogOriginal;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}