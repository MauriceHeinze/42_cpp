#include "Form.hpp"

Form::Form( int gradeToSign, int gradeToExec ) : name("default form"), gradeToSign(gradeToSign), gradeToExec(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooHighException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooLowException();
	std::cout << "Form constructed!" << std::endl;
}

Form::Form( const Form& src ) : name("default form"), gradeToSign(100), gradeToExec(80)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooHighException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooLowException();
	std::cout << "Copy operator called for Form" << std::endl;
	*this = src;
}

Form& Form::operator=( const Form &src ) {
	std::cout << "Assignment operator called for Form" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

Form::~Form( void )
{
	std::cout << "Form destructed!" << std::endl;
}

std::string	Form::getName( void ) const
{
	return (this->name);
}

int	Form::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

int	Form::getGradeToExec( void ) const
{
	return (this->gradeToExec);
}

int	Form::getSigningStatus( void ) const
{
	return (this->isSigned);
}

void	Form::beSigned( Bureaucrat &hehe )
{
	// std::cout << "Form signing function got called!" << std::endl;
	if (hehe.getGrade() <= this->getGradeToSign())
		this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream & operator<<( std::ostream & o, Form &i )
{
	std::string status;

	if (i.getSigningStatus())
		status = "YES";
	else
		status = "NO";

	o << "INFOS ABOUT THIS FORM "
	<< "\nForm name:	" << i.getName()
	<< "\nSigned:		" << status
	<< "\nGrade to sign:	" << i.getGradeToSign()
	<< "\nGrade to exec:	" << i.getGradeToExec()
	<< std::endl;

	return o;
}
