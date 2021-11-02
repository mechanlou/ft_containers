#include "externals.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl;

	std::vector<int> ref_vec(3, 1995);

	ft::vector<int>	default_vec;
	// std::cout << "fill expected" << std::endl;
	ft::vector<int>	fill_vec(2, 666);
	// std::cout << "range expected" << std::endl;
	ft::vector<int>	range_vec(ref_vec.begin(), ref_vec.end());


	default_vec._data[0] = 7;
	std::cout << "default " << default_vec._data[0] << std::endl;

	std::cout << "fill " << fill_vec._data[1] << std::endl;

	std::cout << "range " << range_vec._data[2] << std::endl;
	return (0);
}