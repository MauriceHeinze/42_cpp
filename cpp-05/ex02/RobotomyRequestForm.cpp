#include <stdlib.h>
#include <time.h>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target) : AForm(72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructed with target: " << target << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm(72, 45)
{
	std::cout << "Copy operator called for RobotomyRequestForm" << std::endl;
	*this = src;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
	std::cout << "Assignment operator called for RobotomyRequestForm" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm destructed!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void )
{
	return (this->target);
}

void	RobotomyRequestForm::execute( Bureaucrat &hehe )
{
	if (this->getSigningStatus() == false)
		throw Bureaucrat::FormNotSignedException();
	else if (hehe.getGrade() <= this->getGradeToExec())
	{
		srand(time(NULL)); // to set random value with current time (so rand doesn'r retunr the same every time)
		std::cout << this->target << " [ DRILLING NOISES ] " << std::endl;
		if (rand() % 2) // to get value between one and zero
			std::cout << this->target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy of " << this->target << " has failed" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
	std::cout << hehe.getName() << " executed robotomy request form successfully" << std::endl;
}

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm &i )
{
	std::string status;

	if (i.getSigningStatus())
		status = "YES";
	else
		status = "NO";

	o << "INFOS ABOUT THIS FORM "
	<< "\nAForm name:	" << "Robot to my Request"
	<< "\nSigned:		" << status
	<< "\nTarget:		" << i.getTarget()
	<< "\nGrade to sign:	" << i.getGradeToSign()
	<< "\nGrade to exec:	" << i.getGradeToExec()
	<< std::endl;

	return o;
}