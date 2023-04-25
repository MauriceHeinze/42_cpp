#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		static std::string	original;
		static char				c;
		static int				i;
		static float			f;
		static double			d;
		static bool				error;

		static std::string		defineType( void );

		static void			convertChar( void );
		static void			convertInt( void );
		static void			convertFloat( void );
		static void			convertDouble( void );
		static void			convertShit( void );


		static bool			checkChar( void );
		static bool			checkInt( void );
		static bool			checkFloat( void );
		static bool			checkDouble( void );
		static bool			shitCheck( void );

		static char			getChar( void );
		static int			getInt( void );
		static float		getFloat( void );
		static double		getDouble( void );
		static std::string	getOriginal( void );
		static bool			getError( void );

		static bool 		printInfNan( void );

		ScalarConverter();
		ScalarConverter( const std::string nbr );
		ScalarConverter( const ScalarConverter &src );
		ScalarConverter& operator=( const ScalarConverter &src );
		~ScalarConverter( void );
	public:
		static bool			convert( std::string nbr );

};

std::ostream & operator<<( std::ostream & o, ScalarConverter & i );

#endif