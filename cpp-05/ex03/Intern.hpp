#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern( const Intern &src );
		Intern& operator=( const Intern &src );
		~Intern( void );

		AForm	*makeForm(std::string formName, std::string targetName);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Intern &i );

#endif