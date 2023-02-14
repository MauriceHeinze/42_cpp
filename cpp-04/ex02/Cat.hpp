#ifndef CAT_HPP
# define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *ideas;
	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &Cat );
		Cat& operator=( const Cat &catOriginal );

		void	makeSound( void ) const;
};

#endif