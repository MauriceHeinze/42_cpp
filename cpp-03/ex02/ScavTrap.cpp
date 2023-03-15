#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "ScavTrap: Default constructor called for: " << this->name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called for: " << this->name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in gate keeper mode" << std::endl;
}

void ScavTrap::attack( std::string const& target )
{
	if (energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap can't attack because it doesn't have enough energy points!" << std::endl;
}