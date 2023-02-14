#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "./Brain.hpp"

class Animal
{
	protected:
		std::string		type;
	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal &Animal );
		Animal& operator=( const Animal &animalOriginal );
		virtual ~Animal( void );

		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;
};

#endif