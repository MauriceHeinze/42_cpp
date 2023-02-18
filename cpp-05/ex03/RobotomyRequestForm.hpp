#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string const	target;
		bool				isSigned;
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( const std::string target);
		RobotomyRequestForm( const RobotomyRequestForm &src );
		RobotomyRequestForm& operator=( const RobotomyRequestForm &src );
		~RobotomyRequestForm( void );

		void		beSigned( Bureaucrat &hehe );
		void		execute( Bureaucrat &hehe );
		std::string	getTarget( void );
};

std::ostream & operator<<( std::ostream & o, RobotomyRequestForm &i );

#endif