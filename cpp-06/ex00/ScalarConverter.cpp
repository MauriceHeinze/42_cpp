#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructed!" << std::endl;
}

ScalarConverter::ScalarConverter( const std::string nbr ) : original(nbr)
{
	std::cout << "ScalarConverter constructed with " << nbr << "!" << std::endl;

	this->c = '\0';
	this->i = 0;
	this->f = 0.0f;
	this->d = 0.0;
	this->error = false;
	this->convert();
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

bool	ScalarConverter::convert( void )
{
	try
	{
		if (this->original.find_first_not_of("+-0123456789.f") != std::string::npos)
		{
			this->error = true;
			std::cerr << "\nError: Invalid input!" << '\n';
			return (false);
		}
		if (this->defineType() == "int")
			this->convertInt();
		else if (this->defineType() == "char")
			this->convertChar();
		else if (this->defineType() == "float")
			this->convertFloat();
		else if (this->defineType() == "double")
			this->convertDouble();
		else
			return (false);
	}
	catch(const std::exception& e)
	{
		this->error = true;
		std::cerr << "\nError: Invalid input!" << '\n';
		return (false);
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
	const std::string	original = this->original;

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
	const std::string	nbr = this->original;

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
	const std::string	nbr = this->original;

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
	if (this->checkInt())
		return ("int");
	else if (this->checkChar())
		return ("char");
	else if (this->checkFloat())
		return ("float");
	else if (this->checkDouble())
		return ("double");
	else if (this->shitCheck())
		return ("shit");
	return ("undefined");
}

bool	ScalarConverter::shitCheck( void )
{
	if (this->original == "nan" ||
		this->original == "nanf" ||
		this->original == "+inf" ||
		this->original == "-inf" ||
		this->original == "+inff" ||
		this->original == "-inff")
		return (true);
	else
		return (false);
}

/* CONVERTER FUNCTIONS */
void	ScalarConverter::convertChar( void )
{
	const std::string	original = this->original;

	this->c = original.c_str()[0];
	this->i = static_cast<int>(this->c);
	this->f = static_cast<float>(this->c);
	this->d = static_cast<double>(this->c);
}

void	ScalarConverter::convertInt( void )
{
	const std::string	original = this->original;

	this->i = static_cast<int>(std::stoi(original));
	this->f = static_cast<float>(this->i);
	this->d = static_cast<double>(this->i);
	this->c = static_cast<char>(this->i);
}

void	ScalarConverter::convertFloat( void )
{
	const std::string	original = this->original;

	this->f = static_cast<float>(std::stof(original)) - float(0);
	this->i = static_cast<int>(this->f);
	this->c = static_cast<char>(this->f);
	this->d = static_cast<double>(this->f);
}

void	ScalarConverter::convertDouble( void )
{
	const std::string	original = this->original;

	this->d = static_cast<double>(std::stold(original));
	this->f = static_cast<float>(this->d);
	this->i = static_cast<int>(this->d);
	this->c = static_cast<char>(this->d);
}

/* GETTER FUNCTIONS */
std::string	ScalarConverter::getOriginal( void )
{
	return (this->original);
}

char	ScalarConverter::getChar( void )
{
	return (this->c);
}

int		ScalarConverter::getInt( void )
{
	return (this->i);
}

float	ScalarConverter::getFloat( void )
{
	return (this->f);
}

double	ScalarConverter::getDouble( void )
{
	return (this->d);
}

bool 	ScalarConverter::getError( void )
{
	return (this->error);
}

bool 	ScalarConverter::printInfNan( void )
{
	int	i = 0;
	std::string nan[6] = {"+inf", "-inf", "+inff", "-inff", "nan", "nanf"};

	while (i < 6)
	{
		if (nan[i] == this->getOriginal())
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

std::ostream & operator<<( std::ostream & o, ScalarConverter & i )
{
	if (i.getError() == false)
	{
		std::string character = "Character is not displayable";
		if (i.getInt() >= 32 && i.getInt() <= 126)
			character = std::string() + i.getChar();
		else if (i.getInt() < 0 || i.getInt() > 127)
			character = "Impossible!";

		if (!i.printInfNan() && (static_cast<float>(i.getInt()) - i.getFloat()) != 0)
		{
			o << "\nchar:	" << character
			<< "\nint:	" << i.getInt()
			<< "\nfloat:	" << i.getFloat() << "f"
			<< "\ndouble:	" << i.getDouble()
			<< std::endl;
		}
		else
		{
			o << "\nchar:	" << character
			<< "\nint:	" << i.getInt()
			<< "\nfloat:	" << i.getFloat() << ".0f"
			<< "\ndouble:	" << i.getDouble() << ".0"
			<< std::endl;
		}
	}
	return o;
}
