// #include "truc.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include "../headers/Vector.hpp"
#include "../headers/Is_integral.hpp"

template <class T>
bool	func(T a)
{
	(void) a;
	return (ft::is_integral<T>::value);
}

int main(void)
{
	ft::vector<int>::iterator a;

	std::cout << func(a) << std::endl;
	return (0);
}

