#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		const std::string	original;
		unsigned char		c;
		int					i;
		float				f;
		double				d;
	public:
		ScalarConverter();
		ScalarConverter( const std::string nbr );
		ScalarConverter( const ScalarConverter &src );
		ScalarConverter& operator=( const ScalarConverter &src );
		~ScalarConverter( void );

		void	convert( void );

		/* UTILS */

		void	convertChar( void );
		void	convertInt( void );
		void	convertFloat( void );
		void	convertDouble( void );

		std::string	defineType( void );

		bool	checkChar( void );
		bool	checkInt( void );
		bool	checkFloat( void );
		bool	checkDouble( void );

		unsigned char	getChar( void );
		int				getInt( void );
		float			getFloat( void );
		double			getDouble( void );
		std::string		getOriginal( void );
};

std::ostream & operator<<( std::ostream & o, ScalarConverter & i );

#endif