#include "./Bureaucrat.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Intern.hpp"

int main( void )
{
	std::cout << "\033[32m--------------- Check Forms ---------------\033[0m" << std::endl;

	PresidentialPardonForm a("Obama");
	std::cout << a << std::endl;
	RobotomyRequestForm b("WALL-E");
	std::cout << b << std::endl;
	ShrubberyCreationForm c("Tree");
	std::cout << c << std::endl;

	std::cout << "\033[32m--------------- Check Intern ---------------\033[0m" << std::endl;
	Intern		someRandomIntern;
	AForm*		rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "Grade to sign is: " << rrf->getGradeToSign() << std::endl;

	rrf = someRandomIntern.makeForm("shrubby creation", "WALL-E");
	std::cout << "Grade to sign is: " << rrf->getGradeToSign() << std::endl;

	return (0);
}