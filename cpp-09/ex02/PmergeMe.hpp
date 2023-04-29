// #ifndef PMERGEME_HPP
// # define PMERGEME_HPP

// #include <iostream>
// #include <stack>

// class PmergeMe
// {
// 	private:
// 		std::string input;
// 		std::stack<int> numbers;
// 	public:
// 		PmergeMe();
// 		PmergeMe( const std::string input );
// 		PmergeMe( const PmergeMe &src );
// 		PmergeMe& operator=( const PmergeMe &src );
// 		~PmergeMe( void );
// 		void executeRNP( void );
// };

// #endif

#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>
# include <iomanip>

class ParsingException : public std::exception
{
	std::string	_msg;

public:
	ParsingException(const std::string msg)	: _msg(msg)	{}

	~ParsingException() throw()	{}

	virtual const char*	what(void) const throw()
	{
		return _msg.c_str();
	}
};
