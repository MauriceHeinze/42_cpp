#include <iostream>

template<typename T>
class	Array {

	private:
		T*				array;
		unsigned int	n;
	public:
		Array()
		{
			this->n = 0;
			this->array = NULL;
			this->array = new T[0];
			std::cout << "Array constructed with size 0!" << std::endl;
		}
		Array( unsigned int n )
		{
			unsigned int i = 0;
			this->n = n;
			this->array = NULL;
			this->array = new T[this->n];
			while(i < n)
				this->array[i++] = 0;
			std::cout << "Array constructed with size " << this->n << "!" << std::endl;
		}
		Array( const class Array &src )
		{
			std::cout << "Array copied!" << std::endl;
			unsigned int i = 0;
			delete [] array;
			array = new T[src.size()];
			n = src.n;
			while (i < n)
			{
				array[i] = src.array[i];
				i++;
			}
		}
		Array& operator=( const Array& src ) {
			if ( this != &src ) {
				unsigned int i = 0;
				delete [] array;
				array = new T[src.size()];
				n = src.n;
				while (i < n)
				{
					array[i] = src.array[i];
					i++;
				}
			}
			return *this;
		}
		T	& operator[]( unsigned int n )
		{
			// std::cout << "Subscription operator called!" << std::endl;
			if (n < this->n)
				return (this->array[n]);
			else
				throw OutOfBounds();
		}
		~Array()
		{
			delete [] this->array;
			std::cout << "Destructed array with " << this->n << " elements!" << std::endl;
		}
		unsigned int size() const
		{
			return (this->n);
		}
		class OutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw() { return "Index is out of bounds";}
		};
};

template < typename T >
std::ostream& operator<<( std::ostream& o, Array<T>& i ) {
	unsigned int	counter = 0;

	while (counter < i.size())
		o << i[counter++] << " ";
	return o;
}