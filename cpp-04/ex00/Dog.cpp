#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog constructed!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructed!" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}