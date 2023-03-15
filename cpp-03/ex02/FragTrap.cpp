#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap: Default constructor called for: " << this->name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called for: " << this->name << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints--;
    	std::cout << "FragTrap high fives all guys" << std::endl;
	}
	else
		std::cout << "FragTrap can't high five all guys because it doesn't have enough hit or energy points!" << std::endl;
}

void FragTrap::attack( std::string const& target )
{
	if (energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap can't attack because it doesn't have enough energy points!" << std::endl;
}