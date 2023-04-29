#include "PmergeMe.hpp"

std::vector<unsigned int> initializeVector(char** numStr)
{
    std::string                 tmpString;
	std::vector<unsigned int>   tmpVector;
	int                         i = -1;

	while (numStr[++i])
	{
        tmpString = numStr[i];
		if (tmpString.find_first_not_of("0123456789") != std::string::npos)
			throw ParsingException("Error: Not a number!");
		tmpVector.push_back(std::stoi(tmpString));
		if (tmpVector.back() != std::stol(tmpString))
			throw ParsingException("Error: Not an integer anymore!");
	}
	return (tmpVector);
}

void insertSort(std::vector<unsigned int>& nbrs)
{
    size_t size = nbrs.size();
    
    for (size_t i = 1; i < size; ++i) {
        unsigned int key = nbrs[i];
        int j = i - 1;
        while (j >= 0 && nbrs[j] > key) {
            nbrs[j + 1] = nbrs[j];
            j--;
        }
        nbrs[j + 1] = key;
    }
}

void mergeInsertSort(std::vector<unsigned int>& vec)
{
    if (vec.size() > 5)
    {
        std::vector<unsigned int>::iterator middle = vec.begin() + ((vec.size() + 1) / 2);
        std::vector<unsigned int> firstPart(vec.begin(), middle);
        std::vector<unsigned int> secondPart(middle, vec.end());

        mergeInsertSort(firstPart);
        mergeInsertSort(secondPart);
        std::merge(firstPart.begin(), firstPart.end(), secondPart.begin(), secondPart.end(), vec.begin());
    }
    else
        insertSort(vec);
}

int Pmerge (char** numStr)
{
	try {
		std::vector<unsigned int> vec = initializeVector(numStr);

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