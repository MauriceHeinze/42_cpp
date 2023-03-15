#include "./FragTrap.hpp"

int main( void ) {
	FragTrap a("Maurice");
	
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
	a.takeDamage(200);

	a.highFivesGuys();

	return 0;
}