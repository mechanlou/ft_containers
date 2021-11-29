#include "externals.hpp"
#include "Reverse_iterator.hpp"
#include "Map.hpp"

int main(void)
{
	ft::map<int, char> a;
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	
	ft::map<int, char>::reverse_iterator it1 = a.rbegin(); //default constructor
	ft::map<int, char>::reverse_iterator it2 = it1; //copy assignation
	ft::map<int, char>::reverse_iterator it3(it2); //copy constructor
	
	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	while (it1 != a.rend())
	{
		std::cout << (*it1).first << " | " << (*it1).second << std::endl; //operator*
		(*it1).second++;
		it1++; //operator++
	}
	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	std::cout << std::endl;

	while (it3 != a.rend())
	{
		std::cout << (*it3).first << " | " << (*it3).second << std::endl; //operator*
		(*it3).second++;
		it3++;
	}
	std::cout << std::endl;

	ft::reverse_iterator<ft::map<int, char>::iterator> it4 = a.rend();
	while (it4 != a.rbegin())
	{
		--it4; //operator--
		std::cout << (*it4).first << " | " << (*it4).second << std::endl; //operator*
	}
	std::cout << std::endl;
	return (0);
}