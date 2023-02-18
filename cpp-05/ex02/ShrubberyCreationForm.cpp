#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) : AForm(145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructed with target: " << target << "!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm(145, 137)
{
	std::cout << "Copy operator called for ShrubberyCreationForm" << std::endl;
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
	std::cout << "Assignment operator called for ShrubberyCreationForm" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm destructed!" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void )
{
	return (this->target);
}

void	ShrubberyCreationForm::execute( Bureaucrat &hehe )
{
	std::string		fileName = this->getTarget() + "_shrubbery";;

	if (this->getSigningStatus() == false)
		throw Bureaucrat::FormNotSignedException();
	else if (hehe.getGrade() <= this->getGradeToExec())
	{
		std::ofstream	file( fileName );
		file << "        # #### #### "<< std::endl;
		file << "      ### \\/#|### |/####" << std::endl;
		file << "     ##\\/#/ \\||/##/_/##/_#" << std::endl;
		file << "   ###  \\/###|/ \\/ # ###" << std::endl;
		file << " ##_\\_#\\_\\## | #/###_/_####" << std::endl;
		file << "## #### # \\ #| /  #### ##/##" << std::endl;
		file << " __#_--###`  |{,###---###-~" << std::endl;
		file << "           \\ }{" << std::endl;
		file << "            }}{" << std::endl;
		file << "            }}{" << std::endl;
		file << "       ejm  {{}" << std::endl;
		file << "      , -=-~{ . ^- _" << std::endl;
		file << "            `}" << std::endl;
		file << "             {" << std::endl;
		file.close();

		std::cout << hehe.getName() << " executed shruberry creation form successfully" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm &i )
{
	std::string status;

	if (i.getSigningStatus())
		status = "YES";
	else
		status = "NO";

	o << "INFOS ABOUT THIS FORM "
	<< "\nAForm name:	" << "Shrubbery Creation"
	<< "\nSigned:		" << status
	<< "\nTarget:		" << i.getTarget()
	<< "\nGrade to sign:	" << i.getGradeToSign()
	<< "\nGrade to exec:	" << i.getGradeToExec()
	<< std::endl;

	return o;
}