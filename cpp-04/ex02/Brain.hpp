#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string		*ideas[100];
	public:
		Brain( void );
		Brain( std::string type );
		Brain( const Brain &Brain );
		Brain& operator=( const Brain &brainOriginal );
		~Brain( void );
};

#endif