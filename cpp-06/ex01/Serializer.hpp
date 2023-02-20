#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef struct Data
{
	std::string	email;
	std::string	password;
} Data;

class Serializer
{
	private:
		const std::string	original;
	public:
		Serializer();
		Serializer( const std::string nbr );
		Serializer( const Serializer &src );
		Serializer& operator=( const Serializer &src );
		~Serializer( void );

		uintptr_t	serialize(Data *ptr);
		Data 		*deserialize(uintptr_t raw);
};

#endif