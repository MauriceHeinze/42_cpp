#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <algorithm>
# include <iomanip>

class PmergeMe
{
	private:
		PmergeMe();
		std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;
	public:
		PmergeMe(char** numStr);
		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
		~PmergeMe();
		template<typename Container>
		void    initContainer(Container& container, char** numStr);
		template<typename Container>
		void    insertSort(Container& container);
		template<typename Container>
		void    mergeInsertSort(Container& container);
		void    runVector(std::vector<unsigned int>& vec);
		void    runDequeue(std::deque<unsigned int>& deq);
};

class ErrorMessage : public std::exception
{
	std::string	message;

	public:
		ErrorMessage(const std::string msg)	: message(msg)	{}
		~ErrorMessage() throw()	{}

	virtual const char*	what(void) const throw() { return message.c_str(); }
};

#endif