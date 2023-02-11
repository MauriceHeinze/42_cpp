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

		// OPERATORS
		Fixed operator+( const Fixed &fixedNumber );
		Fixed operator-( const Fixed &fixedNumber );
		Fixed operator*( const Fixed &fixedNumber );
		Fixed operator/( const Fixed &fixedNumber );

		// COMPARISON
		bool operator>( const Fixed &fixedNumber ) const;
		bool operator<( const Fixed &fixedNumber ) const;
		bool operator>=( const Fixed &fixedNumber ) const;
		bool operator<=( const Fixed &fixedNumber ) const;

		// INCREMENT && DECREMENT
		Fixed& operator ++();
		Fixed operator ++( int );
		Fixed& operator --();
		Fixed operator --( int );
		~Fixed();

		// MIN && MAX
		static Fixed&			min( Fixed &a, Fixed &b );
		static const Fixed&	min( const Fixed &a, const Fixed &b );
		static Fixed& 			max( Fixed &a, Fixed &b );
		static const Fixed&	max( const Fixed &a, const Fixed &b );

		void	setRawBits(int const fixedPointValue);
		int		getRawBits(void) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif