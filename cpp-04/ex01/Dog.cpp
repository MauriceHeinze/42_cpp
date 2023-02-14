#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog constructed!" << std::endl;
	this->ideas = new Brain();
}

Dog::~Dog( void )
{
	delete this->ideas;
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
	{
		this->type = dogOriginal.type;
		this->ideas = new Brain( *dogOriginal.ideas );
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Woof!" << std::endl;
}