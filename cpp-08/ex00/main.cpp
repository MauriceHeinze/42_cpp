#include "Easyfind.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));

	std::cout << "What should happen: Shouldn't find it." << std::endl;
	if (easyfind(vect, 1234))
		std::cout << "Result: Found it." << std::endl;
	else
		std::cout << "Result: Didn't find it." << std::endl;

	std::cout << "\nWhat should happen: Should find it." << std::endl;
	if (easyfind(vect, 1))
		std::cout << "Result: Found it." << std::endl;
	else
		std::cout << "Result: Didn't find it." << std::endl;

	return 0;
}
