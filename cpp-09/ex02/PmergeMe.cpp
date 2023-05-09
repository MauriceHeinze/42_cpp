#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** numStr)
{
	try {
        initContainer(this->vec, numStr);
        initContainer(this->deq, numStr);

        runVector(vec);
        std::cout << std::endl;
        runDequeue(deq);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    // std::cout << "Copy constructor called for PmergeMe" << std::endl;
    try {
        // copy data from src object
        this->vec = src.vec;
        this->deq = src.deq;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

PmergeMe& PmergeMe::operator=( const PmergeMe &src ) {
	// std::cout << "Assignment operator called for RPN" << std::endl;
	if (this != &src)
    {
        this->vec = src.vec;
        this->deq = src.deq;
    }
	return *this;
}

PmergeMe::~PmergeMe( void )
{
	// std::cout << "RPN destructed!" << std::endl;
}

template<typename Container>
void    PmergeMe::initContainer(Container& container, char** numStr)
{
    std::string                 tmpString;
	int                         i = -1;

	while (numStr[++i])
	{
        tmpString = numStr[i];
		if (tmpString.find_first_not_of("0123456789") != std::string::npos)
			throw ErrorMessage("\033[1;31mError:\033[0m Not a number!");
		if (tmpString.length() == 0)
			throw ErrorMessage("\033[1;31mError:\033[0m Invalid Arguments!");
        container.push_back(std::stoi(tmpString));
		if (container.back() != std::stol(tmpString))
			throw ErrorMessage("\033[1;31mError:\033[0m Not an integer anymore!");
	}
}

template<typename Container>
void    PmergeMe::insertSort(Container& container)
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
void    PmergeMe::mergeInsertSort(Container& container)
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

void    PmergeMe::runVector(std::vector<unsigned int>& vec)
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

void    PmergeMe::runDequeue(std::deque<unsigned int>& deq)
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