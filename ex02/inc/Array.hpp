#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <limits>

template <class T>
class Array {
	public:
		Array();										//Default constructor
		Array(const unsigned int& capacity);
		~Array();										//Destructor
		Array(const Array &other);				//Copy constructor
		Array &operator=(const Array &other);	//Copy operator
		T&	operator[](const unsigned int& nb);
		void	push(const T& element);
		void	pop();
		const unsigned int& size() const;
		const unsigned int& getCapacity() const;
		T*	getArray() const;
	private:
		T*		_array;
		unsigned int	_capacity;
		unsigned int	_size;

		bool	resize();

};

#include "Array.tpp"
#endif
