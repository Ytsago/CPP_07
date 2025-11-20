#include "Array.hpp"
#include <limits>
#include <cstring>

template <typename T>
Array<T>::Array() : _array(NULL), _capacity(0), _size(0) {
}

template <typename T>
Array<T>::Array(const unsigned int& capacity) {
	this->_capacity = capacity;
	this->_size = 0;
	this->_array = new T[capacity];
	std::memset(this->_array, 0, capacity * sizeof(T));
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _capacity(0), _size(0) {
	*this = other;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		this->_capacity = other._capacity;
		this->_size = other._size;
		if (this->_array) {
			delete[] this->_array;
			this->_array = NULL;
		}
		if (other._array) {
			this->_array = new T[other._capacity];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = other._array[i];
			std::memset(&this->_array[this->_size],0 , sizeof(T) * (this->_capacity - this->_size));
		}
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](const unsigned int& index) {
	if (index >= this->_capacity)
		throw std::out_of_range("Out of bound");
	if (index >= this->_size)
		this->_size = index + 1;
	return this->_array[index];
}

template <typename T>
const unsigned int& Array<T>::size() const {
	return this->_size;
}

template <typename T>
const unsigned int& Array<T>::getCapacity() const {
	return this->_capacity;
}

template <typename T>
T*	Array<T>::getArray() const {
	return this->_array;
}



template <typename T>
bool	Array<T>::resize() {
	if (this->_capacity == std::numeric_limits<unsigned int>::max()) {
		std::cout << "Error\nMax size has been reached" << std::endl;
		return 1;
	}
	else if (this->_capacity >= (std::numeric_limits<unsigned int>::max() / 2)) {
		std::cout << "Warning\n your are reaching maximum capacity, size is now unsigned int max" << std::endl;
		this->_capacity = std::numeric_limits<unsigned int>::max();
	}
	else 
		this->_capacity *= 2;
	T*	newArray = new T[this->_capacity];
	for (unsigned int i = 0; i < this->_size; i++) {
		newArray[i] = this->_array[i];	
	}
	std::memset(&newArray[this->_size],0 , sizeof(T) * (this->_capacity - this->_size));
	delete[] this->_array;
	this->_array = newArray;
	return 0;
}

template <typename T>
void	Array<T>::push(const T& element) {
	if (!this->_array)
		return ;
	if (this->_size == this->_capacity) {
		if (this->resize())
			return ;
	}
   	this->_array[this->_size] = element;
   	this->_size++;
}

template <typename T>
void	Array<T>::pop() {
	this->_size--;
}
template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
}
