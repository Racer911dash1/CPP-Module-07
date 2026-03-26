#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <class T>
class Array
{
	public:
		class OutOfBoundsException : public std::exception
		{
			public:
				OutOfBoundsException(unsigned int idx_);
				const char* what() const noexcept override;

			private:
				unsigned int idx_ {0};
				std::string message_;
		};

		Array();
		Array(unsigned int size);
		Array(const Array& other);
		Array& operator=(Array other);
		~Array();

		T& operator[](unsigned int idx);

	private:
		T* array_ {nullptr};
		unsigned int size_ {0};
};

# include "Array.tpp"

#endif /* ARRAY_HPP */
