#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string		type;
	public:
		WrongAnimal( void );
		WrongAnimal(std::string type);
		WrongAnimal( const WrongAnimal &WrongAnimal );
		WrongAnimal& operator=( const WrongAnimal &WrongAnimalOriginal );
		~WrongAnimal( void );

		std::string		getType( void ) const;
		void	makeSound( void ) const;
};

#endif