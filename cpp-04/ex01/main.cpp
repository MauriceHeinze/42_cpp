#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "---- START -----" << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "---- END -----" << std::endl;

	const Animal* zoo[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
	int	k = 0;

	while (k < 4)
		delete zoo[k++];

	return 0;
}