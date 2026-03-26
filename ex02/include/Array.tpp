#include "Array.hpp"
#include "colors.hpp"
#include <iostream>

template <class T>
Array<T>::Array() : array_(new T[0])
{
	std::cout << GREEN << "Array Default Constructor Called\n" << RESET;
}

template <class T>
Array<T>::Array(unsigned int size) : array_(new T[size]), size_(size)
{
	std::cout << GREEN << "Array Constructor Called\n" << RESET;
}

template <class T>
Array<T>::Array(const Array& other) :  array_(new T[other.size_]), size_(other.size_)
{
	std::cout << YELLOW << "Array Copy Constructor Called\n" << RESET;
	std::copy(other.array_, other.array_ + other.size_, array_);
}

template <class T>
Array<T>& Array<T>::operator=(Array other)
{
	std::cout << BRIGHT_GREEN << "Array Assignment Operator Called\n" << RESET;

	if (this == &other)
	{
		return *this;
	}
	std::swap(array_, other.array_);
	std::swap(size_, other.size_);
	return *this;
}

template <class T>
Array<T>::~Array()
{
	std::cout << RED << "Array Destructor Called\n" << RESET;
	delete[] array_;
}

template <class T>
T& Array<T>::operator[](unsigned int idx)
{
	if (size_ == 0 || idx >= size_)
	{
		throw OutOfBoundsException(idx);
	}
	return array_[idx];
}

template <class T>
Array<T>::OutOfBoundsException::OutOfBoundsException(unsigned int idx) : idx_(idx)
{
	message_ = "Array[" + std::to_string(idx_) + "] is out of bounds";
}

template <class T>
const char* Array<T>::OutOfBoundsException::what() const noexcept
{
	return message_.c_str();
}