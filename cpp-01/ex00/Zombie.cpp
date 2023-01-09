//
// Created by Maurice Heinze on 1/7/23.
//

#include "Zombie.hpp"

Zombie::Zombie()
{
	// std::cout << this->name << "Instance created!\n";
}

Zombie::~Zombie()
{
	std::cout << this->name << " got destructed!\n";
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::addName(std::string name) {
	this->name = name;
}