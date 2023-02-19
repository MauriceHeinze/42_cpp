#include "Base.hpp"

Base::Base()
{
	std::cout << "Base constructed!" << std::endl;
}

Base::Base( const Base& src )
{
	std::cout << "Copy operator called for Base" << std::endl;
	*this = src;
}

Base& Base::operator=( const Base &src ) {
	std::cout << "Assignment operator called for Base" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

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
	try
	{
		A& a = dynamic_cast< A& >( p );
		std::cout << "It's type A!" << std::endl;
	}
	catch( const std::exception& e ) {}
	try
	{
		A& a = dynamic_cast< A& >( p );
		std::cout << "It's type A!" << std::endl;
	}
	catch( const std::exception& e ) {}
	try
	{
		A& a = dynamic_cast< A& >( p );
		std::cout << "It's type A!" << std::endl;
	}
	catch( const std::exception& e ) {}
}