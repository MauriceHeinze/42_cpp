#include "./Bureaucrat.hpp"

int main()
{
	std::cout << "\033[36m****** CREATE IT! *******\033[0m" << std::endl;
	Bureaucrat bureaucrat(21);
	Form form(20, 10);

	std::cout << "\033[36m****** BUREAUCRAT INFOS *******\033[0m" << std::endl;

	std::cout << bureaucrat << std::endl;

	std::cout << "\033[36m****** FORM INFOS *******\033[0m" << std::endl;
	std::cout << form << std::endl;

	std::cout << "\033[36m****** CAN'T SIGN IT YET *******\033[0m" << std::endl;

	bureaucrat.signForm(form);
	bureaucrat.incrementGrade();

	std::cout << "\033[36m****** NOW I SIGN IT! *******\033[0m" << std::endl;
	bureaucrat.signForm(form);

	std::cout << "\033[36m****** DESTROY IT! *******\033[0m" << std::endl;

	return (0);
}