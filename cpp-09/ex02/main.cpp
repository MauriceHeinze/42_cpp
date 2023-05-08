#include "PmergeMe.hpp"

int main (int ac, char** av)
{
	if (ac < 2) {
		std::cerr << "\033[1;31mError: Invalid arguments\033[0m" << std::endl;
		return (1);
	}
	else
    {
        PmergeMe merger(&av[1]);
		return (1);
    }
}