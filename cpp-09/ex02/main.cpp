#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <ctime>

// insertion sort
template<typename T>
void insertionSort(T &arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// merge sort
// merge insertion sort

// create two containers
// function to check how long sorting of container takes

// PRINT
// print unsorted array of integers
// print sorted array of integers
// print time taken to sort first container
// print time taken to sort second container

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	std::vector<int> firstContainer(arr, arr + sizeof(arr) / sizeof(int));
	// std::stack<int> secondContainer(arr, arr + sizeof(arr) / sizeof(int));

    insertionSort(firstContainer, firstContainer.size());

    std::cout << "Sorted array: ";
	return(0);
}
