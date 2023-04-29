#include "PmergeMe.hpp"

bool isNumber(std::string s)
{
	return (s.find_first_not_of("0123456789") == std::string::npos && s.size());
}

std::vector<unsigned int> initVec(char** numStr)
{
	int i = -1;
	std::vector<unsigned int> tmp;

	while (numStr[++i])
	{
		if (!isNumber(numStr[i]))
			throw ParsingException("Error");
		tmp.push_back(atoi(numStr[i]));
		if (tmp.back() != atol(numStr[i]))
			throw ParsingException("Error: unsigned int overflow");
	}
	return (tmp);
}

void	insertSort(std::vector<unsigned int>& vec)
{
	size_t size = vec.size();

	size_t i = -1;
	while (++i < size)
	{
		size_t j = i;
		while (j < size && vec[j] >= vec[i])
			j++;
		if (j < size)
		{
			int tmp = vec[j];
			vec.erase(vec.begin() + j);
			vec.insert(vec.begin() + i, tmp);
			i = -1;
		}
	}
}

void mergeInsertSort (std::vector<unsigned int>& vec)
{
	if (vec.size() > 5)
	{
		std::vector<unsigned int> part1(vec.begin(), vec.begin() + ((vec.size() + 1)/2));
		std::vector<unsigned int> part2(vec.begin() + ((vec.size() + 1)/2), vec.end());

		mergeInsertSort(part1);
		mergeInsertSort(part2);
		std::merge(part1.begin(), part1.end(), part2.begin(), part2.end(), vec.begin());
	}
	else
		insertSort(vec);
}

int Pmerge (char** numStr)
{
	try {
		std::vector<unsigned int> vec = initVec(numStr);

		std::cout << "Before:   ";
		for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;

		clock_t start = clock();
		mergeInsertSort(vec);
		clock_t end = clock();

		std::cout << "After:    ";
		for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << " " << *it;
		std::cout << std::endl;

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << static_cast<double>(end - start / CLOCKS_PER_SEC) << " us" << std::endl;
		return (0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}

int main (int ac, char** av)
{
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	else
		return (Pmerge(&av[1]));
}