#include "ClapTrap.hpp"

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. 
// Attacking and repairing cost 1 energy point each
// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

ClapTrap::ClapTrap(std::string trapName)
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
	this->name = trapName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap can't attack because it doesn't have enough energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		this->hitPoints = this->hitPoints - amount;
		std::cout << "ClapTrap takes " << amount << " points of damage!" << " Current damage points: " << this->hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap can't take more damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
		this->hitPoints = this->hitPoints + amount;
		std::cout << "ClapTrap repairs itself and gets " << amount << " hitpoints back! Current hitpoints: " << this->hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap can't repair itself because it doesn't have enough energy or hit points!" << std::endl;
}