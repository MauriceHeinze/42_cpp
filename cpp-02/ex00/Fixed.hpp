#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed( void );
		Fixed(const Fixed &fixedNumber);
		Fixed& operator=( const Fixed &fixedNumber );
		~Fixed( void );
		void setRawBits(int const raw);
		int getRawBits(void) const;
};

#endif