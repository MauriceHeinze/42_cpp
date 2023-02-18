#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "./Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
		Bureaucrat();
	public:
		Bureaucrat( int grade );
		Bureaucrat( const Bureaucrat &src );
		Bureaucrat& operator=( const Bureaucrat &src );
		~Bureaucrat( void );

		std::string	getType( void ) const;
		void 		incrementGrade( void );
		void		decrementGrade( void );
		std::string	getName() const;
		int			getGrade() const;

		void		signForm(Form &formToSign);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Bureaucrat &i );

#endif