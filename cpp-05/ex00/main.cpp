#include "./Bureaucrat.hpp"

int main()
{
	// SHOULD THROW AN ERROR BECAUSE TO HIGH
	int	GRADE = -1;
	Bureaucrat bureaucrat(GRADE);

	// // SHOULD THROW AN ERROR BECAUSE TOO LOW
	// int	GRADE = 100000;
	// Bureaucrat bureaucrat(GRADE);

	// // SHOULD THROW AN ERROR BECAUSE IT CAN'T INCREMENT ANYMORE (too high)
	// int	GRADE = 1;
	// Bureaucrat bureaucrat(GRADE);
	// bureaucrat.incrementGrade();

	// SHOULD THROW AN ERROR BECAUSE IT CAN'T DECREMENT ANYMORE (too low)
	// int	GRADE = 150;
	// Bureaucrat bureaucrat(GRADE);
	// bureaucrat.decrementGrade();

	// // SHOULD WORK
	// int	GRADE = 1;
	// Bureaucrat bureaucrat(GRADE);
	// for (size_t i = 0; i < 100; i++)
	// 	bureaucrat.decrementGrade();

	// std::cout << bureaucrat << std::endl;

	// for (size_t i = 0; i < 100; i++)
	// 	bureaucrat.incrementGrade();

	// std::cout << bureaucrat << std::endl;

	// SHOULD OUTPUT INFO INTO OUTSTREAM
	// int	GRADE = 1;
	// Bureaucrat bureaucrat(GRADE);
	// std::cout << bureaucrat << std::endl;
	return 0;
}
