#include "externals.hpp"
#include "Vector.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Helo fren ༼ つ ◕_◕ ༽つ" << std::endl << std::endl;

	ft::vector<int>	a(6, 666);
	ft::vector<int>	empty;

	std::cout << a[2]++ << std::endl;
	std::cout << a.at(2) << std::endl;
	std::cout << (a[5] = 1995) << std::endl;
	std::cout << --a.at(5) << std::endl;
	try
	{
		std::cout << a.at(6) << std::endl;
	}
	catch(std::exception const & exc)
	{
		std::cerr << "Catched error : " << exc.what() << std::endl;
	}
	std::cout << std::endl;

	ft::vector<int>::iterator it = a.begin();
	while (it != a.end())
		std::cout << (*(it++))++ << std::endl;
	std::cout << std::endl;

	ft::vector<int>::const_iterator const_it = a.begin();
	// (*const_it) = 4; //doesnt compile = nice
	while (const_it != a.end())
		std::cout << *(const_it++) << std::endl;
	std::cout << std::endl;
	
	std::cout << "front : " << a.front() << std::endl;
	std::cout << "back : " << a.back() << std::endl;
	return (0);
}