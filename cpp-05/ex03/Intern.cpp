#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructed!"<< std::endl;
}

Intern::Intern( const Intern& src )
{
	std::cout << "Copy operator called for Intern" << std::endl;
	*this = src;
}

Intern& Intern::operator=( const Intern &src ) {
	std::cout << "Assignment operator called for Intern" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

Intern::~Intern( void )
{
	std::cout << "Intern destructed!" << std::endl;
}

AForm	*Intern::makeForm(std::string formName, std::string targetName)
{
	int	i = 0;
	std::string	forms[3] = {	"presidential pardon",
								"robotomy request",
								"shrubby creation"
							};
	AForm		*functions[3] = { 	new PresidentialPardonForm( targetName ),
									new RobotomyRequestForm( targetName ),
									new ShrubberyCreationForm( targetName )
    						};
	while (i < 3)
	{
		if (formName == forms[i])
			return (functions[i]);
		i++;
	}
	std::cout << "The intern could not find the form!" << std::endl;
	return (NULL);
}