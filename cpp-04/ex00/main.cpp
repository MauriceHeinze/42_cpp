#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n\n------------- TYPE -------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n\n------------- SOUND -------------" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n\n------------- DESTRUCT -------------" << std::endl;
	delete	i;
	delete	j;

	std::cout << "\n\n------------- Wrong Animal -------------" << std::endl;
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\n\n------------- TYPE -------------" << std::endl;
	std::cout << "WrongAnimal type: " << wrong->getType() << " " << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << " " << std::endl;

	std::cout << "\n\n------------- SOUND -------------" << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	std::cout << "\n\n------------- DESTRUCT -------------" << std::endl;
	delete  wrong;
	delete  wrongCat;

	return 0;
}