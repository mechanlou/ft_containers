#include "externals.hpp"
#include "Vector.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl << std::endl;

	ft::vector<int> a(5, 666);
	ft::vector<int> b(a);

	ft::vector<int>::iterator it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}

	a.assign(12, 667);
	it1 = a.begin();
	while (it1 != a.end())
	{
		std::cout << *(it1++) << std::endl;
	}
	
	return (0);
}