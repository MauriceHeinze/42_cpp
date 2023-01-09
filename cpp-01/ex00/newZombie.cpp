//
// Created by Maurice Heinze on 1/7/23.
//

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*anotherZombie;

	anotherZombie = new Zombie;
	anotherZombie->addName(name);
	return (anotherZombie);
}