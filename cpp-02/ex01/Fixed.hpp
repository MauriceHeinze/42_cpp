#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int fixedNumber);
		Fixed(const float fixedNumber);
		Fixed(const Fixed &fixedNumber);
		Fixed& operator=( const Fixed &fixedNumber );
		~Fixed();

		void	setRawBits(int const fixedPointValue);
		int		getRawBits(void) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif