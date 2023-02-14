#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &Dog );
		Dog& operator=( const Dog &dogOriginal );

		void	makeSound(void) const;
};

#endif