#include "externals.hpp"
#include "Vector.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl;

	std::vector<int> ref_vec(3, 1995);

	ft::vector<int>	default_vec;
	ft::vector<int>	fill_vec(2, 666);
	ft::vector<int>	range_vec(ref_vec.begin(), ref_vec.end());
	ft::vector<int> copy_vec(range_vec);

	ft::vector<int>::iterator it;
	it = range_vec.begin();
	while (it != range_vec.end())
	{
		std::cout << *(it++) << std::endl;
	}

	default_vec = fill_vec;
	it = default_vec.begin();
	while (it != default_vec.end())
	{
		std::cout << *(it++) << std::endl;
	}
	// default_vec._data[0] = 7;
	// std::cout << "default " << default_vec._data[0] << std::endl;

	// std::cout << "fill " << fill_vec._data[1] << std::endl;

	// std::cout << "range " << range_vec._data[2] << std::endl;
	return (0);
}