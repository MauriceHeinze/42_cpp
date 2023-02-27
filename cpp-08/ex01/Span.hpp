#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

#include <iostream>
#include <list>
#include <exception>
#include <limits.h>

class Span
{
	private:
		unsigned int		size;
		std::vector<int>	vector;
	public:
		Span();
		Span( const unsigned int N );
		Span( const Span &src );
		Span& operator=( const Span &src );
		~Span( void );

		void	addNumber( int nbr );
		void	addManyNumbers( void );
		int		shortestSpan( void );
		int		longestSpan( void );
};

std::ostream & operator<<( std::ostream & o, Span & i );

#endif