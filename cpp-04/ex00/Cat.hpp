#ifndef CAT_HPP
# define CAT_HPP

#include "./Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat( void );
		~Cat( void );
		Cat( const Cat &Cat );
		Cat& operator=( const Cat &catOriginal );

		void	makeSound(void) const;
};

#endif