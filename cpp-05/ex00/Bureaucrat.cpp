#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( int grade ) : name("default bureaucrat")
{
	std::cout << "Bureaucrat constructed!" << std::endl;
	if (grade >= 1 && grade <= 150)
		this->grade = grade;
	else if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat& src )
{
	std::cout << "Copy operator called for Bureaucrat" << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &src ) {
	std::cout << "Assignment operator called for Bureaucrat" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat destructed!" << std::endl;
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->grade >= 2)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException();

}

void	Bureaucrat::decrementGrade( void )
{
	if (this->grade <= 149)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException();

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream & operator<<( std::ostream & o, Bureaucrat & i )
{
	o << i.getName() << " has a grade of " << i.getGrade() << std::endl;
	return o;
}