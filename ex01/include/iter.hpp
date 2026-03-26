#ifndef ITER_HPP
# define ITER_HPP

#include <cstdint>

template <typename Array, typename Function>
void iter(Array* array, const std::size_t length, Function func)
{
	for (std::size_t idx = 0; idx < length; idx++)
	{
		func(array[idx]);
	}
}

#endif /* ITER_HPP */
