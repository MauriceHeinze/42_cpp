#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const	target;
		bool				isSigned;
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const std::string target);
		ShrubberyCreationForm( const ShrubberyCreationForm &src );
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm &src );
		~ShrubberyCreationForm( void );

		void		beSigned( Bureaucrat &hehe );
		void		execute( Bureaucrat &hehe );
		std::string	getTarget();
};

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm &i );

#endif