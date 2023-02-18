#ifndef AFORM_HPP
# define AFORM_HPP

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExec;
	public:
		AForm();
		AForm( int gradeToSign, int gradeToExec );
		AForm( const AForm &src );
		AForm& operator=( const AForm &src );
		~AForm( void );

		std::string	getName() const;
		bool		getSigningStatus( void ) const;
		virtual int	getGradeToSign() const;
		virtual int	getGradeToExec() const;

		void		beSigned( Bureaucrat &hehe );

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

std::ostream & operator<<( std::ostream & o, AForm &i );

#endif