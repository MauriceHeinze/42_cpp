#include "Base.hpp"

Base::~Base( void )
{
	std::cout << "Base destructed!" << std::endl;
}

Base	*generate(void)
{
	srand(time(NULL));
	int	i = rand() % 3;

	if (i == 1)
		return (new A());
	else if (i == 2)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if ( dynamic_cast< A* >( p ) )
	 	std::cout << "It's type A!" << std::endl;
	else if ( dynamic_cast< B* >( p ) )
		std::cout << "It's type B!" << std::endl;
	else if ( dynamic_cast< C* >( p ) )
		std::cout << "It's type C!" << std::endl;
	else
		std::cout << "This type is unknown!" << std::endl;
}

void	identify(Base& p)
{
	Base	&tmp = (Base &)"Some_memory_address";
	try
	{
		tmp = dynamic_cast< A& >( p );
		std::cout << "It's type A!" << std::endl;
	}
	catch( const std::exception& e ) {}
	try
	{
		tmp = dynamic_cast< B& >( p );
		std::cout << "It's type B!" << std::endl;
	}
	catch( const std::exception& e ) {}
	try
	{
		tmp = dynamic_cast< C& >( p );
		std::cout << "It's type C!" << std::endl;
	}
	catch( const std::exception& e ) {}
}