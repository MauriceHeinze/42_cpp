#include "PmergeMe.hpp"

template<typename Container>
void    initContainer(Container& container, char** numStr)
{
    std::string                 tmpString;
	int                         i = -1;

	while (numStr[++i])
	{
        tmpString = numStr[i];
		if (tmpString.find_first_not_of("0123456789") != std::string::npos)
			throw ParsingException("\033[1;31mError:\033[0m Not a number!");
		container.push_back(std::stoi(tmpString));
		if (container.back() != std::stol(tmpString))
			throw ParsingException("\033[1;31mError:\033[0m Not an integer anymore!");
	}
}

template<typename Container>
void    insertSort(Container& container)
{
    size_t size = container.size();
    
    for (size_t i = 1; i < size; ++i) {
        unsigned int key = container[i];
        int j = i - 1;
        while (j >= 0 && container[j] > key) {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

template<typename Container>
void    mergeInsertSort(Container& container)
{
    if (container.size() > 5)
    {
        typename Container::iterator middle = container.begin() + ((container.size() + 1) / 2);
        Container firstPart(container.begin(), middle);
        Container secondPart(middle, container.end());

        mergeInsertSort(firstPart);
        mergeInsertSort(secondPart);
        std::merge(firstPart.begin(), firstPart.end(), secondPart.begin(), secondPart.end(), container.begin());
    }
    else
        insertSort(container);
}

void    runVector(std::vector<unsigned int>& vec)
{
    std::cout << "\033[1;31mBefore:\033[0m:   ";
    for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    clock_t start = clock();
    mergeInsertSort(vec);
    clock_t end = clock();
    long timeTaken = (end - start) * 1000000 / CLOCKS_PER_SEC;

    std::cout << "\033[1;32mBefore:\033[0m:   ";
    for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << " " << *it;

    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector: " << timeTaken << " microseconds" << std::endl;
}

void    runDequeue(std::deque<unsigned int>& deq)
{
    
    std::cout << "\033[1;31mBefore:\033[0m:   ";
    for (std::deque<unsigned int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

    clock_t start = clock();
    mergeInsertSort(deq);
    clock_t end = clock();
    long timeTaken = (end - start) * 1000000 / CLOCKS_PER_SEC;

    std::cout << "\033[1;32mBefore:\033[0m:   ";
    for (std::deque<unsigned int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << " " << *it;
    std::cout << "\nTime to process a range of " << deq.size() << " elements with std::deque: " << timeTaken << " microseconds" << std::endl;
}

int Pmerge (char** numStr)
{
	try {
		std::vector<unsigned int> vec;
        std::deque<unsigned int> deq;

        initContainer(vec, numStr);
        initContainer(deq, numStr);

        runVector(vec);
        std::cout << std::endl;
        runDequeue(deq);

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
		std::cerr << "\033[1;31mError:\033[0m" << std::endl;
		return (1);
	}
	else
		return (Pmerge(&av[1]));
}