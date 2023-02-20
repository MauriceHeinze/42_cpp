#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	std::cout << "Serializer constructed!" << std::endl;
}

Serializer::Serializer( const Serializer& src )
{
	std::cout << "Copy operator called for Serializer" << std::endl;
	*this = src;
}

Serializer& Serializer::operator=( const Serializer &src ) {
	std::cout << "Assignment operator called for Serializer" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

Serializer::~Serializer( void )
{
	std::cout << "Serializer destructed!" << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data 		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}