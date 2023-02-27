#include "Span.hpp"

int main()
{
	Span sp = Span(100);
	sp.addNumber(150);
	sp.addNumber(200);
	sp.addNumber(201);
	sp.addNumber(700);
	sp.addNumber(800);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}