//
// Created by Maurice Heinze on 1/7/23.
//

#include "./Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	*randomZombie = newZombie(name);
	randomZombie->announce();
	delete(randomZombie);
}