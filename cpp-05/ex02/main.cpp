#include "./Bureaucrat.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

int main( void )
{
	PresidentialPardonForm a("Obama");
	std::cout << a << std::endl;
	RobotomyRequestForm b("WALL-E");
	std::cout << b << std::endl;
	ShrubberyCreationForm c("Tree");
	std::cout << c << std::endl;

	try {
		std::cout << "\033[32m--------------- Create bureaucrat ---------------\033[0m" << std::endl;
		Bureaucrat bureaucrat(1);
		std::cout << "\033[32m--------------- Create forms ---------------\033[0m" << std::endl;
		PresidentialPardonForm form1("Obama");
		RobotomyRequestForm form2("WALL-E");
		ShrubberyCreationForm form3("Tree");

		std::cout << "\033[36m--------------- Form 1 ( President ) ---------------\033[0m" << std::endl;
		bureaucrat.signForm(form1);
		form1.execute(bureaucrat);

		std::cout << "\033[36m--------------- Form 2 ( Robot ) ---------------\033[0m" << std::endl;
		bureaucrat.signForm(form2);
		form2.execute(bureaucrat);

		std::cout << "\033[36m--------------- Form 3 ( Tree ) ---------------\033[0m" << std::endl;
		bureaucrat.signForm(form3);
		form3.execute(bureaucrat);

		std::cout << "\033[31m--------------- Destruct them ---------------\033[0m" << std::endl;

	} catch (std::exception &e) {
		std::cout << "\033[31m--------------- Error! ---------------\033[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}