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
		Fixed(const Fixed &fixedNumber);
		Fixed& operator=( const Fixed &fixedNumber );
		~Fixed();
		void setRawBits(int const fixedPointValue);
		int getRawBits(void) const;
};

#endif