#include <iostream>
#include "./ClapTrap.hpp"

int main( void ) {
	ClapTrap a("Maurice");
	
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

	return 0;
}