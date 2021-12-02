#include "externals.hpp"
#include "Vector.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl << std::endl;

	ft::vector<int>	a(6, 666);
	ft::vector<int>	empty;
	
	std::cout << "not empty : " << a.empty() << std::endl;
	std::cout << "empty : " << empty.empty() << std::endl << std::endl;

	std::cout << "size before resize : " << a.size() << std::endl;
	std::cout << "capacity before resize : " << a.capacity() << std::endl << std::endl;
	a.resize(20, 1995);
	std::cout << "size after first resize : " << a.size() << std::endl;
	std::cout << "capacity after first resize : " << a.capacity() << std::endl;

	ft::vector<int>::iterator it = a.begin();
	while (it != a.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl;

	a.resize(8, 1995);
	std::cout << "size after second resize : " << a.size() << std::endl;
	std::cout << "capacity after second resize : " << a.capacity() << std::endl;

	it = a.begin();
	while (it != a.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl;
	
	a.reserve(100);
	std::cout << "capacity after reserve 100 : " << a.capacity() << std::endl;
	it = a.begin();
	while (it != a.end())
		std::cout << *(it++) << std::endl;
	return (0);
}