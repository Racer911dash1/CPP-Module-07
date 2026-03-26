#include "colors.hpp"
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main()
{
	{
		Array<int> arr1(2);
		arr1[0] = 1;
		Array<int> arr2(arr1);
		arr1[1] = 2;
		arr2[1] = 3;
		try
		{
			std::cout << "arr1[0]: " << arr1[0] << "\n";
			std::cout << "arr1[1]: " << arr1[1] << "\n";
			std::cout << "arr2[0]: " << arr2[0] << "\n";
			std::cout << "arr2[1]: " << arr2[1] << "\n";
			std::cout << arr1[2] << "\n";
		}
		catch(const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Array<std::string> arr1(2);
		Array<std::string> arr2;
		arr1[0] = "Hello";
		arr2 = arr1;
		arr1[1] = "World";
		arr2[1] = "Codam";
		try
		{
			std::cout << "arr1[0]: " << arr1[0] << "\n";
			std::cout << "arr1[1]: " << arr1[1] << "\n";
			std::cout << "arr2[0]: " << arr2[0] << "\n";
			std::cout << "arr2[1]: " << arr2[1] << "\n";
			std::cout << arr1[2] << "\n";
		}
		catch(const Array<std::string>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
		return 0;
	}
}