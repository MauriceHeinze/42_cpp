#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructed!" << std::endl;
}

Brain::Brain(std::string type)
{
	std::cout << "Brain constructed with type: " << type << "!" << std::endl;
}

Brain::Brain( const Brain& brainOriginal )
{
	std::cout << "Copy operator called for Brain" << std::endl;
	*this = brainOriginal;
}

Brain& Brain::operator=( const Brain &brainOriginal ) {
	std::cout << "Assignment operator called for Brain" << std::endl;
	if (this != &brainOriginal)
	{
		int	i = 0;
		while (i < 100)
		{
			this->ideas[i] = brainOriginal.ideas[i];
			i++;
		}
	}
	return *this;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructed!" << std::endl;
}