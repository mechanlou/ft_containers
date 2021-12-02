#include "externals.hpp"
#include "Vector.hpp"
#include <iostream>

int	main(void)
{
	const ft::vector<int> a(3, 1995);
	const ft::vector<int> b(a);
	ft::vector<int> c(a);

	c[2] = 666;
	std::cout << "a == b ? " << (a == b) << std::endl;
	std::cout << "a == c ? " << (a == c) << std::endl;
	std::cout << "a != b ? " << (a != b) << std::endl;
	std::cout << "a != c ? " << (a != c) << std::endl;
	std::cout << "a < b ? " << (a < b) << std::endl;
	std::cout << "a < c ? " << (a < c) << std::endl;
	std::cout << "a > b ? " << (a > b) << std::endl;
	std::cout << "a > c ? " << (a > c) << std::endl;
	std::cout << "a <= b ? " << (a <= b) << std::endl;
	std::cout << "a <= c ? " << (a <= c) << std::endl;
	std::cout << "a >= b ? " << (a >= b) << std::endl;
	std::cout << "a >= c ? " << (a >= c) << std::endl;
	return (0);
}