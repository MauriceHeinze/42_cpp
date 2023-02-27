#include "Span.hpp"

Span::Span()
{
	std::cout << "Span constructed!" << std::endl;
}

Span::Span( const unsigned int N ) : size(N)
{
	std::cout << "Span constructed with " << N << "!" << std::endl;
	vector.reserve(size);
}

Span::Span( const Span& src )
{
	std::cout << "Copy operator called for Span" << std::endl;
	*this = src;
}

Span& Span::operator=( const Span &src ) {
	std::cout << "Assignment operator called for Span" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

Span::~Span( void )
{
	std::cout << "Span destructed!" << std::endl;
}

void Span::addNumber( int nbr )
{
	vector.push_back(nbr);
	// std::cout << "Just added " << vector[vector.size()] << " to array" << std::endl;
}

void Span::addManyNumbers( void )
{
	std::srand(unsigned(std::time(nullptr)));
	std::generate(vector.begin(), vector.end(), std::rand);
}

int	Span::shortestSpan( void )
{
	int span = INT_MAX;
	std::sort(vector.begin(), vector.end());

	std::vector<int>::iterator start = vector.begin();
	std::vector<int>::iterator start1 = vector.begin() + 1;

	span = (*start1) - (*start);
	while (start1 != vector.end())
	{
		if ((*start1) - (*start) < span)
			span = (*start1) - (*start);
		start++;
		start1++;
	}
	return (span);
}

int	Span::longestSpan( void )
{
	int span = INT_MAX;
	std::sort(vector.begin(), vector.end());

	std::vector<int>::iterator start = vector.begin();
	std::vector<int>::iterator start1 = vector.begin() + 1;

	span = (*start1) - (*start);
	while (start1 != vector.end())
	{
		if ((*start1) - (*start) > span)
			span = (*start1) - (*start);
		start++;
		start1++;
	}
	return (span);
}