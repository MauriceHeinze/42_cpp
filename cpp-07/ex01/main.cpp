#include "./iter.hpp"

int	add(int &num) {
	num += 10;
	return (num);
}

int main()
{
	int tab[5] = {1, 2, 3, 4, 5};
	iter(tab, 5, add);
	return (0);
}