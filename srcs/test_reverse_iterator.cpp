#include "externals.hpp"
#include "Reverse_iterator.hpp"
#include "Vector.hpp"

int main(void)
{
	ft::vector<int> a(3, 12);
	a._data[0] = 1;
	a._data[1] = 2;
	a._data[2] = 3;

	ft::reverse_iterator<ft::vector<int>::iterator> it1(a.begin()); //default constructor
	ft::reverse_iterator<ft::vector<int>::iterator> it2 = it1; //copy assignation
	ft::reverse_iterator<ft::vector<int>::iterator> it3(it2); //copy constructor

	for(int i = 0; i < 3; i++)
	{
		std::cout << *it1 << std::endl; //operator*
		(*it1)++; 
		it1++; //operator++
	}
	std::cout << std::endl;

	for(int i = 0; i < 3; i++)
	{
		std::cout << *it2 << std::endl;
		(*it2)++;
		++it2; //operator++
	}
	std::cout << std::endl;

	std::cout << "operator+ operator- tests:" << std::endl;
	std::cout << "*(it3 + 1) : " << *(it3 + 1) << std::endl;
	std::cout << "*((it3 + 1) - 1) : " << *((it3 + 1) - 1) << std::endl << std::endl;

	for(int i = 0; i < 3; i++)
	{
		std::cout << *it3 << std::endl;
		(*it3)++;
		it3++;
	}
	std::cout << std::endl;

	ft::reverse_iterator<ft::vector<int>::iterator> it4(a.end());
	for(int i = 0; i < 3; i++)
	{
		it4--; //operator--
		std::cout << *it4 << std::endl;
		(*it4)++;
	}
	std::cout << std::endl;

	it4 += 2; //operator -=
	it4 -= 1; //operator +=

	std::cout << "it4[0] after += and -= operations : " << it4[0] << std::endl;
	return (0);
}