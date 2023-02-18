#include "AForm.hpp"

AForm::AForm( int gradeToSign, int gradeToExec ) : name("default form"), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooHighException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
	std::cout << "AForm constructed!" << std::endl;
}

AForm::AForm( const AForm& src ) : name("default form"), gradeToSign(100), gradeToExec(80)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooHighException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooLowException();
	std::cout << "Copy operator called for AForm" << std::endl;
	*this = src;
}

AForm& AForm::operator=( const AForm &src ) {
	std::cout << "Assignment operator called for AForm" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

AForm::~AForm( void )
{
	std::cout << "AForm destructed!" << std::endl;
}

std::string	AForm::getName( void ) const
{
	return (this->name);
}

int	AForm::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

int	AForm::getGradeToExec( void ) const
{
	return (this->gradeToExec);
}

bool	AForm::getSigningStatus( void ) const
{
	return (this->isSigned);
}

void	AForm::beSigned( Bureaucrat &hehe )
{
	// std::cout << "AForm signing function got called!" << std::endl;
	if (hehe.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream & operator<<( std::ostream & o, AForm &i )
{
	std::string status;

	if (i.getSigningStatus())
		status = "YES";
	else
		status = "NO";

	o << "INFOS ABOUT THIS FORM "
	<< "\nAForm name:	" << i.getName()
	<< "\nSigned:		" << status
	<< "\nGrade to sign:	" << i.getGradeToSign()
	<< "\nGrade to exec:	" << i.getGradeToExec()
	<< std::endl;

	return o;
}
