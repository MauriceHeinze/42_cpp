#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target) : AForm(25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructed with target: " << target << "!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm(25, 5)
{
	std::cout << "Copy operator called for PresidentialPardonForm" << std::endl;
	*this = src;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
	std::cout << "Assignment operator called for PresidentialPardonForm" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm destructed!" << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void )
{
	return (this->target);
}

void	PresidentialPardonForm::execute( Bureaucrat &hehe )
{
	if (this->getSigningStatus() == false)
		throw Bureaucrat::FormNotSignedException();
	else if (hehe.getGrade() <= this->getGradeToExec())
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		throw Bureaucrat::GradeTooHighException();
	std::cout << hehe.getName() << " executed presidential pardon form successfully" << std::endl;
}

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm &i )
{
	std::string status;

	if (i.getSigningStatus())
		status = "YES";
	else
		status = "NO";

	o << "INFOS ABOUT THIS FORM "
	<< "\nAForm name:	" << "Presidential Pardon Form"
	<< "\nSigned:		" << status
	<< "\nTarget:		" << i.getTarget()
	<< "\nGrade to sign:	" << i.getGradeToSign()
	<< "\nGrade to exec:	" << i.getGradeToExec()
	<< std::endl;

	return o;
}