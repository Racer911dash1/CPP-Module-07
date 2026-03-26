#include "whatever.hpp"
#include "colors.hpp"
#include <iostream>

int main()
{
	{
		int a = 5;
		int b = 10;
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n";
		swap(a, b);
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n\n";
	}
	{
		double a = 2.7;
		double b = 3.14;
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n";
		swap(a, b);
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n\n";
	}
	{
		std::string a = "Hello";
		std::string b = "World!";
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n";
		swap(a, b);
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n\n";
	}
	{
		int a = 5;
		int b = 10;
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n"
					<< "min: " << min(a, b) << "\n"
					<< "max: " << max(a, b) << "\n\n";
	}
	{
		double a = 5;
		double b = 10;
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n"
					<< "min: " << min(a, b) << "\n"
					<< "max: " << max(a, b) << "\n\n";
	}
	{
		std::string a = "Hello";
		std::string b = "World!";
		std::cout	<< "a: " << a << "\n"
					<< "b: " << b << "\n"
					<< "min: " << min(a, b) << "\n"
					<< "max: " << max(a, b) << "\n";
	}
	return (EXIT_SUCCESS);
}