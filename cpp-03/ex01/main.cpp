#include "./ScavTrap.hpp"

int main( void ) {
	ScavTrap a("Maurice");
	
	a.attack("Tobias");
	a.attack("Tobias");
	a.attack("Tobias");
	a.attack("Tobias");

	a.attack("Tobias");
	a.attack("Tobias");
	a.attack("Tobias");
	a.attack("Tobias");

	a.attack("Tobias");
	a.attack("Tobias");

	a.beRepaired(10);
	a.takeDamage(5);
	a.takeDamage(4);
	a.beRepaired(10);
	a.beRepaired(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);

	a.guardGate();

	return 0;
}