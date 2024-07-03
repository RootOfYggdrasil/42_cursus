
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <class T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;
public:
	Array() :  _size(0) , _array(NULL) { };
	Array(unsigned int n) : _size(n) , _array(new T[n]) { } ;
	Array(Array const &other) : _size(other._size)
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	};
	~Array()
	{
		delete [] _array;
	};
	Array<T> &operator=(Array const &other)
	{
		if (this == &other)
			return *this;
		if (_array)
			delete [] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	T &operator[](unsigned int n)
	{
		if (n < 0 || n >= this->_size)
			throw std::out_of_range("Index out of range");
		return _array[n];
	};
	unsigned int size() const
	{
		return _size;
	};

};

#endif