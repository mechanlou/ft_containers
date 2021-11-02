#include "externals.hpp"
#include "Vector.hpp"

int main(void)
{
	ft::vector<int> a(4, 0);
	ft::vector<int>::iterator it1; //default constructor
	ft::vector<int>::iterator it2;

	it1 = a.begin(); //copy assignation
	it2 = it1; //copy assignation
	ft::vector<int>::iterator it3(it2); //copy constructor

	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	while (it1 != a.end())
	{
		std::cout << *it1 << std::endl; //operator*
		(*it1)++; 
		it1++; //operator++
	}
	std::cout << "it1 == it2 ? " << (it1 == it2) << std::endl;
	std::cout << "it1 != it2 ? " << (it1 != it2) << std::endl;
	std::cout << std::endl;

	while (it2 != a.end())
	{
		std::cout << *it2 << std::endl;
		(*it2)++;
		++it2; //operator++
	}
	std::cout << std::endl;

	std::cout << "operator+ operator- tests:" << std::endl;
	std::cout << "*(it3 + 1) : " << *(it3 + 1) << std::endl;
	std::cout << "*((it3 + 1) - 1) : " << *((it3 + 1) - 1) << std::endl << std::endl;

	while (it3 != a.end())
	{
		std::cout << *it3 << std::endl;
		(*it3)++;
		it3++;
	}
	std::cout << std::endl;

	ft::vector<int>::iterator it4 = a.end();
	while (it4 != a.begin())
	{
		it4--; //operator--
		std::cout << *it4 << std::endl;
		(*it4)++;
	}
	std::cout << std::endl;

	std::cout << "begin > end ? " << (a.begin() > a.end()) << std::endl;
	std::cout << "begin < end ? " << (a.begin() < a.end()) << std::endl;
	std::cout << "begin >= end ? " << (a.begin() >= a.end()) << std::endl;
	std::cout << "begin <= end ? " << (a.begin() <= a.end()) << std::endl;
	std::cout << "begin >= begin ? " << (a.begin() >= a.begin()) << std::endl;
	std::cout << "begin <= begin ? " << (a.begin() <= a.begin()) << std::endl;
	std::cout << "end - begin ? " << (a.end() - a.begin()) << std::endl;

	it4 += 2; //operator -=
	it4 -= 1; //operator +=

	std::cout << "it4[0] after += and -= operations : " << it4[0] << std::endl;
	return (0);
}