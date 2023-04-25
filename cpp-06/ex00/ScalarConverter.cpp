#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

std::string		ScalarConverter::original;
char			ScalarConverter::c;
int				ScalarConverter::i;
float			ScalarConverter::f;
double			ScalarConverter::d;
bool			ScalarConverter::error;

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructed!" << std::endl;
}

ScalarConverter::ScalarConverter( const std::string nbr )
{
	std::cout << "ScalarConverter constructed with " << nbr << "!" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& src )
{
	std::cout << "Copy operator called for ScalarConverter" << std::endl;
	*this = src;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter &src ) {
	std::cout << "Assignment operator called for ScalarConverter" << std::endl;
	if (this != &src)
		*this = src;
	return *this;
}

ScalarConverter::~ScalarConverter( void )
{
	std::cout << "ScalarConverter destructed!" << std::endl;
}

bool	ScalarConverter::convert( std::string nbr )
{
	ScalarConverter::original = nbr;
	try
	{
		if (nbr.find_first_not_of("+-0123456789.f") != std::string::npos)
		{
			ScalarConverter::error = true;
			std::cerr << "\nError: Invalid input!" << '\n';
			return (false);
		}
		if (ScalarConverter::defineType() == "int")
			ScalarConverter::convertInt();
		else if (ScalarConverter::defineType() == "char")
			ScalarConverter::convertChar();
		else if (ScalarConverter::defineType() == "float")
			ScalarConverter::convertFloat();
		else if (ScalarConverter::defineType() == "double")
			ScalarConverter::convertDouble();
	}
	catch(const std::exception& e)
	{
		ScalarConverter::error = true;
		std::cerr << "\nError: Invalid input!" << '\n';
		return (false);
	}
	if (ScalarConverter::getError() == false)
	{
		std::string character = "Character is not displayable";
		if (ScalarConverter::getInt() >= 32 && ScalarConverter::getInt() <= 126)
			character = std::string() + ScalarConverter::getChar();
		else if (ScalarConverter::getInt() < 0 || ScalarConverter::getInt() > 127)
			character = "Impossible!";

		if (!ScalarConverter::printInfNan() && (static_cast<float>(ScalarConverter::getInt()) - ScalarConverter::getFloat()) != 0)
		{
			std::cout << "\nchar:	" << character
			<< "\nint:	" << ScalarConverter::getInt()
			<< "\nfloat:	" << ScalarConverter::getFloat() << "f"
			<< "\ndouble:	" << ScalarConverter::getDouble()
			<< std::endl;
		}
		else
		{
			std::cout << "\nchar:	" << character
			<< "\nint:	" << ScalarConverter::getInt()
			<< "\nfloat:	" << ScalarConverter::getFloat() << ".0f"
			<< "\ndouble:	" << ScalarConverter::getDouble() << ".0"
			<< std::endl;
		}
	}
	return (false);
}

/* CHECKER FUNCTIONS */
bool	ScalarConverter::checkChar( void )
{
	if (original.length() == 1 && (std::isprint(original[0]) == 1))
		return (true);
	return (false);
}

bool	ScalarConverter::checkInt( void )
{
	const std::string	original = ScalarConverter::original;

	if ((original.find_first_not_of("+-0123456789") == std::string::npos)) // no unallowed chars found
	{
		if (original.find_last_of("+-") == 0 && original.find_last_of("+-") != std::string::npos)
			return (true); // sign found at first pos
		else if (original.find_last_of("+-") != 0 && original.find_last_of("+-") != std::string::npos)
			return (false); // sign found at later pos
		else
			return (true); // no sign found
	}
	return (false);
}

bool	ScalarConverter::checkFloat( void )
{
	const std::string	nbr = ScalarConverter::original;

	if ((nbr.find_first_not_of("+-0123456789.f") == std::string::npos)) // no unallowed chars found
	{
		if (nbr.find('f') == nbr.size() - 1 && nbr.find('f', nbr.find('f') + 1) == std::string::npos)
		{
			if (nbr.find('.') != std::string::npos)
			{
				if (nbr.find_last_of("+-") == 0 && nbr.find_last_of("+-") != std::string::npos)
					return (true); // sign found at first pos
				else if (nbr.find_last_of("+-") != 0 && nbr.find_last_of("+-") != std::string::npos)
					return (false); // sign found at later pos
				else
					return (true); // no sign found
			}
		}
	}
	return (false);
}

bool	ScalarConverter::checkDouble( void )
{
	const std::string	nbr = ScalarConverter::original;

	if ((nbr.find_first_not_of("+-0123456789.") == std::string::npos)) // no unallowed chars found
	{
		if (nbr.find_last_of("+-") == 0 && nbr.find_last_of("+-") != std::string::npos)
			return (true); // sign found at first pos
		else if (nbr.find_last_of("+-") != 0 && nbr.find_last_of("+-") != std::string::npos)
			return (false); // sign found at later pos
		else
			return (true); // no sign found
	}
	return (false);
}

std::string	ScalarConverter::defineType( void )
{
	if (ScalarConverter::checkInt())
		return ("int");
	else if (ScalarConverter::checkChar())
		return ("char");
	else if (ScalarConverter::checkFloat())
		return ("float");
	else if (ScalarConverter::checkDouble())
		return ("double");
	else if (ScalarConverter::shitCheck())
		return ("shit");
	return ("undefined");
}

bool	ScalarConverter::shitCheck( void )
{
	if (ScalarConverter::original == "nan" ||
		ScalarConverter::original == "nanf" ||
		ScalarConverter::original == "+inf" ||
		ScalarConverter::original == "-inf" ||
		ScalarConverter::original == "+inff" ||
		ScalarConverter::original == "-inff")
		return (true);
	else
		return (false);
}

/* CONVERTER FUNCTIONS */
void	ScalarConverter::convertChar( void )
{
	const std::string	original = ScalarConverter::original;

	ScalarConverter::c = original.c_str()[0];
	ScalarConverter::i = static_cast<int>(ScalarConverter::c);
	ScalarConverter::f = static_cast<float>(ScalarConverter::c);
	ScalarConverter::d = static_cast<double>(ScalarConverter::c);
}

void	ScalarConverter::convertInt( void )
{
	const std::string	original = ScalarConverter::original;

	ScalarConverter::i = static_cast<int>(std::stoi(original));
	ScalarConverter::f = static_cast<float>(ScalarConverter::i);
	ScalarConverter::d = static_cast<double>(ScalarConverter::i);
	ScalarConverter::c = static_cast<char>(ScalarConverter::i);
}

void	ScalarConverter::convertFloat( void )
{
	const std::string	original = ScalarConverter::original;

	ScalarConverter::f = static_cast<float>(std::stof(original)) - float(0);
	ScalarConverter::i = static_cast<int>(ScalarConverter::f);
	ScalarConverter::c = static_cast<char>(ScalarConverter::f);
	ScalarConverter::d = static_cast<double>(ScalarConverter::f);
}

void	ScalarConverter::convertDouble( void )
{
	const std::string	original = ScalarConverter::original;

	ScalarConverter::d = static_cast<double>(std::stold(original));
	ScalarConverter::f = static_cast<float>(ScalarConverter::d);
	ScalarConverter::i = static_cast<int>(ScalarConverter::d);
	ScalarConverter::c = static_cast<char>(ScalarConverter::d);
}

/* GETTER FUNCTIONS */
std::string	ScalarConverter::getOriginal( void )
{
	return (ScalarConverter::original);
}

char	ScalarConverter::getChar( void )
{
	return (ScalarConverter::c);
}

int		ScalarConverter::getInt( void )
{
	return (ScalarConverter::i);
}

float	ScalarConverter::getFloat( void )
{
	return (ScalarConverter::f);
}

double	ScalarConverter::getDouble( void )
{
	return (ScalarConverter::d);
}

bool 	ScalarConverter::getError( void )
{
	return (ScalarConverter::error);
}

bool 	ScalarConverter::printInfNan( void )
{
	int	i = 0;
	std::string nan[6] = {"+inf", "-inf", "+inff", "-inff", "nan", "nanf"};

	while (i < 6)
	{
		if (nan[i] == ScalarConverter::getOriginal())
			break;
		i++;
	}
	if (i < 6)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: imbossible" << std::endl;
		if (nan[i] == "+inf" || nan[i] == "+inff") {
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (nan[i] == "nan" || nan[i] == "nanf") {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else {
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return (true);
	}
	else
		return (false);
}

// std::ostream & operator<<( std::ostream & o, ScalarConverter & i )
// {
// 	if (ScalarConverter::getError() == false)
// 	{
// 		std::string character = "Character is not displayable";
// 		if (ScalarConverter::getInt() >= 32 && ScalarConverter::getInt() <= 126)
// 			character = std::string() + ScalarConverter::getChar();
// 		else if (ScalarConverter::getInt() < 0 || ScalarConverter::getInt() > 127)
// 			character = "Impossible!";

// 		if (!ScalarConverter::printInfNan() && (static_cast<float>(ScalarConverter::getInt()) - ScalarConverter::getFloat()) != 0)
// 		{
// 			o << "\nchar:	" << character
// 			<< "\nint:	" << ScalarConverter::getInt()
// 			<< "\nfloat:	" << ScalarConverter::getFloat() << "f"
// 			<< "\ndouble:	" << ScalarConverter::getDouble()
// 			<< std::endl;
// 		}
// 		else
// 		{
// 			o << "\nchar:	" << character
// 			<< "\nint:	" << ScalarConverter::getInt()
// 			<< "\nfloat:	" << ScalarConverter::getFloat() << ".0f"
// 			<< "\ndouble:	" << ScalarConverter::getDouble() << ".0"
// 			<< std::endl;
// 		}
// 	}
// 	return o;
// }
