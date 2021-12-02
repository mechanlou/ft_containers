#include "externals.hpp"
#include "Reverse_iterator.hpp"
#include "Vector.hpp"

int main(void)
{
	ft::vector<int> a(3, 12);
	a[0] = 2;
	a[1] = 3;
	a[2] = 4;
	
	ft::vector<int>::reverse_iterator it1 = a.rbegin(); //default constructor
	ft::vector<int>::reverse_iterator it2 = it1; //copy assignation
	ft::vector<int>::reverse_iterator it3(it2); //copy constructor
	
	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	while (it1 != a.rend())
	{
		std::cout << *it1 << std::endl; //operator*
		(*it1)++;
		it1++; //operator++
	}
	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	std::cout << std::endl;

	while (it3 != a.rend())
	{
		std::cout << *it3 << std::endl;
		(*it3)++;
		it3++;
	}
	std::cout << std::endl;

	ft::reverse_iterator<ft::vector<int>::iterator> it4 = a.rend();
	while (it4 != a.rbegin())
	{
		--it4; //operator--
		std::cout << *it4 << std::endl;
	}
	std::cout << std::endl;

	std::cout << "rbegin > rend ? " << (a.rbegin() > a.rend()) << std::endl;
	std::cout << "rbegin < rend ? " << (a.rbegin() < a.rend()) << std::endl;
	std::cout << "rbegin >= rend ? " << (a.rbegin() >= a.rend()) << std::endl;
	std::cout << "rbegin <= rend ? " << (a.rbegin() <= a.rend()) << std::endl;
	std::cout << "rbegin >= rbegin ? " << (a.rbegin() >= a.rbegin()) << std::endl;
	std::cout << "rbegin <= rbegin ? " << (a.rbegin() <= a.rbegin()) << std::endl;

	it4 += 2; //operator -=
	it4 -= 1; //operator +=

	std::cout << "it4[0] after += and -= operations : " << it4[0] << std::endl;
	std::cout << "*it4 after += and -= operations : " << *it4 << std::endl;
	std::cout << "*(1 + it4) : " << *(1 + it4) << std::endl;
	return (0);
}