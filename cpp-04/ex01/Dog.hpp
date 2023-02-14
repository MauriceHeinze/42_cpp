#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*ideas;
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &Dog );
		Dog& operator=( const Dog &dogOriginal );

		void	makeSound(void) const;
};

#endif