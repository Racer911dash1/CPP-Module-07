#include "iter.hpp"
#include "colors.hpp"
#include <iostream>

template<typename T>
void print(const T& ref)
{
	std::cout << ref << "\n";
}

void next_number(int& num)
{
	num += 1;
}

void next_char(char& chr)
{
	chr += 1;
}

int main()
{
	{
		int numbers[] = {10, 20, 30, 40, 50};
		std::size_t length = sizeof(numbers) / sizeof(*numbers);

		iter(numbers, length, print<int>);
		iter(numbers, length, next_number);
		iter(numbers, length, print<int>);
	}
	{
		char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
		std::size_t length = sizeof(chars) / sizeof(*chars);

		iter(chars, length, print<char>);
		iter(chars, length, next_char);
		iter(chars, length, print<char>);
	}
}