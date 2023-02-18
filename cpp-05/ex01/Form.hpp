#ifndef FORM_HPP
# define FORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
		Form();
	public:
		Form( int gradeToSign, int gradeToExec );
		Form( const Form &src );
		Form& operator=( const Form &src );
		~Form( void );

		std::string	getName() const;
		int			getSigningStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned( Bureaucrat &hehe );

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<( std::ostream & o, Form &i );

#endif