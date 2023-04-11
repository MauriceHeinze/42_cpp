#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <stack>
template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void) {}
		MutantStack(const MutantStack& rhs)
		{
			(void) rhs;
		}
		~MutantStack() {}
		MutantStack &operator=(MutantStack const &rhs)
		{
			(void) rhs;
			return *this;
		}
		iterator begin()
		{
			return std::stack<T>::c.begin();
		}
		iterator end()
		{
			return std::stack<T>::c.end();
		}
};

#endif