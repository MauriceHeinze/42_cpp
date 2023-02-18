#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string const	target;
		bool				isSigned;
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( const std::string target);
		PresidentialPardonForm( const PresidentialPardonForm &src );
		PresidentialPardonForm& operator=( const PresidentialPardonForm &src );
		~PresidentialPardonForm( void );

		void		beSigned( Bureaucrat &hehe );
		void		execute( Bureaucrat &hehe );
		std::string	getTarget();
};

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm &i );

#endif