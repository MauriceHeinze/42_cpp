#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class myType>
void iter(myType *array, int length, int (*func)(myType &)) {
	int i = 0;

	while (i < length)
		std::cout << func(array[i++]) << std::endl;
}

#endif