#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &a, int b)
{
	typename T::iterator start = a.begin();
	while (start != a.end())
	{
		if (*start == b)
			return (1);
		start++;
	}
	return (0);
}

#endif