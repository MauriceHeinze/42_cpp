#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::string input;
		std::stack<int> numbers;
	public:
		RPN();
		RPN( const std::string input );
		RPN( const RPN &src );
		RPN& operator=( const RPN &src );
		~RPN( void );
		void executeRNP( void );
};

#endif