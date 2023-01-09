//
// Created by Maurice Heinze on 1/7/23.
//

#include "Zombie.hpp"

int main(void)
{
	Zombie *peterZombie;
	peterZombie = newZombie("Peter");
	randomChump("Meghan");
	delete(peterZombie);
	return 0;
}